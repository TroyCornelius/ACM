import java.util.Scanner;
import java.util.Arrays;
import java.util.Vector;


class DiceProbability {
    static int[] scores_two_dice = {0, 1, 2, 3, 4, /* 6 */ 5, 6, 5, 4, 3, 2, 1};

    static double probability(int current_total, int score) {
        if(current_total <= 6) 
            return (score <= 6) ? 1.0/6 : 0;
        else 
            return scores_two_dice[score - 1]/36.0;
    }
}

/* Our solution is to exhaustively build the entire game tree. Each state is a possible configuration
 * of open cards, i.e., a subset of {1..9}. We will represent that using a boolean array. */
class State {
    boolean[] open = new boolean[Main.MAX];
    int total; /* Total of open cards. */
    int numones; /* Number of open cards. */

    double probability = -1.0; /* Probability of shutting the box. */

    /* Children for each possible score. */
    Vector<State>[] children = (Vector<State>[]) new Vector[12];

    /* Best child for each possible score. */
    State[] bestChildForScore = new State[12];

    State(boolean[] current) {
        total = numones = 0;
        for(int i = 0; i < current.length; i++) {
            open[i] = current[i];
            if(open[i]) {
                total += (i + 1);
                numones++;
            }
        }

        for(int i = 0; i < children.length; i++)
            children[i] = new Vector<State>();
    }


    void addIfChild(State possibleChild) {
        int score = 0;
        for(int i = 0; i < open.length; i++) {
            if(possibleChild.open[i]) {
                if(!open[i]) // not a child
                    return;
            } else {
                if(open[i])
                    score += (i + 1);
            }
        }

        if(score <= 12)
            children[score-1].add(possibleChild);
    }

    public String toString() {
        return Arrays.toString(open);
    }

    public String list() {
        String list = "";
        for(int i = 0; i < open.length; i++) {
            if(open[i]) 
                list = list + " " + (i+1);
        }
        return list;
    }
}


public class Main {

    static final int MAX = 9;

    static boolean print_solutions = false;

    static int convertBooleanArrayToInt(boolean[] arr) {
        int ret = 0;
        int mult = 1;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i]) 
                ret += mult;
            mult *= 2;
        }
        return ret;
    }

    static State[] states = new State[512];

    /* We will statically compute the probabilities of shutting the box for all the possible states. */
    private static void computeAllProbabilities() {
        /* Initialize states. */
        boolean[] current = new boolean[MAX];

        for(int i = 0; i < current.length; i++)
            current[i] = false;
        states[0] = new State(current);

        boolean found = true;
        while(found) {
            /* From the end, find the first one that is false, and set it to true. */
            found = false;
            for(int i = current.length - 1; i >= 0; i--) {
                current[i] = !current[i];
                if(found = current[i]) 
                    break;
            }
            if(found) {
                states[convertBooleanArrayToInt(current)] = new State(current);
            }
        }

        /* Figure out who is child of whom. */
        for(int i = 0; i < states.length; i++)
            for(int j = i+1; j < states.length; j++)
                states[j].addIfChild(states[i]); /* i can be a child of j. */


        /* Compute the probabilities that we can shut the box. */
        states[0].probability = 1.0;

        for(int i = 1; i < states.length; i++) {
            if(print_solutions) System.out.println("Computing for state " + states[i] + " with number of ones " + states[i].numones);

            /* For each score, let's first find the best child. */
            for(int score = 1; score <= 12; score++) {
                for(State ch : states[i].children[score-1]) {
                    if(print_solutions) System.out.println("            has child " + ch + " with probability " + ch.probability);
                    if( (states[i].bestChildForScore[score-1] == null) || (states[i].bestChildForScore[score-1].probability < ch.probability) )
                        states[i].bestChildForScore[score-1] = ch;
                }
            }

            /* Compute the probability for state "i". */
            double p = 0.0;
            for(int score = 1; score <= 12; score++) {
                if(states[i].bestChildForScore[score-1] != null) 
                    p += (states[i].bestChildForScore[score-1].probability * DiceProbability.probability(states[i].total, score));
            }
            states[i].probability = p;

            if(print_solutions) 
                System.out.println("            FINAL PROBABILITY: " + p);

        }
    }

    /* Is val contained in values[] ? */
    static boolean contains(int val, int[] values) {
        for(int i = 0; i < values.length; i++)
            if(val == values[i])
                return true;
        return false;
    }

    private static void Main(int[] values, int score) {
        boolean[] solution = new boolean[values.length];
        boolean solution_found = false;
        double probability = -1;

        /* ------------------- INSERT CODE HERE ---------------------*/

        boolean[] current = new boolean[MAX];
        for(int i = 0; i < current.length; i++)
            current[i] = contains(i+1, values);

        State st = states[convertBooleanArrayToInt(current)];

        /* Check if we have a best child for the required score. */
        if(st.bestChildForScore[score - 1] != null) {
            solution_found = true;
            boolean[] childopen = st.bestChildForScore[score - 1].open;
            probability = st.bestChildForScore[score - 1].probability;

            int index = 0;
            for(int i = 0; i < childopen.length; i++) {
                if(current[i]) 
                    solution[index++] = !childopen[i];
            }
        } 
            
        /* -------------------- END OF INSERTION --------------------*/

        if(!solution_found) {
            System.out.println("No move found.");
        } else {
            System.out.print("The best move is:");
            for(int i = 0; i < solution.length; i++)
                if(solution[i])
                    System.out.print(" " + values[i]);
            System.out.println(", and probability of shutting = " + (String.format("%.4f", probability)));
        }
    }
    
    public static void main(String[] args) {

        computeAllProbabilities();

        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();

        for(int i = 0; i < numCases; i++) 
        {
            int score = sc.nextInt();

            int numEntries = sc.nextInt();

            int[] values = new int[numEntries];

            for(int j = 0; j < values.length; j++)
                values[j] = sc.nextInt();

            Main(values, score);
        }
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class Main {

	static StreamTokenizer in;
	static PrintWriter out;
	
	static int nextInt() throws IOException
	   {
	      in.nextToken();
	      return (int)in.nval;
	   }
	
	static String nextString() throws IOException
	   {
	      in.nextToken();
	      return in.sval;
	   }

	public static void main(String[] args) throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		out = new PrintWriter(System.out);
		
		in.ordinaryChars('0', '9');
		in.wordChars('0', '9');
		
		for (int t = Integer.valueOf(nextString()); t > 0; t--) {
			for (int i = 0; i < M; i++) {
				String s = nextString();
				for (int j = 0; j < M; j++) g[i][j] = s.charAt(j) == '1';
			}
			int n = Integer.valueOf(nextString());
			
			memo = new long[n+1][M][M];
			
			try {
				out.println(solve(n, 0, 2, 1));
			} catch (Exception e) {
				out.println("Epic Fail...");
			}
		}

		out.flush();
	}

	static final int M = 3;
	static boolean[][] g = new boolean[M][M];
	static long[][][] memo;
	
	static long solve(int n, int from, int to, int aux) throws Exception {
		if (memo[n][from][to] != 0) return memo[n][from][to];
		else if (g[from][to]) return memo[n][from][to] = (n == 1 ? 1 : solve(n-1, from, aux, to) + 1 + solve(n-1, aux, to, from));
		else if (g[from][aux] && g[aux][to]) return memo[n][from][to] = (n == 1 ? 2 : solve(n-1, from, to, aux) + 1 + solve(n-1, to, from, aux) + 1 + solve(n-1, from, to, aux));
		else throw new Exception();
	}
}


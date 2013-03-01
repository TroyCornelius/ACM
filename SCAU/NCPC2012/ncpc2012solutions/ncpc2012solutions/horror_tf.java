/* Sample solution for the Doorman problem in NCPC 2012 by Tommy Färnqvist*/

import java.util.Vector;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

class Kattio extends PrintWriter {
  public Kattio(InputStream i) {
    super(new BufferedOutputStream(System.out));
    r = new BufferedReader(new InputStreamReader(i));
  }
  public Kattio(InputStream i, OutputStream o) {
    super(new BufferedOutputStream(o));
    r = new BufferedReader(new InputStreamReader(i));
  }

  public boolean hasMoreTokens() {
    return peekToken() != null;
  }

  public int getInt() {
    return Integer.parseInt(nextToken());
  }

  public long getLong() {
    return Long.parseLong(nextToken());
  }

  public String getWord() {
    return nextToken();
  }

  private BufferedReader r;
  private String line;
  private StringTokenizer st;
  private String token;

  private String peekToken() {
    if (token == null)
      try {
	while (st == null || !st.hasMoreTokens()) {
	  line = r.readLine();
	  if (line == null) return null;
	  st = new StringTokenizer(line);
	}
	token = st.nextToken();
      } catch (IOException e) { }
    return token;
  }

  private String nextToken() {
    String ans = peekToken();
    token = null;
    return ans;
  }
}

public class horror_tf {
  static final int infinity = 2147483647;
  public static void main(String args[]) {
    Kattio io = new Kattio(System.in, System.out);

    while (io.hasMoreTokens()) {
      int N = io.getInt();
      int H = io.getInt();
      int L = io.getInt();
      
      Vector<Integer> hIndex = new Vector<Integer>(N);
      LinkedList<Integer> q = new LinkedList<Integer>();

      for (int i = 0; i < N; i++) {
	hIndex.add(infinity);
      }

      for (int i = 0; i < H; i++) {
	int h = io.getInt();
	hIndex.setElementAt(0, h);
	q.add(h);
      }

      Vector<LinkedList<Integer>> adjList = new Vector<LinkedList<Integer>>(N);

      for (int i = 0; i < N; i++) {
	adjList.add(new LinkedList<Integer>());
      }

      
      for (int i = 0; i < L; i++) {
	int m1 = io.getInt();
	int m2 = io.getInt();

	(adjList.get(m1)).add(m2);
	(adjList.get(m2)).add(m1);
      }

      while (!q.isEmpty()) {
	int m = q.poll();
	int Q = hIndex.get(m);
	for (int i = 0; i < (adjList.get(m)).size(); i++) {
	  if (hIndex.get((adjList.get(m)).get(i)) == infinity) {
	    hIndex.setElementAt(Q + 1, (adjList.get(m)).get(i));
	    q.add((adjList.get(m)).get(i));
	  }
	}
      }

      int movie = 0;
      int index = hIndex.get(0);
      for (int i = 0; i < N; i++) {
	if (hIndex.get(i) > index) {
	  index = hIndex.get(i);
	  movie = i;
	}
      }

      io.println(movie);
    }
    io.close();
  }
}

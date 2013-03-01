/* Sample solution for the Cookie Selection problem in NCPC 2012 by Tommy Färnqvist*/

import java.math.BigInteger;
import java.util.PriorityQueue;
import java.util.Vector;
import java.util.Collections;
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

public class cookieselection_tf {
  public static void main(String args[]) {
    Kattio io = new Kattio(System.in, System.out);
    PriorityQueue<Integer> maxpq = new PriorityQueue<Integer>(11, Collections.reverseOrder());
    PriorityQueue<Integer> minpq = new PriorityQueue<Integer>();

    minpq.add(300000001);
    maxpq.add(-1);

    while (io.hasMoreTokens()) {
      String str = io.getWord();

      if (str.equals("#")) {
	int m = minpq.poll();
	if (minpq.size() != maxpq.size()) {
	  minpq.add(maxpq.poll());
	}
	io.println(m);
      }
      else {
	int d = Integer.parseInt(str);
	if (d > minpq.peek()) {
	  minpq.add(d);
	  if (minpq.size() > maxpq.size() + 1) {
	    maxpq.add(minpq.poll());
	  }

	}
	else {
	  maxpq.add(d);
	  if (maxpq.size() > minpq.size()) {
	    minpq.add(maxpq.poll());
	  }
	}
      }
    }
    io.close();
  }
}

/* Sample solution for the Bread Sorting problem in NCPC 2012 by Tommy Färnqvist. */

import java.util.Arrays;
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

public class bread_tf {

  static long merge(int[] a, int[] copy, int low, int mid, int high) {
    long inv = 0;

    System.arraycopy(a, low, copy, low, high - low + 1);

    int i = low;
    int j = mid + 1;
    for (int k = low; k <= high; k++) {
      if (i > mid)
	a[k] = copy[j++];
      else if (j > high)
	a[k] = copy[i++];
      else if (copy[j] < copy[i]) {
	a[k] = copy[j++];
	inv += (mid - i + 1);
      }
      else
	a[k] = copy[i++];
    }
    return inv;
  }
  
  static long count (int[] a, int[] copy, int low, int high) {
    long inv = 0;

    if (high <= low)
      return 0;

    int mid = low + (high - low) / 2;
    inv += count (a, copy, low, mid);
    inv += count (a, copy, mid + 1, high);
    inv += merge (a, copy, low, mid, high);

    return inv;
  }
  
  static long count(int[] a) {
    int[] copy = new int[a.length];

    long inv = count(a, copy, 0, a.length - 1);
    
    return inv;
  }
  
  public static void main(String args[]) {
    Kattio io = new Kattio(System.in, System.out);

    int n = io.getInt();

    int[] a = new int[n];
    int[] b = new int[n];
    
    for (int i = 0; i < n; i++) {
      a[i] = io.getInt();
    }
    for (int i = 0; i < n; i++) {
      b[i] = io.getInt();
    }

    long inva = count(a);
    long invb = count(b);

    if (inva % 2 == invb % 2) {
      io.println("Possible");
    }
    else {
      io.println("Impossible");
    }

    io.close();
  }
}

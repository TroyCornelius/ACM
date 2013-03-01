import java.text.DecimalFormat;
import java.util.*;
import java.io.*;
import java.math.*;

class Fraction {
	BigInteger a = BigInteger.ZERO, b = BigInteger.ONE;

	Fraction() {
	}

	Fraction(BigInteger a, BigInteger b) {
		BigInteger d = a.gcd(b);
		a = a.divide(d);
		b = b.divide(d);
		if (b.compareTo(BigInteger.ZERO) < 0) {
			a = a.negate();
			b = b.negate();
		}
		this.a = a;
		this.b = b;
	}

	@Override
	public String toString() {
		BigInteger d = a.gcd(b);
		a = a.divide(d);
		b = b.divide(d);
		if (b.compareTo(BigInteger.ONE) == 0)
			return a.toString();
		return a + "/" + b;
	}

	public void reductionOfAFraction() {
		BigInteger d = a.gcd(b);
		a = a.divide(d);
		b = b.divide(d);
	}

	public Fraction add(Fraction p) {
		return new Fraction(a.multiply(p.b).add(b.multiply(p.a)),
				b.multiply(p.b));
	}

	public Fraction subtract(Fraction p) {
		return new Fraction(a.multiply(p.b).subtract(b.multiply(p.a)),
				b.multiply(p.b));
	}

	public Fraction muliply(Fraction p) {
		return new Fraction(a.multiply(p.a), b.multiply(p.b));
	}

	public Fraction divide(Fraction p) {
		return new Fraction(a.multiply(p.b), b.multiply(p.a));
	}

	public Fraction abs() {
		return new Fraction(a.abs(), b.abs());
	}

	public int compareTo(Fraction p) {
		return a.multiply(p.b).subtract(b.multiply(p.a)).signum();
	}
}

public class Main {

	// Gaussian elimination
	public static Fraction[] gaussianElimination(Fraction A[][], int m) {
		for (int i = 0; i < m; ++i) {
			int maxi = i;
			if (i != maxi) {
				Fraction tmp[] = A[i];
				A[i] = A[maxi];
				A[maxi] = tmp;
			}
			for (int k = m; k >= i; --k)
				A[i][k] = A[i][k].divide(A[i][i]);
			for (int u = i + 1; u < m; ++u)
				for (int k = m; k > i; --k)
					A[u][k] = A[u][k].subtract(A[u][i].muliply(A[i][k]));
		}
		Fraction x[] = new Fraction[m];
		x[m - 1] = A[m - 1][m].divide(A[m - 1][m - 1]);
		for (int i = m - 2; i >= 0; --i) {
			x[i] = A[i][m];
			for (int k = i + 1; k < m; ++k)
				x[i] = x[i].subtract(x[k].muliply(A[i][k]));
			x[i] = x[i].divide(A[i][i]);
		}
		return x;
	}

	public static void add(Fraction A[][], int x, int y, BigInteger a,
			BigInteger b) {
		A[x][y] = A[x][y].add(new Fraction(a, b));
	}

	public static void main(String args[]) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		Fraction mat[][] = new Fraction[105][105];

		int t, n, m, k;

		t = cin.nextInt();
		for (int i = 1; i <= t; i++) {
			n = cin.nextInt();
			m = cin.nextInt();
			k = cin.nextInt();
			for (int j = 0; j < n * m; j++) {
				for (int l = 0; l <= n * m; l++) {
					mat[j][l] = new Fraction();
				}
			}
			for (int j = 0; j < m; j++)
				for (int l = 0; l < n; l++) {
					add(mat, j * n + l, j * n + l, BigInteger.valueOf(1),
							BigInteger.valueOf(1));
					if (j == m - 1) {
						if (l == 0)
							mat[j * n][n * m] = new Fraction(BigInteger.ONE,
									BigInteger.ONE);
						continue;
					}
					if (l == 0) {
						add(mat, j * n + l, (j + 1) * n + l,
								BigInteger.valueOf(-1), BigInteger.valueOf(4));
						add(mat, j * n + l, n - 3, BigInteger.valueOf(-3),
								BigInteger.valueOf(4));
					} else if (l == 1) {
						add(mat, j * n + l, (j + 1) * n + n - 3,
								BigInteger.valueOf(-1), BigInteger.valueOf(4));
						add(mat, j * n + l, 0, BigInteger.valueOf(-1),
								BigInteger.valueOf(4));
						add(mat, j * n + l, n - 2, BigInteger.valueOf(-1),
								BigInteger.valueOf(2));
					} else if (l == 2) {
						add(mat, j * n + l, (j + 1) * n + n - 2,
								BigInteger.valueOf(-1), BigInteger.valueOf(4));
						add(mat, j * n + l, 0, BigInteger.valueOf(-1),
								BigInteger.valueOf(4));
						add(mat, j * n + l, n - 2, BigInteger.valueOf(-1),
								BigInteger.valueOf(4));
						add(mat, j * n + l, n - 1, BigInteger.valueOf(-1),
								BigInteger.valueOf(4));
					} else if (l == 3) {
						add(mat, j * n + l, (j + 1) * n + n - 1,
								BigInteger.valueOf(-1), BigInteger.valueOf(4));
						add(mat, j * n + l, 0, BigInteger.valueOf(-1),
								BigInteger.valueOf(4));
						add(mat, j * n + l, n - 1, BigInteger.valueOf(-1),
								BigInteger.valueOf(2));
					} else {
						add(mat, j * n + l, (j + 1) * n + l - 3,
								BigInteger.valueOf(-1), BigInteger.valueOf(4));
						add(mat, j * n + l, l - 3, BigInteger.valueOf(-3),
								BigInteger.valueOf(4));
					}
				}
			Fraction[] ans = gaussianElimination(mat, n * m);
			Fraction[] fra = new Fraction[5];
			for (int j = 1; j <= 4; j++)
				fra[j] = new Fraction(BigInteger.valueOf(j),
						BigInteger.valueOf(4));

			Fraction dou = new Fraction();
			DecimalFormat df = new DecimalFormat("0.000000");
			double a, b;
			if (k == 1) {
				dou = ans[0].muliply(fra[1]).add(ans[n - 3].muliply(fra[3]));
			} else if (k == 2) {
				dou = ans[0].muliply(fra[1]).add(
						ans[n - 3].muliply(fra[1]).add(
								ans[n - 2].muliply(fra[2])));
			} else if (k == 3) {
				dou = ans[0].muliply(fra[1]).add(
						ans[n - 2].muliply(fra[2]).add(
								ans[n - 1].muliply(fra[1])));
			} else if (k == 4) {
				dou = ans[0].muliply(fra[1]).add(ans[n - 1].muliply(fra[3]));
			} else {
				dou = ans[k - 4];
			}
			dou.reductionOfAFraction();
			a = dou.a.doubleValue();
			b = dou.b.doubleValue();
			System.out.println("Case #" + i + ": " + df.format(a / b));
		}

	}
}
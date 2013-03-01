import java.util.PriorityQueue;
import java.util.Scanner;

public class ecodriving_jmv {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int J = in.nextInt(), R = in.nextInt(), M = in.nextInt();
		if (J == 1) {
			System.out.println(0);
			return;
		}
		double[] X = new double[J], Y = new double[J];
		double[][][] A = new double[J][J][J];
		double[][] G = new double[J][J], D = new double[J][J];
		double l, u, m, d;
		for (int i = 0; i < J; i++) {
			X[i] = in.nextInt();
			Y[i] = in.nextInt();
			for (int j = 0; j < J; j++) {
				G[i][j] = 1e30;
			}
		}
		for (int i = 0; i < R; i++) {
			int e = in.nextInt() - 1, f = in.nextInt() - 1;
			G[e][f] = Math.sqrt((X[e] - X[f]) * (X[e] - X[f]) + (Y[e] - Y[f]) * (Y[e] - Y[f]));
		}
		for (int i = 0; i < J; i++) {
			for (int j = 0; j < J; j++) {
				for (int k = 0; k < J; k++) {
					if (G[i][j] < 1e30 && G[j][k] < 1e30) {
						A[i][j][k] = Math.acos(-((X[i] - X[j]) * (X[k] - X[j]) + (Y[i] - Y[j]) * (Y[k] - Y[j])) / G[i][j] / G[j][k]);
					}
					else {
						A[i][j][k] = 1e30;
					}
				}
			}
		}
		
		for (l = -1e-9, u = Math.acos(-1) + 3e-9, m = (l + u) / 2; l + 1e-12 < m; m = (l + u) / 2) {
			PriorityQueue<Node> Q = new PriorityQueue<Node>();
			for (int i = 0; i < J; i++) {
				for (int j = 0; j < J; j++) {
					D[i][j] = 1e30;
				}
				if (G[0][i] < 1e30) {
					D[0][i] = G[0][i];
					Q.add(new Node(D[0][i], 0, i));
//					System.err.printf("Added node {%.3f, %d, %d}\n", D[0][i], 0, i);
				}
				D[0][0] = 0;
			}
			boolean ok = false;
			while (!Q.isEmpty()) {
				Node n = Q.poll();
//				System.err.printf("Popped node {%.3f, %d, %d}\n", n.d, n.e, n.f);
				if (n.d > M) {
					break;
				}
				if (n.f == J - 1) {
					ok = true;
					break;
				}
				if (n.d > D[n.e][n.f]) {
					continue;
				}
				for (int g = 0; g < J; g++) {
//					System.err.printf("Angle to node %d is %.4f\n", g, A[n.e][n.f][g] * 180 / Math.acos(-1));
					if (A[n.e][n.f][g] <= m) {
						if (D[n.e][n.f] + G[n.f][g] < D[n.f][g]) {
							D[n.f][g] = D[n.e][n.f] + G[n.f][g];
							Q.add(new Node(D[n.f][g], n.f, g));
//							System.err.printf("Added node {%.3f, %d, %d}\n", D[n.f][g], n.f, g);
						}
					}
				}
			}
//			System.err.printf("\nResults with m=%.12f: %s\n\n\n", m, ok ? "OK" : "NO");
			if (ok) {
				u = m;
			}
			else {
				l = m;
			}
		}
		System.out.println(m - 1e-9 > Math.acos(-1) ? "Impossible" : m * 180 / Math.acos(-1));
	}
	
	static class Node implements Comparable<Node> {
		double d;
		int e, f;
		
		Node(double d, int e, int f) {
			this.d = d;
			this.e = e;
			this.f = f;
		}
		
		public int compareTo(Node n) {
			return d == n.d ? 0 : d < n.d ? -1 : 1;
		}
	}
}
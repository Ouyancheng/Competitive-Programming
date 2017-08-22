import java.util.*;
import java.math.*;
import java.io.*;

public class CHEFMOVR {
	public static void main(String[] args) throws IOException {
		//System.setProperty("line.separator", "\n");
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		//String line;

		int t = in.nextInt();

		while (t-- > 0) {
			// remember to comment out line separator setting before submission
			int n = in.nextInt();
			int k = in.nextInt();
			long sum = 0, ans = 0;
			long arr[] = new long[n];
			boolean flag = true;
			for (int i = 0; i < n; i++) {
				arr[i] = in.nextInt();
				sum += arr[i];
			}
			if(sum % n != 0) {
				out.println(-1);
			} else {
				int div = (int) (sum/n);
				long tmp = 0;
				for (int i = 0; i < n; i++) {
					if(i + k < n && arr[i] < div) {
						tmp = div - arr[i];
						ans += tmp;
						arr[i] += tmp;
						arr[i+k] -= tmp;
					} else if(i + k < n && arr[i] > div) {
						tmp = arr[i] - div;
						ans += tmp;
						arr[i] -= tmp;
						arr[i+k] += tmp;
					}
				}

				for (int i = 0; i < n; i++) {
					if(arr[i] != div) {
						flag = false;
						break;
					}
				}
				if(flag) {
					out.println(ans);
				} else {
					out.println(-1);
				}
			}
		}
		in.close();
		out.close();
	}

	/* Utility classes and methods */
	public static boolean nextPerm(int[] p) {
		for (int a = p.length - 2; a >= 0; --a)
			if (p[a] < p[a + 1])
				for (int b = p.length - 1;; --b)
					if (p[b] > p[a]) {
						int t = p[a];
						p[a] = p[b];
						p[b] = t;
						for (++a, b = p.length - 1; a < b; ++a, --b) {
							t = p[a];
							p[a] = p[b];
							p[b] = t;
						}
						return true;
					}
		return false;
	}

	static class Pair<X extends Comparable<X>,Y extends Comparable<Y>> implements Comparable<Pair<X,Y>> {
		X x;
		Y y;

		public Pair(X a,Y b) {
			x = a;
			y = b;
		}

		@Override
			@SuppressWarnings("unchecked")
			public boolean equals(Object p) {
				if(!(p instanceof Pair)) return false;
				return compareTo((Pair<X,Y>) p) == 0;
			}

		@Override
			public int compareTo(Pair<X,Y> p) {
				int xres = p.x.compareTo(x), yres = p.y.compareTo(y);
				if(xres == 0 && yres == 0) {
					return 0;
				} else if(xres >= 0) {
					if(xres > 0) {
						return -1;
					} else {
						return (yres > 0) ? -1 : 1;
					}
				} else {
					return 1;
				}
			}

		@Override
			public int hashCode() {
				return Objects.hash(x,y);
			}

		@Override
			public String toString() {
				return "(" + x + "," + y + ")";
			}
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastReader(String name) throws IOException {
            br = new BufferedReader(new FileReader(name));
        }

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String readLine() {
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		void close() {
			try {
				br.close();
			} catch(IOException e) {
				e.printStackTrace();
			}
		}
	}
}

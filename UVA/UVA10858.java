import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		System.setProperty("line.separator", "\n");
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		Vector<Integer> s = new Vector<>();
		Vector<Vector<Integer>> res = new Vector<>();
		while (true) {
			int n = in.nextInt();
			if(n == 0) break;
			Vector<Integer> v = factor(n);
			if(v.isEmpty()) {
				out.println(0);
			} else {
				s.clear();
				res.clear();
				dfs(n,0,v,s,res);
				out.println(res.size());
				for(int i = 0; i < res.size(); i++) {
					for(int j = 0; j < res.get(i).size()-1; j++) {
						out.print(res.get(i).get(j) + " ");
					}
					out.println(res.get(i).get(res.get(i).size()-1));
				}
			}
		}
		in.close();
		out.close();
	}

	public static Vector<Integer> factor(int n) {
		int t = n;
		Vector<Integer> factors = new Vector<>();
		if(n == 0) return factors;
		for(int i = 2; i*i <= n && t > 1; i++) {
			if(t % i == 0) {
				factors.add(i);
				if(t/i != i) factors.add(t/i);
			}
		}
		Collections.sort(factors);
		return factors;
	}

	public static void dfs(int n,int cur,Vector<Integer> factors,Vector<Integer> s,Vector<Vector<Integer>> res) {
		if(n == 1) {
			res.add(new Vector<Integer>());
			for(int i = 0; i < s.size(); i++) {
				res.get(res.size()-1).add(s.get(i));
			}
			s.removeElementAt(s.size()-1);
			return;
		}
		for(int i = cur; i < factors.size(); i++) {
			if(n % factors.get(i) == 0) {
				s.add(factors.get(i));
				dfs(n/factors.get(i),i,factors,s,res);
			}
		}
		if(s.size() > 0) s.removeElementAt(s.size()-1);
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

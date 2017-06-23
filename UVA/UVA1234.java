import java.util.*;
import java.io.*;

class Main {
	static int[] parent = new int[10000],rank = new int[10000];

	@SuppressWarnings("unchecked")
		public static int root(int p) {
			if(parent[p] == p) return p;
			return parent[p] = root(parent[p]);
		}

	public static void main(String[] args) throws Exception {
		IntegerScanner io = new IntegerScanner(System.in);
		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int cc = io.nextInt();
		while(cc-- >= 1) {
			int V = io.nextInt(), E = io.nextInt(), t = 0;
			Vector < IntegerTriple > EdgeList = new Vector < IntegerTriple >();

			for (int i = 0; i < E; i++) {
				int u = io.nextInt()-1, v = io.nextInt()-1, w = io.nextInt();
				EdgeList.add(new IntegerTriple(w, u, v));
				EdgeList.add(new IntegerTriple(w, v, u));
				t += w;
			}
			for(int i = 0; i < V; i++) {
				parent[i] = i;
				rank[i] = 1; 
			}
			Collections.sort(EdgeList,Collections.reverseOrder());

			int i,cost = 0, c = 0;
			for (i = 0; i < EdgeList.size() && c < V; i++) {
				IntegerTriple e = EdgeList.get(i);
				int u = e.second(), v = e.third(), w = e.first();
				int p = root(u), q = root(v);
				if (p != q) {
					cost += w;
					c++;
					if(rank[p] > rank[q]) {
						parent[q] = p;
						rank[p]+=rank[q];
					} else {
						parent[p] = q;
						rank[q]+=rank[p];
					}
				}
			}
			pr.println(t-cost);
		}
		pr.close();
	}
}

class IntegerTriple implements Comparable<IntegerTriple> {
	Integer _first, _second, _third;

	public IntegerTriple(Integer f, Integer s, Integer t) {
		_first = f;
		_second = s;
		_third = t;
	}

	public int compareTo(IntegerTriple o) {
		if (!this.first().equals(o.first()))
			return this.first() - o.first();
		else if (!this.second().equals(o.second()))
			return this.second() - o.second();
		else
			return this.third() - o.third();
	}

	Integer first() { return _first; }
	Integer second() { return _second; }
	Integer third() { return _third; }

	public String toString() { return first() + " " + second() + " " + third(); }
}

class IntegerScanner {
	BufferedInputStream bis;
	IntegerScanner(InputStream is) {
		bis = new BufferedInputStream(is, 1000000);
	}

	public int nextInt() {
		int result = 0;
		try {
			int cur = bis.read();
			if (cur == -1)
				return -1;

			while ((cur < 48 || cur > 57) && cur != 45) {
				cur = bis.read();
			}

			boolean negate = false;
			if (cur == 45) {
				negate = true;
				cur = bis.read();
			}

			while (cur >= 48 && cur <= 57) {
				result = result * 10 + (cur - 48);
				cur = bis.read();
			}

			if (negate) {
				return -result;
			}
			return result;
		}
		catch (IOException ioe) {
			return -1;
		}
	}
}

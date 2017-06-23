import java.util.*;
import java.io.*;

class Main {
	static int[] parent = new int[1000],rank = new int[1000];

	@SuppressWarnings("unchecked")
		public static int root(int p) {
			if(parent[p] == p) return p;
			return parent[p] = root(parent[p]);
		}

	public static void main(String[] args) throws Exception {
		IntegerScanner io = new IntegerScanner(System.in);
		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int cc = 1;
		while(true) {
			int V = io.nextInt(), E = io.nextInt();
			if(V == 0 && E == 0) break;
			//System.out.println("case: " + cc++);
			Vector < IntegerTriple > EdgeList = new Vector < IntegerTriple >();
			Vector<Integer> ans = new Vector<Integer>();
			HashMap<Integer,Integer> inMST = new HashMap<Integer,Integer>();

			for (int i = 0; i < E; i++) {
				int u = io.nextInt(), v = io.nextInt(), w = io.nextInt();
				EdgeList.add(new IntegerTriple(w, u, v));
				EdgeList.add(new IntegerTriple(w, v, u));
			}
			for(int i = 0; i < V; i++) {
				parent[i] = i;
				rank[i] = 1; 
			}
			Collections.sort(EdgeList);

			int i;
			for (i = 0; i < EdgeList.size(); i++) {
				IntegerTriple e = EdgeList.get(i);
				int u = e.second(), v = e.third(), w = e.first();
				int p = root(u), q = root(v);
				if (p != q) {
					if(rank[p] > rank[q]) {
						parent[q] = p;
						rank[p]+=rank[q];
					} else {
						parent[p] = q;
						rank[q]+=rank[p];
					}
				} else if(!inMST.containsKey(w)){
					ans.add(w);
				}
				inMST.put(w,1);
			}
			if(ans.size() == 0) {
				pr.println("forest");
			} else {
				pr.print(ans.get(0));
				for(int it = 1; it < ans.size(); it++) {
					pr.print(" " + ans.get(it));
				}
				pr.println();
			}
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

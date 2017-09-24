import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		//System.setProperty("line.separator", "\n");
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		//String line;

		// int t = in.nextInt();

		// while (t-- > 0) {

		// }
		int n = in.nextInt(), even = 0, odd = 0, sum = 0;

		for (int i = 0; i < n; i++) {
			int a = in.nextInt();
			if((a & 1) == 1) {
				odd++;
			} else {
				even++;
			}
			sum += a;
		}
		if((sum & 1) == 1) {
			out.println("First");
		} else if(odd == 0) {
			out.println("Second");
		} else if(!(--odd >= 2 || even >= 1)) {
			out.println("First");
		} else {
			out.println("First");
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

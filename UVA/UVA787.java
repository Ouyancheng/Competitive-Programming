import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		System.setProperty("line.separator", "\n");
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		String line;

		while ((line = in.readLine()) != null) {
			String tmp[] = line.split("\\s+");
			BigInteger arr[] = new BigInteger[tmp.length - 1];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = new BigInteger(tmp[i]);
			}
			out.println(solve(arr));
		}
		in.close();
		out.close();
	}

	public static BigInteger solve(BigInteger arr[]) {
		BigInteger ans = new BigInteger(Integer.MIN_VALUE + "");
		BigInteger tmpmax = new BigInteger("1");
		BigInteger tmpmin = new BigInteger("1");

		for (int i = 0; i < arr.length; i++) {
			BigInteger tmp1 = new BigInteger(tmpmax+"");
			BigInteger tmp2 = new BigInteger(tmpmin+"");
			tmpmax = max(tmp1.multiply(arr[i]),max(tmp2.multiply(arr[i]),arr[i]));
			tmpmin = min(tmp1.multiply(arr[i]),min(tmp2.multiply(arr[i]),arr[i]));
			ans = max(ans,tmpmax);
		}
		return ans;
	}

	public static BigInteger max(BigInteger b1, BigInteger b2) {
		return (b1.compareTo(b2) > 0) ? b1 : b2;
	}

	public static BigInteger min(BigInteger b1, BigInteger b2) {
		return (b1.compareTo(b2) < 0) ? b1 : b2;
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

				static class Pair<X extends Comparable<X>, Y extends Comparable<Y>> implements Comparable<Pair<X, Y>> {
					X x;
					Y y;

					public Pair(X a, Y b) {
						x = a;
						y = b;
					}

					@Override
					@SuppressWarnings("unchecked")
					public boolean equals(Object p) {
						if (!(p instanceof Pair)) return false;
						return compareTo((Pair<X, Y>) p) == 0;
					}

					@Override
					public int compareTo(Pair<X, Y> p) {
						int xres = p.x.compareTo(x), yres = p.y.compareTo(y);
						if (xres == 0 && yres == 0) {
							return 0;
						} else if (xres >= 0) {
							if (xres > 0) {
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
						return Objects.hash(x, y);
					}

					@Override
					public String toString() {
						return "(" + x + "," + y + ")";
					}
				}
			}
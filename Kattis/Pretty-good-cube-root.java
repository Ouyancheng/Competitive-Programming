import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
	public static BigInteger go(String s) {
		BigInteger lo = BigInteger.ONE;
		BigInteger hi = new BigInteger(s);
		BigInteger ans = null;
		final BigInteger f = new BigInteger(s);

		for(int i = 0; i < 1655 && hi.subtract(lo).compareTo(BigInteger.ONE) > 0; i++) {
			BigInteger mid = lo.add(hi).shiftRight(1);
			BigInteger res = mid.multiply(mid).multiply(mid);
			int cmp = res.compareTo(f);
			if(cmp >= 0) {
				hi = mid.add(BigInteger.ZERO);
			} else {
				lo = mid.add(BigInteger.ZERO);
			}
		}
		if(lo.equals(hi)) {
			return lo;
		}
		BigInteger t1 = lo.multiply(lo).multiply(lo);
		BigInteger t2 = hi.multiply(hi).multiply(hi);

		if(t1.subtract(f).abs().compareTo(t2.subtract(f).abs()) <= 0) {
			return lo;
		} else {
			return hi;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);

		String s;

		while((s = in.readLine()) != null) {
			out.println(go(s));
		}
		in.close();
		out.close();
	}
}

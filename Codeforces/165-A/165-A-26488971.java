import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static boolean isright(Pair<Integer,Integer> p1,Pair<Integer,Integer> p2) {
		return p2.x > p1.x && p2.y.equals(p1.y);
	}
	public static boolean isleft(Pair<Integer,Integer> p1,Pair<Integer,Integer> p2) {
		return p2.x < p1.x && p2.y.equals(p1.y);
	}
	public static boolean islower(Pair<Integer,Integer> p1,Pair<Integer,Integer> p2) {
		return p2.y < p1.y && p2.x.equals(p1.x);
	}
	public static boolean isupper(Pair<Integer,Integer> p1,Pair<Integer,Integer> p2) {
		return p2.y > p1.y && p2.x.equals(p1.x);
	}
	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		PrintWriter out = new PrintWriter(System.out);
		int a, b, ans = 0;
		int n = in.nextInt();
		Vector<Pair<Integer,Integer>> arr = new Vector<Pair<Integer,Integer>>();

		for(int i = 0; i < n; i++) {
			a = in.nextInt();
			b = in.nextInt();
			arr.add(new Pair<Integer,Integer>(a,b));
		}
		for(int i = 0; i < n; i++) {
			int left = 0, right = 0, up = 0, down = 0;
			for(int j = 0; j < n ; j++) {
				if(i == j) continue;
				if(isright(arr.get(i),arr.get(j))) {
					right++;
				} else if(isleft(arr.get(i),arr.get(j))) {
					left++;
				} else if(islower(arr.get(i),arr.get(j))) {
					down++;
				} else if(isupper(arr.get(i),arr.get(j))) {
					up++;
				}
				if(left > 0 && right > 0 && up > 0 && down > 0)
					break;
			}
			if(left > 0 && right > 0 && up > 0 && down > 0)
				ans++;
		}
		out.println(ans);
		out.close();
	}

	static class Pair<X,Y> {
		X x;
		Y y;

		public Pair(X x,Y y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return "(" + x + "," + y + ")";
		}
	}

	// Fast input class
	static class Reader
	{
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader()
		{
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException
		{
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException
		{
			byte[] buf = new byte[1000]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1)
			{
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException
		{
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
			{
				ret = ret * 10 + c - '0';
			}  while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException
		{
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException
		{
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');

			if (c == '.')
			{
				while ((c = read()) >= '0' && c <= '9')
				{
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException
		{
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException
		{
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException
		{
			if (din == null)
				return;
			din.close();
		}
	}
}
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	static int n;
	static HashMap<Integer,Integer> map = new HashMap<>();
	static int arr[];
	static int dist;
	static long ans = 0;
	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		PrintWriter out = new PrintWriter(System.out);
		n = in.nextInt();
		arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = in.nextInt();
		}
		Arrays.sort(arr);
		dist = arr[n-1]-arr[0];
		for(int i = 0; i < n; i++) {
			if(map.containsKey(arr[i]-dist)) {
				ans += map.get(arr[i]-dist);
			}
			if(map.containsKey(arr[i])) {
				map.put(arr[i],map.get(arr[i])+1);
			} else {
				map.put(arr[i],1);
			}
		}
		out.println(dist + " " + ans);
		out.close();
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

		public String next() throws IOException
		{
			byte[] buf = new byte[10000]; // line length
			int cnt = 0, c;
			Boolean white;
			while ((c = read()) != -1)
			{
				white = Character.isWhitespace(c);
				if (white && cnt > 0)
					break;
				if(!white) {
					buf[cnt++] = (byte) c;
				}
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
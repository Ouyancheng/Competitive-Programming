import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		int k = in.nextInt();
		int arr[] = new int[n+1];

		for(int i = 0; i < n; i++) {
			arr[i] = in.nextInt();
		}

		int lo = 0, hi = 0, max_win = 1, a = 0, b = 0;
		int cnt[] = new int[(int)(1e6+1)];
		cnt[arr[0]]++;
		int u = 1;

		while(true) {
			while(true) {
				if(hi == n-1) break;
				boolean c = cnt[arr[hi+1]] == 0;
				if(c && u == k) break;
				if(c) u++;
				cnt[arr[hi+1]]++;
				hi++;
			}
			if(hi - lo + 1 > max_win) {
				a = lo; b = hi;
				max_win = Math.max(max_win,hi - lo + 1);
			}
			while(lo <= hi && u == k) {
				if(cnt[arr[lo]] == 1) u--;
				cnt[arr[lo++]]--;
			}
			if(hi == n-1) break;
		}
		out.println((a+1) + " " + (b+1));
		
		in.close();
		out.close();
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
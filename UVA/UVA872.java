import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;
import java.util.HashSet;

class Main {
	public static void t(HashMap<Integer,ArrayList<Integer>> conn,int cur,Stack<Integer> s,HashSet<Integer> hs) {
		ArrayList<Integer> adj = conn.get(cur);
		hs.add(cur);
		for(int i = 0; i < adj.size(); i++) {
			if(!hs.contains(adj.get(i))) {
				t(conn,adj.get(i),s,hs);
			}
		}
		s.push(cur);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(true) {
			int N = in.nextInt();
			int M = in.nextInt();
			if(N == 0) {
				break;
			}
			HashMap<Integer,ArrayList<Integer>> conn = new HashMap<Integer,ArrayList<Integer>>();
			StringBuffer buf = new StringBuffer();
			Stack<Integer> s = new Stack<Integer>();
			HashSet<Integer> hs = new HashSet<Integer>();

			for(int i = 0; i < M; i++) {
				int c = in.nextInt();
				if(!conn.containsKey(c)) {
					conn.put(c,new ArrayList<Integer>());
				}
				conn.get(c).add((in.nextInt()));
			}
			for(int i = 1; i <= N; i++) {
				if(!conn.containsKey(i)) {
					conn.put(i,new ArrayList<Integer>());
				}
			}
			//System.out.println(conn);
			for(int i = 1; i <= N; i++) {
				if(!hs.contains(i)) {
					t(conn,i,s,hs);
				}
			}
			while(!s.empty()) {
				buf.append(s.pop() + " ");
			}
			System.out.println(buf.delete(buf.length()-1,buf.length()));
		}
	}
}

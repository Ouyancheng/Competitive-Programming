import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
	public static int find(int e,int[] par) {
		if(par[e] != e) {
			int r = find(par[e],par);
			par[e] = r;
			return r;
		}
		return e;
	}

	public static void union(int s,int d,int[] par,int[] rank) {
		int r1 = find(s,par),r2 = find(d,par);
		if(r1 != r2) {
			if(rank[r1] > rank[r2]) {
				par[r2] = r1;
				rank[r1]+=rank[r2];
			} else {
				par[r1] = r2;
				rank[r2]+=rank[r1];
			}
		}
	}

	public static boolean sameSet(int s,int d,int[] par) {
		return find(s,par) == find(d,par);
	}
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int[] p = new int[in.nextInt()+1];
        int q = in.nextInt();
        int[] r = new int[p.length];
        Arrays.fill(r,1);
        
        for(int i = 0; i < p.length; i++) p[i] = i;
        
        while(q-- > 0) {
            switch(in.next()) {
                case "M":
                    union(in.nextInt(),in.nextInt(),p,r);
                    break;
                case "Q":
                    
                    System.out.println(r[find(in.nextInt(),p)]);
            }
        }
    }
}
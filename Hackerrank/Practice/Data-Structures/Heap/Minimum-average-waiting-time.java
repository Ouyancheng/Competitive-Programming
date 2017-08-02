import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Pair implements Comparable<Pair>{
    long t;
    long w;
    
    public Pair(long t,long w) {
        this.t = t;
        this.w = w;
    }
    
    public int compareTo(Pair p2) {
        if(this.t < p2.t) {
            return -1;
        } else if(this.t > p2.t) {
            return 1;
        }
        return 0;
    }
    
    public String toString() {
        return t + " " + w;
    }
}

class CompareDelay implements Comparator<Pair> {
    public int compare(Pair p1,Pair p2) {
        if(p1.w < p2.w) {
            return -1;
        } else if(p1.w > p2.w) {
            return 1;
        }
        return 0;       
    }
    
    public boolean equals(Pair p1,Pair p2) {
        return compare(p1,p2)==0;        
    }
}

public class Solution {
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>(1,new CompareDelay());
        Scanner in = new Scanner(System.in);
        int cc = in.nextInt();
        Pair[] cust = new Pair[cc];
        long time = 0;
        long delay = 0;

        while(cc-- > 0) {
            cust[cust.length-cc-1] = new Pair(in.nextLong(),in.nextLong());
        }
        Arrays.sort(cust);
        
        for(int i = 0; i  < cust.length || !pq.isEmpty();) {
            if(pq.isEmpty())
                time = Math.max(time,cust[i].t);
            while(i < cust.length && time >= cust[i].t) {
                pq.offer(cust[i++]);
            }
            //System.out.println(pq);
            time += pq.peek().w; // Cook the pizza
            delay += time-pq.poll().t; // Calculate the delay incurred
            //System.out.println(pq);
            //System.out.println();
        }
        System.out.println(delay/cust.length);
    }
}
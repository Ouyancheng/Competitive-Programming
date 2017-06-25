import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Node {
    boolean leaf;
    Node[] des;
    
    public Node(boolean l) {
        this.leaf = l;
        des = new Node[26];
        for(int i = 0; i < des.length; i++) {
            des[i] = null;
        }
    }
}

public class Solution {
    public static boolean insert(String s,Node cur) {
        boolean pre = false;
        for(int i = 0; i < s.length(); i++) {
            int ci = s.charAt(i)-97;
            if(cur.des[ci] == null) {
                cur.des[ci] = new Node(false);
            } else if(cur.des[ci].leaf) {
                pre = true;
            }
            if(i == s.length() - 1) {
                for(int j = 0; j < 26; j++) {
                    if(cur.des[ci].des[j] != null) {
                        pre = true;
                        break;
                    }
                }
                cur.des[ci].leaf = true;
            }
            cur = cur.des[ci];
        }
        return pre;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int sc = in.nextInt();
        Node root = new Node(false);
        for(int i = 0; i < sc; i++) {
            String s = in.next();
            if(insert(s,root)) {
                System.out.println("BAD SET");
                System.out.println(s);
                return;
            }
        }
        System.out.println("GOOD SET");
    }
}
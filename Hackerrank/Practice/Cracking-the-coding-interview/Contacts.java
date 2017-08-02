import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        TreeSet<String> s = new TreeSet<String>();
        int wc = in.nextInt();
        for(int i = 0; i < wc; i++) {
            String c = in.next();
            switch(c) 
            { 
                case "add":
                    c = in.next();
                    s.add(c);
                    break;
                case "find":
                    c = in.next();
                    System.out.println(s.subSet(c,c.substring(0,c.length()-1)+((char)(c.charAt(c.length()-1)+1))).size());
            }
        }
    }
}
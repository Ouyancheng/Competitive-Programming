import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
	SortedSet<String> dict = new TreeSet<String>();
	
	while(in.hasNext()) {
	  String[] words = in.next().split("[^a-zA-Z]");
	  for(String word : words) {
	    if(word.isEmpty()) continue;
	    dict.add(word.toLowerCase());
	  }
	}
	
	for(String s : dict) {
	  System.out.println(s);
	}
  }
}
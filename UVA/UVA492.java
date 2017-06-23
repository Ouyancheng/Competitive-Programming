import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<String> words = new ArrayList<String>(2000);
		StringBuilder out = new StringBuilder();

		while(in.hasNext()) {
			String[] arr = in.next().split("[^a-zA-Z]");
			for(String w : arr) {
				if(!w.isEmpty()) {
					words.add(w);
				}
			}
		}

		Result.procVowels(words);
		Result.procConsonants(words);

		for(int i = 0; i < words.size(); i++) {
			out.append(words.get(i)+" ");
		}
		out.delete(out.length()-1,out.length());
		out.append(".");
		System.out.println(out);
	}
}

class Result {
	// Processes words with preceeding vowels
	public static void procVowels(ArrayList<String> words) {
		for(int i = 0; i < words.size(); i++) {
			if(words.get(i).matches("^[aeiouAEIOU].*")) {
				words.set(i,words.get(i) + "ay");
			}
		}
	}

	// Processes words not preceeding with vowels
	public static void procConsonants(ArrayList<String> words) {

		int arrSize = words.size();

		for(int i = 0; i < arrSize; i++) {
			if(words.get(i).matches("[^aeiouAEIOU].*")) {
				words.set(i,(words.get(i).substring(1)+words.get(i).charAt(0)+"ay"));
			}
		}
	}
}

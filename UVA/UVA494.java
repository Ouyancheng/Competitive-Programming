import java.util.*;
import java.util.regex.*;

class Main {
	public static void main(String[] args) {
		// Declare Scanner object to read input
		Scanner in = new Scanner(System.in);

		// Read in the input
		
		//System.out.println(word_count);
		while(in.hasNextLine()) {
			System.out.println(countWords(in.nextLine()));
		}
	}

	// Counts the number of words that are present in
	// one line of text
	// Pre-condition: A string containing space delimited
	// words
	// Post-condition: An integer containing the number
	// of words in the string
	static int countWords(String line) {
		Pattern p  = Pattern.compile("[a-zA-Z]+");
		Matcher m  = null;
		
		// Variable to track the word count
		int word_count = 0;
		m = p.matcher(line);

		// Scan the input for words
		while(m.find()) {
			word_count += 1;
		}
		return word_count;
	}
}

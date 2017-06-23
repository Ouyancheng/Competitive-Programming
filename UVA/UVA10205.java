import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		int num_shuffles = in.nextInt();
		String[] values = { "2", "3", "4", "5", "6", "7", "8", "9", "10","Jack","Queen","King","Ace"};
		String[] suit = { "Clubs","Diamonds","Hearts","Spades" };
		ArrayList<String> deck = new ArrayList<String>();
		ArrayList<String> deck2 = new ArrayList<String>();

		// Temporary array to store all shuffle configurations
		int[] all_shuffles = null;

		// Process all test cases
		for(int i = 1; i <= cases; i++) {
			all_shuffles   = new int[num_shuffles*52];
			deck.clear();
			
			// Initialize a new deck
			for(String s : suit) {
				for(String v : values) {
					deck.add(v + " of " + s);
				}
			}


			// Read all shuffle configurations
			for(int j = 0; j < num_shuffles*52; j++) {
				all_shuffles[j] = in.nextInt();
			}
			String line = "";
			in.nextLine();
			while(in.hasNextLine() && !(line = in.nextLine()).isEmpty()) {
				int shuffle_num = Integer.parseInt(line)-1;
				// Apply observed shuffle config
				for(int s = 0; s < 52; s++) {
					// process the shuffle config accordingly
					// process...
					move(deck,deck2,all_shuffles[shuffle_num*52+s]-1);
				}
				
				deck = deck2;
				deck2 = new ArrayList<String>();
			}
			for(String s : deck) {
				System.out.println(s);
			}

			// Go to next test case
			if(in.hasNextInt()) {
				num_shuffles = in.nextInt();
				System.out.println();
			}
		}
	}

	public static void move(ArrayList<String> deck,ArrayList<String> dest,int pos) {
		dest.add(deck.get(pos));
	}
}

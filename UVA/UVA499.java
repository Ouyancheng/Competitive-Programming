import java.util.*;

class Main {
	public static void main(String[] args) {
		// Declare Scanner object to read input
		Scanner in = new Scanner(System.in);

		// Read in the input
		while(in.hasNextLine()) {
			// Read in next Line
			String line = in.nextLine();
			HashMap<String,Integer> occurMap = new HashMap<String,Integer>();
			ArrayList<String> maxList = new ArrayList<String>();
			int maxOccur = Integer.MIN_VALUE;

			// Count the occurence of each non-blank
			// letter
			for(int i = 0; i < line.length(); i++) {
				String ch = line.charAt(i) + "";
				if(!ch.matches("[a-zA-Z]")) continue;
				if(occurMap.containsKey(ch)) {
					occurMap.put(ch,occurMap.get(ch)+1);
				} else {
					occurMap.put(ch,1);
				}
				// Record the highest occurence number
				maxOccur = Math.max(maxOccur,occurMap.get(ch));
			}

			// Add char with highest frequency to arraylist
			for(String ch : occurMap.keySet()) {
				if(occurMap.get(ch) == maxOccur) {
					maxList.add(ch);
				}
			}

			// Sort the list based on ascii
			Collections.sort(maxList);
			for(String ch : maxList) {
				System.out.print(ch);
			}
			System.out.print(" ");
			System.out.println(maxOccur);
		}
	}
}

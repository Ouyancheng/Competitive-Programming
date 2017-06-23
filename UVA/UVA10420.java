import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		SortedMap<String,Integer> women = new TreeMap<>();
		int num_cases = in.nextInt();
		for(int i = 1; i <= num_cases; i++) {
			String country = in.next();
			if(women.containsKey(country)) {
				women.put(country,women.get(country)+1);
			} else {
				women.put(country,1);
			}
			in.nextLine();
		}
		for(String country : women.keySet()) {
			System.out.println(country + " " + women.get(country));
		}
	}
}

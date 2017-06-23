import java.util.*;

class Main {
	public static void main(String[] args) {
		// Declare Scanner object to read input
		Scanner in = new Scanner(System.in);
		int no_of_tests = in.nextInt();

		// Read in the test cases
		for(int i = 1; i <= no_of_tests; i++) {
			// process one test case
			int no_of_farmers = in.nextInt();
			double total = 0;
			for(int j = 1; j <= no_of_farmers; j++) {
				total += Solution.premium(in.nextInt(),in.nextInt(),in.nextInt());
			}
			System.out.println((int)total);
		}
	}
}

class Solution {
	// Compute premium based on parameters
	static double premium(double area,int num_animals,int quality) {
		return (area/num_animals) * quality * num_animals;
	}
}

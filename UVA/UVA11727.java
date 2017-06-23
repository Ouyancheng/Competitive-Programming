import java.util.Scanner;

class CuttingCost {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] line = new int[3];
		int numOfLines = in.nextInt();

		for(int i = 0; i < numOfLines; i++) {
			int max = 0;
			int maxIdx = -1;
			for(int j = 0; j < 3; j++) {
				line[j] = in.nextInt();
				maxIdx = (line[j] > max) ? j : maxIdx;
				max = Math.max(line[j],max);
			}
			int survivor = line[(maxIdx+3-1)%3] > line[(maxIdx+3+1)%3] ?
				line[(maxIdx+3-1)%3] : line[(maxIdx+3+1)%3];
			System.out.println("Case " + (i+1) + ": " + survivor);
		}
	}
}
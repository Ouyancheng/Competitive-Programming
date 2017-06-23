import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numOfTests = in.nextInt();
		for(int i = 1; i <= numOfTests; i++) {
			int numOfCalls = in.nextInt();
			long cost1 = 0,cost2 = 0;
			for(int j = 1; j <= numOfCalls; j++) {
				int callDur = in.nextInt();
				cost1 += 10 * (callDur/30 + 1);
				cost2 += 15 * (callDur/60 + 1);
			}
			System.out.print("Case " + i + ": ");
			System.out.print((cost1 <= cost2) ? "Mile " : "");
			System.out.print((cost1 >= cost2) ? "Juice " : "");
			System.out.println((cost1 < cost2) ? cost1 : cost2);
		}
	}
}
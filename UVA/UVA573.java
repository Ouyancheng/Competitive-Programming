import java.util.Scanner;

class Snail {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double hWell,climbDist,slideDist,fatigue,distClimbed;

		while(true) {
			// init variables
			hWell = in.nextDouble();
			climbDist = in.nextDouble();
			slideDist = in.nextDouble();
			fatigue = in.nextDouble()/100 * climbDist;
			distClimbed = climbDist;
			int curDay = 1;

			if(hWell == 0) {
				break;
			}
			//System.out.println("Height of well: " + hWell + " Climb Dist: " + climbDist + " Slide Dist: " + slideDist + " Fatigue: " + fatigue);
			// while snail has not reached bottom or top
			while(distClimbed >= 0 && distClimbed <= hWell) {
				climbDist = (curDay > 1) ? Math.max(climbDist - fatigue,0) : climbDist;
				// Snail climbs well
				distClimbed += (curDay > 1) ? climbDist : 0;
				// Snail slides down or remains on top
				distClimbed -= (distClimbed > hWell) ? 0 : slideDist;
				// Get the day that the snail reaches the top or bottom
				curDay += (distClimbed > hWell || distClimbed < 0) ? 0 : 1;
			}
			// print result
			System.out.println((distClimbed > hWell ? "success on day " : "failure on day ") + curDay);
		}
	}
}
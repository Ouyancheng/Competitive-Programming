import java.util.Scanner;
import java.util.Arrays;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int loanDur = 0;

		while((loanDur = in.nextInt()) >= 0) {
			double downPayment = in.nextDouble();
			double loanAmt = in.nextDouble();
			double valueOfCar = loanAmt + downPayment;
			Deprecate[] deprArr = new Deprecate[in.nextInt()+1];
			int curMonth = 1;
			double amntPerMonth = loanAmt/loanDur;
			String monthString = "";

			for(int i = 0; i < deprArr.length-1; i++) {
				deprArr[i] = new Deprecate(in.nextInt(),in.nextDouble());
			}
			deprArr[deprArr.length-1] = new Deprecate(loanDur+1,deprArr[deprArr.length-2].percent);
			valueOfCar *= 1-deprArr[0].percent;

			for(int i = 0; i + 1 < deprArr.length && valueOfCar <= loanAmt; i++) {
				while(curMonth >= deprArr[i].month && curMonth < deprArr[i+1].month && valueOfCar <= loanAmt) {
					valueOfCar *= 1 - deprArr[i].percent;
					loanAmt -= amntPerMonth;
					curMonth++;
				}
			}

			monthString = (curMonth - 1) != 1 ? "months" : "month"; 

			System.out.println((curMonth - 1) + " " + monthString);
		}
	}
}

class Deprecate {
	int month;
	double percent;

	public Deprecate(int m,double p) {
		month = m;
		percent = p;
	}

	public String toString() {
		return "(Month: " + month + ",Percent: " + percent + ")"; 
	}
}

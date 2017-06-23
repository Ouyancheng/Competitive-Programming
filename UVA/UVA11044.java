import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
	int cases  = in.nextInt();
	// Read in the cases
	for(int i = 1; i <= cases; i++) {
	  int rows = in.nextInt();
	  int cols = in.nextInt();
	  int r = ((rows - 2)%3 != 0) ? (rows - 2)/3+1 : (rows - 2)/3;
	  int c = ((cols - 2)%3 != 0) ? (cols - 2)/3+1 : (cols - 2)/3;
	  System.out.println(r*c);
	}
  }
}
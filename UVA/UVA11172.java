import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
	for(int i = 0; i < cases; i++) {
	  int num1 = in.nextInt();
	  int num2 = in.nextInt();
	  if(num1 == num2) System.out.println("=");
	  else if(num1 < num2) System.out.println("<");
	  else System.out.println(">");
	}
  }
}
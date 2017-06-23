import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		// Read in all the input
		while(in.hasNext()) {
			int initial = in.nextInt() * 9;
			int first   = in.nextInt() * 9;
			int second  = in.nextInt() * 9;
			int third   = in.nextInt() * 9;

			Lock l = new Lock(initial);
			int total = 0;

			if(first == second && second == third && first == 0) {
				break;
			}

			// Enter first set
			total = 720;
			total += l.turnCW(first);

			// Enter second set
			total += 360;
			total += l.turnACW(second);

			// Enter third set
			total += l.turnCW(third);

			// Print the result
			System.out.println(total);
		}
	}
}

class Lock {
	private int state;

	public Lock(int s) {
		state = s;
	}

	// Turns the lock in an anti-clockwise motion
	// Pre-condition: An integer containing the target degree
	// Post-condition: State of the lock is set to the given degree.
	// An int variable state must exist as an attribute.
	// Returns the degrees through which the lock was turned in an
	// anti-clockwise motion
	int turnACW(int deg) {
		int old_state = this.state;
		this.state = deg;
		return (deg < old_state) ? 360-(old_state-deg) : deg-old_state;
	}

	// Turns the lock in a clockwise motion
	// Pre-condition: An integer containing the target degree
	// Post-condition: State of the lock is set to the given degree.
	// An int variable state must exist as an attribute.
	// Returns the degrees through which the lock was turned in an
	// clockwise motion
	int turnCW(int deg) {
		int old_state = this.state;
		this.state = deg;
		return (deg < old_state) ? old_state-deg : 360-(deg-old_state);
	}

	// Retrieves the state of the lock
	// Pre-condition: An int variable state must exist as an attribute
	// Post-condition: The value of the attribute state
	int getState() {
		return state;
	}
}

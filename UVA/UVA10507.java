import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Brain {
	public static final boolean SLEEPING = true;
	public static final boolean AWAKE = false;

	public static void main(String[] args) {
		// Declare Scanner to read keyboard input
		Scanner in = new Scanner(System.in);

		// While there is more input from the keyboard
		while(in.hasNext()) {

		// Declare HashMap to hold nodes
		HashMap<Character,BrainArea> nodes = new HashMap<Character,BrainArea>();

		// Declare Queue to hold sleeping nodes
		Queue<BrainArea> sleepingNodes = new LinkedList<BrainArea>();

		// Declare and instatiate variable for number of nodes
		int noOfNodes = in.nextInt();

		// Declare and instatiate variabe for number of connections
		int noOfConn = in.nextInt();

		// Create the awake nodes in the HashMap
		char[] awakeNodes = in.next().toCharArray();
		for(char c : awakeNodes) {
			nodes.put(c,new BrainArea(c,AWAKE));
		}

		// Loop through the connections and create the nodes mapping
			// If node was not alr present, it must be sleeping
		for(int i = 0; i < noOfConn; i++) {
			char[] nxt = in.next().toCharArray();
			if(!nodes.containsKey(nxt[0])) {
				nodes.put(nxt[0],new BrainArea(nxt[0],SLEEPING));
				sleepingNodes.offer(nodes.get(nxt[0]));
			}
			if(!nodes.containsKey(nxt[1])) {
				nodes.put(nxt[1],new BrainArea(nxt[1],SLEEPING));
				sleepingNodes.offer(nodes.get(nxt[1]));
			}
			nodes.get(nxt[0]).neighbours.add(nodes.get(nxt[1]));
			nodes.get(nxt[1]).neighbours.add(nodes.get(nxt[0]));
		}

		// Declare counter for year
		int year = 0;

		// Declare variable to hold no. of awake nodes
		int noOfAwakeNodes = 3;

		// Declare temp ArrayList to hold nodes to wake up
		ArrayList<BrainArea> toWakeUp = new ArrayList<BrainArea>();

		// While no of awake nodes != no of nodes
		while(noOfAwakeNodes != noOfNodes) {
			// Get the next node out from the queue
			for(int j = 0; j < sleepingNodes.size(); ) {

				BrainArea curBA = sleepingNodes.peek();

				// Try to find 3 awake neighbours
				ArrayList<BrainArea> nbr = curBA.neighbours;
				int noOfAwakeNbr = 0;

				for(int i = 0; i < nbr.size(); i++) {
					// 3 awake neighbours found, node is awakened (on the next yr)
					if(!nbr.get(i).isAsleep) {
						noOfAwakeNbr++;
					}
					if(noOfAwakeNbr == 3) {
						toWakeUp.add(curBA);
						break;
					}
				}			
				// Remove node from queue
				// Otherwise, put the node at the back of the queue
				sleepingNodes.poll();
				if(noOfAwakeNbr < 3) {
					sleepingNodes.offer(curBA);
					j++;
				}
			}

			// If there are no nodes to wake, end the loop
			if(toWakeUp.isEmpty()) {
				break;
			} else {
				// Otherwise increment the yr and wake the nodes
				// Clear the tmp ArrayList
				year++;
				for(BrainArea n : toWakeUp) {
					noOfAwakeNodes++;
					n.isAsleep = AWAKE;
				}
				toWakeUp.clear();
			}
		}
		// If no of awake nodes == no of nodes, print out year
		// Otherwise print out brain never wakes up
		System.out.println(noOfAwakeNodes == noOfNodes ? "WAKE UP IN, " + year + ", YEARS" : "THIS BRAIN NEVER WAKES UP");
		}
	}
}

class BrainArea {
	// Declare variable to hold value
	char alpha;
	
	// Declare boolean to indicate status
	boolean isAsleep;

	// Declare ArrayList to hold neighbours
	ArrayList<BrainArea> neighbours;

	// Declare constructor
	public BrainArea(char a,boolean as) {
		alpha = a;
		isAsleep = as;
		neighbours = new ArrayList<BrainArea>();
	}
}
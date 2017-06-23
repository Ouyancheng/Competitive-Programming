import java.util.*;

class Pair
{
	int time;
	String direction;

	Pair(int t,String d)
	{
		this.time = t;
		this.direction = d;
	}

	public String toString()
	{
		return time + " " + direction;
	}
}

class Main
{
	public static void main(String[] args)
	{
		boolean debug = false;
		Queue<Pair> leftBank = new LinkedList<Pair>();
		Queue<Pair> rightBank = new LinkedList<Pair>();
		Queue<Integer> leftTimes = new LinkedList<Integer>();
		Queue<Integer> rightTimes = new LinkedList<Integer>();
		Queue<Pair> unload = new LinkedList<Pair>();

		Scanner in = new Scanner(System.in);

		int cases = in.nextInt();

		for(int i = 0; i < cases; i++)
		{
			int max_load = in.nextInt();
			int ferry_time = in.nextInt();
			int num_cars = in.nextInt();
			int current_time = 0;
			String direction = "left";
			Pair[] carPairs = new Pair[num_cars];
			int carPairs_index = 0;

			for(int j = 0; j < num_cars; j++)
			{
				Pair p = new Pair(in.nextInt(),in.next());
				carPairs[carPairs_index++] = p;
				if(p.direction.equals("left"))
				{
					leftBank.offer(p);
				}
				else
				{
					rightBank.offer(p);
				}
			}

			// Process the queues of the left and right banks
			while(!leftBank.isEmpty() || !rightBank.isEmpty())
			{
				int ferry_load = 0;
				if(debug)
				{
					System.out.println((direction.equals("left") ? "LEFT" : "Left") + " Bank:");
					System.out.println(leftBank);
					System.out.println((direction.equals("right") ? "RIGHT" : "Right") + " Bank:");
					System.out.println(rightBank);
				}
				if(debug)
				{
					System.out.println("Ferry is waiting on " + direction + "bank.");
					System.out.println("Current time is: " + current_time);
				}

				// Go to other bank if cars over there arrive earlier than the ones at the current bank
				// Simulates the waiting state
				if((direction.equals("left") && !leftBank.isEmpty() && leftBank.peek().time > current_time) ||
						(direction.equals("right") && !rightBank.isEmpty() && rightBank.peek().time > current_time))
				{
					if((direction.equals("left")))
					{
						current_time = (!rightBank.isEmpty() && rightBank.peek().time < leftBank.peek().time) ?
							Math.max(rightBank.peek().time,current_time) + ferry_time : leftBank.peek().time;
						direction = (!rightBank.isEmpty() && rightBank.peek().time < leftBank.peek().time) ? "right" : direction;
					}
					else
					{
						current_time = (!leftBank.isEmpty() && leftBank.peek().time < rightBank.peek().time) ?
							Math.max(leftBank.peek().time,current_time)  + ferry_time : rightBank.peek().time;
						direction = (!leftBank.isEmpty() && leftBank.peek().time < rightBank.peek().time) ? "left" : direction;
					}
				}
				else
				{
					if((direction.equals("left") && leftBank.isEmpty()))
					{
						current_time = Math.max(current_time + ferry_time,rightBank.peek().time + ferry_time);
						direction = "right";
					}
					else if(direction.equals("right") && rightBank.isEmpty())
					{
						current_time = Math.max(current_time + ferry_time,leftBank.peek().time + ferry_time);
						direction = "left";
					}
				}

				if(debug)
				{
					System.out.println("Now, ferry is waiting on " + direction + "bank.");
					System.out.println("Now, current time is: " + current_time);
				}

				// Load the cars on the current bank
				switch(direction)
				{
					case "left":
						while(!leftBank.isEmpty() && leftBank.peek().time <= current_time && ferry_load < max_load)
						{
							unload.offer(leftBank.poll());
							ferry_load++;
						}
						break;
					case "right":
						while(!rightBank.isEmpty() && rightBank.peek().time <= current_time && ferry_load < max_load)
						{
							unload.offer(rightBank.poll());
							ferry_load++;
						}
				}
				// Ferry the cars to the opposite bank
				current_time += ferry_time;
				direction = (direction.equals("left")) ? "right" : "left";

				if(debug)
				{
					System.out.println("After transport, ferry is waiting on " + direction + "bank.");
					System.out.println("After transport, current time is: " + current_time);
					System.out.println("--------------------------------------------------");
				}
				// Save out the time at which the cars are unloaded
				while(!unload.isEmpty())
				{
					if(unload.poll().direction.equals("left"))
					{
						leftTimes.offer(current_time);
					}
					else
					{
						rightTimes.offer(current_time);
					}
				}
			}
			for(int index = 0; index < num_cars; index++)
			{
				System.out.println(carPairs[index].direction.equals("left") ? leftTimes.poll() : rightTimes.poll());
			}
			if(i < cases - 1)
			{
				System.out.println();
			}
		}
	}
}

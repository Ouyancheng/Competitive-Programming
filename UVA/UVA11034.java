import java.util.*;

class Car
{
    int length;
    String direction;

    public Car(int l,String d)
    {
        this.length = l;
        this.direction = d;
    }

    public String toString()
    {
        return this.length + " " + this.direction;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        Queue<Car> leftBank = new LinkedList<Car>();
        Queue<Car> rightBank = new LinkedList<Car>();
        Queue<Car> ferry = new LinkedList<Car>();
        Queue<Car> inputQueue = new LinkedList<Car>();

        int numOfCases = in.nextInt();

        for(int caseNum = 1; caseNum <= numOfCases; caseNum++)
        {
            int ferryLength = in.nextInt() * 100;
            int numOfCars = in.nextInt();
            Car[] cars = new Car[numOfCars];
            Queue<Car> currentBank = leftBank;
            int ferryTrips = 0;
            int ferryLoad = 0;

            // Process all the car data in data file and store
            // them into queues
            for(int carNum = 1; carNum <= numOfCars; carNum++)
            {
                // Create car objects and save them in order into
                // a queue
                // This is for printing out final result in sequence
                cars[carNum-1] = new Car(in.nextInt(),in.next());
                inputQueue.offer(cars[carNum-1]);
                
                // Queue the cars at the left and right banks
                if(cars[carNum-1].direction.equals("left"))
                {
                    leftBank.offer(cars[carNum-1]);
                }
                else
                {
                    rightBank.offer(cars[carNum-1]);
                }
            }

            while(!leftBank.isEmpty() || !rightBank.isEmpty())
            {
                // If current bank has no cars, go to opposite bank
                if(currentBank.isEmpty())
                {
                    currentBank = (currentBank == leftBank) ? rightBank : leftBank;
                    ferryTrips++;
                }
                // Load the cars from the current bank until the bank is empty 
                // or the ferry cannot load any more
                while(!currentBank.isEmpty() && ferryLoad + currentBank.peek().length <= ferryLength)
                {
                    Car c = currentBank.poll();
                    ferryLoad += c.length;
                    ferry.offer(c);
                }

                // Go to opposite bank
                currentBank = (currentBank == leftBank) ? rightBank : leftBank;
                ferryTrips++;

                // Empty the ferry load each time the ferry is on
                // a different bank
                while(!ferry.isEmpty())
                {
                    Car c = ferry.poll();
                    ferryLoad -= c.length;
                }
	    }
	    // Print the total trip count
	    System.out.println(ferryTrips);

	    if(debug)
	    {
		    System.out.println("Left Bank:");
		    System.out.println(leftBank);
		    System.out.println("Right Bank:");
		    System.out.println(rightBank);
	    }
	}
    }
}

import java.util.Scanner;

class Main
{
	public static void main(String[] args)
	{
		int num_trains = 0;
		String can_arrange = "";
		Scanner in = new Scanner(System.in);

		while(true)
		{
			num_trains = in.nextInt();
			if(num_trains == 0) break;
			int[] order = new int[num_trains];
			/* Process one block */
			while(true)
			{
				can_arrange = "Yes";
				int index = 0;
				int max_so_far = 0;
				while(index < num_trains)
				{
					/* Get one configuration */
					order[index++] = in.nextInt();
					if(index > 0 && order[0] == 0) break;
				}

				if(order[0] == 0) break;

				max_so_far = order[0];

				/* process the configuration */
				for(index = 1; index < num_trains; index++)
				{
					max_so_far = (int) Math.max(order[index],max_so_far);
					if(max_so_far > order[index] && order[index] > order[index-1])
					{
						can_arrange = "No";
						break;
					}
				}
				System.out.println(can_arrange);
			}
			System.out.println();
		}
	}
}

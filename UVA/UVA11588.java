import java.util.*;

class Main
{
	public static void main(String[] args) throws java.io.IOException
	{
		java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int cases = Integer.parseInt(in.readLine());
		String[] data = null;
		String[] image = null;
		int index = 0;
		HashMap<String,Integer> regions = null;
		int result = 0;

		for(int test = 1; test <= cases; test++)
		{
			data = in.readLine().split("\\s+");
			int rows = Integer.parseInt(data[0]);
			int cols = Integer.parseInt(data[1]);
			int important = Integer.parseInt(data[2]);
			int not_important = Integer.parseInt(data[3]);

			image =	new String[rows*cols];
			index = 0;
			regions = new HashMap<String,Integer>();
			result = 0;
			int max_region_size = 0;

			for(int i = 0; i < rows; i++)
			{
				char[] line = in.readLine().toCharArray();
				for(int j = 0; j < cols; j++)
				{
					image[index++] = String.valueOf(line[j]);
					regions.put(image[index-1],regions.containsKey(image[index-1]) ? regions.get(image[index-1]) + 1: 1);
					max_region_size = Math.max(regions.get(image[index-1]),max_region_size);
				}
			}

			for(String i : regions.keySet())
			{
				int occur_count = regions.get(i);
				result += occur_count * ((occur_count == max_region_size) ? important : not_important);
			}
			System.out.println("Case " + test + ": " + result);
		}
	}
}

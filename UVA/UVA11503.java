import java.util.*;

class WeightedQU 
{
	private int[] id;
	private int[] iz;
	private HashMap<String,Integer> map;

	public WeightedQU(Set<String> people)
	{
		id = new int[people.size()];
		iz = new int[people.size()];
		map = new HashMap<String,Integer>();

		int counter = 0;
		for(String s : people)
		{
			map.put(s,counter++);
		}

		for(int i = 0; i < id.length; i++)
		{
			iz[i] = 1;
			id[i] = i;
		}
	}

	public int root(int i)
	{
		while(i != id[i])
		{
			id[i] = id[id[i]];   // this line represents "path compression"
			i = id[i];
		}
		return i;
	}

	public boolean connected(String p, String q)
	{
		return root(map.get(p)) == root(map.get(q));
	}

	public void union(String p, String q)   // here iz[] is used to "weighting"
	{
		int i = root(map.get(p));
		int j = root(map.get(q));
		if(iz[i] < iz[j])
		{
			id[i] = j;
			iz[j] += iz[i];
		}
		else
		{
			id[j] = i;
			iz[i] += iz[j];
		}
	}

	public int circleSize(String p1,String p2)
	{
		int int1 = root(map.get(p1));
		int int2 = root(map.get(p2));

		if(connected(p1,p2))
		{
			return iz[int1];
		}
		else
		{
			return iz[int1] + iz[int2];
		}
	}
}

class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		Set<String> persons = new HashSet<String>();
		List<String> pairs = new ArrayList<String>();
		WeightedQU sol = null;

		// Record all distinct names and friendship pairs
		for(int i = 0; i < cases; i++)
		{
			int friendships = in.nextInt();
			persons.clear();
			pairs.clear();
			for(int j = 1; j <= friendships; j++)
			{
				String person1 = in.next();
				String person2 = in.next();
				pairs.add(person1);
				pairs.add(person2);
				persons.add(person1);
				persons.add(person2);
			}
			sol = new WeightedQU(persons);
			for(int j = 0; j < pairs.size(); j += 2)
			{
				if(!sol.connected(pairs.get(j),pairs.get(j+1)))
				{
					sol.union(pairs.get(j),pairs.get(j+1));
				}
				System.out.println(sol.circleSize(pairs.get(j),pairs.get(j+1)));
			}
		}
	}
}

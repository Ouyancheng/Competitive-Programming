import java.util.*;

class Pair {
	int x;
	int y;

	public Pair(int x,int y) {
		this.x = x;
		this.y = y;
	}
}

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt()) {
			int numBooks = in.nextInt();
			HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
			int[] arr = new int[numBooks];
			Pair p = new Pair(0,Integer.MAX_VALUE);

			for(int i = 0; i < numBooks; i++) {
				int price = in.nextInt();
				arr[i] = price;
				hm.put(price,hm.containsKey(price) ? hm.get(price) + 1 : 1);
			}

			int money = in.nextInt();

			for(Integer i : arr) {
				if(hm.get(i) <= 0) continue;
				int diff = money - i;
				hm.put(i,hm.get(i)-1);
				if(hm.containsKey(diff) && hm.get(diff) >= 1) {
					p = (p.y - p.x < Math.max(diff,i) - Math.min(diff,i)) ? p : new Pair(Math.min(i,diff),Math.max(i,diff));
					hm.put(diff,hm.get(diff)-1);
				}
			}
			System.out.println("Peter should buy books whose prices are " + p.x + " and " + p.y + ".");
			System.out.println();
		}
	}
}

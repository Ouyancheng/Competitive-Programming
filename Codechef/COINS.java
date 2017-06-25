class Main {
	static java.util.HashMap<Long,Long> result = new java.util.HashMap<Long,Long>();
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		while(in.hasNextInt()) {
			System.out.println(maxCoins(in.nextInt()));
		}
	}
 
	public static long maxCoins(long coins) {
		if(coins == 0) {
			return 0;
		} else if(coins <= 2 || result.containsKey(coins)) {
			return (result.containsKey(coins) ? result.get(coins) : coins);
		} else {
			long split = maxCoins(coins/2) + maxCoins(coins/3) + maxCoins(coins/4);
			if(split > coins) {
				result.put(coins,split);
			}
 
			return (split > coins) ? split : coins;
		}
	}
 
}
 
import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		HashMap<Integer,Integer> count = new HashMap<>();

		while(input.hasNextInt()) {
			int num1 = input.nextInt();
			int num2 = input.nextInt();

			int hi = Math.max(num1,num2);
			int lo = Math.min(num1,num2);
			int max_cycle = 0;

			for(int i = lo; i <= hi; i++) {
				int cycles = cycles(i,count);
				max_cycle = Math.max(cycles,max_cycle);
			}

			System.out.print(num1 + " ");
			System.out.print(num2 + " ");
			System.out.println(max_cycle);
		}
	}

	static int cycles(int n,HashMap<Integer,Integer> count) {

		// If data is already available, return it
		if(count.containsKey(n)) return count.get(n);
		Stack<Integer> countData = new Stack<Integer>();
		Queue<Integer> sequence = new LinkedList<Integer>();
		int old_n = n;

		while(n != 1) {
			sequence.offer(n);
			countData.push(countData.isEmpty() ? 1 : countData.peek() + 1);
			if(n % 2 != 0) 
				n = 3 * n + 1;
			else
				n /= 2;
			if(count.containsKey(n)) {
				count.put(old_n,count.get(n) + countData.peek());
				return count.get(n) + countData.peek();
			}
		}

		// Put 1 into the queue
		sequence.offer(1); 
		countData.push(countData.isEmpty() ? 1 : countData.peek() + 1);

		while(!sequence.isEmpty()) {
			int num = sequence.poll();
			count.put(num,countData.pop());
		}

		return count.get(old_n);
	}
}

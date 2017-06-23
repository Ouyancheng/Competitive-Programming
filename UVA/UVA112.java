import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int count = 0;
		StringBuffer tree = new StringBuffer();

		while(in.hasNext())
		{
			int sum = in.nextInt();
			tree.delete(0,tree.length());
			tree.append(in.nextLine().replaceAll("\\s+",""));
			for(int i = 0; i < tree.length(); i++)
			{
				count = (tree.charAt(i) == '(') ? count + 1 : (tree.charAt(i) == ')') ? count - 1 : count;
			}
			while(tree.length() == 0 || count != 0)
			{
				String tmp = in.nextLine();
				tree.append(tmp.replaceAll("\\s+",""));
				for(int j = 0; j < tmp.length(); j++)
				{
					count = (tmp.charAt(j) == '(') ? count + 1 : (tmp.charAt(j) == ')') ? count - 1 : count;
				}
			}
			System.out.println(findPath(sum,tree.toString()) ? "yes" : "no");
		}
	}

	public static boolean findPath(int sum,String exp)
	{
		if(!exp.equals("()"))
		{
			int remaining = sum - Integer.parseInt(exp.substring(1,exp.indexOf("(",1)));
			int leftbound = treeBoundary(exp.substring(exp.indexOf("(",1))) + exp.indexOf("(",1);
			int rightbound = treeBoundary(exp.substring(leftbound+1)) + leftbound + 1;
			String leftTree = exp.substring(exp.indexOf("(",1),leftbound+1);
			String rightTree = exp.substring(leftbound+1,rightbound+1);
			return leftTree.equals("()") && rightTree.equals("()") ? remaining == 0 : findPath(remaining,leftTree) || findPath(remaining,rightTree);
		}
		return false;
	}

	public static int treeBoundary(String expression)
	{
		int count = 0;
		int i;

		for(i = 0; i < expression.length(); i++)
		{
			count = (expression.charAt(i) == '(') ? count + 1 : (expression.charAt(i) == ')') ? count - 1 : count;
			if(count == 0) break;
		}
		return i;
	}
}

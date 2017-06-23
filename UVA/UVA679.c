# include <stdio.h>
# include <math.h>

int main()
{
	int cases = 0;
	int depth = 0;
	int drop = 0;
	scanf("%d",&cases);
	int loopCount = 1;

	while(loopCount++ <= cases)
	{
		scanf("%d",&depth);
		scanf("%d",&drop);
		
		/* Calculate the T/F value for each level */
		int pos = 1;
		int level = 1;

		for(level = 1; level < depth; level++)
		{
			/* Two cases:
			 * if value of current node is true,
			 * go to its right child,
			 * otherwise go to its left child
			 */
			int interval = pow(2,level);
			pos = (drop % interval == 0) ? pos * 2 + 1 : (drop % interval <= interval/2) ? pos * 2 : pos * 2 + 1;
		}
		printf("%d\n",pos);
	}
	return 0;
}

import java.util.*;

class Main
{
	static long mergeCount(long to_be_sorted[],int lo,int hi,int mid)
	{
		int left = lo;
		int right = mid + 1;

		long[] fArr = new long[hi-lo+1];
		int index = 0;
		long inversions = 0;

		/* Compare and copy the elements from the left and right partitions */
		while(left <= mid && right <= hi)
		{
			inversions += (to_be_sorted[left] > to_be_sorted[right]) ? mid - left + 1 : 0;
			fArr[index++] = (to_be_sorted[left] <= to_be_sorted[right]) ? to_be_sorted[left++] :  to_be_sorted[right++];
		}

		/* Copy remaining elements from the left */
		while(left <= mid)
		{
			fArr[index++] = to_be_sorted[left++];
		}

		/* Copy any remaining elements from the right */
		while(right <= hi)
		{
			fArr[index++] = to_be_sorted[right++];
		}

		int i = 0;
		int fIndex = 0;

		/* Copy back to the original array */
		for(i = lo; i <= hi; i++)
		{
			to_be_sorted[i] = fArr[fIndex++];
		}
		return inversions;
	}

	static long mergeSortIterative(long to_be_sorted[],int lo,int hi,int size)
	{
		int mid = (lo + hi) / 2;
		long inversions = 0;
		int i = 1;
		int j = 0;

		for(i = 1; i <= hi*2; i*=2)
		{
			for(j = 0; j <= hi; j += i)
			{
				inversions += mergeCount(to_be_sorted,j,(int)Math.min(size-1,j+i-1),((int)Math.min(size-1,((j+i-1)+j)/2)));
			}
		}
		return inversions;
	}

	static long mergeSort(long to_be_sorted[],int lo,int hi)
	{
		int mid = (lo + hi) / 2;
		long inversions = 0;

		if(lo < hi)
		{
			inversions += mergeSort(to_be_sorted,lo,mid);
			inversions += mergeSort(to_be_sorted,mid+1,hi);
		}
		inversions += mergeCount(to_be_sorted,lo,hi,mid);
		return inversions;
	}

	static void print(long arr[],int lo,int hi)
	{
		for(lo = lo; lo <= hi; lo++)
		{
			System.out.print(arr[lo] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args)
	{
		int num_input = 0;
		int loop_count = 1;
		Scanner in = new Scanner(System.in);

		while(true)
		{
			num_input = in.nextInt();
			long[] to_be_sorted = new long[num_input];
			for(loop_count = 1;loop_count <= num_input; loop_count++)
			{
				to_be_sorted[loop_count-1] = in.nextInt();
			}
			if(num_input == 0) { break; }
			long result = mergeSortIterative(to_be_sorted,0,num_input-1,num_input);
			System.out.println(result);
		}
	}
}

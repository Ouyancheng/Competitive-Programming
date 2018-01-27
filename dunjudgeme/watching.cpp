#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll n, p, q, temp, dp[2100][2100];
vector<ll> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>p>>q;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	if (p+q >= n)
	{
		cout<<1<<"\n";
		return 0;
	}
	else
	{
		ll beg1 = 1, end1 = 1000000000, ans = 1000000000; 
		while (beg1 <= end1)
		{
			ll midw = (beg1+end1)/2;
			/*
				dp[x][y] is equal to the minimum number of large cameras needed to cover all indexes from 0 to x, using y small cameras.
			*/	
			for (int i = 0; i < n; i++) 
			{
				for (int j = 0; j <= p; j++)
					dp[i][j] = 1000000000; 
			}
			if (p > 0)
				dp[0][1] = 0; //A small camera is used to cover index 0. 
			if (q > 0)
				dp[0][0] = 1; //A large camera is used to cover index 0.
			for (ll i = 1; i < n; i++)
			{
				ll pos = i;
				while (pos >= 0 and v[i]-v[pos] < midw) //We find the maximum index that is at least midw units away from index i.
				{			
					pos--;
				}	
				if (pos == -1)	//If there is no such index, we can use just 1 camera from beginning to index i.
				{
					if (p > 0)
						dp[i][1] = 0;
					if (q > 0)
						dp[i][0] = 1;
				}
				else //If there is such an index, we find all ways 
				{
					for (int j = 0; j <= min(p, pos+1); j++)
					{
						if (dp[pos][j] != 1e9)
						{	
							if (j == p)
								dp[i][j] = min(dp[i][j], dp[pos][j]+1);
							else
							{
								dp[i][j+1] = min(dp[i][j+1], dp[pos][j]);
								if (dp[pos][j] < q)
									dp[i][j] = min(dp[i][j], dp[pos][j]+1);
							}
						}
					}
				}
				ll pos1 = pos;
 
				while (pos >= 0 and v[i]-v[pos] < 2*midw) // Same thing as above, except that this is being done for 2*midw.
					pos--;
 
				if (pos1 == pos) // If the indices are same, we have already processed it.
					continue;
 
				if (pos == -1)
				{
					if (q > 0)
						dp[i][0] = 1;
					continue;
				}
 
				for (int j = 0; j <= min(p, pos+1); j++)
				{
					if (dp[pos][j] < q) // We can only use a large camera.
					{
						dp[i][j] = min(dp[i][j], dp[pos][j]+1);
					}
				}	
			}
			int flag = 0;
			for (int j = 0; j <= min(p, n-1); j++) //Check if it is possible with w = midw.
			{
				if (dp[n-1][j] <= q)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				ans = midw;
				end1 = midw-1;
			}
			else
				beg1 = midw+1;
		}
		cout<<ans<<"\n";
	}
}

# include<math.h>
# include<stdio.h>
# define max(x,y) x > y ? x : y

int main() {
	int numCases;
	scanf("%d",&numCases);
	int rungs[(int)pow(10,5)+1];
	int caseNo;

	for(caseNo = 1; caseNo <= numCases; caseNo++) {
		int costCount = 0;
		int costCounter = 0;
		int minStrength = 0;
		int curStrength = 0;

		scanf("%d",&costCount);

		for(costCounter = 1; costCounter <= costCount; costCounter++) {
			scanf("%d",&rungs[costCounter]);
			minStrength = max(minStrength,rungs[costCounter]-rungs[costCounter-1]);
		}
		curStrength = minStrength;

		for(costCounter = 1; costCounter <= costCount; costCounter++) {
			int diff = rungs[costCounter]-rungs[costCounter-1];
			if(curStrength < diff) {
				minStrength++;
				break;
			} else if (curStrength == diff) {
				curStrength--;
			}
		}
		printf("Case %d: %d\n",caseNo,minStrength);
	}
}

#include<cstdio>
#include<unordered_map>
#include<cstring>
#include<cstdlib>
 
using namespace std;
 
int main(void) {
	int c1 = 0, c2 = 0;
	const long long MAX = (1LL << 26) - 1;
	char * s = (char *) malloc(10001*sizeof(char));
	scanf("%d %d",&c1,&c2);
	unordered_map<long long,int> m;
	long long cnt = 0;
 
	for(int i = 0; i < c1; i++) {
		scanf("%s",s);
		int l = strlen(s);
		int c[26] = { 0 };
		long long sv = 0;
		for(int j = 0; j < l; j++) {
			if(!c[s[j]-'A'] && (c[s[j]-'A']=1))
				sv += 1LL << (s[j]-'A');
		}
		m[sv]++;
	}
 
	for(int i = 0; i < c2; i++) {
		scanf("%s",s);
		int l = strlen(s);
		int c[26] = { 0 };
		long long sv = 0;
		for(int j = 0; j < l; j++) {
			if(!c[s[j]-'A'] && (c[s[j]-'A']=1))
				sv += 1LL << (s[j]-'A');
		}
		for(auto p : m)
			if((sv|p.first)==MAX)
				cnt += p.second;
	}
	printf("%lld\n",cnt);
	free(s);
	return 0;
}
 
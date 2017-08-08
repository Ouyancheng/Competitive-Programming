#include<bits/stdc++.h>

using namespace std;
#define MAX_N 5005
#define MAX_C 26

struct PalTreeNode {
	int start;
	int length;
	int insEdge[MAX_C];
	int sufEdge;
	int palCnt;
	int occ;
	int k;
} palTree[MAX_N];

int maxPalSuf, palTreeSz, updi, toUpd[MAX_N], ans[MAX_N];
string s;

void initPalTree() {
	palTree[1].length = 0;
	palTree[1].sufEdge = 2;
	palTree[2].length = -1;
	palTree[2].sufEdge = 2;

	maxPalSuf = 1;
	palTreeSz = 2;
}

int go(int cur,int len) {
	while(cur > 2) {
		cur = palTree[cur].sufEdge;
		if(palTree[cur].length == (len>>1)) {
			return palTree[cur].k;
		} else if(palTree[cur].length < (len>>1)) {
			return 0;
		}
	}
}

void insToPalTree(int idx)
{
	int tmp = maxPalSuf, curPalLen = 0;
	char cc = s[idx]-'a';

	while (true) {
		curPalLen = palTree[tmp].length;
		if (idx - curPalLen >= 1 && s[idx] == s[idx-curPalLen-1])
			break;
		tmp = palTree[tmp].sufEdge;
	}
	if(palTree[tmp].insEdge[cc]) {
		maxPalSuf = palTree[tmp].insEdge[cc];
		palTree[maxPalSuf].palCnt <<= 1;
		palTree[maxPalSuf].occ++;
		return;
	}

	palTree[tmp].insEdge[cc] = ++palTreeSz;
	palTree[palTreeSz].length = palTree[tmp].length + 2;

	palTree[palTreeSz].start = idx - palTree[palTreeSz].length + 1;

	tmp = palTree[tmp].sufEdge;
	maxPalSuf = palTreeSz;

	if (palTree[maxPalSuf].length == 1) {
		palTree[maxPalSuf].sufEdge = 1;
		palTree[maxPalSuf].palCnt = 1;
		palTree[maxPalSuf].occ = 1;
		palTree[maxPalSuf].k = 1;
		toUpd[updi++] = maxPalSuf;
		return;
	}
	while (true) {
		curPalLen = palTree[tmp].length;
		if (idx-curPalLen >= 1 && s[idx] == s[idx-curPalLen-1])
			break;
		tmp = palTree[tmp].sufEdge;
	}
	palTree[maxPalSuf].sufEdge = palTree[tmp].insEdge[cc];
	// augmenting each node with the number of subpalindromes of the node
	palTree[maxPalSuf].palCnt = 1 + palTree[palTree[maxPalSuf].sufEdge].palCnt;
	// for counting the number of occurence of each palindrome
	palTree[maxPalSuf].occ = 1;
	toUpd[updi++] = maxPalSuf;

	palTree[maxPalSuf].k = 1 + go(maxPalSuf,palTree[maxPalSuf].length);
}

void propOcc() {
	for(int i = palTreeSz; i >= 0; i--) {
		if(palTree[i].length > 1)
			palTree[palTree[i].sufEdge].occ += palTree[i].occ;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	initPalTree();

	int len = (int) s.length();

	for(int i = 0; i < len; i++)
		insToPalTree(i);
	propOcc();

	for(int i = 3; i <= palTreeSz; i++)
		ans[palTree[i].k]+=palTree[i].occ;
	for(int i = len-1; i >= 1; i--)
		ans[i] += ans[i+1];
	for(int i = 1; i <= len; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}

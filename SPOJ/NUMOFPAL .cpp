#include<bits/stdc++.h>

using namespace std;
#define MAX_N 1005
#define MAX_C 26

struct PalTreeNode {
	int start;
	int length;
	int insEdge[MAX_C];
	int sufEdge;
	int palCnt;
	int occ;
} palTree[MAX_N];

int maxPalSuf, palTreeSz, updi, toUpd[MAX_N];
string s; int ans;

void initPalTree() {
	palTree[1].length = 0;
	palTree[1].sufEdge = 2;
	palTree[2].length = -1;
	palTree[2].sufEdge = 2;

	maxPalSuf = 1;
	palTreeSz = 2;
}

void insToPalTree(int idx) {
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
}

void propOcc() {
	for(int i = palTreeSz; i >= 0; i--) {
		if(palTree[i].length > 1)
			palTree[palTree[i].sufEdge].occ += palTree[i].occ;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	initPalTree();
	cin >> s;
	int l = s.length();

	for (int i=0; i<l; i++)
		insToPalTree(i);
	propOcc();

	for(int i = 3; i <= palTreeSz; i++)
		ans += palTree[i].occ;
	cout << ans << "\n";
	return 0;
}

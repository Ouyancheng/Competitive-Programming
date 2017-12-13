#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int sum,r,c;
char ch;
unordered_set<int> us;
unordered_map<int,int> um;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		sum = 0;
		for(int j = 0; j < c; j++) {
			if(cin >> ch, ch == 'X'){
				sum++;
				um[j]++;
			}
		}
		if(sum != 0) us.insert(sum);
	}
	if(us.size()!=1) { cout << "NO" << endl; return 0; }
	us.clear();
	for(auto p : um) us.insert(p.second);
	if(us.size()==1) cout << "YES"; else cout << "NO";
	cout << endl;
		
	return 0;
}
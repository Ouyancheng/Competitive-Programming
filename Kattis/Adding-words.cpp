#include<bits/stdc++.h>

using namespace std;

unordered_map<string,int> dict;
unordered_map<int,string> rdict;
vector<string> cmd;
const int oo = 1e8;

int evaluate(int i,int pre=0,string sign="+") {
	if(i == (int) cmd.size()) return 0;
	string word = cmd[i], op = cmd[i+1];
	if(op == "=") {
		if(dict.count(word) > 0) {
			return (sign == "+") ? pre + dict[word] : pre - dict[word];
		} else {
			return -oo;
		}
	} else {
		if(dict.count(word) > 0) {
			int res = (sign == "+") ? evaluate(i+2,pre+dict[word],op) :
				evaluate(i+2,pre-dict[word],op);
			return (res == -oo) ? -oo : res;
		} else {
			return -oo;
		}
	}
}

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string line;
	while(getline(cin,line)) {
		cmd.clear();
		line += " ";
		while(1) {
			int pos = line.find_first_of(" ");
			if(pos == string::npos) break;
			cmd.push_back(line.substr(0,pos));
			line = line.substr(pos+1);
		}
		if(cmd[0] == "def") {
			if(dict.count(cmd[1]) > 0)
				rdict.erase(dict[cmd[1]]);
			rdict[stoi(cmd[2])] = cmd[1];
			dict[cmd[1]] = stoi(cmd[2]);
		} else if(cmd[0] == "clear") {
			rdict.clear();
			dict.clear();
		} else if(cmd[0] == "calc") {
			for(int i = 1; i < (int) cmd.size(); i++) {
				cout << cmd[i] << " ";
			}
			int res = evaluate(1);
			if(res == -oo || rdict.count(res) == 0) {
				cout << "unknown";
			} else {
				cout << rdict[res];
			}
			cout << "\n";
			// cout << "the result of res is " << res << "\n";
		}
	}
	return 0;
}
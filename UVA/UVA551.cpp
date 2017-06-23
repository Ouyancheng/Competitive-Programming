#include<iostream>
#include<stack>
#include<string>

using namespace std;

string s,s2;
stack<char>bal;
int flag;

bool chk(char c,int p) {
	if(bal.size() && bal.top() == c) {
		bal.pop();
	} else {
		flag = p;
		return 0;
	}
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(getline(cin,s)) {
		s2 = ""; flag = -1;
		for(int i = 0; i < s.length();) {
			if(i < s.length()-1 && s[i] == '(' && s[i+1] == '*') {
				s2 += (char (202)); i+= 2;
			} else if(i < s.length()-1 && s[i] == '*' && s[i+1] == ')') {
				s2 += (char (203)); i+= 2;
			} else {
				s2 += s[i]; i++;
			}
		}
		if(s2.find_last_not_of(' ') != string::npos)
			s2 = s2.substr(0,s2.find_last_not_of(' ')+1);
		for(int i = 0; i < s2.length(); i++) {
			if(s2[i] == '(') {
				bal.push(s2[i]);
			} else if(s2[i] == '[') {
				bal.push(s2[i]);
			} else if(s2[i] == '{') {
				bal.push(s2[i]);
			} else if(s2[i] == '<') {
				bal.push(s2[i]);
			} else if(s2[i] == (char (202))) {
				bal.push(s2[i]);
			} else if(s2[i] == ')') {
				if(!chk('(',i)) break;
			} else if(s2[i] == ']') {
				if(!chk('[',i)) break;
			} else if(s2[i] == '}') {
				if(!chk('{',i)) break;
			} else if(s2[i] == '>') {
				if(!chk('<',i)) break;
			} else if(s2[i] == (char (203))) {
				if(!chk((char (202)),i)) break;
			} 
		}
		if(flag == -1 && bal.size()) flag = s2.length();
		while(bal.size()) bal.pop();
		if(flag==-1) {
			cout << "YES";
		} else {
			cout << "NO" << " " << flag+1;
		}
		cout << endl;
	}
	return 0;
}
#include "pingpong.h"
using namespace std;

string winner(string s) {
	int rg = 0, pg = 0, rt = 0, pt = 0;
	for(int i = 0; i < (int) s.length(); i++) {
		if(s[i] == 'R') rt++;
		else pt++;
		if(rt >= 11 && rt - pt >= 2) {
			rg++;
			rt = pt = 0;
		} else if(pt >= 11 && pt - rt >= 2) {
			pg++;
			rt = pt = 0;
		}
	}
	return (pg > rg) ? "Potato" : "Rar";
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e3 + 5;

ll ans;
int eh[maxn], sh[maxn];

// Function to print all distinct palindrome sub-strings of s (Geeks4Geeks)
void manacher(string &s)
{
	map<string, int> m;
	int n = s.size();

	// table for storing results (2 rows for odd-
	// and even-length palindromes
	int R[2][n+1];

	// Find all sub-string palindromes from the given input
	// string insert 'guards' to iterate easily over s
	s = "@" + s + "#";

	for (int j = 0; j <= 1; j++)
	{
		int rp = 0; // length of 'palindrome radius'
		R[j][0] = 0;

		int i = 1;
		while (i <= n)
		{
			// Attempt to expand palindrome centered at i
			while (s[i - rp - 1] == s[i + j + rp])
				rp++; // Incrementing the length of palindromic
			// radius as and when we find vaid palindrome

			// Assigning the found palindromic length to odd/even
			// length array
			R[j][i] = rp;
			int k = 1;
			while ((R[j][i - k] != rp - k) && (k < rp))
			{
				R[j][i + k] = min(R[j][i - k],rp - k);
				k++;
			}
			rp = max(rp - k,0);
			i += k;
		}
	}

	// remove 'guards'
	s = s.substr(1, n);

	// Put all obtained palindromes in a hash map to
	// find only distinct palindromess
	sh[0]++, eh[0]++;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++) {
			for (int rp = R[j][i]; rp > 0; rp--) {
				int si = i-rp-1, ei = si + 2*rp+j-1;
				sh[si]++;
				eh[ei]++;
			}
		}
		sh[i]++;
		eh[i]++;
	}
}

string s;

int main() {
	cin >> s;
	manacher(s);
	for(int i = 0; i < (int) s.length(); i++) {
		for(int j = i+1; j < (int) s.length(); j++) {
			ans += eh[i] * sh[j];
		}
	}
	cout << ans << "\n";
	return 0;
}

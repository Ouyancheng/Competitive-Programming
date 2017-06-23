#include<iostream>
 
using namespace std;
 
string in, out;
 
void dfs(string a, string b, string stack, string path, int n) {
    if(n == in.length() * 2) {
        if(b == out)
            cout << path << endl;
        return;
    }
 
    // push
    if(a.length() > 0)
        dfs(a.substr(1, a.length() - 1), b, \
            stack + a[0], path + (n == 0? "i" : " i"), n + 1);
    // pop
    if(stack.length() > 0 && stack[stack.length() - 1] == out[b.length()])
        dfs(a, b + stack[stack.length() - 1], \
            stack.substr(0, stack.length() - 1), \
            path + " o", n + 1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> in >> out) {
        cout << "[\n";
        if(in.length() == out.length())
            dfs(in, "", "", "", 0);
        cout << "]\n";
    }
}
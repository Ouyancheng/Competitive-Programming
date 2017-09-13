#include<iostream>

using namespace std;

int a;

long long factor(int n) {
    int t = n;
    long long sum = 1;
    for(int i = 2; i*i <= n && t > 1; i++) {
        if(t % i == 0) {
            sum += i;
            if(t/i > i) sum += t/i;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> a) {
        long long sum = factor(a);

        cout << a << " ";
        if(sum - a > 2 || a - sum > 2) {
            cout << "not ";
        } else if(sum != a) {
            cout << "almost ";
        }
        cout << "perfect\n";
    }
    return 0;
}

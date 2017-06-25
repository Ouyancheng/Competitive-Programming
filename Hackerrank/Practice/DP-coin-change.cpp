#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long dp[260][60];

long long make_change(vector<int> coins, int money) {
    fill_n(dp[0],60,1);
    for(int i = 1; i <= money; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(coins[j] <= i) {
                for(int k = 0; k * coins[j] <= i; k++)
                        dp[i][j+1] += dp[i-k*coins[j]][j];
            } else {
                dp[i][j+1] = dp[i][j];
            }
        }
    }
    return dp[money][coins.size()];
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}

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

int solve(int r,int c,vector< vector<int> > &grid) {
    if(r >= 0 && c >= 0 && r < grid.size() && c < grid[r].size()) {
        if(grid[r][c]) {
            grid[r][c] = 0;
            return 1 + solve(r-1,c,grid) + solve(r+1,c,grid) + solve(r,c-1,grid) + solve(r,c+1,grid) + 
                solve(r-1,c-1,grid) + solve(r-1,c+1,grid) + solve(r+1,c-1,grid) + solve(r+1,c+1,grid);
        }
    }
    return 0;
}

int get_biggest_region(vector< vector<int> > grid) {
    int ans = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            ans = max(ans,solve(i,j,grid));
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

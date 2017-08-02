#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue {
  
    public:
        stack<int> behind, infront;   
        void push(int x) {
            infront.push(x);
        }

        void pop() {
            if(!behind.size()) {
                while(infront.size())
                    behind.push(infront.top()),infront.pop();
            }
            if(behind.size()) behind.pop();
        }

        int front() {
            int e = -(1 << 30);
            if(!behind.size()) {
                while(infront.size())
                    behind.push(infront.top()),infront.pop();
            }
            if(behind.size()) e = behind.top();
            return e;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

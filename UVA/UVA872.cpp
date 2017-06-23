#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <set>

#define id(a) static_cast<int>(a) - 65
#define ntc(a) static_cast<char>(a + 65)
#define fill(s,n) n = ""; while(n == "") getline(s,n)
#define DCV vector<char>
#define DSS stringstream
#define clone(a,b) for(int i = 0; i < ALN; i++) b[i] = a[i]
#define init(a) for(int i = 0; i < ALN; i++) a[i] = -1
#define ALN 26

using namespace std;

int cycle(map<char,DCV> M,int E[],set<char> D,char cur) {
        D.insert(cur);
        DCV NB = M[cur];
        for(int i = 0; i < NB.size(); i++) {
            if(D.find(NB[i]) == D.end()) {
                return cycle(M,E,D,NB[i]);
            } else {
                return 1;
            }
         }
         D.erase(cur);
    return 0;
}

int hasCycle(map<char,DCV> M,int E[]) {
    set<char> D;
    int cy = 0;
    for(int i = 0; i < ALN; i++) {
        if(D.find(ntc(i)) == D.end()) {
            cy = cycle(M,E,D,ntc(i));
        }
        if(cy) {
            break;
        }
    }
    return cy;
}

void print(map<char,DCV> M,int E[],list<char> out,int EC) {
    if(out.size()==EC) {
            list<char>::iterator it = out.begin();
            cout << *it++;
            for(; it != out.end(); ++it) {
                cout << " " << *it;
            }
            cout << endl;
            out.pop_back();
            return;
    }

    int A[ALN] = {0};
    init(A);
    for(int i = 0; i < ALN; i++) {
        clone(E,A);
        if(A[i] == 0) {
            A[i]--;
            out.push_back(ntc(i));
            DCV NB = M[ntc(i)];
            for(int j = 0; j< NB.size(); j++) {
                A[id(NB[j])]--; // decrement indeg of neighbours
            }
            print(M,A,out,EC);
            out.pop_back();
        }    
    }
}

int main(void)
{
    int cases = 0;
    char alp = '\0';
    cin >> cases;
    int E[ALN] = { 0 };

    for(int i = 0; i < cases; i++){
        int EC = 0;
        map<char,DCV> M;
        
        string tmp = "";
        list<char> out;
        init(E);
        fill(cin,tmp);
        DSS ss(tmp);
        
        // read the elements
        while(ss >> alp) {
            M.insert(pair<char,DCV>(alp,DCV()));
            E[id(alp)] = 0;
            EC++;
        }
        
        fill(cin,tmp);
        ss.str(tmp);
        ss.clear();
        
        // read the constraints
        while(ss >> tmp) {
            E[id(static_cast<char>(tmp[2]))]++;
            M[tmp[0]].push_back(tmp[2]);
        }
        
        if(!hasCycle(M,E)) {
            print(M,E,out,EC);
        } else {
            cout << "NO" << endl;
        }
        if(i < cases-1) {
            cout << endl;
        }
    }
    return 0;
}
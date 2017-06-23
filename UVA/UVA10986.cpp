#include<iostream>
#include<vector>
#include <climits>
#include <cmath>
#include <queue>
#include <cstdio>

using namespace std;

#define rep(a,b,c) for(int c=a;c<b;c++)

typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
typedef std:: pair<int,int> PII;

void sp(vector<vector<PII> > &graph,priority_queue<PII,vector<PII>,greater<PII> > &minv,VI &ans,int S,int T) {
	int e = -1,w = -1;
	minv.push(pair<int,int>(0,S));
	while(!minv.empty()) {
		w = minv.top().first;
		e = minv.top().second;
		minv.pop();
		rep(0,graph[e].size(),d) {
			if(graph[e][d].first != INT_MAX && ans[e] + graph[e][d].first < ans[graph[e][d].second]) {
				ans[graph[e][d].second] = ans[e] + graph[e][d].first;
				minv.push(pair<int,int>(ans[graph[e][d].second],graph[e][d].second));
			}
		}
	}
}

int main(void) {
	int cc = 0,N = 0,M = 0,S = -1,T = -1,A=-1,B=-1,W=-1;
	vector<vector<PII> > graph;
	VI ans;
	priority_queue<PII,vector<PII>,greater<PII> > minv;
	scanf("%d",&cc);

	rep(0,cc,i) {
		scanf("%d %d %d %d",&N,&M,&S,&T);
		graph.assign(N,vector<PII>());
		ans.assign(graph.size(),INT_MAX);
		ans[S] = 0;
		rep(0,M,j) {
			scanf("%d %d %d",&A,&B,&W);
			graph[A].push_back(PII(W,B));
			graph[B].push_back(PII(W,A));
		}
		sp(graph,minv,ans,S,T);
		if(ans[T] != INT_MAX)
			cout << "Case #" << i + 1 << ": " << ans[T] << endl;
		else
			cout << "Case #" << i + 1 << ": " << "unreachable" << endl;
	}
}

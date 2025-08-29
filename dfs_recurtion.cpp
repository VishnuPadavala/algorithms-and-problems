#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector< vector<int> > &adj, vector<int> &v) {
    v[start]=0;
    cout<<start<<" ";
    for(int i=0;i<adj[start].size();i++){
    	int a=adj[start][i];
    	if(v[a]==-1)
    	dfs(a,adj,v);
	}
}

int main() {
    int n = 7;
    vector< vector<int> > adj(n);
    vector<int> v(n, -1);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(5);
    adj[2].push_back(4);
    adj[2].push_back(6);
    adj[3].push_back(6);
    adj[3].push_back(4);

    cout << "DFS Traversal: ";
    dfs(0, adj, v);

    return 0;
}



//by using queue data structure we can travel the bfs.
#include <iostream>
#include <vector>
#include <queue  >
using namespace std;
void bfs(int start, vector< vector<int> > &adj, vector<int> &v) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (v[node] == -1) { 
            cout << node << " ";
            v[node] = 0; 
		}
        for (int i = 0; i < adj[node].size(); i++) {
            int a = adj[node][i];
            if (v[a] == -1)
                q.push(a);
        }
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

    cout << "BFS Traversal: ";
    bfs(0, adj, v);
    return 0;
}



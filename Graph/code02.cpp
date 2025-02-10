#include<bits/stdc++.h>
using namespace std;

void bfsHelper(vector<vector<int>> &adj, int root = 1) {
    vector<int> parent(adj.size());

    queue<int> q;
    q.push(root);
    parent[root] = -1;

    while(!q.empty()) {
        int current = q.front();
        cout << current << ' ';
        q.pop();
        for(int neighbr : adj[current]) {
            if(neighbr == parent[current]) {
                continue;
            }
            q.push(neighbr);
            parent[neighbr] = current;
        }
    }
}

    int main()
{
    int n; cin >> n;
    vector<vector<int>> adj(n+1);

    for(int e=0; e<n-1; e++) {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    bfsHelper(adj);

    return 0;
}
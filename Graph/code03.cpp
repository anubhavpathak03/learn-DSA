#include <bits/stdc++.h>
using namespace std;

int num[100100];

void dfsHelper(vector<vector<int>> &adj, int current = 1, int parent = -1)
{
    num[current] = 1;
    for (auto neighbr : adj[current]) 
    {
        if (neighbr == parent) continue;
        dfsHelper(adj, neighbr, current);
        num[current] += num[neighbr];
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1); // Adj. list (1-indexed)

    for (int e = 0; e < n - 1; e++)
    { // n-1 edges for a tree
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    } // adj list ready

    // printing the adjacency list
    for (int i = 1; i <= n; i++)
    {
        cout << i << "---> ";
        for (auto node : adj[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    cout << endl;

    dfsHelper(adj);


    for(int i=1; i<=n; i++) {
        cout << i << "-->  " << num[i] << "\n"; 
    }
    return 0;
}
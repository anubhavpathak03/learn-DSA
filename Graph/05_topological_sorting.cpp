#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {   // directed graph
        l[x].push_back(y);
    }

    void topologicalSorting() {
        vector<int> indegree(V, 0);

        // iterate over all the edges to find the right indegree
        for(int i=0; i<V; i++) {
            for(auto nbr : l[i]) {
                indegree[nbr]++;
            }
        }

        // bfs
        queue<int> q;
        // initalise the queue with the node having 0 indegree
        for(int i=0;i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }


        //start poping this node
        while(!q.empty()) {
            int node = q.front();
            cout << node << ", ";
            q.pop();

            // iterate over there nbr to reduce there indegree by 1
            for(auto nbr : l[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

    }
};

int main()
{
    Graph g(6);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.topologicalSorting();
    return 0;
}
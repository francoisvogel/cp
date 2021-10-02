#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;
    vector<vector<int>> graph(nbNodes);
    for (int i = 0; i < nbEdges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    bool vis [nbNodes];
    for (int i = 0; i < nbNodes; i++) {
        vis[i] = false;
    }
    vector<int> comp;
    for (int i = 0; i < nbNodes; i++) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int curNode = q.front();
                q.pop();
                for (int newNode : graph[curNode]) {
                    if (!vis[newNode]) {
                        q.push(newNode);
                        vis[newNode] = true;
                    }
                }
            }
            comp.push_back(i);
        }
    }
    cout << comp.size()-1 << endl;
    for (int i = 0; i < comp.size()-1; i++) cout << comp[i]+1 << " " << comp[i+1]+1 << endl;
    int d = 0;
    d++;
}
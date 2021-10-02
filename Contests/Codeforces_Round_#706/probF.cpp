/*
 * Author: Francois Vogel
 * Comment: 
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
 
using namespace std;
using namespace __gnu_pbds;
 
#define pii pair<int, int>
#define f first
#define s second
 
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define cls clear
 
#define int ll
#define ll long long
#define ld long double
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int inf = 1e17;
const int MOD = 998244353;
 
signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, nbEdges;
    cin >> n >> nbEdges;
    vi graph [n];
    int dist [n][n];
    vector<pii> edges;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = inf;
    for (int i = 0; i < nbEdges; i++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        nodeA--;
        nodeB--;
        graph[nodeA].pb(nodeB);
        graph[nodeB].pb(nodeA);
        dist[nodeA][nodeB] = 1;
        dist[nodeB][nodeA] = 1;
        edges.pb(pii(nodeA, nodeB));
        edges.pb(pii(nodeB, nodeA));
    }
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    int res [n][n];
    int spNode [n];
    bool spEdge [n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) spEdge[i][j] = false;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < n; k++) spNode[k] = false;
            spNode[i] = spNode[j] = true;
            int edgeCount = 0;
            for (pii k : edges) if (dist[i][k.f]+dist[k.s][j]+1 == dist[i][j]) {
                spNode[k.f] = spNode[k.s] = spEdge[k.f][k.s] = spEdge[k.s][k.f] = true;
                edgeCount++;
            }
            int spNodeCount = 0;
            for (int i = 0; i < n; i++) if (spNode[i]) spNodeCount++;
            if (edgeCount != spNodeCount-1) {
                res[i][j] = res[j][i] = 0;
                for (pii k : edges) if (dist[i][k.f]+dist[k.s][j]+1 == dist[i][j]) spEdge[k.f][k.s] = spEdge[k.s][k.f] = false;
                continue;
            }
            for (pii k : edges) {
                if (!spEdge[k.f][k.s] and dist[i][k.f]+1 == dist[i][k.s] and dist[j][k.f]+1 == dist[j][k.s]) {
                    spNode[k.s]++;
                }
            }
            int comb = 1;
            for (int i : spNode) {
                comb *= i;
                comb %= MOD;
            }
            res[i][j] = res[j][i] = comb;
            for (pii k : edges) if (dist[i][k.f]+dist[k.s][j]+1 == dist[i][j]) spEdge[k.f][k.s] = spEdge[k.s][k.f] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << res[i][j] << " ";
        cout << endl;
    }
 
    int d = 0;
    d++;
}
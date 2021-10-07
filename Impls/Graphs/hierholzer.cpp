/*
 * Author: Francois Vogel
 * Comment: Hierholzer algorithm to find eulerian path
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define mp pair<pii, int>
#define pii pair<int, int>
#define f first
#define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define size(x) (int)(x.size())
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int n = 20; // set your bounds here

vector<pii> graph [n];

vi hierholzer() {
    vector<mp> edges;
    for (mp i : edges) {
        graph[i.f.f].pb(pii(i.f.s, i.s));
        graph[i.f.s].pb(pii(i.f.f, i.s));
    }
    bool vis [n];
    for (int i = 0; i < n; i++) vis[i] = false;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (pii y : graph[x]) if (!vis[y.f]) {
            vis[y.f] = 1;
            q.push(y.f);
        }
    }
    for (int i = 0; i < n; i++) if (!vis[i]) return {-1};
    vi unevenDegree;
    for (int i = 0; i < n; i++) if (size(graph[i])%2 == 1) unevenDegree.pb(i);
    if (size(unevenDegree) != 0 && size(unevenDegree) != 2) return {-1};
    if (size(unevenDegree) == 2) {
        graph[unevenDegree[0]].pb(pii(unevenDegree[1], size(edges)));
        graph[unevenDegree[1]].pb(pii(unevenDegree[0], size(edges)));
    }
    int used [n];
    for (int i = 0; i < n; i++) used[i] = 0;
    vi ac, t;
    ac.pb(0);
    set<int> rem;
    while (!ac.empty()) {
        int x = ac.back();
        while (used[x] < size(graph[x]) && rem.count(graph[x][used[x]].s)) used[x]++;
        if (used[x] == size(graph[x])) {
            t.pb(x);
            ac.pop_back();
        }
        else {
            ac.pb(graph[x][used[x]].f);
            rem.ins(graph[x][used[x]].s);
        }
    }
    if (size(unevenDegree) == 2) {
        t.pop_back();
        for (int i = 0; i < size(t)-1; i++) if ((unevenDegree[0] == t[i] && unevenDegree[1] == t[i+1]) || (unevenDegree[0] == t[i+1] && unevenDegree[1] == t[i])) {
            vi t1, t2;
            for (int j = 0; j <= i; j++) t1.pb(t[j]);
            for (int j = i+1; j < size(t); j++) t2.pb(t[j]);
            t.cls();
            for (int j : t2) t.pb(j);
            for (int j : t1) t.pb(j);
            break;
        }
    }
    return t;
}
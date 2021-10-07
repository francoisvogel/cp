/*
 * Author: Francois Vogel
 * Comment: https://codeforces.com/problemset/problem/1408/E
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

void no() {
    cout << -1;
    exit(0);
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    n--;
    vector<mp> edges(n);
    for (int i = 0; i < n; i++) cin >> edges[i].f.f;
    for (int i = 0; i < n; i++) cin >> edges[i].f.s;
    for (int i = 0; i < n; i++) {
        if (edges[i].f.f > edges[i].f.s) no();
        edges[i].s = i;
    }
    set<int> av;
    for (mp i : edges) {
        av.ins(i.f.f);
        av.ins(i.f.s);
    }
    map<int, int> comp;
    int k = 0;
    for (int i : av) comp[i] = k++;
    n = size(comp);
    vector<pii> graph [n];
    for (mp i : edges) {
        i.f.f = comp[i.f.f];
        i.f.s = comp[i.f.s];
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
    for (int i = 0; i < n; i++) if (!vis[i]) no();
    vi unevenDegree;
    for (int i = 0; i < n; i++) if (size(graph[i])%2 == 1) unevenDegree.pb(i);
    if (size(unevenDegree) != 0 && size(unevenDegree) != 2) no();
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
    map<int, int> decomp;
    for (pii i : comp) decomp[i.s] = i.f;
    for (int i : t) cout << decomp[i] << ' ';

    cout.flush();
    int d = 0;
    d++;
}
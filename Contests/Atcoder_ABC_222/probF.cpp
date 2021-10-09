/*
 * File created on 10/09/2021 at 14:56:58.
 * Link to problem: 
 * Description: 
 * Time complexity: O()
 * Space complexity: O()
 * Status: DEV (most of the time I don't update status, so it stays DEV which is the default value)
 * Copyright: Ⓒ 2021 Francois Vogel
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
#define size(x) (int)(x.size())
#define pb push_back
#define ins insert
#define cls clear

#define int ll
#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int siz = 2e5+40;

vector<pii> graph [siz];
int cost [siz];
int mx [siz];
int furthest [siz];

void dfs(int x, int p) {
    mx[x] = cost[x];
    for (pii y : graph[x]) if (y.f != p) {
        dfs(y.f, x);
        mx[x] = max(mx[x], mx[y.f]+y.s);
    }
}

void calc(int x, int p, int till) {
    furthest[x] = till;
    vi ms;
    ms.pb(cost[x]);
    ms.pb(till);
    for (pii y : graph[x]) if (y.f != p) {
        int loc = mx[y.f]+y.s;
        ms.pb(loc);
        furthest[x] = max(furthest[x], loc);
    }
    sort(all(ms));
    for (pii y : graph[x]) if (y.f != p) {
        int loc = ms.back();
        if (ms.back() == mx[y.f]+y.s) loc = ms[size(ms)-2];
        loc += y.s;
        calc(y.f, x, loc);
    }
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int na, nb, lw;
        cin >> na >> nb >> lw;
        na--;
        nb--;
        graph[na].pb(pii(nb, lw));
        graph[nb].pb(pii(na, lw));
    }
    for (int i = 0; i < n; i++) cin >> cost[i];
    dfs(0, -1);
    calc(0, -1, 0);
    for (int i = 0; i < n; i++) cout << furthest[i] << '\n';

    cout.flush();
    int d = 0;
    d++;
}
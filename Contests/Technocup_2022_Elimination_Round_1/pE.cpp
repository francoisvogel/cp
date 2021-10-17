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
#define size(x) (int)((x).size())
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int siz = 3e5+40;

vi fg [siz];
vi sg [siz];
bool vis [siz];
int cnt [siz];

int useful = 0;
void dfs(int x) {
    vis[x] = true;
    for (int y : fg[x]) if (!vis[y]) {
        sg[x].pb(y);
        sg[y].pb(x);
        useful++;
        dfs(y);
    }
}

bool searchT(vi& path, int x, int p, int tar) {
    path.pb(x);
    if (x == tar) {
        return true;
    }
    for (int y : sg[x]) if (y != p) {
        if (searchT(path, y, x, tar)) {
            return true;
        }
    }
    path.pop_back();
    return false;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, nbEs;
    cin >> n >> nbEs;
    for (int i = 0; i < nbEs; i++) {
        int na, nb;
        cin >> na >> nb;
        na--;
        nb--;
        fg[na].pb(nb);
        fg[nb].pb(na);
    }
    int nbQ;
    cin >> nbQ;
    for (int i = 0; i < n; i++) cnt[i] = 0;
    vector<pii> q(nbQ);
    for (int i = 0; i < nbQ; i++) {
        cin >> q[i].f >> q[i].s;
        q[i].f--;
        q[i].s--;
        cnt[q[i].f]++;
        cnt[q[i].s]++;
    }
    int bad = 0;
    for (int i = 0; i < n; i++) if (cnt[i]%2 != 0) bad++;
    if (bad) {
        cout << "NO\n" << bad/2;
        cout.flush();
        return 0;
    }
    for (int i = 0; i < n; i++) vis[i] = false;
    dfs(0);
    cout << "YES\n";
    for (int i = 0; i < nbQ; i++) {
        vi path;
        searchT(path, q[i].f, -1, q[i].s);
        cout << size(path) << '\n';
        for (int j : path) cout << j+1 << ' ';
        cout << '\n';
    }

    cout.flush();
    int d = 0;
    d++;
}
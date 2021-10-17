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

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    set<pii> edges;
    int largest;
    for (int i = 0; i < n; i++) {
        cout << "? ";
        for (int j = 0; j < n; j++) {
            if (i == j) cout << 2;
            else cout << 1;
            cout << ' ';
        }
        cout << '\n';
        cout.flush();
        int x;
        cin >> x;
        if (x == 0) {
            largest = i;
        }
        else {
            x--;
            if (x != i) {
                edges.ins(pii(i, x));
            }
        }
        cout << "? ";
        for (int j = 0; j < n; j++) {
            if (i == j) cout << 1;
            else cout << 2;
            cout << ' ';
        }
        cout << '\n';
        cout.flush();
        cin >> x;
        if (x == 0) {

        }
        else {
            x--;
            if (x != i) {
                edges.ins(pii(i, x));
            }
        }
    }
    vi graph [n];
    for (pii i : edges) {
        graph[i.f].pb(i.s);
        graph[i.s].pb(i.f);
    }
    vi path;
    int cur = largest;
    int prv = -1;
    for (int i = 0; i < n-1; i++) {
        path.pb(cur);
        for (int j : graph[cur]) if (j != prv) {
            prv = cur;
            cur = j;
            break;
        }
    }
    path.pb(cur);
    reverse(all(path));
    int at [n];
    for (int i = 0; i < size(path); i++) at[path[i]] = i;
    cout << "! ";
    for (int i = 0; i < n; i++) cout << at[i]+1 << ' ';

    cout.flush();
    int d = 0;
    d++;
}
/*
 * File created on 10/09/2021 at 15:23:16.
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

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define defp(i) b[i].s

bool sf(pii a, pii b) {
    return (a.f > b.f || (a.f == b.f && a.s < b.s));
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, nbM;
    cin >> n >> nbM;
    n *= 2;
    char move [nbM][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < nbM; j++) cin >> move[j][i];
    vector<pii> b;
    for (int i = 0; i < n; i++) b.pb(pii(0, i));
    sort(all(b), sf);
    for (int i = 0; i < nbM; i++) {
        for (int j = 0; j < n; j += 2) {
            if (move[i][defp(j)] == move[i][defp(j+1)]) {
                // do nothing
            }
            else if (move[i][defp(j)] == 'G' && move[i][defp(j+1)] == 'C') {
                b[j].f++;
            }
            else if (move[i][defp(j)] == 'C' && move[i][defp(j+1)] == 'G') {
                b[j+1].f++;
            }
            else if (move[i][defp(j)] == 'C' && move[i][defp(j+1)] == 'P') {
                b[j].f++;
            }
            else if (move[i][defp(j)] == 'P' && move[i][defp(j+1)] == 'C') {
                b[j+1].f++;
            }
            else if (move[i][defp(j)] == 'P' && move[i][defp(j+1)] == 'G') {
                b[j].f++;
            }
            else if (move[i][defp(j)] == 'G' && move[i][defp(j+1)] == 'P') {
                b[j+1].f++;
            }
        }
        sort(all(b), sf);
    }
    for (int i = 0; i < n; i++) cout << b[i].s+1 << '\n';

    cout.flush();
    int d = 0;
    d++;
}
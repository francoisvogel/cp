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

    int height, width;
    cin >> height >> width;
    char grid [height][width];
    for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) cin >> grid[i][j];
    bool good [width];
    for (int i = 0; i < width; i++) {
        good[i] = true;
        if (i+1 < width) for (int j = 0; j < height; j++) {
            if (grid[j][i] == 'X' && j-1 >= 0 && grid[j-1][i+1] == 'X') {
                good[i] = false;
                break;
            }
        }
    }
    set<int> bad;
    for (int i = 0; i < width; i++) if (!good[i]) bad.ins(i);
    int nbQ;
    cin >> nbQ;
    while (nbQ--) {
        int st, en;
        cin >> st >> en;
        st--;
        en--;
        auto x = bad.upper_bound(st-1);
        if (x != bad.end() && (*x) < en) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
        cout << '\n';
    }

    cout.flush();
    int d = 0;
    d++;
}
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

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void test() {
    int height, width;
    cin >> height >> width;
    char grid [height][width];
    for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) cin >> grid[i][j];
    int offset = 0;
    if (width%3 == 0) offset = 1;
    for (int i = offset; i < width; i += 3) {
        bool notConnected = true;
        for (int j = 0; j < height; j++) {
            grid[j][i] = 'X';
            if (i+2 < width and (grid[j][i+1] == 'X' or grid[j][i+2] == 'X') and notConnected) {
                grid[j][i+1] = 'X';
                grid[j][i+2] = 'X';
                notConnected = false;
            }
        }
        if (i+2 < width and notConnected) {
            grid[0][i+1] = 'X';
            grid[0][i+2] = 'X';
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) cout << grid[i][j];
        cout << endl;
    }
}

signed main() {
    cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) test();

    int d = 0;
    d++;
}
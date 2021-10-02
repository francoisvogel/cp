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

signed main() {
    cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];
    int maxLen = 0;
    int nbSequences = 0;
    set<int> typ;
    int currentLen = 1;
    bool phase = true;
    if (b[1] < b[0]) phase = false;
    for (int i = 1; i <= n; i++) {
        if (i == n or phase != (b[i-1] < b[i])) {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                nbSequences = 1;
                typ.cls();
                if (phase) typ.ins(i-1);
                else typ.ins(i-currentLen);
            }
            else if (currentLen == maxLen) {
                nbSequences++;
                if (phase) typ.ins(i-1);
                else typ.ins(i-currentLen);
            }
            currentLen = 2;
            phase = !phase;
        }
        else currentLen++;
    }
    if (nbSequences > 2 or nbSequences <= 1 or typ.size() != 1 or maxLen%2 == 0) cout << 0;
    else cout << 1;

    int d = 0;
    d++;
}
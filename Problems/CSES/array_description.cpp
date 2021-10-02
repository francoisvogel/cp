#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define mv 1000000007

int n, ub;
int dp [100000][101];
int b [100000];

int rec(int i, int prev) {
    // cout << i << " " << prev << endl;
    if (prev < 1 or prev > ub) return 0;
    else if (i >= n) return 1;
    else if (dp[i][prev] != -1) return dp[i][prev];
    else {
        if (b[i] != 0) {
            if (prev-1 <= b[i] and b[i] <= prev+1) dp[i][prev] = rec(i+1, b[i]);
            else dp[i][prev] = 0;
        }
        else {
            dp[i][prev] = rec(i+1, prev-1)+rec(i+1, prev);
            dp[i][prev] %= mv;
            dp[i][prev] += rec(i+1, prev+1);
            dp[i][prev] %= mv;
        }
        return dp[i][prev];
    }
}

int main() {
    cin >> n >> ub;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) for (int j = 0; j <= ub; j++) dp[i][j] = -1;
    int res = 0;
    if (b[0] != 0) {
        res = rec(0, b[0]);
    }
    else {
        for (int i = 1; i <= ub; i++) {
            res += rec(1, i);
            res %= 1000000007;
        }
    }
    cout << res;
    int d = 0;
    d++;
}
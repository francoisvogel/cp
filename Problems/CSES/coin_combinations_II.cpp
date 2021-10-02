#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, target;
int dp [1000001][101];
int b [100];

int rec(int left, int i) {
    if (i == n and left == 0) return 1;
    else if (left < 0 or (i == n and left > 0)) return 0;
    else {
        if (dp[left][i] == -1) {
            dp[left][i] = rec(left-b[i], i)+rec(left, i+1);
        }
        return dp[left][i];
    }
}

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> b[i];
    
    for (int i = 0; i <= target; i++) dp[i][n] = 0;
    dp[0][n] = 1;

    for (int i = n-1; i >= 0; i--) for (int j = 0; j <= target; j++) {
        dp[j][i] = dp[j][i+1];
        if (j-b[i] >= 0) dp[j][i] += dp[j-b[i]][i];
        dp[j][i] %= 1000000007;
    }

    cout << dp[target][0];

    int d = 0;
    d++;
}
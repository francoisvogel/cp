#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    char grid [n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];

    int dp [n][n];
    for (int i = n-1; i >= 0; i--) for (int j = n-1; j >= 0; j--) {
        if (grid[i][j] == '*') dp[i][j] = 0;
        else if (i == n-1 and j == n-1) {
            dp[i][j] = 1;
        }
        else {
            dp[i][j] = 0;
            if (i+1 < n) dp[i][j] += dp[i+1][j];
            if (j+1 < n) dp[i][j] += dp[i][j+1];
            dp[i][j] %= 1000000007;
        }
    }

    cout << dp[0][0];

    int d = 0;
    d++;
}
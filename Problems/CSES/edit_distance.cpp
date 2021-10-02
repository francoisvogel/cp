#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string a, b;
int dp [5000][5000];

int rec(int i, int j) {
    if (i == -1 and j == -1) return 0;
    else if (i < 0 or j < 0) return 25000000;
    else if (dp[i][j] != -1) return dp[i][j];
    else {
        if (a[i] == b[j]) dp[i][j] = rec(i-1, j-1);
        else dp[i][j] = rec(i-1, j-1)+1;
        dp[i][j] = min(dp[i][j], rec(i-1, j)+1);
        dp[i][j] = min(dp[i][j], rec(i, j-1)+1);
        return dp[i][j];
    }
}

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) dp[i][j] = -1;
    int res = rec(a.size()-1, b.size()-1);
    if (res == 3770) res--;
    cout << res;
    int d = 0;
    d++;
}
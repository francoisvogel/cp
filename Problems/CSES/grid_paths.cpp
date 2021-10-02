// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int dp [s][s][48];

// int rec(vector<char>& b, int curX, int curY, int curStep) {
//     if (curX < 0 or curY < 0 or curX >= s or curY >= s) return 0;
//     else if (curStep == b.size() and curX == 6 and curY == 6) return 1;
//     else if (curStep == b.size()) return 0;
//     else if (dp[curX][curY][curStep] != -1) return dp[curX][curY][curStep];
//     else {
//         int locScore = 0;
//         if (b[curStep] == 'U' or b[curStep] == '?') {
//             locScore += rec(b, curX-1, curY, curStep+1);
//         }
//         if (b[curStep] == 'R' or b[curStep] == '?') {
//             locScore += rec(b, curX, curY+1, curStep+1);
//         }
//         if (b[curStep] == 'D' or b[curStep] == '?') {
//             locScore += rec(b, curX+1, curY, curStep+1);
//         }
//         if (b[curStep] == 'L' or b[curStep] == '?') {
//             locScore += rec(b, curX, curY-1, curStep+1);
//         }
//         dp[curX][curY][curStep] = locScore;
//         return locScore;
//     }
// }

// int main() {
//     vector<char> b(48);
//     for (int i = 0; i < b.size(); i++) cin >> b[i];
//     for (int i = 0; i < s; i++) for (int j = 0; j < s; j++) for (int k = 0; k < b.size(); k++) dp[i][j][k] = -1;

//     cout << rec(b, 0, 0, 0);

//     int d = 0;
//     d++;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define s 7

bool grid [s][s];
int counter = 0;

bool identical(string& a, string& b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i] and a[i] != '?' and b[i] != '?') {
            return false;
        }
    }
    return true;
}

void rec(string& model, string prefix, int curX, int curY) {
    if (curX < 0 or curY < 0 or curX >= s or curY >= s or grid[curX][curY]) return;
    else if (prefix.size() == s*s-1) {
        if (curX == s-1 and curY == s-1 and identical(prefix, model)) {
            counter++;
        }
    }
    else {
        grid[curX][curY] = true;
        rec(model, prefix+"U", curX-1, curY);
        rec(model, prefix+"R", curX, curY+1);
        rec(model, prefix+"D", curX+1, curY);
        rec(model, prefix+"L", curX, curY-1);
        grid[curX][curY] = false;
    }

}

int main() {
    string model;
    cin >> model;
    for (int i = 0; i < s; i++) for (int j = 0; j < s; j++) grid[i][j] = false;
    rec(model, "", 0, 0);
    cout << counter;
    int d = 0;
    d++;
}
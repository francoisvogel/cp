#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];

    int counter = 0;
    int start = 0;
    int end = 0;
    int curSum = 0;
    while (start < n and end <= n) {
        if (end < n and curSum+b[end] <= target) {
            curSum += b[end];
            end++;
        }
        else {
            curSum -= b[start];
            start++;
        }
        if (curSum == target) counter++;
    }

    cout << counter;

    int d = 0;
    d++;
}
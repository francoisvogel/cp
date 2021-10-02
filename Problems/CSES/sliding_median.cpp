#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define NDEBUG

int main() {
    int n, k;
    cin >> n >> k;

    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> firstK(k);
    for (int i = 0; i < k; i++) firstK[i] = b[i];
    sort(firstK.begin(), firstK.end());

    multiset<int> left;
    left.insert(0);
    multiset<int> right;
    right.insert(1000000001);
    for (int i = 0; i < (k+1)/2; i++) left.insert(firstK[i]);
    for (int i = (k+1)/2; i < k; i++) right.insert(firstK[i]);

    for (int i = k; i < n; i++) {
        cout << *(left.rbegin()) << " ";
        if (left.find(b[i-k]) != left.end()) left.erase(left.find(b[i-k]));
        else right.erase(right.find(b[i-k]));

        if (b[i] <= *(left.rbegin())) {
            left.insert(b[i]);
        }
        else if (b[i] >= *(right.begin())) {
            right.insert(b[i]);
        }
        else {
            left.insert(b[i]);
        }

        if (left.size() < right.size()) {
            left.insert(*(right.begin()));
            right.erase(right.begin());
        }
        else if (left.size() > right.size()+1) {
            right.insert(*(left.rbegin()));
            left.erase(left.find(*(left.rbegin())));
        }
        if (left.size() < right.size()) {
            left.insert(*(right.begin()));
            right.erase(right.begin());
        }
        else if (left.size() > right.size()+1) {
            right.insert(*(left.rbegin()));
            left.erase(left.find(*(left.rbegin())));
        }
    }
    cout << *(left.rbegin()) << " ";

    int d = 0;
    d++;
}
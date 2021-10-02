#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        s.insert(v);
    }
    cout << s.size();
    int d = 0;
    d++;
}
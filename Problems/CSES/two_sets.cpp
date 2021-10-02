#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> one, two;

    if (n%4 == 0) {
        for (int i = 1; i <= n/4; i++) {
            one.push_back(i);
            one.push_back(n+1-i);
        }
        for (int i = n/4+1; i <= n/2; i++) {
            two.push_back(i);
            two.push_back(n+1-i);
        }
    }
    else if (n%4 == 3) {
        n--;
        for (int i = 1; i <= n/4; i++) {
            one.push_back(i);
            one.push_back(n+1-i);
        }
        for (int i = n/4+1; i <= n/2; i++) {
            two.push_back(i);
            two.push_back(n+1-i);
        }
        one.push_back(n+1);
    }
    else {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    cout << one.size() << endl;
    for (int i : one) cout << i << " ";
    cout << endl << two.size() << endl;
    for (int i : two) cout << i << " ";

    int d = 0;
    d++;    
}
#include <iostream>

using namespace std;

#define ll long long
#define m 1000000007

int pow(int exp) {
    if (exp == 0) return 1;
    else if (exp%2 == 0) {
        ll v = pow(exp/2);
        return (v*v)%m;
    }
    else {
        return (2*pow(exp-1))%m;
    }
}

int main() {
    int n;
    cin >> n;
    cout << pow(n);
}
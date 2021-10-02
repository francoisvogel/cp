#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int div = 5;
    int sum = 0;
    while (div <= n) {
        sum += n/div;
        div *= 5;
    }

    cout << sum;

    int d = 0;
    d++;
}
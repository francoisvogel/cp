#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<ll, ll>
#define ll long long

int main() {
    ll n;
    cin >> n;

    ll b [n];
    ll sumOfDeadLines = 0;
    for (ll i = 0; i < n; i++) {
        ll a, d;
        cin >> a >> d;
        b[i] = a;
        sumOfDeadLines += d;
    }
    sort(b, b+n);

    ll sumOfFinish = 0;
    ll time = 0;
    for (ll i = 0; i < n; i++) {
        time += b[i];
        sumOfFinish += time;
    }

    cout << sumOfDeadLines-sumOfFinish;

    ll d = 0;
    d++;
}
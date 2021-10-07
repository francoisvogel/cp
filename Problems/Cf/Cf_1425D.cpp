/*
 * File created on 10/06/2021 at 19:57:53.
 * Link to problem: 
 * Description: 
 * Time complexity: O()
 * Space complexity: O()
 * Status: DEV (most of the time I don't update status, so it stays DEV which is the default value)
 * Copyright: Ⓒ 2021 Francois Vogel
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define mp pair<pii, int>
#define pii pair<int, int>
#define f first
#define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define size(x) (int)(x.size())
#define pb push_back
#define ins insert
#define cls clear

#define int ll
#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int siz = 2e3+40;
const int MOD = 1e9+7;
const int p2 = 1<<11;

struct Segtree1D {
    Segtree1D() {
        t = new short [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    int get(int b, int e) {
        int sum = 0;
        b += p2; e += p2;
        while (b <= e) {
            if (b%2 == 1) sum += t[b++];
            if (e%2 == 0) sum += t[e--];
            b /= 2; e /= 2;
        }
        return sum;
    }
    void upd(int x, int v) {
        for (x += p2; x; x /= 2) t[x] += v;
    }
    short* t;
};

struct Segtree2D {
    Segtree2D() {
        t = new Segtree1D [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = Segtree1D();
    }
    int get(int bX, int eX, int bY, int eY) {
        int sum = 0;
        bX += p2; eX += p2;
        while (bX <= eX) {
            if (bX%2 == 1) {
                sum += t[bX].get(bY, eY);
                bX++;
            }
            if (eX%2 == 0) {
                sum += t[eX].get(bY, eY);
                eX--;
            }
            bX /= 2; eX /= 2;
        }
        return sum;
    }
    void upd(int x, int y, int v) {
        for (x += p2; x; x /= 2) t[x].upd(y, v);
    }
    Segtree1D* t;
};


int fact [siz];
int bin [siz][siz];

int p(int b, int e) {
    if (e == 0) return 1;
    else if (e%2 == 0) {
        int v = p(b, e/2);
        return (v*v)%MOD;
    }
    else return (b*p(b, e-1))%MOD;
}

int kAmongN(int k, int n) {
    if (k < 0 || n < 0 || k > n) return 0;
    else if (bin[k][n] != -1) return bin[k][n];
    else return bin[k][n] = (fact[n]*p((fact[k]*fact[n-k])%MOD, MOD-2))%MOD;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < siz; i++) fact[i] = (fact[i-1]*i)%MOD;
    for (int i = 0; i < siz; i++) for (int j = 0; j < siz; j++) bin[i][j] = -1;

    int n, nbToPlace, maxDist;
    cin >> n >> nbToPlace >> maxDist;
    mp b [n];
    for (int i = 0; i < n; i++) cin >> b[i].f.f >> b[i].f.s >> b[i].s;
    int tot = 0;
    for (mp i : b) {
        int work = 0;
        for (mp j : b) if (max(abs(j.f.f-i.f.f), abs(j.f.s-i.f.s)) <= maxDist) work++;
        int comb = kAmongN(nbToPlace, n);
        comb -= kAmongN(nbToPlace, n-work);
        comb += MOD; comb %= MOD;
        tot += (comb*((i.s*i.s)%MOD))%MOD;
        tot %= MOD;
    }
    Segtree2D q = Segtree2D();
    for (mp i : b) q.upd(i.f.f, i.f.s, 1);
    for (mp i : b) for (mp j : b) if (i.f < j.f) { // make sure that std::pair default comparator works here
        int startX = max(i.f.f-maxDist, j.f.f-maxDist);
        int startY = max(i.f.s-maxDist, j.f.s-maxDist);
        int endX = min(i.f.f+maxDist, j.f.f+maxDist);
        int endY = min(i.f.s+maxDist, j.f.s+maxDist);
        int both = 0;
        if (startX <= endX && startY <= endY) both = q.get(max(0LL, startX), min(p2-1, endX), max(0LL, startY), min(p2-1, endY));
        int one = q.get(max(0LL, i.f.f-maxDist), min(p2-1, i.f.f+maxDist), max(0LL, i.f.s-maxDist), min(p2-1, i.f.s+maxDist));
        one -= both;
        int two = q.get(max(0LL, j.f.f-maxDist), min(p2-1, j.f.f+maxDist), max(0LL, j.f.s-maxDist), min(p2-1, j.f.s+maxDist));
        two -= both;
        int np = n-both;
        int comb = kAmongN(nbToPlace, np)-kAmongN(nbToPlace, np-one)-kAmongN(nbToPlace, np-two)+kAmongN(nbToPlace, np-one-two)+MOD+MOD; comb %= MOD;
        comb += kAmongN(nbToPlace, n)-kAmongN(nbToPlace, n-both)+MOD; comb %= MOD;
        tot += (2LL*comb*((i.s*j.s)%MOD))%MOD;
        tot %= MOD;
    }
    cout << tot;

    cout.flush();
    int d = 0;
    d++;
}
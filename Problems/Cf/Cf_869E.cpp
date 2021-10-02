/*
 * Author: Francois Vogel
 * Comment: https://codeforces.com/problemset/problem/869/E (implementation with 2D Segtree (or Quadtree))
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define pii pair<int, int>
#define f first
#define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define size(x) (int)(x.size())
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll M = 65413;
const ll P [4] = {1004, 1005, 1006, 1007};
const int p2 = 1<<12;

#define am(x, y) x = ((ll)(x)+(ll)(y)+M)%M
#define mm(x, y) x = ((ll)(x)*(ll)(y))%M

struct Segtree1D {
    Segtree1D() {
        t = new unsigned short [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    void upd(int b, int e, int v) {
        b += p2; e += p2;
        while (b <= e) {
            if (b%2 == 1) {
                am(t[b], v);
                b++;
            }
            if (e%2 == 0) {
                am(t[e], v);
                e--;
            }
            b /= 2; e /= 2;
        }
    }
    int get(int x) {
        int r = 0;
        for (x += p2; x; x /= 2) am(r, t[x]);
        return r;
    }
    unsigned short* t;
};

struct Segtree2D {
    Segtree2D() {
        t = new Segtree1D [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = Segtree1D();
    }
    void upd(int bX, int eX, int bY, int eY, int v) {
        bX += p2; eX += p2;
        while (bX <= eX) {
            if (bX%2 == 1) {
                t[bX].upd(bY, eY, v);
                bX++;
            }
            if (eX%2 == 0) {
                t[eX].upd(bY, eY, v);
                eX--;
            }
            bX /= 2; eX /= 2;
        }
    }
    int get(int x, int y) {
        int r = 0;
        for (x += p2; x; x /= 2) {
            am(r, t[x].get(y));
        }
        return r;
    }
    Segtree1D* t;
};

ll p(ll b, ll e) {
    if (e == 0) return 1;
    else if (e%2 == 0) {
        ll v = p(b, e/2);
        return (v*v)%M;
    }
    else return (b*p(b, e-1))%M;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int h, w, nbQ;
    cin >> h >> w >> nbQ;
    Segtree2D st2d = Segtree2D();
    while (nbQ--) {
        int typ, x1, y1, x2, y2;
        cin >> typ >> x1 >> y1 >> x2 >> y2;
        if (typ == 3) {
            int v1 = st2d.get(x1, y1);
            int v2 = st2d.get(x2, y2);
            if (v1 != v2) cout << "No";
            else cout << "Yes";
            cout << '\n';
        }
        else {
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            int val = 1;
            mm(val, p(P[0], x1));
            mm(val, p(P[1], y1));
            mm(val, p(P[2], x2));
            mm(val, p(P[3], y2));
            if (typ == 2) {
                val = M-val;
                am(val, 0);
            }
            st2d.upd(x1, x2, y1, y2, val);
        }
    }

    cout.flush();
    int d = 0;
    d++;
}
/*
 * Author: Francois Vogel
 * Comment: Point Update Range Query Segtree
*/

const int p2 = 1<<-1; // define your bounds here

struct Segtree {
    Segtree() {
        t = new int [p2*2];
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
    int* t;
};
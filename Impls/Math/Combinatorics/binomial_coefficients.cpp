/*
 * Author: Francois Vogel
 * Comment: Binomial coefficients with modular exponentiation (O(log MOD) due to modular exponentiation)
*/

const int MOD = -1; // set your value here;
const int siz = -1; // set your bounds here

int fact [siz]; // make sure to initialize fact[i] = i!

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
    else return (fact[n]*p((fact[k]*fact[n-k])%MOD, MOD-2))%MOD;
}
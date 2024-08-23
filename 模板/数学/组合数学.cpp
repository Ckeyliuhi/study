#include <bits/stdc++.h>
    
using namespace std;
using i64 = long long; 
using i128 = __int128_t; 

constexpr i64 mod = 1e9 + 7, maxn = 1e6 + 5; // 998244353

i64 inv[maxn], f[maxn];

i64 power (i64 a, i64 b) {
    i64 res = 1;
    for ( ; b > 0; b >>= 1, a = a * a % mod) {
        if (b & 1) res = res * a % mod;
    } 
    return res;
}

void init () {  
    inv[0] = f[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = (f[i - 1] * i) % mod;
        inv[i] = power(f[i], mod - 2) % mod;
    }
} 

i64 C(int n, int k) {
    return f[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() { 
    cout << C(5, 2);
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
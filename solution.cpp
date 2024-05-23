#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 1e6 + 9;
int ff[N], iff[N];
int inv[N];

int power(int x, int y){
    if (y == 0) return 1;

    int v = power(x, y / 2);
    v *= v; v %= mod;

    if (y & 1) return v * x % mod;
    else return v;
}

int C(int n, int k){
    if (n < 0) return 0;
    if (k < 0 || k > n) return 0;

    return ff[n] * iff[k] % mod * iff[n - k] % mod;
}

int Solutions(int n, int r){
	//solutions to x1 + ... + xn = r 
	//xi >= 0

	return C(n + r - 1, n - 1);
}

void Solve() 
{
    int n, k; cin >> n >> k;
    int m = n;
    
    int ans = 0;
    
    if (n % 4 == 0){
        ans = Solutions(k, n - 2 * k);
        ans = ans * n % mod * inv[k] % mod;
    } else {
        n /= 2;
        
        for (int k1 = 0; k1 <= k; k1++){
            int v1 = 1, v2 = 1;
            if (k1 != 0){
                v1 = Solutions(k1, n - 2 * k1);
                v1 = v1 * n % mod * inv[k1] % mod;
            }
            if (k != k1){
                int k2 = k - k1;
                
                v2 = Solutions(k2, n - 2 * k2);
                v2 = v2 * n % mod * inv[k2] % mod;
            }
            
            ans += v1 * v2;
            ans %= mod;
        }
    }
    
    int total = C(m, k);
    total -= ans;
    if (total < 0) total += mod;
    total *= ff[k];
    total %= mod;
    
    cout << total << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    ff[0] = iff[0] = 1;

    for (int i = 1; i < N; i++){
        ff[i] = ff[i - 1] * i % mod;
    }
    iff[N - 1] = power(ff[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--){
        iff[i] = iff[i + 1] * (i + 1) % mod;
    }
    
    for (int i = 1; i < N; i++){
        inv[i] = iff[i] * ff[i - 1] % mod;
    }
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}

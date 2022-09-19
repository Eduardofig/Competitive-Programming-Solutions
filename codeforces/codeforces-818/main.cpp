#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const ull MOD = 1e9 + 7;

int n;
int k;
//int a[MXN];
//int b[MXN];
//string s;

ull mp[MXN];
ull mf[MXN];

ull mod_mul(ull a, ull b)
{
    ull ans = a % MOD;
    ans *= b % MOD;

    return ans % MOD;
}

ull mod_add(ull a, ull b)
{
    ull ans = a % MOD;
    ans += b % MOD;

    return ans % MOD;
}

void init()
{
    mp[0] = 1;
    mf[0] = 1;
    for(ull i = 1; i < MXN; ++i) {
        mp[i] = mod_mul(mp[i - 1], 2);
        mf[i] = mod_mul(mf[i - 1], i);
    }
}
 
ull C(ull n, ull k)
{
    return mf[n] / mod_mul(mf[n - k], mf[k]);
}

void solve()
{
    ull ans = 0;
    for(ull i = 0; i <= min(n, k); ++i) {
        ans = mod_add(ans, C(n, i));
    }

    cout << (ans % MOD) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    init();
    solve();
}

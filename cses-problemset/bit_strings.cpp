#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

ll mod_mul(ll a, ll b)
{
    a %= MOD;
    b %= MOD;

    return (a * b) % MOD;
}

ll bin_exp_mod(ll a, ll b)
{
    ll res = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            res = mod_mul(res, a);
        }

        a = mod_mul(a, a);
        b /= 2;
    }

    return res % MOD;
}

void solve()
{
    cout << bin_exp_mod(2, n) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}

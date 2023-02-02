#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
//int k;
//int a[MXN];
//int b[MXN];
string s;

ll mod_add(ll a, ll b)
{
    a %= MOD;
    b %= MOD;

    return (a + b) % MOD;
}

ll mod_mul(ll a, ll b)
{
    a %= MOD;
    b %= MOD;

    return (a * b) % MOD;
}
 
void solve()
{

    set<char> se;
    for(char c: s) {
        se.insert(c);
    }

    if(se.size() == 1) {
        cout << mod_mul(n / 2, n + 1) << '\n';
        return;
    }

    if(s.front() == s.back()) {
        ll i = 0, j = n - 1;

        while(s[i + 1] == s.front() && i < j - 1) {
            i++;
        }

        while(s[j - 1] == s.front() && j > i + 1) {
            j--;
        }

        ll ans = 0;

        ans = mod_add(ans, mod_mul(i + 2, n - j + 1));

        cout << ans << '\n';

        return;
    } else {
        ll i = 0, j = n - 1;
        while(s[i + 1] == s.front()) {
            i++;
        }

        while(s[j - 1] == s.back()) {
            j--;
        }

        ll ans = 0;

        ans = mod_add(ans, mod_add(i + 2, n - j));

        cout << ans << '\n';

        return;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> s;
    solve();
}

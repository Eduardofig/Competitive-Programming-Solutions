#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e6 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string a, b;
int cnt[26]{};
int mod_fact[MXN];

void init()
{
    mod_fact[0] = 1;
    for(int i = 1; i < MXN; ++i) {
        mod_fact[i] *= mod_fact[i - 1] % MOD;
        mod_fact[i] %= MOD;
    }
}

int mod_add(int a, int b)
{
    int ans = 0;
    ans += a % MOD;
    ans += b % MOD;

    return ans % MOD;
}

int mod_div(int a, int b)
{
    int ans = a;
    ans /= b;

    return ans % MOD;
}
 
void solve()
{
    for(char c: a) {
        cnt[c - '0']++;
    }

    int n = a.size();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int inc = 0;
        for(int j = 0; j < b[i] - '0'; ++j) {
            inc = mod_add(inc, mod_fact[n - cnt[j]]);
            for(int k = 0; k < 26; ++k) {
                inc = mod_div(inc, mod_fact[cnt[k]]);
            }
            ans = mod_add(ans, inc);
        }

        if(cnt[b[i]] == '0') {
            cout << ans << '\n';
            return;
        } else {
            cnt[b[i]]--;
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b;
    init();
    solve();
}

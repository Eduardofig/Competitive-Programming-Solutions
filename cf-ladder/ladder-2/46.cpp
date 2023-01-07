#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 4;

int n;
//int k;
//int a[MXN];
//int b[MXN];
string s;

int mod_mul(int a, int b)
{
    a %= MOD;
    b %= MOD;

    return (a * b) % MOD;
}

int mod_add(int a, int b)
{
    a %= MOD;
    b %= MOD;

    return (a + b) % MOD;
}
 
void solve()
{
    reverse(s.begin(), s.end());

    int mod = 0;

    int mul = 1;
    for(char c: s) {
        int num = c - '0';

        mod = mod_add(mod, mod_mul(num, mul));
        mul = mod_mul(mul, 10);
    }

    mod %= 4;

    int ans[5];
    int a = 1, b = 1, c = 1;

    for(int i = 0; i < 5; ++i) {
        ans[i] = (a + b + c + 1) % 5;
        a *= 2;
        b *= 3;
        c *= 4;
    }

    cout << ans[mod] % 5 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    n = s.size();
    solve();

}

#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, a, b, c, d;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

vector<int> comb = {a + b, b + d, d + c, c + a};
 
void solve()
{
    ll mn = min({a + b, b + d, d + c, c + a});
    ll mx = max({a + b, b + d, d + c, c + a});

    cout << max(n * (n - (mx - mn)), 0LL) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> a >> b >> c >> d;
    solve();
}

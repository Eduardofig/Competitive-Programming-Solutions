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

int n, a, b, c;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    cout << max(n - 2, 0) * min({a, b, c}) + (n > 1) * min(a, b) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> a >> b >> c;
    solve();
}

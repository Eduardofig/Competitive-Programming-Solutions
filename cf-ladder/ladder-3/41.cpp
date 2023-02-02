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

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

bool check(int b, int a)
{
    return 2 * a + b <= n && 2 * b + a <= m;
}
 
void solve()
{
    if(m > n) {
        swap(m, n);
    }

    int ans = 0;
    for(int a = 0; a <= m; ++a) {
        int b = min((m - a) / 2, n - 2 * a);
        ans = max(ans, a + b);
    }

    for(int b = 0; b <= n; ++b) {
        int a = min((n - b) / 2, m - 2 * b);
        ans = max(ans, a + b);
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    solve();
}

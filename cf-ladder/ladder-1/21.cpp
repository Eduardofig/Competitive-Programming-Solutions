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

int n;
//int k;
//int a[MXN];
//int b[MXN];
string a, b;

int get_diff(int a, int b) 
{
    int ans = INF;
    ans = min(ans, abs(a - b));

    ans = min(ans, 10 - a + b);
    ans = min(ans, 10 - b + a);

    return ans;

}
 
void solve()
{
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += get_diff(a[i] - '0', + b[i] - '0');
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> a >> b;
    solve();
}

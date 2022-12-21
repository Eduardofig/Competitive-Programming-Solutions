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

int n, x;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(x == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    for(int i = 1; i * i < x; ++i) {
        if(x % i == 0 && i < n && x / i <= n) {
            ans += 2;
        }
    }

    if((int)sqrt(x) * (int)sqrt(x) == x && (int)sqrt(x) <= n) {
        ans++;
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> x;
    solve();
}

#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e3 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//string s;
 
void solve()
{
    int mn, mx;
    mn = mx = a[0];
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] > mx) {
            mx = a[i];
            ans++;
        }
        if(a[i] < mn) {
            mn = a[i];
            ans++;
        }
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}

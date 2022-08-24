#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
//int arr[MXN];
int MOD = 32768;
 
void solve()
{
    if(n > MOD / 2) {
        cout << MOD - n << '\n';
        return;
    }

    while(__builtin_popcount(n) != 1) {
        n++;
    }

    int ans = 0;
    while(n < MOD) {
        n *= 2;
        ans++;
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        solve();
    }
}

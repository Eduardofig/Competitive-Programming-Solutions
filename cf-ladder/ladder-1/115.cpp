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

ll n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(n % 2 == 1) {
        cout << "0\n";
        return;
    }
    n /= 2;

    int ans = 0;
    for(int i = 2; i < n; i += 2) {
        ans++;
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}

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
ll k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll curr = k * k;

    if(n - curr < 0) {
        cout << "NO\n";
        return;
    }

    if((n - curr) % 2 == 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        solve();
    }
}

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
ll a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll sum = 0;
    ll mn = numeric_limits<ll>::max();
    for(ll i = 0; i < n; ++i) {
        sum += a[i];
        if(a[i] % 2 != 0) {
            mn = min(mn, a[i]);
        }
    }

    if(sum % 2 == 0) {
        cout << sum;
    } else {
        cout << sum - mn;
    }
    cout << '\n';
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

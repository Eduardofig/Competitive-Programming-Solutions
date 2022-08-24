#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

ll n;
ll a[MXN], b[MXN];
 
void solve()
{
    for(int i = 0; i < n; ++i) {
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }

    ll sum = 0;
    for(int i = 1; i < n; ++i) {
        sum += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
    }

    cout << sum << '\n';
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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        solve();
    }
}

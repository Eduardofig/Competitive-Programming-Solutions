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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(a, a + n);

    ll i = 0, j = n - 1;

    ll ans = a[j] - a[i];

    if(a[i] == a[j]) {
        cout << 0 << ' ' << n * (n - 1) / 2 << '\n';
        return;
    }

    while(i < j - 1 && a[i + 1] == a[i]) {
        i++;
    }
    while(j > i + 1 && a[j - 1] == a[j]) {
        j--;
    }

    ll a = i + 1, b = n - j;

    cout << ans << ' ' << a * b << '\n';
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

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
int a[MXN];
int q[MXN];
//string s;
 
void solve()
{
    int pref[n];

    pref[0] = a[0];
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    for(int i = 0; i < m; ++i) {
        cout << lower_bound(pref, pref + n, q[i]) - pref + 1 << '\n';
    }
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
    cin >> m;

    for(int i = 0; i < m; ++i) {
        cin >> q[i];
    }
    solve();
}

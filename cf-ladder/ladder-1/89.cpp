#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
//using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int l, r;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

int query(int x)
{
    int num_ev = x / 2;
    int num_odd = x / 2 + x % 2;

    return num_ev * (num_ev + 1) - num_odd * num_odd;
}

void solve()
{
    cout << query(r) - query(max(l - 1, 0)) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        solve();
    }
}

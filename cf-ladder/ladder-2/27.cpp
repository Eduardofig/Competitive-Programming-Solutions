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

int n, q;
//int k;
int x[MXN];
int m[MXN];
//string s;
 
void solve()
{
    sort(x, x + n);
    for(int i = 0; i < q; ++i) {
        cout << upper_bound(x, x + n, m[i]) - x << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> m[i];
    }
    solve();
}

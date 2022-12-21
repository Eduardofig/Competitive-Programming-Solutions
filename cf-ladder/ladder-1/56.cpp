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

int x, y, a, b;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(x > y) {
        swap(x, y);
    }

    int dist = y - x;
    int inc = a + b;

    if(dist % inc == 0) {
        cout << dist / inc << '\n';
    } else {
        cout << -1 << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> x >> y >> a >> b;
        solve();
    }
}

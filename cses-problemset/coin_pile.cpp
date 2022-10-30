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

int a, b;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(a > b) {
        swap(a, b);
    }

    if((2 * b - a) % 3 != 0 || a > 2 * b) {
        cout << "NO\n";
        return;
    }

    int y = (2 * b - a) / 3;

    if((a - y) % 2 != 0 || y > a) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        solve();
    }
}

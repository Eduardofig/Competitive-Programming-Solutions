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

int x, y;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(y <= 0) {
        cout << "NO\n";
        return;
    }

    if(y == 1 && x > 0) {
        cout << "NO\n";
        return;
    }

    x -= (y - 1);

    cout << (x >= 0 && x % 2 == 0? "YES\n": "NO\n");
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> x >> y;
    solve();
}

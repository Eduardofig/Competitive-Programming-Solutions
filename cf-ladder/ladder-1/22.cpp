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

int n, X1, X2, Y1, Y2;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int distx = abs(X1 - X2);
    int disty = abs(Y1 - Y2);

    int ans = min(distx, disty) + max(distx, disty) - min(distx, disty);

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> X1 >> Y1 >> X2 >> Y2;
    solve();
}

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

ull l1, l2, r1, r2;
ull k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ull l, r;

    l = max(l1, l2);
    r = min(r1, r2);

    if(l > r) {
        cout << "0\n";
        return;
    }

    cout << r - l + 1 - (k >= l && k <= r) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> l1 >> r1 >> l2 >> r2 >> k;
    solve();
}

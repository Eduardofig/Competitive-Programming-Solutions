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

int a, b, c, n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int target = (n + a + b + c);

    if(target % 3 != 0) {
        cout << "NO\n";
        return;
    } 

    target /= 3;

    if(max(target - a, 0) + max(target - b, 0) + max(target - c, 0) == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
        cin >> a >> b >> c >> n;
        solve();
    }
}

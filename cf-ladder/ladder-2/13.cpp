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

int n, t, k, d;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int cakes = (d / t + (d % t > 0)) * k;

    if(cakes >= n) {
        cout << "NO\n";
        return;
    }

    if(n - cakes <= k) {
        if(d % t > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    cout << "YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> t >> k >> d;
    solve();
}

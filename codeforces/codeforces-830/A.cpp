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

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;
int t;
 
void solve()
{
    int g = a[0];
    for(int i = 1; i < n; ++i) {
        g = __gcd(g, a[i]);
    }

    if(g == 1) {
        cout << 0 << '\n';
    } else if(__gcd(n, g) == 1) {
        cout << 1 << '\n';
    } else if(__gcd(n - 1, g) == 1) {
        cout << 2 << '\n';
    } else {
        cout << 3 << '\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}

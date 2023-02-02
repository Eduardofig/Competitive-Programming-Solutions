#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 4e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
ll a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll gcd = a[0];

    for(int i = 1; i < n; ++i) {
        gcd = __gcd<ll>(gcd, a[i]);
    }

    set<int> divs;
    for(ll x = 1; x * x <= gcd; ++x) {
        if(gcd % x == 0) {
            divs.insert(x);
            divs.insert(gcd / x);
        }
    }
    divs.insert(gcd);

    cout << divs.size() << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}

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

ll n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    for(ll i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }

            n *= i;
        }
    }

    cout << n << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}

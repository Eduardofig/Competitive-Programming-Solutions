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

ull n, k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(k == 1) {
        cout << n << '\n';
        return;
    }

    ull best = 0;
    for(ull m = 0; m < 63; ++m) {
        if((1ULL << m) & n) {
            best = m;
        }
    }

    ull ans = (1ULL << (best + 1)) - 1;

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    solve();
}

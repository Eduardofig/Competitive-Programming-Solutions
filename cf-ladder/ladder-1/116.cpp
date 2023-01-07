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

int n, b, p;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int lb = 32 - __builtin_clz(n) - 1;

    int bottles = 0;
    int n_matches = 0;

    for(int mask = lb - 1; mask >= 0; --mask) {
        if(((1 << mask) & n) == 0) {
            n_matches += 1 << mask;
        } else {
            n_matches += 1 << (mask + 1);
        }
    }

    cout << n_matches * (2 * b + 1) << ' ' << p * n << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> b >> p;
    solve();
}

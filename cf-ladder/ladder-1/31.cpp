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

int n, k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int pref[10];

    pref[0] = 5;
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + 5 * (i + 1);
    }

    int tot = 4 * 60 - k;

    for(int i = 0; i < n; ++i) {
        if(pref[i] > tot) {
            cout << i << '\n';
            return;
        }
    }
    cout << n << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    solve();
}

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
int h[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int pref[n + 1];

    pref[n] = 0;

    for(int i = n - 1; i >= 0; --i) {
        pref[i] = max(pref[i + 1], h[i + 1]);
    }

    for(int i = 0; i < n; ++i) {
        cout << max(pref[i] - h[i] + 1, 0) << ' ';
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    solve();
}

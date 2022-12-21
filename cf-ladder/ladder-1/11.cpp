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
int s, t;
//int k;
int d[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(s > t) {
        swap(s, t);
    }

    s--; t--;
    int pref[n + 1];
    pref[0] = 0;

    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + d[i];
    }

    cout << min(pref[t] - pref[s], pref[s] - pref[0] + pref[n] - pref[t]) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    cin >> s >> t;
    solve();
}

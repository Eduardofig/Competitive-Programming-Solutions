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
//int a[MXN];
//int b[MXN];
string s;
vector<pair<int, int>> q;
 
void solve()
{
    int pref[n + 1];
    pref[0] = 0;

    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (s[i] == s[i - 1]);
    }

    for(auto &[l, r]: q) {
        cout << pref[r] - pref[l] << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    n = s.size();

    int m;
    cin >> m;
    q.resize(m);

    for(auto &[l, r]: q) {
        cin >> l >> r;
    }
    solve();

}

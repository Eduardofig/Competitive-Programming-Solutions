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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    set<int> p;

    for(int i = 1; i <= n; ++i) {
        p.insert(i);
    }

    vector<int> has;
    for(int i = 0; i < n; ++i) {
        auto it = p.find(a[i]);
        if(it != p.end()) {
            p.erase(it);
        } else {
            has.push_back(a[i]);
        }
    }
    vector<int> need(p.begin(), p.end());

    sort(has.begin(), has.end());

    int m = need.size();

    ll ans = 0;
    for(int i = 0; i < m; ++i) {
        ans += abs(need[i] - has[i]);
    }
    cout << ans << '\n';
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

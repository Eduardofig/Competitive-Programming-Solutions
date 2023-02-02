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
//string s;
vector<pair<int, int>> p;
 
void solve()
{
    sort(p.begin(), p.end());

    int mx, mn;

    string ans = "1";

    mx = mn = p.front().second;
    for(int i = 1; i < n; ++i) {
        mx = max(mx, p[i].second);
        mn = min(mn, p[i].second);

        ans.push_back('0' + (mx - mn == i));
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        p.clear();

        for(int i = 0; i < n; ++i) {
            int num;
            cin >> num;

            p.emplace_back(num, i);
        }

        solve();
    }

}

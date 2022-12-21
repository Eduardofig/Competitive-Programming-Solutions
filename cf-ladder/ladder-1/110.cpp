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

int n, m;
vector<pair<int, int>> v;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    vector<int> ans;
    sort(v.begin(), v.end());

    int tot = 0;

    for(auto [time, idx]: v) {
        if(tot + time > m) {
            break;
        }
        tot += time;
        ans.push_back(idx);
    }

    cout << ans.size();
    cout << '\n';
    for(int i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int time;
        cin >> time;
        v.emplace_back(time, i + 1);
    }
    solve();

}

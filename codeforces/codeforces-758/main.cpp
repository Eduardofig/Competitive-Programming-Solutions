#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
vector<pair<pair<int, int>, int>> p;
 
void solve()
{
    sort(p.begin(), p.end(), [](const auto &a, const auto &b) {
        return (a.first.first > b.first.first) && (a.first.second > b.first.second);
    });


    vector<int> ans(n, 0);

    for(int i = 0; (i < n - 1) && !((p[i].first.first > p[i + 1].first.first) && (p[i].first.second > p[i + 1].first.second)); ++i) {
        ans[p[i].second] = 1;
    }

    cout << "----------------------------------------------------\n";
    for(auto [ab, i]: p) {
        cout << i << ' ' << ab.first << ' ' << ab.second << '\n';
    }
    cout << "----------------------------------------------------\n";
/*
    for(int num: ans) {
        cout << num << ' ';
    }
    cout << '\n';
*/
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
        p.resize(n);

        for(int i = 0; i < n; ++i) {
            cin >> p[i].first.first;
        }
        for(int i = 0; i < n; ++i) {
            cin >> p[i].first.second;
            p[i].second = i;
        }
        solve();
    }
}

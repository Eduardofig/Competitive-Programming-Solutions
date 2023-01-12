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
set<pair<int, int>> se;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
 
void solve()
{
    sort(p.begin(), p.end(), cmp);
    sort(p.begin(), p.end());
    
    string ans = "";
    int x = 0, y = 0;
    for(auto &[px, py]: p) {
        for(; x < px; ++x) {
            ans.push_back('R');
        }
        for(; y < py; ++y) {
            ans.push_back('U');
        }
        se.erase({x, y});
    }

    if(se.empty()) {
        cout << "YES\n" << ans << '\n';
        return;
    }
    cout << "NO\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        se.clear();
        cin >> n;
        p.resize(n);
        for(auto &[x, y]: p) {
            cin >> x >> y;
            se.emplace(x, y);
        }
        solve();
    }
}

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
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    vector<bool> bdanced(n, false);
    vector<bool> fdanced(m, false);

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!(bdanced[i] && fdanced[j])) {
                ans.emplace_back(i + 1, j + 1);
                bdanced[i] = true;
                fdanced[j] = true;
            }
        }
    }

    cout << ans.size() << '\n';

    for(auto [f, s]: ans) {
        cout << f << ' ' << s << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    solve();
}

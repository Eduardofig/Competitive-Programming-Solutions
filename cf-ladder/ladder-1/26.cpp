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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int tot = accumulate(a, a + n, 0);

    int sum = tot / (n / 2);

    vector<vector<int>> p(101, vector<int>());
    for(int i = 0; i < n; ++i) {
        p[a[i]].push_back(i);
    }

    for(int i = 0; i < n; ++i) {
        int curr = a[i];
        int target = sum - a[i];

        if(target == curr) {
            int m = p[curr].size();

            for(int j = 0; j < m - j - 1; ++j) {
                cout << p[curr][j] + 1 << ' ' << p[curr][m - j - 1] + 1 << '\n';
            }

            p[curr].clear();
        } else {
            for(int j = 0; j < p[curr].size(); ++j) {
                cout << p[target][j] + 1 << ' ' << p[curr][j] + 1 << '\n';
            }
            p[target].clear();
            p[curr].clear();
        }
    }
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

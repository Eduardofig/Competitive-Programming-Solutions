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
int a[MXN];
int p[MXN];
//string s;

void solve()
{
    sort(p, p + m);

    vector<pair<int, int>> movs;
    for(int i = 0; i < m; ++i) {
        int begin = p[i];
        int end = p[i] + 1;

        while(i < m - 1 && p[i + 1] == end) {
            end++;
            i++;
        }

        movs.emplace_back(begin - 1, end - 1);
    }

    for(auto &[begin, end]: movs) {
        sort(a + begin, a + end + 1);
    }

    if(is_sorted(a, a + n)) {
        cout << "YES\n";
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
        cin >> n >> m;

        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < m; ++i) {
            cin >> p[i];
        }

        solve();
    }
}

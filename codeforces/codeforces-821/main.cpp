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
pair<int, int> p[MXN];
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(p, p + n);

    int i = n - 1, j = n - 1;

    vector<pair<int, int>> ans;
    while(i >= 0) {
        if(p[j].first > a[i]) {
            ans.push_back({i, p[j].second});

            if(p[j].first + a[i] % 2 == 0) {
                a[p[j].second] = a[i];
                j--;
            } else {
                a[i] = p[j].first;
                i--;
            }
        } else {
            i--;
        }
    }

    /*
    printf("n = %d, op = %d\n", n, (int)ans.size());
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    */
    cout << ans.size() << '\n';
    for(auto [u, v]: ans) {
        u++;
        v++;
        cout << min(u, v) << ' ' << max(u, v) << '\n';
    }
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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            p[i].first = a[i];
            p[i].second = i;
        }
        solve();
    }
}

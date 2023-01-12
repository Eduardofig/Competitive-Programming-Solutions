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

int n, k;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(count_if(a, a + n, [](const int &i) { return i % 2 == 1; }) == 0) {
        cout << "NO\n";
        return;
    }

    vector<int> bds;

    int nod = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] % 2 == 1) {
            nod++;
        }

        if(nod == 2) {
            bds.push_back(i);
            nod = 1;
        }
    }
    bds.push_back(n);
    int m = bds.size();

    if(k <= m && k % 2 == m % 2) {
        cout << "YES\n";
        for(int i = m - k; i < m; ++i) {
            cout << bds[i] << ' ';
        }
        cout << '\n';
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
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}

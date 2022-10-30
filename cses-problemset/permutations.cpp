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
 
void solve()
{
    int m = n / 2;

    int l = 1, r = m + 1;

    vector<int> ans;
    while(l <= m && r <= n) {
        ans.push_back(r++);
        ans.push_back(l++);
    }

    if(r == n) {
        ans.push_back(n);
    }


    for(int i = 1; i < n; ++i) {
        if(abs(ans[i] - ans[i - 1]) == 1) {
            cout << "NO SOLUTION\n";
            return;
        }
    }

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

    cin >> n;
    solve();
}

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

int par[MXN];
 
void solve()
{
    vector<int> ans;

    int curr = n - 2;

    while(curr >= 0) {
        ans.push_back(curr + 2);
        curr = par[curr] - 2;
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

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

    for(int i = 0; i < n; ++i) {
        cin >> par[i];
    }
    solve();
}

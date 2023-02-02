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
int k;
//int a[MXN];
//int b[MXN];
//string s;
//
vector<int> mem;

void init()
{
    int curr = 2;

    mem.push_back(1);

    while(mem.back() < 2e9 + 1) {
        mem.push_back(curr++ + mem.back());
    }
    cout << mem.size() << '\n';
}
 
void solve()
{
    int where = lower_bound(mem.begin(), mem.end(), k) - mem.begin();

    string ans(n, 'a');

    ans[where + 1] = 'b';
    ans[where - (mem[where] - k)] = 'b';

    //cout << k << ' ' << mem[where] << ' ' << '\n';

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    init();
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        solve();
    }
}

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

//int k;
//int a[MXN];
//int b[MXN];
//string s;

vector<int> sums[10];

ull n, m;
 
void solve()
{
    if(m % 10 == 0) {
        cout << 0 << '\n';
        return;
    }

    for(int i = 1; i < 10; ++i) {
        int curr = i;
        while(curr % 10 != 0) {
            sums[i].push_back(curr % 10);
            curr += i;
        }
        sums[i].push_back(0);
    }

    ull times = n / m;

    ull ans = (times / sums[m % 10].size()) * accumulate(sums[m % 10].begin(), sums[m % 10].end(), 0)
        + accumulate(sums[m % 10].begin(), sums[m % 10].begin() + (times % sums[m % 10].size()), 0);

    cout << ans << '\n';
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
        solve();
    }
}

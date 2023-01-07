#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 200;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, B;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int tot[n];

    tot[0] = (a[0] % 2 == 0? 1: -1);

    for(int i = 1; i < n; ++i) {
        tot[i] = tot[i - 1] + (a[i] % 2 == 0? 1: -1);
    }
    vector<int> cost;

    for(int i = 1; i < n; ++i) {
        if(tot[i - 1] == 0) {
            cost.push_back(abs(a[i] - a[i - 1]));
        }
    }

    sort(cost.begin(), cost.end());

    int m = cost.size();
    if(m == 0) {
        cout << "0\n";
        return;
    }
    int pref[m];

    pref[0] = cost[0];
    for(int i = 1; i < m; ++i) {
        pref[i] = pref[i - 1] + cost[i];
    }

    cout << upper_bound(pref, pref + m, B) - pref << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> B;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}

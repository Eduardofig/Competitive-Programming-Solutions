#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 505;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
int grid[MXN][MXN];
ll ians[MXN]{};
ll jans[MXN]{};
bool is_prime[(int)2e5 + 1];
vector<int> p;

void init()
{
    memset(is_prime, true, sizeof is_prime);

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= (int)2e5; ++i) {
        if(is_prime[i]) {
            for(int j = i * i; j <= (int)2e5; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= (int)(2e5); ++i) {
        if(is_prime[i]) {
            p.push_back(i);
        }
    }

}
 
void solve()
{
    init();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ians[i] += *lower_bound(p.begin(), p.end(), grid[i][j]) - grid[i][j];
            jans[j] += *lower_bound(p.begin(), p.end(), grid[i][j]) - grid[i][j];
        }
    }

    ll ans = INF;

    for(int i = 0; i < n; ++i) {
        ans = min(ans, ians[i]);
    }
    for(int j = 0; j < m; ++j) {
        ans = min(ans, jans[j]);
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    solve();
}

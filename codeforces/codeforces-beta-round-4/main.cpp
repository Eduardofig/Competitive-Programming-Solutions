#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n, h, w;
pair<int, int> arr[MXN];

int dp[(int)5e3 + 3][(int)1e5 + 3];
int maxn = -INF;

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; ++i) {
        printf("{%d, %d} ", arr[i].first, arr[i].second);
    }
    cout << '\n';

    memset(dp, 0, sizeof dp);
    dp[0][arr[0].first] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= maxn; ++j) {
            if(arr[i].first > j) {
                dp[i + 1][arr[i].first] = max(dp[i + 1][arr[i].first], dp[i][j] + 1);
            }
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }

    int ans = *max_element(dp[n], dp[n] + maxn + 1);
    sort(arr, arr + n);


    cout << "First dp: \n";
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= maxn; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    memset(dp, 0, sizeof dp);
    dp[0][arr[0].second] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= maxn; ++j) {
            if(arr[i].second > j) {
                dp[i + 1][arr[i].second] = max(dp[i + 1][arr[i].second], dp[i][j] + 1);
            }
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    ans = max(*max_element(dp[n], dp[n] + maxn + 1), ans);

    for(int i = 0; i < n; ++i) {
        printf("{%d, %d} ", arr[i].first, arr[i].second);
    }
    cout << '\n';

    cout << "Second dp: \n";
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= maxn; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << ans << '\n';
}
 
int main()
{
    //ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> w >> h;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        maxn = max({maxn, arr[i].first, arr[i].second}); 
    }

    solve();
}

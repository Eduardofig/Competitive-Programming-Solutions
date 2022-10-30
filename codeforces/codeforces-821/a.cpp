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
ll a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    vector<bool> used(n + 1, false);
    vector<ll> best;
    for(int rep = 0; rep < 2; ++rep) {
        for(int i = 0 ; i < k; ++i) {
            ll mx = 0;
            int mxj = n;
            for(int j = i; j < n; j += k) {
                if(a[j] > mx && !used[j]) {
                    mx = a[j];
                    mxj = j;
                }
            }
            best.push_back(mx);
            used[mxj] = true;
        }
    }

    ll sum = accumulate(best.begin(), best.begin() + k, 0LL);
    ll ans = sum;

    for(int l = 0; l + k < best.size(); ++l) {
        int r = l + k;
        sum += best[r] - best[l];

        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

int main()
{
    //ios_base::sync_with_stdio(false);
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

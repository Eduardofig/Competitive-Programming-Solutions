#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n, m;
int cnt[MXN];

void solve()
{
    int high = (m / n + 1) * 2, low = 0;
    while(high - low > 1) {
        int mid = low + (high - low) / 2;

        int comp{}, rem{};
        for(int i = 0; i < n; ++i) {
            comp += min(cnt[i], mid);
            rem += (mid - min(cnt[i], mid)) / 2;
        }
        if(m - comp > rem) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << high << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof cnt);
        cin >> n >> m;
        for(int i = 0; i < m; ++i) {
            int num;
            cin >> num;
            cnt[num - 1]++;
        }
        solve();
    }
}

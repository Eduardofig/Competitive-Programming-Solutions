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

ll n;
ll k;
ll m;
ll a[MXN];
//ll b[MXN];
//string s;
vector<array<ll, 3>> op;
vector<array<ll, 2>> qs;
 
void solve()
{
    ll first = a[0];
    ll first2 = 0;

    ll diff[n];
    ll diff2[m];

    memset(diff2, 0, sizeof diff2);

    for(ll i = 0; i < n - 1; ++i) {
        diff[i] = a[i + 1] - a[i];
    }

    for(auto [x, y]: qs) {
        x--;
        y--;

        if(x > 0) {
            diff2[x - 1]++;
        } else {
            first2++;
        }

        diff2[y]--;
    }

    ll curr2 = first2;

    //cout << "first2 " << first2 << '\n';

    op[0][2] *= curr2;

    for(int i = 0; i < m - 1; ++i) {
        //cout << diff2[i] << ' ';
        curr2 += diff2[i];

        auto &[l, r, d] = op[i + 1];

        d *= curr2;
    }
    //cout << '\n';

    for(ll i = 0; i < m; ++i) {
        auto [l, r, d] = op[i];

        l--;
        r--;

        //cout << l << ' ' << r << ' ' << d << '\n';

        if(l > 0) {
            diff[l - 1] += d;
        } else {
            first += d;
        }

        diff[r] -= d;
    }

    ll curr = first;
    cout << first << ' ';
    for(ll i = 0; i < n - 1; ++i) {
        curr += diff[i];
        cout << curr << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    op.resize(m);
    qs.resize(k);

    for(int i = 0; i < m; ++i) {
        auto &[l, r, d] = op[i];

        cin >> l >> r >> d;
    }

    for(int i = 0; i < k; ++i) {

        auto &[x, y] = qs[i];

        cin >> x >> y;
    }

    solve();
}

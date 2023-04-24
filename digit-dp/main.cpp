#include <bits/stdc++.h>

#define For(i, n) for(int i = 0; i < (int)(n); ++i)
#define Foro(i, n) for(int i = 1; i < (int)(n); ++i)
#define Forr(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define Forl(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define Fore(v, ...) for(auto &[__VA_ARGS__]: (v))
#define All(x) (x).begin(), (x).end()
#define Mini(x, y) (x) = min((x), (y))
#define Maxi(x, y) (x) = max((x), (y))
#define Pb push_back
#define Eb emplace_back
#define Lb(x, y) lower_bound(x, (y))
#define Ub(x, y) upper_bound(x, (y))
#define Rz(x, y) resize((x), (y))
#define Read(x) generate(All((x)), nxt)
#define Pr(x) cout << (x) << ' '
#define Prn(x) cout << (x) << '\n'

// #define int ll

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vvvi = vector<vvi>;
using vvvii = vector<vvii>;

const int MXN = 1e4 + 100;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
// vi a(MXN);
// vi b(MXN);
// vi v(MXN);
// vvi g(MXN, vi());
// string s;
string l, r;
int x;

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

void solve()
{
    // r.Rz(MXN, 0);
    // l.Rz(MXN, 0);

    n = r.size();

    vvvi dp(MXN, vvi(2, vi(MXN, 0)));
    vvvi dp2(MXN, vvi(2, vi(MXN, 0)));

    fill(All(dp[0]), vi(MXN, 1));
    fill(All(dp2[0]), vi(MXN, 1));

    For(i, n) {
        For(tight, 2) {
            For(sum, x) {
                For(d, tight) {
                    if(sum + d <= x) {
                        Prn("here");
                        dp[i + 1][tight && (d == r[i + 1] - 'a')][sum + d] += dp[i][tight][sum];

                        if(d < l[i + 1] - 'a' || !tight) {
                            dp2[i + 1][tight && (d == l[i + 1] - 'a')][sum + d] += dp2[i][tight][sum];
                        }
                    }

                }
            }
        }
    }

    ll ans = 0;
    For(i, n) {
        For(tight, 2) {
            ans += dp[i][tight][x];
            ans -= dp2[i][tight][x];
        }
    }

    Prn(ans);

}


void read()
{
    cin >> l >> r >> x;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}

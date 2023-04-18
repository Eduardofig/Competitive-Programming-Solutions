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
 
const int MXN = 5e5 + 100;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
int a, b, c;
// vi a(MXN);
// vi b(MXN);
// vi v(MXN);
// vvi g(MXN, vi());
// string s;

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

void solve()
{
    int weeks = min({a / 3, b / 2, c / 2});

    int ans = weeks * 7;

    vi left = {a - weeks * 3, b - weeks * 2, c - weeks * 2};
    map<int, int> mp = {
        {0, 0},
        {3, 0},
        {6, 0},
        {1, 1},
        {5, 1},
        {2, 2},
        {4, 2},
    };

    int best = 0, curr = 0;
    For(i, 7) {
        curr = 0;
        vi tmp(All(left));
        For(j, 7) {
            if(tmp[mp[(i + j) % 7]] > 0) {
                tmp[mp[(i + j) % 7]]--;
                curr++;
            } else {
                break;
            }
        }
        Maxi(best, curr);
    }

    ans += best;

    Prn(ans);
}

void read()
{
    cin >> a >> b >> c;
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

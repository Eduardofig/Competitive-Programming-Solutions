#include <bits/stdc++.h>

#define For(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define Foro(i, n) for(int (i) = 1; (i) < (int)(n); ++(i))
#define Forr(i, n) for(int (i) = (int)(n) - 1; (i) >= 0; --(i))
#define Forl(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
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

const int MXN = 5e5 + 100;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int c, r;
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
    if(r == c and c == 1) {
        Prn(0);
        return;
    }

    vvi ans(r, vi(c, 1));
    int curr = 1;

    if(r == 1) {
        curr++;
        For(i, c) {
            Pr(curr++);
        }
        Prn("");

        return;
    }

    if(c == 1) {
        curr++;
        For(j, r) {
            Prn(curr++);
        }

        return;
    }



    For(i, r) {
        For(j, c) {
            ans[i][j] *= curr;
        }
        curr++;
    }

    For(j, c) {
        For(i, r) {
            ans[i][j] *= curr;
        }
        curr++;
    }

    For(i, r) {
        For(j, c) {
            Pr(ans[i][j]);
        }
        Prn("");
    }

}

void read()
{
    cin >> r >> c;
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

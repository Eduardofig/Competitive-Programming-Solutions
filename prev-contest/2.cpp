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
#define Rz(x) resize((x))
#define Rzz(x, y) resize((x), (y))
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

int n, m, k;
vi l, r;
map<int, int> diff;
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
	int first = 0;
	for(int i = 0; i < n; ++i) {
		if(r[i] - l[i] + 1 >= k) {
			diff[0]++;
		} else {
			r[i] %= k;
			l[i] %= k;
			if(r[i] >= l[i]) {
				diff[r[i] + 1]--;
				diff[l[i]]++;
			} else {
				diff[0]++;
				diff[r[i] + 1]--;
				diff[l[i]]++;
			}
		} 
	}

	int curr = first;
	int ans = curr;
	for(auto [day, val]: diff) {
		curr += val;
		Maxi(ans, curr);
	}

	cout << ans << '\n';
}

void read()
{
	 cin >> n >> k;
	 l.Rz(n);
	 r.Rz(n);
	 for(int i = 0; i < n; ++i) {
		  cin >> l[i] >> r[i];
		  l[i]--;
		  r[i]--;
	 }
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

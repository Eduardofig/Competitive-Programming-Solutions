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
ll k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int mx[n];

    mx[0] = a[0];
    for(int i = 1; i < n; ++i) {
        mx[i] = max(a[i], mx[i - 1]);
    }

    for(int i = 0; i < n; ++i) {
        bool ok = true;
        for(int j = 1; j <= (int)min(k, (ll)n); ++j) {
            ok = ok && a[(i + j) % n] <= a[i];
        }
        if(ok) {
            cout << a[i] << '\n';
            return;
        }

        if(i > 0) {
            bool ok = a[i] > mx[i - 1];

            for(int j = 1; j <= (int)min(k - 1, (ll)n); ++j) {
                ok = ok && a[(i + j) % n] <= a[i];
            }
            if(ok) {
                cout << a[i] << '\n';
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();

}

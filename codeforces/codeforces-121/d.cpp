#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n, k;
ll b;
int a[MXN];
set<int> has;
 
void solve()
{
    vector<int> copy(a, a + n - 1);
    sort(copy.rbegin(), copy.rend());
    ll sum = 0;
    for(int i = 0; i < k - 1; ++i) {
        sum += copy[i];
        has.insert(copy[i]);
    }

    for(int i = 0; i < n - 1; ++i) {
        bool check = has.find(a[i]) != has.end();
        if(check) {
            sum -= a[i];
            sum += copy[k - 1];
        }

        if(b - sum < a[i]) {
            cout << i + 1 << '\n';
            return;
        }

        if(check) {
            sum -= copy[k - 1];
            sum += a[i];
        }
    }
    cout << n << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> b;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}

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
//int k;
int a[MXN];
//int b[MXN];
//string s;

void solve()
{
    set<int> se;
    for(int i = 0; i < n; ++i) {
        while(a[i] % 2 == 0) {
            a[i] /= 2;
        }
        while(a[i] % 3 == 0) {
            a[i] /= 3;
        }

        se.insert(a[i]);
    }


    cout << (se.size() == 1? "YES\n": "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}

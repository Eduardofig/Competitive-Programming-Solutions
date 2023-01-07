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
 
void solve()
{

    int best = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 0) {
            best++;
        } else {
            best--;
        }
    }

    for(int i = 0; i < n; ++i) {
        int curr = 0;
        for(int j = i; j < n; ++j) {
            if(a[j] == 0) {
                curr++;
            } else {
                curr--;
            }
            best = max(curr, best);
        }
    }

    cout << count(a, a + n, 1) + best << '\n';
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

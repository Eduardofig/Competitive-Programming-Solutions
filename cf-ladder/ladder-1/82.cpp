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

int n, k;
//int k;
//int a[MXN];
//int b[MXN];
string s;
 
void solve()
{
    sort(s.begin(), s.end());

    int curr = -3;
    int ans = 0;
    int nk = 0;

    for(char c: s) {
        if(nk < k) {
            int num = c - 'a';

            if(num >= curr + 2) {
                ans += num + 1;
                curr = num;
                nk++;
            }
        }
    }

    cout << (nk < k? -1: ans) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    cin >> s; 
    solve();
}

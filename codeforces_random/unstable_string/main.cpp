#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
string s;
//int arr[MXN];
 
void solve()
{
    int n = s.size();
    int ans = 0, cnt = 0, q = 0;
    char prev = 0;
    bool check = false;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '?') {
            check = true;
            if(q == 0 && i > 0) {
                prev = s[i - 1];
            }
            q++;
            cnt++;
        } else {
            if(q == 0) {
                if(i > 0 && s[i] == s[i - 1]) {
                    if(check) {
                        ans += cnt * (cnt + 1) / 2;
                    }
                    cnt = 1;
                    check = false;
                } else {
                    cnt++;
                }
            } else {
                // q is even then s[i] != prev
                if(q % 2 == 0) {
                    if(s[i] == prev && prev != 0) {
                        ans += cnt * (cnt + 1) / 2;
                        cnt = q + 1;
                    } else {
                        cnt++;
                    }
                } else {
                    if(s[i] != prev && prev != 0) {
                        ans += cnt * (cnt + 1) / 2;
                        cnt = q + 1;
                    } else {
                        cnt++;
                    }
                }
                q = 0;
            }
        }
    }

    if(check) {
        ans += cnt * (cnt + 1) / 2;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        solve();
    }
}

#include <bits/stdc++.h>

using namespace std;

string s;
int k, n;

void solve()
{
    int ans = 10 * (s.front() == '1') + 1 * (s.back() == '1');
    for(int i = 1; i < n - 1; ++i) {
        ans += 11 * (s[i] == '1');
    }

    if(s.back() == '0') {
        int i = n - 1;
        while(i >= 0 && s[i] != '1') {
            i--;
        }
        int diff = n - i - 1;

        if(i > 0 && k >= diff) {
            swap(s[i], s.back());
            k -= diff;
            ans -= 10;
        }
    }

    if(s.front() == '0') {
        int i = 1;
        while(i < n - 1 && s[i] != '1') {
            i++;
        }

        if(i < n - 1 && k >= i) {
            ans -= 1;
        }
    }

    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> k >> s;
        solve();
    }
}

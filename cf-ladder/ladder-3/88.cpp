#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

int n;
//int a[MXN];
//int b[MXN];
string s;

void solve()
{
    vector<pair<string, int>> ans;
    for(int k = 1; k <= n; ++k) {
        string tmp = "";

        for(int i = k - 1; i < n; i++) {
            tmp.push_back(s[i]);
        }

        if((n - k + 1) % 2 == 1) {
            for(int i = k - 2; i >= 0; --i) {
                tmp.push_back(s[i]);
            }
        } else {
            for(int i = 0; i < k - 1; ++i) {
                tmp.push_back(s[i]);
            }
        }

        ans.emplace_back(tmp, k);
    }


    auto it = min_element(ans.begin(), ans.end());

    cout << it->first << '\n' << it->second << '\n';
}

void read()
{
    cin >> n >> s;
}

int main()
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

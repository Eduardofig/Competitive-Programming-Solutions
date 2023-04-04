#include <bits/stdc++.h>
#include <numeric>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int k;
//int a[MXN];
//int b[MXN];
//string s;
vector<int> a[MXN];
map<int, pair<int, int>> found;

void solve()
{
    for(int i = 0; i < k; i++) {
        int tot = accumulate(a[i].begin(), a[i].end(), 0);
        set<int> used;

        for(int j = 0; j < a[i].size(); j++) {
            if(used.find(a[i][j]) == used.end()) {

                used.insert(a[i][j]);

                int curr = tot - a[i][j];
                if(found.find(curr) != found.end()) {
                    cout << "YES\n";
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    cout << found[curr].first << ' ' << found[curr].second << '\n';
                    return;
                } else {
                    found.insert({curr, {i + 1, j + 1}});
                }
            }
        }
    }

    cout << "NO\n";
}

void read()
{
    cin >> k;

    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        a[i].resize(n);

        for(int &num: a[i]) {
            cin >> num;
        }
    }
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

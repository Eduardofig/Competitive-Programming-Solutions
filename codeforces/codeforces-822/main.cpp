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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    vector<int> left, right;

    int curr = 0;
    for(int i = k; i < n; ++i) {
        if(curr == 0) {
            curr = a[i];
        } else {
            if(curr < 0) {
                if(a[i] > 0) {
                    right.push_back(curr);
                    curr = a[i];
                } else {
                    curr += a[i];
                }
            } else if(curr > 0) {
                if(a[i] < 0) {
                    right.push_back(curr);
                    curr = a[i];
                } else {
                    curr += a[i];
                }
            }
        }
    }
    if(curr != 0) {
        right.push_back(curr);
    }
    curr = 0;
    for(int i = k - 2; i >= 0; --i) {
        if(curr == 0) {
            curr = a[i];
        } else {
            if(curr < 0) {
                if(a[i] > 0) {
                    left.push_back(curr);
                    curr = a[i];
                } else {
                    curr += a[i];
                }
            } else if(curr > 0) {
                if(a[i] < 0) {
                    left.push_back(curr);
                    curr = a[i];
                } else {
                    curr += a[i];
                }
            }
        }
    }
    if(curr != 0) {
        left.push_back(curr);
    }

    int rp = 0, lp = 0;

    int rn = right.size();
    int ln = left.size();

    curr = a[k - 1];
    while(rp < rn && lp < ln) {
        while(curr + left[lp] >= 0) {
            curr += left[lp++];
            if(rp == rn || lp == ln) {
                cout << "yes\n";
                return;
            }
        }

        while(curr + right[rp] >= 0) {
            curr += right[rp++];
            if(rp == rn || lp == ln) {
                cout << "yes\n";
                return;
            }
        }

        if(curr + right[rp] < 0 && curr + left[lp] < 0) {
            cout << "no\n";
            return;
        }
    }


    cout << "yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}

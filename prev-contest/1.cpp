#include <bits/stdc++.h>

#define All(x) (x).begin(), (x).end()

using namespace std;

const int MXN = 2e5 + 300;
const int INF = INT_MAX;

#define int long long

vector<int> w;
int n;

int32_t main()
{
    cin >> n;
    w.resize(n);

    for(int &i: w) {
        cin >> i;
    }

    int tot = accumulate(All(w), 0);
    //cout << tot << '\n';

    set<pair<int, int>> mx, mn;

    for(int i = 0; i < n; ++i) {
        mx.insert({-w[i], i});
        mn.insert({w[i], i});
    }

    vector<int> left(n), right(n);

    for(int i = 0; i < n; ++i) {
        left[i] = i - 1;
        right[i] = i + 1;
    }

    for(int i = 0; i < n - 1; ++i) {
        int best = -(mx.begin()->first);

        int val, idx;

        //cout << "DBG " << tot << ' ' << best << '\n';

        if(best > tot - best) {
            val = mn.begin()->first;
            idx = mn.begin()->second;
        } else {
            val = best;
            idx = mx.begin()->second;
        }

        cout << idx + 1 << ' ' << val << '\n';

        tot -= val;

        if(left[idx] >= 0) {
            mn.erase({w[left[idx]], left[idx]});
            mx.erase({-w[left[idx]], left[idx]});

            w[left[idx]] += val / 2;
            tot += val / 2;

            mn.insert({w[left[idx]], left[idx]});
            mx.insert({-w[left[idx]], left[idx]});

            right[left[idx]] = right[idx];
        }

        if(right[idx] < n) {
            mn.erase({w[right[idx]], right[idx]});
            mx.erase({-w[right[idx]], right[idx]});

            w[right[idx]] += val / 2;
            tot += val / 2;

            mn.insert({w[right[idx]], right[idx]});
            mx.insert({-w[right[idx]], right[idx]});

            left[right[idx]] = left[idx];
        }

        // if(idx == 0) {
        //     cout << "dbg left\n";
        //     cout << left[right[idx]] << '\n';
        // }

        mn.erase({val, idx});
        mx.erase({-val, idx});

        w[idx] = 0;

        // cout << "dbg mx\n";
        // for(auto [val, idx]: mx) {
        //     cout << val << ' ' << idx << '\n';
        // }
        //
        // cout << "dbg mn\n";
        // for(auto [val, idx]: mn) {
        //     cout << val << ' ' << idx << '\n';
        // }
    }

    cout << mx.begin()->second + 1 << ' ' << -(mx.begin()->first) << '\n';

}

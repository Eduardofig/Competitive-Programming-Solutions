#include <bits/stdc++.h>

using namespace std;

const int MXN = 4e8;

int main()
{
    int n, m, toy;
    cin >> n >> m;

    unordered_set<int> has;

    for(int i = 0; i < n; ++i) {
        cin >> toy;
        has.insert(toy);
    }

    int ans = 0;

    vector<int> purchases;

    for(int i = 1; i < MXN; ++i) {
        if(m < i) {
            break;
        } else if(has.find(i) == has.end()) {
            m -= i;
            purchases.push_back(i);
            ans++;
        }
    }

    cout << ans << endl;
    for(int new_toy: purchases) {
        cout << new_toy << " ";
    }
    cout << endl;
}

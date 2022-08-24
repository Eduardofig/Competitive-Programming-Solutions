#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vectors(n, vector<int>(3));
    for(auto &v: vectors) {
        cin >> v[0] >> v[1] >> v[2];
    }

    vector<int> sum = {0, 0, 0};
    for(auto v: vectors) {
        for(int i = 0; i < 3; ++i) {
            sum[i] += v[i];
        }
    }

    cout << (sum[0] == 0 && sum[1] == 0 && sum[2] == 0? "YES\n": "NO\n");
}

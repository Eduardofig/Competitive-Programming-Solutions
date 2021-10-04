#include <bits/stdc++.h>

using namespace std;

const int MXN = 400;

int main()
{
    long long int forbidden[MXN];

    int n, m, ing1, ing2;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        cin >> ing1 >> ing2;
        forbidden[i] = (1 << --ing1) | (1 << --ing2);
    }

    int count = 0;
    bool flag;

    for(int mask = 0; mask < (1 << n); ++mask) {
        flag = false;

        for(int i = 0; i < m; ++i)
            if(__builtin_popcount(forbidden[i] & mask) == 2) flag = true;

        if(!flag) count++;
    }

    cout << count - 1 << endl;
}

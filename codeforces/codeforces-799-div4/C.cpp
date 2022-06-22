#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

char mat[8][8];

void solve()
{
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            cin >> mat[i][j];
        }
    }

    ll diri[4] = {-1, 1, 1, -1};
    ll dirj[4] = {-1, 1, -1, 1};

    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(mat[i][j] == '#') {
                bool diag1 = false, diag2 = false;
                for(int k = 0; k < 2; ++k) {
                    if(i + diri[k] >= 0 && i + diri[k] < 8 && j + dirj[k] >= 0 && j + dirj[k] < 8) {
                        if(mat[i + diri[k]][j + dirj[k]] == '#') {
                            diag1 = true;
                        }
                    }
                }
                for(int k = 2; k < 4; ++k) {
                    if(i + diri[k] >= 0 && i + diri[k] < 8 && j + dirj[k] >= 0 && j + dirj[k] < 8) {
                        if(mat[i + diri[k]][j + dirj[k]] == '#') {
                            diag2 = true;
                        }
                    }
                }
                if(diag1 && diag2) {
                    cout << i + 1 << " " << j + 1 << '\n';
                    return;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}

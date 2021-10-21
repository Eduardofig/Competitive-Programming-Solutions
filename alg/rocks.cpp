#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6;
int dp[2][MXN], moves[10], n, m;

#define OLLIE_WIN 1
#define STAN_WIN 0
#define OLLIE_TURN 0
#define STAN_TURN 1
#define NOT_VISITED -1

string winner[2] = {"Stan", "Ollie"};

void solve()
{
    memset(dp, NOT_VISITED, sizeof dp);

    dp[STAN_TURN][0] = OLLIE_WIN;
    dp[OLLIE_TURN][0] = STAN_WIN;

    for(int i = 0; i <= n; ++i) 
        for(int turn = 0; turn <= 1; ++turn)
            if(dp[turn][i] != NOT_VISITED)
                for(int j = 0; j < m; ++j)
                    if(moves[j] + i <= n && dp[!turn][i + moves[j]] != turn)
                        dp[!turn][i + moves[j]] = dp[turn][i];

    cout << winner[dp[STAN_TURN][n]] << " wins" << endl;

}

int main()
{
    while(cin >> n) {
        cin >> m;
        for(int i = 0; i < m; ++i)
            cin >> moves[i];

        solve();
    }
}

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int curr[4], target[4], ans = INF;

void solve_rec(vector<int[4]> &confs, int pos, int moves)
{
    bool eq = true;

    for(int i = 0; i < 4; ++i) {
        eq &= curr[i] == target[i];
        if(eq) {
            ans = min(ans, moves);
            return;
        }
    }

    curr[pos]++;

    //checa se ele nao bate com nenhuma conf proibida
    for(int *conf: confs) {
        eq = true;
        for(int i = 0; i < 4; ++i) {
            eq &= curr[i] == conf[i];
        }
    }

    //chama recursiva no prox digito e no mesmo digito
    if(eq) {
        if(curr[pos] != 9) solve_rec(confs, pos + 1, moves + 1);
        if(pos != 3) solve_rec(confs, pos, moves + 1);
    }

    curr[pos]--;
}

int main()
{

}

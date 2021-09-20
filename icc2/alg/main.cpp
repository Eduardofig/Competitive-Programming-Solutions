#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;
int confs[mxN][4], n, start[4], forbidden[4];
int final_ans = 0x3f3f3f3f, curr_conf;

void solve_rec(int pos, int ans)
{
    if(pos == 4) {
        final_ans = min(final_ans, ans);
        return;
    }

    if(start[pos] == confs[curr_conf][pos]) pos++;

    start[pos]++;
    solve_rec(pos, ans + 1);

    start[pos] -= 2;
    solve_rec(pos, ans + 1);

    start[pos]++;
}

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


}

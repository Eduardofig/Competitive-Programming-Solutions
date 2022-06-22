#include <bits/stdc++.h>

using namespace std;

enum direction { up_e, left_e, down_e, right_e };

direction get_dir(pair<int, int> p1, pair<int, int> p2) {
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;

    int delta_x = x2 - x1, delta_y = y2 - y1;

    if (delta_x > 0) {
        return right_e;
    } else if (delta_x < 0) {
        return left_e;
    } else if (delta_y > 0) {
        return up_e;
    } else {
        return down_e;
    }
}

string print_dir(direction dir)
{
    switch(dir) {
        case right_e:
            return "right";
            break;
        case left_e:
            return "left";
            break;
        case up_e:
            return "up";
            break;
        default:
            return "down";
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> points[n];
    int biggest_x = -0x3f3f3f3f;
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        biggest_x = max(biggest_x, points[i].first);
    }

    int ans = 0;
    direction prev_dir = get_dir(points[0], points[1]);
    for(int i = 2; i < n; ++i) {
        direction curr_dir = get_dir(points[i - 1], points[i]);

        //cout << "curr_dir: " << print_dir(curr_dir) << " prev_dir: " << print_dir(prev_dir) << endl;

        if(curr_dir == (prev_dir + 1) % 4) {
            ans++;
        }

        prev_dir = curr_dir;
    }

    cout << ans << endl;
}

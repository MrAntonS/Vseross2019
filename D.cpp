#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, sx, sy, fx, fy;
    cin >> n >> m;
    sx = 0;
    sy = 0;
    fx = abs(n);
    fy = abs(m);
    int n1 = max(abs(n) + 1, abs(m) + 1);
    int absn = abs(n);
    int absm = abs(m);
    pair<int, int> a = make_pair(sx, sy), b = make_pair(fx, fy);
    vector<vector<int>> d(n1, vector<int> (n1, -1));
    vector<vector<pair<int, int>>> p(n1, vector<pair<int, int>> (n1, {0,0}));
    queue<pair<int, int>> k;
    k.push(a);
    for (int i = 0; i < n1 * n1; i++) {
        pair<int, int> o = k.front();
        k.pop();
        if (o.first + 2 < n1 && o.second + 1 < n1 && d[o.first + 2][o.second + 1] == -1) {
            k.push(make_pair(o.first + 2, o.second + 1));
            d[o.first + 2][o.second + 1] = d[o.first][o.second] + 1;
            p[o.first + 2][o.second + 1] = o;
        }
        if (o.first + 1 < n1 && o.second + 2 < n1 && d[o.first + 1][o.second + 2] == -1) {
            k.push(make_pair(o.first + 1, o.second + 2));
            d[o.first + 1][o.second + 2] = d[o.first][o.second] + 1;
            p[o.first + 1][o.second + 2] = o;
        }
        if (o.first - 2 >= 0 && o.second - 1 >= 0 && d[o.first - 2][o.second - 1] == -1) {
            k.push(make_pair(o.first - 2, o.second - 1));
            d[o.first - 2][o.second - 1] = d[o.first][o.second] + 1;
            p[o.first - 2][o.second - 1] = o;
        }
        if (o.first - 1 >= 0 && o.second - 2 >= 0 && d[o.first - 1][o.second - 2] == -1) {
            k.push(make_pair(o.first - 1, o.second - 2));
            d[o.first - 1][o.second - 2] = d[o.first][o.second] + 1;
            p[o.first - 1][o.second - 2] = o;
        }
        if (o.first + 2 < n1 && o.second - 1 >= 0 && d[o.first + 2][o.second - 1] == -1) {
            k.push(make_pair(o.first + 2, o.second - 1));
            d[o.first + 2][o.second - 1] = d[o.first][o.second] + 1;
            p[o.first + 2][o.second - 1] = o;
        }
        if (o.first + 1 < n1 && o.second - 2 >= 0 && d[o.first + 1][o.second - 2] == -1) {
            k.push(make_pair(o.first + 1, o.second - 2));
            d[o.first + 1][o.second - 2] = d[o.first][o.second] + 1;
            p[o.first + 1][o.second - 2] = o;
        }
        if (o.first - 2 >= 0 && o.second + 1 < n1 && d[o.first - 2][o.second + 1] == -1) {
            k.push(make_pair(o.first - 2, o.second + 1));
            d[o.first - 2][o.second + 1] = d[o.first][o.second] + 1;
            p[o.first - 2][o.second + 1] = o;
        }
        if (o.first - 1 >= 0 && o.second + 2 < n1 && d[o.first - 1][o.second + 2] == -1) {
            k.push(make_pair(o.first - 1, o.second + 2));
            d[o.first - 1][o.second + 2] = d[o.first][o.second] + 1;
            p[o.first - 1][o.second + 2] = o;
        }
    }

    int ax = fx;
    int by = fy;
    vector<pair<int, int>> g;
    while (ax != sx or by != sy) {
        pair<int, int> h = p[ax][by];
        g.push_back({(ax) * (absn / n), (by) * (absm / m)});
        ax = h.first;
        by = h.second;
    }
    g.push_back({sx, sy});
    reverse(g.begin(), g.end());
    for (auto i : g) {
        cout << i.first << ' ' << i.second << '\n';
    }
}


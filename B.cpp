#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    int r = min(n, m) / 2, l = 0;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (n * m - (n - 2 * mid) * (m - 2 * mid) <= t) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}

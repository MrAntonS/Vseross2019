#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << max(((a + 1) * (n - 1) + 1), ((b + 1) * (m - 1) + 1)) << ' ' << min(((a + 1) * (n - 1) + 1 + a + a), ((b + 1) * (m - 1) + 1 + b + b));
}

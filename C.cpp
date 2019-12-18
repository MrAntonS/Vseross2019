#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int max = 0;
    int i1 = 0;
    for (int i = 0; i < n; i++) {
        if (max < a[i] * (n - i)) {
            max = a[i] * (n - i);
            i1 = n - i;
        }
    }
    cout << i1 << ' ' << max / i1;
}

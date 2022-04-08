#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &bit, int n, int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int read(vector<int> &bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q, type, k, p;
    cin >> n >> q;
    vector<int> bit(n + 1);
    vector<int> frequency(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p;
        frequency[i] = p;
        update(bit, n, i, p);
    }
    for (int i = 0; i < q; i++) {
        cin >> type >> k;
        if (type == 0) {
            cin >> p;
            update(bit, n, k, -frequency[k] + p);
            frequency[k] = p;
        } else {
            cout << read(bit, k) << "\n";
        }
    }
    return 0;
}

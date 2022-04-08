#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;

int G[MAXN], S[MAXN], groups;

int find(int a) {
    while (a != G[a]) {
        a = G[a];
        G[a] = G[G[a]];
    }
    return a;
}

bool unify(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (S[a] > S[b]) {
        G[b] = a;
        S[a] += S[b];
    } else {
        G[a] = b;
        S[b] += S[a];
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    groups = n;
    for (int i = 0; i < n; i++) {
        G[i] = i, S[i] = 1;
    }
    while (m--) {
        cin >> a >> b;
        if (unify(a, b)) groups--;
    }
    cout << groups << "\n";
    return 0;
}

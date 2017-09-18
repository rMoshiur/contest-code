#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, v[10] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int greedy(int x, int c[10]) {
    int cnt = 0;
    for (int i = 9; i >= 0; i--) {
        int t = (v[i] == 50 || v[i] == 500) ? 2 * min(c[i] / 2, (x / (2 * v[i]))) : min(c[i], x / v[i]);
        cnt += t;
        x -= t * v[i];
    }
    return x == 0 ? cnt : INF;
}
int main() {
    int t, p, c[10], s;
    scanf("%d", &t);
    assert(1 <= t && t <= 200000);
    while (t--) {
        scanf("%d", &p);
        assert(0 <= p && p <= 1000000000);
        for (int i = 0; i < 10; i++) scanf("%d", c + i);
        for (int i = 0; i < 10; i++) assert(0 <= c[i] && c[i] <= 100000);
        for (int i = s = 0; i < 10; i++) s += c[i] * v[i];
        int mi = INF;
        for (int i = 0; i <= min(1, c[4]); i++)
            for (int j = 0; j <= min(1, c[7]); j++) {
                int x = s - p - i * 50 - j * 500;
                if (x < 0) continue;
                c[4] -= i;
                c[7] -= j;
                mi = min(mi, greedy(x, c) + i + j);
                c[4] += i;
                c[7] += j;
            }
        printf("%d\n", mi == INF ? -1 : accumulate(c, c + 10, 0) - mi);
    }
    return 0;
}

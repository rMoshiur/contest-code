#include <bits/stdc++.h>

using namespace std;

int data[1005];

bool cmp(const int& x, const int& y) {
    return x < y;
}

int bSearch(int index, int st, int ed) {
    if ((data[st]&(1<<index)) != 0) return -1;
    int now = st;
    int step = ed-st;
    while (step) {
        if (now+step <= ed && ((data[now+step]&(1<<index)) == 0)) now += step;
        else step >>= 1;
    }
    return now;
}

int solve(int target, int x, int y, int st, int ed) {
    //cerr << "target: " << target << " " << x << " " << y << endl;
    for (int i = 30; i >= 0; --i) {
        int size = ed-st+1;
        if (x <= ed && x >= st) --size;
        if (y <= ed && y >= st) --size;
        if (size == 1) {
            for (int j = st; j <= ed; ++j) {
                if (j != x && j != y) return j;
            }
        }

        int stop = bSearch(i, st, ed);
        
        if (stop == -1) continue;

        if ((target&(1<<i)) == 0) {
            size = stop-st+1;

            if (x <= stop && x >= st) --size;
            if (y <= stop && y >= st) --size;
            //cerr << "size: " << size << endl;
            if (size <= 0) {
                st = stop+1;
            }
            else {
                ed = stop;
            }
        }

        else {
            size = ed-stop;

            if (x <= ed && x > stop) --size;
            if (y <= ed && y > stop) --size;
            //cerr << "size: " << size << endl;
            if (size <= 0) {
                ed = stop;
            }
            else {
                st = stop+1;
            }
        }
    }

    int size = ed-st+1;
    for (int i = ed; i >= st; --i) {
        if (i == x || i == y) continue;
        return i;
    }
    return -1;
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &data[i]);
        }
        sort(data, data+n, cmp);

        int ans = 0;
        
        for (int x = 0; x < n; ++x) {
            for (int y = x+1; y < n; ++y) {
                int target = (0x7fffffff ^(data[x]+data[y]));
                int chosen = solve(target, x, y, 0, n-1);
                //cerr << x << " " << y << " " << chosen << endl;
                ans = max(ans, ((data[x]+data[y])^data[chosen]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

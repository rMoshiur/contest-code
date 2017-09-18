#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

typedef double T;

class POS {
public:
    T x, y;
    POS(const T& x = 0, const T& y = 0) : x(x), y(y) {}
    POS(const POS& x) : x(x.x), y(x.y) {}

    bool operator==(const POS& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    POS& operator+=(const POS& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    POS operator -() {
        POS tmp(-x, -y);
        return tmp;
    }

    double dist(const POS& rhs) const {
        T tmp_x = x-rhs.x, tmp_y = y-rhs.y;
        return sqrt(tmp_x*tmp_x+tmp_y*tmp_y);
    }

    friend ostream& operator<<(ostream& out, const POS& pos) {
        out << pos.x << " " << pos.y;
        return out;
    }
};

POS input[105];
POS output[105];

bool cmp(const POS& lhs, const POS& rhs) {
    return (lhs.x < rhs.x) || ( (lhs.x == rhs.x)&&(lhs.y < rhs.y) );
}


T cross(POS& o, POS& a, POS& b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

void convex_hull(POS* points, POS* need, int n, int& number) {
    sort(points, points+n, cmp);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        while (index >= 2 && cross(need[index-2], need[index-1], points[i]) <= 0) index--;
        need[index++] = points[i];
    }
    int half_point = index+1;
    for (int i = n-2; i >= 0; --i) {
        while (index >= half_point && cross(need[index-2], need[index-1], points[i]) <= 0) index--;
        need[index++] = points[i];
    } /* be careful that start point will appear in fisrt and last in need array */
    number = index;
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            input[i] = POS(x, y);
        }
        int number;
        convex_hull(input, output, n, number);
        if (number-1 != n) {
            printf("NO\n");
            continue;
        }
        bool has_ans = false;
        double dist = output[0].dist(output[1]);
        for (int i = 1; i < number-1; ++i) {
            if (fabs(output[i].dist(output[i+1])-dist) > EPS) {
                printf("NO\n");
                has_ans = true;
                break;
            }
        }
        if (has_ans) continue;
        printf("YES\n");
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int input[100005];

int main () {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int number;
        scanf("%d", &number);
        for (int i = 0; i < number; ++i) {
            scanf("%d", &input[i]);
        }
        int front_as = -1, front_ds = -1, end_as = -1, end_ds = -1;
        bool get_as = false, get_ds = false;
        for (int i = 1; i < number; ++i) {
            if (!get_as && input[i] < input[i-1]) {
                get_as = true;
                front_as = i;
            }
            if (!get_ds && input[i] > input[i-1]) {
                get_ds = true;
                front_ds = i;
            }
            if (get_as && get_ds) break;
        }

        get_as = get_ds = false;
        for (int i = number-2; i >= 0; --i) {
            if (!get_as && input[i] < input[i+1]) {
                get_as = true;
                end_as = i;
            }
            if (!get_ds && input[i] > input[i+1]) {
                get_ds = true;
                end_ds = i;
            }
            if (get_as && get_ds) break;
        }

        if ( ((front_as == -1) && (end_ds == -1)) || ((front_ds == -1) && (end_as == -1)) ) {
            printf("YES\n");
            continue;
        }

        bool has_ans = false;
        if ( front_as >= end_ds ) {
            for (int i = end_ds; i <= front_as; ++i) {
                if (i+1==number || i==0) {
                    printf("YES\n");
                    has_ans = true;
                    break;
                }
                else {
                    if (input[i-1] <= input[i+1]) {
                        printf("YES\n");
                        has_ans = true;
                        break;
                    }
                }
            }
        }
        if (has_ans) continue;
        if ( front_ds >= end_as ) {
            for (int i = end_as; i <= front_ds; ++i) {
                if (i+1==number || i==0) {
                    printf("YES\n");
                    has_ans = true;
                    break;
                }
                else {
                    if (input[i-1] >= input[i+1]) {
                        printf("YES\n");
                        has_ans = true;
                        break;
                    }
                }
            }
        }
        if (has_ans) continue;
        printf("NO\n");
    }
    return 0;
}

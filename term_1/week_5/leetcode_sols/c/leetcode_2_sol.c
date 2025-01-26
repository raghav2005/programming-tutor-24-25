#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

// version 1
int maxArea(int* height, int heightSize) {
    int ans = 0, l = 0, r = heightSize - 1, dist;

    while (l < r) {
        dist = r - l;
        if (*(height + l) >= *(height + r)) {
            ans = MAX(ans, *(height + r) * dist);
            r--;
        } else {
            ans = MAX(ans, *(height + l) * dist);
            l++;
        }
    }

    return ans;
}

// version 2
int maxArea2(int* height, int heightSize) {
    int ans = 0, l = 0, r = heightSize - 1, dist, new_ans;

    while (l < r) {
        dist = r - l;
        if (*(height + l) >= *(height + r)) {
            new_ans = *(height + r--) * dist;
            ans = (new_ans > ans) ? new_ans : ans;
        } else {
            new_ans = *(height + l++) * dist;
            ans = (new_ans > ans) ? new_ans : ans;
        }
    }

    return ans;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(*height);

    int ans = maxArea(height, heightSize);

    printf("%d\n", ans);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

double dis(double x1, double y1, double x2, double y2) {
    double ret = sqrt(pow(x2 - x1, 2) + pow(y1 - y2, 2));
    return ret;
}

int main() {
    double xy[3][2];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> xy[i][j];
        }
    }
    double c = 0;
    c += dis(xy[0][0], xy[0][1], xy[1][0], xy[1][1]);
    c += dis(xy[1][0], xy[1][1], xy[2][0], xy[2][1]);
    c += dis(xy[2][0], xy[2][1], xy[0][0], xy[0][1]);

    printf("%.2f", c);

    return 0;
}
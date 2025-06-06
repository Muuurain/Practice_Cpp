#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        double x0, x1, y0;
        scanf(" %lf %lf %lf", &x0, &x1, &y0);
        double l = fabs(x0 - x1);
        double S = l * fabs(y0) * 1 / 2;
        double s = S / 4;

        printf("%.10f\n", s);
    }

    return 0;
}
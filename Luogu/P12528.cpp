#include <bits/stdc++.h>


using namespace std;

double ans[10][2];
double num[550][2];
int main() {
    int n;
    cin >> n;
    int nums = pow(2, n);
    for(int i = 0; i < nums; i++) {
        scanf("%lf%lf", &num[i][0], &num[i][1]);
        double temp = num[i][0] * num[i][0] + num[i][1] * num[i][1];
        int t = i;
        for(int j = 0; j < n; j++) {
            ans[j][t & 1] += temp;
            t >>= 1;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%.9f %.9f\n", ans[i][0], ans[i][1]);
    }

    return 0;
}
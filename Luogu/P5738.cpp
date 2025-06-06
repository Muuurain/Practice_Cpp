#include <bits/stdc++.h>

using namespace std;

int score[110][30];
int n, m;

double avg(int a) {
    int maxn = 0;
    int minn = 10;
    double sum = 0;
    double avg;
    for(int i = 0; i < m; i++) {
        maxn = max(maxn, score[a][i]);
        minn = min(minn, score[a][i]);
        sum += score[a][i]; 
    }
    avg = (sum - maxn - minn) / (m - 2);
    return avg;
}

int main() {
    cin >> n >> m;
    double maxs = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> score[i][j];
        }
        maxs = max(maxs, avg(i));
    }

    printf("%.2f", maxs);

    return 0;
}
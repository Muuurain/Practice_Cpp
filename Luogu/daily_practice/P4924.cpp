#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > mp;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        vector<int> t1;
        for(int j = i * n + 1; j <= (i + 1) * n; j++) {
            t1.push_back(j);
        }
        mp.push_back(t1);
    }

    while(m--) {
        int x, y, r, z;
        scanf("%d%d%d%d", &x, &y, &r, &z);
        int tmp[2 * r + 1][2 * r + 1];
        for(int i = x - r - 1; i <= x + r - 1; i++) {
            for(int j = y - r - 1; j <= y + r - 1; j++) {
                tmp[i - (x - r - 1)][j - (y - r - 1)] = mp[i][j];
            }
        }    
        if(z == 0) {
            for(int i = x - r - 1; i <= x + r - 1; i++) {
                for(int j = y - r - 1; j <= y + r - 1; j++) {
                    mp[i][j] = tmp[(-1) * j + 2 * y - 2 - (y - r - 1)][i - (x - r - 1)];
                }
            }
        }
        else if(z == 1) {
            for(int i = x - r - 1; i <= x + r - 1; i++) {
                for(int j = y - r - 1; j <= y + r - 1; j++) {
                    mp[i][j]= tmp[j - (y - r - 1)][(-1) * i + 2 * x - 2 - (x - r - 1)];
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         printf("%d", mp[i][j]);
        //         if(j != n - 1) {
        //             printf(" ");
        //         }
        //         else {
        //             printf("\n");
        //         }
        //     }
        // }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", mp[i][j]);
            if(j != n - 1) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
    }
    return 0;
}
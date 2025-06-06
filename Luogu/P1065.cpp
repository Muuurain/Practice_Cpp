#include <bits/stdc++.h>

using namespace std;

struct doit{
    int id = 0;
    int tm = 0;
    int done = 0;
    int lasttime = 0;
};

int main() {
    int ma[25][10001] = {0};
    int doorder[600] = {0};
    int m, n;
    doit workp[30][30];
    cin >> m >> n;
    for(int i = 1; i <= m * n; i++) {
        cin >> doorder[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            workp[i][j].id = t;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            workp[i][j].tm = t;
        }
    }
    int ret = 0;
    for(int i = 1; i <= m * n; i++) {
        int now = doorder[i];
        for(int j = 1; j <= m; j++) {
            if(workp[now][j].done) {
                continue;
            }
            else {
                int ma_id = workp[now][j].id;
                for(int k = workp[now][j - 1].lasttime + 1; k < 10001; k++) {
                    if(ma[ma_id][k] == 0) {
                        int value = 1;
                        for(int l = k; l < k + workp[now][j].tm; l++) {
                            if(ma[ma_id][l] == 1) {
                                value = 0;
                                break;
                            }
                        }
                        if(value) {
                            for(int l = k; l < k + workp[now][j].tm; l++) {
                                ma[ma_id][l] = 1;
                            }
                            workp[now][j].done = 1;
                            workp[now][j].lasttime = k + workp[now][j].tm - 1;
                            ret = max(ret, workp[now][j].lasttime);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    cout << ret << endl;



    return 0;
}
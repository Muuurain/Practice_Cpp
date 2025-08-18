#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
namespace MCMF{
    const int N = 2e5+100;
    struct node{
        int y, v, w, pid;
    };
    vector<node> tu[N];
    int S, T, dis[N], min_cost;
    int sz;
    int new_p(){
        return sz++;
    }
    bool vis[N];
    void addE(int x, int y, int v, int w){
        tu[x].push_back({y, v, w, (int)tu[y].size()});
        tu[y].push_back({x, 0, -w, (int)tu[x].size()-1});
    }
    bool spfa(){
        memset(dis, 0x3f, sizeof(int)*(sz+10));
        dis[S] = 0;
        static bool in[N]; memset(in, 0, sizeof(bool)*(sz+10));
        queue<int> q; q.push(S);
        while(!q.empty()){
            int x = q.front(); q.pop();
            in[x] = false;
            for(auto e: tu[x]){
                if(!e.v) continue;
                if(dis[e.y] > dis[x] + e.w){
                    dis[e.y] = dis[x] + e.w;
                    if(!in[e.y]) q.push(e.y), in[e.y] = true;
                }
            }
        }
        return dis[T] < 1e9;
    }
    int dfs(int x, int flow){
        if(x == T) return flow;
        int res = flow;
        vis[x] = true;
        for(auto &e: tu[x]){
            if(vis[e.y] || dis[e.y] != dis[x] + e.w || !e.v) continue;
            int now = dfs(e.y, min(res, e.v));
            res -= now;
            e.v -= now, tu[e.y][e.pid].v += now;
            min_cost += e.w * now;
            if(!res) break;
        }
        vis[x] = false;
        return flow - res;
    }
    pair<int, int> dinic(){
        int max_flow = 0;
        while(spfa()){
            int now = dfs(S, 1e5);
            while(now) max_flow += now, now = dfs(S, 1e5);
        }
        return {max_flow, min_cost};
    }
};
const int N = 1e5+100;
int n, T, id[N][8];
char s[N];
void add_r(vector<int> px, int liml, int limr, int y){
    limr = min(limr, T+1), liml = min(liml, T+1);
    int npx = MCMF::new_p(), npy = MCMF::new_p();
    for(int p: px) MCMF::addE(p, npx, 1, 0);
    MCMF::addE(npx, npy, 1, -1);
    for(int t = liml; t <= limr; t++) MCMF::addE(npy, id[t][y], 1, 0);
}
int main(){
    scanf("%d%s", &n, s+1);
    MCMF::S = MCMF::new_p();
    int len = strlen(s+1);
    s[len+1] = ',';
    for(int i = 1; i <= len; i++) T += (s[i] == ',');
    T++;
    for(int i = 1; i <= T+1; i++){
        for(int j = 0; j < 8; j++) id[i][j] = MCMF::new_p(); 
    }
    MCMF::T = MCMF::new_p();
    int bg = MCMF::new_p();
    MCMF::addE(MCMF::S, bg, n, 0);
    for(int i = 1; i <= T+1; i++){
        for(int j = 0; j < 8; j++){
            MCMF::addE(bg, id[i][j], n, 0);
            MCMF::addE(id[i][j], MCMF::T, n, 0);
        }
    }
    int l = 1, t = 0, tot = 0;
    while(l <= len){
        t++;
        int r = l;
        while(r <= len + 1){
            if(s[r] == '/' || s[r] == ','){
                if(!isdigit(s[l])){
                    l = r+1;
                    if(s[r] == ',') break;
                    r++; continue;
                }
                tot++;
                int now = s[l] - '1';
                vector<int> las;
                if(t == 1) las.push_back(bg);
                else las.push_back(id[t-1][(now+7)%8]), las.push_back(id[t-1][(now+1)%8]);
                int liml, limr, py;
                if(l+1 == r) liml = t, limr = T+1, py = now;
                else{
                    if(s[l+1] == '['){
                        int d = 0;
                        for(int i = l+2; i <= r; i++){
                            if(!isdigit(s[i])) break;
                            d = d * 10 + s[i] - '0';
                        }
                        liml = t + d - 1, limr = T+1, py = now;
                    }else{
                        int d = 0;
                        for(int i = l+4; i <= r; i++){
                            if(!isdigit(s[i])) break;
                            d = d * 10 + s[i] - '0';
                        }
                        liml = t, limr = t+d-1, py = s[l+2]-'1';
                    }
                }
                add_r(las, liml, limr, py);
                l = r + 1;
                if(s[r] == ',') break;
            }
            r++;
        }
    }
    int ans = -MCMF::dinic().Y;
    if(ans == tot) printf("FC\n");
    else printf("%d/%d\n", ans, tot);
    return 0;
}
/*
2
1,2,1,2,1,2[2],1,2,3-5[2],6,1
*/

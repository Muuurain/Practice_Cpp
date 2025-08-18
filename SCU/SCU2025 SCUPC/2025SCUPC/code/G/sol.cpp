#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int N = 5e5+100;
int n;
pair<int,int> E[N];
int deg[N], degans[N], L[N], R[N];
vector<int> w[N], sum[N];
set<int> tu[N];
bool vis_E[N], vis_p[N];
char ans[N];
bool ok;
void init(){
    for(int i = 1; i <= n; i++){
        deg[i] = degans[i] = L[i] = R[i] = 0;
        vis_E[i] = vis_p[i] = 0;
        tu[i].clear(), w[i].clear(), sum[i].clear();
    }
}
bool check(int x){
    if(sum[x][R[x]] - sum[x][L[x]] + w[x][L[x]] == 1){
        return (w[x][L[x]] == 1 || w[x][R[x]] == 1);
    }
    return false;
}
void calc(int id, int op);
void dfs_calc(int x);
bool solve(){
    ok = true;
    for(int i = 1; i <= n; i++) L[i] = 0, R[i] = deg[i];
    scanf("%s", ans+1);
    for(int i = 1; i < n; i++){
        if(ans[i] == '?') continue;
        int op = ans[i] == '1';
        int x = E[i].X, y = E[i].Y;
        if(op) swap(x, y);
        vis_E[i] = true; degans[y]++;
        R[x]--, L[y]++;
        tu[x].erase(i), tu[y].erase(i);
    }
    for(int i = 1; i <= n; i++) if(check(i)) dfs_calc(i); 
    for(int i = 1; i < n; i++){
        if(ans[i] == '?' && !vis_E[i]) calc(i, 0);
    }
    for(int i = 1; i <= n; i++){
//        cout<<degans[i]<<" "<<deg[i]<<endl;
        if(degans[i] > deg[i] || !w[i][degans[i]]) return false;
    }
    memset(degans, 0, sizeof(degans));
    for(int i = 1; i < n; i++){
        assert(ans[i] != '?');
        if(ans[i] == '0') degans[E[i].Y]++;
        else degans[E[i].X]++;
    }
    for(int i = 1; i <= n; i++) assert(w[i][degans[i]] == 1);
    return ok;
}
int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            int x, y; scanf("%d%d", &x, &y);
            deg[x]++, deg[y]++;
            tu[x].insert(i), tu[y].insert(i);
            E[i] = {x, y};
        }
        
        for(int i = 1; i <= n; i++){
            w[i].resize(deg[i]+1), sum[i].resize(deg[i]+1);
            for(int j = 0; j <= deg[i]; j++){
                char ch = getchar();
                while(ch != '0' && ch != '1') ch = getchar();
                w[i][j] = (ch == '1'), sum[i][j] = w[i][j];
            }
            for(int j = 1; j <= deg[i]; j++) sum[i][j] += sum[i][j-1];
        }
 
        if(!solve()) printf("-1\n");
        else{
            for(int i = 1; i < n; i++) printf("%c", ans[i]); printf("\n");
        }
        init();
    }
}
void calc(int id, int op){
    int x = E[id].X, y = E[id].Y;
    vis_E[id] = true;
    if(ans[id] != '?'){
        if(op + '0' != ans[id]) ok = false;
    }
    ans[id] = '0' + op;
    if(op) swap(x, y);
    degans[y]++;
//    cout<<tu[x].size()<<" "<<tu[y].size()<<endl; 
    tu[x].erase(id), tu[y].erase(id);
    L[y]++, R[x]--;
    if(!vis_p[x] && check(x)) dfs_calc(x);
    if(!vis_p[y] && check(y)) dfs_calc(y);
    
}
void dfs_calc(int x){
    vis_p[x] = true;
    int fx = w[x][R[x]] == 1;//1代表要指向自己
    vector<int> ns;
    for(int id: tu[x]) ns.push_back(id);
    for(int id: ns){
    //    cout<<"***"<<id<<" "<<x<<endl;
        assert(!vis_E[id]);
        int to = (E[id].X == x)? E[id].Y: E[id].X;
        int op = (E[id].Y == x);//现在是否指向自己
        calc(id, op^fx);
    }
}
/*
1
13
10 4
3 13
3 5
5 12
9 12
13 6
8 11
6 10
1 12
11 3
2 7
8 2
11
110
1001
11
110
110
01
111
11
111
111
1111
111
????????????
*/

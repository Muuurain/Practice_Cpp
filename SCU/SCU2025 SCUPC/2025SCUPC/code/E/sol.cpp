#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500013;
const int P=998244353;
int qy(int l,int r) {
    if(l==r)return 1;
    cout<< "? " << l<<' '<<r<<endl;
    int x;cin>>x;return x;
}
string t="0123456789abcdef";
char ans[N];
int pos[20];
void solve() {
    map<char, int> mp;
    for(int i = 0; i <= 15; i++) mp[t[i]] = i;
    int n;
    cin>>n;
    int k=1;
    memset(pos, 0, sizeof(pos));
    ans[1]=t[0];
    pos[0]=1;
    for(int i=2;i<=n;i++) {
        vector<int>ve;
        for(int j=0;j<16;j++)if(pos[j])ve.push_back(pos[j]);
        sort(ve.begin(),ve.end(), greater<int> ());
        if(ve.size() == 16){
            int l = 0,r = (int)ve.size() - 1;
            while(l < r) {
                int mid = (l + r) >> 1;
                int now = qy(ve[mid], i);
                if(now != mid+1) l = mid + 1;
                else r = mid;
            } 
            ans[i] = ans[ve[l]];  
        }else{
            int l = 0, r = (int)ve.size() - 1, v = ve.size();
            while(l <= r){
                int mid = (l + r) >> 1;
                if(qy(ve[mid], i) != mid+1) l = mid + 1;
                else v = mid, r = mid - 1;
            }
            if(v == ve.size()) ans[i] = t[k], k++;
            else ans[i] = ans[ve[v]];
        }
        pos[mp[ans[i]]] = i;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<ans[i];cout<<endl;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
}

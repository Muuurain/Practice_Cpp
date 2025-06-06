#include <iostream>
#include <vector>
#include <queue>
#pragma GCC optimize(3)
using namespace std;
#define int long long
#define rep( i , a , b ) for( int i = (a) , i##end = (b) ; i <= i##end ; ++ i )
#define per( i , a , b ) for( int i = (a) , i##end = (b) ; i >= i##end ; -- i )
const int MAXN = 1e6 + 30;
int n , q;
vector<int> G[MAXN];
 
int rd( ) {
	int ret = 0;
	char ch = getchar();
	while( ch > '9' || ch < '0' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) ret = ret * 10 + ch - '0' , ch = getchar();
	return ret;
}
 
struct BIT {
	int T[MAXN];
	void add( int x , int c ) {
		while( x <= n ) T[x] += c , x += ( x & -x );
	}
	int sum( int x ) {
		int ret = 0;
		while( x > 0 ) ret += T[x] , x -= ( x & -x );
		return ret;
	}
} df , gg ;
 
int siz[MAXN] , deg[MAXN] , hea[MAXN] , szd[MAXN];
int dfn[MAXN] , clo , bac[MAXN] , R[MAXN] , top[MAXN] , fa[MAXN] , tot;
void dfs( int u , int f ) {
	siz[u] = 1;
	fa[u] = f;
	dfn[u] = ++ clo , bac[clo] = u;
	szd[u] = ( deg[u] == 1 );
	for( int v : G[u] ) if( v != f ) {
		dfs( v , u );
		siz[u] += siz[v];
		if( !hea[u] || siz[v] > siz[hea[u]] ) hea[u] = v;
		szd[u] += szd[v];
	}
	R[u] = clo;
}
 
void ffs( int u , int tp ) {
	top[u] = tp;
	if( hea[u] ) ffs( hea[u] , tp );
	for( int v : G[u] ) if( v != fa[u] && v != hea[u] ) {
		ffs( v , v );
	}
}
 
int lt[MAXN] , ad[MAXN];
 
void add( int u , int x ) {
	while( u != 1 ) {
		u = top[u];
		lt[fa[u]] += x * ( tot - szd[u] );
		u = fa[u];
	}
}
 
signed main() {
//	ios::sync_with_stdio( false );
//	cin.tie( 0 );
	n = rd() , q = rd();
	rep( i , 2 , n ) {
		int u , v;
		u = rd() , v = rd();
		G[u].push_back( v ) , G[v].push_back( u );
		++ deg[u] , ++ deg[v];
	}
	if( deg[1] == 1 ) ++ n , G[1].push_back( n ) , deg[n] = 1 , ++ deg[1];
	dfs( 1 , 1 );
	ffs( 1 , 1 );
	tot = szd[1];
	int glob = 0;
	while( q-- ) {
		int o , u , x;
		o = rd() , u = rd();
		if( o == 1 ) {
			x = rd();
			glob += x;
			gg.add( dfn[u] , x );
			add( u , x );
			ad[u] += x;
		} else {
			int ans = ( glob - ( gg.sum( R[u] ) - gg.sum( dfn[u] - 1 ) ) ) * szd[u] + lt[u] + ad[u] * tot;
			
			if( hea[u] ) {
				int h = hea[u];
				ans += ( gg.sum( R[h] ) - gg.sum( dfn[h] - 1 ) ) * ( tot - szd[h] );
			}
			cout << ans << endl;
		}
	}
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;


int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}


bool v[1200][1200];
int c, r, maxl, maxr, maxc, t;
int dr[] = {0, 0, 1, -1};
int dc[] = {1,-1, 0, 0};
string s[1100];

void dfs(int i, int j, int l) {

	v[i][j] = 1;

	if(l > maxl) {  
		maxr  = i;
		maxc = j;
		maxl = l;
	}

	for(int k = 0; k < 4; k++) {
		if(i + dr[k] >= 0 && i + dr[k] < r && j + dc[k] >= 0 && dc[k] + j < c && v[i + dr[k]][j+dc[k]] == false && s[i + dr[k]][j + dc[k]] == '.') {
			dfs(i + dr[k], j + dc[k], l + 1);
		}
	}
 
}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while(t--) {
		cin >> c >> r;
		for(int i = 0; i < r; i++)  cin >> s[i];
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {

				if(s[i][j] == '.') {
					maxl = -1;
					memset(v, false, sizeof(v));
					dfs(i, j, 0);
					maxl = -1;
					memset(v, false, sizeof(v));
					dfs(maxr, maxc, 0);
					goto fin;
				}
			}
		}
		fin:;

		cout << "Maximum rope length is " << maxl << "." << endl;
	}
}



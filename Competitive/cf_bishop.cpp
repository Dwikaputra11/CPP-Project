#include <iostream>
using namespace std;
#define ll                  long long
#define scl(n)              cin>>n;
#define scc(c)              cin>>c;
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define pb                  push_back

#define l(s)                s.size()
#define asort(a)            sort(a,a+n)
#define all(x)              (x).begin(), (x).end()
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)           sort(v.begin(), v.end());
#define vdsort(v)           sort(v.begin(), v.end(),greater<int>());
#define uniquee(x)          x.erase(unique(x.begin(), x.end()),x.end())
#define pn                  cout<<endl;
#define md                  1000000007
#define inf                 1e18
#define ps                  cout<<" ";
#define Pi                  acos(-1.0)
#define mem(a,i)            memset(a, i, sizeof(a))
#define tcas(i,t)           for(ll i=1;i<=t;i++)
#define pcas(i)             cout<<"Case "<<i<<": "<<"\n";
#define fast  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// But, the editorial made some brilliant observations. We don't need to explicitly colour the squares. 

// The secondary diagonal has the invariant (x + y)

// The principal diagonal has the invariant (x - y). However, we want to avoid negative numbers and use array indices, so use (x - y + n).

int const N = 2005;
int n, g[N][N], x, y, xx, yy;
long long dp1[2 * N], dp2[2 * N], sol1 = -1, sol2 = -1;

int main() {
	fast;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
      cin >> g[i][j];
      dp1[i + j] += g[i][j];
      dp2[i - j + n] += g[i][j];
    }
  
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
      long long v = dp1[i + j] + dp2[i - j + n] - g[i][j];
      	if((i + j) & 1) {
	        if(v > sol2) {
	          sol2 = v;
	          xx = i;
	          yy = j;
	        }
	      }
		else {
	        if(v > sol1) {
	          sol1 = v;
	          x = i;
	          y = j;
	        }
	    }
    }
  
  cout << sol1 + sol2 << endl;
  cout << x << " " << y << " " << xx << " " << yy << endl;
  
  return 0;
}
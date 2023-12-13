#include <bits/stdc++.h>
#include <vector>
using namespace std;
// link: https://codeforces.com/problemset/problem/448/D
vector <long long int> first;
vector <long long int> second;

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

int main() {
  fast;
  int n,m, k;
  int val = 1;
  cin >> n >> m >> k;

  for(int i = 1; i <= n;i++){
    // first.push_back(i);
    for(int j = 1; j <= m; j++){
      val = i * j;
      first.pb(val);
    }
  } 
  vasort(first);
  int found = 1;
  int itr = first[n*m - 1];
  int index;
  for(int i = n*m - 1; i >= 0; i--){
    if(first[i] < itr){
      itr = first[i];
      found++;
    }
    if(k == found){
      index = found;
      break;
    } 
  }
  cout << first[index - 1] << endl;
  
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef pair<ll, ll>	pl;
typedef pair<int, int>	pii;



const ll mod = 1000000007;
ll mpow(ll base, ll exp) {
  base %= mod;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}


bool f(int x, int y)         //to sort in reverse order like-->sort(a.begin(),a.end(),f)
{
	return x>y;
}

int gcdExtended(int a, int b, int *x, int *y) 
{ 
   
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        
        int res = (x%m + m) % m; 
        cout << "Modular multiplicative inverse is " << res; 
    } 
} 
/*
#define maxx
vector<int> pr;
vector<bool> p(maxx,true);

sieve() {
	for(int i=2;i<maxx,;i++) {
		if(p[i]) {
			int j=2*i;
			while(j <MAXX) {
				p[j] = false;
				j+=i;
			}
			pr.push_back(i);
		}
	}
}
*/

void solve() {
	ll n,k;
	cin>>n>>k;
	ll ps[n];
	ll a[n];
	
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ps[0]=a[0];
	for(ll i=1;i<n;i++)
	ps[i]=a[i]+ps[i-1];
	
	ll inc=0;
	
	for(ll i=n-1;i>0;i--) {
		ll temp = k*(ps[i-1]+inc);
		if(temp>a[i]*100)
		continue;
		else {
			ll x=(a[i]*100 -(ps[i-1]+inc)*k +k -1)/k;
			inc+=x;
		}
	}
	cout<<inc<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
    
	
}



#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define si(n) scanf("%d", &n)
#define sl(l)	scanf("%lld",&l)
#define ss(s)	cin>>s
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	cout<<s<<"\n"
#define debug(x) cout<< #x <<" = "<<x<<"\n"
#define endl "\n"



typedef vector< int > vi;
typedef vector< char > vc;
typedef vector< string > vs;
typedef vector< ll > vll;
typedef vector< float > vf;
typedef vector< vi > vvi;
typedef vector< vll > vvll;


const int m = 3e5;



vector<int> getPre(int a[], int t){
    vector<int> b(t, 0);
    stack<int> s;
    for(int i = 0;i < t;i++){
        while(!s.empty() && a[s.top()] >= a[i]){
            s.pop();
        }
        if(!s.empty())
        b[i] = s.top() + 1;
        s.push(i);
    }
    
    return b;
}

vector<int> getSuf(int a[], int t){
    vector<int> c(t, t - 1);
    stack<int> ns;
    for(int i = t - 1; i > -1;i--){
        while(!ns.empty() && a[ns.top()] >= a[i]){
            // int ind = ns.top();
            ns.pop();
            // c[ind] = i;
        }
        if(!ns.empty())
        c[i] = ns.top() - 1;
        ns.push(i);
    }
    
    return c;
}

int areaOfHistogram(int a[], int n){
    
    vector<int> l = getPre(a, n);
    vector<int> r = getSuf(a, n);

    // for(int i = 0;i < n;i++)cout<<l[i]<<" ";
    	// cout<<endl;
    // for(int i = 0;i < n;i++)cout<<r[i]<<" ";

    
    int ans = INT_MIN;
    for(int i = 0;i < n;i++){
       int t = (r[i] - l[i] + 1) * a[i];
        ans = max(ans, t);
    }
    return ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)cin>>a[i];
        cout<<areaOfHistogram(a, n)<<endl;
        
    }
    return 0;
}
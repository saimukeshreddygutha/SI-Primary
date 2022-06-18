#include<bits/stdc++.h>
using namespace std;

void selectsort(int a[], int n){
    for(int i = n - 1;i > 0;i--){
        
        int mx = i;
        
        for(int j = i - 1;j >= 0;j--){
            
            if(a[mx] <= a[j]){
                    mx = j;
            }
        }
        
        int t = a[mx];
        a[mx] = a[i];
        a[i] = t;
        cout<<mx<<" ";
        
    }
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
        selectsort(a, n);
        cout<<endl;
        
    }
    return 0;
}

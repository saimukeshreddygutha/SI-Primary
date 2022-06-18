#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    long int num[1000],sum=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%ld",&num[i]);
            sum+=num[i];
        }
        printf("%ld\n",sum);
        sum=0;
    }
}

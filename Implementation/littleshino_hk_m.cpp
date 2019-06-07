#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n],flag[n],fight[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        fight[i]=0;
        flag[i]=1;
    }
    int j=0,k=0,x=n;
    while(x){
        j=0;
        while(j < n){
            if(flag[j] == 1){
                k=j+1;
                while(k<n){
                    if(flag[k] == 1){
                        fight[j]++;
                        fight[k]++;
                        if(arr[j] < arr[k])flag[j]=0;
                        else flag[k]=0;
                        j=k;
                        break;
                    }
                    k++;
                }
            }
            j++;
        }
        x/=2;
    }
    while(q--){
        int temp;
        scanf("%d",&temp);
        printf("%d\n",fight[temp-1]);
    }
    return 0;
}
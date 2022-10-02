#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k,i,sum=0,mn,ind,totalSum;
    scanf("%d%d",&n,&k);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //so basically we have to find the subarray of size k having min sum
    // since subarray is of fixed size , we will use sliding window algorithm
    for(i=0;i<k;i++)
        sum = sum+a[i];
    totalSum = sum;
    mn=sum;
    for(i=1;i<=(n-k);i++){
        sum = sum-a[i-1];
        sum = sum+ a[i+(k-1)];
        mn= min(mn,sum);
    }
    if(totalSum==mn)
        ind=0;
    else{
        for(i=1;i<=(n-k);i++){
            totalSum = totalSum-a[i-1];
            totalSum = totalSum +a[i+(k-1)];
            if(totalSum==mn){
                ind=i;
                break;
            }
        }
    }
    cout<<ind+1;


}

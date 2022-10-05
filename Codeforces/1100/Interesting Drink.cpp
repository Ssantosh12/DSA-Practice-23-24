#include <bits/stdc++.h>

using namespace std;

int main(){
    int money,n,i,low,mid,high,q;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    scanf("%d",&q);
    int ans[q];
    for(i=0;i<q;i++){
        scanf("%d",&money);
        low=-1;
        high=n-1;
      
        //NOTE : There are MAJOR EDGE Case in Binary Search (how  mid is calculated and Low and High is changed)
      
        while(low<high){
            if((high-low)&1)
                mid=low+(high-low)/2+1;
            else mid=low+(high-low)/2;
          
            //now we check the binary search conditions for finding the largest element less than equal to money in the array
            if(a[mid]>money)
                 high=mid-1;
            else
                low=mid;

        }

        //ans array store the answer for each query q
        ans[i]=low+1;
    }
    for(i=0;i<q;i++)
        cout<<ans[i]<<"\n";
}

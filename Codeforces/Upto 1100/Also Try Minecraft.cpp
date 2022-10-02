#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int inds,indt,n,m,i,j,fall=0;
    scanf("%lld%lld",&n,&m);
    long long int a[n];
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    // first we store the fall damage till ith index
    //we use the prefix and suffix array concept to store the prefix and suffix fall damage beforehand
    long long int fallPrefix[n],fallSuffix[n];

    for(i=0;i<n;i++){
        if(i==0||a[i]>=a[i-1])
            fallPrefix[i] = fall;
        else{
            fall = fall+(a[i-1]-a[i]);
            fallPrefix[i]=fall;
        }
    }
    fall=0;
    for(i=n-1;i>=0;i--){
        if(i==(n-1)||a[i]>=a[i+1])
            fallSuffix[i] = fall;
        else{
            fall = fall+(a[i+1]-a[i]);
            fallSuffix[i]=fall;
        }
    }
    vector<long long int> vc;
    for(i=0;i<m;i++){
        scanf("%lld%lld",&inds,&indt);
        inds--; indt--;
        if(indt>inds)
            vc.push_back(fallPrefix[indt]-fallPrefix[inds]);
        else  vc.push_back(fallSuffix[indt]-fallSuffix[inds]);
    }
    for(auto x: vc)
        cout<<x<<endl;
}

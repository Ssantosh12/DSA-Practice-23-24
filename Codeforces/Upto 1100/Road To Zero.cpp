#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int diff,intx,inty,costa,costb,totalCost=0;
        scanf("%lld%lld%lld%lld",&intx,&inty,&costa,&costb);
        diff=max(intx,inty)-min(intx,inty);
        //for diff we will have to use operation 1st
        if(2*costa<costb)
            totalCost = totalCost+min(intx,inty)*(2*costa);
        else totalCost = totalCost+min(intx,inty)*costb;

        totalCost = totalCost+diff*costa;
        cout<<totalCost<<"\n";
    }
}

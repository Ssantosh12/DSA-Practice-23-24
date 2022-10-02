
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,i,cnt=0,ele;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    multiset<int> mst;
    for(i=0;i<m;i++){
        scanf("%d",&ele);
        mst.insert(ele);
    }
    //now check for every a[i] if a[i]-1,a[i],a[i+1] is present
    //if multiple are present we choose the leftmost,ans leave the right ones in sorted manner of array a(boys)
    //so that right ones can be useful for other as well
    sort(a,a+n);
    for(i=0;i<n;i++){
        ele=a[i]-1;
        if(mst.lower_bound(ele)!=mst.end()&&(*mst.lower_bound(ele))<=(ele+2)){
            cnt++;
            mst.erase(mst.lower_bound(ele));
        }
    }
    printf("%d\n",cnt);
    //adding comment for learning purposes
}

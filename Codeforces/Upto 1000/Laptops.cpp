#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,n,i;
    bool alex=false;;
    scanf("%d",&n);
    vector<vector<int>> vec(n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        vec[i].push_back(a);
        vec[i].push_back(b);
    }

    sort(vec.begin(),vec.end());  // sorting by increasing price so quality should also increase accordingly
                                  // but as we go down/forward and quality is less than we have ATLEAST 2 laptops where price is less but quality is more
    for(i=1;i<n;i++){
        if(vec[i][1]<vec[i-1][1]){
            alex=true;
            break;
        }
    }
    if(alex)
        cout<<"Happy Alex";
    else cout<<"Poor Alex";

}

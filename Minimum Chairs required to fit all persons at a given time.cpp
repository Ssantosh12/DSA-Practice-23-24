#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int i,j,n,ts,te,siz,mx=0,people=0;
        scanf("%d",&n);
        vector<pair<int,pair<char,int>>> vc;
        vector<int> T1(n);
        vector<int> T2(n);
        vector<int> S(n);

        for(i=0;i<n;i++){
            scanf("%d",&T1[i]);  // entry time of each group of people 
        }
        for(i=0;i<n;i++){
            scanf("%d",&T2[i]);  // exiting time of each group of people
        }
        for(i=0;i<n;i++){
            scanf("%d",&S[i]);  // size of each group of people
        }
      
        for(i=0;i<n;i++){
            ts=T1[i];
            te=T2[i];
            siz=S[i];
            vc.push_back({ts,{'a',siz}});
            vc.push_back({te,{'l',siz}});
        }
      
        // sorting according to time ( irrespective of arrival or leaving )
        sort(vc.begin(),vc.end());
        for(auto x: vc){
            cout<<x.first<< " "<<x.second.first<<" "<<x.second.second<<endl;
            if(x.second.first=='a')   // a denotes 'arrival' of group of people
                people+=x.second.second;   
            else if(x.second.first=='l')  // l denotes 'leaving' group of people
                people-=x.second.second;
            mx=max(mx,people);
        }
        cout<<mx<<endl;
    }
}

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int i,low=0,high=1e14,mid,n=time.size(),cnt;
        
        // we can use binary search to find the answer 
        // because this comes under this category => NNNNNYYYYY
        while(low<high){
            mid = low+(high-low)/2;
            cnt=0;
            for(i=0;i<n;i++)
                cnt+=mid/time[i];

            if(cnt<totalTrips)
                low=mid+1;
            else high=mid;
        }

        return high;
        
    }
};

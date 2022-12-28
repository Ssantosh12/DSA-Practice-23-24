class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int i,sum=0,ele;
        priority_queue<int> pq;
        for(i=0;i<piles.size();i++)
            pq.push(piles[i]);
        // we choose the current max element each time we do the operation
        while(k--){
            ele=pq.top()-(pq.top()/2);
            pq.pop();
            pq.push(ele);
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        } 
        return sum;
    }
};

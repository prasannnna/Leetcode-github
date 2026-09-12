class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>>pq;
        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int diff = abs(x - y);
            if(diff != 0) {
                pq.push(diff);
            }
        }
        if(!pq.empty()) {
            return pq.top();
        }
        return 0;
    }
};
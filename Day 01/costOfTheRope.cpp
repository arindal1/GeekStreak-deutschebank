class Solution {
  public:
    long long minCost(std::vector<long long>& arr) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq(std::move(arr));
        long long totalCost = 0;
        
        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            long long cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        return totalCost;
    }
};
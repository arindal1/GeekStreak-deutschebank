class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positive, negative;
        
        for (int num : arr) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }
    
        int posIndex = 0, negIndex = 0, i = 0;
        while (posIndex < positive.size() && negIndex < negative.size()) {
            if (i % 2 == 0) {
                arr[i] = positive[posIndex++];
            } else {
                arr[i] = negative[negIndex++];
            }
            i++;
        }
    
        while (posIndex < positive.size()) {
            arr[i++] = positive[posIndex++];
        }
    
        while (negIndex < negative.size()) {
            arr[i++] = negative[negIndex++];
        }
    }
};
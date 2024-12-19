class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxChunk = 0;
        int maxValue = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxValue = max(maxValue, arr[i]);

            if (i == maxValue) {
                maxChunk++;
            }
        }

        return maxChunk;
    }
};
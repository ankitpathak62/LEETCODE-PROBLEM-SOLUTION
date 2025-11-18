class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Hash map to count frequencies of each number
        unordered_map<int, int> freq;

        // Count frequencies
        for (int& num : nums)
            freq[num]++; // Increment frequency count for each number

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        for (auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;
            minHeap.push({count, num});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
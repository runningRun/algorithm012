class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (0 == k) 
            return vector<int>();
            
        priority_queue<int, vector<int>> kQueue;
        vector<int> result(k);
        int index = 0;
        for (index = 0; index < k; ++index) {
            kQueue.push(arr[index]);
        }

        for (index = k; index < arr.size(); ++index) {
            if (kQueue.top() > arr[index]) {
                kQueue.pop();
                kQueue.push(arr[index]);
            }
        }

        index = 0;
        while (!kQueue.empty()) {
            result[index++] = kQueue.top();
            kQueue.pop();
        }

        return result;
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> tmpDigits;
        vector<int> result;
        int tmpSum = 1;
        
        for (int index = digits.size() - 1; index >= 0; --index) {
            tmpSum += digits[index];
            tmpDigits.push(tmpSum % 10);
            tmpSum /= 10;
        }
        
        if (0 != tmpSum)
            tmpDigits.push(tmpSum);
        
        while (!tmpDigits.empty()) {
            result.push_back(tmpDigits.top());
            tmpDigits.pop();
        }
        
        return result ;

    }
};
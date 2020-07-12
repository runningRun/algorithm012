class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;
        int diff = longer - shorter;
        if (0 == k)
            return result;
        if (shorter == longer) {
            result.push_back(shorter * k);
            return result;
        }
        for (int index = 0; index <= k; ++index) {
            result.push_back(shorter * k + diff * index);
        }
        return result;
    }
};


/*
  * 由于最初可以知道最多有k+1中方法，所以可以将result的长度固定为k+1
  * 从而使用result[index] = shorter * k + diff * index; 减少使用
  * push_back引起的多次内存分配
*/

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
       
        if (0 == k)
            return vector<int>{};
        if (shorter == longer) {
            return vector<int>{shorter * k};
        }
        int diff = longer - shorter;
        vector<int> result(k + 1) ;
        for (int index = 0; index <=k; ++index)
            result[index] = shorter * k + diff * index;
        
        return result;
    }
};
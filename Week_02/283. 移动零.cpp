class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int jIndex = 0;
        int tmp = 0;
        int numsSize = nums.size();
        for (; index < numsSize; ++index) {
            if (0 != nums[index]) {
                tmp = nums[jIndex];
                nums[jIndex++] = nums[index];
                nums[index] = tmp;
            }
        }
    }
};

/*
 * 1. 10 - 12行，为何不能直接nums[index] = 0 ??
 * 因为可能存在如果nums[0] = 2，则在10~12行中直接被覆盖为0
 * 2. 如果只有index != jIndex 才进行交换，则 
 *     if (0 != nums[index]) {
          if (index == jIndex) {
              jIndex += 1;
          } else {
              tmp = nums[jIndex];
              nums[jIndex++] = nums[index];
              nums[index] = tmp;
          }
      }

      如果
      if (0 != nums[index] && index != jIndex) {
          tmp = nums[jIndex];
          nums[jIndex++] = nums[index];
          nums[index] = tmp;
      }

      则输入[1,2],直接被变为[2,1]了，原因在于nums[index]不为0时，jIndex也要增加
*/
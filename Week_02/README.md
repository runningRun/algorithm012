学习笔记
1. 有效的字母异位词：统计两个字符串中同一字母出现的次数是否相同
    a) 使用两个长度为26的数组，存储'a' - 'z'出现的次数，然后顺序比较两个数组
    b) 使用一个数组，初始化为0，s中出现字母ch时，arrary[ch] += 1; t中出现字母ch时，array[ch] -= 1
        最后再判断数组是不是完全为0
2. 关于移动零
    a. 10 - 12行，为何不能直接nums[index] = 0 ??
        因为可能存在如果nums[0] = 2，则在10~12行中直接被覆盖为0
    b. 如果只有index != jIndex 才进行交换，则 
      if (0 != nums[index]) {
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

3.  while (!kWindow.empty() && kWindow.back() <= nums[index])
        kWindow.pop_back();
    如果使用 <= 来删除kWindow的队尾元素，则
    输入：[-7,-8,7,5,7,1,6,0] 
          4
    输出：[7,7,7,6,6]
    预期：[7,7,7,7,7]
    
    原因是下标为nums[4]为7，会把kWindow里面的nums[2]的7冲掉
    并且当index == 6时，此时kWindow中7是nums[4]的7，但由于
    kWindow.front() == nums[index - k]，所以会kWindow.pop_front()
    导致kWindow中没有7
 
    for (index = k; index < nums.size(); ++index) {
        if (kWindow.size() == k)
            kWindow.pop_front();
        while (!kWindow.empty() && kWindow.back() <= nums[index])
            kWindow.pop_back();
        kWindow.push_back(nums[index]);
        result[index - k + 1] = kWindow.front();
    }

    如果依靠 kWindow.size() == k 来删除头元素，则案例
    输入：[1,3,1,2,0,5]
          3
    输出：[3,3,3,5]
    预期：[3,3,2,5]

    原因是2进入时，会把1从队列尾部移除，0 进入前，kWindow中元素为：3，2
    结果0再进入时，kWindow.front()仍然是3，所以通过 
    kWindow.front() == nums[index - k]滤除“过期”的3

4. TOP-K问题：
    a. 使用快排思想，利用快排的特性，一次排序后，即可将一个特定的元素归为，并且左边的全比其小(或大)，右边的全比其大(或小)，
       利用这个特性，如果该元素正好在K位置，则左边(或右边)的就是结果
    b. 利用堆排序，建立一个规模为K的大顶堆(或小顶堆)，依次将元素放入，每次弹出最大(或最小的)元素，最终堆中剩余的元素即为K小或K大的元素
       时间复杂度为O(nlogk)
    c. 排序后，选择前K个元素，时间复杂度为O(nlogn)
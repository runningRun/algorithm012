class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0;
        int count_10 = 0;
        int index = 0;
        int size = bills.size();

        for (index = 0; index < size; ++index) {
            switch (bills[index]) {
                case 5:
                    count_5 += 1;
                    break;
                case 10:
                    if (count_5 < 1)
                        return false;
                    count_5 -= 1;
                    count_10 += 1;
                    break;
                case 20:
                    if (count_5 > 0 && count_10 > 0) {
                        count_10 -= 1;
                        count_5 -= 1;
                    } else if (count_5 > 3) {
                        count_5 -= 3;
                    } else {
                        return false;
                    }

                    break;
            }
        }

        return true;
    }
};
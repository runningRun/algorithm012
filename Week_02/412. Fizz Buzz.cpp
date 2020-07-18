class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        map<int, string> fizzBuzzMap = {{3, "Fizz"}, {5, "Buzz"}};
        auto itBegin = fizzBuzzMap.begin();
        auto itEnd = fizzBuzzMap.end();

        string tmpResult;
        for (int index = 1; index <= n; ++index) {
            tmpResult = "";
            for (auto it = itBegin; it != itEnd; ++it) {
                if (0 == index % it->first) {
                    tmpResult += it->second;
                }
            }

            if (tmpResult.empty()) {
                tmpResult = to_string(index);
            }
            result[index - 1] = tmpResult;
        }
        return result;
    }
};
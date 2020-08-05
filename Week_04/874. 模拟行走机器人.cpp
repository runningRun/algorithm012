class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        stringstream ss;
        unordered_set<string> obstacleSet;
        int currentX = 0;
        int currentY = 0;
        int maxDistance = 0;
        int currentDirect = 0;
        pair<int, int> directs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        cout << "obstacles: ";
        for (int index = 0; index < obstacles.size(); ++index) {
            ss.str("");
            ss << obstacles[index][0] << "," << obstacles[index][1];
            // cout << ss.str() << " ";
            obstacleSet.insert(ss.str());
        }

        for (int &steps : commands) {
            switch(steps) {
            case -1:
                // 向右转90度
                currentDirect = (currentDirect + 1) % 4;
                break;
            case -2:
                // 向左转90度
                currentDirect = (currentDirect + 3) % 4;
                break;
            default:
                for (int ii = 0; ii < steps; ++ii) {
                    int tx = currentX + directs[currentDirect].first;
                    int ty = currentY + directs[currentDirect].second;
                    ss.str("");
                    ss << tx << "," << ty;
                    if (obstacleSet.find(ss.str()) == obstacleSet.end()) {
                        // nums[tx][ty]不是障碍物
                        currentX = tx;
                        currentY = ty;
                        maxDistance = max(maxDistance, currentX * currentX + currentY * currentY);
                        // cout << "at: " << ss.str() << " max distance: " << maxDistance << endl;
                    } else {
                        break;
                    }
                }
                break;
            }
        }

        return maxDistance;
    }
};

// 将二维下标[index][jIndex]使用 (index << 32 + jIndex)的方式转换成1一个数值
// 由于这里的index、jIndex均可能是负数，所以强制使用unsigned int转换为正数
// 测试案例
// [7,-2,-2,7,5]、[[-3,2],[-2,1],[0,1],[-2,4],[-1,0],[-2,-3],[0,-3],[4,4],[-3,3],[2,2]]
// [-2,-1,8,9,6]、[[-1,3],[0,1],[-1,5],[-2,-4],[5,4],[-2,-3],[5,-1],[1,-1],[5,5],[5,2]]
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obstacleSet;
        long long tx = 0;
        long long ty = 0;
        int currentX = 0;
        int currentY = 0;
        long long tmpValue = 0;
        int maxDistance = 0;
        int currentDirect = 0;
        pair<int, int> directs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int index = 0; index < obstacles.size(); ++index) {
            tmpValue = ((unsigned long long)obstacles[index][0] << 32); 
            tmpValue += (unsigned int)obstacles[index][1];
            obstacleSet.insert(tmpValue);
        }

        for (int &steps : commands) {
            switch(steps) {
            case -1:
                // 向右转90度
                currentDirect = (currentDirect + 1) % 4;
                break;
            case -2:
                // 向左转90度
                currentDirect = (currentDirect + 3) % 4;
                break;
            default:
                for (int ii = 0; ii < steps; ++ii) {
                    tx = currentX + directs[currentDirect].first;
                    ty = currentY + directs[currentDirect].second;
                    tmpValue = ((unsigned long long)tx << 32);
                    tmpValue += (unsigned int)ty;
                    if (obstacleSet.find(tmpValue) == obstacleSet.end()) {
                        // nums[tx][ty]不是障碍物
                        currentX = tx;
                        currentY = ty;
                        maxDistance = max(maxDistance, currentX * currentX + currentY * currentY);
                        // cout << "at: " << ss.str() << " max distance: " << maxDistance << endl;
                    } else {
                        break;
                    }
                }
                break;
            }
        }

        return maxDistance;
    }
};
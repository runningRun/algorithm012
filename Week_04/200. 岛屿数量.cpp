class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        for (int index = 0; index < grid.size(); ++index) {
            for (int jIndex = 0; jIndex < grid[index].size(); ++jIndex) {
                if ('1' == grid[index][jIndex]) {
                //    cout << "find from [" << index <<　",　"　<<　jIndex <<　"]"　<<　endl;
                    findLand(index, jIndex, grid);
                    result += 1;
                }
            }
        }
        return result;
    }

    void findLand(int i, int j, vector<vector<char>> &grid) {
        // cout << "i: " << i << " j: " << j << endl;
        if (i < 0 || j < 0 || i == grid.size() || j == grid[i].size()) {
            return ;
        }
        if ('1' == grid[i][j]) {
            // stringstream ss;
            // ss << "[" << i << ", " << j << "]";
            // cout << ss.str() << endl; 
            grid[i][j] = '2';
            // this line next column
            findLand(i, j + 1, grid);
            // this columen next line
            findLand(i + 1, j, grid);
            findLand(i, j - 1, grid);
            findLand(i - 1, j, grid);
        }
        
    }
};
/*



*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<unordered_set<string>> lands;
        
        for (int index = 0; index < grid.size(); ++index) {
            for (int jIndex = 0; jIndex < grid[index].size(); ++jIndex) {
                if ('1' == grid[index][jIndex]) {
                //    cout << "find from [" << index <<　",　"　<<　jIndex <<　"]"　<<　endl;
                    unordered_set<string> land;
                    findLand(index, jIndex, grid, land);
                    lands.push_back(land);
                }
            }
        }
        return lands.size();
    }

    void findLand(int i, int j, vector<vector<char>> &grid, unordered_set<string> &land) {
        // cout << "i: " << i << " j: " << j << endl;
        if (i < 0 || j < 0 || i == grid.size() || j == grid[i].size()) {
            return ;
        }
        // cout << "check" << endl;
        if ('1' == grid[i][j]) {
            stringstream ss;
            // ss << "[" << i << ", " << j << "]";
            land.insert(ss.str());
            cout << ss.str() << endl; 
            grid[i][j] = '2';
            // this line next column
            findLand(i, j+1, grid, land);
            // this columen next line
            findLand(i+1, j, grid, land);
            findLand(i, j - 1, grid, land);
            findLand(i - 1, j, grid, land);

            // // this line [0, j-1]
            // // [["1","1","1"],["0","1","0"],["1","1","1"]]
            // int tmpJ = j;
            // while (tmpJ > 0 && '1' == grid[i][tmpJ-1]) {
            //     findLand(i, tmpJ - 1, grid, land);
            //     tmpJ -= 1;
            // }

            // // this column [0, j-1]
            // // [["1","0","1","1","1"],["1","0","1","0","1"],["1","1","1","0","1"]]
            // while (i > 0 && '1' == grid[i - 1][j]) {
            //     findLand(i - 1, j, grid, land);
            //     i -= 1;
            // }
        }
        
    }
};

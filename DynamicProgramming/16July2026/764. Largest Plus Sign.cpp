class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> grid(n, vector<int>(n, 1));

        // Place mines
        for (auto &m : mines)
            grid[m[0]][m[1]] = 0;

        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        // Left DP
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { //checks whether the current cell is 0 or 1, if 1 then only go inside
                    if (j == 0) //we know all elements are 1, Base Case: if j==0(0th col) then always put 1
                        left[i][j] = 1;
                    else //if not 0th col then left + 1 is current cell value
                        left[i][j] = left[i][j - 1] + 1;
                }
            }
        }

        // Right DP
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    if (j == n - 1)
                        right[i][j] = 1;
                    else
                        right[i][j] = right[i][j + 1] + 1;
                }
            }
        }

        // Up DP
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) {
                    if (i == 0)
                        up[i][j] = 1;
                    else
                        up[i][j] = up[i - 1][j] + 1;
                }
            }
        }

        // Down DP
        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 1) {
                    if (i == n - 1)
                        down[i][j] = 1;
                    else
                        down[i][j] = down[i + 1][j] + 1;
                }
            }
        }

        int ans = 0;

        // Find largest plus
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int order = min({
                    left[i][j],
                    right[i][j],
                    up[i][j],
                    down[i][j]
                });

                ans = max(ans, order);
            }
        }

        return ans;
    }
};
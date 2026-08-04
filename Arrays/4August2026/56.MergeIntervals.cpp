class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        for(int i = 0; i< n; i++){
            if(i == 0){                                                  // when ans vector is empty
                ans.push_back(intervals[i]);
                continue;
            }

            if(ans.back()[1] >= intervals[i][0]){
                // int vecFirst = ans.back()[0];
                // int vecLast  = ans.back()[1];

                // ans.pop_back();
                // ans.push_back( { min(vecFirst, intervals[i][0]), max(vecLast, intervals[i][1]) } );
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            // else if(ans.back()[1] == intervals[i][0]){
            //     int vecFirst = ans.back()[0];
            //     int vecLast  = ans.back()[1];
            //     ans.pop_back();
            //     ans.push_back({vecFirst, intervals[i][1]});

            // }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
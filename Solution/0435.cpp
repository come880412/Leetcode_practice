class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // Sort the intervals array according to strating point.
        int end = intervals[0][1];
        int delete_cnt = 0;

        // for(int i=0; i < intervals.size(); ++i){
        //     for(int j=0; j<2; ++j)
        //         cout<<intervals[i][j]<<" ";
        //     cout<<endl;
        // }

        for(int i=1; i < intervals.size(); ++i){
            if(intervals[i][0] < end){
                delete_cnt += 1;
                if(intervals[i][1] < end) // Greedy alg.(Choose a smaller end point)
                    end = intervals[i][1];
            }
            else
                end = intervals[i][1];
        }
        
        return delete_cnt;
    }
};
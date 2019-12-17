//input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//subarray after step 1: [[7,0], [7,1]]
//subarray after step 2: [[7,0], [6,1], [7,1]]
//sort and insert
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>&v1,vector<int>&v2){
            return v1[0]>v2[0]||(v1[0]==v2[0]&&v1[1]<v2[1]);
        });
        vector<vector<int>>ret;
        for(auto person:people)
        {
            ret.insert(ret.begin()+person[1],person);
        }
        return ret;
    }
};
//change to one dimention 
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool overlap_x=!(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]);
        bool overlap_y=!(rec1[3]<=rec2[1]||rec2[3]<=rec1[1]);
        return overlap_x&&overlap_y;
    }
};
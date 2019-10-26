//overlap
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return min(ret1[2],ret2[2])>max(ret1[0],ret2[0])&&
            min(ret1[3],ret2[3])>max(ret1[1],ret2[1]);
    }
};
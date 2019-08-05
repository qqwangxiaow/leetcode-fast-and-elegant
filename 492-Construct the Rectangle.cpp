/*直接做 最后return不能忘记 */
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i=sqrt(area);i>0;i--)
        {
            if(area%i==0)
                return {area/i,i};
        }
        return {area,1};
           
    }
};

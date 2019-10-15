//找大于等于target的sum 一定要是偶数
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int step=0;
        int sum=0;
        while(sum<target)
        {
            step++;
            sum+=step;
        }
        while((sum-target)%2!=0)
        {
            step++;
            sum+=step;
        }
        return step;
        
    }
};
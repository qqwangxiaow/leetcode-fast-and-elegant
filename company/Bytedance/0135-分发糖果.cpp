//从左边遍历 比左边大+1 
//从右边同理 取最大
class Solution {
public:
    int candy(vector<int>& ratings) {
        int count=0;
        vector<int>left(ratings.size(),1);
        vector<int>right(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1;
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
            else    
                right[i]=1;
        }
        for(int i=0;i<ratings.size();i++)
        {
            count+=max(left[i],right[i]);
        }
        return count;
    }
};
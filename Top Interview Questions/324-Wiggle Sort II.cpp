//partion to find median
//3-way-partition to sort
//两边数组都反着插入就不会出现相邻的
//[1,1,2] [2,2,3]
//反过来 成为 [2,1,1] [3,2,2]
//插入就是 231212 满足！
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto midptr=nums.begin()+nums.size()/2;
        nth_element(nums.begin(),midptr,nums.end());
        int mid=*midptr;
        int i=0,j=0,k=nums.size()-1;
        //3-way-partition  i means left(<mid)  k-right(>mid)
        while(j<k)
        {
            if(nums[j]>mid)
            {
                swap(nums[j],nums[k]);
                k--;
            }
            else if(nums[j]<mid)
            {
                swap(nums[j],nums[i]);
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(nums.size()%2)
            ++midptr;
        vector<int>tmp1(nums.begin(),midptr);
        vector<int>tmp2(midptr,nums.end());
        for(int i=0;i<tmp1.size();i++)
        {
            nums[2*i]=tmp1[tmp1.size()-1-i];
        }
        for(int i=0;i<tmp2.size();i++)
        {
            nums[2*i+1]=tmp2[tmp2.size()-1-i];
        }
    }
};
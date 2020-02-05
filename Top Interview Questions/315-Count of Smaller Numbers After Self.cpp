//count when merge 
//using pair to get the index of ret
//inplace_merge() [l,m) [m,r) all in one vector (unlike merge)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>myvec;
        myvec.reserve(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            myvec.emplace_back(nums[i],i);
        }
        vector<int>ret(myvec.size());
        merge_sort(myvec,0,myvec.size(),ret);
        return ret;
    }
    void merge_sort(vector<pair<int,int>>&nums,int l,int r,vector<int>&ret)
    {
        if(r-l<=1)
            return;
        int m=l+(r-l>>1);
        merge_sort(nums,l,m,ret);
        merge_sort(nums,m,r,ret);
        int right=m;
        for(int left=l;left<m;left++)
        {
            while(right!=r&&nums[left]>nums[right])
                right++;
            ret[nums[left].second]+=right-m;
        }
        inplace_merge(nums.begin()+l,nums.begin()+m,nums.begin()+r);
    }
};
//from right using binary search to find the index in ret vector
//the index is the count
vector<int> countSmaller(vector<int>& nums) 
{
	if (nums.empty()) return {};
	if (nums.size() == 1) return { 0 };

	vector<int> counts(nums.size(), 0);
	vector<int> sort_nums;

	sort_nums.push_back(nums[nums.size() - 1]);
	size_t i = nums.size() - 2;
	do
	{
		auto it = lower_bound(sort_nums.begin(), sort_nums.end(), nums[i]);
		counts[i] = it - sort_nums.begin();
		sort_nums.insert(it, nums[i]);
	} while (i-- != 0);
	
	return counts;
}

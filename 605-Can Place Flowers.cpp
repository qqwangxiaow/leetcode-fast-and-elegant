/*头尾插入0，判断成立则置为1*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        vector<int>temp=flowerbed;
        temp.insert(temp.begin(),0);
        temp.push_back(0);
        for(int i=1;i<temp.size()-1;i++)
        {
            if(temp[i-1]==0&&temp[i+1]==0&&temp[i]==0)
       
            {
                count++;
                temp[i]=1;
            }
        }
        if(count>=n)
            return true;
        else 
            return false;
        
        
    }
};
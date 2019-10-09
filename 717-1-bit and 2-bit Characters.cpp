//last0 and last-2 0
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count_1=0;
        for(int i=(int)bits.size()-2;i>=0&&bits[i];i--)
        {
            count_1++;
        }
        return (count_1%2==0);
    }
};




class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool c;
        for(int i=0;i<bits.size();)
        {
            if(bits[i])
            {
                c=0;
                i+=2;
            }
            else 
            {
                c=1;
                ++i;
            }
        }
        return c;
        
        
    }
};
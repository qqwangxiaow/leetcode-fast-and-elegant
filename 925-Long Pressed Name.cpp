//two pointers
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.size()&&j<typed.size())
        {
            int count1=0,count2=0;
            if(name[i]!=typed[j])
                return false;
            while(i+1<name.size()&&name[i+1]==name[i])
            {
                count1++;
                i++;
            }
            while(j+1<typed.size()&&typed[j+1]==typed[j])
            {
                count2++;
                j++;
            }
            if(count2<count1)
                return false;
            i++,j++;

        }
        if(name[name.size()-1]!=typed[typed.size()-1])
            return false;
        return true;
    }
};
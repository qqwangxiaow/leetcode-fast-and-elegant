//more concise using substr
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>myset;
        for(auto email:emails)
        {
            string begin="";
            for(auto each:email)
            {
                if(each=='+'||each=='@')
                    break;
                else if(each=='.')
                    continue;
                else begin+=each;
            }
            begin+=email.substr(email.find_first_of('@'));
            myset.insert(begin);
        }
        return myset.size();
    }
    
};
//using set straight forward
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>myset;
        for(auto each :emails)
        {
            myset.insert(change(each));

        }
        return myset.size();
    }
    string change(string str)
    {
        string ret;
        int flag=0;
        for(int i=0;i<str.size();i++)
        {
            if(!flag)
            {
                if(str[i]=='.')
                    continue;
                else if(str[i]=='+')
                {
                    i=str.find_first_of('@');
                    ret+='@';
                    flag=1;
                }
                else if(str[i]=='@')
                {
                    flag=1;
                    ret+='@';
                }
                else
                {
                    ret+=str[i];
                }
            }
            else
            {
                ret+=str[i];
            }
        }
        return ret;
    }
};
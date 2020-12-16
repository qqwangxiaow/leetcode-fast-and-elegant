//都映射成int也比较好判断
//要双射才行 不然 abba  dog dog dog dog 也算
class Solution {
public:
   bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i +1;
    }
    return i == n;
}
};

//互相映射版本
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>myvec;
        stringstream ss(s);
        string temp;
        while(ss>>temp)
        {
            myvec.push_back(temp);
        }
        if(pattern.size()!=myvec.size())
            return false;
        map<char,string>mymap1;
        map<string,char>mymap2;
        for(int i=0;i<pattern.size();i++)
        {
            if(!mymap1.count(pattern[i]))
            {
                mymap1[pattern[i]]=myvec[i];
            }
            else
            {
                if(mymap1[pattern[i]]!=myvec[i])
                    return false;
            }
        }
        for(int i=0;i<myvec.size();++i)
        {
            if(!mymap2.count(myvec[i]))
            {
                mymap2[myvec[i]]=pattern[i];
            }
            else
            {
                if(mymap2[myvec[i]]!=pattern[i])
                    return false;
            }
        }
        return true;
    }
};
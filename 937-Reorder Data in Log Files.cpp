//stable_sort
bool compare(string a, string b){
    int i = a.find(' ');
    int j = b.find(' ');
    if(!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
    {
        if(a.substr(i+1)==b.substr(j+1))
            return a.substr(0,i)<b.substr(0,j);
        return a.substr(i + 1) < b.substr(j + 1);

    }
    else{
        if(!isdigit(a[i + 1])) return true;
        return false;
    }
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),compare);
        return logs;
    }
    
};
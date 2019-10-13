//upper_bound
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(upper_bound(letters.begin(),letters.end(),target)==letters.end())
            return letters[0];
        else 
            return *upper_bound(letters.begin(),letters.end(),target);
    }
};
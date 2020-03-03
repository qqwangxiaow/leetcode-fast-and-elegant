//A B数组别搞混
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int len1=m-1,len2=n-1;
        int index=len1+len2+1;
        while(len1>=0&&len2>=0)
        {
            if(A[len1]>B[len2])
            {
                A[index--]=A[len1--];
            }
            else
            {
                A[index--]=B[len2--];
            }
        }
        while(len2>=0)
        {
            A[index--]=B[len2--];
        }

    }
};
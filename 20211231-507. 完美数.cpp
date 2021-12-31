class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
            if (i * i == num) {
                sum -= i;
            } 
            if (i == 1) {
                sum -= num;
            }

        }
        return sum == num;

    }
};
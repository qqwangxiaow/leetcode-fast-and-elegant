//考虑余数
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = numBottles;
        while (numBottles / numExchange > 0) {
            ret += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return ret;
    }
};
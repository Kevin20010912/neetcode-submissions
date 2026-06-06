class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int sum_without_carry = a ^ b;
            int carry = (unsigned)(a & b) << 1;

            a = sum_without_carry;
            b = carry;
        }
        return a;
        
        

    }
};

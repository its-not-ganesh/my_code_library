//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

 int reverse(int x) {
        int r = x, rem, ans = 0;
        while(r != 0){
            rem = r % 10;
            r = r / 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && rem > 7)) return 0;
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && rem < -8)) return 0;
            ans = (ans * 10) + rem;
        }
        // return (ans * f);
        return ans;
    }

// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
 bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int r = x, rem, ans = 0;
        while(r != 0){
            rem = r % 10;
            r = r / 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && rem > 7)) return 0;
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && rem < -8)) return 0;
            ans = (ans * 10) + rem;
        }
        if(ans == x)
            return true;
        return false;
    }

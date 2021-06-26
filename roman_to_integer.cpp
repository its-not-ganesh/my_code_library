//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 int romanToInt(string s) {
        int l = s.size(), ans = 0;
        for(int i = l-1; i >= 0; i--){
            char x = s[i];
            switch(x){
                case 'I': ans = ans + 1;
                    break;
                case 'V': ans += 5;
                    if(i != 0){
                        if(s[i-1] == 'I'){
                            ans -= 1;
                            i--;
                        }
                    }
                    break;
                case 'X': ans += 10;
                    if(i != 0){
                        if(s[i-1] == 'I'){
                            ans -= 1;
                            i--;
                        }
                    }
                    break;
                case 'L': ans += 50;
                    if(i != 0){
                        if(s[i-1] == 'X'){
                            ans -= 10;
                            i--;
                        }
                    }
                    break;
                case 'C': ans += 100;
                    if(i != 0){
                        if(s[i-1] == 'X'){
                            ans -= 10;
                            i--;
                        }
                    }
                    break;
                case 'D': ans += 500;
                    if(i != 0){
                        if(s[i-1] == 'C'){
                            ans -= 100;
                            i--;
                        }
                    }
                    break;
                case 'M': ans += 1000;
                    if(i != 0){
                        if(s[i-1] == 'C'){
                            ans -= 100;
                            i--;
                        }
                    }
                    break;
            }
        }
        return ans;
    }

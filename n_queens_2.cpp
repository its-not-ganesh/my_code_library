int count = 0; 
    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    
    void dfs(int row, int n){
        if(row == n)
        {
            count++;
            return;
        }
        for(int x = 0; x < n; x++){
            int d1 = row - x;
            int d2 = row + x;
            if(col.count(x) || diag1.count(d1) || diag2.count(d2))
                continue;
            
            col.insert(x);
            diag1.insert(d1);
            diag2.insert(d2);
            
            dfs(row+1, n);
            
            col.erase(x);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }
    
    int totalNQueens(int n) {
        count = 0;
        if(n == 1)
            return 1;
        if(n <= 3)
            return count;
        dfs(0,n);
        return count;
    }

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")
            return 0;
        unordered_set<string> visited, dead;
        dead.insert(deadends.begin(), deadends.end());

        if(dead.find("0000")!=dead.end())
            return -1;

        int minTurns=0;
        queue<string> q;
        q.push("0000");
        while(!q.empty()){
            int n = q.size();
            minTurns++;
            for(int i=0;i<n;i++){
                string curr = q.front();q.pop();
                for(int j=0;j<4;j++){
                    string f=curr, b=curr;
                    f[j] = '0' + ((f[j]-'0') + 1 )%10;
                    b[j] = '0' + ((b[j]-'0') + 9)%10;
                    if(f==target || b==target) return minTurns;

                    if(visited.find(f)==visited.end() && dead.find(f)==dead.end()){
                        q.push(f); visited.insert(f);}
                    if(visited.find(b)==visited.end() && dead.find(b)==dead.end()){
                        q.push(b); visited.insert(b);}
                }
            }
        }
        return -1;
    }
};

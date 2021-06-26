class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int count=0, i=0, boxes=0;
        while(truckSize>0 && i<boxTypes.size()){
            count+=min(boxTypes[i][0]boxTypes[i][1],truckSizeboxTypes[i][1]);
            boxes=min(boxTypes[i][0], truckSize);
            truckSize-=boxes;
            i++;
        }
        return count;
    }
};

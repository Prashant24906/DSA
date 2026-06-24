class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = n-k;
        int r = l;
        int sum = 0;
        int maxi = 0;
        for(int i = 0;i<k;i++){
            sum+=cardPoints[r];
            maxi = max(maxi,sum);
            r++;
        }
        for(int i = 0;i<k;i++){
            sum+=cardPoints[(r%n)];
            sum-=cardPoints[(l%n)];
            r++;
            l++;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};

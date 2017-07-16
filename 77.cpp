class Solution {
  public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
      // write your code here
      vector<vector<int>> temp (A.length(), vector<int>(B.length(), 0));
      int max_val = 0;
      for(int i=0; i < temp.size(); i++){
        for(int j=0; j < temp[i].size(); j++){
          if(A[i] == B[j]) {
            if(i-1 < 0 || j-1 < 0)  temp[i][j] = 1;
            else    temp[i][j] = temp[i - 1][j - 1] + 1;
          }
          else
          {
            temp[i][j] = max((j-1>=0)?temp[i][j-1]:0,(i-1>=0)?temp[i-1][j]:0);
          }
          if(temp[i][j] > max_val){
            max_val = temp[i][j];
          }
        }
      }
      return max_val;
    }
};


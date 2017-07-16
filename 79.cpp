class Solution {
  public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
      if(A.length() == 0 || B.length() == 0)  return 0;
      // write your code here
      vector<vector<int>> matrix (A.length(), vector<int>(B.length(),0));
      int max = 0;
      //int matrix[A.length()][B.length()] = {0};
      for (int i = 0; i < A.length(); i++) {
        for(int j=0; j<B.length(); j++){
          if(A[i] == B[j]){
            if(i-1 < 0 || j-1 < 0)  matrix[i][j] = 1;
            else    matrix[i][j] = matrix[i-1][j-1] + 1;
          }
          if(matrix[i][j] > max)  max = matrix[i][j];
        }
      }
      return max;
    }
};


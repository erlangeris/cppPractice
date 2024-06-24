#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int editDistance(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (memo[i][j] != -1) return memo[i][j];
    
    if (word1[i-1] == word2[j-1]) {
        memo[i][j] = editDistance(word1, word2, i-1, j-1, memo);
    } else {
        memo[i][j] = 1 + min({editDistance(word1, word2, i-1, j, memo), // Delete
                              editDistance(word1, word2, i, j-1, memo), // Insert
                              editDistance(word1, word2, i-1, j-1, memo)}); // Replace
    }
    return memo[i][j];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    cout << "Minimum edit distance = " << editDistance(word1, word2, word1.size(), word2.size(), memo) << endl;
    return 0;
}

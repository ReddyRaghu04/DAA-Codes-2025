#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(const string& str1, const string& str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    int lcsLength = longestCommonSubsequence(str1, str2);

    cout << "Length of longest common subsequence is " 
         << lcsLength << endl;

    return 0;
}

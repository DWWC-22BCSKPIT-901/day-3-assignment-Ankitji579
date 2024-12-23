/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

*/ 

#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    // Create a DP table
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true; // Both strings are empty

    // Handle patterns with '*'
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2]; // '*' matches zero occurrences
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                // Characters match, or '.' matches any character
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' matches zero occurrences or one/more of the preceding character
                dp[i][j] = dp[i][j - 2] || 
                           (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s, p;
    cout << "Enter the string s: ";
    cin >> s;
    cout << "Enter the pattern p: ";
    cin >> p;

    if (isMatch(s, p)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

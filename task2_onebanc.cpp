#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class onebanc {
public:
    static int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

        for (int i = 0; i <= l1; i++) {
            dp[i][0] = i * Cd;
        }
        for (int j = 0; j <= l2; j++) {
            dp[0][j] = j * Ci;
        }

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i][j - 1] + Ci, min(dp[i - 1][j] + Cd, dp[i - 1][j - 1] + Cs));
            }
        }

        return dp[l1][l2];
    }

    static int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
};

int main() {
    cout << "Output: " << onebanc::EditDistance("kitten", "sitting", 1, 2, 3) << endl;
    cout << "Output: " << onebanc::EditDistance("flaw", "lawn", 2, 2, 1) << endl;
    cout << "Output: " << onebanc::EditDistance("algorithm", "logarithm", 1, 3, 2) << endl;
    return 0;
}

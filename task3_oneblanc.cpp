#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SpellChecker {
public:
    static int calculateEditDistance(const string& original, const string& target, int insertCost, int deleteCost, int substituteCost) {
        int originalLength = original.length();
        int targetLength = target.length();
        vector<vector<int>> dp(originalLength + 1, vector<int>(targetLength + 1));

        for (int i = 0; i <= originalLength; i++) {
            dp[i][0] = i * deleteCost;
        }
        for (int j = 0; j <= targetLength; j++) {
            dp[0][j] = j * insertCost;
        }

        for (int i = 1; i <= originalLength; i++) {
            for (int j = 1; j <= targetLength; j++) {
                if (original[i - 1] == target[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({ dp[i][j - 1] + insertCost,
                                     dp[i - 1][j] + deleteCost,
                                     dp[i - 1][j - 1] + substituteCost });
                }
            }
        }
        return dp[originalLength][targetLength];
    }
};

int main() {
    vector<string> dictionary = {"cred", "bet", "shat", "that", "brad", "cart", "brat", "card"};
    string input = "dat";
    int insertCost = 1;
    int deleteCost = 1;
    int substituteCost = 1;

    int minDistance = INT_MAX;
    vector<string> suggestions;

    for (const string& word : dictionary) {
        int dist = SpellChecker::calculateEditDistance(input, word, insertCost, deleteCost, substituteCost);
        if (dist < minDistance) {
            minDistance = dist;
        }
    }

    for (const string& word : dictionary) {
        int dist = SpellChecker::calculateEditDistance(input, word, insertCost, deleteCost, substituteCost);
        if (dist == minDistance) {
            suggestions.push_back(word);
        }
    }

    cout  << input << ": ";
    for (const string& word : suggestions) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

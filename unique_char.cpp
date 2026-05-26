#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    // Create an unordered_map to store the frequency of each character
    unordered_map<char, int> charCounts;

    // Pass 1: Tally up the characters
    for (char c : s) {
        charCounts[c]++;
    }

    // Pass 2: Check the string from left to right to find the first '1'
    for (int i = 0; i < s.length(); i++) {
        if (charCounts[s[i]] == 1) {
            return i; // Return the index immediately upon finding it
        }
    }

    return -1; // If no unique character exists
}

int main() {
    string test1 = "leetcode";
    string test2 = "loveleetcode";

    cout << "Test 1 ('leetcode'): " << firstUniqChar(test1) << endl; // Expected: 0 ('l')
    cout << "Test 2 ('loveleetcode'): " << firstUniqChar(test2) << endl; // Expected: 2 ('v')

    return 0;
}

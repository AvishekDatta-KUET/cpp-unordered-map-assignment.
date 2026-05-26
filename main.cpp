#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    // Create a static lookup map for Roman numerals
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int n = s.length();

    // Loop through the string
    for (int i = 0; i < n; i++) {
        // Rule: If current numeral is smaller than the NEXT numeral, subtract it
        if (i < n - 1 && romanMap[s[i]] < romanMap[s[i+1]]) {
            total -= romanMap[s[i]];
        }
        // Otherwise, just add it to the total
        else {
            total += romanMap[s[i]];
        }
    }

    return total;
}

int main() {
    string roman1 = "XIV";
    string roman2 = "MCMXCIV";

    cout << roman1 << " in integer is: " << romanToInt(roman1) << endl; // Expected: 14
    cout << roman2 << " in integer is: " << romanToInt(roman2) << endl; // Expected: 1994

    return 0;
}

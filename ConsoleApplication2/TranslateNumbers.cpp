#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> split(string str, char del) {
    vector<string> result;
    str += del;
    int pos = str.find(del);
    while (pos != string::npos)
    {
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + 1);
        pos = str.find(del);
    }
    return result;
}
vector<int> splitNums(string str, char del)
{
    vector<int> result;
    str += del;
    int pos = str.find(del);

    while (pos != string::npos)
    {
        int num = stoi(str.substr(0, pos));
        result.push_back(num);
        str.erase(0, pos + 1);
        pos = str.find(del);
    }
    return result;
}

int translateNumbers(vector<string> number)
{
    std::map<string, int> dict = {
    {"negative", -1},
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90},
    {"hundred", 100},
    {"thousand", 1000},
    {"million", 1000000}
    };
    int result = 0, current = 0;
    bool isNegative = false;
    std::list <int> mapped;
    for (auto it = number.begin(); it != number.end(); ++it) {
        if (dict.find(*it) != dict.end()) {
            mapped.push_back(dict[*it]);
        }
    }
    for (const auto word : number)
    {
        if (word == "negative") {
            isNegative = true;
            continue;
        }

        if (dict.find(word) != dict.end()) {
            int value = dict[word];

            if (value == 100) {
                current *= value;
            }
            else if (value >= 1000) {
                current *= value;
                result += current;
                current = 0;
            }
            else {
                current += value;
            }
        }
    }
    result += current;
    if (isNegative) {
        result *= -1;
    }
    return result;
}
int main() {
    string line;
    while (getline(cin, line)) {
        char del = ' ';
        auto input = split(line, del);
        cout << translateNumbers(input) << endl;
    }
    return 0;
}

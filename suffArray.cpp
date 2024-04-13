#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a < b;
}

vector<int> buildSuffixArray(const string& text) {
    int n = text.size();
    vector<string> suffixes(n);

    for (int i = 0; i < n; ++i) {
        suffixes[i] = text.substr(i, n - i);
    }

    vector<int> suffixArray(n);
    for (int i = 0; i < n; ++i) {
        suffixArray[i] = i;
    }

    sort(suffixArray.begin(), suffixArray.end(), [&suffixes](int a, int b) {
        return compare(suffixes[a], suffixes[b]);
    });

    return suffixArray;
}

int main() {
    string text;
    cout << "Enter a string: ";
    cin >> text;

    vector<int> suffixArray = buildSuffixArray(text);

    cout << "Suffix Array for '" << text << "':\n";
    for (int index : suffixArray) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string str, str1;
int i = 0, j = 0;

bool is_end() {
    return i < str.length() || j < str1.length();
}

int main() {
    cin >> str >> str1;
    while (is_end()) {
        if (str[i] == str1[j]) {
            i++;
            j++;
        } else if (str[i] != str1[j] && str1[j] == str1[j - 1] && j > 0) {
            j++;
        } else {
            break;
        }
    }

    cout << (is_end() ? 0 : 1);
    return 0;
}
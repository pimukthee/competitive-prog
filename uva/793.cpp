#include <bits/stdc++.h>

using namespace std;

int head[1000000+10];

int findhead(int x) {
    if (head[x] == x) {
        return x;
    } else {
        return head[x] = findhead(head[x]);
    }
}

int main() {
    int c, n;
    string input;
    cin >> c;
    while (c--) {
        cin >> n;

        for (int i = 1; i <= n; ++i) head[i] = i;
        int success = 0, unsuccess = 0;

        getline(cin, input);
        while (getline(cin, input)) {
            if (input.empty()) break;
            auto pos = input.find_last_of(" ");
            int u = stoi(input.substr(2, (int)pos - 2));
            int v = stoi(input.substr(pos+1));

            u = findhead(u);
            v = findhead(v);

            if (input[0] == 'c') {
                head[v] = u;
            } else {
                if (u == v) {
                    ++success;
                } else {
                    ++unsuccess;
                }
            }
        }

        cout << success << "," << unsuccess << endl;
        if (c) cout << endl;
    }
    return 0;
}



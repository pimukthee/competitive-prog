#include <bits/stdc++.h>

using namespace std;

stack <char> stk;

bool is_open(char c) {
  return c == '<' || c == '{' || c == '[' || c == '(';
}

bool is_pair(char c, char b) {
  return (c == '<' && b == '>') || (c == '{' && b == '}') || (c == '[' && b == ']') || (c == '(' && b == ')');
}

int main() {
  string str;
  int ans = 0;

  cin >> str;
  for (auto& c : str) {
    if (is_open(c)){
        stk.push(c);
    } else {
      if (!stk.empty()) {
        //cout << c << " " << stk.top() << endl;
        //cout << is_pair(c, stk.top());
        ans += !is_pair(stk.top(), c);
        stk.pop();
      } else {
        cout << "Impossible";
        break;
      }
    }
  }

  cout << ans;

  return 0;
}

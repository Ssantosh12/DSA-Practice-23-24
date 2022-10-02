#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, i;
        scanf("%d", &n);
        string s;
        cin >> s;
        //now we use stack for finding the unbalanced brackets
        stack<char> stk;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push('(');
            else if (!stk.empty())
                stk.pop();
        }
        //finally the remaining unbalanced opening brackets in the stack will tell us the number of moves required
        
        cout << stk.size() << endl;

        //NOTE : the no. of unbalanced closing brackets must be equal to no. of unbalanced opening brackets 
        //       if both are n/2 and n/2 in numbers (i.e same in no. )
    }
}

// #include <iostream>
// //LIFO
// #include <stack>
// using namespace std;

// int main() {
//     stack<char> numbers;
//     string bracket = "[{)}]";

//     for (int i = 0; i < bracket.size(); i++)
//     {
//         if (bracket[i] == '[' || bracket[i] == '{' || bracket[i] == '('  )
//         {
//             numbers.push(bracket[i]);
//             cout << bracket[i];
//         }        
//         else if (numbers.top() == '(' && bracket[i] == ')' )
//         {
//             numbers.pop();
//         }
//         else if (numbers.top() == '{' && bracket[i] == '}' )
//         {
//             numbers.pop();
//         }
//         else if (numbers.top() == '[' && bracket[i] == ']' )
//         {
//             numbers.pop();
//         }
//     }

//     if(numbers.empty()){
//         cout << "right order";
//     }else{
//         cout << "wrong order";
//     }

//     return 0;
// }

//✅Did first one by ownself, which had some loopholes.Improved from internet

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    stack<char> st;
    string bracket = "[{()}]";

    unordered_map<char, char> matching = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : bracket) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else {
            if (st.empty() || st.top() != matching[ch]) {
                cout << "wrong order\n";
                return 0;
            }
            st.pop();
        }
    }

    if (st.empty()) {
        cout << "right order\n";
    } else {
        cout << "wrong order\n";
    }

    return 0;
}

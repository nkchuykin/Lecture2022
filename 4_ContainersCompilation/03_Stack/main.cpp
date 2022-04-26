#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
    string right = "((()))";
    string wrong = "(())))";

    stack<char> stack1;
    stack<char,deque<char>> stack2;
    stack<char,vector<char>> stack3;
    stack<char,list<char>> stack4;

    for (char ch : wrong) {
        if (ch == '('){
            stack1.push(ch);
        } else{
            if (stack1.empty())
            {
                cout << "NO";
                return 0;
            }
            stack1.pop();
        }
    }
    if (!stack1.empty())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

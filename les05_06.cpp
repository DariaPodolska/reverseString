#include <iostream>
#include <sstream>
#include <conio.h>
#include <stack>
using namespace std;

string reverse(string word);
string reverseLines(string text);
string reverseWords(string text);

int main()
{
    cout << "Text & Word Reverse" << endl << endl;
    string text = R"(Yesterday All my troubles seemed so far away Now it looks
                     as though they're here to stay Oh I believe in yesterday)";
    cout << "Source text:" << endl;
    cout << text << endl << endl;
    cout << "Reverse text:" << endl;
    cout << reverse(text) << endl << endl;
    cout << "Reverse lines:" << endl;;
    cout << reverseLines(text) << endl;
    cout << "Reverse words:" << endl;
    cout << reverseWords(text);
    cout << endl;
    _getch();
    return 0;
}

string reverse(string text)
{
    stack<char> stack;
    for (auto it : text)
    {
        stack.push(it);
    }
    string result;
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    return result;
}

string reverseLines(string text)
{
    stringstream textStream;
    textStream << text;
    stack<string> stack;
    string line;
    while (getline(textStream, line))
    {
        stringstream lineStream;
        lineStream << line;
        string word;
        stack.push("\n");
        while (lineStream >> word)
        {
            stack.push(" ");
            stack.push(word);
        }
    }
    string result;
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    return result;
}

string reverseWords(string text)
{
    stringstream textStream;
    textStream << text;
    string line;
    string result;
    while (getline(textStream, line))
    {
        stringstream lineStream;
        lineStream << line;
        string word;
        while (lineStream >> word)
        {
            result += reverse(word);
            result += " ";
        }
        result += "\n";
    }
    return result;
}
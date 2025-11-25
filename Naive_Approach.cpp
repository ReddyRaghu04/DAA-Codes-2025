#include <iostream>
using namespace std;

void naive_pattern_match(string &text, string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (n < m)
    {
        cout << "Invalid inputs" << endl;
        return;
    }

    for (int s = 0; s <= n - m; s++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (text[s + j] != pattern[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            cout << "Pattern available at: " << s << endl;
        }
    }
}

int main()
{
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    naive_pattern_match(text, pattern);  
    return 0;
}

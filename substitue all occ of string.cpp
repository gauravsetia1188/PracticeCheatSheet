#include <iostream>

using namespace std;

void find_and_replace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

int main()
{
    string text;

    // simple replace
    text = "i have a blue house and a blue car";
    cout << "string:  " << text << endl;
    find_and_replace(text, "blue", "red");
    cout << "replace: " << text << endl;

    cout << endl;

    // simple replace 2
    text = "i love apple";
    cout << "string:  " << text << endl;
    find_and_replace(text, "apple", "banana");
    cout << "replace: " << text << endl;

    cout << endl;

    // simple replace 3
    text = "some-words-separated-by-hyphen";
    cout << "string:  " << text << endl;
    find_and_replace(text, "-", "_");
    find_and_replace(text, "hyphen", "underscore");
    cout << "replace: " << text << endl;

    cout << endl;

    // replace with empty string
    text = "this string has an is missing";
    cout << "string:  " << text << endl;
    find_and_replace(text, "is", "");
    cout << "replace: " << text << endl;

    cout << endl;

    // replace with space
    text = "hello;world;";
    cout << "string:  " << text << endl;
    find_and_replace(text, ";", " ");
    cout << "replace: " << text << endl;

    return 0;
}

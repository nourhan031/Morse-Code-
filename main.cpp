#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

map< char, string > ascii_to_morse =
{
{'A',".-"},
{'B',"-..."},
{'C',"-.-."},
{'D',"-.."},
{'E',"."},
{'F',"..-."},
{'G',"--."},
{'H',"...."},
{'I',".."},
{'J',".---"},
{'K',"-.-"},
{'L',".-.."},
{'M',"--"},
{'N',"-."},
{'O',"---"},
{'P',".--."},
{'Q',"--.-"},
{'R',".-."},
{'S',"..."},
{'T',"-"},
{'U',"..-"},
{'V',"...-"},
{'W',".--"},
{'X',"-..-"},
{'Y',"-.--"},
{'Z',"--.."},
{'0',"-----"},
{'1',".----"},
{'2',"..---"},
{'3',"...--"},
{'4',"....-"},
{'5',"....."},
{'6',"-...."},
{'7',"--..."},
{'8',"---.."},
{'9',"----."},
{'.',".-.-.-"},
{',',"--..--"},
{'?',"..--.."},
{'=',"-...-"},
};

map< string, char > morse_to_ascii;

int main()
{
    for (auto kv : ascii_to_morse)
        morse_to_ascii[kv.second] = kv.first;
    char option;
    string word, code, decryp;
    istringstream scin("");

    cout << "What would you like to do?\n";
    cout << "1- Cipher a message\n";
    cout << "2- Decipher a message\n";
    cout << "3- End\n";
    cin >> option;
    cin.get();

    if (option == '1') {
        cout << "Enter a word to cipher: ";
        getline(cin, word);

        for (char letter : word) {
            letter = toupper(letter);//upper case
            if (letter != ' ') {
                cout << ascii_to_morse[letter] << ' ';
            }
            else {
                cout << '\t';
            }

        }
    }


    else if (option == '2') {
       cout << "Enter an encrypted message: ";

        getline(cin, code);
        scin.str(code);

        scin >> decryp;
        int c = 0;
        while (scin) {
            if (c == 3) {
                cout << " ";
            }

            for (char letter = 65; letter < 91; letter++) {
                if (ascii_to_morse[letter] == decryp) {
                    cout << letter;
                }
            }
            scin >> decryp;

            if (decryp == " ") {
                c++;
            }
            else {
                c = 0;
            }
        }
        cout << endl;


    }
}


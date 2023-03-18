#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <clocale>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#ifdef _DEBUG
#undef _DEBUG
#include <python.h>
#define _DEBUG
#else
#include <python.h>
#endif

#include <typeinfo>

using namespace std;

// q - function to close the application.

void command_q() {
    exit(0);
}

int main() {
    setlocale(LC_ALL, "Turkish");
    string command;

    cout << "Shell Apllication\n Version 0.0.1\t\t Use q command to quit" << endl;

    // Shell application loop.
    std::vector<std::string> data = { "q","read" };
    while (true) {
        cout << "\n> ";
        getline(cin, command);

        // q - command to exit the application.
        if (command == "q") {
            command_q();
        }
        // read - print the contents of the specified file.
        else if (command.substr(0, 4) == "read")
        {

            if (command.length() > 5 && command.substr(5, 2) == "-n")
            {  
                string NotePad = "notepad " + command.substr(8);
                    system(NotePad.c_str());
            }
            else if (command == "read" || command.length() > 5 && command.substr(5, 2) == "-h")

            {
                cout << "Komut kullanımı:\n";
                cout << "read <filename> \tDosyanın içeriğini yazdırır.\n";
                cout << "Parametreler:\n";
                cout << "read -n <filename>\tDosyayı Not Defteri ile açar.";
            }
            else {
                string r = command.substr(5);
                std::ifstream f(r);
                if (f.is_open())
                    std::cout << f.rdbuf();
            }

        }

        //Check if the command is in special commands.
        // auto it = std::find(data.begin(), data.end(), command);

        // If the command is not in special commands, run it with the command prompt.
        //if (std::find(data.begin(), data.end(), command) == data.end()) {
        else {
            int result = system(command.c_str());
        }
    }

    return 0;
}

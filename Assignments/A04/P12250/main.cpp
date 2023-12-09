#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    // Mapping greetings to languages
    map<string, string> languageMap = {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}
    };

    string word;
    int caseNum = 1;
    while (inputFile >> word && word != "#") {
        string language = languageMap.count(word) ? languageMap[word] : "UNKNOWN";
        outputFile << "Case " << caseNum++ << ": " << language << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

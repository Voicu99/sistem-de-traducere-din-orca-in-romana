// sistem de traducere din orca in romana.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

std::string toOrca(const std::string& word) {
    if (word.empty()) {
        return "";
    }

    std::string translatedWord = word.substr(1) + word[0]; // Mutam prima litera la sfarsit
    if (!isVowel(word[0])) {
        translatedWord += "ay"; // Adaugam "ay" la sfarsitul cuvantului, daca prima litera nu este o vocala
    }
    else {
        translatedWord += "yay"; // Adaugam "yay" la sfarsitul cuvantului, daca prima litera este o vocala
    }

    return translatedWord;
}

std::string translateToOrca(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::string word;
    std::string translatedSentence = "";

    while (iss >> word) {
        translatedSentence += toOrca(word) + " ";
    }

    return translatedSentence;
}

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);

    std::string translatedSentence = translateToOrca(sentence);
    std::cout << translatedSentence << std::endl;

    return 0;
}

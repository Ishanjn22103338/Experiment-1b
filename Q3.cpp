#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

struct WordCount {
    char word[100];
    int count;
};

int findWordIndex(const vector<WordCount>& words, const string& word) {
    for (int i = 0; i < words.size(); ++i)
        if (strcmp(words[i].word, word.c_str()) == 0) 
            return i;
    return -1;
}

int main() {
    char paragraph[10000];
    vector<WordCount> wordCounts;
    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, sizeof(paragraph));
    char* token = strtok(paragraph, " \n\t");
    while (token) {
        for (char* p = token; *p; ++p) 
            *p = tolower(*p);
        int index = findWordIndex(wordCounts, token);
        if (index == -1) {
            WordCount wc;
            strncpy(wc.word, token, sizeof(wc.word) - 1);
            wc.word[sizeof(wc.word) - 1] = '\0';
            wc.count = 1;
            wordCounts.push_back(wc);
        } else {
            ++wordCounts[index].count;
        }
        token = strtok(NULL, " \n\t");
    }
    cout << "Word frequencies:\n";
    for (const auto& wc : wordCounts)
        cout << wc.word << ": " << wc.count << endl;
    return 0;
}

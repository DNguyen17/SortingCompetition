#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

class SortingCompetition
{
private:
    //private data members
    ifstream fin;
    ofstream fout;
    int setDataSize; //for switching algorithms based on size
    vector<char*> words;
    char** words2;
    int previousWordCount;
    int wordCount;


    //vector<char*> words2;

    //private functions
        //setter,getters
    void SortingCompetition::setSetDataSize(int newSize);
    void SortingCompetition::setSetDataSize(int newSize);

    vector<char*> SortingCompetition::getWords(void);

    char** SortingCompetition::getWords2(void);


    void SortingCompetition::setWords2(char** newWords2);

    void SortingCompetition::setWordCount(int count);

    int SortingCompetition::getWordCount(void);

    void SortingCompetition::setPreviousWordCount(int count);


    int SortingCompetition::getPreviousWordCount(void);

    int compareWords(char* one, char* str2);
    void quicksort(vector<char*>& wordArr, size_t start, size_t end);


public:
    SortingCompetition(const string& inputFileName);
    ~SortingcCompetition();
    void setFileName(const string& inputFileName);
    bool readData();
    bool prepareData();
    void sortData();
    void outputData(const string& outputFileName);
};


#endif // SORTINGCOMPETITION_H

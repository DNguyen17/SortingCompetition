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
    ifstream fin;
    ofstream fout;
    int setDataSize; //for switching algorithms based on size
    vector<char*> words;
    vector<char*> words2;
    int compareWords(char* one, char* str2);
    void quicksort(vector<char*>& wordArr, size_t start, size_t end);


public:
    SortingCompetition(const string& inputFileName);
    void setFileName(const string& inputFileName);
    bool readData();
    bool prepareData();
    void sortData();
    void outputData(const string& outputFileName);
};

#endif // SORTINGCOMPETITION_H

#include "SortingCompetition.h"

SortingCompetition::SortingCompetition(const string &inputFileName)
{
    setFileName(inputFileName);
}
void SortingCompetition::setFileName(const string& inputFileName)
{
    fin.close();
    fin.open(inputFileName.c_str(), ios::in);
    if (!fin.good())
    {
        cerr << "file could not be opened" << endl;
    }
}

bool SortingCompetition::readData()
{
    for (size_t i = 0; i < words.size(); i++)
    {
        delete[] words.at(i);
    }
    words.clear();

    string buffer;
    while(!fin.eof())
    {
        fin >> buffer;
        words.push_back(new char[buffer.length()+1]);
        strcpy(words.at(words.size()-1),buffer.c_str());
    }
    fin.close();
    return true;
}

bool SortingCompetition::prepareData()
{
    bool x = false;

    for(size_t i = 0; i < words2.size(); i++)
    {
        delete[] words2.at(i);
    }
    words2.clear();

    //copy data from original data structure over
    for(size_t i = 0; i < words.size(); i++)
    {
        words2.push_back(new char[strlen(words.at(i))+1]);
        strcpy(words2.at(i), words.at(i));
    }
    x = true;

    return x;
}

void SortingCompetition::sortData()
{

}

void SortingCompetition::outputData(const string& outputFileName)
{
    //output sorted data (in words2)
    fout.open(outputFileName.c_str(), ios::out);
    if(!fout.good())
    {
        cerr << "file could not be opened" << endl;
    }

    for(size_t i = 0; i < words2.size(); i++)
    {
        fout << words2.at(i) << " " << strlen(words2.at(i)) << endl;
    }
    fout.close();

}

//PRIVATE FUNCTIONS IMPLEMENTATION

int SortingCompetition::compareWords(char* str1, char* str2)
{
    if (strlen(str1) < strlen(str2))
    {
        return -1;
    }

    else if(strlen(str1) > strlen(str2))
    {
        return 1;
    }
    else
    {
        return strcmp(str1, str2);
    }
}

/*void quicksort(vector<char*>& wordArr, size_t start, size_t end)
{

}*/

#include "SortingCompetition.h"

//Constructor and Destructor
SortingCompetition::SortingCompetition(const string &inputFileName)
{
    setFileName(inputFileName);
   //initialize private data members
    words2 = NULL;
    //Don't need to initialize the vector???
    setDataSize = 0;
    wordCount = 0;
//    previousWordCount = 0;


}
//need destructor
SortingCompetition::~SortingCompetition(){
    //deletes dynamically allocated memory
    //**********//
}

//setters and getters

//Will close current ifstream member object incase still open
//and sets object to open new input specified
void SortingCompetition::setFileName(const string& inputFileName)
{
    fin.close();
    fin.open(inputFileName.c_str(), ios::in);
    if (!fin.good())
    {
        cerr << "file could not be opened" << endl;
    }
}
void SortingCompetition::setSetDataSize(int newSize){
    setDataSize = newSize;
}

int SortingCompetition::getSetDataSize(){
    return setDataSize;

}

//getter for storage containers
vector<char*> SortingCompetition::getWords(void){
   return words;
}

char** SortingCompetition::getWords2(void){
    return words2;
}

void SortingCompetition::setWords2(char** newWords2){
    words2 = newWords2;
}

void SortingCompetition::setWordCount(int count){
    wordCount = count;

}

int SortingCompetition::getWordCount(void){
    return wordCount;
}

/*
void SortingCompetition::setPreviousWordCount(int count){
    previousWordCount = count;
}

int SortingCompetition::getPreviousWordCount(void){
    return previousWordCount;
}
*/

/* function will process all words in input file and put them
 * sequentially in a vector in the order they were in in the input file
 * */

bool SortingCompetition::readData(){

    for(size_t i = 0; i < getWordCount(); i++)
    {
        delete[] words2[i];
    }
    delete[] words2;

/*   //store off the size of the previous wordCount
    setPreviousWordCount(words.size());*/

    //clear all existing words in the vector in order that
    //if readData run multiple times that words are not just concatenated
    //onto the end of the existed vector from a previous run
    for (size_t i = 0; i < words.size(); i++)
    {
        delete[] words.at(i);
    }
    words.clear();


    //collect and store words from input file
    string buffer;
    while(!fin.eof())
    {
        fin >> buffer;
        //store pointer to a dynamically allocated
        //char* at end of vector
        words.push_back(new char[buffer.length()+1]);
        //copy word into chra* pointer
        strcpy(words.at(words.size()-1),buffer.c_str());
    }

    //set wordcount after input function finishes
    setWordCount(words.size());
    //close input file
    fin.close();
    //function complete so return true as success
    return true;
}

//function copies values stored in the vector into an array of char*
//The char* are length prefixed in order to eliminate the need
//to used strlen when sorting. The copy of the words list is first
//cleared to prevent any overlap from one run to the next
bool SortingCompetition::prepareData(){

    bool x = false;


    //copy data from original data structure over
    /* Loop first finds the length of the word, and then
     * creates length prefixed strings
     * */

    //create initialized char** that will hold the copied data
    //words2 = new char*[10];
    //initialize elements of words2
/*    for(int k = 0;k<10;k++){
        words2[k] = NULL;
    }
*/
    //counter to help with resizing
//    int count = 0;

    words2 = new char*[words.size()];

    for(size_t i = 0; i < words.size(); i++)
    {
        //determine length of string and store as character
        char length = strlen(words.at(i));
        //store the length of the string as an ascii character

        //need new string with 2 elements longer than length of word
        //for null termination and the length prefix
        char* newString = new char[length+2];
        //store length of word as fist character as char
        newString[0] = length;
        //add prefix to beginning of word
        strcpy(&(newString[1]),words[i]);

        //add new length prefixed string to end of words2
        words2[i] = newString;
/*
        count++;
        //resize if list is full
        if(count>=10){
            resize(i);
            count = 0;
        }
*/
    }

    //if no errors occured return true
    x = true;

    return x;
}

/* function resizes the dynamically created copy of the words
 * list */

/*
void SortingCompetition::resize(int currentSize){
   //dynammically create new list for words2
    char** tempWords2 = new char*[currentSize+1+10];

    //cycle through and copy the old pointers to new list

    for(int i = 0;i<getWordCount();i++){
      tempWords2[i] = words2[i];
    }

    //initialize the additional spaces of longer list
    for(int j = getWordCount();j<getWordCount()+10;j++){
        tempWords2[j] = NULL;
    }

    //free memory from old list
    delete[] words2;

    //reassign lists to temporary list created
    words2 = tempWords2;

}
*/

/*
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
*/
void SortingCompetition::sortData()
{
    bubbleSort();
}

void SortingCompetition::outputData(const string& outputFileName)
{
    cout<<"inside outputData"<<endl;
    //output sorted data (in words2)
    fout.open(outputFileName.c_str(), ios::out);
    if(!fout.good())
    {
        cerr << "file could not be opened" << endl;
    }

    for(size_t i = 0; i < wordCount; i++)
    {
        cout << &(words2[i][1]) << " " << words2[i][0]<< endl;
    }
    fout.close();

}

//PRIVATE FUNCTIONS IMPLEMENTATION

int SortingCompetition::compareWords(char* str1, char* str2)
{
    if (str1[0] > str2[0])
    {
        return -1;
    }

    else if(str1[0] > str2[0])
    {
        return 1;
    }
    else
    {
        return strcmp(&(str1[1]), &(str2[1]));
    }

}

/*void quicksort(vector<char*>& wordArr, size_t start, size_t end)
{

}*/

void SortingCompetition::bubbleSort(){
    for(int j = 0; j<getWordCount();j++){
        for(int y = 0;y<(getWordCount()-1);y++){
            if (compareWords(words2[y],words2[y+1])== 1){
                char* temp1 =words2[y+1];
                words2[y+1]=words2[y];
                words[y] = temp1;

            }
        }

    }
}


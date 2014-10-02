#include <iostream>
#include <chrono>
#include <ctime>
#include "SortingCompetition.h"

using namespace std;

int main()
{
    SortingCompetition sorter("input.txt");

    sorter.readData();

    sorter.prepareData();

    //declare 2 time points
    std::chrono::time_point<std::chrono::system_clock> start, end;

    //store time (now()) in start
    start = std::chrono::system_clock::now();

    //execute sort
    sorter.sortData();

    //store time(now()) in end
    end = std::chrono::system_clock::now();

    //get No. of seconds elapsed & output duration
    //need to do this multiple times & get average
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << "s" << endl;

    sorter.outputData("output.txt");
    return 0;
}


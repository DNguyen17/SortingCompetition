//Danh Nguyen
//Brendan Celii

#include <iostream>
#include <chrono>
#include <ctime>
#include "SortingCompetition.h"

using namespace std;

int main()
{
    srand(time(0));
    SortingCompetition sorter("input2.txt");
    //store data from input file
    sorter.readData();
    //prepare copy of data to be sorted
    sorter.prepareData();

    //declare 2 time points
    std::chrono::time_point<std::chrono::system_clock> start, end;

    //store current time (now()) in start
    start = std::chrono::system_clock::now();

    //execute sort on copy of data
    sorter.sortData();

    //store time(now()) in end
    end = std::chrono::system_clock::now();

    //get No. of seconds elapsed & output duration
    //need to do this multiple times & get average
    std::chrono::duration<double> elapsed_seconds = end-start;
    //std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout //<< "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << "s" << endl;

    //output sorted data to output file
    //sorter.outputData("output.txt");
    return 0;
}

/*
 * SortingCompetition main driver
 * CSE 2341
 * Spring 2013
 * Written by Jason Murphy


#include <iostream>
#include <chrono>
#include "SortingCompetition.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Invalid arguments" << std::endl;
        std::cerr << "Usage: ./a.out <input file> <output file>" << std::endl;
        return 1;
    }

    //Number of times to run sort
    const int NUM_REPS = 5;
    unsigned int totalMilliseconds = 0;

    //Create the sorter object and load the data from a file
    SortingCompetition sorter(argv[1]);
    if (!sorter.readData())
    {
        std::cerr << "Error reading data" << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_REPS; i++)
    {
        //Load the unsorted data into our sorter object
        if (!sorter.prepareData())
        {
            std::cerr << "Error preparing data" << std::endl;
            return 1;
        }

        //Sort the data, and time the results
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        sorter.sortData();
        end = std::chrono::system_clock::now();
        unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        totalMilliseconds += milliseconds;
        std::cout << "Sort #" << i+1 << " Time: " << milliseconds << " milliseconds" << std::endl;
    }

    //Print sorted data to a file, and print the avg.
    sorter.outputData(argv[2]);
    std::cout << "Average sorting time: " << totalMilliseconds / NUM_REPS << " milliseconds" << std::endl;
}
*/

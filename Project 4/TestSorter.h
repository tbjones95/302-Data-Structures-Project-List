// Program Information ////////////////////////////////////////////////////////
/**
 * @file TestSorter.h
 *
 * @author Tanner Jones
 *
 * @brief Header file for the Test Sorter class
 *
 * @details Specifies all data of the Test Sorter class,
 *          along with the constructor
 *
 * @version 1.00 (23 September 2015))
 *
 * @Note Requires TestSorter.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////
#ifndef PROJECT_4_TESTSORTER_H
#define PROJECT_4_TESTSORTER_H

// Header files ///////////////////////////////////////////////////////////////
#include "SorterClass.cpp"
#include "SimpleVector.cpp"
#include "DateType.h"

// Class constants ////////////////////////////////////////////////////////////

// Class definition ///////////////////////////////////////////////////////////
class TestSorter : public SorterClass<DateType>
{
    public:
        TestSorter();
        ~TestSorter();
        void extractionLoop(const DateType object, char * dummy);
        void extraction(int &day, char *month, int &year, const DateType &object);
        virtual int compareTo( const DateType &lhObject,
                               const DateType &rhObject);
    	int findIndexofLargest(int size);
        virtual bool sort();
        void dateSwitcher(int lhObject, int rhObject);
        int charToInt(char * number);
        void lowerToUpper(char * month);
        bool myCompare(const char * stringOne, const char * stringTwo);
        int monthNumberTester(char * month);

    private:
        
        
};

#endif //PROJECT_4_TESTSORTER_H

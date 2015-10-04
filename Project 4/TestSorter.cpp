// Program Information ////////////////////////////////////////////////////////
/**
 * @file TestSorter.cpp
 *
 * @author Tanner Jones
 *
 * @brief Header file for the Test Sorter class
 *
 * @details Implements all member methods of the TestSorter class
 *
 * @version 1.00 (23 September 2015))
 *
 * @Note Requires TestSorter.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef TESTSORTER_CPP
#define TESTSORTER_CPP

// Header files ///////////////////////////////////////////////////////////////
#include "TestSorter.h"
#include "SorterClass.h"

using namespace std;

// Class constants ////////////////////////////////////////////////////////////
const char WHITE_SPACE = ' ';
const char NULL_CHAR = '\0';
const char THREE = 3;
const char JAN [] = "JAN";
const char FEB [] = "FEB";
const char MAR [] = "MAR";
const char APR [] = "APR";
const char MAY [] = "MAY";
const char JUN [] = "JUN";
const char JUL [] = "JUL";
const char AUG [] = "AUG";
const char SEP [] = "SEP";
const char OCT [] = "OCT";
const char NOV [] = "NOV";
const char DEC [] = "DEC";

/**
 * @brief Default constructor
 *
 * @details Constructs of test sorter class with default vector class initialization
 *
 * @param None
 *
 * @note None
 */

TestSorter::TestSorter()
            :SorterClass<DateType>()
{
    // Variables
}

/**
 * @brief ~TestSorter
 *
 * @details deconstruct  of test sorter class
 *
 * @param None
 *
 * @note None
 */

TestSorter::~TestSorter()
{
    // Variables
}

/**
 * @brief extractionLoop
 *
 * @details loops through date and copying the string
 *
 * @param a DateType and a char array
 *
 * @note None
 */

void TestSorter::extractionLoop(const DateType object, char * dummy)
{
    // Variables
    int count = 0;
    static int index = 0;

    // Loop through data
    while(object.date[index] != WHITE_SPACE) 
    {
        // Copy Data
        dummy[count] = object.date[index];

        // Increment index's
        index++;
        count++;
        
        if(object.date[index] == NULL_CHAR)
        {
        	index = -1;
        	break;
		}
    }

    // Add NULL Char
    dummy[count] = NULL_CHAR;

    // Increment index
    index++;
}

/**
 * @brief Default extraction
 *
 * @details Takes apart the date and splits into three different
 *  test subjects
 *
 * @param Simple vector has already been filled
 *
 * @note None
 */

void TestSorter::extraction(int &day, char * month, int &year, const DateType &object)
{
    // Variables
    char yDummy [5];
    char dDummy [3];
    int index;

    // Loop through the data until white space
    extractionLoop(object, dDummy);

    // Change day into number
    day = charToInt(dDummy);

    // Loop through the data until white space
    extractionLoop(object, month);

    // Copy array to month
    lowerToUpper(month);
    
    // Insert Null char at the end of three chars of month
    month[THREE] = NULL_CHAR;
    
    // Loop through the data until white space
    extractionLoop(object, yDummy);

    // Change year into year
    year = charToInt(yDummy);

}

/**
 * @brief compareTo
 *
 * @details compares two different dataTypes and figures out which one is greater
 *
 * @param simple vector has already been filled
 *
 * @note None
 */

int TestSorter::compareTo(const DateType &lhObject, const DateType &rhObject)
{
    // Variables
    int lhDay;
    int rhDay;
    int lhYear;
    int rhYear;
    char lhMonth [4];
    char rhMonth [4];
    int lhMonthNum;
    int rhMonthNum;
    DateType lhTemp = lhObject;
    DateType rhTemp = rhObject;

    // Extract char data in lhObject
    extraction(lhDay, lhMonth, lhYear, lhObject);

    // Extract char data in rhObject
    extraction(rhDay, rhMonth, rhYear, rhObject);

    // Get monthNum
    lhMonthNum = monthNumberTester(lhMonth);
    rhMonthNum = monthNumberTester(rhMonth);

    // Test to see if the next year is bigger then the index year
    if(lhYear > rhYear)
    {
       // Return 1
        return 1;
    }

    // Test to see if the years match
    if(lhYear == rhYear)
    {
        // Test to see if the next month is bigger then the index year
        if(lhMonthNum > rhMonthNum)
        {
            // Return 1
            return 1;

        }else if(lhMonthNum == rhMonthNum)
        {
            // Test to see if the days match
            if(lhDay > rhDay)
            {
                // Return 1
                return 1;
            }
        }
    }

    // Return 0 if the dates match
    return 0;
}

/**
 * @brief findIndexofLargest
 *
 * @details goes through the whole vector and finds the largest value
 *
 * @param simple vector has already been filled
 *
 * @note size
 */
 
int TestSorter::findIndexofLargest(int size)
{
	// Variables
	int indexSoFar = 0;
	int currentIndex;
	DateType testIndex;
	DateType largest;
	
	// Loop through data
	for(currentIndex = 1; currentIndex < size; currentIndex++)
	{
		// Get the currentIndex value
		this->getValueAt(currentIndex, testIndex);
		
		// Get the largest value
		this->getValueAt(indexSoFar, largest);
		
		// Compare the two different dateTyps
		if(compareTo(testIndex, largest) == 1)
		{
			indexSoFar = currentIndex;
		}
	}
	
	// Return largest index
	return indexSoFar;
}

/**
 * @brief sort
 *
 * @details goes through the whole vector and sorts
 *
 * @param simple vector has already been filled
 *
 * @note None
 */

bool TestSorter::sort()
{
    // Variables
   	int last;
   	int largest;
   	
   	// Loop through data
   	for(last = this->getSize() - 1; last >= 1; last--)
   	{
   			// Set largest due to function findIndexofLargest
   			largest = findIndexofLargest(last + 1);
   			
   			// Switch dataPoints
   			dateSwitcher(largest, last);
	}
	
	// Return true
	return true;
}

/**
 * @brief dateSwitcher
 *
 * @details takes two dates and switches them
 *
 * @param two different Dates
 *
 * @note None
 */
void TestSorter::dateSwitcher(int lhObject, int rhObject)
{
    // Variables
    DateType lhTemp;
    DateType rhTemp;

    // Get both objects
    this->getValueAt(lhObject, lhTemp);
    this->getValueAt(rhObject, rhTemp);

    // Swap the objects
    this->setValueAt(rhObject, lhTemp);
    this->setValueAt(lhObject, rhTemp);

}

/**
 * @brief charToInt
 *
 * @details switchs an char array to an int
 *
 * @param char array 
 *
 * @note None
 */

int TestSorter::charToInt(char * number)
{
    // Variables
    int result = 0;
    int count;

    // Loop through char array
    for(count = 0; number[count] != NULL_CHAR; count++)
    {
        result = result * 10 + number[count] - '0';
    }

    // Return result
    return result;
}

/**
 * @brief lowerToUpper
 *
 * @details switchs a char from lower to upper case
 *
 * @param an array that holds the months 
 *
 * @note None
 */
 
void TestSorter::lowerToUpper(char * month)
{
	// Variables
	int count;
	
	// Loop through date
	for(count = 0; count < THREE; count++)
	{
		// Test to see what char 
		if(month[count] == 'a' )
		{
			month[count] = 'A';
			
		}else if (month[count] == 'b')
		{
			month[count] = 'B';
		
		}else if (month[count] == 'c' )
		{
			month[count] = 'C';
			
		}else if (month[count] == 'd' )
		{
			month[count] = 'D';
			
		}else if (month[count] == 'e' )
		{
			month[count] = 'E';
			
		}else if (month[count] == 'f' )
		{
			month[count] = 'F';
			
		}else if (month[count] == 'g' )
		{
			month[count] = 'G';
			
		}else if (month[count] == 'h' )
		{
			month[count] = 'H';
			
		}else if (month[count] == 'i' )
		{
			month[count] = 'I';
			
		}else if (month[count] == 'j' )
		{
			month[count] = 'J';
			
		}else if (month[count] == 'k' )
		{
			month[count] = 'K';
			
		}else if (month[count] == 'l' )
		{
			month[count] = 'L';
			
		}else if (month[count] == 'm' )
		{
			month[count] = 'M';
			
		}else if (month[count] == 'n' )
		{
			month[count] = 'N';
			
		}else if (month[count] == 'o' )
		{
			month[count] = 'O';
			
		}else if (month[count] == 'p' )
		{
			month[count] = 'P';
			
		}else if (month[count] == 'q' )
		{
			month[count] = 'Q';
			
		}else if (month[count] == 'r' )
		{
			month[count] = 'R';
			
		}else if (month[count] == 's' )
		{
			month[count] = 'S';
			
		}else if (month[count] == 't' )
		{
			month[count] = 'T';
			
		}else if (month[count] == 'u' )
		{
			month[count] = 'U';
			
		}else if (month[count] == 'v' )
		{
			month[count] = 'V';
			
		}else if (month[count] == 'w' )
		{
			month[count] = 'W';
			
		}else if (month[count] == 'x' )
		{
			month[count] = 'X';
			
		}else if (month[count] == 'y' )
		{
			month[count] = 'Y';
			
		}else if (month[count] == 'z' )
		{	
			month[count] = 'Z';	
		}
	}
	
}

/**
 * @brief myCompare
 *
 * @details compares two strings to see if they are similar
 *
 * @param to char arrays 
 *
 * @note None
 */

bool TestSorter::myCompare(const char * stringOne, const char * stringTwo)
{
    // Variables
    int count = 0;

    // Loop through each string
    while(stringOne[count] != NULL_CHAR || stringTwo[count] != NULL_CHAR)
    {
    	// Compare each char
        if(stringOne[count] != stringTwo[count])
        {
            return false;
        }

        // Increase size
        count++;
    }

    // Return true
    return true;
}

/**
 * @brief monthNumberTest
 *
 * @details sets a value for each month
 *
 * @param an array for the month
 *
 * @note None
 */

int TestSorter::monthNumberTester(char * month)
{
    // Variables

    // Test for each month
    if(myCompare(month, JAN))
    {
        // Return 1
        return 1;
    }else if(myCompare(month, FEB))
    {
        // return 2
        return 2;
    }else if(myCompare(month, MAR))
    {
        // return 3
        return 3;
    }else if(myCompare(month, APR))
    {
        // return 4
        return 4;
    }else if(myCompare(month, MAY))
    {
        //return 5
        return 5;
    }else if(myCompare(month, JUN))
    {
        // return 6
        return 6;
    }else if(myCompare(month, JUL))
    {
        // return 7
        return 7;
    }else if(myCompare(month, AUG))
    {
        // return 8
        return 8;
    } else if(myCompare(month, SEP))
    {
        // return 9
        return 9;
    }else if(myCompare(month, OCT))
    {
        // return 10
        return 10;
    }else if(myCompare(month, NOV))
    {
        // return 11
        return 11;
        
    }else{
        // return 12
        return 12;
    }
}

#endif

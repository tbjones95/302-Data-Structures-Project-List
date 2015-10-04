// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.cpp
 *
 * @brief Implementation file for QkSorter using quick sort,
 *        derived from SorterClass
 *
 * @author Tanner Jones
 *
 * @details Implements virtual member methods of the QkSorter
 *
 * @version 1.00 (30 September 2015)
 *
 * @Note Requires QkSorter.h, SorterClass.cpp, SimpleVector.cpp,
 *
 */

// Header files ///////////////////////////////////////////////////////////////
#include "QkSorter.h"
#include "SorterClass.cpp"
#include "SimpleVector.cpp"

/**
 * @brief Default constructor
 *
 * @details Constructs sorter class with default vector class initialization
 *
 * @param None
 *
 * @note None
 */
QkSorter::QkSorter()
        : SorterClass<DateType>()
{
    // Variables
}

/**
 * @brief Initialization constructor
 *
 * @details Constructs sorter class with specified vector class initialization
 *
 * @param None
 *
 * @note None
 */
QkSorter::QkSorter(int capacity)
        : SorterClass<DateType>(capacity)
{
    // Variables
}

/**
 * @brief Copy constructor
 *
 * @details Constructs sorter class with copied object
 *
 * @param None
 *
 * @note None
 */
QkSorter::QkSorter(const SorterClass<DateType> &copiedSorter)
        : SorterClass<DateType>(copiedSorter)
{
    // Variables
}

/**
 * @brief Destructor
 *
 * @details Destructs object after going out of bonds
 *
 * @param None
 *
 * @note None
 */
QkSorter::~QkSorter()
{
    // Variables
}

/**
 * @brief compareTo
 *
 * @details Compares two sets of dates to see if one is different then the other
 *
 * @param the left and right date object
 *
 * @note None
 */
int QkSorter::compareTo(const DateType &lhObject, const DateType &rhObject)
{
    // Variables
    int diff = makeYear( lhObject.date ) - makeYear( rhObject.date );

    // Test to see if years are different
    if( diff != 0 )
    {
        return diff;
    }

    // Set diffence in months
    diff = makeMonth( lhObject.date ) - makeMonth( rhObject.date );

    // Test to see if months are different
    if( diff != 0 )
    {
        return diff;
    }

    // Return the difference in days
    return makeDate( lhObject.date ) - makeDate( rhObject.date );
}

/**
 * @brief sort
 *
 * @details sorts a list of objects in a merge sort
 *
 * @param none
 *
 * @note None
 */
bool QkSorter::sort()
{
    // Variables
    int first = 0;
    int size = getSize() - 1;

    quickSort(first, size);

    return true;
}

/**
 * @brief insertionSort
 *
 * @details helper function for the quickSort
 *
 * @param size
 *
 * @note None
 */
int QkSorter::partition(int first, int last)
{
    // Variables
    DateType pivot;
    DateType temp;

    int index = first;
    int count;

    getValueAt(first, pivot);

    for(count = first + 1; count <= last; count++)
    {
        getValueAt(count, temp);

        if(compareTo(temp, pivot) <= 0)
        {
            index++;
            swap(index, count);
        }
    }

    swap(index, first);

    return index;
}

/**
 * @brief insertionSort
 *
 * @details helper function for the quickSort
 *
 * @param size
 *
 * @note None
 */
void QkSorter::quickSort(int first, int last)
{
    // Variables
    int pivotElement;

    // Test indexes
    if(first < last)
    {
        pivotElement = partition(first, last);
        quickSort(first, pivotElement - 1);
        quickSort(pivotElement + 1, last);
    }
}

/**
 * @brief swap
 *
 * @details swaps two data points data
 *
 * @param two ints of positions
 *
 * @note None
 */
void QkSorter::swap(int one, int other)
{
    // Variables
    DateType oneDate, otherDate;

    // Get values at each position
    getValueAt( one, oneDate );
    getValueAt( other, otherDate );

    // Set values at opposite position
    setValueAt( other, oneDate );
    setValueAt( one, otherDate );
}

/**
 * @brief makeDate
 *
 * @details takes out the day of the date
 *
 * @param c style string
 *
 * @note None
 */
int QkSorter::makeDate(const char *str)
{
    // Variables
    int startIndex = 0;
    int maxDate, date = strToInt( startIndex, str );

    // Test To see what month it is
    switch( makeMonth( str ) )
    {
        // Set days to 30 if month is correct
        case 4: case 6: case 9: case 11:
            maxDate = 30;
            break;

            // Test to see if Feb
        case 2:
            if( isLeapYear( makeYear( str ) ) )
            {
                maxDate = 29;
            }
            else
            {
                maxDate = 28;
            }
            break;

            // Set default days
        default:
            maxDate = 31;
            break;
    }

    // Set if correct day meets month
    if( date > 0 && date <= maxDate )
    {
        return date;
    }

    // Fails sort if date is wrong
    sortSuccess = false;

    // Return 0
    return 0;
}

/**
 * @brief makeDate
 *
 * @details takes out the day of the date
 *
 * @param c style string
 *
 * @note None
 */
int QkSorter::makeMonth(const char *str)
{
    // Variables
    int startIndex = 0;

    // Gets the starting index for the date
    startIndex = findSpace( startIndex, str ) + 1;

    // Test each month
    if( compMonth( str, startIndex, "APR" ) )
    {
        return 4;
    }

    else if( compMonth( str, startIndex, "AUG" ) )
    {
        return 8;
    }

    else if( compMonth( str, startIndex, "DEC" ) )
    {
        return 12;
    }

    else if( compMonth( str, startIndex, "FEB" ) )
    {
        return 2;
    }

    else if( compMonth( str, startIndex, "MAR" ) )
    {
        return 3;
    }

    else if( compMonth( str, startIndex, "MAY" ) )
    {
        return 5;
    }

    else if( compMonth( str, startIndex, "JAN" ) )
    {
        return 1;
    }

    else if( compMonth( str, startIndex, "JUL" ) )
    {
        return 7;
    }

    else if( compMonth( str, startIndex, "JUN" ) )
    {
        return 6;
    }

    else if( compMonth( str, startIndex, "NOV" ) )
    {
        return 11;
    }

    else if( compMonth( str, startIndex, "OCT" ) )
    {
        return 10;
    }

    else if( compMonth( str, startIndex, "SEP" ) )
    {
        return 9;
    }

    // If test fail sort fails
    sortSuccess = false;

    // return 0
    return 0;
}

/**
 * @brief makeYear
 *
 * @details takes out the year of the string
 *
 * @param c style string
 *
 * @note None
 */
int QkSorter::makeYear(const char *str)
{
    // Variables
    int startIndex = 0;
    int year;

    // Get index for string
    startIndex = findSpace( startIndex, str ) + 1;
    startIndex = findSpace( startIndex, str ) + 1;

    // Get year to number
    year = strToInt( startIndex, str );

    // Test to see if year is correct
    if( year < 0 || year > MAX_YEAR_ALLOWED )
    {
        sortSuccess = false;

        return 0;
    }

    // Return year
    return year;
}

/**
 * @brief strToInt
 *
 * @details takes a str and changes it to an int
 *
 * @param c style string
 *
 * @note None
 */
int QkSorter::strToInt(int startIndex, const char *str)
{
    // Variables
    int val, leftShiftFactor = 10;

    // Set value
    val = int( str[ startIndex ] - '0' );

    // Increase index
    startIndex++;

    // Loop through data
    while( isDigit( str[ startIndex ] ) )
    {
        val *= leftShiftFactor;

        val += int( str[ startIndex ] - '0' );

        startIndex++;
    }

    // Retrun val
    return val;
}

/**
 * @brief findSpace
 *
 * @details finds space in a string
 *
 * @param c style string and index
 *
 * @note None
 */
int QkSorter::findSpace(int startIndex, const char *str)
{
    // Variables

    // Loop through data
    while( str[ startIndex ] != SPACE && str[ startIndex ] != NULL_CHAR )
    {
        startIndex++;
    }

    // Return index
    return startIndex;
}

/**
 * @brief compMonth
 *
 * @details Compares to months to see if they are the same
 *
 * @param two c style string and index
 *
 * @note None
 */
bool QkSorter::compMonth(const char *testStr, int startIndex, const char *testMonth)
{
    // Variables
    int endIndex = startIndex + MONTH_NAME_WIDTH;
    int testIndex = 0;

    // Loop through data
    while( startIndex < endIndex )
    {
        // Test to see if month is the same
        if( toUpper( testStr[ startIndex ] ) != testMonth[ testIndex ] )
        {
            return false;
        }

        // Increase size
        startIndex++; testIndex++;
    }

    // return true
    return true;
}

/**
 * @brief toUpper
 *
 * @details changes a char to upper case
 *
 * @param one char
 *
 * @note None
 */
char QkSorter::toUpper(char testChar)
{
    // Variables

    // Tests to see if a char
    if( testChar >= 'a' && testChar <= 'z' )
    {
        testChar = int( testChar - 'a' + 'A' );
    }

    // Returns char
    return testChar;
}

/**
 * @brief isDigit
 *
 * @details tests to see if a char is a digit
 *
 * @param one char
 *
 * @note None
 */
bool QkSorter::isDigit(char testDigit)
{
    // Variables

    // returns true if its a real int
    return ( testDigit >= '0' && testDigit <= '9' );
}

/**
 * @brief isLeapYear
 *
 * @details tests to see if the year is a leap year
 *
 * @param one int
 *
 * @note None
 */
bool QkSorter::isLeapYear(int year)
{
    // Variables

    // returns the test if its a leap year
    return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 );
}
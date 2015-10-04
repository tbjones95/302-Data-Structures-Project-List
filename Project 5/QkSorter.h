// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.h
 *
 * @brief Definition file for QkSorter using a quick sort,
 *          derived from the SorterClass
 *
 * @author Tanner Jones
 *
 * @details Specifies all member methods of the QkSorter Class
 *
 * @version 1.00 (30 September 2015)
 *
 * @Note Requires DateType.h, SorterClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////
#ifndef PROJECT_5_QKSORTER_H
#define PROJECT_5_QKSORTER_H

// Header files ///////////////////////////////////////////////////////////////
#include "DateType.h"
#include "SorterClass.h"

// Class definition  //////////////////////////////////////////////////////////
class QkSorter: public SorterClass<DateType>
{
    public:

        // local constants
        static const char NULL_CHAR = '\0';
        static const char SPACE = ' ';
        static const int MONTH_NAME_WIDTH = 3;
        static const int MAX_YEAR_ALLOWED = 3000;

        // Constructors
        QkSorter();
        QkSorter(int capacity);
        QkSorter( const SorterClass<DateType> &copiedSorter );

        // Destructors
        virtual ~QkSorter();

        // Testers
        virtual int compareTo( const DateType &lhObject,
                           const DateType &rhObject );

        // Sorters
        virtual bool sort();
        int partition(int first, int last);
        void quickSort(int first, int last);

    private:

        // Class Member Variables
        bool sortSuccess;

        // Member Functions
        void swap( int one, int other );
        int makeDate( const char *str );
        int makeMonth( const char *str );
        int makeYear( const char *str );
        int strToInt( int startIndex, const char *str );
        int findSpace( int startIndex, const char *str );
        bool compMonth( const char *testStr,
                        int startIndex,
                        const char *testMonth );
        char toUpper( char testChar );
        bool isDigit( char testDigit );
        bool isLeapYear( int year );
};

#endif //PROJECT_5_QKSORTER_H

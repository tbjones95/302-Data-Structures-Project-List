// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleVector.h
 *
 * @brief Definition file for SimpleVector class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the SimpleVector class
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMPLEVECTOR_H
#define CLASS_SIMPLEVECTOR_H

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

template <class DataType>
class SimpleVector
   {
    public:

    // Internal constant
    static const int DEFAULT_CAPACITY = 10;

    // constructors
    SimpleVector();
    SimpleVector( int newCapacity );
    SimpleVector( int newCapacity, const DataType &fillValue );
    SimpleVector( const SimpleVector &copiedVector ); 

    // destructor
    ~SimpleVector( );

    // assignment
    const SimpleVector &operator = ( const SimpleVector &rhVector );

    // accessors
    int getCapacity() const;
    int getSize() const;

    // index access
    DataType &operator [ ] ( int index ) throw ( logic_error );
    const DataType &operator [ ] ( int index ) const throw ( logic_error );

    // modifiers

       // set value in array, without index brackets
       void setValueAt( int index, const DataType &item )
                                                      throw ( logic_error );

       // get value in array, without index brackets
       void getValueAt( int index, DataType &item ) const throw ( logic_error );

       // allows vector to grow by given quantity
       void grow( int growBy );

       // allows vector to shrink by given quantity
       // allows vector to be shrunk to zero, 
       //   but throws logic_error if attempt to shrink to less than zero
       void shrink( int shrinkBy ) throw ( logic_error );

       // increment/decrement don't affect class
       //    but allows programmer to keep track of size inside vector
       void incrementSize();
       void decrementSize();

  private:

    int vectorCapacity;
    int vectorSize;
    DataType *vectorData;

    void copyVector( DataType *dest, DataType *src );
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMPLEVECTOR_H


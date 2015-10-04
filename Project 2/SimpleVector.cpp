// Program Information ////////////////////////////////////////////////////////
/*
     File Name:    SimpleVector.cpp

     Description:  Implementation file for Simple vector class
*/

// Version/Revision Information ///////////////////////////////////////////////
/*
     1.00 (9/9/2015) - Tanner Jones
          Implementation file in order to correctly run first CS 302 - Data
          Structions program
*/

// Header files ///////////////////////////////////////////////////////////////
#include "SimpleVector.h"

// Global constant definitioans  //////////////////////////////////////////////
const int ZERO = 0;

// Free function implementation  //////////////////////////////////////////////

/******************************************************************************
Function Specifications: SimpleVector constructor
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - SimpleVector will be created
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
SimpleVector<DataType>::SimpleVector()
						:vectorCapacity(DEFAULT_CAPACITY),
						 vectorSize(ZERO),
						 vectorData( new DataType [vectorCapacity])				
{
	// Variables	
}

/******************************************************************************
Function Specifications: SimpleVector constructor
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - LinkedList will be created with a special capacity
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
SimpleVector<DataType>::SimpleVector(int newCapacity)
						:vectorCapacity(newCapacity),
						 vectorSize(ZERO),
						 vectorData( new DataType [vectorCapacity])
						 
{
	// Variables
}

/******************************************************************************
Function Specifications: SimpleVector constructor
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - SimpleVector will be created and filled with dataType provided
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
SimpleVector<DataType>::SimpleVector( int newCapacity, const DataType &fillValue )
						:vectorCapacity(newCapacity),
						 vectorSize(newCapacity),
						 vectorData( new DataType [vectorCapacity])
{
	// Variables
	int count;
	
	// Insert value
	for(count = 0; count < vectorCapacity; count++)
	{
		vectorData [count] = fillValue;
	}
}


/******************************************************************************
Function Specifications: SimpleVector copy constructor
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - SimpleVector will be created and filled with another simpleVector
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
SimpleVector<DataType>::SimpleVector( const SimpleVector &copiedVector )
						:vectorCapacity(copiedVector.vectorCapacity),
						 vectorSize(copiedVector.vectorSize),
						 vectorData( new DataType [vectorCapacity])
{
	// Variables
	
	// Copy data
	copyVector(vectorData, copiedVector.vectorData);
}

/******************************************************************************
Function Specifications: SimpleVector deconstructor
===============================================================================
Preconditions:
  - SimpleVector has already been created
Postconditions:
  - SimpleVector will be delete and the memory will be free
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
SimpleVector<DataType>::~SimpleVector( )
{
	// Variables
	
	// Set data members to default
	vectorCapacity = ZERO;
	vectorSize = ZERO;
	
	// delete vectorData
	delete [] vectorData;
	
	// Set vector to null
	vectorData = NULL;	
}

/******************************************************************************
Function Specifications: SimpleVector overloaded assignment 
===============================================================================
Preconditions:
  - simplevector has already been created 
Postconditions:
  - Simplevector will be copied and put into another simplevector 
Algorithm: 
  - data will be deleted and then reallocated to be copied
Exceptional/Error Conditions:
  - this pointer and the simpleVector passed through arent the same 
*/

template<class DataType> 
const SimpleVector<DataType> &SimpleVector<DataType>::operator= ( const SimpleVector &rhVector )
{
	// Variables
	
	// Test SimpleVector pointers
	if( this == &rhVector)
	{
		return *this;
	}
	
	// Set up data members
	vectorCapacity = rhVector.vectorCapacity;
	vectorSize = rhVector.vectorSize;
	
	// Delete this vectorData
	delete [] vectorData;
	
	// Resize vectorData
	vectorData = new DataType [vectorCapacity];
	
	// Copy Data
	copyVector(vectorData, rhVector.vectorData);
	
	// return simpleVector
	return *this;
}

/******************************************************************************
Function Specifications: getCapacity
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - capacity is return to the main driver
Algorithm: 
  - return capacity
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
int SimpleVector<DataType>::getCapacity() const
{
	// Variables
	
	// Return capacity
	return vectorCapacity;
}

/******************************************************************************
Function Specifications: getSize
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - size is returned to the main driver
Algorithm: 
  - return size
Exceptional/Error Conditions:
  - none expected or treated
*/

template<class DataType> 
int SimpleVector<DataType>::getSize() const
{
	// Variables
	
	// Return capacity
	return vectorSize;
}

/******************************************************************************
Function Specifications: overloaded operator[]
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - allows the programer to access to dataVector 
Algorithm: 
  - takes indexs and returns it to the main driver
Exceptional/Error Conditions:
  - as long as the index is not out of the range of the capacity 
*/

template<class DataType> 
DataType &SimpleVector<DataType>::operator [ ] ( int index ) throw ( logic_error )
{
	// Variables
	
	// Test if index is in correct capacity
	if(index > vectorCapacity || index < 0)
	{
		throw logic_error("Index is out of the capacity");
	}
	
	// Return data member
	return vectorData [index];
}

/******************************************************************************
Function Specifications: overloaded operator[] const
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - allows the program to see what is in dataVector
Algorithm: 
  - returns the dataType from the index of SimpleVector
Exceptional/Error Conditions:
  - as long as the index is not out of the range of the capacity 
*/

template<class DataType> 
const DataType &SimpleVector<DataType>::operator [ ] ( int index ) const throw ( logic_error )
{
	// Variables
	
	// Test if index is in correct capacity
	if(index > vectorCapacity || index < 0)
	{
		throw logic_error("Index is out of the capacity");
	}
	
	// Return data member
	return vectorData [index];	
}

/******************************************************************************
Function Specifications: grow
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - increase the size of the capacity
Algorithm: 
  - deletes vectorData after being copied and reallicates memory for a bigger
    size 
Exceptional/Error Conditions:
  - none
*/

template<class DataType>
void SimpleVector<DataType>::grow( int growBy )
{
	// Variables
	DataType * temp = new DataType [vectorCapacity];
	
	// Copy data into temp
	copyVector(temp, vectorData);
	
	// Delete VectorData
	delete [] vectorData;
	
	// Resize vectorData
	vectorData = new DataType [vectorCapacity + growBy];
	
	// Copy data back into it
	copyVector(vectorData, temp);
	
	// Resize Capacity
	vectorCapacity += growBy;
	
	// Delete Temp
	delete [] temp;
	temp = NULL;
}

/******************************************************************************
Function Specifications: shrink
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - shrinks the SimpleVector size 
Algorithm: 
  - deletes vectorData after being copied and reallicates memory for a smaller
    size 
Exceptional/Error Conditions:
  - tests to see if the capacity goes lower then zero
*/

template<class DataType>
void SimpleVector<DataType>::shrink( int shrinkBy ) throw ( logic_error )
{
	// Variables
	DataType * temp = NULL;
	
	// Test to see if capacity goes below zero
	if(vectorCapacity - shrinkBy < 0)
	{
		// Throw exception
		throw logic_error("Capacity goes below zero");
	}
	
	// Set up Temp
	temp = new DataType [vectorCapacity];
	
	// Copy data into temp
	copyVector(temp, vectorData);
	
	// Delete VectorData
	delete [] vectorData;
	
	// Reset capacity
	vectorCapacity -= shrinkBy;
	
	// Resize vectorData
	vectorData = new DataType [vectorCapacity];
	
	// Copy data back into it
	copyVector(vectorData, temp);
	
	// Test Size
	if(vectorSize > vectorCapacity)
	{
		vectorSize = vectorCapacity;
	}
	
	// Delete Temp
	delete [] temp;
	temp = NULL;
}

/******************************************************************************
Function Specifications: incrementSize
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - increases the size for the user
Algorithm: 
  - increases the size by one
Exceptional/Error Conditions:
  - none
*/

template<class DataType> 
void SimpleVector<DataType>::incrementSize()
{
	// Variables
	
	// Decrease size
	vectorSize++;
}

/******************************************************************************
Function Specifications: decrementSize
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - decreases the size for the user
Algorithm: 
  - decreases the size by one
Exceptional/Error Conditions:
  - none
*/

template<class DataType> 
void SimpleVector<DataType>::decrementSize()
{
	// Variables
	
	// Decrease size
	vectorSize--;
}

/******************************************************************************
Function Specifications: copyVector
===============================================================================
Preconditions:
  - SimpleVector has been created
Postconditions:
  - copy of the dataType is created and put into the dest
Algorithm: 
  - loops through the data until it reaches the vectorCapacity
Exceptional/Error Conditions:
  - none
*/

template<class DataType>
void SimpleVector<DataType>::copyVector( DataType *dest, DataType *src )
{
	// Varaibles
	int count;
	
	// Loop through data
	for(count = 0; count < vectorCapacity; count++)
	{
		dest[count] = src[count];
	}
}

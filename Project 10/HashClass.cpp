// Program Information ////////////////////////////////////////////////////////
/**
 * @file HashClass.cpp
 *
 * @brief Implementation file for HashClass class
 * 
 * @details Implements the constructor method of the HashClass class
 *
 * @author Tanner Jones
 *
 * @version 1.00 (18 November 2015)
 *
 * @Note Requires HashClass.h, SimpleVector.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HASH_CLASS_CPP
#define HASH_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HashClass.h"
#include "SimpleVector.cpp"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

/**
 * @brief Default constructor
 *
 * @details Constructs empty HashNode
 *
 * @param DataType and the next pointer
 *
 * @note None
 */

template<typename DataType>
HashNode<DataType>::HashNode
        (
                const DataType &newData, HashNode *next
        )
        : data( newData ), nextPtr( next )
{
    // no parameters
}

/**
 * @brief Default constructor
 *
 * @details Constructs empty Hashtable
 *
 * @param None
 *
 * @note None
 */

template<typename DataType>
HashClass<DataType>::HashClass
        (
                // no parameters
        )
        : tableLength( 0 ), hashLetterCount( DEFAULT_HASH_LETTER_COUNT ), list()
{
    // data placed in initializers
}

/**
 * @brief Copy constructor
 *
 * @details Copy a given Hashtable
 *
 * @param Hashtable
 *
 * @note None
 */

template<typename DataType>
HashClass<DataType>::HashClass
        (
                const HashClass<DataType> &copied
        )
        : tableLength( copied.tableLength ),
          hashLetterCount( copied.hashLetterCount ), list( copied.tableLength, NULL )
{
    // Variables
    HashNode<DataType> * currentCopiedNode = NULL;
    int count;

    // Loop through the table
    for(count = 0; count < tableLength; count++)
    {
        currentCopiedNode = copied.list[count];

            // Loop through the branch
            while(currentCopiedNode != NULL)
            {
                addItem(currentCopiedNode->data);

                currentCopiedNode = currentCopiedNode->nextPtr;
            }
    }
}

/**
 * @brief destructor
 *
 * @details deconstructs a hashtable
 *
 * @param None
 *
 * @note None
 */

template<typename DataType>
HashClass<DataType>::~HashClass
        (
                // no parameters
        )
{
    // Variables

    // Clear list
    clearList();
}

/**
 * @brief operator=
 *
 * @details copys a given hashtable
 *
 * @param hashtable
 *
 * @note None
 */

template <typename DataType>
const HashClass<DataType>& HashClass<DataType>:: operator =
        ( const HashClass &rhHashTable )
{
    // Variables
    HashNode<DataType> * currentCopiedNode = NULL;
    int count;

    // Set the table
    setTableLength(rhHashTable.tableLength);
    setHashLetterCount(rhHashTable.hashLetterCount);


    // Loop through the table
    for(count = 0; count < tableLength; count++)
    {
        currentCopiedNode = rhHashTable.list[count];

        // Loop through the branch
        while(currentCopiedNode != NULL)
        {
            addItem(currentCopiedNode->data);

            currentCopiedNode = currentCopiedNode->nextPtr;
        }
    }

    // Return this
    return *this;
}

/**
 * @brief setTableLength
 *
 * @details sets the table length and sets the vector
 *
 * @param table length
 *
 * @note None
 */

template <typename DataType>
void HashClass<DataType>::setTableLength
        (
                int newTableLength
        )
{
    // Variables
    int count;

    // Test to see if the Vector is at 0
    if(tableLength == 0)
    {
        // Set the table length
        list.grow(newTableLength);

        // Set the Nodes to NULL
        for(count = 0; count < newTableLength; count++)
        {
            list[count] = NULL;
        }

        tableLength = newTableLength;
    }
}

/**
 * @brief setHashLetterCount
 *
 * @details sets the hash letter count
 *
 * @param hashLetter count
 *
 * @note None
 */

template <typename DataType>
void HashClass<DataType>::setHashLetterCount
        (
                int newHashLetterCount
        )
{
   // Variables

    // Set Hash Letter Count
    hashLetterCount = newHashLetterCount;
}

/**
 * @brief addItem
 *
 * @details adds a new item to the hashTable
 *
 * @param None
 *
 * @note None
 */

template <typename DataType>
bool HashClass<DataType>::addItem
        (
                const DataType &newData
        )
{
    // Variables
    int index = hash(newData);
    HashNode<DataType> * currentNode = NULL;

    // Test to see if its the first node
    if(list[index] == NULL)
    {
        // Set new value
        list[index] = new HashNode<DataType>(newData, NULL);

        // Increase size
        list.incrementSize();

        return true;
    }else
    {
        // Set currentNode
        currentNode = list[index];

        // Loop till next open stage
        while(currentNode->nextPtr != NULL)
        {
            currentNode = currentNode->nextPtr;
        }

        // Set new value
        currentNode->nextPtr = new HashNode<DataType>(newData, NULL);

        // Increase size
        list.incrementSize();

        // Return true
        return true;
    }
}

/**
 * @brief findItem
 *
 * @details finds a given dataItem
 *
 * @param dataItem
 *
 * @note None
 */

template <typename DataType>
bool HashClass<DataType>::findItem
        (
                const DataType &dataItem
        ) const
{
    return true;
}

/**
 * @brief removeItem
 *
 * @details removes a given item
 *
 * @param dataItem
 *
 * @note None
 */

template <typename DataType>
bool HashClass<DataType>::removeItem
        (
                const DataType &dataItem
        )
{
    // Variables
    int index = hash(dataItem);
    int count;
    HashNode<DataType> * currentNode = list[index];
    HashNode<DataType> * fallow = list[index];

    // Test the first value
    if(list[index]->data.compareTo(dataItem) == 0)
    {
        // Moves main pointer
        list[index] = currentNode->nextPtr;

        // Deletes the node
        currentNode->nextPtr = NULL;
        delete currentNode;
        currentNode = NULL;
        fallow = NULL;

        // Return true
        return true;
    }

    // Position the pointers
    currentNode = currentNode->nextPtr;

    // Loop until the node is found
    while(currentNode != NULL)
    {
        if(currentNode->data.compareTo(dataItem) == 0)
        {
            // Moves main pointer
            fallow->nextPtr = currentNode->nextPtr;

            // Deletes the node
            currentNode->nextPtr = NULL;
            delete currentNode;
            currentNode = NULL;
            fallow = NULL;

            // Return true
            return true;
        }

        // Move Pointer
        currentNode = currentNode->nextPtr;
        fallow = fallow->nextPtr;
    }

    return false;
}

/**
 * @brief isEmpty
 *
 * @details test to see if the hashtable is empty
 *
 * @param None
 *
 * @note None
 */

template<typename DataType>
bool HashClass<DataType>::isEmpty
        (
                // no parameters
        ) const
{
    // Variables
    int count = 0;

    // Loop through the list
    for(count = 0; count < tableLength; count++)
    {
        if(list[count] != NULL)
        {
            return false;
        }
    }

    // Return true
    return true;
}

/**
 * @brief clearList
 *
 * @details resets the hashtable
 *
 * @param None
 *
 * @note None
 */

template <typename DataType>
void HashClass<DataType>::clearList()
{
    // Variables
    int count;
    HashNode<DataType> * currentNode = NULL;
    HashNode<DataType> * fallow = NULL;

    // Loop through vector
    for(count = 0; count < tableLength; count++)
    {
        // Set currentNode
        currentNode = list[count];
        fallow = list[count];

        while(currentNode != NULL)
        {
            // Move down the chain
            fallow = fallow->nextPtr;

            // Delete the chain
            delete currentNode;
            currentNode = NULL;

            // Move down the Chain
            currentNode = fallow;
        }

        // Set List to NULL
        list[count] = NULL;
    }

}

/**
 * @brief getChainLengthMean
 *
 * @details gets the mean of the lengths of the hashtable
 *
 * @param None
 *
 * @note None
 */

template<typename DataType>
double HashClass<DataType>::getChainLengthMean
        (
                // no parameters
        ) const
{
    // Variables
    double result;
    int numNodes = list.getSize();

    // Get Mean
    result = numNodes / tableLength;

    // Return mean
    return result;
}

/**
 * @brief getChainLengthMedian
 *
 * @details finds the median of all the lengths of the hashtable
 *
 * @param None
 *
 * @note None
 */

template<typename DataType>
double HashClass<DataType>::getChainLengthMedian
        (
                // no parameters
        ) const
{
    // Variables
    int * lengths = new int[tableLength];
    double results;
    int index = (tableLength/2) - 1;

    // Get lengths
    findLengths(lengths);

    // Sort Lengths
    sortLengths(lengths);

    return lengths[index];

}

/**
 * @brief showStructure
 *
 * @details shows the structure of the hashTable
 *
 * @param None
 *
 * @note None
 */

template<typename DataType>
void HashClass<DataType>::showStructure
        (
        ) const
{
    // Variables
    int count;
    char * name = new char[STD_STR_LEN];
    char * id = new char[STD_STR_LEN];
    char gender;
    HashNode<DataType> * currentNode = NULL;

    // Loop through the vector
    for(count = 0; count < tableLength; count++)
    {
        // Test to see if its Null
        if(list[count] == NULL)
        {
            // Print out NULL
            cout << "NULL" << endl;
        }else{

            // Set currentNode
            currentNode = list[count];

            // Loop through the different stages
            while(currentNode != NULL)
            {
                // Get Information
                currentNode->data.getAccount(name, id, gender);

                // Print Name
                cout << "[ " << name << " ] ";

                // Go to next stage
                currentNode = currentNode->nextPtr;

            }

            cout << endl;
        }
    }

    // Delete Name and id
    delete [] name;
    delete [] id;
    name = NULL;
    id = NULL;
}

/**
 * @brief hash
 *
 * @details finds a given data items hash value
 *
 * @param dataItem
 *
 * @note None
 */

template<typename DataType>
int HashClass<DataType>::hash
        (
                const DataType &dataItem
        )
{
    DataType tempData( dataItem );

    return tempData.hash( hashLetterCount, tableLength );
}

/**
 * @brief findsLengths
 *
 * @details finds the lengths of each hashtable
 *
 * @param array of lengths
 *
 * @note None
 */

template<typename DataType>
void HashClass<DataType>::findLengths(int *lengths) const
{
    // Variables
    HashNode<DataType> * currentNode = NULL;
    int count;
    int distance = 0;

    // Loop through table
    for(count = 0; count < tableLength; count++)
    {
        // Set currentNode
        currentNode = list[count];

        // Loop through stages
        while(currentNode != NULL)
        {
            // Increase Length
            distance++;

            // Move pointer
            currentNode = currentNode->nextPtr;
        }

        // Set length
        lengths[count] = distance;
        distance = 0;
    }
}

/**
 * @brief sortLengths
 *
 * @details sorts an array of ints
 *
 * @param array of lengths
 *
 * @note None
 */

template<typename DataType>
void HashClass<DataType>::sortLengths(int *lengths) const
{
    // Variables
    bool sorted = false;
    int pass = 1;
    int index;
    int temp;

    // Loop through the array
    while(!sorted && (pass < tableLength))
    {
        // Set sorted
        sorted = true;

        for(index = 0; index < tableLength - pass; index++)
        {
            // Test the next index
            if(lengths[index] > lengths[index + 1])
            {
                // Swap values
                temp = lengths[index];
                lengths[index] = lengths[index + 1];
                lengths[index + 1] = temp;

                // Set sorted
                sorted = false;
            }
        }

        pass++;
    }

}
#endif	// define HASH_CLASS_CPP
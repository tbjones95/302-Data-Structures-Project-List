// Program Information ////////////////////////////////////////////////////////
/**
 * @file PriorityQueue.cpp
 *
 * @author Tanner Jones
 *
 * @brief Implementation file for priority queue class
 *
 * @details Implement's all functions in the Priority Queue class,
 *          along with the constructor
 *
 * @version 1.00 (16 September 2015))
 *
 * @Note Requires PriorityQueue.h
 */

// Precompiler directives /////////////////////////////////////////////////////

    // None

// Class constants ////////////////////////////////////////////////////////////
const int ONE = 1;
const int ZERO = 0;
const char NULL_CHAR = '\0';

// Header files ///////////////////////////////////////////////////////////////
#include "PriorityQueue.h"
#include "DataType.h"
#include "SimpleVector.h"
#include <iostream>
using namespace std;

/**
 * @brief Default constructor
 *
 * @details None
 *
 * @param None
 *
 * @note None
 */
template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
{

}

/**
 * @brief Copy constructor
 *
 * @details Copys all data from the copiedQueue
 *
 * @param None
 *
 * @note None
 */
template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue &copiedQueue)
{
    // Variables

    // Copy Data
    queue = copiedQueue.queue;
}

/**
 * @brief Destructor
 *
 * @details None
 *
 * @param None
 *
 * @note None
 */
template <class DataType>
PriorityQueue<DataType>::~PriorityQueue()
{
    // Variables
}

/**
 * @brief enqueue(int qPriority, char qProcess [])
 *
 * @details Adds new DataType to the vector
 *
 * @param loops through the vector to see where the new
 *         dataType will be placed
 *
 * @note if the vector is full double the memory
 */
template <class DataType>
bool PriorityQueue<DataType>::enqueue(int qPriority,char qProcess [] )
{
    // Variables
    int index;
    bool priorityFound = false;
    DataType temp;


    // Check if Full
    if(queue.getSize() == queue.getCapacity())
    {
        // Grow the vector
        queue.grow(queue.getCapacity());
    }

    // Check if Empty
    if(isEmpty())
    {
        // Insert dataItem in the beginning
        queue[ZERO].priority =  qPriority;
        stringCopy(queue[ZERO].process, qProcess);

        // Increase Size
        queue.incrementSize();

        // Return True
        return true;
    }

    for(index = queue.getSize() - ONE; index >= 0; index--)
    {
        // Test Priority
        if(qPriority >= queue[index].priority)
        {
            // Increase index
            index++;
            priorityFound = true;
            break;
        }
    }

    if(!priorityFound)
    {
        index++;
    }

    // Increase size
    queue.incrementSize();

    // Loop through data
    for(index = index; index < queue.getSize(); index++)
    {
        // Copy to temp
        temp.priority = queue[index].priority;
        stringCopy(temp.process, queue[index].process);

        // Insert new value
        queue[index].priority = qPriority;
        stringCopy(queue[index].process, qProcess);

        // Move temp to new values
        qPriority = temp.priority;
        stringCopy(qProcess, temp.process);
    }

    // return
    return true;
}

/**
 * @brief Default dequeue(DataType &dataItem)
 *
 * @details removes the first item from the list
 *
 * @param takes the first dataType from the beginning
 *          from the list and pushes all dataType down
 *
 * @note if the size is a fourth of the capacity the capacity
 *          is cut
 */
template <class DataType>
bool PriorityQueue<DataType>::dequeue(DataType &dataItem)
{
    // Variables
    int index;

    // Check if empty
    if(isEmpty())
    {
        return false;
    }

    // Set up dataItem
    dataItem.priority = queue[ZERO].priority;
    stringCopy(dataItem.process, queue[ZERO].process);

    // Decrease size
    queue.decrementSize();

    // Loop through data
    for(index = 0; index < queue.getSize(); index++)
    {
        // Move dataItem down the list
        queue[index].priority = queue[index + ONE].priority;
        stringCopy(queue[index].process, queue[index + ONE].process);
    }

    // Checks the queues capacity and size
    if(4 * queue.getSize() <  queue.getCapacity())
    {
        queue.shrink(queue.getCapacity()/2);
    }

    // Return true
    return true;
}

/**
 * @brief Default peekAtFront
 *
 * @details looks at the first item in vector
 *
 * @param takes the first dataType for the user
 *
 * @note if empty returns false
 */
template <class DataType>
bool PriorityQueue<DataType>::peekAtFront(DataType &dataItem)
{
    // Variables

    // Check if empty
    if(isEmpty())
    {
        return false;
    }

    // Set DataItem
    dataItem.priority = queue[ZERO].priority;
    stringCopy(dataItem.process, queue[ZERO].process);

    // Return true
    return true;
}

/**
 * @brief Default operator=
 *
 * @details sets the vectors equal to each other
 *
 * @param None
 *
 * @note None
 */
template <class DataType>
const PriorityQueue<DataType> &PriorityQueue<DataType>::operator= ( const PriorityQueue &rhQueue )
{
    // Variables
    int index;

    // Copy Queue
    queue = rhQueue.queue;

    // Return this
    return *this;
}

/**
 * @brief isEmpty()
 *
 * @details tests to see if the vector is empty
 *
 * @param None
 *
 * @note None
 */
template <class DataType>
bool PriorityQueue<DataType>::isEmpty() const
{
    // Variables

    // Test the size
    if(queue.getSize() == ZERO)
    {
        return true;
    }

    // Return false
    return false;
}

/**
 * @brief Default showStructure
 *
 * @details ShowStructure prints out the vector of all data
 *
 * @param None
 *
 * @note None
 */
template <class DataType>
void PriorityQueue<DataType>::showStructure(char list)
{
    // Variables
    int count;

    // Test to see empty
    if(isEmpty())
    {
        cout << "  Empty list" << endl;
    }else{

        // Format print
        cout << "  List " << list << " (" << queue.getSize() << "/" << queue.getCapacity() << "): ";

        // Loop through data
        for (count = 0; count < queue.getSize(); count++)
        {
            cout << "[" << queue[count].priority << "/" << queue[count].process << "] ";
        }

        // print endl
        cout << endl;
    }
}

/**
 * @brief stringCopy
 *
 * @details copys string into another string
 *
 * @param None
 *
 * @note None
 */
template<class DataType>
void PriorityQueue<DataType>::stringCopy(char dest [], const char source[])
{
    // Variables
    int count = 0;

    // Loop till null char
    while(source[count] != NULL_CHAR)
    {
        dest[count] = source[count];
        count++;
    }

    dest[count] = NULL_CHAR;
}

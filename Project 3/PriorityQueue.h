// Program Information ////////////////////////////////////////////////////////
/**
 * @file PriorityQueue.h
 *
 * @author Tanner Jones
 *
 * @brief Header file for the priority queue class
 *
 * @details Specifies all data of the Priority Queue class,
 *          along with the constructor
 *
 * @version 1.00 (16 September 2015))
 *
 * @Note Requires PriorityQueue.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////
#ifndef PROJECT_3_PRIORITYQUEUE_H
#define PROJECT_3_PRIORITYQUEUE_H

// Header files ///////////////////////////////////////////////////////////////
#include "SimpleVector.cpp"
#include "DataType.h"

// Class constants ////////////////////////////////////////////////////////////

    // None

// Class definition ///////////////////////////////////////////////////////////
template<class DataType>
class PriorityQueue
    {
    public:
    // Constructors
        PriorityQueue();
        PriorityQueue(const PriorityQueue &copiedQueue );

    // Destructor
        ~PriorityQueue();

    // Modifiers
        bool enqueue(int qPriority,char qProcess [] );
        bool dequeue(DataType &dataItem);
        const PriorityQueue &operator= ( const PriorityQueue &rhQueue );

    // Viewers
        bool peekAtFront(DataType &dataItem);
        void showStructure( char list);

    // Testers
        bool isEmpty() const;

    private:
        SimpleVector<DataType> queue;
        void stringCopy(char dest [], const char source[]);
};

// Terminating precompiler directives  ////////////////////////////////////////
#endif //PROJECT_3_PRIORITYQUEUE_H

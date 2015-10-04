// Program Information ////////////////////////////////////////////////////////
/*
     File Name:    ListNode.cpp

     Description:  Implementation file for ListNode class
*/

// Version/Revision Information ///////////////////////////////////////////////
/*
     1.00 (9/2/2015) - Tanner Jones
          Implementation file in order to correctly run first CS 302 - Data
          Structions program
*/

// Header files ///////////////////////////////////////////////////////////////
#include "ListNode.h"


/******************************************************************************
Function Specifications: ListNode constructor
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - ListNode will be created
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

ListNode::ListNode( int nodeData, ListNode* nextPtr)
{
	// Variables
	
	// Set up data
	dataItem = nodeData;
	next = nextPtr;
}

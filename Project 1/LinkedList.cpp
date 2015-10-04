// Program Information ////////////////////////////////////////////////////////
/*
     File Name:    LickedList.cpp

     Description:  Implementation file for Linked List class
*/

// Version/Revision Information ///////////////////////////////////////////////
/*
     1.00 (9/2/2015) - Tanner Jones
          Implementation file in order to correctly run first CS 302 - Data
          Structions program
*/

// Header files ///////////////////////////////////////////////////////////////
#include "LinkedList.h"
#include "ListNode.h"

// Free function implementation  //////////////////////////////////////////////

/******************************************************************************
Function Specifications: LinkedList constructor
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - LinkedList will be created
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

LinkedList::LinkedList( int maxSize)
{
	// Variables
	
	// Set Size and capacity
	size = 0;
	capacity = maxSize;
	
	// Set node pointers
	head = NULL;
	cursor = NULL;
	
}

/******************************************************************************
Function Specifications: LinkedList copy constructor
===============================================================================
Preconditions:
  - LinkedList other is already been created
Postconditions:
  - New LinkedList will be created
Algorithm: 
  - set data to default
Exceptional/Error Conditions:
  - none expected or treated
*/

LinkedList::LinkedList( const LinkedList& other )
{
	// Variables
	
	// Call assignedIt
	isAssigned(other);	
}

/******************************************************************************
Function Specifications: LinkedList destructor
===============================================================================
Preconditions:
  - LinkedList was created before hand
Postconditions:
  - LinkedList will be deleted
Algorithm: 
  - go through each node and delete them
Exceptional/Error Conditions:
  - none expected or treated
*/

LinkedList::~LinkedList()
{
	// Variables
	
	// Set Size and capacity to default
	size = 0;
	capacity = 0;
	
	// Set cursor to first node
	goToBeginning();
	
	// Loop through data and delete all nodes
	while(head != NULL)
	{
		// Move head up
		head = head->next;
		
		// Set next to NULL
		cursor->next = NULL;
		
		// delete cursor
		delete cursor; 
		
		// Move cursor
		cursor = head;
	}	
}

/******************************************************************************
Function Specifications: insertBeforeCursor
===============================================================================
Preconditions:
  - LinkedList created
Postconditions:
  - New Node will be created
Algorithm: 
  - create a new node
Exceptional/Error Conditions:
  - none expected or treated
*/

bool LinkedList::insertBeforeCursor( int newDataItem )
{
	// Variables
	
	// Check if full
	if(isFull())
	{
		return false;
	}
	
	// Check if empty
	if(isEmpty())
	{
		// Create first node in list
		head = new ListNode(newDataItem, NULL);
		
		// Set cursor to head
		cursor = head;
		
		// reset size
		size++;
		
		// return true
		return true;
	}
	
	// Check if cursor is at the first node
	if(cursor != NULL && cursor == head)
	{
		// Create a new first node
		head = new ListNode(newDataItem, cursor);
		
		// Set cursor to head
		cursor = head;
		
		// reset size
		size++;
		
		// return true
		return true;		
	}
	
	// Move cursor back one
	goToPrior();
	
	// create a new node
	cursor->next = new ListNode(newDataItem, cursor->next);
	
	// Move cursor to next
	goToNext();
	
	// reset size
	size++;
	
	// Return true
	return true;	
}

/******************************************************************************
Function Specifications: InsertAfterCursor
===============================================================================
Preconditions:
  - LinkedList was created
Postconditions:
  - New node was created after the curser
Algorithm: 
  - create a new after the cursor 
Exceptional/Error Conditions:
  - none expected or treated
*/

bool LinkedList::insertAfterCursor( int newDataItem )
{
	// Variables
	
	// Check if full
	if(isFull())
	{
		return false;
	}
	
	// Check if empty
	if(isEmpty())
	{
		// Create first node in list
		head = new ListNode(newDataItem, NULL);
		
		// Set cursor to head
		cursor = head;
		
		// reset size
		size++;
		
		// return true
		return true;
	}
	
	// Check if at the end of list
	if(cursor->next == NULL)
	{
		// Create a new node in list
		cursor->next = new ListNode(newDataItem, NULL);
		
		// Set cursor to new node
		goToNext();
		
		// reset size
		size++;
		
		// return true
		return true;
	}
	
	// Create a new node
	cursor->next = new ListNode(newDataItem, cursor->next);
	
	// Move cursor to next 
	goToNext();
	
	// reset size
	size++;
	
	// Return true
	return true;	
}

/******************************************************************************
Function Specifications: replaceBeforeCursor
===============================================================================
Preconditions:
  - node most be created already
Postconditions:
  - data in the node will be replaced
Algorithm: 
  - replaces data in node after testing
Exceptional/Error Conditions:
  - if cursor is at beginning wont replace 
*/

bool LinkedList::replaceBeforeCursor( int newDataItem )
{
	// Variables
	
	// Check if cursor is at the head or if empty
	if(cursor == head || isEmpty())
	{
		// return false
		return false; 
	}
	
	// Go back to prior node
	goToPrior();
	
	// Replace the node data
	cursor->dataItem = newDataItem;
	
	// Return true
	return true;
}

/******************************************************************************
Function Specifications: replaceAtCursor
===============================================================================
Preconditions:
  - node most be created already
Postconditions:
  - data in the node will be replaced at cursor
Algorithm: 
  - replaces data in node after testing
Exceptional/Error Conditions:
  - if cursor is at beginning wont replace 
*/

bool LinkedList::replaceAtCursor( int newDataItem )
{
	// Variables
	
	// Check if list is empty
	if(isEmpty())
	{
		// return false
		return false;
	}
	
	// Replace the node data
	cursor->dataItem = newDataItem;
	
	// Return true
	return true; 
}

/******************************************************************************
Function Specifications: replaceAfterCursor
===============================================================================
Preconditions:
  - node most be created already
Postconditions:
  - data in the node will be replaced after cursor 
Algorithm: 
  - replaces data in node after testing
Exceptional/Error Conditions:
  - if cursor is at beginning wont replace 
*/

bool LinkedList::replaceAfterCursor( int newDataItem )
{
	// Variables
	
	// Check if list is empty and if cursor is at the end 
	if(isEmpty() || cursor->next == NULL)
	{
		// return false
		return false;
	}
	
	// Go to the next node
	goToNext();
	
	// Replace the node data
	cursor->dataItem = newDataItem;
	
	// Return true
	return true;
}

/******************************************************************************
Function Specifications: removeAtCursor
===============================================================================
Preconditions:
  - node most be created already
Postconditions:
  - node will be delete
Algorithm: 
  - tested to see what condition matchs and deletes node
Exceptional/Error Conditions:
  - if list is empty it wont remove 
*/

bool LinkedList::removeAtCursor( int &dataVal )
{
	// Variables
	ListNode * temp;
		
	// Check if empty
	if( isEmpty() )
	{
		// return false
		return false;
	}
	
	// Check if there is only one item in the list
	if(cursor == head && cursor->next == NULL)
	{
		// Set dataVal
		dataVal = cursor->dataItem;
		
		// Delete node
		delete cursor;
		
		// reset size
		size--;
		
		// Set Head and cursor to NUll
		head = NULL;
		cursor = NULL;
		
		// Return true
		return true;
	}

	// Check if cursor is at the beginning of the list
	if(head == cursor && size > 1)
	{
		// Set head to next
		head = head->next;
		
		// Set cursor next to null
		cursor->next = NULL;
		
		// Set dataVal
		dataVal = cursor->dataItem;
		
		// delete cursor
		delete cursor; 
		
		// Set cursor to head
		cursor = head;
		
		// reset size
		size--;
		
		// Return true
		return true;
	} 
	
	// Check if cursor is at the end of the list 
	if(cursor->next == NULL)
	{
		// Set temp
		temp = cursor;
		
		// Move cursor back
		goToPrior();
		
		// Set dataVAl
		dataVal = temp->dataItem;
		
		// Set cursor next to null
		cursor->next = NULL;
		
		// Delete node
		delete temp;
		
		// Set temp to NUll
		temp = NULL;
		
		// reset size
		size--;
		
		// Return true
		return true;
	}

	// Set up 
	temp = cursor;
		
	// Move cursor back one
	goToPrior();
	
	// Link list together
	cursor->next = temp->next;
	
	// Set temp to null
	temp->next = NULL;
	
	// set dataVal
    dataVal = temp->dataItem;
	
	// delete temp
	delete temp;
	
	// Set temp to null
	temp = NULL;

	// reset size
	size--;
	
	// Move cursor up
	goToNext();
	
	// Return true
	return true;	
}

/******************************************************************************
Function Specifications: clear
===============================================================================
Preconditions:
  - LinkedList most be created 
Postconditions:
  - data in List will be deleted
Algorithm: 
  - replaces data in node after testing
Exceptional/Error Conditions:
  - none
*/

void LinkedList::clear()
{
	// Variables
	
	// Set cursor to beginning
	goToBeginning();
	
	// Reset size
	size = 0;

	// Loop through data
	while( head != NULL)
	{
		head = head->next;
		cursor->next = NULL;
		delete cursor;
		cursor = head;
	}
}

/******************************************************************************
Function Specifications: isAssigned
===============================================================================
Preconditions:
  - other List most be created
Postconditions:
  - other List will be copyed into this
Algorithm: 
  - loops through data and copy after testing either other is equal to this
Exceptional/Error Conditions:
  - if lists are the same
*/

LinkedList& LinkedList::isAssigned( const LinkedList& other )
{
	// Variables
	ListNode * temp = other.head;
	
	// Clear list
	clear();
	
	// Set Size and capacity
	size = other.size;
	capacity = other.capacity;
	
	// Set the first node
	head = new ListNode(temp->dataItem, NULL);
	cursor = head;
	
	// Move temp to the next item 
	temp = temp->next;
	
	// Loop through the rest of the list
	while(temp != NULL)
	{
		// Create the next node for the list
		cursor->next = new ListNode(temp->dataItem, NULL);
		
		// Move pointers
		cursor = cursor->next;
		temp = temp->next;
	}
	
	// Set temps to Null
	temp = NULL;	
	
	// return this
	return *this;
}

/******************************************************************************
Function Specifications: operator=
===============================================================================
Preconditions:
  - none
Postconditions:
  - this LinkedList will be a copy of other
Algorithm: 
  - copy all data to this linkedList 
Exceptional/Error Conditions:
  - if other linkedList is this linkedList
*/

LinkedList& LinkedList::operator = ( const LinkedList& other )
{
	// Variables
	
	// Call isAssigned
	isAssigned(other);
	
	// Return this
	return *this;
}

/******************************************************************************
Function Specifications: getDataAtCursor 
===============================================================================
Preconditions:
  - node most be filled
Postconditions:
  - gets data from node
Algorithm: 
  - gets dataVal
Exceptional/Error Conditions:
  - if the linkedList is empty
*/

bool LinkedList::getDataAtCursor( int &dataVal ) const
{
	// Variables
	
	// Test to see if empty
	if(isEmpty())
	{
		// return false
		return false;
	}
	
	// Set dataVal
	dataVal = cursor->dataItem;
	
	// return true
	return true;
}

/******************************************************************************
Function Specifications: showsStructure
===============================================================================
Preconditions:
  - none
Postconditions:
  - prints out all the data from the list
Algorithm: 
  - loops through all the data 
Exceptional/Error Conditions:
  - none 
*/

void LinkedList::showStructure( char listID ) const
{
	// Variables
	int count;
	ListNode * temp = head;
	
	// Check if empty
	if(isEmpty())
	{
		cout << "  Empty list";
	}else{
		// Print out information
		cout << "  List " << listID << " (" << size << "/" << capacity << "): ";
		
		// Print out list
		while(temp != NULL)
		{
			// Test to see where cursor is
			if(temp == cursor)
			{
				// Print cursor out
				cout << "[" << temp->dataItem << "] "; 
			}else{
				// Print information out
				cout << temp->dataItem << " ";
			}
			
			// Move pointer
			temp = temp->next;
		}
	}
	
	// Print a endline
	cout << endl;
}

/******************************************************************************
Function Specifications: isEmpty
===============================================================================
Preconditions:
  - none
Postconditions:
  - figures out if list is empty 
Algorithm: 
  - checks the posistion of the pointers
Exceptional/Error Conditions:
  - none
*/

bool LinkedList::isEmpty() const
{
	// Variables
	
	// Test to see if empty
	if(head == NULL && cursor == NULL)
	{
		// Return true
		return true;
	}else{
		// return false
		return false;
	}
}

/******************************************************************************
Function Specifications: isFull
===============================================================================
Preconditions:
  - none
Postconditions:
  - figures out if list is full 
Algorithm: 
  - checks the posistion of the pointers
Exceptional/Error Conditions:
  - none
*/

bool LinkedList::isFull() const
{
	// Variables
	
	// Test to see if full
	if(size == capacity)
	{
		// Return true
		return true;
	}else{
		// Return false
		return false;
	}
}

/******************************************************************************
Function Specifications: goToBeginning
===============================================================================
Preconditions:
  - list must not be empty 
Postconditions:
  - cursor is at the head
Algorithm: 
  - takes the cursor and moves it to the head
Exceptional/Error Conditions:
  - if its empty its not moving
*/

bool LinkedList::goToBeginning()
{
	// Variables
	
	// Test to see if empty
	if(isEmpty())
	{
		// Return false;
		return false;
	}
	
	// Set cursor to head
	cursor = head;
	
	// Return true;
	return true;
}

/******************************************************************************
Function Specifications: goToEnd
===============================================================================
Preconditions:
  - list must not be empty
Postconditions:
  - cursor moves to the end of the list
Algorithm: 
  - loops until the end
Exceptional/Error Conditions:
  - if its empty its not moving
*/

bool LinkedList::goToEnd()
{
	// Vaiables 
	
	// Test to see if empty
	if(isEmpty())
	{
		// Return false;
		return false;
	}
	
	// Loop till the end
	while(cursor->next != NULL)
	{
		// set cursor to next
		cursor = cursor->next;
	}
	
	// Return true
	return true;
}

/******************************************************************************
Function Specifications: goToNext
===============================================================================
Preconditions:
  - list must not be empty
Postconditions:
  - cursor moves to the next node
Algorithm: 
  - moves next node
Exceptional/Error Conditions:
  - if its empty its not moving
*/

bool LinkedList::goToNext()
{
	// Variables
	
	// Test to see if empty
	if(isEmpty() || cursor->next == NULL)
	{
		// Return false;
		return false;
	}
	
	// Move cursor
	cursor = cursor->next;
	
	// Return true
	return true;	
}

/******************************************************************************
Function Specifications: goToPrior
===============================================================================
Preconditions:
  - list must not be empty
Postconditions:
  - cursor moves back a node
Algorithm: 
  - goes to the first nodes and loops until the gets to the node before 
Exceptional/Error Conditions:
  - if its empty its not moving
*/

bool LinkedList::goToPrior()
{
	// Variables	
	ListNode * temp = head;
	
	// Check if empty or at the endl
	if( isEmpty() || cursor == head)
	{
		return false;
	}

	// Loop until temp is one before cursor
	while(temp->next != cursor)
	{
		temp = temp->next;
	}
	
	// Set cursor to temp	
	cursor = temp;

	// Set temp to null
	temp = NULL;
 
	// return true
	return true;
}

// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.cpp
 *
 * @brief Definition file for Binary Search Tree class
 *
 * @details Implements all given functions of the BST class
 *
 * @author Tanner Jones
 *
 * @version 1.00 (21 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////
#include <iostream>
#include "BSTClass.h"

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

// None

// Class functions ///////////////////////////////////////////////////////////

/**
 * @brief Default constructor
 *
 * @details Constructs BSTNode
 *
 * @param NameType data, left and right pointers
 *
 * @note none
 */

template <class AcctType>
BSTNode<AcctType>::BSTNode(const AcctType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr)
        : dataItem(nodeData),
          left(leftPtr),
          right(rightPtr)
{

}

/**
 * @brief Default constructor
 *
 * @details Constructs BSTClass
 *
 * @param None
 *
 * @note none
 */

template <class AcctType>
BSTClass<AcctType>::BSTClass()
        : rootNode(NULL)
{

}

/**
 * @brief Copy constructor
 *
 * @details Constructs a copy of BSTClass
 *
 * @param BSTClass to copy
 *
 * @note none
 */

template<class AcctType>
BSTClass<AcctType>::BSTClass(const BSTClass<AcctType> &copied)
        : rootNode( NULL )
{
    // Variables

    // Copy Tree
    copyTree( copied );
}

/**
 * @brief Destructor
 *
 * @details destroys the BSTClass
 *
 * @param None
 *
 * @note none
 */

template<class AcctType>
BSTClass<AcctType>::~BSTClass()
{
    // Variables

    // Clear Tree
    clearTree();
}

/**
 * @brief operator=
 *
 * @details overloads the assignment operator
 *
 * @param copied tree
 *
 * @note none
 */

template <class AcctType>
const BSTClass<AcctType>& BSTClass<AcctType>:: operator =( const BSTClass &rhTree )
{
    // Variables

    // Test to see if the pointers are the same
    if( this != &rhTree )
    {
        clearTree();
        copyTree( rhTree );
    }

    // Return the binary tree
    return *this;
}

/**
 * @brief copyTree
 *
 * @details copies a tree into another tree
 *
 * @param binary tree
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::copyTree(const BSTClass<AcctType> &copiedTree)
{
    // Variables

    // Copy the tree
    copyTreeHelper( rootNode, copiedTree.rootNode );
}

/**
 * @brief clearTree
 *
 * @details deletes the whole tree
 *
 * @param none
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::clearTree()
{
    // Variables

    // Clear Tree
    clearTreeHelper( rootNode );
    rootNode = NULL;
}

/**
 * @brief insert
 *
 * @details inserts a new node
 *
 * @param NameType
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::insert(const AcctType &newData)
{
    // Variables

    // Class insert Helper
    insertHelper( rootNode, newData);
}

/**
 * @brief findItem
 *
 * @details finds a given NameType
 *
 * @param NameType
 *
 * @note none
 */

template <class AcctType>
bool BSTClass<AcctType>::findItem(const AcctType &searchDataItem) const
{
    // Variables
    BSTNode<AcctType> * temp = rootNode;
    bool foundItem = false;

    // Loop through tree
    while( foundItem == false && temp != NULL)
    {
        // Test the roots item
        if(temp->dataItem.compareTo(searchDataItem) > 0)
        {
            temp = temp->left;
        }else if(temp->dataItem.compareTo(searchDataItem) < 0)
        {
            temp = temp->right;
        }else{
            foundItem = true;
        }
    }
    // Return false
    return foundItem;
}
#endif //PROJECT_6_BSTCLASS_CPP
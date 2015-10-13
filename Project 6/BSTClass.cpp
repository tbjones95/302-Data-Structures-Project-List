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
 * @version 1.00 (15 October 2015)
 *
 * @Note None
 */
 
 // Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "BSTClass.h"
#include "NameType.h"
#include <iostream>

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

template <class NameType>
BSTNode<NameType>::BSTNode(const NameType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr)
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

template <class NameType>
BSTClass<NameType>::BSTClass()
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

template <class NameType>
BSTClass<NameType>::BSTClass(const BSTClass<NameType> &copied)
        : rootNode(branchLoop(copied.rootNode))
{

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

template <class NameType>
BSTClass<NameType>::~BSTClass()
{
    // Variables

    // Test to see if tree is empty
    if( !isEmpty() )
    {
        // Clear Tree
        clearTree();
    }
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

template <class NameType>
const BSTClass<NameType> &BSTClass<NameType>::operator=(const BSTClass &rhData)
{
    // Variables

    // Test to see if the tree is empty
    if( !isEmpty() )
    {
        // Clear tree
        clearTree();
    }

    // Copy Tree
    rootNode = branchLoop(rhData.rootNode);

    // Return copy
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

template <class NameType>
void BSTClass<NameType>::copyTree(const BSTClass &copied)
{
    // Variables

    // Copy the copied tree
    if(!copied.isEmpty())
    {
        rootNode = branchLoop(copied.rootNode);
    }

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

template <class NameType>
void BSTClass<NameType>::clearTree()
{
    // Variables

    // Test to see if root is empty
    if(rootNode != NULL)
    {
        deleteTree(rootNode);
    }
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

template <class NameType>
void BSTClass<NameType>::insert(const NameType &newData)
{
    // Variables


}

template <class NameType>
bool BSTClass<NameType>::findItem(const NameType &searchDataItem) const
{
    // Return false
    return false;
}

template <class NameType>
bool BSTClass<NameType>::removeItem(const NameType &dataItem)
{
    // Return true
    return true;
}

template <class NameType>
bool BSTClass<NameType>::isEmpty() const
{
    // Return false
    return false;
}

template <class NameType>
void BSTClass<NameType>::preOrderTraversal() const
{

}

template <class NameType>
void BSTClass<NameType>::inOrderTraversal() const
{

}

template <class NameType>
void BSTClass<NameType>::postOrderTraversal() const
{

}

template <class NameType>
int BSTClass<NameType>::getHeight() const
{
    // Return 0
    return 0;
}

template <class NameType>
void BSTClass<NameType>::showStructure() const
{

}

/**
 * @brief branchLoop
 *
 * @details loops and copies through the tree
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class NameType>
BSTNode<NameType> * BSTClass<NameType>::branchLoop(const BSTNode<NameType> *treePnt)
{
    // Variables
    BSTNode<NameType> * temp = NULL;

    // Copy the copied tree
    if(treePnt != NULL)
    {
        // Copy node
        temp = new BSTNode<NameType>(treePnt->dataItem, NULL, NULL);

        // Assign left and right
        temp->left = branchLoop(treePnt->left);
        temp->right = branchLoop(treePnt->right);
    }

    // Return temp
    return temp;
}

/**
 * @brief deleteTree
 *
 * @details loops through the tree and delets it
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::deleteTree(BSTNode<NameType> *treePnt)
{
    // Variables

    // Test left Node
    if(treePnt->left != NULL)
    {
        deleteTree(treePnt->left);
    }

    // Test right node
    if(treePnt->right != NULL)
    {
        deleteTree(treePnt->right);
    }

    // Delete Node
    delete treePnt;
}

#endif //PROJECT_6_BSTCLASS_CPP
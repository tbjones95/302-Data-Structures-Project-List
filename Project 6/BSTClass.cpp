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
    BSTNode<NameType> * leader = rootNode;
    BSTNode<NameType> * follower = NULL;
    
    // Loop till the end of the tree is reached
    while( leader != NULL)
    {
        // Set follower
        follower = leader;
       
        // Test the two data names
        if(leader->dataItem.compareTo(newData) > 0)
        {
            leader = leader->left; 
        }else{
            leader = leader->right;
        }
    }
    
    // Test to see if its the first node
    if(follower == NULL)
    {
        // Create the first Node
        rootNode = new BSTNode<NameType>(newData, NULL, NULL);
    }else{
        // Test to see what side of the tree to put it on
        if(follower->dataItem.compareTo(newData) > 0)
        {
            // Insert new Node
            follower->left = new BSTNode<NameType>(newData, NULL, NULL);
        }else{
            follower->right = new BSTNode<NameType>(newData, NULL, NULL);
        }
    }


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
 
template <class NameType>
bool BSTClass<NameType>::findItem(const NameType &searchDataItem) const
{
    // Variables
    BSTNode<NameType> * temp = root; 
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

/**
 * @brief removeItem
 *
 * @details finds a given item and removes it
 *
 * @param NameType
 *
 * @note none
 */
 
template <class NameType>
bool BSTClass<NameType>::removeItem(const NameType &dataItem)
{
    // Variables
    BSTNode * leader = root;
    BSTNode * follower = NULL;
    BSTNode * delParent = NULL;
    BSTNode * delNode = NULL;
    bool foundItem = false;
    
    // Test to see if the node is empty
    if(isEmpty() || !findItem(dataItem))
    {
        // Return false
        return false;
    }
    
    // Find the Node
   while( !foundItem && leader != NULL)
   {
      // Set follower
      follower = leader;
      
      // Test the roots item
      if(leader->dataItem.compareTo(searchDataItem) > 0)
      {
         leader = leader->left;
      }else if(leader->dataItem.compareTo(searchDataItem) < 0)
      {
         leader = leader->right;
      }else{
         foundItem = true;
      }
    }
    
    // Test if its the root
    if(leader == root)
    {
        // Set delNode node
        delNode = leader;
    }else{
        // Set delNode and Parent node
        delNode = leader;
        delParent = follower;
    }
    
    // Return true
    return true;
}

/**
 * @brief isEmpty
 *
 * @details tests to see if tree is empty
 *
 * @param none
 *
 * @note none
 */
 
template <class NameType>
bool BSTClass<NameType>::isEmpty() const
{
    // Variables
    
    // Test root
    if(rootNode == NULL)
    {
        // Return true
        return reture;
    }
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

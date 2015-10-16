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
        rootNode = NULL;
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
        rootNode = NULL;
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
    deleteTree(rootNode);
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
    BSTNode<NameType> * temp = rootNode;
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
        return true;
    }
    // Return false
    return false;
}

/**
 * @brief preOderTraversal
 *
 * @details loops through the tree and prints out in preOrder traversal
 *
 * @param none
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::preOrderTraversal() const
{
    // Variables
    BSTNode<NameType> * temp = rootNode;

    // Test to see if tree is empty
    if(!isEmpty())
    {
        // Call print function
        preorderPrint(temp);
    }else{

        cout << "Tree is empty" << endl;
    }
}

/**
 * @brief inOrderTraversal
 *
 * @details loops through the tree and prints out in in order traversal
 *
 * @param none
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::inOrderTraversal() const
{
    // Variables
    BSTNode<NameType> * temp = rootNode;

    // Test to see if three is empty
    if(!isEmpty())
    {
        // call print function
        inorderPrint(temp);
    }else{

        cout << "Tree is empty" << endl;
    }
}

/**
 * @brief postOrderTraversal
 *
 * @details loops through the tree and prints out in post order traversal
 *
 * @param none
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::postOrderTraversal() const
{
    // Variables
    BSTNode<NameType> * temp = rootNode;

    // Test to see if three is empty
    if(!isEmpty())
    {
        // call print function
        postorderPrint(temp);
    }else{

        cout << "Tree is empty" << endl;
    }

}

template <class NameType>
int BSTClass<NameType>::getHeight() const
{
    // Variables
    int height;

    // Get Height
    height = getHeightHelper(rootNode);

    // Return Height
    return height;
}

template <class NameType>
void BSTClass<NameType>::showStructure() const
{
    // Variables
    int height;

    // Test to if tree is empty
    if(rootNode == NULL)
    {
        cout << "Tree is empty" << endl;
    }else{

        // Get Height
        height = getHeight();
        cout << endl;
        printStructure(rootNode, height);
    }
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
    if(treePnt != NULL) {

        if (treePnt->left != NULL) {
            deleteTree(treePnt->left);
        }

        // Test right node
        if (treePnt->right != NULL) {
            deleteTree(treePnt->right);
        }

        // Delete Node
        delete treePnt;
    }
}

/**
 * @brief preoderPrint
 *
 * @details prints out all the nodes through preorder
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::preorderPrint(BSTNode<NameType> *branch) const
{
    // Variables

    // Test to see if branch is pointing to null
    if(branch != NULL)
    {
        cout << branch->dataItem << endl;
        preorderPrint(branch->left);
        preorderPrint(branch->right);
    }
}

/**
 * @brief inorderPrint
 *
 * @details loops through tree and prints out in inorder Print
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::inorderPrint(BSTNode<NameType> *branch) const
{
    // Variables

    // Test to see if branch is pointing to null
    if(branch != NULL)
    {
        inorderPrint(branch->left);
        cout << branch->dataItem << endl;
        inorderPrint(branch->right);
    }
}

/**
 * @brief postorderPrint
 *
 * @details loops through tree and prints out in postorder Print
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::postorderPrint(BSTNode<NameType> *branch) const
{
    // Variables

    // Test to see if branch is point to null
    if(branch != NULL)
    {
        postorderPrint(branch->left);
        postorderPrint(branch->right);
        cout << branch->dataItem << endl;
    }
}

/**
 * @brief getHeightHelper
 *
 * @details loops through tree and finds height
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class NameType>
int BSTClass<NameType>::getHeightHelper(BSTNode<NameType> *branch) const
{
    // Variables
    int left;
    int right;

    // Test to see if branch is null
    if(branch == NULL)
    {
        // Return 0
        return 0;
    }

    // Get left and right height
    left = getHeightHelper(branch->left);
    right = getHeightHelper(branch->right);

    // Test the heights
    if(left > right)
    {
        return left + 1;

    }else{

        return right + 1;
    }
}

/**
 * @brief printStructure
 *
 * @details loops through tree and prints out in structure form
 *
 * @param BSTNode node and int level
 *
 * @note none
 */

template <class NameType>
void BSTClass<NameType>::printStructure(BSTNode<NameType> *branch, int level) const
{
    // Variables
    int count;

    // Test to see if branch is pointing to null
    if(branch != NULL)
    {
        printStructure(branch->left,level-1);
        for(count = 0; count < level; count++)
        {
            // print tap
            cout << TAB;
        }
        cout << branch->dataItem << endl << endl;
        printStructure(branch->right, level-1);
    }
}
#endif //PROJECT_6_BSTCLASS_CPP
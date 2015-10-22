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
    copyTreeHelper( copiedTree.rootNode );
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
 * @param AcctType
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
 * @param AcctType
 *
 * @note none
 */

template <class AcctType>
bool BSTClass<AcctType>::findItem(AcctType &searchDataItem) const
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
            searchDataItem = temp->dataItem;

        }
    }
    // Return false
    return foundItem;
}

/**
 * @brief removeItem
 *
 * @details finds a given AcctType and delete it
 *
 * @param AcctType
 *
 * @note none
 */

template <class AcctType>
bool BSTClass<AcctType>::removeItem(const AcctType &dataItem)
{
    // Variables

    // Return the status of removeItemHelper
    return removeItemHelper( rootNode, dataItem );
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

template <class AcctType>
bool BSTClass<AcctType>::isEmpty() const
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

template <class AcctType>
void BSTClass<AcctType>::preOrderTraversal() const
{
    // Variables

    // Test to see if tree is empty
    if(!isEmpty())
    {
        // Call print function
        preorderPrint(rootNode);
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

template <class AcctType>
void BSTClass<AcctType>::inOrderTraversal() const
{
    // Variables

    // Test to see if three is empty
    if(!isEmpty())
    {
        // call print function
        inorderPrint(rootNode);
        cout << endl;
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

template <class AcctType>
void BSTClass<AcctType>::postOrderTraversal() const
{
    // Variables

    // Test to see if three is empty
    if(!isEmpty())
    {
        // call print function
        postorderPrint(rootNode);
    }else{

        cout << "Tree is empty" << endl;
    }
}


/**
 * @brief getHeight
 *
 * @details loops through the tree and finds height
 *
 * @param none
 *
 * @note none
 */

template <class AcctType>
int BSTClass<AcctType>::getHeight() const
{
    // Variables
    int height;

    // Get Height
    height = getHeightHelper(rootNode);

    // Return Height
    return height;
}

/**
 * @brief getWidthAtRow
 *
 * @details finds the width at a given row
 *
 * @param row number
 *
 * @note none
 */

template<class AcctType>
int BSTClass<AcctType>::getWidthAtRow(int row) const
{
    // Variables
    int height = getHeightHelper(rootNode);
    int width = 0;

    // Test row
    if(row < height)
    {
        width = getWidthAtRowHelper(rootNode, 0, row);
        return width;
    }

    // Return 0 if the row is out of bounds of height
    return 0;
}

/**
 * @brief getMaxWidth
 *
 * @details finds the max width and which row has it
 *
 * @param row number and the width
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::getMaxWidth(int &maxWidth, int &maxWidthRow) const
{
    // Variables
    int count;
    int height = getHeight();
    int testWidth;

    // Set MaxWidth and maxWidthRow
    maxWidth = 0;
    maxWidthRow = 0;

    // Find greatest max width
    for(count = 0; count < height; count++)
    {
        testWidth = getWidthAtRow(count);

        if(testWidth > maxWidth)
        {
            maxWidth = testWidth;
            maxWidthRow = count;
        }
    }
}

/**
 * @brief getMinWidth
 *
 * @details finds the smallest width and which row has it
 *
 * @param row number and width
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::getMinWidth(int &minWidth, int &minWidthRow) const
{
    // Variables

    // Set MaxWidth and maxWidthRow
    minWidth = getWidthAtRow(0);
    minWidthRow = 0;
}

/**
 * @brief getMinWidth
 *
 * @details finds the smallest width and which row has it
 *
 * @param row number and width
 *
 * @note none
 */

template<class AcctType>
int BSTClass<AcctType>::getBottomWidth() const
{
    // Variables
    int height = getHeight();
    int bottomWidth;

    // Set bottomWidth
    bottomWidth = getWidthAtRow(height - 1);

    // Return width
    return bottomWidth;
}

/**
 * @brief isCompleteTree
 *
 * @details tests to see if the tree is complete
 *
 * @param none
 *
 * @note none
 */

template<class AcctType>
bool BSTClass<AcctType>::isCompleteTree() const
{
    int depth;

    if( rootNode != NULL )
    {
        checkDepth( INITIALIZE, getHeight() - 1 );

        for( depth = 0; depth < getHeight() - 1; depth++ )
        {
            if( getWidthAtRow( depth ) != toPower( 2, depth ) )
            {
                return false;
            }
        }
    }

    isCompleteTreeHelper( rootNode, getHeight() - 1, 0 );

    return checkDepth( GET_RESULT, 0 );
}

/**
 * @brief isFullTree
 *
 * @details tests to see if the tree is full
 *
 * @param none
 *
 * @note none
 */

template<class AcctType>
bool BSTClass<AcctType>::isFullTree() const
{
    // Variables
    bool fullStatus;

    // Set fullStatus
    fullStatus = fullTreeHelper(rootNode);

    // Return fullStatus
    return fullStatus;
}

/**
 * @brief showStructure
 *
 * @details prints out the whole tree
 *
 * @param none
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::showStructure() const
{
    // Variables
    int height = getHeight();

    // Print Structure
    printStructure( rootNode, height, 0 );
    cout << endl;
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

template <class AcctType>
BSTNode<AcctType> * BSTClass<AcctType>::copyTreeHelper(const BSTNode<AcctType> *treePnt)
{
    // Variables
    BSTNode<AcctType> * temp = NULL;

    // Copy the copied tree
    if(treePnt != NULL)
    {
        // Copy node
        temp = new BSTNode<AcctType>(treePnt->dataItem, NULL, NULL);

        // Assign left and right
        temp->left = copyTreeHelper(treePnt->left);
        temp->right = copyTreeHelper(treePnt->right);
    }

    // Return temp
    return temp;
}

/**
 * @brief clearTreeHelper
 *
 * @details tests treePnt and deletes the tree
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::clearTreeHelper(BSTNode<AcctType> * treePnt)
{
    // Variables

    // Test pointer
    if ( treePnt != NULL )
    {
        clearTreeHelper( treePnt->left );
        clearTreeHelper( treePnt->right );
        delete treePnt;
    }
}

/**
 * @brief insertHelper
 *
 * @details loops and inserts a new node
 *
 * @param BSTNode node and AcctType data
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::insertHelper(BSTNode<AcctType> *&treePnt,const AcctType &newData)
{
    // Variables

    // Test Tree Pointer and insert newData
    if ( treePnt == NULL )
    {
        treePnt = new BSTNode<AcctType>( newData, NULL, NULL );
    }

    else if ( newData.compareTo( treePnt->dataItem ) < 0 )
    {
        insertHelper( treePnt->left, newData );
    }

    else if ( newData.compareTo( treePnt->dataItem ) > 0 )
    {
        insertHelper( treePnt->right, newData);
    }

    else
    {
        treePnt->dataItem = newData;
    }
}

/**
 * @brief removeItemHelper
 *
 * @details finds the right node and deletes it
 *
 * @param BSTNode node and dataType
 *
 * @note none
 */

template <class AcctType>
bool BSTClass<AcctType>::removeItemHelper(BSTNode<AcctType> *&treePnt, const AcctType &removeDataItem)
{
    // Variables
    BSTNode<AcctType> *delPtr;
    BSTNode<AcctType> *temp;
    BSTNode<AcctType> *followPtr;
    bool result = false;
    bool rightNode = false;

    // Test if treePnt is empty, less then, or greater then
    if( isEmpty() )
    {
        result = false;

    }else if ( removeDataItem.compareTo( treePnt->dataItem ) < 0 )
    {
        result = removeItemHelper( treePnt->left, removeDataItem );

    }else if ( removeDataItem.compareTo( treePnt->dataItem ) > 0 )
    {
        result = removeItemHelper( treePnt->right, removeDataItem );

    }

    // Test to see if its the right node
    if(removeDataItem.compareTo( treePnt->dataItem ) == 0 )
    {
        // Set detPnt
        delPtr = treePnt;

        // Test for which case it is
        if ( treePnt->left == NULL )
        {
            // Set the right as the new node
            treePnt = treePnt->right;
            delete delPtr;

        }else if ( treePnt->right == NULL )
        {
            // Set the left as the new node
            treePnt = treePnt->left;
            delete delPtr;

        }else
        {
            // Set followPnt and temp
            followPtr = treePnt;
            temp = treePnt->left;

            // Loop until we reach the bottom
            while( temp->right != NULL )
            {
                followPtr = temp;
                temp = temp->right;

                rightNode = true;
            }

            // Set the new data Node
            treePnt->dataItem = temp->dataItem;

            // Test to see if the new node is right
            if( rightNode )
            {
                followPtr->right = temp->left;

            }else
            {
                followPtr->left = followPtr->left;
                followPtr->left = followPtr->left;
            }

            // Delete node
            delete temp;
        }

        // Set Result
        result = true;
    }

    // Return the result
    return result;
}

/**
 * @brief preorderPrint
 *
 * @details Prints the tree in preorderPrint
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::preorderPrint(BSTNode<AcctType> *treePnt) const
{
    // Variables
    char acctName[ MAX_STR_LEN ];
    char acctType[ MAX_STR_LEN ];
    int acctNum;

    // Test treePnt
    if( treePnt != NULL )
    {
        // Get Account Information
        treePnt->dataItem.getAccount( acctName, acctNum, acctType );
        cout << acctName << endl;

        // print Left and right tree nodes
        preorderPrint( treePnt->left );
        preorderPrint( treePnt->right );
    }
}

/**
 * @brief inorderPrint
 *
 * @details Prints the tree in inorderPrint
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::inorderPrint(BSTNode<AcctType> * treePnt) const
{
    // Variables
    char acctName[ MAX_STR_LEN ];
    char acctType[ MAX_STR_LEN ];
    int acctNum;

    // Test treePnt
    if( treePnt != NULL )
    {
        // Print left pointer
        inorderPrint( treePnt->left );

        // Get Account Information
        treePnt->dataItem.getAccount( acctName, acctNum, acctType );
        cout << acctName << endl;

        // Print right pointer
        inorderPrint( treePnt->right );
    }
}

/**
 * @brief postorderPrint
 *
 * @details Prints the tree in postorderPrint
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class AcctType>
void BSTClass<AcctType>::postorderPrint(BSTNode<AcctType> *treePnt) const
{
    // Variables
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    // Test Treepnt
    if( treePnt != NULL )
    {
        // Print out the left and right treePnt node
        postorderPrint( treePnt->left );
        postorderPrint( treePnt->right );

        // Get account information and print
        treePnt->dataItem.getAccount( acctName, acctNum, acctType );
        cout << acctName << endl;
    }
}

/**
 * @brief getHeightHelper
 *
 * @details finds the height of both sides of the tree
 *
 * @param BSTNode node
 *
 * @note none
 */

template <class AcctType>
int BSTClass<AcctType>::getHeightHelper(BSTNode<AcctType> *treePnt) const
{
    // Variables
    int left;
    int right;

    // Test to see if branch is null
    if(treePnt == NULL)
    {
        // Return 0
        return 0;
    }

    // Get left and right height
    left = getHeightHelper(treePnt->left);
    right = getHeightHelper(treePnt->right);

    // Test the heights
    if(left > right)
    {
        return left + 1;

    }else{

        return right + 1;
    }
}

/**
 * @brief getWidthAtRowHelper
 *
 * @details finds the width at a given row
 *
 * @param node pointer, the height and the given row
 *
 * @note none
 */

template <class AcctType>
int BSTClass<AcctType>::getWidthAtRowHelper(BSTNode<AcctType> *treePnt, int height, int &row) const
{
    // Variables
    int widthR;
    int widthL;

    // Test to see if treePnt is Null
    if(treePnt == NULL)
    {
        return 0;
    }

    // Test height and row
    if(height == row)
    {
        return 1;
    }

    // Go deep into the tree
    widthR = getWidthAtRowHelper(treePnt->right, height+1, row);
    widthL = getWidthAtRowHelper(treePnt->left, height+1, row);

    // Return height
    return widthL + widthR;
}

/**
 * @brief checkDepth
 *
 * @details checks if the depth of the creates a full state
 *
 * @param ind cmdCode and depth
 *
 * @note none
 */

template<class AcctType>
bool BSTClass<AcctType>::checkDepth(int cmdCode, int depth) const
{
    // Variables
    static int depthHolder = 0;
    static int counter = 0;
    static bool fullState = false;
    static bool leftState = false;
    static bool rightState = false;

    switch( cmdCode )
    {
        case INITIALIZE:
            depthHolder = depth;
            break;

        case AT_BOTTOM:
            if( counter == 1 && depth == depthHolder )
            {
                leftState = true;
                fullState = true;
            }

            else if( leftState && !rightState )
            {
                if( depth == depthHolder - 1 )
                {
                    rightState = true;

                    depthHolder = depth;
                }
            }

            else if( leftState && rightState && fullState )
            {
                if( depth != depthHolder )
                {
                    fullState = false;
                }
            }
            break;
    }

    counter++;

    return fullState;
}

/**
 * @brief isCompleteTreeHelper
 *
 * @details loops through and tests to see if the tree creates a complete tree helper
 *
 * @param BSTNode pointer, tested depth and current depth
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::isCompleteTreeHelper( BSTNode<AcctType> *workingPtr, int testDepth, int currentDepth) const
{
    // Variables

    // Test to see if pointer is NUll
    if( workingPtr != NULL )
    {
        isCompleteTreeHelper( workingPtr->left, testDepth, currentDepth + 1 );
        isCompleteTreeHelper( workingPtr->right, testDepth, currentDepth + 1 );
    }else
    {
        checkDepth( AT_BOTTOM, currentDepth - 1 );
    }
}

/**
 * @brief fullTreeHelper
 *
 * @details goes through the tree and test to see if the tree is a full tree
 *
 * @param BSTNode pointer
 *
 * @note none
 */

template <class AcctType>
bool BSTClass<AcctType>::fullTreeHelper(BSTNode<AcctType> *treePnt) const
{
    // Variables
    bool rightSide = false;
    bool leftSide = false;

    // Test to see if empty tree
    if(treePnt == NULL)
    {
        return true;
    }

    // Test the left and right pointers
    if(treePnt->right == NULL && treePnt->left == NULL)
    {
        return true;
    }

    // Look at the subtrees pointers
    if(treePnt->right != NULL && treePnt->left != NULL)
    {
        rightSide = fullTreeHelper(treePnt->right);
        leftSide = fullTreeHelper(treePnt->left);

        return (rightSide && leftSide);
    }

    // If all other test fail return false
    return false;
}

/**
 * @brief showsStructureHelper
 *
 * @details loops throught the tree and prints the struture
 *
 * @param BSTNode pointer, fullHeight, the present height
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::printStructure(BSTNode<AcctType> *treePnt, int fullHeight, int presentHeight) const
{
    // Variables
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    // Test treePnt
    if( treePnt != NULL )
    {
        printStructure( treePnt->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        treePnt->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        printStructure( treePnt->right, fullHeight, presentHeight + 1 );
    }
}

/**
 * @brief showTabs
 *
 * @details prints tabs
 *
 * @param number of tabs
 *
 * @note none
 */

template<class AcctType>
void BSTClass<AcctType>::showTabs(int numTabs) const
{
    // Variables
    int counter;

    // Loop through number of taps
    for( counter = 0; counter < numTabs; counter++ )
    {
        cout << TAB;
    }
}

/**
 * @brief toPower
 *
 * @details finds the result of the exponent
 *
 * @param number of tabs
 *
 * @note none
 */

template<class AcctType>
int BSTClass<AcctType>::toPower
        (
                int base,    // in: base
                int exponent // in: times to multiply base by itself
        ) const
{
    int index, result = 1;

    for( index = 0; index < exponent; index++ )
    {
        result *= base;
    }

    return result;
}

#endif //PROJECT_6_BSTCLASS_CPP
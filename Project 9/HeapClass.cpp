// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Tanner Jones
 *
 * @version 1.00 (11 November 2015)
 *
 * @Note Requires HeapClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HEAP_CLASS_CPP
#define HEAP_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HeapClass.h"
#include <math.h>
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename KeyType, typename DataType>
HeapNode<KeyType, DataType>::HeapNode
        (
                const KeyType &nodeKey,   // in: key value
                const DataType &nodeData, // in: data value
                HeapNode *parentPtr,      // in: parent pointer
                HeapNode *leftPtr,         // in: left node pointer
                HeapNode *rightPtr         // in: right node pointer
        )
        : keyItem( nodeKey ), dataItem( nodeData ), parent( parentPtr ),
          left( leftPtr ), right( rightPtr )
{
    // data placed in initializers
}

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
        (
                // no parameters
        )
        : rootNode( NULL )
{
    // data placed in initializers
}

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
        (
                const HeapClass<KeyType, DataType> &copied
        )
        : rootNode( NULL )
{
    copyTree( copied );
}

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::~HeapClass
        (
                // no parameters
        )
{
    clearTree();
}

template<typename KeyType, typename DataType>
const HeapClass<KeyType, DataType>& HeapClass<KeyType, DataType>:: operator =
        ( const HeapClass &rhTree )
{
    if( this != &rhTree )
    {
        clearTree();
        copyTree( rhTree );
    }

    return *this;
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTree
        (
                const HeapClass<KeyType, DataType> &copiedTree
        )
{
    copyTreeHelper( rootNode, NULL, copiedTree.rootNode );
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTree
        (
                // no parameters
        )
{
    clearTreeHelper( rootNode );

    rootNode = NULL;
}

/**
 * @brief addItem
 *
 * @details adds a new item to the left most bottom node with the help of the helper function
 *
 * @param key number, data information
 *
 * @note none
 */

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItem
        (
                const KeyType &newKey,
                const DataType &newData
        )
{
    // Variables
    HeapNode<KeyType, DataType> * temp = rootNode;

    if(isEmpty())
    {
        rootNode = new HeapNode<KeyType, DataType>(newKey, newData, NULL, NULL, NULL);

    }else {

        addItemHelper(newKey, newData, temp, 0);
    }
}

/**
 * @brief removeItem
 *
 * @details removes the top item and adds the last item to the top
 *
 * @param key number, data information,
 *
 * @note none
 */

template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItem
        (
                DataType &returnedDataItem,
                KeyType &returnedKeyItem
        )
{
    // Variables
    HeapNode<KeyType, DataType> * temp = rootNode;

    // Test to see if the tree is empty
    if(isEmpty())
    {
        return false;
    }

    // Assign Returned values
    returnedDataItem = rootNode->dataItem;
    returnedKeyItem = rootNode->keyItem;

    // Test Rootnode
    if(rootNode->left == NULL && rootNode->right == NULL)
    {
        delete rootNode;
        rootNode = NULL;
    }else{
        removeItemHelper(temp,0);
    }

    return true;
}

template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::isEmpty
        (
                // no parameters
        ) const
{
    return ( rootNode == NULL );
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversal
        (
                // no parameters
        ) const
{
    if( rootNode != NULL )
    {
        preOrderTraversalHelper( rootNode );
        cout << endl;
    }

    else
    {
        cout << "Tree is empty" << endl;
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversal
        (
                // no parameters
        ) const
{
    if( rootNode != NULL )
    {
        inOrderTraversalHelper( rootNode );
        cout << endl;
    }

    else
    {
        cout << "Tree is empty" << endl;
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversal
        (
                // no parameters
        ) const
{
    if( rootNode != NULL )
    {
        postOrderTraversalHelper( rootNode );
        cout << endl;
    }

    else
    {
        cout << "Tree is empty" << endl;
    }
}

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getLeftHeight
        (
                // no parameters
        ) const
{
    return getHeightHelper( rootNode, 'L' );
}

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getRightHeight
        (
                // no parameters
        ) const
{
    return getHeightHelper( rootNode, 'R' );
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructure
        (
                // no parameters
        ) const
{
    int height = getLeftHeight();

    if( rootNode != NULL )
    {
        showStructureHelper( rootNode, height, 0 );

        cout << endl << "Left Height: " << getLeftHeight()
        << ", Right Height: "  << getRightHeight() << endl;
    }

    else
    {
        cout << "Empty Tree" << endl;
    }

    cout << endl;
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructureHelper
        (
                HeapNode<KeyType, DataType> *workingPtr,
                int fullHeight,
                int presentHeight
        ) const
{
    char patientName[ MAX_STR_LEN ], medicalCode[ MAX_STR_LEN ];
    char patientGender;

    if( workingPtr != NULL )
    {
        showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        workingPtr->dataItem.getAccount( patientName, medicalCode, patientGender );

        cout << patientName;

        cout << ", " << int( workingPtr->keyItem ) << endl;

        showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
    }
}

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getHeightHelper
        (
                HeapNode<KeyType, DataType> *workingPtr,
                char leftRightIndicator
        ) const
{
    if( workingPtr != NULL )
    {
        if( leftRightIndicator == 'L' )
        {
            return 1 + getHeightHelper( workingPtr->left, leftRightIndicator );
        }

        return 1 + getHeightHelper( workingPtr->right, leftRightIndicator );
    }

    return 0;
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTreeHelper
        (
                HeapNode<KeyType, DataType> *&workingPtr,      // local working pointer
                HeapNode<KeyType, DataType> *parentPtr,      // local parent pointer
                const HeapNode<KeyType, DataType> *sourcePtr  // incoming source pointer
        )
{
    if( sourcePtr != NULL )
    {
        workingPtr = new HeapNode<KeyType, DataType>( sourcePtr->keyItem,
                                                      sourcePtr->dataItem, parentPtr, NULL, NULL );
        copyTreeHelper( workingPtr->left, workingPtr, sourcePtr->left );
        copyTreeHelper( workingPtr->right, workingPtr, sourcePtr->right );
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTreeHelper
        (
                HeapNode<KeyType, DataType> *workingPtr
        )
{
    if ( workingPtr != NULL )
    {
        clearTreeHelper( workingPtr->left );
        clearTreeHelper( workingPtr->right );
        delete workingPtr;
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversalHelper
        (
                HeapNode<KeyType, DataType> *workingPtr
        ) const
{
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
    {
        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        preOrderTraversalHelper( workingPtr->left );

        preOrderTraversalHelper( workingPtr->right );
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversalHelper
        (
                HeapNode<KeyType, DataType> *workingPtr
        ) const
{
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
    {
        inOrderTraversalHelper( workingPtr->left );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        inOrderTraversalHelper( workingPtr->right );
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversalHelper
        (
                HeapNode<KeyType, DataType> *workingPtr
        ) const
{
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
    {
        postOrderTraversalHelper( workingPtr->left );

        postOrderTraversalHelper( workingPtr->right );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;
    }
}

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showTabs
        (
                int numTabs
        ) const
{
    int counter;

    for( counter = 0; counter < numTabs; counter++ )
    {
        cout << TAB;
    }
}

/**
 * @brief addItemHelper
 *
 * @details adds a new item to the left most bottom node
 *
 * @param key number, data information, heap pointer, and the current height
 *
 * @note none
 */

template <typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::addItemHelper(const KeyType &newKey, const DataType &newData,
                                                 HeapNode<KeyType, DataType> *workingPtr, int height)
{
    // Variables
    int length = getLeftHeight() - 1;
    int maxwidth = pow(2, length - height);
    int width = getWidthAtRow(workingPtr, height, length);

    // Check left node
    if(workingPtr->left == NULL)
    {
        // Insert Node
        workingPtr->left = new HeapNode<KeyType,DataType>(newKey, newData,workingPtr, NULL, NULL);

        // Shuffle the nodes up
        bubbleUp(workingPtr->left);

        // Return true
        return true;

    }

    // Check right node
    if(workingPtr->right == NULL)
    {
        // Insert Node
        workingPtr->right = new HeapNode<KeyType,DataType>(newKey, newData,workingPtr, NULL, NULL);

        // Shuffle the nodes up
        bubbleUp(workingPtr->right);

        // Return true
        return true;
    }

    // Test width
    if(width < maxwidth/2 || width == maxwidth)
    {
        addItemHelper(newKey, newData, workingPtr->left, height+1);
    }else{
        addItemHelper(newKey, newData, workingPtr->right, height+1);
    }

}

/**
 * @brief bubbleUp
 *
 * @details moves the smaller items up the tree
 *
 * @param node pointer
 *
 * @note none
 */

template <typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::bubbleUp(HeapNode<KeyType, DataType> *insertedNode)
{
    // Variables
    HeapNode<KeyType, DataType> temp(insertedNode->keyItem, insertedNode->dataItem, NULL, NULL, NULL);

    // Test the insertedNode and parent
    if(insertedNode->parent != NULL)
    {
        // Test to see if nodes need to be switched
        if (insertedNode->keyItem < insertedNode->parent->keyItem )
        {

            insertedNode->keyItem = insertedNode->parent->keyItem;
            insertedNode->dataItem = insertedNode->parent->dataItem;

            insertedNode->parent->keyItem = temp.keyItem;
            insertedNode->parent->dataItem = temp.dataItem;

            bubbleUp(insertedNode->parent);
        }
    }
}

/**
 * @brief getWidthAtRow
 *
 * @details finds the width at a given row
 *
 * @param node pointer, the height
 *
 * @note none
 */

template <typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getWidthAtRow(HeapNode<KeyType, DataType> *workingPtr, int height, int &row) const
{
    // Variables
    int widthR;
    int widthL;

    // Test to see if treePnt is Null
    if(workingPtr == NULL)
    {
        return 0;
    }

    // Test height and row
    if(height == row)
    {
        return 1;
    }

    // Go deep into the tree
    widthR = getWidthAtRow(workingPtr->right, height+1, row);
    widthL = getWidthAtRow(workingPtr->left, height+1, row);

    // Return height
    return widthL + widthR;
}

/**
 * @brief removeItemHelper
 *
 * @details deletes the top node and moves the last node added to the top
 *
 * @param node pointer, the height
 *
 * @note none
 */

template <typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItemHelper(HeapNode<KeyType, DataType> *workingPtr, int height)
{
    // Variables
    int length = getLeftHeight() - 1;
    int maxwidth = pow(2, length - height);
    int width = getWidthAtRow(workingPtr, height, length);
    HeapNode<KeyType, DataType> *temp = workingPtr;

    // Check workingPtr
    if(workingPtr->left == NULL && workingPtr->right == NULL)
    {
        // Set Root node
        rootNode->dataItem = workingPtr->dataItem;
        rootNode->keyItem = workingPtr->keyItem;

        // Move working pointer
        workingPtr = workingPtr->parent;

        // Delete pointer node
        if(workingPtr->left == temp)
        {
            delete workingPtr->left;
            workingPtr->left = NULL;
        }else{
            delete workingPtr->right;
            workingPtr->right = NULL;
        }

        // Set Temp
        temp = NULL;

        // Shuffle down the tree
        bubbleDown(rootNode);

        // Return true
        return true;
    }

    // Test width
    if(width <= maxwidth/2 && width != maxwidth)
    {
        removeItemHelper(workingPtr->left, height+1);
    }else{
        removeItemHelper(workingPtr->right, height+1);
    }
}

/**
 * @brief bubbleDown
 *
 * @details moves the lowest values to the top of the tree
 *
 * @param node pointer
 *
 * @note none
 */

template <typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::bubbleDown(HeapNode<KeyType, DataType> *removedNode)
{
    // Variables
    HeapNode<KeyType, DataType> temp(removedNode->keyItem, removedNode->dataItem, NULL, NULL, NULL);

    // Test if both child nodes are not Null
    if(removedNode->left != NULL && removedNode->right != NULL)
    {
        // Test to see if which node is smaller
        if(removedNode->left->keyItem < removedNode->right->keyItem)
        {
            // Test to see if nodes need to be switched
            if(removedNode->left->keyItem < removedNode->keyItem)
            {
                removedNode->keyItem = removedNode->left->keyItem;
                removedNode->dataItem = removedNode->left->dataItem;

                removedNode->left->keyItem = temp.keyItem;
                removedNode->left->dataItem = temp.dataItem;

                bubbleDown(removedNode->left);
            }

        }else
        {
            // Test to see if nodes need to be switched
            if(removedNode->right->keyItem < removedNode->keyItem)
            {
                removedNode->keyItem = removedNode->right->keyItem;
                removedNode->dataItem = removedNode->right->dataItem;

                removedNode->right->keyItem = temp.keyItem;
                removedNode->right->dataItem = temp.dataItem;

                bubbleDown(removedNode->right);
            }
        }
    }

    // Test if either nodes are either NULL
    if(removedNode->left == NULL || removedNode->right == NULL)
    {
        // Test to see if left child is null and right is smaller
        if(removedNode->left == NULL && removedNode->right->keyItem < removedNode->keyItem)
        {
            removedNode->keyItem = removedNode->right->keyItem;
            removedNode->dataItem = removedNode->right->dataItem;

            removedNode->right->keyItem = temp.keyItem;
            removedNode->right->dataItem = temp.dataItem;

            bubbleDown(removedNode->right);
        }

        // Test to see if right child is Null and left is smaller
        if(removedNode->right == NULL && removedNode->left->keyItem < removedNode->keyItem)
        {
            removedNode->keyItem = removedNode->left->keyItem;
            removedNode->dataItem = removedNode->left->dataItem;

            removedNode->left->keyItem = temp.keyItem;
            removedNode->left->dataItem = temp.dataItem;

            bubbleDown(removedNode->left);
        }
    }
}
#endif	// define HEAP_CLASS_CPP
// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.h
 *
 * @brief Definition file for Binary Search Tree class
 *
 * @details Defines all given functions of the BST class
 *
 * @author Tanner Jones
 *
 * @version 1.00 (21 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////
#ifndef CURRENT_PROJECT_BSTCLASS_H
#define CURRENT_PROJECT_BSTCLASS_H

// Header files ///////////////////////////////////////////////////////////////
#include "AcctType.h"

// Class constants ////////////////////////////////////////////////////////////

// None

// Class definition ///////////////////////////////////////////////////////////

template <class AcctType>
class BSTNode
{
public:

    // Member Function
    BSTNode( const AcctType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr );

    AcctType dataItem;

    BSTNode<AcctType> *left;
    BSTNode<AcctType> *right;
};

template <class AcctType>
class BSTClass
{
public:

    // constants
    static const char TAB = '\t';
    static const int MAX_STR_LEN = 80;
    static const int INITIALIZE = 101;
    static const int AT_BOTTOM = 102;
    static const int GET_RESULT = 103;

    // constructor
    BSTClass();
    BSTClass( const BSTClass<AcctType> &copied );

    // destructor
    ~BSTClass();

    // assignment operator
    const BSTClass &operator = (const BSTClass<AcctType> &rhData );

    // modifiers
    void copyTree( const BSTClass<AcctType> &copied );
    void clearTree();
    void insert( const AcctType &newData );
    bool findItem( const AcctType &searchDataItem ) const;
    bool removeItem( const AcctType &dataItem );

    // accessors
    bool isEmpty() const;
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    int getHeight() const;
    int getWidthAtRow( int row ) const;                       // assigned
    void getMaxWidth( int &maxWidth, int &maxWidthRow ) const;  // assigned
    void getMinWidth( int &minWidth, int &minWidthRow ) const;  // assigned
    int getBottomWidth() const;                               // assigned
    bool isCompleteTree() const;
    bool isFullTree() const;
    void showStructure() const;

private:
    // Private Member Function
    void showStructureHelper( BSTNode<AcctType> *workingPtr, int fullHeight, int presentHeight ) const;
    int getHeightHelper( BSTNode<AcctType> *workingPtr ) const;
    void copyTreeHelper( BSTNode<AcctType> *&workingPtr,const BSTNode<AcctType> *sourcePtr );
    void clearTreeHelper( BSTNode<AcctType> *workingPtr );
    void insertHelper( BSTNode<AcctType> *&workingPtr, const AcctType &newData );
    void isCompleteTreeHelper( BSTNode<AcctType> *workingPtr,int testDepth, int currentDepth ) const;
    void preOrderTraversalHelper( BSTNode<AcctType> *workingPtr) const;
    void inOrderTraversalHelper( BSTNode<AcctType> *workingPtr) const;
    void postOrderTraversalHelper( BSTNode<AcctType> *workingPtr) const;
    void showTabs( int numTabs ) const;
    bool checkDepth( int cmdCode, int depth ) const;
    int toPower( int base, int exponent ) const;

    // Private Member Data Members
    BSTNode<AcctType> *rootNode;
};


#endif //CURRENT_PROJECT_BSTCLASS_H

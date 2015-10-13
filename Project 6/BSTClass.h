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
 * @version 1.00 (15 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////
#ifndef PROJECT_6_BSTCLASS_H
#define PROJECT_6_BSTCLASS_H

// Header files ///////////////////////////////////////////////////////////////
#include "NameType.h"

// Class constants ////////////////////////////////////////////////////////////

    // None

// Class definition ///////////////////////////////////////////////////////////

template <class NameType>
class BSTNode
{
    public:

        // Member Function
        BSTNode( const NameType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr );

        NameType dataItem;

        BSTNode<NameType> *left;
        BSTNode<NameType> *right;
};

template <class NameType>
class BSTClass
{
    public:

        // constants
        static const char TAB = '\t';

        // constructor
        BSTClass();
        BSTClass( const BSTClass<NameType> &copied );

        // destructor
        ~BSTClass();

        // assignment operator
        const BSTClass &operator = (const BSTClass<NameType> &rhData );

        // modifiers
        void copyTree( const BSTClass<NameType> &copied );
        void clearTree();
        void insert( const NameType &newData );
        bool findItem( const NameType &searchDataItem ) const;
        bool removeItem( const NameType &dataItem );

        // accessors
        bool isEmpty() const;
        void preOrderTraversal() const;
        void inOrderTraversal() const;
        void postOrderTraversal() const;
        int getHeight() const;
        void showStructure() const;

    private:
        // Variables
        BSTNode<NameType> *rootNode;

        // Member Functions
        BSTNode<NameType> * branchLoop(const BSTNode<NameType> * treePnt);
        void deleteTree(BSTNode<NameType> * treePnt);
};

#endif //PROJECT_6_BSTCLASS_H

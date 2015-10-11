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

#include "BSTClass_PublicMethods.h"
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
 * @param None
 *
 * @note set running flag to false
 */
 
template <typename DataType>
BSTNode::BSTNode( const DataType &nodeData, BSTNode * leftPtr, BSTNode * rightPtr)
        :left(leftPtr),
         right(rightPtr),
         dataItem(nodeData)
{
    
}
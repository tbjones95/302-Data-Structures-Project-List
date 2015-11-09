// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.h
 *
 * @brief Definition file for class that attempts to locate smaller
 *        inside a larger container rectangle
 *
 * @author Tanner Jones
 *
 * @details Specifies all member methods of the Solver class
 *
 * @version 1.00 (4 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CURRENT_PROJECT_SOLVERCLASS_H
#define CURRENT_PROJECT_SOLVERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "Rectangle.h"
#include "SimpleMatrix.h"

// Class definition  //////////////////////////////////////////////////////////

#include "SimpleMatrix.h"

class SolverClass
{
    public:

        // constructor
        SolverClass();

        // destructor
        ~SolverClass( );

        // modifiers
        bool findSolution();
        bool setContainerRectangle( int height, int width );
        bool addInsideRectangle( int height, int width );
        void setDisplayFlag( bool setFlag );
        void displayField() const;

    private:

        // Private Data members
        SimpleMatrix<char> * container;
        SimpleVector<Rectangle> rectangles;
        bool displayFlag;

        // Private Functions
        bool solutionHelper(int recUsed, int numRec);
        void findOpenSpace(int &row, int &col);
        void findOpenArea(int &row, int &col);
        bool findNextRect(int &numberOfRec, Rectangle &nonUsed);
        bool matrixTest(Rectangle &testRec, bool rotateFlag);
        void insertRec(int testRow, int testCol, Rectangle newRec, int index);
        void removeRec(int testRow, int testCol, Rectangle oldRec, int index);

};

#endif //CURRENT_PROJECT_SOLVERCLASS_H

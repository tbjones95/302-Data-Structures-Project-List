// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.cpp
 *
 * @author Tanner Jones
 *
 * @brief Implementation file for SolverClass class
 *
 * @details Implements all member methods of the SolverClass class
 *
 * @version 1.00 (11 November 2015)
 *
 * @Note Requires SolverClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

    // None

// Header files ///////////////////////////////////////////////////////////////

#include "SolverClass.h"
#include "SimpleMatrix.cpp"
#include "SimpleVector.cpp"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor
 *
 * @details Constructs a solver class by making a simple matrix and simple vector
 *          to hold all the rectangle data
 *
 * @param None
 *
 * @note None
 */

SolverClass::SolverClass()
            :container (NULL),
             displayFlag (false)
{

}

/**
 * @brief Default destructor
 *
 * @details destructs the solver class
 *
 * @param None
 *
 * @note None
 */

SolverClass::~SolverClass()
{
    // Variables

    // Deletes container pointer
    delete container;
    container = NULL;
}

/**
 * @brief findSolution
 *
 * @details finds out if there's a solution with the rectangles
 *
 * @param None
 *
 * @note None
 */

bool SolverClass::findSolution()
{
    // Variables

    // Test for a solution
    if(solutionHelper(0, rectangles.getSize()))
    {
        // Set print flag
        setDisplayFlag(true);

        // Print container
        displayField();

        // Return true
        return true;
    }

    // Return false
    return false;
}

/**
 * @brief setContainerRectangle
 *
 * @details sets up a container to hold rectangles
 *
 * @param height and a width
 *
 * @note None
 */

bool SolverClass::setContainerRectangle(int height, int width)
{
    // Variables

    // Set Container
    if(container == NULL)
    {
        // Create a new matrix
        container = new SimpleMatrix<char>(height, width, 'O');

        // Return true
        return true;
    }

    // Return false
    return false;
}

/**
 * @brief addInsideTectangle
 *
 * @details sets up a vector to hold rectangles to inset to the matrix
 *
 * @param height and a width
 *
 * @note None
 */

bool SolverClass::addInsideRectangle(int height, int width)
{
    // Variables
    int size = rectangles.getSize();
    char id = 'A';

    // Test to see if height and width are smaller then matrix
    if(height < container->getNumRows() && width < container->getNumCols())
    {
        // Increase size
        id += size;

        // Set height and width
        rectangles[size].setHeight(height);
        rectangles[size].setWidth(width);
        rectangles[size].setIDLetter(id);
        rectangles[size].setUsedState(false);

        // Increment size
        rectangles.incrementSize();

        // Return true
        return true;
    }

    // Return false if failed
    return false;
}

/**
 * @brief setDisplayFlag
 *
 * @details sets the displayFlag
 *
 * @param bool setFlag
 *
 * @note None
 */

void SolverClass::setDisplayFlag(bool setFlag)
{
    // Variables

    displayFlag = setFlag;
}

/**
 * @brief displayField
 *
 * @details prints out the matrix
 *
 * @param None
 *
 * @note None
 */

void SolverClass::displayField() const
{
    // Variables
    int rowIndex;
    int colIndex;
    char value;

    // Test the displayFlag
    if(displayFlag)
    {
        // Loop through the matrix
        for(rowIndex = 0; rowIndex < container->getNumRows(); rowIndex++)
        {
            for(colIndex = 0; colIndex < container->getNumCols(); colIndex++)
            {
                // Get value
                container->getValueAt(rowIndex, colIndex, value);

                // Print value
                cout << value << " ";
            }

            cout << endl;
        }
    }
}

/**
 * @brief solutionHelper
 *
 * @details finds a solution
 *
 * @param number of rectangle used and number of rectangles
 *
 * @note None
 */

bool SolverClass::solutionHelper(int recUsed, int numRec)
{
    // Variables
    int index;
    int openRow;
    int openCol;
    Rectangle currentRec;

    // Test recUsed and num Rec
    if(recUsed == numRec)
    {
        return true;
    }

    // Loop through rectangles
    for(index = 0; index < numRec; index++)
    {
        // Get next rectangle
        findNextRect(index, currentRec);

        // Test the rectangle
        if(matrixTest(currentRec,false))
        {
            // Insert Rect
            insertRec(openRow, openCol, currentRec, index);

            // Solve the next rect
            if (solutionHelper(recUsed + 1, numRec)) {
                return true;
            }

            // Remove Rect
            removeRec(openRow, openCol, currentRec, index);

        }

        if(matrixTest(currentRec,true))
        {
            // Insert Rect
            insertRec(openRow, openCol, currentRec, index);

            // Solve the next rect
            if(solutionHelper(recUsed + 1, numRec))
            {
                return true;
            }
        }

        // Remove Rect
        removeRec(openRow, openCol, currentRec, index);
    }

    // Can't find a solution
    return false;
}

/**
 * @brief findOpenSpace
 *
 * @details finds the first open spot
 *
 * @param row and col
 *
 * @note None
 */

void SolverClass::findOpenSpace(int &row, int &col)
{
    // Variables
    char test;

    // Set row and col
    row = 0;
    col = 0;

    // Prime Loop
    container->getValueAt(row, col, test);

    // Loop through the matrix to get starting position
    for(col = 0; col < container->getNumCols(); col++)
    {
        for(row = 0; row < container->getNumRows(); row++)
        {
            // Get Value
            container->getValueAt(row, col, test);

            // Test if O
            if(test == 'O')
            {
                return;
            }
        }
    }
}

/**
 * @brief findOpenArea
 *
 * @details finds the open area for a retangle
 *
 * @param row and col
 *
 * @note None
 */

void SolverClass::findOpenArea(int &row, int &col)
{
    // Variables
    int difRow = 0;
    int difCol = 0;
    int tempRow = row;
    char test;

    // Prime loop
    container->getValueAt(row, col, test);

    // Loop through the rows
    while(row < container->getNumRows() && test == 'O')
    {
        // Increase row
        difRow++;

        // Get Value
        container->getValueAt(row, col, test);

        // Move Down
        row++;
    }

    // Reset Row
    row = tempRow;

    // Prime loop
    container->getValueAt(row, col, test);

    // Loop through the rows
    while(col < container->getNumCols() && test == 'O')
    {
        // Increase row
        difCol++;

        // Get Value
        container->getValueAt(row, col, test);

        col++;
    }

    // Assign row and col
    row = difRow;
    col = difCol;
}


/**
 * @brief findNextRect
 *
 * @details finds the next rectangle
 *
 * @param number of rectangle, rectangle
 *
 * @note None
 */

bool SolverClass::findNextRect(int &numberOfRec, Rectangle &nonUsed)
{
    // Variables
    Rectangle temp;

    // Test current rectangle
    if(!rectangles[numberOfRec].isUsed())
    {
        // Get rectangle
        rectangles.getValueAt(numberOfRec, temp);

        // Set nonUsed
        nonUsed = temp;

        // Return temp
        return true;
    }

    for(numberOfRec = 0; numberOfRec < rectangles.getSize(); numberOfRec++)
    {
        // Test current rectangle
        if(!rectangles[numberOfRec].isUsed())
        {
            // Get rectangle
            rectangles.getValueAt(numberOfRec, temp);

            // Set nonUsed
            nonUsed = temp;

            // Return temp
            return true;
        }
    }

    // Return false
    return false;
}

/**
 * @brief matrixTest
 *
 * @details tests if the rectangle will fit
 *
 * @param rectangle, rotate flag
 *
 * @note None
 */

bool SolverClass::matrixTest(Rectangle &testRec, bool rotateFlag)
{
    // Variables
    int height;
    int width;

    // Find Starting area
    findOpenSpace(height, width);

    // Find Area
    findOpenArea(height, width);

    // Test
    if(rotateFlag)
    {
        // Rotate Flag
        testRec.rotate();

        // Test if it will fit
        if(testRec.getWidth() <= width && testRec.getHeight() <= height)
        {
            return true;
        }
    }

    // Test if it will fit normally
    if((testRec.getWidth() <= width) && (testRec.getHeight() <= height))
    {
        return true;
    }else
    {

        // Rotate Flag
        testRec.rotate();

        // Test if it will fit
        if(testRec.getWidth() <= width && testRec.getHeight() <= height)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief insertRec
 *
 * @details inserts a rectangle
 *
 * @param row, col,rectangle, and index of rectangle
 *
 * @note None
 */

void SolverClass::insertRec(int testRow, int testCol, Rectangle newRec, int index)
{
    // Variables
    int heightPos;
    int widthPos;
    int tempHeight;
    int tempWidth;
    char value;

    // Find Starting area
    findOpenSpace(heightPos, widthPos);

    // Set Test row and col
    testCol = widthPos;
    testRow = heightPos;

    // Set value
    value = newRec.getIDLetter();

    // Insert triangle
    for(tempWidth = 0; tempWidth < newRec.getWidth(); tempWidth++)
    {
        for (tempHeight = 0; tempHeight < newRec.getHeight(); tempHeight++)
        {
            // Insert rectangle
            container->setValueAt(heightPos, widthPos, value);

            // Increase height
            heightPos++;
        }

        // Reset Height
        heightPos = testRow;

        // Increase width
        widthPos++;
    }

    // Set Rectangle as used
    rectangles[index].setUsedState(true);
}

/**
 * @brief removeRec
 *
 * @details removes a rectangle in which didnt work
 *
 * @param row, col, rectangle, and index of rectangle
 *
 * @note None
 */

void SolverClass::removeRec(int testRow, int testCol, Rectangle oldRec, int index)
{
    // Variables
    char value = 'O';
    int tempHeight;
    int tempWidth;
    int heightPos = testRow;
    int widthPos = testCol;

    // Insert triangle
    for(tempWidth = 0; tempWidth < oldRec.getWidth(); tempWidth++)
    {
        for (tempHeight = 0; tempHeight < oldRec.getHeight(); tempHeight++)
        {
            // Insert rectangle
            container->setValueAt(heightPos, widthPos, value);

            // Increase height
            heightPos++;
        }

        // Reset Height
        heightPos = testRow;

        // Increase width
        widthPos++;
    }

    // Set Rectangle as used
    rectangles[index].setUsedState(false);
}
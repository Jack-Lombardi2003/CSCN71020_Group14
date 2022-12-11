#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "rectangleSolver.h"

//Taiyo Suzuki, Jack Lombardi
//December 2022
//Write a program with 2 functionalities:
//1. Accept 3 user input numbers, check if they make a triangle, and if they do, display what type of triangle it is 
//and calculate and display the inside angles between the sides.
//2. Accept 4 user input points as x/y pairs (x, y), generate lines between the points and determine if they form a rectangle.
//Report the perimiter of the shape, and if it is a rectangle, report the area. To create the rectangle, 
//determine which corner each point is by calculation, then connect each corner in order. This eliminates the possibility of lines crossing.

#define NUMBER_OF_POINTS 4

char* analyzeRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	char* result = "";

	double xCoords[NUMBER_OF_POINTS] = { x1, x2, x3, x4 };
	double yCoords[NUMBER_OF_POINTS] = { y1, y2, y3, y4 };

	double side1 = x1 + x2 && y1 + y2; 
	double side2 = x2 + x3 && y2 + y3;
	double side3 = x3 + x4 && y3 + y4;
	double side4 = x4 + x1 && y4 + y1;

	if (x1 <= 0 || x2 <= 0 || x3 <= 0 || x4 <= 0 || y1 <= 0 || y2 <= 0 || y3 <= 0 || y4 <= 0)			//rectangle points can't be less than or equal to zero
	{
		result = "Not a rectangle";
		return result;
	}
	else if(side1 == side2 && side2 == side3 && side3 == side4 && side4 == side1)
	{
		result = "\nYou Entered a Square";
		return result;
	}
	else if(side1 == side3 && side2 == side4)
	{
		double rectangleArea = side1 * side2;
		result = "\nYou Entered a Rectangle";
		return result;
		printf("\n%d", rectangleArea);
	}


	return result;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

//Taiyo Suzuki, Jack Lombardi
//December 2022
//Write a program with 2 functionalities:
//1. Accept 3 user input numbers, check if they make a triangle, and if they do, display what type of triangle it is 
//and calculate and display the inside angles between the sides.
//2. Accept 4 user input points as x/y pairs (x, y), generate lines between the points and determine if they form a rectangle.
//Report the perimiter of the shape, and if it is a rectangle, report the area. To create the rectangle, 
//determine which corner each point is by calculation, then connect each corner in order. This eliminates the possibility of lines crossing.

int side = 0;

int main() {

	bool continueProgram = true;

	while (continueProgram) {

		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 0:																								//case 0: exit (written as case 0)
			continueProgram = false;
			break;

		case 1:																								//case 1: triangle checking
			printf_s("\nTriangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;

		case 2:																								//case 2: rectangle checking
			printf_s("\nRectangle selected.\n");
			int rectangleCorners[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectangleCornersPtr = getRectangleCorners(rectangleCorners);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result2 = analyzeRectangle(rectangleCornersPtr[0], rectangleCornersPtr[1], rectangleCornersPtr[2], rectangleCornersPtr[3], 
				rectangleCornersPtr[4], rectangleCornersPtr[5], rectangleCornersPtr[6], rectangleCornersPtr[7]);
			printf_s("%s\n", result2);
			break;

		default:
			printf_s("Invalid value entered.\n");															//default case (number input other than 0-2)
			break;
		}
	}
	return 0;
}

void printWelcome() {																						//print welcome header
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon-Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {																						//print function menu
	printf_s("\n");
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("\nEnter number\n>");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {																	//get triangle input
	printf_s("Enter the three sides of the triangle\n>");
	for (int i = 0; i < 3; i++)
	{
		if (scanf_s("%d", &triangleSides[i]) == 0)
		{
			printf_s("\nInvalid input. Please try again\n");												//check if input is an int
			exit(1);
		}
	}

	return triangleSides;
}

int* getRectangleCorners(int* rectangleCorners) {															//get triangle input
	printf_s("Enter the corner point values (x, y) one at a time, x then y. \nExample: points - (1,2) (3,4) (5,6) (7,8) input - 1 2 3 4 5 6 7 8\n>");
	for (int i = 0; i < 8; i++)
	{
		if (scanf_s("%d", &rectangleCorners[i]) == 0)
		{
			printf_s("\nInvalid input. Please try again\n");												//check if input is an int
			exit(1);
		}
	}
	return rectangleCorners;
}
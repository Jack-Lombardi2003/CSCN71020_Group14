#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "triangleSolver.h"

//Taiyo Suzuki, Jack Lombardi, Logan Haiser
//December 2022
//Write a program with 2 functionalities:
//1. Accept 3 user input numbers, check if they make a triangle, and if they do, display what type of triangle it is 
//and calculate and display the inside angles between the sides.
//2. Accept 4 user input points as x/y pairs (x, y), generate lines between the points and determine if they form a rectangle.
//Report the perimiter of the shape, and if it is a rectangle, report the area. To create the rectangle, 
//determine which corner each point is by calculation, then connect each corner in order. This eliminates the possibility of lines crossing.

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = "";
	char* buffer = "";
	double angles = -1;
	int anglesInt = -1;

	if (side1 <= 0 || side2 <= 0 || side3 <= 0)				//triangle sides can't be less than or equal to zero
	{
		result = "Not a triangle";
		return result;
	}														//a triangle is valid if it satisfies three conditions: (a + b > c) (a + c > b) (b + c > a)
	else if(side1 + side2 < side3 || side2 + side3 < side1 || side1 + side3 < side2)
	{
		result = "Not a triangle";
		return result;
	}
	else if (side1 == side2 && side1 == side3)				//all equal sides == equilateral triangle
	{			
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2) || 
		(side2 == side3 && side2 != side1))					//2 sides the same == isosceles triangle
	{
		result = "Isosceles triangle";
	}
	else													//all other triangles are scalene
	{													
		result = "Scalene triangle";
	}

	angles = ((pow(side2, 2)) + (pow(side3, 2))) - ((pow(side1, 2)) / (2*side2*side3));	//cosine law for angle 1
	anglesInt = angles;

	//_itoa(anglesInt, &buffer, 10);														//works for int to char, not sure about double value

	//figure out how to add buffer string onto end of result string with a whitespace character in between
	
	//then, solve for 2 other angles and add them onto the end of the string as well (with spaces and labels i.e. angle 1 = "" angle 2 = "" etc.)
	
	return result;
}
#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

//Taiyo Suzuki, Jack Lombardi, Logan Haiser
//December 2022
//Write a program with 2 functionalities:
//1. Accept 3 user input numbers, check if they make a triangle, and if they do, display what type of triangle it is 
//and calculate and display the inside angles between the sides.
//2. Accept 4 user input points as x/y pairs (x, y), generate lines between the points and determine if they form a rectangle.
//Report the perimiter of the shape, and if it is a rectangle, report the area. To create the rectangle, 
//determine which corner each point is by calculation, then connect each corner in order. This eliminates the possibility of lines crossing.

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
															//a triangle is valid if it satisfies three conditions: (a + b > c) (a + c > b) (b + c > a)

	if (side1 <= 0 || side2 <= 0 || side3 <= 0)				//triangle sides can't be less than or equal to zero
	{			
		result = "Not a triangle";
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

	return result;
}
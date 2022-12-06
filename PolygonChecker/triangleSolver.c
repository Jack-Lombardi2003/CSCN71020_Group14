#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "triangleSolver.h"

//Taiyo Suzuki, Jack Lombardi
//December 2022
//Write a program with 2 functionalities:
//1. Accept 3 user input numbers, check if they make a triangle, and if they do, display what type of triangle it is 
//and calculate and display the inside angles between the sides.
//2. Accept 4 user input points as x/y pairs (x, y), generate lines between the points and determine if they form a rectangle.
//Report the perimiter of the shape, and if it is a rectangle, report the area. To create the rectangle, 
//determine which corner each point is by calculation, then connect each corner in order. This eliminates the possibility of lines crossing.

#define BUFFER_SIZE 256

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = malloc(sizeof(char) * BUFFER_SIZE);
	double angle1, angle2, angle3;

	if (side1 <= 0 || side2 <= 0 || side3 <= 0)			//triangle sides can't be less than or equal to zero
	{
		result = "Not a triangle";
		return result;
	}													//a triangle is valid if it satisfies three conditions: (a + b > c) (a + c > b) (b + c > a)
	else if(side1 + side2 < side3 || side2 + side3 < side1 || side1 + side3 < side2)
	{
		result = "Not a triangle";
		return result;
	}
	else if (side1 == side2 && side1 == side3)			//all equal sides == equilateral triangle
	{			
		result = "\nEquilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2) || 
		(side2 == side3 && side2 != side1))				//2 sides the same == isosceles triangle
	{
		result = "\nIsosceles triangle";
	}
	else												//all other triangles are scalene
	{													
		result = "\nScalene triangle";
	}

	angle1 = ((pow(side2, 2)) + (pow(side3, 2))) - ((pow(side1, 2)) / (2*side2*side3));		//cosine law for angle 1

	char* angleBuffer1 = malloc(sizeof(char) * BUFFER_SIZE);
	snprintf(angleBuffer1, sizeof(angleBuffer1), " %.2f,", angle1);							//write angle 1 to string

	angle2 = ((pow(side1, 2)) + (pow(side3, 2))) - ((pow(side2, 2)) / (2 * side1 * side3));	//cosine law for angle 2

	char* angleBuffer2 = malloc(sizeof(char) * BUFFER_SIZE);
	snprintf(angleBuffer2, sizeof(angleBuffer2), " %.2f,", angle2);							//write angle 2 to string

	angle3 = ((pow(side2, 2)) + (pow(side1, 2))) - ((pow(side3, 2)) / (2 * side2 * side1));	//cosine law for angle 3

	char* angleBuffer3 = malloc(sizeof(char) * BUFFER_SIZE);
	snprintf(angleBuffer3, sizeof(angleBuffer3), " %.2f", angle3);							//write angle 3 to string

	char* angleLabel = "\nInterior angles:";												//for output (once all strings are added together, output should look like "Interior angles: x, y, z")

	int newBufSize = strlen(result) + strlen(angleLabel) + strlen(angleBuffer1) + strlen(angleBuffer2) + strlen(angleBuffer3)+1;
	char* resultBuffer = (char*)malloc(newBufSize);											//create new buffer and allocate memory

	strcpy(resultBuffer, result);															//copy triangle type (stored in result) and angles to buffer
	strcat(resultBuffer, angleLabel);
	strcat(resultBuffer, angleBuffer1);
	strcat(resultBuffer, angleBuffer2);
	strcat(resultBuffer, angleBuffer3);
	
	return resultBuffer;																	//return buffer containing entire string
}
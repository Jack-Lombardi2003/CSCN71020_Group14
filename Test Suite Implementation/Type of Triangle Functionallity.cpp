#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuiteImplementation
{
	TEST_CLASS(TestSuiteImplementation)
	{
	public:
		
		TEST_METHOD(PositiveValueChecker)	// Makes sure if the values entered are zero or below the program wont run
		{
			if (side1 <= 0 || side2 <= 0 || side3 <= 0)			//triangle sides can't be less than or equal to zero
			{
				printf("Incorrect Triangle");
			}
			else 
			{
				printf("Correct Angles");
			}

		}
		TEST_METHOD(SideLengthValueChecker)	// Makes sure if the values entered are correct and that two sides added togther are more than the final side
		{
			if (side1 + side2 < side3 || side2 + side3 < side1 || side1 + side3 < side2)
			{
				printf("Incorrect Triangle");

			}
			else
			{
				printf("Correct Angles");
			}

		}

	};




}

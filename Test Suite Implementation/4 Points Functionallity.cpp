#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuiteImplementation
{
	TEST_CLASS(TestSuiteImplementation)
	{
	public:

		TEST_METHOD(MinimumPointChecker)
		{
			if (x1 <= 0 || x2 <= 0 || x3 <= 0 || x4 <= 0 || y1 <= 0 || y2 <= 0 || y3 <= 0 || y4 <= 0)			//rectangle points can't be less than or equal to zero
			{
				printf("Incorrect Rectangle");
			}
			else
			{
				printf("Correct Triangle");
			}
		}

		TEST_METHOD(MinimumSideChecker) 
		{
			if (side1 <=0 || side2 == 0 || side3 == 0 || side4 == 0)
			{
				printf("Incorrect Rectangle");
			}
			else
			{
				printf("Correct Triangle");
			}
		}
	};
}

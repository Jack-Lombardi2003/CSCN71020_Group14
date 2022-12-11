#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuiteImplementation
{
	TEST_CLASS(TestSuiteImplementation)
	{
	public:

		TEST_METHOD(MinimumAngelChecker)	// all the angle values should be above zero
		{
			if(angle1 == 0 || angle2 == 0 || angle3 == 0)
			{
				printf("Incorrect Angles");
			}
			else
			{
				printf("Correct Angles");
			}

		}
		TEST_METHOD(AngelValueChecker)	// all the angle values should add up to 180
		{
			if (angle1 + angle2 + angle3 == 180) 
			{
				printf("Correct Angles");
			}
			else 
			{
				printf("Incorrect Angles");
			}
		}

	};
}

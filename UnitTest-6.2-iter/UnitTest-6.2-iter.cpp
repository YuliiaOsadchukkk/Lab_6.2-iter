#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2---iter/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62iter
{
	TEST_CLASS(UnitTest62iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int mass[4] = {-4,5,7,3};
			Assert::AreEqual(do_stuff(mass, 4), 6.);

		}
	};
}

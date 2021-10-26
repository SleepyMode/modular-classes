
#pragma once

#include "wrapper/base.h"

class Derived1 : public ActiveBase
{
public:
	virtual void Test()
	{
		__super::Test();
		std::printf("Derived1::Test\n");
	}
};

#undef ActiveBase
#define ActiveBase Derived1


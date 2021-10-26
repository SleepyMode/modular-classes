
#pragma once

#include "wrapper/base.h"

class Derived2 : public ActiveBase
{
public:
	virtual void Test()
	{
		__super::Test();
		std::printf("Derived2::Test\n");
	}
};

#undef ActiveBase
#define ActiveBase Derived2


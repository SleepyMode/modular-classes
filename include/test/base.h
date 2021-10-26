
#pragma once

class Base
{
public:
	virtual void Test() {}
};

#undef ActiveBase
#define ActiveBase Base

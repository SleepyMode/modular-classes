
#include <cstdio>

#include "test/base.h"
#include "test/derived1.h"
#include "test/derived2.h"
#include "test/derived3.h"

// SOME VERY IMPORTANT NOTES!!!
// - the functions HAVE to be inline and in the header file!
// - the order of inclusion is the order in which they'll run
// - this is literally only useful for registrars (will elaborate on those in a moment).
//
// A registrar (in concept):
// So, imagine you have a class - called Action. It's a base class. You want to register A LOT of actions.
// They're all stored in a master registrar so you can easily access them (e.g. ActionRegistrar.Get<Action2>()).
// The problem you'll run into is that, unfortunately, you end up with making a class with a stupid long list, like:
// void RegisterActions()
// {
//		m_actionList.RegisterAction(new Action1);
//		m_actionList.RegisterAction(new Action2);
//		m_actionList.RegisterAction(new Action3);
//		...
// }
// 
// This is inefficient and not very modular.
// Making a .DLL plugin for each group of actions is too much work.
// 
// Well, here's a solution I thought about! Let's abuse MSVC's __super keyword alongside with the preprocessor to make this:
// A class that derives from its predecessor without knowing it by name explicitly. And now, you can simply make a new registrar
// that's derived from "ActiveRegistrar" or whatever you want to name it - and there you have it. Very modular. Very clean.
// & it works.

int main(int argc, char* argv[])
{
	std::printf("[+] Starting test:\n");
	ActiveBase base;
	base.Test();
}

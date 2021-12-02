#pragma once

#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW   new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void initMemleaksDebug()
{
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(flag);
}
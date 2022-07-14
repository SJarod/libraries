#pragma once

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

#include <stdlib.h>
#include <crtdbg.h>

// To check the memory leaks
/*

#include <Windows.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG | _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;

    _CrtMemCheckpoint(&sOld); //take a snapshot

    // allocations

    _CrtMemCheckpoint(&sNew); //take a snapshot

    if (_CrtMemDifference(&sDiff, &sOld, &sNew))
        OutputDebugString("\n===MEMORY LEAKS DETECTED WITHIN THE CHECKPOINTS===\n");
    else
        OutputDebugString("\n===NO MEMORY LEAKS DETECTED WITHIN THE CHECKPOINTS===\n");

    OutputDebugString("\n-----------_CrtMemDumpStatistics-----------\n");
    _CrtMemDumpStatistics(&sDiff);

    OutputDebugString("\n===POSSIBLE OUT OF CHECKPOINT RANGE LEAKS===\n");
    OutputDebugString("\n-----------_CrtDumpMemoryLeaks-----------\n");
    _CrtDumpMemoryLeaks();

    return 0;
}

*/
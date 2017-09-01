// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include <vld.h>
#include <crtdbg.h>
#include "test_shared_pointer.h"
#include "test_delegate.h"
#include "test_time.h"
#include "test_bitset.h"
#include "test_array.h"


int main()
{
    _CrtSetBreakAlloc(185);
    {
        test_shared_pointer test;
    }
    {
        test_delegate test;
    }
    {
        test_time test;
    }
    {
        test_bitset test;
    }
    {
        test_array test;
    }
    int* pInt = new int[30];

    _CrtDumpMemoryLeaks();
    return 0;
}


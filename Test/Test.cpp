// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test_shared_pointer.h"
#include "test_delegate.h"


int main() {
    {
        test_shared_pointer test;
    }
    {
        test_delegate test;
    }
    return 0;
}


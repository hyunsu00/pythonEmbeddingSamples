// pythonEmbeddingSample01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// Python
#ifdef _DEBUG
#   undef _DEBUG
#   include <Python.h>
#   define _DEBUG
#else
#   include <Python.h>
#endif

int main()
{
    Py_Initialize();

    PyRun_SimpleString("from time import time,ctime\n"
        "print('Today is',ctime(time()))\n");

    Py_Finalize();

    return 0;
}

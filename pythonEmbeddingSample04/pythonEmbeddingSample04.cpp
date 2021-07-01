// pythonEmbeddingSample04.cpp
//
#include <iostream>
#include <string> // std::string

// Python
#ifdef _DEBUG
#   undef _DEBUG
#   include <Python.h>
#   define _DEBUG
#else
#   include <Python.h>
#endif

int main(int argc, char* argv[])
{
    // 로케일 설정
    setlocale(LC_ALL, "");

    std::string exeDir;
    std::string pklDir;
#ifdef _WIN32	
    {
        char drive[_MAX_DRIVE] = { 0, }; // 드라이브 명
        char dir[_MAX_DIR] = { 0, }; // 디렉토리 경로
        _splitpath_s(argv[0], drive, _MAX_DRIVE, dir, _MAX_DIR, nullptr, 0, nullptr, 0);
        exeDir = std::string(drive) + dir;
        pklDir = exeDir + "pkl\\";
    }
#else
    {
        char* exePath = strdup(argv[0]);
        exeDir = dirname(exePath);
        free(exePath);
        exeDir += "/";
        pklDir = exeDir + "pkl/";
    }
#endif

    Py_Initialize();

    PyObject* file = NULL, * p = NULL;

    const char* s = 0;

    PyGILState_STATE gilState = PyGILState_Ensure();
    PyObject* pickle = PyImport_ImportModule("pickle"); // import module
    PyObject* io = PyImport_ImportModule("io"); // import io

    if (!pickle) goto error;
    // file = PyFile_FromString((pklDir + "chunk0.pkl").c_str(), "rb");
    file = PyObject_CallMethod(io, "open", "ss", (pklDir + "chunk0.pkl").c_str(), "rb"); // open("chunk0.pkl")
    if (!file) goto error;
    p = PyObject_CallMethod(pickle, "load", "O", file); // pickle.load(file)

    {
        PyObject* iter = PyObject_GetIter(p);
        if (iter) {
            while (true) {
                PyObject* next = PyIter_Next(iter);
                if (!next) {
                    // nothing left in the iterator
                    break;
                }

                if (!PyFloat_Check(next)) {
                    // error, we were expecting a floating point value
                }

                double foo = PyFloat_AsDouble(next);
                // do something with foo
            }
        }
    }
    

error:
    Py_XDECREF(pickle);
    Py_XDECREF(file);

    PyGILState_Release(gilState);
    Py_Finalize();
    return 0;
}

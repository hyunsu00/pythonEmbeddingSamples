// pythonEmbeddingSample02.cpp
//
#include <iostream>
#include <string>

#ifdef _DEBUG
#   undef _DEBUG
#   include <python.h>
#   define _DEBUG
#else
#   include <python.h>
#endif

#ifdef _WIN32
#include <atlconv.h>
#else
#	include <string.h>	// strdup
#	include <libgen.h>	// dirname
#endif

void _PrintPyInfo()
{
    USES_CONVERSION;

    std::cout << "Py_GetPath() = " << W2A(Py_GetPath()) << std::endl << std::endl;
    // std::cout << "Py_GetPythonHome() = " << W2A(Py_GetPythonHome()) << std::endl;
    std::cout << "Py_GetVersion() = " << Py_GetVersion() << std::endl;
    std::cout << "Py_GetPlatform() = " << Py_GetPlatform() << std::endl;
    std::cout << "Py_GetProgramName() = " << W2A(Py_GetProgramName()) << std::endl;
    std::cout << "Py_GetProgramFullPath() = " << W2A(Py_GetProgramFullPath()) << std::endl << std::endl;
}

int main(int argc, char* argv[])
{
    std::string exeDir;
    std::string scriptsDir;
    std::string resultDir;
#ifdef _WIN32	
    {
        char drive[_MAX_DRIVE] = { 0, }; // 드라이브 명
        char dir[_MAX_DIR] = { 0, }; // 디렉토리 경로
        _splitpath_s(argv[0], drive, _MAX_DRIVE, dir, _MAX_DIR, nullptr, 0, nullptr, 0);
        exeDir = std::string(drive) + dir;
        scriptsDir = exeDir + "scripts\\";
        resultDir = exeDir + "result\\";
    }
#else
    {
        char* exePath = strdup(argv[0]);
        exeDir = dirname(exePath);
        free(exePath);
        exeDir += "/";
        scriptsDir = exeDir + "scripts/";
        resultDir = exeDir + "result/";
    }
#endif

    _PrintPyInfo();

    std::cout << "Py_InitializeEx(0) = 시작" << std::endl;
    Py_SetProgramName(L"pythonEmbeddingSample02");
    Py_InitializeEx(0);
    if (!Py_IsInitialized()) {
        std::cerr << "Py_InitializeEx is Failed" << std::endl;
        return -1;
    }

    {
        PyObject* pPath = PySys_GetObject("path");
        PyList_Append(pPath, PyUnicode_FromString("./"));
        PyList_Append(pPath, PyUnicode_FromString(scriptsDir.c_str()));

        PyObject* pName = PyUnicode_FromString("ConvertHtmlModule");
        PyObject* pModule = PyImport_Import(pName);
        _ASSERTE(pModule && "pModule is not Null");
        if (!pModule) {
            std::cerr << "PyImport_Import() : ";
            PyErr_Print();
            return -1;
        }

        PyObject* pDict = PyModule_GetDict(pModule);
        _ASSERTE(pDict && "pDict is not Null");

        std::cout << "HtmlToImage() = 시작" << std::endl;
        {
            PyObject* pImageFunc = PyDict_GetItemString(pDict, "HtmlToImage");
            _ASSERTE(pImageFunc && "pImageFunc is not Null");
            _ASSERTE(PyCallable_Check(pImageFunc));
            {
                std::string url = "https://www.naver.com/";
                std::string result = resultDir + "naver.png";
                std::string type = "png";

                PyObject* pImageArgs = Py_BuildValue("(z, z, z)", url.c_str(), result.c_str(), type.c_str());
                _ASSERTE(pImageArgs && "pImageArgs is not Null");
                PyObject* pResult = PyObject_CallObject(pImageFunc, pImageArgs);
                _ASSERTE(pResult && "pResult is not Null");
            }
        }
        std::cout << "HtmlToImage() = 종료" << std::endl;

        std::cout << "HtmlToPdf() = 시작" << std::endl;
        {
            PyObject* pPdfFunc = PyDict_GetItemString(pDict, "HtmlToPdf");
            _ASSERTE(pPdfFunc && "pPdfFunc is not Null");
            _ASSERTE(PyCallable_Check(pPdfFunc));
            {
                std::string url = "https://www.naver.com/";
                std::string result = resultDir + "naver.pdf";

                PyObject* pPdfArgs = Py_BuildValue("(z, z)", url.c_str(), result.c_str());
                _ASSERTE(pPdfArgs && "pPdfArgs is not Null");
                PyObject* pResult = PyObject_CallObject(pPdfFunc, pPdfArgs);
                _ASSERTE(pResult && "pResult is not Null");
            }
        }
        std::cout << "HtmlToPdf() = 종료" << std::endl;
    }

    Py_Finalize();
}

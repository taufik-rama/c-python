#include <string>
#include <Python.h>

int main(int argc, char const *argv[]) {

    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    PyObject *myModuleString = PyUnicode_FromString("app");
    PyObject *myModule = PyImport_Import(myModuleString);

    PyObject *myFunction = PyObject_GetAttrString(myModule, "print_text");
    PyObject* myResult = PyObject_CallObject(myFunction, NULL);

    // FILE *file = fopen("app.py", "r");
    // if (file != NULL) {
    //     PyRun_SimpleFile(file, "app.py");
    // }

    Py_Finalize();
    return 0;
}

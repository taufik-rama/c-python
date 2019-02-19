// #include <string>
#include <Python.h>

int run() {

    long result = 0;

    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./c-python/')");

    PyObject *module = PyImport_Import(PyUnicode_FromString("app"));
    if (!module) {
        PyErr_Print();
        return -1;
    }

    PyObject *print_text = PyObject_GetAttrString(module, "print_text");
    if (!print_text) {
        PyErr_Print();
        return -1;
    }

    result = PyLong_AsLong(PyObject_CallObject(print_text, NULL));
    if (!result) {
        PyErr_Print();
        return -1;
    }

    printf("| C | print_text(): %ld\n", result);

    // FILE *file = fopen("app.py", "r");
    // if (file != NULL) {
    //     PyRun_SimpleFile(file, "app.py");
    // }

    Py_Finalize();
    return result;
}

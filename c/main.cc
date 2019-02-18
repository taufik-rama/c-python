#include <string>
#include <Python.h>

int main(int argc, char const *argv[]) {

    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    PyObject *module = PyImport_Import(PyUnicode_FromString("app"));

    PyObject *print_text = PyObject_GetAttrString(module, "print_text");
    long result = PyLong_AsLong(PyObject_CallObject(print_text, NULL));
    if(!result) {
        PyErr_Print();
        return -1;
    }

    printf("print_text(): %ld\n", result);

    // FILE *file = fopen("app.py", "r");
    // if (file != NULL) {
    //     PyRun_SimpleFile(file, "app.py");
    // }

    Py_Finalize();
    return 0;
}

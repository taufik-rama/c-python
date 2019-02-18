#include <Python.h>

int main(int argc, char const *argv[]) {
    Py_Initialize();

    // PyObject *pyname = ;
    PyObject *py_module = PyImport_Import(PyUnicode_FromString("app"));
    // PyObject *py_global_dict = ;
    PyObject *print_text = PyDict_GetItemString(PyModule_GetDict(py_module), "print_text");

    PyObject_CallObject(print_text, NULL);

    Py_Finalize();
    return 0;
}

#include "Python.h"
#include "obj_loader/obj_loader.h"

static PyObject* YR_Init(PyObject *self, PyObject *args){
    printf("hello World");
    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject* YR_Load_Obj_Handler(PyObject *self, PyObject *args){
        char *filename = NULL;

        if (!PyArg_ParseTuple(args, "s", &filename)){
            printf("--%s--\n", filename);
            Py_RETURN_FALSE;
        }

        YR_Load_Obj(filename);
        Py_RETURN_TRUE;

        

}

static PyMethodDef YureiMethods[] = {
    
    {"yurei_init",  YR_Init, METH_VARARGS,
     "Execute a shell command."},
    {"load",  YR_Load_Obj_Handler, METH_VARARGS,
     "Load Model."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef yureimodule = {
    PyModuleDef_HEAD_INIT,
    "yurei",
    NULL,
    -1,
    YureiMethods
    
};


static PyObject *YureiError;


PyMODINIT_FUNC
PyInit_yurei(void){
   return PyModule_Create(&yureimodule);

}


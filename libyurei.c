#include <Python.h>
#include "obj_loader/obj_loader.h"


extern obj_model model;

static PyObject* YR_Init(PyObject *self, PyObject *args){
    printf("hello World");
    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject* YR_Load_Obj_Handler(PyObject *self, PyObject *args){
        char *filename = NULL;
        PyObject *dict = NULL;
        PyListObject *vertex = NULL;
        int i;

        if (!PyArg_ParseTuple(args, "s", &filename)){
            printf("--%s--\n", filename);
            Py_RETURN_FALSE;
        }

        YR_Load_Obj(filename);
        
        /* add vertex */

        vertex = (PyListObject *) Py_BuildValue("[]");
        for (i = 0; i < model.v_count; ++i){
            
            dict = Py_BuildValue("{s:(d,d,d)}", "v",  model.vertex[i].x, model.vertex[i].y, model.vertex[i].z);
            PyList_Append(vertex,dict); 
        }
        
        Py_INCREF(vertex);
        return (PyObject *) vertex;
        

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


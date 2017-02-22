#include <Python.h>
#include "obj_loader/obj_loader.h"


extern obj_model model;

static PyObject* YR_Init(PyObject *self, PyObject *args){
    printf("hello World");
    Py_INCREF(Py_None);
    return Py_None;
}



static PyObject*  YR_vertex_obj(PyObject *self, PyObject *args){
    int i;
    PyObject *dict = NULL;
    PyListObject *list = NULL;

    list = (PyListObject *)Py_BuildValue("[]");
    for(i = 0; i < model.v_count; ++i){
        dict = Py_BuildValue("{s:(f,f,f)}", "v", model.vertex[i].x, model.vertex[i].y, model.vertex[i].z);
        PyList_Append(list,dict);
    }
    Py_INCREF(list);
    return (PyObject *)list;

}

static PyObject*  YR_vt_obj(PyObject *self, PyObject *args){
    int i;
    PyObject *dict = NULL;
    PyListObject *list = NULL;

    list = (PyObject *)Py_BuildValue("[]");
    for(i = 0; i < model.vt_count; ++i){
        dict = Py_BuildValue("{s:(f,f)}", "vt", model.vt[i].x, model.vt[i].y);
        PyList_Append(list,dict);
    }
    Py_INCREF(list);
    return (PyObject *)list;

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
     {"vertex",  YR_vertex_obj, METH_VARARGS, "Vertex"},
     {"vt",      YR_vt_obj, METH_VARARGS, "Vertex Textures"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef yureimodule = {
    PyModuleDef_HEAD_INIT,
    "yurei",
    NULL,
    -1,
    YureiMethods
    
};




PyMODINIT_FUNC
PyInit_yurei(void){
   return PyModule_Create(&yureimodule);

}


#ifndef YR_OBJECT_LOADER
#define YR_OBJECT_LOADER

#include <stdio.h>

 struct obj_coord {
        float x,y,z;
};

struct obj_model {
    char name[56];
    
    struct obj_coord *vt;
    struct obj_coord *vertex;
    size_t vt_count;
    size_t v_count;
};


typedef struct obj_model obj_model;


void YR_Load_Obj(const char *file);





#endif

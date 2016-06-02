%module libyurei_loader

%{
	
#include "../obj_loader.h"

typedef struct obj_vertex obj_vertex;
typedef struct obj_model obj_model;
typedef struct obj_vertex_texture obj_vertex_texture;
obj_model *obj_loadfile(const char *filename);


%}

%include "../obj_loader.h"

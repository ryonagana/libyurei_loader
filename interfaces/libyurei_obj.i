%module libyurei_loader

%{

#include "../obj_loader.h"
void obj_loader_Init();
struct object_model* obj_load_model(const char *filename);	
	

%}

%include "../obj_loader.h"

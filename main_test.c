#include "obj_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *name = "test//model.obj";

int main(int argc, char **argv[]){
	


	struct object_model *m;
	m = obj_load_model(name);

	/*
	int c = 0;
	struct model_coord vertex[m->vertex_count];

	

	memcpy(&vertex, m->vertex, sizeof(struct model_coord) * m->vertex_count);
	



	for(c = 0; c < m->vertex_count;++c){
		printf("%.6f %.6f %.6f\n", vertex[c].x, vertex[c].y, vertex[c].z);
	}

	*/
	free(m);

	
	
	

	
	

	return 0;
}

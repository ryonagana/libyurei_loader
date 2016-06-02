#include "obj_loader.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_BYTES_PER_LINE 60 * 4


static struct obj_model *obj_AllocModel(){
	struct obj_model *model = NULL;
	model = malloc(sizeof(struct obj_model));
	if(!model){
		return model;
	}

	model->vertices = NULL;

	return model;
}

static struct obj_vertex *obj_AllocVertex(){
		struct obj_vertex *v = NULL;

        v = calloc(sizeof(struct obj_vertex),1);
		v->x = 0;
		v->y = 0;
		v->z = 0;

		return v;

}

static float* obj_append_vertices(char *linefeed){
		char *data  = strtok(linefeed, " ");
		float *coord = NULL;
		int c = 0;

        coord = calloc(sizeof(float), 3);

		if(!coord){
			return NULL;
		}

		//put the first element
		coord[0] = atof(data);
		data = strtok(NULL, " ");

		while(data != NULL){
			coord[c] = atof(data);			
			data = strtok(NULL, " ");
			++c;
		}
		return coord;		
}

static void obj_create_vertices(struct obj_vertex **v, float x, float y, float z, int count){

        *v = realloc(*v, (count + 1) * sizeof(struct obj_vertex));
        (*(v) + count)->x = x;
        (*(v) + count)->y = y;
        (*(v) + count)->z = z;




}

struct obj_model  *obj_loadfile(const char *filename){
	char line[255];
	FILE *fp = NULL;
	struct obj_vertex *v = NULL;
	struct obj_model *model = NULL;
    float *coord = NULL;
	int vertex_count;

	vertex_count = 0;


	fp = fopen(filename, "rb");

	if(!fp){
		/*
			TODO:  adicionar uma exception pro swig
		*/
		return NULL;
	}


	v = obj_AllocVertex();
	model = obj_AllocModel();

    strcpy(model->name, filename);


	while(fgets(line, MAX_BYTES_PER_LINE, fp)){
			
			/* ignore comments */
			if(line[0] == '#'){
				continue;
			}

			switch(line[0]){

				case 'v':
					switch(line[1]){
						
						/* vt */
						case 't':
						break;

						/* vp */
						case 'p':
						break;

						/* load v */
						default:
							coord = obj_append_vertices(line);
							obj_create_vertices(&v, coord[0], coord[1], coord[2], vertex_count);
							++vertex_count;
						break;
					}

	

					

				break;

			default:
				continue;

			}	

	}

	model->vertices_count = vertex_count;


	return model;

}

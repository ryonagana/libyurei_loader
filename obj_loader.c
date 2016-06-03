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

	model->vertices =  NULL;


	return model;
}


static struct obj_vertex *obj_AllocVertex(){
	struct obj_vertex  *v = NULL;
	v = malloc(sizeof(struct obj_vertex));
	if(!v){
		return v;
	}

	v->x = 0;
	v->y = 0;
	v->z = 0;
	v->next = NULL;

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

int obj_add_vertex(struct obj_vertex **v, float *coordinates){
		struct obj_vertex *root = *v;
		
		/* is it the head? */
		if( root == NULL ){
			root  = obj_AllocVertex();
		}

		root->x = coordinates[0];
		root->y = coordinates[1];
		root->z = coordinates[2];
		root->next = NULL;

		*v = root->next;

		if(*v == NULL){
			return 0;
		}

		return 1;

}



struct obj_model  *obj_loadfile(const char *filename){
	char line[255];
	FILE *fp = NULL;
	struct obj_model *model = NULL;
    float *coord = NULL;
    struct obj_vertex *vertex = NULL;
	int vertex_count;

	vertex_count = 0;


	fp = fopen(filename, "rb");

	if(!fp){
		/*
			TODO:  adicionar uma exception pro swig
		*/
		//SWIG_exception(SWIG_ValueError, "Arquivo nao encontrado");
		return NULL;
	}

	model = obj_AllocModel();
	vertex = obj_AllocVertex();
	

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
							obj_add_vertex(&vertex, coord);

							
							++vertex_count;
						break;
					}

	

					

				break;

			default:
				continue;

			}	

	}


	model->vertices = vertex;
	model->vertices_count = vertex_count;






	return model;

}

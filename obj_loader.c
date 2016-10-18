#include "obj_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE (60 * 4)


struct object_model obj_model;
FILE *obj_input;





void obj_loader_Init(){
	
	strcpy(obj_model.name, "");
	obj_model.vertex  =  NULL;
	obj_model.texture =  NULL;
	obj_model.vertex_count = 0;
	obj_model.textures_count = 0;
	obj_model.normals_count = 0;
	
	obj_model.vertex = calloc(sizeof(struct model_v),1);
	
	
}


static float* split_coord(char *linefeed){
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

struct object_model* obj_load_model(const char *filename){
	char line[255];

	float *coordinates = NULL;
	long line_count  = 0;
	struct model_v *tmp_vertex = NULL;
	
	obj_loader_Init();
	
	obj_input =  fopen(filename, "rb");
	
	if(!obj_input){
		return;
	}
	
	while(fgets(line, LINE_SIZE, obj_input)){
		
		/* ignore comments */
		if(line[0] == '#' ) continue;
		
		switch(line[0]){
			
			/* 
			v - vertex
			vn - vertex normals
			vt vertex textures,
			vp - ????????????
			*/
				
			case 'v': /* can be v, vt or vp or vn */
				switch(line[1]){
					case 'p':
					case 't':
					case 'n':
						break;
					
					
					default:
					
							coordinates = split_coord(line);
							++line_count;
							if( tmp_vertex = realloc(obj_model.vertex, line_count * sizeof(struct model_v))){
								obj_model.vertex = tmp_vertex;
								tmp_vertex[line_count - 1].x = coordinates[0];
								tmp_vertex[line_count - 1].y = coordinates[1];
								tmp_vertex[line_count - 1].z = coordinates[2];
								++obj_model.vertex_count;
							}
							
							

							
						break;
					
				}
				break;
				
		}
	}
	

	
	return &obj_model;
	
	
}


void obj_copy_vertex(struct model_v* dest, struct object_model *orig){

}

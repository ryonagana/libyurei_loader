#include "obj_loader.h"

int main(int argc, char **argv[]){

	struct obj_model *model = NULL;
	int i = 0;

	model = obj_loadfile("test//model.obj");

    if(!model){
        printf("arquivo nao encontrado");
        exit(0);
    }


    
    printf("%zd", model->vertices_count);

    while(model->vertices->next != NULL){

        //printf("%f %f %f\n\n", model->vertices->x, model->vertices->y, model->vertices->z);
        model->vertices = model->vertices->next;

    }

 
	

	return 0;
}

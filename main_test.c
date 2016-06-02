#include "obj_loader.h"

int main(int argc, char **argv[]){

	struct obj_model *model = NULL;
	int i = 0;

	model = obj_loadfile("test//stick.obj");

    if(!model){
        printf("arquivo nao encontrado");
        exit(0);
    }

    printf("%zd", model->vertices_count);

    for(i = 0; i < model->vertices_count; ++i){
        printf("\nX:%f\nY:%f\nZ:%f\n", (model->vertices + i)->x, (model->vertices + i)->y, (model->vertices + i)->z );
    }
	

	return 0;
}

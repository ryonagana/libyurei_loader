#include "obj_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *obj_file = NULL;
struct obj_model model;


static void obj_init(void){
    model.vertex = NULL;
    model.v_count = 0;
    model.vertex = calloc(sizeof(struct obj_coord),1);
}

static float* Tokenize(char *text){
    char *data = strtok(text, " ");
    float *coord_array = NULL;
    int c = 0;

    coord_array = calloc(sizeof(float), 3);

    if(!coord_array){
        fprintf(stdout, "Tokenize(): Error While trying to read the file\n");
        return NULL;
    }

    coord_array[0] = atof(data);
    data = strtok(NULL, " ");

    while(data != NULL){
        coord_array[c++] = atof(data);
        data = strtok(NULL, " ");
    }

    free(data);
    return coord_array;



}




static void obj_readVertex(struct obj_coord *coordinates[], int c, const char *line){
     fprintf(stdout, "%f %f %f\n", coordinates[c]->x, coordinates[c]->y, coordinates[c]->x );
    
}

static void ReadVertex(){
    size_t c = 0;
    char buf[256];
    while( fgets(buf,60, obj_file)){
        switch(buf[0]){
            case 'v':
                switch(buf[1]){
                    case ' ':
                     ++c;
                     break;
                }
            break;
        }
    }
    rewind(obj_file);
    printf("NUM V: %d", c);
    model.vertex = calloc(c, sizeof( struct obj_coord ));
    
    return;
}


static void obj_readLine(void){
    char buf[255];

    ReadVertex();

    while( fgets(buf, 60, obj_file) ){
        if(buf[0] == '#') continue;

        switch(buf[0]){
            case 'v':
              
                    switch(buf[1]){
                        /* VP */
                        case 'p': break;
                    
                        /* VT textures */
                        case 't': break;
                        
                        /* LOAD V */
                        case ' ':
                            obj_readVertex(&model.vertex, ++model.v_count, buf);
                            break;
                    }
            break;
           


        }
    }

}

static void obj_model_load(const char *filename){
    obj_file = fopen(filename, "rb");
    if(!obj_file){
        fprintf(stdout, "Failed to load: %s\n", filename);
        return;
    }

        fprintf(stdout, "%s loaded with success!\n", filename);
        
        obj_readLine();
}



void YR_Load_Obj(const char *file){
    obj_init();
    obj_model_load(file);

}
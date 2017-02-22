#include "obj_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *obj_file = NULL;
struct obj_model model;


static void obj_init(void)
{
    model.vertex = NULL;
    model.v_count = 0;
    model.vertex = calloc(sizeof(struct obj_coord),1);
    
    model.vt = NULL;
    model.vt_count = 0;


}


static float* Tokenize_VT(char *line)
{
    char *data = strtok(line, " ");
    float *v_texture;
    int c = 0;


    v_texture = calloc(2, sizeof(float));

    if(!v_texture){
        fprintf(stdout, "Tokenize_VT(): error trying to alloc memory");
        return NULL;
    }
    
    
    v_texture[0] = atof(data);
    data = strtok(NULL, " ");
    
    while(data != NULL){
        v_texture[c++] = atof(data);
        data = strtok(NULL, " ");
    }

    free(data);
    return v_texture;

}


static float* Tokenize(char *text)
{
    char *data = strtok(text, " ");
    float *coord_array = NULL;
    int c = 0;

    coord_array = calloc(3, sizeof(float));

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



static void obj_readVertexTexture(int c, char *line){
    float *t =  NULL;

    t = Tokenize_VT(line);
    model.vt[c].x = t[0];
    model.vt[c].y = t[1];
    model.vt[c].z = 0; /* not used but we dont want garbage numbers */
    

    free(t);
}

static void obj_readVertex(int c, char *line)
{
    float *new_coord =  NULL;
          
    
      
       if (new_coord != NULL || line != '\0'){
        new_coord = Tokenize(line);
        model.vertex[c].x = new_coord[0];
        model.vertex[c].y = new_coord[1];
        model.vertex[c].z = new_coord[2];
        free(new_coord);
      }
    
   
}


static void CountInternals(void){
    size_t c = 0;
    size_t count_vt = 0;
    char buf[256];
    while( fgets(buf,60, obj_file)){
        if(buf[0] == '#' ) continue;
        switch(buf[0]){
            case 'v':
                switch(buf[1]){
                    case 't':
                        ++count_vt;
                        break;

                    case ' ':
                         ++c;
                        break;
                }
            break;
        }
    }
    
    fprintf(stdout, "Read %zu vertexes\nRead %zu vertex Textures Positions\n", c,count_vt);
    /*
     * rollback the file to the beginning
     * */
    rewind(obj_file);
    model.vertex = (struct obj_coord *)  calloc(c, sizeof( struct obj_coord ));
    model.vt = (struct obj_coord *) calloc(count_vt, sizeof(struct obj_coord));
    return;
}


static void obj_readLine(void)
{
    char buf[255];

    CountInternals();

    while( fgets(buf, 60, obj_file) ){
        if(buf[0] == '#') continue;

        switch(buf[0]){
            case 'v':
              
                    switch(buf[1]){
                        /* VP */
                        case 'p': break;
                    
                        /* VT textures */
                        case 't': 
                            obj_readVertexTexture(model.vt_count++, buf);
                            break;
                        
                        /* LOAD V */
                        case ' ':
                            obj_readVertex(model.v_count++, buf); 
                            break;
                    }
            break;
           


        }
    }

}

static void obj_model_load(const char *filename)
{
    obj_file = fopen(filename, "rb");
    if(!obj_file){
        fprintf(stdout, "Failed to load: %s\n", filename);
        return;
    }

        fprintf(stdout, "%s loaded with success!\n", filename);
        
        obj_readLine();
}



void YR_Load_Obj(const char *file)
{
    obj_init();
    obj_model_load(file);

}

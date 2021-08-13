#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include<stdio.h>

#define NUM_TEXTURE 15

#define DOOR_TEXTURE 0
#define WALL_TEXTURE 1
#define SAND_TEXTURE 2
#define PILLAR_TEXTURE 3
#define CASTLE_FLOOR_TEXTURE 4
#define ROAD_TEXTURE 5
#define CAR_GRILL_TEXTURE 6
#define CAR_SIDE_HOOD_TEXTURE 7
#define CAR_BOTTOM_TEXTURE 8
#define CAR_SIDE_TEXTURE 9
#define CAR_REAR_TEXTURE 10
#define CAR_GLASS_TEXTURE 11
#define CAR_TOP_TEXTURE 12
#define CAR_TOP_HOOD_TEXTURE 13
#define CAR_WHEEL_TEXTURE 14


GLuint textures[NUM_TEXTURE]; // Texture object list
const char *img_path[] =
{
    "assets/door.bmp",
    "assets/wall.bmp",
    "assets/sand.bmp",
    "assets/pillar.bmp",
    "assets/castle_floor.bmp",
    "assets/road.bmp",
    "assets/car_grill.bmp",
    "assets/car_side_hood.bmp",
    "assets/car_bottom.bmp",
    "assets/car_side.bmp",
    "assets/car_rear.bmp",
    "assets/car_glass.bmp",
    "assets/car_top.bmp",
    "assets/car_top_hood.bmp",
    "assets/car_wheel.bmp"
}; // Path to texture - Absolute

// Load texture from file to object
void LoadTexture( const char * filename, GLuint texture)
{
    int width, height;
    unsigned char * data;

    FILE *file;
    file = fopen( filename, "rb" );

    if ( file == NULL )
        printf("image Not Found");

    unsigned char imagedata[54];
    int bytevalue;
    int index = 0;

    do
    {
        bytevalue = fgetc(file);
        imagedata[index] = bytevalue;
        index++;
        if (index == 54)
            break;
    }
    while (bytevalue != EOF);

    width = imagedata[20 - 1] * 256 + imagedata[19 - 1];
    height = imagedata[24 - 1] * 256 + imagedata[23 - 1];

    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );

    for(int i = 0; i < width * height ; ++i)
    {
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;
    }

    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,data);
    free( data );
}

// Load All textures
void texture_init()
{
    glGenTextures(NUM_TEXTURE, textures);
    for(int i = 0; i < NUM_TEXTURE; i++)
        LoadTexture(img_path[i],textures[i]);
}

#endif // BMP_H_INCLUDED

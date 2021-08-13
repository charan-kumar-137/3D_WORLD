#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "bmp.h"
#include "input.h"
#include "truck.h"


void display();
void draw_surface();
GLvoid draw_circle(const GLfloat, int, GLuint);
void draw_castle_wall();
void draw_castle_pillars();
void draw_castle_floor();
void draw_road();
void draw_car();
void draw_castle_pillar_wall();

// Display callback
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cam_x, cam_y, cam_z,
              cam_x + lx,cam_y + ly,cam_z + lz,
              0.0f,1.0f,0.0f); // Camera Position

    draw_surface();
    draw_castle_wall();
    draw_castle_pillars();
    draw_castle_floor();
    draw_road();
    draw_car();
    draw_truck();
    glutSwapBuffers();
}

// Bottom Surface (Desert)
void draw_surface()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[SAND_TEXTURE]);
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-100.0, 0.0, 100.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(100.0, 0.0, 100.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(100.0, 0.0, -100.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

// Function to draw circular texture object
GLvoid draw_circle(const GLfloat radius,int num_vertex, GLuint texID)
{
    GLfloat vertex[4];
    GLfloat texcoord[2];

    const GLfloat delta_angle = 2.0*M_PI/num_vertex;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texID);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
    glBegin(GL_TRIANGLE_FAN);

    texcoord[0] = 0.5;
    texcoord[1] = 0.5;
    glTexCoord2fv(texcoord);

    vertex[0] = vertex[1] = vertex[2] = 0.0;
    vertex[3] = 1.0;
    glVertex4fv(vertex);

    for(int i = 0; i < num_vertex ; i++)
    {
        texcoord[0] = (cos(delta_angle*i) + 1.0)*0.5;
        texcoord[1] = (sin(delta_angle*i) + 1.0)*0.5;
        glTexCoord2fv(texcoord);

        vertex[0] = cos(delta_angle*i) * radius;
        vertex[1] = sin(delta_angle*i) * radius;
        vertex[2] = 0.0;
        vertex[3] = 1.0;
        glVertex4fv(vertex);
    }

    texcoord[0] = (1.0 + 1.0)*0.5;
    texcoord[1] = (0.0 + 1.0)*0.5;
    glTexCoord2fv(texcoord);

    vertex[0] = 1.0 * radius;
    vertex[1] = 0.0 * radius;
    vertex[2] = 0.0;
    vertex[3] = 1.0;
    glVertex4fv(vertex);
    glEnd();

    glDisable(GL_TEXTURE_2D);

}

// Draw Caltle walls and door
void draw_castle_wall()
{
    GLdouble wall_angle[] = {0.0, 90.0, 270.0};
    GLdouble front_wall_pos[] = {0.0, 12.0};

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textures[WALL_TEXTURE]);

    // back, left, right wall
    for(int i = 0; i < 3; i++)
    {
        glPushMatrix();
        glRotated(wall_angle[i], 0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(-10.0, 0.0, -10.0);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(10.0, 0.0, -10.0);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(10.0, 7.0, -10.0);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(-10.0, 7.0, -10.0);
        glEnd();
        glPopMatrix();
    }

    // front - top wall
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-10.0, 5.0, 10.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(10.0, 5.0, 10.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(10.0, 7.0, 10.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-10.0, 7.0, 10.0);
    glEnd();

    // front - side walls
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(front_wall_pos[i], 0.0, 0.0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(-10.0, 0.0, 10.0);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-2.0, 0.0, 10.0);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-2.0, 5.0, 10.0);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(-10.0, 5.0, 10.0);
        glEnd();
        glPopMatrix();
    }

    // door
    glBindTexture(GL_TEXTURE_2D, textures[DOOR_TEXTURE]);
    glPushMatrix();
    glTranslated(castle_door_pos_x, 0.0, 0.05);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-2.0, 0.0, 10.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(2.0, 0.0, 10.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(2.0, 5.0, 10.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-2.0, 5.0, 10.0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

// Draw Castle Pillars
void draw_castle_pillars()
{
    GLdouble position_array[4][3] =
    {
        {-11.0, 0.0, -11.0},
        {-11.0, 0.0, 11.0},
        {11.0, 0.0, 11.0},
        {11.0, 0.0, -11.0}
    }; // Position array of each pillar

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[PILLAR_TEXTURE]);


    for(int i = 0; i < 4; i ++ )
    {
        glPushMatrix();
        glTranslated(position_array[i][0], position_array[i][1], position_array[i][2]);
        draw_castle_pillar_wall();
        glPopMatrix();
    }

    glDisable(GL_TEXTURE_2D);
}

// Draw Castle floor
void draw_castle_floor()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[CASTLE_FLOOR_TEXTURE]);
    glPushMatrix();
    glTranslated(0.0, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-10.0, 0.0, 10.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(10.0, 0.0, 10.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(10.0, 0.0, -10.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-10.0, 0.0, -10.0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

// Draw road
void draw_road()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[ROAD_TEXTURE]);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-2.0, 0.1, 10.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(2.0, 0.1, 10.0);
    glTexCoord2d(.0, 1.0);
    glVertex3d(2.0, 0.1, 20.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(-2.0, 0.1, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-40.0, 0.1, 20.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(40.0, 0.1, 20.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(40.0, 0.1, 24.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(-40.0, 0.1, 24.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

// Draw Car
void draw_car()
{

    GLdouble z_array[] = {1.0, -1.0};
    GLdouble z_array_wheel[] = {1.01, -1.01};

    glPushMatrix();
    glTranslated(car_x, car_y, car_z);
    glRotated(car_angle, 0.0, 1.0, 0.0);

    glEnable(GL_TEXTURE_2D);

    // hood side
    glBindTexture(GL_TEXTURE_2D, textures[CAR_SIDE_HOOD_TEXTURE]);
    for(int i = 0; i < 2; i++)
    {
        glPushMatrix();
        glTranslated(1.0, 1.0, z_array[i]);
        glBegin(GL_POLYGON);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(-0.5, 0.0, 0.0);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(0.5, 0.0, 0.0);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(0.5, 1.0, 0.0);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-0.5, 1.0, 0.0);
        glEnd();
        glPopMatrix();
    }

    // hood top
    glBindTexture(GL_TEXTURE_2D, textures[CAR_TOP_HOOD_TEXTURE]);
    glPushMatrix();
    glTranslated(1.0, 2.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(0.5, 0.0, -1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(0.5, 0.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-0.5, 0.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(-0.5, 0.0, -1.0);
    glEnd();
    glPopMatrix();

    // front
    glBindTexture(GL_TEXTURE_2D, textures[CAR_GRILL_TEXTURE]);
    glPushMatrix();
    glTranslated(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(0.5, 0.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(0.5, 0.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(0.5, 1.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(0.5, 1.0, -1.0);
    glEnd();
    glPopMatrix();

    // rear
    glBindTexture(GL_TEXTURE_2D, textures[CAR_REAR_TEXTURE]);
    glPushMatrix();
    glTranslated(-3.5, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(0.5, 0.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(0.5, 0.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(0.5, 2.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(0.5, 2.0, -1.0);
    glEnd();
    glPopMatrix();

    // body
    glBindTexture(GL_TEXTURE_2D, textures[CAR_SIDE_TEXTURE]);
    for(int i = 0; i < 2; i++)
    {
        glPushMatrix();
        glTranslated(0.0, 1.0, z_array[i]);
        glBegin(GL_POLYGON);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(-3.0, 0.0, 0.0);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(0.5, 0.0, 0.0);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(0.5, 2.0, 0.0);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-3.0, 2.0, 0.0);
        glEnd();
        glPopMatrix();
    }

    // body bottom
    glBindTexture(GL_TEXTURE_2D, textures[CAR_BOTTOM_TEXTURE]);
    glPushMatrix();
    glTranslated(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(-3.0, 0.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(1.5, 0.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(1.5, 0.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-3.0, 0.0, -1.0);
    glEnd();
    glPopMatrix();

    // body top
    glBindTexture(GL_TEXTURE_2D, textures[CAR_TOP_TEXTURE]);
    glPushMatrix();
    glTranslated(0.0, 3.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(-3.0, 0.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(0.5, 0.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(0.5, 0.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(-3.0, 0.0, -1.0);
    glEnd();
    glPopMatrix();

    // body glass
    glBindTexture(GL_TEXTURE_2D, textures[CAR_GLASS_TEXTURE]);
    glPushMatrix();
    glTranslated(0.5, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0);
    glVertex3d(0.0, 1.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3d(0.0, 1.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3d(0.0, 2.0, -1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3d(0.0, 2.0, 1.0);
    glEnd();
    glPopMatrix();

    for(int i = 0; i < 2; i++)
    {
        // wheel 1
        glColor3d(0.0, 0.0, 0.0);
        glPushMatrix();
        glTranslated(-2.5, 0.7, z_array_wheel[i]);
        draw_circle(0.7, 16, textures[CAR_WHEEL_TEXTURE]);
        glPopMatrix();

        // wheel 2
        glColor3d(0.0, 0.0, 0.0);
        glPushMatrix();
        glTranslated(1.0, 0.7, z_array_wheel[i]);
        draw_circle(0.7, 16, textures[CAR_WHEEL_TEXTURE]);
        glPopMatrix();
    }

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

// Draw wall of Castle Pillar
void draw_castle_pillar_wall()
{
    GLdouble wall_angle[] = {0.0, 90.0, 180.0, 270.0};

    for(int i = 0; i < 4; i++)
    {
        glPushMatrix();
        glRotated(wall_angle[i], 0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(-1.5, 0.0, 1.5);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(1.5, 0.0, 1.5);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(1.5, 10.0, 1.5);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-1.5, 10.0, 1.5);
        glEnd();
        glPopMatrix();
    }
}

#endif // DISPLAY_H_INCLUDED

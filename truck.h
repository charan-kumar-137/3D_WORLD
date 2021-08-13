#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include<math.h>
#include "shape.h"
#include "vertices.h"
#include "truck_color.h"

// Position for parts
GLdouble z_part_position[] = {1.0, -1.0};
GLdouble z_wheel_position[] = {0.75, -1.0};

void draw_truck();

void draw_hood();
void draw_hood_front();
void draw_hood_top();

void draw_front_side();

void draw_body();
void draw_glass();
void draw_door();
void draw_top();
void draw_floor();

void draw_tail();
void draw_tail_side();
void draw_tail_rear();

void draw_light();

void draw_wheel();

void DrawCircle(float, float, float, int);

// Draw a circular object
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / (float) num_segments;
    float tangetial_factor = tanf(theta);

    float radial_factor = cosf(theta);

    float x = r;

    float y = 0;

    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);

        float tx = -y;
        float ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

// Draw Truck
void draw_truck()
{
    // vehicle position
    glPushMatrix();
    glTranslated(truck_x, truck_y, truck_z);
    glRotated(truck_angle, 0.0, 1.0, 0.0);

    // body
    glPushMatrix();
    glTranslated(0.0, 0.4, 0.0);
    draw_hood();
    draw_hood_front();
    draw_hood_top();

    draw_front_side();

    draw_body();
    draw_glass();
    draw_door();
    draw_top();
    draw_floor();

    draw_tail();
    draw_tail_side();
    draw_tail_rear();

    draw_light();
    glPopMatrix();

    // wheels
    draw_wheel();
    glPopMatrix();
}

// Draw Hood
void draw_hood()
{
    for(int i = 0; i < 2; i++)
    {
        glPushMatrix();
        glTranslated(0.0, 1.0, z_part_position[i]);
        truck_primary_color();
        draw_4_vertex_polygon(truck_hood_vertices);
        glPopMatrix();
    }
}

// Draw Hood - front
void draw_hood_front()
{
    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0);
    truck_primary_color();
    draw_4_vertex_polygon(truck_hood_front_vertices);
    glPopMatrix();
}

// Draw Hood - top
void draw_hood_top()
{
    glPushMatrix();
    glTranslated(0.0, 1.5, 0.0);
    truck_secondary_color();
    draw_4_vertex_polygon(truck_hood_top_vertices);
    glPopMatrix();
}

// Draw Front - Side
void draw_front_side()
{
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(0.4, 0.0,z_part_position[i]);
        truck_primary_color();
        draw_4_vertex_polygon(truck_front_side_vertices);
        glPopMatrix();
    }

    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(0.0, 0.0,z_part_position[i]);
        draw_4_vertex_polygon(truck_front_side_2_vertices);
        glPopMatrix();
    }
}

// Draw Body
void draw_body()
{
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(1.45, 0.0, z_part_position[i]);
        draw_4_vertex_polygon(truck_body_1_vertices);
        draw_4_vertex_polygon(truck_body_2_vertices);
        draw_4_vertex_polygon(truck_body_3_vertices);
        draw_4_vertex_polygon(truck_body_4_vertices);
        draw_4_vertex_polygon(truck_body_5_vertices);
        glPopMatrix();
    }
}

// Draw Glass
void draw_glass()
{
    glPushMatrix();
    glTranslated(1.45, 0.0, 0.0);
    glColor3d(0.0, 0.0, 1.0);
    draw_4_vertex_polygon(truck_glass_vertices);
    glPopMatrix();
}

// Draw Door
void draw_door()
{
    // left
    glPushMatrix();
    glTranslated(1.45, 0.0, 1.0);
    truck_secondary_color();
    draw_4_vertex_polygon(truck_door_left_1_vertices);
    draw_4_vertex_polygon(truck_door_left_2_vertices);
    draw_4_vertex_polygon(truck_door_left_3_vertices);
    draw_4_vertex_polygon(truck_door_left_4_vertices);
    glPopMatrix();

    // right
    glPushMatrix();
    glTranslated(1.45, 0.0, -1.0);
    truck_secondary_color();
    draw_4_vertex_polygon(truck_door_right_1_vertices);
    draw_4_vertex_polygon(truck_door_right_2_vertices);
    draw_4_vertex_polygon(truck_door_right_3_vertices);
    draw_4_vertex_polygon(truck_door_right_4_vertices);
    glPopMatrix();

    // left glass
    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(1.45, 0.0, 1.0);
    draw_4_vertex_polygon(truck_door_glass_left_vertices);
    glPopMatrix();

    // right glass
    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(1.45, 0.0, -1.0);
    draw_4_vertex_polygon(truck_door_glass_right_vertices);
    glPopMatrix();
}

// Draw Top
void draw_top()
{
    glPushMatrix();
    glTranslated(1.5, 0.0, 0.0);
    truck_secondary_color();
    draw_4_vertex_polygon(truck_top_1_vertices);
    draw_4_vertex_polygon(truck_top_2_vertices);
    draw_4_vertex_polygon(truck_top_3_vertices);
    draw_4_vertex_polygon(truck_top_4_vertices);
    glPopMatrix();

    // glass
    glPushMatrix();
    glTranslated(1.5, 0.0, 0.0);
    glColor3d(0.0, 0.0, 1.0);
    draw_4_vertex_polygon(truck_top_glass_vertices);
    glPopMatrix();
}

// Draw Floor
void draw_floor()
{
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3d(-0.75, 0.5, 1.0);
    glVertex3d(4.0, 0.5, 1.0);
    glVertex3d(4.0, 0.5, -1.0);
    glVertex3d(-0.75, 0.5, -1.0);
    glEnd();
    glPopMatrix();
}

// Draw Tail
void draw_tail()
{
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(3.15, 2.0, z_part_position[i]);
        truck_secondary_color();
        draw_4_vertex_polygon(truck_tail_1_vertices);
        draw_4_vertex_polygon(truck_tail_2_vertices);
        draw_4_vertex_polygon(truck_tail_3_vertices);
        draw_4_vertex_polygon(truck_tail_4_vertices);
        glPopMatrix();

        // glass
        glPushMatrix();
        glTranslated(3.15, 2.0, z_part_position[i]);
        glColor3d(0.0, 0.0, 1.0);
        draw_4_vertex_polygon(truck_tail_glass_vertices);
        glPopMatrix();
    }
}

// Draw Tail - side
void draw_tail_side()
{
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(3.15, 0.5, z_part_position[i]);
        truck_primary_color();
        draw_4_vertex_polygon(truck_tail_side_1_vertices);
        glPopMatrix();

        glPushMatrix();
        glTranslated(3.15, 0.0, z_part_position[i]);
        draw_4_vertex_polygon(truck_tail_side_2_vertices);
        glPopMatrix();

        glPushMatrix();
        glTranslated(3.15, 0.0, z_part_position[i]);
        draw_4_vertex_polygon(truck_tail_side_3_vertices);
        glPopMatrix();
    }
}

// Draw Tail - rear
void draw_tail_rear()
{
    // bottom
    glPushMatrix();
    glTranslated(3.0, 0.0, 0.0);
    draw_4_vertex_polygon(truck_tail_bottom_vertices);
    glPopMatrix();

    // top
    glPushMatrix();
    glTranslated(3.0, 0.0, 0.0);
    truck_secondary_color();
    draw_4_vertex_polygon(truck_tail_top_1_vertices);
    draw_4_vertex_polygon(truck_tail_top_2_vertices);
    draw_4_vertex_polygon(truck_tail_top_3_vertices);
    glPopMatrix();

    // glass
    glPushMatrix();
    glTranslated(3.0, 0.0, 0.0);
    glColor3d(0.0, 0.0, 1.0);
    draw_4_vertex_polygon(truck_tail_rear_glass_vertices);
    glPopMatrix();
}

// Draw Light
void draw_light()
{
    GLdouble light_pos_z[] = {0.7, -0.7};

    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(-0.751, 1.0, light_pos_z[i]);
        glRotated(90.0, 0.0, 1.0, 0.0);
        glColor3d(1.0, 1.0, 0.0);
        DrawCircle(0.0, 0.0, 0.2, 15);
        glPopMatrix();
    }
}

// Draw Wheels
void draw_wheel()
{
    GLUquadricObj *quad;
    quad = gluNewQuadric();

    // front
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(0.0, 0.5, z_wheel_position[i]);
        truck_secondary_color();
        gluCylinder(quad, 0.3, 0.3, 0.25, 16, 16);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.0, 0.0, z_part_position[i]);
        DrawCircle(0.0, 0.5, 0.3, 16);
        glPopMatrix();
    }

    // rear
    for(int i = 0; i< 2; i++)
    {
        glPushMatrix();
        glTranslated(3.15, 0.5, z_wheel_position[i]);
        truck_secondary_color();
        gluCylinder(quad, 0.3, 0.3, 0.25, 16, 16);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.0, 0.0, z_part_position[i]);
        DrawCircle(3.15, 0.5, 0.3, 16);
        glPopMatrix();
    }
}

#endif // TRUCK_H_INCLUDED

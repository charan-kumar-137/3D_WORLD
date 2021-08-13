#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include "parameters.h"
#include "vertices.h"

void move_camera(unsigned char);
void move_car(unsigned char);
void move_truck(unsigned char);
void handle_full_screen();
void handle_castle_door();
void car_forward();
void car_backward();
void truck_forward();
void truck_backward();
void truck_hood();
void truck_door_left();
void truck_door_right();
void truck_rear();
void truck_top_glass();

// Move the Camera
void move_camera(unsigned char key)
{
    float fraction = 1.0f;

    switch (key)
    {
    case 'a' :
        angle_x -= 0.01f;
        lx = sin(angle_x);
        lz = -cos(angle_x);
        break;
    case 'd' :
        angle_x += 0.01f;
        lx = sin(angle_x);
        lz = -cos(angle_x);
        break;
    case 'w' :
        cam_x += lx * fraction;
        cam_z += lz * fraction;
        break;
    case 's' :
        cam_x -= lx * fraction;
        cam_z -= lz * fraction;
        break;
    case 'q':
        cam_y += 1.0;
        break;
    case 'e':
        cam_y = (cam_y == 1.0? 1.0 : cam_y - 1.0);
        break;
    }

}

// Move The Car
void move_car(unsigned char key)
{
    switch (key)
    {
    case 'a' :
        car_angle = (car_angle == 360? 90: car_angle + 90.0);
        break;
    case 'd' :
        car_angle = (car_angle == 0? 270: car_angle - 90.0);
        break;
    case 'w' :
        car_forward();
        break;
    case 's' :
        car_backward();
        break;
    }
}

// Move The Truck
void move_truck(unsigned char key)
{
    switch (key)
    {
    case 'a' :
        truck_angle = (truck_angle == 360? 90: truck_angle + 90.0);
        break;
    case 'd' :
        truck_angle = (truck_angle == 0? 270: truck_angle - 90.0);
        break;
    case 'w' :
        truck_forward();
        break;
    case 's' :
        truck_backward();
        break;
    }
}

// Set/Unset FullScreen
void handle_full_screen()
{
    full_screen_flag = (full_screen_flag == 0? 1: 0);
    if(full_screen_flag)
    {
        glutFullScreen();
    }
    else
    {
        glutPositionWindow(0, 0);
        glutReshapeWindow(1920, 1080);
    }
}

// Close/Open Castle Door
void handle_castle_door()
{
    castle_door_pos_x = (castle_door_pos_x == 0.0? 4.0:0.0);
}

// Handle car forward movement
void car_forward()
{
    switch((int) car_angle)
    {
    case 0:
        car_x += 1.0;
        break;
    case 90:
        car_z -= 1.0;
        break;
    case 180:
        car_x -= 1.0;
        break;
    case 270:
        car_z += 1.0;
        break;
    case 360:
        car_x += 1.0;
        break;
    }
}

// Handle car backward movement
void car_backward()
{
    switch((int) car_angle)
    {
    case 0:
        car_x -= 1.0;
        break;
    case 90:
        car_z += 1.0;
        break;
    case 180:
        car_x += 1.0;
        break;
    case 270:
        car_z -= 1.0;
        break;
    case 360:
        car_x -= 1.0;
        break;
    }
}

// Handle truck forward movement
void truck_forward()
{
    switch((int) truck_angle)
    {
    case 0:
        truck_x -= 1.0;
        break;
    case 90:
        truck_z += 1.0;
        break;
    case 180:
        truck_x += 1.0;
        break;
    case 270:
        truck_z -= 1.0;
        break;
    case 360:
        truck_x -= 1.0;
        break;
    }
}

// Handle truck backward movement
void truck_backward()
{
    switch((int) truck_angle)
    {
    case 0:
        truck_x += 1.0;
        break;
    case 90:
        truck_z -= 1.0;
        break;
    case 180:
        truck_x -= 1.0;
        break;
    case 270:
        truck_z += 1.0;
        break;
    case 360:
        truck_x += 1.0;
        break;
    }
}

// Open/Close truck hood
void truck_hood()
{
    truck_door_flag[0] = (truck_door_flag[0] == 0 ? 1: 0 );

    if(truck_door_flag[0] == 1)
    {
        truck_hood_top_vertices[0][0] = 0.0;
        truck_hood_top_vertices[0][1] = 2.0;
        truck_hood_top_vertices[1][0] = 0.0;
        truck_hood_top_vertices[1][1] = 2.0;
    }
    else
    {
        truck_hood_top_vertices[0][0] = -0.75;
        truck_hood_top_vertices[0][1] = 0.0;
        truck_hood_top_vertices[1][0] = -0.75;
        truck_hood_top_vertices[1][1] = 0.0;
    }
}

// Open/Close truck left door
void truck_door_left()
{
    truck_door_flag[1] = (truck_door_flag[1] == 0 ? 1: 0 );

    // bottom part
    if(truck_door_flag[1] == 1)
    {
        truck_door_left_1_vertices[1][0] = 0.17;
        truck_door_left_1_vertices[1][2] = 0.77;
        truck_door_left_1_vertices[2][0] = 0.17;
        truck_door_left_1_vertices[2][2] = 0.77;

    }
    else
    {
        truck_door_left_1_vertices[1][0] = 0.5;
        truck_door_left_1_vertices[1][2] = 0.0;
        truck_door_left_1_vertices[2][0] = 0.5;
        truck_door_left_1_vertices[2][2] = 0.0;
    }

    // left part
    if(truck_door_flag[1] == 1)
    {
        truck_door_left_2_vertices[0][0] = 0.03;
        truck_door_left_2_vertices[0][2] = 0.63;

        truck_door_left_2_vertices[1][0] = 0.17;
        truck_door_left_2_vertices[1][2] = 0.77;

        truck_door_left_2_vertices[2][0] = 0.17;
        truck_door_left_2_vertices[2][2] = 0.77;

        truck_door_left_2_vertices[3][0] = 0.03;
        truck_door_left_2_vertices[3][2] = 0.63;

    }
    else
    {
        truck_door_left_2_vertices[0][0] = 0.3;
        truck_door_left_2_vertices[0][2] = 0.0;

        truck_door_left_2_vertices[1][0] = 0.5;
        truck_door_left_2_vertices[1][2] = 0.0;

        truck_door_left_2_vertices[2][0] = 0.5;
        truck_door_left_2_vertices[2][2] = 0.0;

        truck_door_left_2_vertices[3][0] = 0.3;
        truck_door_left_2_vertices[3][2] = 0.0;
    }

    // top part
    if(truck_door_flag[1] == 1)
    {
        truck_door_left_3_vertices[0][0] = -0.31;
        truck_door_left_3_vertices[0][2] = 0.28;

        truck_door_left_3_vertices[1][0] = 0.03;
        truck_door_left_3_vertices[1][2] = 0.63;

        truck_door_left_3_vertices[2][0] = 0.03;
        truck_door_left_3_vertices[2][2] = 0.63;

        truck_door_left_3_vertices[3][0] = -0.38;
        truck_door_left_3_vertices[3][2] = 0.21;

    }
    else
    {
        truck_door_left_3_vertices[0][0] = -0.2;
        truck_door_left_3_vertices[0][2] = 0.0;

        truck_door_left_3_vertices[1][0] = 0.3;
        truck_door_left_3_vertices[1][2] = 0.0;

        truck_door_left_3_vertices[2][0] = 0.3;
        truck_door_left_3_vertices[2][2] = 0.0;

        truck_door_left_3_vertices[3][0] = -0.3;
        truck_door_left_3_vertices[3][2] = 0.0;
    }

    // right part
    if(truck_door_flag[1] == 1)
    {
        truck_door_left_4_vertices[0][0] = -0.6;
        truck_door_left_4_vertices[0][2] = 0.0;

        truck_door_left_4_vertices[1][0] = -0.45;
        truck_door_left_4_vertices[1][2] = 0.14;

        truck_door_left_4_vertices[2][0] = -0.31;
        truck_door_left_4_vertices[2][2] = 0.28;

        truck_door_left_4_vertices[3][0] = -0.38;
        truck_door_left_4_vertices[3][2] = 0.21;

    }
    else
    {
        truck_door_left_4_vertices[0][0] = -0.6;
        truck_door_left_4_vertices[0][2] = 0.0;

        truck_door_left_4_vertices[1][0] = -0.4;
        truck_door_left_4_vertices[1][2] = 0.0;

        truck_door_left_4_vertices[2][0] = -0.2;
        truck_door_left_4_vertices[2][2] = 0.0;

        truck_door_left_4_vertices[3][0] = -0.3;
        truck_door_left_4_vertices[3][2] = 0.0;
    }

    // glass
    if(truck_door_flag[1] == 1)
    {
        truck_door_glass_left_vertices[0][0] = -0.45;
        truck_door_glass_left_vertices[0][2] = 0.14;

        truck_door_glass_left_vertices[1][0] = 0.03;
        truck_door_glass_left_vertices[1][2] = 0.63;

        truck_door_glass_left_vertices[2][0] = 0.03;
        truck_door_glass_left_vertices[2][2] = 0.63;

        truck_door_glass_left_vertices[3][0] = -0.31;
        truck_door_glass_left_vertices[3][2] = 0.28;

    }
    else
    {
        truck_door_glass_left_vertices[0][0] = -0.4;
        truck_door_glass_left_vertices[0][2] = 0.0;

        truck_door_glass_left_vertices[1][0] = 0.3;
        truck_door_glass_left_vertices[1][2] = 0.0;

        truck_door_glass_left_vertices[2][0] = 0.3;
        truck_door_glass_left_vertices[2][2] = 0.0;

        truck_door_glass_left_vertices[3][0] = -0.2;
        truck_door_glass_left_vertices[3][2] = 0.0;
    }
}

// Open/Close truck right door
void truck_door_right()
{
    truck_door_flag[2] = (truck_door_flag[2] == 0 ? 1: 0 );

    // bottom part
    if(truck_door_flag[2] == 1)
    {
        truck_door_right_1_vertices[1][0] = 0.17;
        truck_door_right_1_vertices[1][2] = -0.77;
        truck_door_right_1_vertices[2][0] = 0.17;
        truck_door_right_1_vertices[2][2] = -0.77;

    }
    else
    {
        truck_door_right_1_vertices[1][0] = 0.5;
        truck_door_right_1_vertices[1][2] = 0.0;
        truck_door_right_1_vertices[2][0] = 0.5;
        truck_door_right_1_vertices[2][2] = 0.0;
    }

    // left part
    if(truck_door_flag[2] == 1)
    {
        truck_door_right_2_vertices[0][0] = 0.03;
        truck_door_right_2_vertices[0][2] = -0.63;

        truck_door_right_2_vertices[1][0] = 0.17;
        truck_door_right_2_vertices[1][2] = -0.77;

        truck_door_right_2_vertices[2][0] = 0.17;
        truck_door_right_2_vertices[2][2] = -0.77;

        truck_door_right_2_vertices[3][0] = 0.03;
        truck_door_right_2_vertices[3][2] = -0.63;

    }
    else
    {
        truck_door_right_2_vertices[0][0] = 0.3;
        truck_door_right_2_vertices[0][2] = 0.0;

        truck_door_right_2_vertices[1][0] = 0.5;
        truck_door_right_2_vertices[1][2] = 0.0;

        truck_door_right_2_vertices[2][0] = 0.5;
        truck_door_right_2_vertices[2][2] = 0.0;

        truck_door_right_2_vertices[3][0] = 0.3;
        truck_door_right_2_vertices[3][2] = 0.0;
    }

    // top part
    if(truck_door_flag[2] == 1)
    {
        truck_door_right_3_vertices[0][0] = -0.31;
        truck_door_right_3_vertices[0][2] = -0.28;

        truck_door_right_3_vertices[1][0] = 0.03;
        truck_door_right_3_vertices[1][2] = -0.63;

        truck_door_right_3_vertices[2][0] = 0.03;
        truck_door_right_3_vertices[2][2] = -0.63;

        truck_door_right_3_vertices[3][0] = -0.38;
        truck_door_right_3_vertices[3][2] = -0.21;

    }
    else
    {
        truck_door_right_3_vertices[0][0] = -0.2;
        truck_door_right_3_vertices[0][2] = 0.0;

        truck_door_right_3_vertices[1][0] = 0.3;
        truck_door_right_3_vertices[1][2] = 0.0;

        truck_door_right_3_vertices[2][0] = 0.3;
        truck_door_right_3_vertices[2][2] = 0.0;

        truck_door_right_3_vertices[3][0] = -0.3;
        truck_door_right_3_vertices[3][2] = 0.0;
    }

    // right part
    if(truck_door_flag[2] == 1)
    {
        truck_door_right_4_vertices[0][0] = -0.6;
        truck_door_right_4_vertices[0][2] = 0.0;

        truck_door_right_4_vertices[1][0] = -0.45;
        truck_door_right_4_vertices[1][2] = -0.14;

        truck_door_right_4_vertices[2][0] = -0.31;
        truck_door_right_4_vertices[2][2] = -0.28;

        truck_door_right_4_vertices[3][0] = -0.38;
        truck_door_right_4_vertices[3][2] = -0.21;

    }
    else
    {
        truck_door_right_4_vertices[0][0] = -0.6;
        truck_door_right_4_vertices[0][2] = 0.0;

        truck_door_right_4_vertices[1][0] = -0.4;
        truck_door_right_4_vertices[1][2] = 0.0;

        truck_door_right_4_vertices[2][0] = -0.2;
        truck_door_right_4_vertices[2][2] = 0.0;

        truck_door_right_4_vertices[3][0] = -0.3;
        truck_door_right_4_vertices[3][2] = 0.0;
    }

    // glass
    if(truck_door_flag[2] == 1)
    {
        truck_door_glass_right_vertices[0][0] = -0.45;
        truck_door_glass_right_vertices[0][2] = -0.14;

        truck_door_glass_right_vertices[1][0] = 0.03;
        truck_door_glass_right_vertices[1][2] = -0.63;

        truck_door_glass_right_vertices[2][0] = 0.03;
        truck_door_glass_right_vertices[2][2] = -0.63;

        truck_door_glass_right_vertices[3][0] = -0.31;
        truck_door_glass_right_vertices[3][2] = -0.28;

    }
    else
    {
        truck_door_glass_right_vertices[0][0] = -0.4;
        truck_door_glass_right_vertices[0][2] = 0.0;

        truck_door_glass_right_vertices[1][0] = 0.3;
        truck_door_glass_right_vertices[1][2] = 0.0;

        truck_door_glass_right_vertices[2][0] = 0.3;
        truck_door_glass_right_vertices[2][2] = 0.0;

        truck_door_glass_right_vertices[3][0] = -0.2;
        truck_door_glass_right_vertices[3][2] = 0.0;
    }
}

// Open/Close truck rear door
void truck_rear()
{
    truck_door_flag[3] = (truck_door_flag[3] == 0? 1: 0);
    if(truck_door_flag[3] == 1)
    {
        truck_tail_rear_glass_vertices[0][0] = 2.45;
        truck_tail_rear_glass_vertices[0][1] = 2.8;

        truck_tail_rear_glass_vertices[1][0] = 2.45;
        truck_tail_rear_glass_vertices[1][1] = 2.8;

    }
    else
    {
        truck_tail_rear_glass_vertices[0][0] = 1.15;
        truck_tail_rear_glass_vertices[0][1] = 1.5;

        truck_tail_rear_glass_vertices[1][0] = 1.15;
        truck_tail_rear_glass_vertices[1][1] = 1.5;
    }
}

// Open/Close truck top glass
void truck_top_glass()
{
    truck_door_flag[4] = (truck_door_flag[4] == 0? 1: 0);
    if(truck_door_flag[4] == 1)
    {
        truck_top_glass_vertices[2][0] = -0.05;
        truck_top_glass_vertices[2][1] = 3.35;

        truck_top_glass_vertices[3][0] = -0.05;
        truck_top_glass_vertices[3][1] = 3.35;

    }
    else
    {
        truck_top_glass_vertices[2][0] = -0.2;
        truck_top_glass_vertices[2][1] = 3.0;

        truck_top_glass_vertices[3][0] = -0.2;
        truck_top_glass_vertices[3][1] = 3.0;
    }
}

#endif // ACTION_H_INCLUDED

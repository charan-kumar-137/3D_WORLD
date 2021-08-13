#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED


#include "action.h"

void input_init();
void keyboard(unsigned char, int, int);
void mouseButton(int, int, int, int);
void mouseMove(int, int);
void menu_init();
void menu_function(int);
void movement_menu(int);
void truck_menu(int);
void truck_color_menu(int);

// Register Input callbacks
void input_init()
{
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    menu_init();
}

// Define keyboard actions
void keyboard(unsigned char key, int xx, int yy)
{
    switch(veh_select_flag)
    {
    case 0:
        move_camera(key);
        break;
    case 1:
        move_car(key);
        break;
    case 2:
        move_truck(key);
        break;
    }
}

// Handle Mouse position
void mouseButton(int button, int state, int x, int y)
{
    if (state == GLUT_UP)
    {
        angle_x += deltaAngle_x;
        angle_y += deltaAngle_y;

        xOrigin = -1;
        yOrigin = -1;
    }
    else
    {
        xOrigin = x;
        yOrigin = y;
    }
}

// Track Mouse Position
void mouseMove(int x, int y)
{
    if (xOrigin >= 0)
    {
        deltaAngle_x = (x - xOrigin) * 0.001f;
        lx = sin(angle_x + deltaAngle_x);
        lz = -cos(angle_x + deltaAngle_x);
    }
    if(yOrigin >= 0)
    {
        deltaAngle_y = (y - yOrigin) * 0.001f;
        ly = sin(angle_y + deltaAngle_y);
    }
}

// Define Menu actions
void menu_init()
{
    // Movement Menu
    int movement_menu_id = glutCreateMenu(movement_menu);
    glutAddMenuEntry("Camera", 0);
    glutAddMenuEntry("Car", 1);
    glutAddMenuEntry("Truck", 2);

    // Truck Menu
    int truck_menu_id = glutCreateMenu(truck_menu);
    glutAddMenuEntry("Truck Hood", 0);
    glutAddMenuEntry("Truck Left", 1);
    glutAddMenuEntry("Truck Right", 2);
    glutAddMenuEntry("Truck Rear", 3);
    glutAddMenuEntry("Truck Top", 4);

    // Truck color Menus
    int truck_color_menu_id = glutCreateMenu(truck_color_menu);
    glutAddMenuEntry("Red", 0);
    glutAddMenuEntry("Green", 1);
    glutAddMenuEntry("Black", 2);

    // Main Menu
    glutCreateMenu(menu_function);
    glutAddSubMenu("Movement", movement_menu_id);
    glutAddSubMenu("Truck", truck_menu_id);
    glutAddSubMenu("Truck Color", truck_color_menu_id);
    glutAddMenuEntry("Castle Door", 0);
    glutAddMenuEntry("Full Screen", 1);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Define Movement menu actions
void movement_menu(int num)
{
    switch(num)
    {
    case 0:
        veh_select_flag = 0;
        break;
    case 1:
        veh_select_flag = 1;
        break;
    case 2:
        veh_select_flag = 2;
        break;
    }
}

// Define truck menu actions
void truck_menu(int num)
{
    switch(num)
    {
    case 0:
        truck_hood();
        break;
    case 1:
        truck_door_left();
        break;
    case 2:
        truck_door_right();
        break;
    case 3:
        truck_rear();
        break;
    case 4:
        truck_top_glass();
        break;
    }
}

// Define truck color menu actions
void truck_color_menu(int num)
{
    truck_primary_color_flag = num;
}

// Define main menu actions
void menu_function(int menu)
{
    switch(menu)
    {
    case 0:
        handle_castle_door();
        break;
    case 1:
        handle_full_screen();
        break;
    }
}


#endif // INPUT_H_INCLUDED

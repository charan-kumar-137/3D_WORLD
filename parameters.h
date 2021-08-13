#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

// angle of rotation for the camera direction
extern float angle_x, angle_y;
// Camera lookup position
extern float lx, ly, lz;
// XYZ position of the camera
extern float cam_x, cam_y, cam_z;

// change in angle
extern float deltaAngle_x, deltaAngle_y;
// track mouse action
extern int xOrigin, yOrigin;

// car position
extern GLdouble car_x, car_y, car_z;
extern GLdouble car_angle;

// truck position
extern GLdouble truck_x, truck_y, truck_z;
extern GLdouble truck_angle;

// select Vehicle: 0 - None, 1 - Car, 2 - Truck
extern int veh_select_flag;

// Truck door ( binary ): 0 - hood, 1 - Left, 2 - Right, 3 - Rear, 4 - top glass
extern int truck_door_flag[];

// Full Screen (binary)
extern int full_screen_flag;

extern GLdouble castle_door_pos_x;

extern int truck_primary_color_flag;


float angle_x=0.0, angle_y= 0.0;

float lx=0.0f,ly = 0.0f, lz=-1.0f;
float cam_x=0.0f, cam_y = 2.0f, cam_z=40.0f;

float deltaAngle_x = 0.0f, deltaAngle_y = 0.0f;
int xOrigin = -1, yOrigin = -1;

GLdouble car_x = -15.0, car_y = 0.0, car_z = 0.0;
GLdouble car_angle = 0.0;

GLdouble truck_x = 15.0, truck_y = 0.0, truck_z = 0.0;
GLdouble truck_angle = 0.0;

int veh_select_flag = 0;
int truck_door_flag[] = {0, 0, 0, 0, 0};

int full_screen_flag = 0;

GLdouble castle_door_pos_x = 0.0;

int truck_primary_color_flag = 0;

#endif // PARAMETERS_H_INCLUDED

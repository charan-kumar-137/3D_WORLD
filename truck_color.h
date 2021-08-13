#ifndef TRUCK_COLOR_H_INCLUDED
#define TRUCK_COLOR_H_INCLUDED

void truck_primary_color();
void truck_secondary_color();

// Truck Primary Color
void truck_primary_color()
{
    switch(truck_primary_color_flag)
    {
    case 0: // Red
        glColor3d(1.0, 0.0, 0.0);
        break;
    case 1: // Green
        glColor3d(0.0, 1.0, 0.0);
        break;
    case 2: // Black
        glColor3d(0.0, 0.0, 0.0);
        break;
    }
}

// Truck Secondary Color
void truck_secondary_color()
{
    if(truck_primary_color_flag == 0 || truck_primary_color_flag == 1)
        glColor3d(0.0, 0.0, 0.0); // Black
    else
        glColor3d(0.0, 1.0, 0.0); // Green
}

#endif // TRUCK_COLOR_H_INCLUDED

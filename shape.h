#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

void draw_4_vertex_polygon(GLdouble [4][3]);

void draw_4_vertex_polygon(GLdouble vertices[4][3])
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 4; i++)
        glVertex3dv(vertices[i]);
    glEnd();
}

#endif // SHAPE_H_INCLUDED

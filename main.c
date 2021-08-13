#include<GL/glut.h>
#include<math.h>

#include<stdio.h>
#include "display.h"
#include "input.h"

void init();
void reshape(int, int);

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.52, 0.8, 0.92, 1.0);

    // texture
    glShadeModel(GL_SMOOTH);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    texture_init();
}

void reshape(int w, int h)
{
    h = ( h == 0 ? 1 : h );
    glViewport(0.0, 0.0, w, h);

    GLdouble aspect = w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// main
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("3D WORLD");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    input_init();

    glutMainLoop();

    return 0;
}

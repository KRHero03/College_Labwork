#include <GL/glut.h>
#include <stdio.h>

// To Compile:-
// g++ -pthread 1.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut


float points[6][2] = {{0.25f,0.433f},{-0.25f,0.433f},{-0.5f,0.0f},{-0.25f,-0.433f},{0.25f,-0.433f},{0.5f,0.0f}};

void showPoints()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    for(int i = 0;i<6;i++){
        glBegin(GL_POINTS);
        glVertex2f(points[i][0],points[i][1]);
        glEnd();
    }
    glutSwapBuffers();
}

void showLines(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    for(int i = 0;i<5;i+=2){
        glBegin(GL_LINES);
        glVertex2f(points[i][0],points[i][1]);
        glVertex2f(points[i+1][0],points[i+1][1]);
        glEnd();
    }
    glutSwapBuffers();
}

void showLineStrips(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    for(int i = 0;i<5;i++){
        glBegin(GL_LINES);
        glVertex2f(points[i][0],points[i][1]);
        glVertex2f(points[i+1][0],points[i+1][1]);
        glEnd();
    }
    glutSwapBuffers();

}


void showLoop(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    for(int i = 0;i<6;i++){
        glBegin(GL_LINES);
        glVertex2f(points[i][0],points[i][1]);
        glVertex2f(points[(i+1)%6][0],points[(i+1)%6][1]);
        glEnd();
    }
    glutSwapBuffers();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment 4");

    glClearColor(1, 1, 1, 0);
    glShadeModel(GLU_FLAT);
    glPointSize(6.0);

    glutDisplayFunc(showLoop);
    glutMainLoop();
}
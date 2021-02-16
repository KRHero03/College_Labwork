#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// To Compile:-
// g++ -pthread 1.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut

int size = 9;
float points[9][2] = {{0.25f,0.433f},{-0.25f,0.433f},{-0.5f,0.0f},{-0.25f,-0.433f},{0.25f,-0.433f},{0.5f,0.0f},{-0.25f,0.433f},{-0.5f,0.0f},{-0.25f,-0.433f},};

void showTriangles()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    glBegin(GL_TRIANGLES);
    for(int i = 0;i<size;i++){
        glVertex2f(points[i][0],points[i][1]);
    }
    glEnd();
    glutSwapBuffers();
}

void showTriangleStripes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    glBegin(GL_TRIANGLE_STRIP_ADJACENCY);
    for(int i = 0;i<size;i++){
        if(i>=3) glColor3f(1,0,0);
        if(i>=6) glColor3f(0,1,0);
        glVertex2f(points[i][0],points[i][1]);
    }
    glEnd();
    glutSwapBuffers();
}

void showTriangleFans(){
    glClear(GL_COLOR_BUFFER_BIT);
    vector<vector<float>> points = {{0,0},{0,0.5},{0.5/1.414,0.5/1.414},{0.5,0}};
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0;i<points.size();i++){
        glColor3f(0.25*i,0,0);
        glVertex2f(points[i][0],points[i][1]);
    }
    glEnd();
    glutSwapBuffers();

}

void showQuad(){

    glClear(GL_COLOR_BUFFER_BIT);
    vector<vector<float>> points = {{0,0},{0,0.5},{0.5/1.414,0.5/1.414},{0.5,0},{0,0},{0,-0.5},{-0.5/1.414,-0.5/1.414},{-0.5,0}};
    glBegin(GL_QUADS);
    for(int i = 0;i<points.size();i++){
        glColor3f(0.125*i,0,0);
        glVertex2f(points[i][0],points[i][1]);
    }
    glEnd();
    glutSwapBuffers();
}

void showQuadStripe(){
    glClear(GL_COLOR_BUFFER_BIT);
    vector<vector<float>> points = {{0,0},{0,0.5},{0.5/1.414,0.5/1.414},{0.5,0},{0,0},{0,-0.5},{-0.5/1.414,-0.5/1.414},{-0.5,0}};
    glBegin(GL_QUAD_STRIP);
    for(int i = 0;i<points.size();i++){
        glColor3f(0.125*i,0,0);
        glVertex2f(points[i][0],points[i][1]);
    }
    glEnd();
    glutSwapBuffers();

}

void showPolygon(){
    glClear(GL_COLOR_BUFFER_BIT);
    vector<vector<float>> points = {{0,0},{0,0.5},{0.5/1.414,0.5/1.414},{0.5,0},{0,-0.5},{-0.5/1.414,-0.5/1.414},{-0.5,0}};
    glBegin(GL_POLYGON);
    for(int i = 0;i<points.size();i++){
        glColor3f(0.125*i,0,0);
        glVertex2f(points[i][0],points[i][1]);
    }
    glEnd();
    glutSwapBuffers();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment 5");

    glClearColor(1, 1, 1, 0);
    glShadeModel(GLU_FLAT);
    glPointSize(6.0);

    glutDisplayFunc(showPolygon);
    glutMainLoop();
}
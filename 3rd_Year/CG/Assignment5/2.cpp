#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// To Compile:-
// g++ -pthread 2.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void midpoint_circle_util(int r,int cx,int cy){

    int y = 0, x = r;
    int p = 1 - r;

    while(x>=y){
        plot(cx+x,cy+y);
        plot(cx-x,cy+y);
        plot(cx+x,cy-y);
        plot(cx-x,cy-y);
        plot(cx+y,cy+x);
        plot(cx-y,cy+x);
        plot(cx+y,cy-x);
        plot(cx-y,cy-x);
        if(p<=0){
            p += 2*(y+1)+1;
        }else{
            p += 2*(y+1)+1-2*(x+1);
            x--;
        }
        y++;
    }
}
void midpoint_circle(){
    glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
    glColor3f(0,0,1);
    midpoint_circle_util(100,400,300);
	glutSwapBuffers();
}

void midpoint_ellipse_util(int rx,int ry,int cx,int cy){
    float dx, dy, p1, p2, x, y; 
    x = 0; 
    y = ry; 
  
    p1 = (ry * ry) - (rx * rx * ry) +  
                     (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
  
    while (dx < dy)  
    {        
        plot(cx+x,cy+y);
        plot(cx-x,cy+y);
        plot(cx+x,cy-y);
        plot(cx-x,cy-y);
        if (p1 < 0) 
        { 
            x++; 
            dx = dx + (2 * ry * ry); 
            p1 = p1 + dx + (ry * ry); 
        } 
        else 
        { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            p1 = p1 + dx - dy + (ry * ry); 
        } 
    } 
  
    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +  
         ((rx * rx) * ((y - 1) * (y - 1))) - 
          (rx * rx * ry * ry); 
  
    while (y >= 0) 
    { 
        plot(cx+x,cy+y);
        plot(cx-x,cy+y);
        plot(cx+x,cy-y);
        plot(cx-x,cy-y);
        if (p2 > 0)  
        { 
            y--; 
            dy = dy - (2 * rx * rx); 
            p2 = p2 + (rx * rx) - dy; 
        } 
        else 
        { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            p2 = p2 + dx - dy + (rx * rx); 
        } 
    } 
}
void midpoint_ellipse(){
    glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
    glColor3f(0,0,1);
    midpoint_ellipse_util(150,100,200,200);
	glutSwapBuffers();
}

int main(int argc, char *argv[]){
    cout<<"Midpoint Algorithms\n1. Circle\n2. Ellpise\n>>";
    int choice;
    cin >> choice;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment 5");
    glShadeModel(GLU_FLAT);   
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);

    if(choice==1){        
        glutDisplayFunc(midpoint_circle);
    }else if(choice==2){
        glutDisplayFunc(midpoint_ellipse);
    }else{
        cout<<"Invalid Choice!"<<endl;
        return 0;
    }
    glutMainLoop();
}
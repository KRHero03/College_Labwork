#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// To Compile:-
// g++ -pthread 3.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut

int ax,bx,ay,by;
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

int get_side(int x,int y){
    return (y-ay)*(bx-ax)-(by-ay)*(x-ax)>=0;
}


void draw_line_bres(int x1, int y1, int x2, int y2,int t = 0)
{
    if(abs(y2-y1)>abs(x2-x1)){
        draw_line_bres(y1,x1,y2,x2,1);
        return;
    }
    if(x1>x2){
    	swap(x1,x2);
    	swap(y1,y2);
    }
    int inc = y1>y2?-1:1;
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new + inc==1?-(x2 - x1):(x2-x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        if(t) plot(y,x);
        else plot(x, y);

        slope_error_new += m_new;       

        if (inc==1 && slope_error_new >= 0) 
        { 
            y+=inc; 
            slope_error_new  -= 2 * (x2 - x1); 
        }else if(inc==-1 && slope_error_new<=0){
            y+=inc;
            slope_error_new += 2*(x2-x1);
        }
        
    }
}


void draw_half_circle(int r,int cx,int cy, int up){

    int y = 0, x = r;
    int p = 1 - r;

    while(x>=y){
        if(get_side(cx+x,cy+y)==up) plot(cx+x,cy+y);
        if(get_side(cx-x,cy+y)==up) plot(cx-x,cy+y);
        if(get_side(cx+y,cy+x)==up) plot(cx+y,cy+x);
        if(get_side(cx-y,cy+x)==up) plot(cx-y,cy+x);
        if(get_side(cx+x,cy-y)==up) plot(cx+x,cy-y);
        if(get_side(cx-x,cy-y)==up) plot(cx-x,cy-y);
        if(get_side(cx+y,cy-x)==up) plot(cx+y,cy-x);
        if(get_side(cx-y,cy-x)==up) plot(cx-y,cy-x);
        if(p<=0){
            p += 2*(y+1)+1;
        }else{
            p += 2*(y+1)+1-2*(x+1);
            x--;
        }
        y++;
    }
}

void draw_custom_util(){
    int midx = (ax + bx)/2;
    int midy = (ay + by)/2;

    int cx1 = (ax+midx)/2;
    int cy1 = (ay+midy)/2;

    int cx2 = (midx+bx)/2;
    int cy2 = (midy+by)/2;

    int r = sqrt(pow(ax-bx,2)+pow(ay-by,2))/4;

    draw_line_bres(ax,ay,bx,by);
    draw_half_circle(r,cx1,cy1,0);
    draw_half_circle(r,cx2,cy2,1);

}
void draw_custom(){
    glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
    glColor3f(0,0,1);
    draw_custom_util();
	glutSwapBuffers();
}


int main(int argc, char *argv[]){
    cout<<"Custom Diagram Drawing Program"<<endl;
    cout<<"AX: ";
    cin >> ax;
    cout<<"AY: ";
    cin >> ay;
    cout<<"BX: ";
    cin >> bx;
    cout<<"BY: ";
    cin >> by;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment 5");
    glShadeModel(GLU_FLAT);   
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);

    glutDisplayFunc(draw_custom);
    glutMainLoop();
}
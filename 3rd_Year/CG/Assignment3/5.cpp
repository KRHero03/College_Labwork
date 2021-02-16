#include <graphics.h>
#include <bits/stdc++.h>
#include <signal.h>

using namespace std;

void draw_car(int left, int top,int right,int bottom)
{
    assert(bottom>top);
    assert(right>left);

    int unitx = (right-left)/8;
    int unity = (bottom-top)/8;
    setcolor(4);
    bar(left+unitx,top+4*unity,right-unitx,bottom-2*unity);
    bar(left+2*unitx,top+2*unity,right-2*unitx,top+4*unity);
    
    setcolor(0);
    circle(left+2*unitx,bottom-2*unity,3*(unity)/4);
    floodfill(left+2*unitx,bottom-2*unity,0);
    circle(right-2*unitx,bottom-2*unity,3*(unity)/4);
    floodfill(right-2*unitx,bottom-2*unity,0);



}

int main()
{
    int gdriver = DETECT;
    int gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setbkcolor(15);
    int maxx = getmaxx();
    int maxy = getmaxy();

    int centerx = maxx / 2, centery = maxy / 2;
    int del = 10;
    int left = maxx/2-200,right = maxx/2+200,top=maxy/2-150,bottom = maxy/2+150;
    while(true){
        cleardevice();
        if(right+del>maxx) del = -10;
        else if(left+del<0) del = 10;
        left += del;
        right += del;
        draw_car(left, top,right,bottom);
        delay(30);
    }
    

    getch();
    closegraph();
}
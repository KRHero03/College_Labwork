#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int gdriver = DETECT;
    int gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    int maxx = getmaxx();
    int maxy = getmaxy();

    //grass
    setcolor(2);
    bar(0,(3*maxy)/4,maxx,maxy);

    //sky
    setcolor(3);
    bar(0,0,maxx,(3*maxy)/4);

    //tag
    setfontcolor(4);
    setcolor(1);
    outtextxy(10,10,"House Design");
    outtextxy(10,30,"By Krunal Rank");
    outtextxy(10,50,"U18CO081");


    //sun
    setcolor(14);
    circle((3*maxx)/4,100,50);
    floodfill((3*maxx)/4,100,14);

    //house 
    setcolor(6);
    bar(maxx/2-100,(3*maxy)/4-100,maxx/2+100,(3*maxy)/4);

    //roof
    setcolor(4);
    line(maxx/2-100,(3*maxy)/4-100,maxx/2+100,(3*maxy)/4-100);    
    line(maxx/2-100,(3*maxy)/4-100,maxx/2,(3*maxy)/4-200);
    line(maxx/2+100,(3*maxy)/4-100,maxx/2,(3*maxy)/4-200);
    floodfill(maxx/2,(3*maxy)/4-150,4);

    //door
    setcolor(15);
    bar(maxx/2-20,(3*maxy)/4-50,maxx/2+20,(3*maxy)/4);
    getch();
    closegraph();

}
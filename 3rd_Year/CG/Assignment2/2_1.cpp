#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, ""); //Used to fetch graphics driver and initialise the graph

   arc(100, 100, 0, 200, 100);                  // Draws Arc (x,y,start_angle,end_angle,radius)
   bar(100, 250, 200, 300);                     // Draws Bar (left,top,right,bottom)
   circle(250, 100, 50);                        // Draws circle (x,y,radius)
   line(100, 350, 200, 350);                    // Draws Lines (start_x,start_y,end_x,end_y)
   rectangle(250, 250, 350, 300);               // Draws Rectangle (left,top,right,bottom)
   ellipse(350, 250, 0, 180, 50, 20);           // Draws Ellipse (x,y,start_angle,end_angle,x_radius,y_radius)
   int arr[6] = {400, 450, 450, 400, 500, 450}; // Points in clockwise order
   fillpoly(3, arr);                            //Fills Polygon (no.of points, point array (having size 2 * no.of points))

   getch();
   closegraph();
   return 0;
}
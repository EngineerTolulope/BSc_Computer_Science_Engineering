
int s = 20;
void setup() {
  size(640, 480);
  background(0,0,255);
  noLoop( );
}
void drawGrid( )//draws the line grid
{
    for ( int i = 0; i <= 640; i += s )
      line(  i, 0, i, 480 );
    for ( int i = 0; i <= 480; i += s )
      line(  0, i, 640, i );
}
void drawPosition( int x, int y ){//This function draws the circle inside the squares
     ellipseMode( RADIUS );
     ellipse( s * x + 0.5 * s, s * y + 0.5 * s, 0.5 * s, 0.5 * s );
}
void drawMidpointCircle( int u, int v, int r )//function using the midpoint circle algorithm
{
  int xp = 0;
  int yp = r;
  int d  = 1 - r;
      
  drawPosition (u + xp, v + yp);//we use (u+xp, v+yp) because we are not drawing on the origin (xp,yp), so we have to translate first and draw
  drawPosition (u + yp, v + xp);//they are eight possiblity, if (x,y) on circle then y,x y,-x x,-y -x,-y -y,-x -y,x -x,y is on circle
  drawPosition (u+xp,v-yp);
  drawPosition(u-xp,v-yp);
  drawPosition(u-xp,v+yp);
  drawPosition(u+yp,v-xp);
  drawPosition(u-yp,v-xp);
  drawPosition(u-yp,v+xp);
  
  while(yp > xp)  {  //the while loop increments/decrements xp,yp to get new points and apply draw them as well
    if(d < 0) {
      d = d + xp * 2 + 3;
      xp++;
    }
    else {
      d = d + ( xp - yp ) * 2 + 5;
      xp++;
      yp--;
    }
  drawPosition (u + xp, v + yp);//draws new 8 possibilities and repeats the loop and draw again
  drawPosition (u + yp, v + xp);
  drawPosition (u+xp,v-yp);
  drawPosition(u-xp,v-yp);
  drawPosition(u-xp,v+yp);
  drawPosition(u+yp,v-xp);
  drawPosition(u-yp,v-xp);
  drawPosition(u-yp,v+xp);
    
    
  }
}
void drawMidpointLine( int x1, int y1, int x2, int y2 )//function using the midpoint line algorithm
{
  //.... implement it based on the pseudocode on the slide
  int a = y1 - y2;//Dy change in y // a=deltaY
  int b = -1*(x1 - x2);//Dx change in x//b= -deltaX
  int deltaE = 2*a;
  int deltaNE=2*(a+b);
  int d= 2*a + b;//initial delta
  int x=x1,y=y1;
  while(x <  x2)//we go from x1 to x2 
  {
    drawPosition(x, y);//we pass the new points to the function
                       //starting from initial ones
    if (d>=0)
      {
        d=d+deltaE;//we go to E next
        x+=1;
      }
    else
      {      
      d=d+deltaNE;
      x+=1;
      y+=1;
     }
  
}

  
}
void draw() {
  fill( 255,0,255 );//makes the circle points purple
  drawGrid( );//draws the grid lines
  drawMidpointCircle ( 10, 12, 7  ); 
  //Now we draw a line using midpoint line algorithm
  
  fill (0,255,0);//we draw points connecting the 2 end points in green colour 
  drawMidpointLine( 9, 10, 28, 13 );//passing the two end point
                                    //into the midpoint line algorithm 
  //drawMidpointLine( 1, 1, 30, 15 );//Example
  //we now draw the start and endpoint of the above line
  fill( 255, 0, 0 );//makes the fill red
  drawPosition( 9, 10 );//calls the drawPosition() giving x and y coordinates as (9,10)
  drawPosition( 28, 13 );
}
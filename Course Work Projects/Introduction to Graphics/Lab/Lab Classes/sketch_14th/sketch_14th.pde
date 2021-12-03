
int s = 20;
void setup() {
  size(640, 480);
  background(255);
  noLoop( );
}
void drawGrid( )
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
void drawMidpointCircle( int u, int v, int r )
{
  int xp = 0;
  int yp = r;
  int d  = 1 - r;
      
  drawPosition (u + xp, v + yp);
  drawPosition (u + yp, v + xp);
  //....
  //....
  //....
  //....
  //....
  //....
  
  while(yp > xp)  {  
    if(d < 0) {
      d = d + xp * 2 + 3;
      xp++;
    }
    else {
      d = d + ( xp - yp ) * 2 + 5;
      xp++;
      yp--;
    }
    drawPosition (u + xp, v + yp);
    drawPosition (u + yp, v + xp);
    //....
    //....
    //....
    //....
    //....
    //....
    
  }
}
void drawMidpointLine( int x1, int y1, int x2, int y2 )
{
  //.... implement it based on the pseudocode on the slide
}
void draw() {
  fill( 0 );
  drawGrid( );
  drawMidpointCircle ( 10, 12, 7  ); 
  fill( 255, 0, 0 );
  drawPosition( 9, 10 );
  drawPosition( 28, 13 );
  
  drawMidpointLine( 9, 10, 28, 13 );
}
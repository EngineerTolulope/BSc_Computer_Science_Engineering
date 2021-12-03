 
int radius = 5;
int dragged = -1;
int activePoint = -1;

inhom2d[] points;

class inhom2d {
  float x, y;
 
  inhom2d(float x, float y ) {
    this.x=x;
    this.y=y;
  } 
}

void setup() {
  size(640, 360);
  ellipseMode( RADIUS );
  points = new  inhom2d[ 3 ];
  points[ 0 ] = new inhom2d(100, 100);
  points[ 1 ] = new inhom2d(200, 300);
  points[ 2 ] = new inhom2d(300, 300);
}

int getActivePoint( inhom2d[] t, int size, int sens, int mousex, int mousey ) {
  inhom2d M = new inhom2d( mousex, mousey );
  
   for ( int i = 0; i < size; i++ ) {
        if ( (M.x-t[i].x)*(M.x-t[i].x)+(M.y-t[i].y)*(M.y-t[i].y) < sens*sens )
            return i;
   }
    return -1;
}

void draw() { 
  background(0);
  activePoint = getActivePoint( points, 3, 7, mouseX, mouseY );
  // Draw the circles
  for ( int i = 0; i < 3; i++ ) {
  ellipse(points[ i ].x, points[ i ].y, radius, radius );
  }
  noFill( );
  stroke( 255, 0, 0 );
  strokeWeight( 4 );
  beginShape();
    for ( int i = 0; i < 3; i++ )
      vertex( points[ i ].x, points[ i ].y );
  endShape();
  
  stroke( 255 );
  beginShape();
    for ( float t = 0; t <= 1; t += 0.01 )
      vertex( (1-t)*(1-t)*points[0].x + 2*t*(1-t)*points[1].x + t * t * points[ 2 ].x,
              (1-t)*(1-t)*points[0].y + 2*t*(1-t)*points[1].y + t * t * points[ 2 ].y  );
  endShape();
  
  
}

void mousePressed() {
  if (activePoint != -1 ) {  
    dragged = activePoint;
  }
}

void mouseDragged() {
  if(dragged!=-1) {
    points[dragged].x = mouseX; 
    points[dragged].y = mouseY; 
  }
}

void mouseReleased() {
  dragged = -1;
}

int radius = 5;
int sens = 8;
int dragged = -1;
int activePoint = -1;

point2d[] points;

class point2d {
  float x, y;

  point2d(float x, float y ) {
    this.x=x;
    this.y=y;
  }
}

void setup() {
  size(640, 360);
  ellipseMode( RADIUS );
  points = new  point2d[ 3 ];
  points[ 0 ] = new point2d(100, 100);
  points[ 1 ] = new point2d(200, 300);
  points[ 2 ] = new point2d(300, 300);
}

int getActivePoint( point2d[] t, int size, int sens, int mousex, int mousey ) {
  point2d M = new point2d( mousex, mousey );

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
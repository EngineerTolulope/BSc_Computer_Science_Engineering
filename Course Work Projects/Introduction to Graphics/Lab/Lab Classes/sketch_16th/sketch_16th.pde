
inhom2d P0, P1, P2, P3;
class inhom2d {
  float x, y;
 
  inhom2d(float x, float y ) {
  this.x = x;
  this.y = y;
  }
}
void setup( ) {
  size( 800, 600 );
  P0 = new inhom2d( 100, 400 );
  P1 = new inhom2d( 200, 210 );
  P2 = new inhom2d( 350, 200 );
  P3 = new inhom2d( 500, 400 );
}

void draw() {
  noFill( );
  stroke( 0 );
  strokeWeight(1);
  beginShape();
  vertex(P0.x, P0.y);
  vertex(P1.x, P1.y);
  vertex(P2.x, P2.y);
  vertex(P3.x, P3.y);
  endShape();
 
  stroke(255, 0, 0 );
  strokeWeight(10);
  beginShape(POINTS);
  vertex(P0.x, P0.y);
  vertex(P1.x, P1.y);
  vertex(P2.x, P2.y);
  vertex(P3.x, P3.y);
  endShape();
 
  strokeWeight(2);
  beginShape();
  for ( float t = 0; t <= 1; t += 0.01 ) {
  vertex( (1-t)*(1-t)*(1-t)*P0.x + 3*t*(1-t)*(1-t)*P1.x + 3*t*t*(1-t)*P2.x + t*t*t*P3.x,
          (1-t)*(1-t)*(1-t)*P0.y + 3*t*(1-t)*(1-t)*P1.y + 3*t*t*(1-t)*P2.y + t*t*t*P3.y);
  }
  endShape();
}
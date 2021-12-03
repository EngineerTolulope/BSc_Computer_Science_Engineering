void setup( ) {
 size(640,480);
}

void draw(){
  background(255,255,255);//Or background(255)
  stroke(255,0,0);
  line(0,480,640,0);
  line(0,240,640,240);
  stroke(0,255,0);
  line(320,0,320,480);
  line(0,0,640,480);
  ellipseMode(RADIUS);
  fill(255,0,255);
  noStroke();
  ellipse(160,120,120,120);
}
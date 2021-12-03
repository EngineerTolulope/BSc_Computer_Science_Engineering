void setup( ) {
 size(640,480);
}

void draw( ){
  line(50, 100, 600, 300);
  line(100, 100, 200, 200);
  //Now we try to draw and connect the diameter of the drawing board together
  line(0, 0, 640, 480);
  line(640,0, 0, 480);
  //Now we try to draw the mid points lines together
  line(320,0,320,480);
  line(0,240,640,240);
  //Now we want to draw an ellipse in the drawing board
  ellipse(320,240,640,480);//This is when the ellipsemode is center
}
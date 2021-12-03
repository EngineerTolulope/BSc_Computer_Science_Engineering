
float bx;
float by;
int boxSize = 75;
boolean overBox = false;
boolean buttonPressedOverTheBox = false;
float vx = 0.0;
float vy = 0.0;
void setup() {
  size(640, 360);
  bx = width/2.0;//we want to draw the shape at the center of the drawing board
  by = height/2.0;
  rectMode(RADIUS);
}
void draw() {
  background(0);
  // Test if the cursor is over the box
  if ( abs( mouseX - bx ) < boxSize && abs( mouseY - by ) < boxSize ) {
    //if condition to check if the mouse is over the box
    overBox = true;
  } else {
    overBox = false;
  }
  // Draw the box
  rect(bx, by, boxSize, boxSize);
}
void mousePressed() {
  if(overBox) {
    buttonPressedOverTheBox = true;
  }
  vx = bx - mouseX;
  vy = by - mouseY;
}
void mouseDragged() {
  if(buttonPressedOverTheBox) {
    bx = mouseX + vx;
    by = mouseY + vy ;
  }
}
void mouseReleased() {
  buttonPressedOverTheBox = false;
}
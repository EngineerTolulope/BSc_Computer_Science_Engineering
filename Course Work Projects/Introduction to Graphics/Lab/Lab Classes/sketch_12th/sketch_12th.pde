
float centerx;
float centery;
int radius = 50;
boolean overCircle = false;
boolean buttonPressedOverTheCircle = false;
float vx = 0.0;
float vy = 0.0;
void setup() {
  size(640, 360);
  centerx = width/2.0;
  centery = height/2.0;
  ellipseMode( RADIUS );
}
void draw() {
  background(0);
  // Test if the cursor is over the circle
  if (  ( mouseX - centerx ) * ( mouseX - centerx ) + ( mouseY - centery ) * ( mouseY - centery )  < radius * radius ) {
    overCircle = true;
  } else {
    overCircle = false;
  }
  // Draw the circle
  ellipse(centerx, centery, radius, radius );
}
void mousePressed() {
  if(overCircle) {
    buttonPressedOverTheCircle = true;
  }
  vx = centerx - mouseX;
  vy = centery - mouseY;
}
void mouseDragged() {
  if(buttonPressedOverTheCircle) {
    centerx = mouseX + vx;
    centery = mouseY + vy;
  }
}
void mouseReleased() {
  buttonPressedOverTheCircle = false;
}
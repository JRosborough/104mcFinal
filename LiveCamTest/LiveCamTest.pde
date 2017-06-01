import gab.opencv.*;
import processing.video.*;
import java.awt.*;

import processing.serial.*;
Serial port; //Creates object from Serial class



Capture video;
OpenCV opencv;



void setup() {
  size(640, 480);
  video = new Capture(this, 640/2, 480/2);
  opencv = new OpenCV(this, 640/2, 480/2);
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);  

  String portName = Serial.list()[2]; //Change the zero to match the port on the serial list
  println(portName);
  
  port = new Serial(this, portName, 9600);

delay(2000);
  video.start();
}

void draw() {
  scale(2);
  opencv.loadImage(video);

  image(video, 0, 0 );

  noFill();
  stroke(0, 255, 0);
  strokeWeight(3);
  Rectangle[] faces = opencv.detect();
  println(faces.length);

  for (int i = 0; i < faces.length; i++) {
    println(faces[i].x + "," + faces[i].y);
    rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
  }
  
  if (faces.length > 0) {
    port.write('1');
  }
  else {
    port.write('0');
  }

  
}

void captureEvent(Capture c) {
  c.read();
  

   
}
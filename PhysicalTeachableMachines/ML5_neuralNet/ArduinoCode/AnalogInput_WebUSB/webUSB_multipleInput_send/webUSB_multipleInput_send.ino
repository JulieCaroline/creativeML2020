#include <WebUSB.h>

/**
   Creating an instance of WebUSBSerial will add an additional USB interface to
   the device that is marked as vendor-specific (rather than USB CDC-ACM) and
   is therefore accessible to the browser.

   The URL here provides a hint to the browser about what page the user should
   navigate to to interact with the device.
*/
WebUSB WebUSBSerial(1 /* https:// */, "editor.p5js.org/jen_GSA/sketches/_UTpiD3sM");

#define Serial WebUSBSerial




void setup() {
  while (!Serial) {
    ;
  }
  Serial.begin(9600);
  Serial.write("Sketch begins.\r\n");
  Serial.flush();

}

void loop() {

  int x = analogRead(A1);
  int y = analogRead(A2);
  int z = analogRead(A3);
  String json;
  json = "{\"x\":";
  json = json + x;
  json = json + ";\"y\":";
  json = json + y;
  json = json + ";\"z\":";
  json = json + z;
  json = json + "}";

  Serial.println(json);
  Serial.flush();


}

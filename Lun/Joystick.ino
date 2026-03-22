#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

struct Data {
  bool up;
  bool down;
  bool left;
  bool right;
};

Data data;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);

  data.up    = (y > 700);
  data.down  = (y < 300);
  data.left  = (x < 300);
  data.right = (x > 700);

  radio.write(&data, sizeof(data));
}
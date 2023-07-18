#include <Arduino.h>

#if !defined(__SAMD21G18A__)
#error "This sketch is only for SAMD21G18A."
#endif

// on Xiao SAMD21, LOW = ON
const auto LED_ON = LOW;
const auto LED_OFF = HIGH;

void blink(uint8_t cnt = 3) {
  for (byte i = 0; i < cnt; i++) {
    if (i) {
      delay(100);
    }
    digitalWrite(LED_BUILTIN, LED_ON);
    delay(100);
    digitalWrite(LED_BUILTIN, LED_OFF);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);  // baud is arbitrary for USB Serial
  blink();
  delay(1000);
}

void loop() {

  uint32_t uid_buffer[4];

  uid_buffer[0] = *((volatile uint32_t *)0x0080A00C);
  uid_buffer[1] = *((volatile uint32_t *)0x0080A040);
  uid_buffer[2] = *((volatile uint32_t *)0x0080A044);
  uid_buffer[3] = *((volatile uint32_t *)0x0080A048);

  Serial.print("Unique ID: ");
  for (auto i = 0; i < sizeof(uid_buffer); i++) {
    byte b = *((byte *)uid_buffer + i);
    if (b < 0x10) {
      Serial.print("0");
    }
    Serial.print(b, HEX);
  }
  Serial.println();

  blink(1);

  delay(5000);
}

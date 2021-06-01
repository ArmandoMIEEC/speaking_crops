//Framework
#include <Arduino.h>

//Libraries
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SerialCommand.h>

//Sleep Timers
#define uS_TO_S_FACTOR 1000000
#define DEATH_TIME  3600

//LoRa Config
#define BAND 866E6  //868 MHz
#define LORA_DIO0 12 //868 MHz

//Oled Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//Objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST); // Display Object
SerialCommand sCmd; //Commands Object

//Functions Declaration
void die (void);
void cmd_unrecognized(const char* cmd);
void cmd_send(void);

void setup() {
  esp_sleep_enable_timer_wakeup(DEATH_TIME * uS_TO_S_FACTOR);

  //reset OLED display via software
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  //initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
    Serial.println("SSD1306 allocation failed! (ERROR000)");
    die();
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Base Station: ON\n");
  display.display();

  Serial.begin(115200);   //initialize Serial
  Serial.println("Base Station: ON\n");

  SPI.begin(SCK, MISO, MOSI, SS);                 //set SPI pins
  LoRa.setPins(LORA_NSS, LORA_RST, LORA_DIO0);     //set LoRa pins
  if (!LoRa.begin(BAND)) {
    Serial.println("LoRa failed! (ERROR001)");
    die();
  }

  Serial.println("LoRa Initializing OK!");
  display.setCursor(0,10);
  display.print("LoRa Initializing OK!\n");
  display.display();
  delay(2000);

  sCmd.addCommand("send", cmd_send);
  sCmd.setDefaultHandler(cmd_unrecognized);
}

void loop() {
  sCmd.readSerial();
}

void die(void){
  noInterrupts();
  Serial.flush();
  esp_deep_sleep_start();

  while (true){
    esp_deep_sleep_start();
  }
}

void cmd_send()
{
  Serial.println("Send command");
}

void cmd_unrecognized(const char *cmd)
{
  Serial.println("Unrecognized command [");
  Serial.println(cmd);
  Serial.println("]!\nUse command [list] to list all commands.");
}

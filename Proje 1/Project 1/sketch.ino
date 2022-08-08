#include <Arduino_FreeRTOS.h>

void setup() {
  Serial.begin(9600);
 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  xTaskCreate(BlinkRed, "BlinkRed", 100, NULL, 3, NULL);
  xTaskCreate(BlinkBlue, "BlinkBlue", 100, NULL, 2, NULL);
  xTaskCreate(BlinkGreen, "BlinkGreen", 100, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}

static void BlinkRed(void* pvParameters)
{
 while (true){
 digitalWrite(3, HIGH);
 vTaskDelay(100 / portTICK_PERIOD_MS);//100 ms
 digitalWrite(3, LOW);
 vTaskDelay(100 / portTICK_PERIOD_MS);
 Serial.println(F("Task1"));
 }
}
 
static void BlinkBlue(void* pvParameters)
{
 while (true) {
 digitalWrite(4, HIGH);
 vTaskDelay(1000 / portTICK_PERIOD_MS);//1000 ms
 digitalWrite(4, LOW);
 vTaskDelay(1000 / portTICK_PERIOD_MS);
 
 Serial.println(F("Task2"));
 }
}
 
static void BlinkGreen(void* pvParameters)
{
 while (true){
 digitalWrite(5, HIGH);
 vTaskDelay(2000 / portTICK_PERIOD_MS);//2000 ms
 digitalWrite(5, LOW);
 vTaskDelay(2000 / portTICK_PERIOD_MS);
 
 Serial.println(F("Task3"));
 }
}
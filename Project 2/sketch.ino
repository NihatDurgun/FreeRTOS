#include <Arduino_FreeRTOS.h>

bool inputStatus = false;
void setup() {
  Serial.begin(9600);
 
   pinMode(3, OUTPUT);
   pinMode(8, INPUT);
   xTaskCreate(OutputTask, "OutputTask", 100, NULL, 1, NULL);
   xTaskCreate(InputTask, "InputTask", 100, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}

static void OutputTask(void* pvParameters)
{
 while (true){
  if(inputStatus == 1){
   digitalWrite(3, HIGH);
   vTaskDelay(1000 / portTICK_PERIOD_MS);//100 ms
  }
   vTaskDelay(1000 / portTICK_PERIOD_MS);
   digitalWrite(3, LOW);
 }
}
 
static void InputTask(void* pvParameters)
{
 while (true) {
  if(digitalRead(8) == 1){
      inputStatus = true;
  }else{
    inputStatus = false;
  }
  vTaskDelay(1000 / portTICK_PERIOD_MS);
 }
}
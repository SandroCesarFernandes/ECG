#include <Arduino.h>
#include <SD.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

TaskHandle_t write_sd= NULL;
TaskHandle_t read_sd= NULL;

void write_sd(void *pvParameters);
void read_sd(void *pvParameters);

xTaskCreate(Task_write, "EscreverSD", 256, null, 3, &write_sd);
xTaskCreate(Task_write, "EscreverSD", 256, null, 4, &read_sd);

void setup()
{
  Serial.begin(9600);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
}

void loop()
{
  if ((digitalRead(34) == 1) || (digitalRead(35) == 1))
  {
    Serial.println('!');
  }
  else
  {
    
    int val = analogRead(A0);
    val = map(val, 0, 1900, 0, 128);
    Serial.println(val);
  }
  
  delay(20);
}

void write_sd(void *pvParameters)
{

}

void read_sd(void *pvParameters)
{


}


//*========AHT传感器库调用=======*/
#include <Thinary_AHT10.h>
AHT10Class AHT10;
//*========1602I2C库调用=======*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);        //设置LCD地址,显示模式
//*======通用I2C驱动库调用======*/
#include <Wire.h>
//*========BMP180气压计库调用=====*/
#include <SFE_BMP180.h>
SFE_BMP180 pressure;
void setup() {
  // put your setup code here, to run once:
Wire.begin();                            //初始化I2C
lcd.init();                              //初始化LCD
lcd.backlight();                         //打开背光
pressure.begin();                        //初始化BMP180
AHT10.begin();                           //初始化AHT10

  }
void loop() {
  // put your main code here, to run repeatedly:
double P,T;
//pressure.startTemperature();
//pressure.getTemperature(T);                  //测量温度
pressure.startPressure(3);
pressure.getPressure(P,T);                   //测量气压
lcd.setCursor(0,0);                          //移动光标
lcd.print("T");                              //显示T
lcd.print(AHT10.GetTemperature());                                //显示温度
lcd.print("C");                              //显示单位
lcd.setCursor(8,0);                          //移动光标
lcd.print("RH");                             //显示RH
lcd.print(AHT10.GetHumidity());              //显示湿度
lcd.print("%");                              //显示单位
lcd.setCursor(0,1);                          //移动光标
lcd.print("P:");                             //显示P
lcd.print(P,2);                              //显示气压
lcd.setCursor(13,1);                         //移动光标
lcd.print("hPa");                            //显示单位
delay(5000);                                 //5秒一循环
}

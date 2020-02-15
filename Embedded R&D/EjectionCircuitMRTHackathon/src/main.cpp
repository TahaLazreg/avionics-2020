#include <stdio.h>
#include "mbed.h"
#include "BMP180.h"

I2C i2c(I2C_SDA, I2C_SCL);
BMP180 bmp180(&i2c);
DigitalOut myled(PB_4);

int main(void) {

    while(1) {
        if (bmp180.init() != 0) {
            printf("Error communicating with BMP180\n");
            for(int i =0; i<10; i++){
              myled = 1;
              wait_ms(50);
              myled = 0;
              wait_ms(50);
            }
        } else {
            printf("Initialized BMP180\n");
            break;
        }
        wait(1);
    }

   
        bmp180.startTemperature();
        wait_ms(5);     // Wait for conversion to complete
        float temp;
        if(bmp180.getTemperature(&temp) != 0) {
            printf("Error getting temperature\n");
            
        }

        bmp180.startPressure(BMP180::ULTRA_LOW_POWER);
        wait_ms(10);    // Wait for conversion to complete
        int pressure;
        if(bmp180.getPressure(&pressure) != 0) {
            printf("Error getting pressure\n");
            
            
        }

        printf("Pressure = %d Pa Temperature = %f C\n", pressure, temp);

        int prevP = pressure;
        for (int i=0; i<30; i++){
            bmp180.getPressure(&pressure);
            if(pressure-prevP > 1){
                i = 0;
            }
            prevP = pressure;
            wait_ms(500);
        }
         while(1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
    }
}
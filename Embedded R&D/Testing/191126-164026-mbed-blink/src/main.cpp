#include "mbed.h"
#include "pitches.h"
#include <iostream>

/******************* Tune Function for Piezo Buzzer ********************/
/**
   * @brief     Tune Function
   * @param  name : Choose the PwmOut
                    period : this param is tune value. (C_3...B_5)
                    beat : this param is beat value. (1..16) 1 means 1/16 beat
   * @retval    None
   */
void Tune(PwmOut name, int period, int beat)
{  
    int delay;
    
    delay = beat*63;
    name.period_us(period);
    name.write(0.50f); // 50% duty cycle
    wait_ms(delay); // 1 beat
    name.period_us(0); // Sound off
}
 
/**
   * @brief     Auto tunes Function
   * @param  name : Choose the PwmOut
                    period : this param is tune value. (C_3...B_5)
                    beat : this param is beat value. (1..16) 1 means 1/16 beat
   * @retval    None
   */
void Auto_tunes(PwmOut name, int period, int beat)
{    
    int delay;
    delay = beat*63;
    name.period_us(period);
    name.write(0.50f); // 50% duty cycle
    wait_ms(delay);
}
 
/**
   * @brief     Stop tunes Function
   * @param  name : Choose the PwmOut
   * @retval    None
   */
void Stop_tunes(PwmOut name)
{
    name.period_us(0.01);
}

void MRT_Stop(PwmOut name)
{
    name.write(0);
}

void MRT_Tune(PwmOut name, int period, int beat)
{
   int delay = beat * 63;
   name.period_ms(period);
   name.write(0.5f);
   wait(delay / 100);
}
/****************************** End of Functions *******************************/

PwmOut BuzzerPin(PB_4);
DigitalOut ButtonState(LED2);
DigitalIn ButtonPressed(USER_BUTTON);

//Hot cross buns
int melody[] = {E_5, D_5, C_5, E_5, D_5, C_5, C_5, C_5, C_5, C_5, D_5, D_5, D_5, D_5, E_5, D_5, C_5};

int noteDuration[] = {4, 4, 8, 4, 4, 8, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 8};

int main() 
{   
    BuzzerPin.period_ms(1517.45);
    BuzzerPin.write(0.5f);
    wait(4*63/100);

    BuzzerPin.period_ms(1703.58);
    BuzzerPin.write(0.5f);
    wait(4*63/100);

    BuzzerPin.period_ms(C_5);
    BuzzerPin.write(0.5f);
    wait(8*63/100);

    BuzzerPin = 0;
}
#include "leg_info.h"
#include "control_parameters.h"
#include "desired_values.h"
#include "conversions.h"
#include "pd_control.h"
#include "gait_parameters.h"

// Dynamixel ayarlar //
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(DXL_BUS_SERIAL1);

// kontrol tablosu //
#define MOVING_SPEED 32
#define PRESENT_POS 37
#define PRESENT_SPEED 39
#define PRESENT_VOLTAGE 45
#define LED 25

//Rewritable globals
float desired_vel;
float desired_theta;
float actual_vel;
float actual_theta;
float control_signal;
float actual_p;


int dead_buffer = 40;

const int legs_active = 6;

const int packet_length =  2 * legs_active;
word packet[packet_length]; 

void setup(){
  Dxl.begin(3); 
  Serial2.begin(57600); 
  pinMode(BOARD_BUTTON_PIN, INPUT_PULLDOWN); 
  pinMode(BOARD_LED_PIN, OUTPUT); 
  int t_start = millis();
  for (int i = 1; i <= legs_active; i++){ 
    Dxl.wheelMode(legs[i].id); 
    update_gait(i, initial_gait, t_start); 
  }
}

void dur(){

    int t_start=millis();
    int gait=0;
    for(int i = 1; i <= legs_active; i++){
    update_gait(i, gait, t_start);}  

}
void ileri(){

    int t_start=millis();
    int gait=1;
    for(int i = 1; i <= legs_active; i++){
    update_gait(i, gait, t_start);}  

}
void sol(){

    int t_start=millis();
    int gait=2;
    for(int i = 1; i <= legs_active; i++){
    update_gait(i, gait, t_start);}  

}

void geri(){

    int t_start=millis();
    int gait=3;
    for(int i = 1; i <= legs_active; i++){
    update_gait(i, gait, t_start);}  

}
void sag(){

    int t_start=millis();
    int gait=4;
    for(int i = 1; i <= legs_active; i++){
    update_gait(i, gait, t_start);}  

}
void pronk(){

    int t_start=millis();
    int gait=5;
    for(int i = 1; i <= legs_active; i++){
    update_gait(i, gait, t_start);}  

}

void loop(){
  
if(millis()>2000 && millis()<2100){//2.saniyede ileri fonksiyonu çalıştır. 
ileri();
}
if(millis()>5000 && millis()<5100){ //5.saniyede dur fonksiyonunu çalıştır.
dur();
}
if(millis()>5500 && millis()<5600){//5,5.saniyede dur fonksiyonunu çalıştır. 
sag();
}
if(millis()>8000 && millis()<8100){//8.saniyede dur fonksiyonunu çalıştır. 
dur();
}
  
  for(int i = 1; i <= legs_active; i++){
    packet[(i-1) * 2] = legs[i].id;
    actual_p = Dxl.readWord(legs[i].id, PRESENT_POS);
    actual_theta = P_to_Theta(actual_p); 
    actual_vel = dynV_to_V(Dxl.readWord(legs[i].id, PRESENT_SPEED)); 
    if (!legs[i].deadzone){
      
      if (actual_p == 0 || actual_p == 1023){ 
        legs[i].deadzone = true;
        if (actual_p == 0) legs[i].dead_from_neg = true;
        else legs[i].dead_from_neg = false;
        continue;
      }

      if (legs[i].gait == STAND){ 
        if (legs[i].right_side){
          desired_theta = Theta_to_ThetaR(legs[i].desired_theta);
        }
        else{
          desired_theta = legs[i].desired_theta;
        }
        actual_theta = actual_theta - legs[i].zero; 
        control_signal = pd_controller(actual_theta, desired_theta, actual_vel, 0, kp_hold, kd_hold); 
      }
      else { 
        
        vals v = get_desired_vals(millis(), legs[i]);
        
        if (legs[i].right_side){
          desired_vel = -v.global_velocity; 
          desired_theta = Theta_to_ThetaR(v.global_theta); 
        }
        else{ 
          desired_vel = v.global_velocity;
          desired_theta = v.global_theta;
        }
        actual_theta = actual_theta - legs[i].zero;
        
        control_signal = pd_controller(actual_theta, desired_theta, actual_vel, desired_vel, legs[i].kp, legs[i].kd);  
      }


      int new_vel = V_to_dynV(actual_vel + control_signal);
      packet[(i-1) * 2 + 1] = new_vel;
    }

    else{ 
      if ((actual_p > 0) & (actual_p < dead_buffer) || (actual_p < 1023) & (actual_p > 1023 -dead_buffer)){ 
        legs[i].deadzone = false;
      }
      float signed_recovery_speed = legs[i].dead_from_neg == true ? -legs[i].recovery_speed : legs[i].recovery_speed;
      packet[(i-1) * 2 + 1] = V_to_dynV(signed_recovery_speed);
    }
  }

  Dxl.syncWrite(MOVING_SPEED, 1, packet, packet_length); 
}




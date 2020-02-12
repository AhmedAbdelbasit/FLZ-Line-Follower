#ifndef DC_MOTOR_DRIVER_H
#define DC_MOTOR_DRIVER_H

#define LS 2
#define RS 3
#define LM1 4
#define LM2 5
#define RM1 6
#define RM2 7

void setup_dc_motors();
void moveForward (int SPEED , int forwadDistanse, int DEALY);
void STOP ( int stopDistanse);
void moveRight( int turnSpeed , int turnDistanse , int DELAY) ;
void moveLeft( int turnSpeed , int turnDistanse , int DELAY);

#endif

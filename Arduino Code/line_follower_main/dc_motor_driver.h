#ifndef DC_MOTOR_DRIVER_H
#define DC_MOTOR_DRIVER_H

#define LEFT_SPEED 9
#define RIGHT_SPEED 11
#define LM1 4
#define LM2 5
#define RM1 6
#define RM2 7

void setupDCMotors();
void setRobotSpeed(int s);
void setSpeed(int leftSpeed, int rightSpeed);
void setLeftDirection(boolean d);
void setRightDirection(boolean d);
void moveForward ();
void moveBackward();
void stopRobot ();
void moveRight() ;
void moveLeft();
void setLeftSpeed(float output);
void setRightSpeed(float output);

#endif

#ifndef DC_MOTOR_DRIVER_H
#define DC_MOTOR_DRIVER_H

#define LEFT_SPEED 5
#define RIGHT_SPEED 6
#define LM1 3
#define LM2 2
#define RM1 4
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

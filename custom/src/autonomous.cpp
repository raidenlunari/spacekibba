#include "vex.h"
#include "utils.h"
#include "pid.h"
#include <ctime>
#include <cmath>
#include <thread>

#include "../include/autonomous.h"
#include "motor-control.h"
#include "../custom/include/intake.h"

// IMPORTANT: Remember to add respective function declarations to custom/include/autonomous.h
// Call these functions from custom/include/user.cpp
// Format: returnType functionName() { code }
//s

void awp(){
min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
 matchloader.set(true);
 
 //matchload 1
 moveToPoint(0,17.5, 1, 2000, true, 10);
 turnToAngle(90, 1000, true, 7);
 moveToPoint(23,29,1, 1000,true,6);
 vex::wait(250,msec);
 moveToPoint(-8,28.5,-1,2000,true,8);
 scoreLongGoal();
 matchloader.set(false);
 moveToPoint(-20,28.5,-1,400,true,6);
 vex::wait(600,msec);
 resetOdom(-11,30);
 resetAngle(90);

 //stack 1
 /*vex::task matchloadDeploy([]{
    vex::wait(1500, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadRetract([]{
    vex::wait(1750, msec);
    matchloader.set(false);
    return 0;
  }); */
 storeIntake();
 swing(235,1,2000,true,12);
 moveToPoint(-17.5,2.5,1,3000,true,3);
 turnToAngle(-180,2000, true, 6);
 
 
 //stack 2
 vex::task matchloadDeploy1([]{
    vex::wait(800, msec);
    matchloader.set(true);
    return 0;
  });
vex::task matchloadRetract1([]{
    vex::wait(1000, msec);
    matchloader.set(false);
    return 0;
  });
moveToPoint(-13,-28,1,2000,true,7);
moveToPoint(-13,-34,1,3000,true,3);

//middle
turnToAngle(135,2000,true,6);
outtake();
vex::wait(25,msec);
stopIntake();
driveTo(-1,200,true,6);
vex::task midgoaldown([]{
  vex::wait(550, msec);
  middleGoal.set(true);
  return 0;
 });
vex::wait(50, msec);
scoreMiddleGoal();
moveToPoint(-20.5,-29,-1, 1500, true, 6);
driveTo(-10,2000,true,3);
vex::wait(350,msec);
outtake();
vex::task matchloadDeploy2([]{
  vex::wait(850, msec);
  matchloader.set(true);
  return 0;
 });
vex::wait(50,msec);
stopIntake();
vex::task midgoalup([]{
  vex::wait(200, msec);
  middleGoal.set(false);
  return 0;
 }); 
storeIntake();

//matchload 2
moveToPoint(5,-50.5,1, 1500, true, 7);
turnToAngle(90,1000,true,7);
moveToPoint(23,-50.5,1, 600, true, 6);
vex::wait(400,msec);
moveToPoint(-12,-50.5, -1, 1500, true, 8);
moveToPoint(-18,-50.5 ,-1, 300, false, 6);
scoreLongGoal();
driveTo(-10,2000,true,6);
vex::wait(20000,msec);

}

void rightwing4(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
  correct_angle = 45;
  vex::task matchloadDeploy([]{
    vex::wait(450, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadDeploy1([]{
    vex::wait(1500, msec);
    matchloader.set(false);
    return 0;
  });
  moveToPoint(6, 30, 1, 2000, true, 8);
  moveToPoint(14, 16, -1, 1000, true, 8);
  moveToPoint(27, 4, -1, 1000, true, 8);
  turnToAngle(180, 2000, true, 8);
  moveToPoint(37, 28, -1, 800, true, 8);
  scoreLongGoal();
  matchloader.set(false);
  task::sleep(1000);
  storeIntake();
  driveTo(3,1000,true,8);
  turnToAngle(240,1200,true,8);
  leftWing.set(false);
  driveTo(-8,1500,true,8);
  turnToAngle(-180,2000,true,8);
  driveTo(-10,2000,false,6);
  turnToAngle(230,2000,true,6);
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);
  stopChassis(brakeType::hold);

}

void rightwing4matchload(){
min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
 matchloader.set(true);
 //matchload 1
 moveToPoint(0,18.5, 1, 2000, true, 10);
 turnToAngle(90, 1000, true, 8);
 moveToPoint(23,30,1, 1000,true,5);
 vex::wait(150,msec);
 moveToPoint(-8,29,-1,2000,true,8);
 matchloader.set(false);
 scoreLongGoal();
 moveToPoint(-20,29,-1,600,true,6);
 matchloader.set(false);
 task::sleep(700);
 storeIntake();
 //wing
 resetAngle(90);

  driveTo(5,600,true,8);
  turnToAngle(120,1200,true,8);
  leftWing.set(false);
  driveTo(-18,1500,true,8);
  turnToAngle(80,2000,true8);
  driveTo(-10,2000,false,6,);
  turnToAngle(120,2000,true,6);
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);
  stopChassis(brakeType::hold);


 
}

void rightwing7(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
  correct_angle = 45;
  vex::task matchloadDeploy([]{
    vex::wait(450, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadDeploy1([]{
    vex::wait(1500, msec);
    return 0;
  });
  moveToPoint(6, 30, 1, 2000, true, 8);
  moveToPoint(14, 16, -1, 800, true, 8);
  moveToPoint(24, 4, -1, 800, true, 8);
  turnToAngle(180, 1000, true, 8);
  moveToPoint(34, 3, 1, 800, true, 8);
  moveToPoint(34, -15, 1, 1200, true, 6);
  vex::wait(150,msec);
  moveToPoint(36, 10, -1, 2000, true, 8);
  scoreLongGoal();
  moveToPoint(36, 20, -1, 600, true, 6);
  matchloader.set(false);
  task::sleep(900);
  storeIntake();
  driveTo(5,600,true,8);
  turnToAngle(210,1200,true,8);
  leftWing.set(false);
  driveTo(-15,1500,true,8);
  turnToAngle(-190,2000,true,8);
  driveTo(-10,2000,false,6);
  turnToAngle(230,2000,true,6);
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);
  stopChassis(brakeType::hold);

}
void leftmidseven(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(550, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadDeploy1([]{
    vex::wait(2000, msec);
    matchloader.set(false);
    return 0;
  });
  moveToPoint(-6.5, 33, 1, 2000, true, 8);
  matchloader.set(false);
  turnToAngle(-50,2000,true,6);
  moveToPoint(2,31,-1,2000,true,5);
  turnToAngle(-135, 2000,true,6);
  moveToPoint(9.5,36.5,-1,2000,true,5);
  middleGoal.set(true);
  vex::task middlegoalup([]{
    vex::wait(1800, msec);
    middleGoal.set(false);
    return 0;
  });
  scoreMiddleGoal();
  task::sleep(1800);
  moveToPoint(-19, 6, 1, 2000, true, 6);
  storeIntake();
  matchloader.set(true);
  turnToAngle(180,1800,true,4);
  moveToPoint(-20, -14, 1, 1400, true, 4);
  vex::wait(100,msec);
  moveToPoint(-21,28,-1,1500,false,7);
  scoreLongGoal();
  vex::wait(20000, msec);

}

void leftwingauto(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(450, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadDeploy1([]{
    vex::wait(900, msec);
    matchloader.set(false);
    return 0;
  });
  moveToPoint(-7, 33, 1, 2000, true, 8);
  turnToAngle(-30,400,true,8);
  moveToPoint(-19, 20, -1, 1000, true, 8);
  moveToPoint(-27.5, 15, -1, 1000, true, 8);
  turnToAngle(-180, 600, true, 8);
  moveToPoint(-21, 28, -1, 6000, true, 8);
  scoreLongGoal();
  task::sleep(1200);
  storeIntake();
  driveTo(4,800,true,7);
  turnToAngle(-125,800,true,8);
  leftWing.set(false);
  driveTo(-13,2000,true,8);
  turnToAngle(165,2000,true,8);
  driveTo(-13,3000,false,8);
  vex::wait(100,msec);
  turnToAngle(-150,2000,true,8);
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);

}

void rightlowquals(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  moveToPoint(0,-33,-1,2000,true,6);
  swing(-45,-1,600,true,8);
  vex::wait(300,msec);
  middleGoal.set(true);
  scoreMiddleGoal();
  vex::wait(900,msec);
    vex::task matchloadDeploy([]{
    vex::wait(550, msec);
    matchloader.set(true);
    return 0;
  });
  storeIntake();
  middleGoal.set(false);
  moveToPoint(-14,-25,1,2000,false,8);
  moveToPoint(-25,-14,1,4000,true,6);
  turnToAngle(-0,2000,true,6);
  driveChassis(6,6);
  vex::wait(900,msec);
  driveChassis(2,2);
  vex::wait(500,msec);
  driveToHeading(-36, 3, 1200, true, 7);
  driveChassis(-5,-5);
  scoreLongGoal();
  task::sleep(1000);
  storeIntake();
  matchloader.set(false);
  curveCircle(-40, 8, 3000, false, 10);
  driveTo(2, 500, true, 10);
  turnToAngle(0, 3000, true, 10);
  driveTo(-30, 3000, true, 5.5);
  stopChassis(hold);

  /*
  driveTo(3,1000,true,8);
  turnToAngle(240,1200,true,8);
  leftWing.set(false);
  driveTo(-8,1500,true,8);
  turnToAngle(-180,2000,true,8);
  driveTo(-10,2000,false,6);
  turnToAngle(230,2000,true,6);
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);
  stopChassis(brakeType::hold);
  */
}

void leftmidelims(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  
  moveToPoint(0,-33,-1,2000,true,6);
  swing(-45,-1,1000,true,6);
  vex::wait(300,msec);
  middleGoal.set(true);
  scoreMiddleGoal();
  vex::wait(900,msec);
    vex::task matchloadDeploy([]{
    vex::wait(550, msec);
    matchloader.set(true);
    return 0;
  });
  storeIntake();
  middleGoal.set(true);
  leftWing.set(true);
  moveToPoint(-14,-25,1,2000,true,5);
  moveToPoint(-27,-14,1,4000,true,5);
  turnToAngle(-0,2000,true,5);
  vex::wait(100,msec);
  moveToPoint(-31.5,12,1,1200,true,4);
  vex::wait(350,msec);
  moveToPoint(-33,-28,-1,1500,true,6);
  scoreLongGoal();
  vex::wait(1500,msec);
  matchloader.set(false);
vex::wait(100000,msec);
driveTo(1,2000,true,1);


}

void left54(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(500, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(-5.5, 26, 1, 2000, true, 8);
  matchloader.set(false);
  vex::task matchloadDeploy1([]{
    vex::wait(1200, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadretract([]{
    vex::wait(1400, msec);
    matchloader.set(false);
    return 0;
  });
  moveToPoint(-20,34.5,1,1000,true,4);
  driveTo(5,2000,true,4);
  vex::wait(3000,msec);
  moveToPoint(-3,25,-1,2000,true,7);
  turnToAngle(225,2000,true,7);
  driveTo(-12,2000,true,7);
  outtake();
  vex::wait(150, msec);
  stopIntake();
  middleGoal.set(true);
  scoreMiddleGoal();
  driveTo(1,200,true,2);
  vex::wait(1500,msec);
  moveToPoint(-20,5,1,2000,true,7);
  middleGoal.set(false);
  vex::task matchloadDeploy2([]{
    vex::wait(300, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadDeploy3([]{
    vex::wait(3000, msec);
    matchloader.set(false);
    return 0;
  });
  turnToAngle(-180,2000,true,7);
  moveToPoint(-22,-10,1,800,true,5);
  vex::wait(300,msec);
  moveToPoint(-20,15,-1,2000,true,8);
  moveToPoint(-120,118,-1,2000,true,6);
  scoreLongGoal();
  vex::wait(600,msec);
  driveTo(4,800,true,7);
  turnToAngle(-125,800,true,8);
  leftWing.set(false);
  driveTo(-13,2000,true,8);
  turnToAngle(165,2000,true,8);
  driveTo(-13,3000,false,8);
  vex::wait(100,msec);
  turnToAngle(-150,2000,true,8);
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);


}

void skills(){
min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
 matchloader.set(true);
 //matchload 1 
 moveToPoint(0,22, 1, 2000, true, 6);
 turnToAngle(90, 1000, true, 7);
 moveToPoint(23,31,1, 1000,true,4);
 vex::wait(800,msec);
 driveTo(1,200,false,4);
 driveTo(-1,200,false,4);
 driveTo(1,00,false,4);
 vex::wait(1000,msec);
 //alley 1
 moveToPoint(8,32,-1,2000,true,6);
 turnToAngle(135,2000,true,6);
 moveToPoint(-2,42,-1,2000,true,6);
 turnToAngle(90,2000,true,6);
 moveToPoint(-70,42,-1,2000,true,6);
 stopIntake();
 matchloader.set(false);
 turnToAngle(45,2000,true,6);
 moveToPoint(-76,32,-1,2000,true,6);
 moveToPoint(-80,22,-1,2000,true,6);
 turnToAngle(270,2000,true,6);
 driveTo(-20,2000,true,6);
 scoreLongGoal();
 driveChassis(-5,-5);
 resetOdom(-70,22);
 resetAngle(270);
 //matchload 2
 matchloader.set(true);
 vex::wait(3000,msec);
 storeIntake();
 moveToPoint(-80,22,1,2000,true,7);
 moveToPoint(-105,22,1,2000,true,4);
 vex::wait(800,msec);
 driveTo(1,200,false,4);
 driveTo(-1,200,false,4);
 driveTo(1,00,false,4);
 vex::wait(1000,msec);
 moveToPoint(-80,22,-1,2000,true,7);
 moveToPoint(-70,22,-1,2000,true,5);
 scoreLongGoal();
 driveChassis(-5,-5);
 vex::wait(2000,msec);
 resetOdom(-70,22);
 resetAngle(270);
 //cross field 
 driveTo(10,2000,true,6);
 turnToAngle(180,2000,true,6);
 driveTo(-20,2000,true,5);
 moveToPoint(-77,-70,1,8000,true,7);
 turnToAngle(270,2000,true,6);
 /* 
 
 //matchload 3
 moveToPoint(-80,_,1,2000,true,7);
 moveToPoint(-105,_,1,2000,true,4);
 vex::wait(800,msec);
 driveTo(1,200,false,4);
 driveTo(-1,200,false,4);
 driveTo(1,00,false,4);
 vex::wait(1000,msec);
 moveToPoint(-80,_,-1,2000,true,7);
 moveToPoint(-70,_,-1,2000,true,5);
 scoreLongGoal();
 driveChassis(-5,-5);
 vex::wait(2000,msec);
 resetOdom(-70,_);
 resetAngle(270);
 
 //alley 2
 moveToPoint(-80,_,1,2000,true,7);
 turnToAngle(315,2000,true,6);
 moveToPoint(-75,_,1,2000,true,7);
 turnToAngle(270,2000,true,6);
 moveToPoint(0,_,1,2000,true,7);
 stopIntake();
 matchloader.set(false);
 turnToAngle(225,2000,true,6);
 moveToPoint(6,32,-1,2000,true,6);
 moveToPoint(10,22,-1,2000,true,6);
 turnToAngle(90,2000,true,6);
 moveToPoint(10,_,1,2000,true,7);
 scoreLongGoal();
 driveChassis(-5,-5);
 vex::wait(2000,msec);
 resetOdom(10,_);
 resetAngle(90);

 //matchload 4
 moveToPoint(20,_,1,2000,true,7);
 moveToPoint(30,_,1,2000,true,4);
 vex::wait(800,msec);
 driveTo(1,200,false,4);
 driveTo(-1,200,false,4);
 driveTo(1,00,false,4);
 vex::wait(1000,msec);
 moveToPoint(20,_,-1,2000,true,7);
 moveToPoint(10,_,-1,2000,true,5);
 scoreLongGoal();
 driveChassis(-5,-5);
 vex::wait(2000,msec);
 resetOdom(10,_);
 resetAngle(90));

 //go to park
 moveToPoint(10,_,1,2000,true,7);
 turnToAngle(75,2000,2000,6);
 moveToPoint(10,_,1,2000,true,7);
 matchloader.set(true);
 driveChassis(10,10);
 vex::wait(1500,msec);
 stopChassis();
 matchloader.set(false);
 
 
 */
 vex::wait(200000,msec);

}


void awp2(){
min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
 matchloader.set(true);
 
 //matchload 1
 moveToPoint(0,18.5, 1, 2000, true, 10);
 turnToAngle(90, 1000, true, 7);
 moveToPoint(23,30,1, 1000,true,5);
 vex::wait(200,msec);
 moveToPoint(-8,30,-1,2000,true,8);
 matchloader.set(false);
 moveToPoint(-20,30,-1,600,true,6);
 scoreLongGoal();
 driveChassis(-8,-8);
 vex::wait(500,msec);
 driveChassis(0,0);
 resetOdom(-11,30);
 resetAngle(90);

 //stack 1
 vex::task matchloadDeploy([]{
    vex::wait(1500, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadRetract([]{
    vex::wait(1750, msec);
    matchloader.set(false);
    return 0;
  });
 storeIntake();
 swing(235,1,2000,true,12);
 moveToPoint(-16,-0.5,1,3000,true,3);
 turnToAngle(-180,2000, true, 6);
 
 
 //stack 2
 vex::task matchloadDeploy1([]{
    vex::wait(700, msec);
    matchloader.set(true);
    return 0;
  });
moveToPoint(-14.5,-30,1,2000,true,8);
moveToPoint(-14.5,-35,1,3000,true,3);

//middle
turnToAngle(135,2000,true,6);
outtake();
vex::wait(50,msec);
storeIntake();
driveTo(-1,200,true,6);
vex::task midgoaldown([]{
  vex::wait(600, msec);
  middleGoal.set(true);
  return 0;
 });
outtake();
vex::wait(50, msec);
scoreMiddleGoal();
moveToPoint(-22.5,-32.5,-1, 1500, true, 6);
driveTo(-10,2000,true,3);
vex::wait(200,msec);
stopIntake();
vex::task matchloadDeploy2([]{
  vex::wait(600, msec);
  matchloader.set(true);
  return 0;
 });
vex::wait(50,msec);
vex::task midgoalup([]{
  vex::wait(100, msec);
  middleGoal.set(false);
  return 0;
 }); 
storeIntake();
//matchload 2
moveToPoint(7,-53,1, 1500, true, 7);
turnToAngle(90,1000,true,7);
moveToPoint(23,-53,1, 1500, true, 6);
vex::wait(350,msec);
moveToPoint(-12,-53, -1, 1500, true, 8);
moveToPoint(-18,-53 ,-1, 300, false, 6);
scoreLongGoal();
vex::wait(100000,msec);
driveTo(1,2000,true,1);

}

void awp3(){
min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
 matchloader.set(true);
 
 //matchload 1
 moveToPoint(0,18.5, 1, 2000, true, 10);
 turnToAngle(90, 1000, true, 7);
 moveToPoint(23,30,1, 1000,true,5);
 vex::wait(200,msec);
 moveToPoint(-8,30,-1,2000,true,8);
 matchloader.set(false);
 moveToPoint(-20,30,-1,600,true,6);
 scoreLongGoal();
 driveChassis(-8,-8);
 vex::wait(500,msec);
 driveChassis(0,0);
 resetOdom(-11,30);
 resetAngle(90);

 //stack 1
 vex::task matchloadDeploy([]{
    vex::wait(1500, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadRetract([]{
    vex::wait(1750, msec);
    matchloader.set(false);
    return 0;
  });
 storeIntake();
 swing(235,1,2000,true,12);
 moveToPoint(-16,-0.5,1,3000,true,3);
 turnToAngle(-180,2000, true, 6);
 
 
 //stack 2
 vex::task matchloadDeploy1([]{
    vex::wait(700, msec);
    matchloader.set(true);
    return 0;
  });
moveToPoint(-14.5,-30,1,2000,true,8);
moveToPoint(-14.5,-35,1,3000,true,3);

//middle
turnToAngle(135,2000,true,6);
outtake();
vex::wait(50,msec);
storeIntake();
driveTo(-1,200,true,6);
vex::task midgoaldown([]{
  vex::wait(600, msec);
  middleGoal.set(true);
  return 0;
 });
outtake();
vex::wait(50, msec);
scoreMiddleGoal();
moveToPoint(-22.5,-32.5,-1, 1500, true, 6);
driveTo(-10,2000,true,3);
vex::wait(200,msec);
stopIntake();
vex::task matchloadDeploy2([]{
  vex::wait(600, msec);
  matchloader.set(true);
  return 0;
 });
vex::wait(50,msec);
vex::task midgoalup([]{
  vex::wait(100, msec);
  middleGoal.set(false);
  return 0;
 }); 
storeIntake();
//matchload 2
moveToPoint(7,-53,1, 1500, true, 7);
turnToAngle(90,1000,true,7);
moveToPoint(23,-53,1, 1500, true, 6);
vex::wait(350,msec);
moveToPoint(-12,-53, -1, 1500, true, 8);
moveToPoint(-18,-53 ,-1, 300, false, 6);
scoreLongGoal();
vex::wait(100000,msec);
driveTo(1,2000,true,1);

}

void awp4(){
min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  outtake();
  middleGoal.set(false);
  leftWing.set(true);
  storeIntake();
 matchloader.set(true);
 
 //matchload 1
 moveToPoint(0,18.5, 1, 2000, true, 10);
 turnToAngle(90, 1000, true, 7);
 moveToPoint(23,30,1, 1000,true,5);
 vex::wait(200,msec);
 moveToPoint(-8,30,-1,2000,true,8);
 matchloader.set(false);
 moveToPoint(-20,30,-1,600,true,6);
 scoreLongGoal();
 driveChassis(-8,-8);
 vex::wait(500,msec);
 driveChassis(0,0);
 resetOdom(-11,30);
 resetAngle(90);

 //stack 1
 vex::task matchloadDeploy([]{
    vex::wait(1500, msec);
    matchloader.set(true);
    return 0;
  });
  vex::task matchloadRetract([]{
    vex::wait(1750, msec);
    matchloader.set(false);
    return 0;
  });
 storeIntake();
 swing(235,1,2000,true,12);
 moveToPoint(-16,-0.5,1,3000,true,3);
 turnToAngle(-180,2000, true, 6);
 
 
 //stack 2
 vex::task matchloadDeploy1([]{
    vex::wait(700, msec);
    matchloader.set(true);
    return 0;
  });
moveToPoint(-14.5,-30,1,2000,true,8);
moveToPoint(-14.5,-35,1,3000,true,3);

//middle
turnToAngle(135,2000,true,6);
outtake();
vex::wait(50,msec);
storeIntake();
driveTo(-1,200,true,6);
vex::task midgoaldown([]{
  vex::wait(600, msec);
  middleGoal.set(true);
  return 0;
 });
outtake();
vex::wait(50, msec);
scoreMiddleGoal();
moveToPoint(-22.5,-32.5,-1, 1500, true, 6);
driveTo(-10,2000,true,3);
vex::wait(200,msec);
stopIntake();
vex::task matchloadDeploy2([]{
  vex::wait(600, msec);
  matchloader.set(true);
  return 0;
 });
vex::wait(50,msec);
vex::task midgoalup([]{
  vex::wait(100, msec);
  middleGoal.set(false);
  return 0;
 }); 
storeIntake();
//matchload 2
moveToPoint(7,-53,1, 1500, true, 7);
turnToAngle(90,1000,true,7);
moveToPoint(23,-53,1, 1500, true, 6);
vex::wait(350,msec);
moveToPoint(-12,-53, -1, 1500, true, 8);
moveToPoint(-18,-53 ,-1, 300, false, 6);
scoreLongGoal();
vex::wait(100000,msec);
driveTo(1,2000,true,1);

}


void left9Long(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(850, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(-10.5, 24, 1, 2000, false, 5);
  matchloader.set(false);
  vex::task matchloadDeploy2([]{
    vex::wait(950, msec);
    // matchloader.set(true);
    return 0;
  });
  boomerang(-31, 32, 1, -39, 0.1, 3000, true, 6);
  vex::wait(80, msec);
  heading_correction_kp = 0.3;
  moveToPoint(-23, 10, -1, 3000, false, 8);
  stopIntake();
  moveToPoint(-38, 8, -1,  3000, true, 8);
  turnToAngle(180, 1000, true, 7);
  driveToHeading(-16.8, 180, 3000, true, 7);
  driveChassis(-1,-1);
  scoreLongGoal();
  vex::wait(1300, msec);
  driveChassis(0,0);
  resetOdom(-31.5, 15);
  matchloader.set(true);
  max_slew_accel_fwd = 24;
max_slew_decel_fwd = 24;
max_slew_accel_rev = 24;
 max_slew_decel_rev = 24;
dir_change_end = true;   
  moveToPoint(-28.5, -9, 1, 3000, false, 6);
  storeIntake();
  turnToAngle(180, 3000);
  driveChassis(6,6);
  vex::wait(1380, msec);
  vex::task scoreL([]{
    vex::wait(1100, msec);
    scoreLongGoal();
    return 0;
  });
  moveToPoint(-29, 10, -1, 3000, false, 6);
  driveChassis(-6, -6);
  vex::wait(1200, msec);
  driveChassis(0,0);
  resetChassis();
  driveChassis(4,4);
  vex::wait(500, msec);
  driveChassis(-6,-6);
  vex::wait(700, msec);
  driveChassis(0,0);
}

void left9LongDisrupt(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(800, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(-7, 24, 1, 2000, false, 6);
  boomerang(-30, 33.5, 1, -39, 0.1, 3000, true, 9);
  matchloader.set(true);
  vex::wait(80, msec);
  heading_correction_kp = 0.3;
  moveToPoint(-23, 15, -1, 3000, false, 8);
  boomerang(-32, 15, -1,90, 0.1, 3000, true, 8);
  turnToAngle(180, 1000, true, 7);
  driveToHeading(-14, 180, 3000, true, 7);
  scoreLongGoal();
  vex::wait(1100, msec);
  driveChassis(0,0);
  resetOdom(-31.5, 15);
  matchloader.set(true);
  moveToPoint(-30, -7, 1, 3000, false, 6);
  storeIntake();
  turnToAngle(180, 3000);
  driveChassis(6,6);
  vex::wait(950, msec);
  vex::task scoreL([]{
    vex::wait(1100, msec);
    scoreLongGoal();
    return 0;
  });
  moveToPoint(-31, 10, -1, 3000, false, 6);
  driveChassis(-6, -6);
  vex::wait(1000, msec);
  driveToHeading(12, 180, 3000, true, 6);
  vex::wait(20, msec);
  driveToHeading(-20, 180, 3000, true, 6);
}



void right9Long(){
  leftWing.set(true);
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = 45;
  vex::task matchloadDeploy([]{
    vex::wait(800, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(9, 24, 1, 2000, false, 5);
  matchloader.set(false);
  vex::task matchloadDeploy2([]{
    vex::wait(1000, msec);
    matchloader.set(true);
    return 0;
  });
  boomerang(34, 43, 1, 40, 0.1, 3000, true, 5);
  driveChassis(2,2);
  vex::wait(0.1, sec);
  matchloader.set(true);
  vex::wait(80, msec);
  //moveToPoint(34, 30, -1, 3000, false, 8);
  moveToPoint(26, 13, -1, 3000, false, 8);
  stopIntake();
  moveToPoint(47.8,10, -1, 3000, true, 8);
  turnToAngle(180, 1000, true, 7);
  driveChassis(-6,-6);
  vex::wait(0.4, sec);
  driveChassis(-1, -1);
  scoreLongGoal();
  vex::wait(1500, msec);
  matchloader.set(true);
  moveToPoint(49, 6, 1, 3000, false, 6);
  storeIntake();
  turnToAngle(180, 3000);
  driveChassis(6,6);
  vex::wait(950, msec);
  vex::task scoreL([]{
    vex::wait(1100, msec);
    scoreLongGoal();
    return 0;
  });
  moveToPoint(49, 10, -1, 3000, false, 6);
  driveToHeading(-16, 180, 3000, true, 6);
  scoreLongGoal();
  vex::wait(1500, msec);
  driveToHeading(12, 180, 3000, true, 6);
  vex::wait(20, msec);
  driveToHeading(-20, 180, 3000, true, 6);

}

void right9LongDisrupt(){
  leftWing.set(true);
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = 45;
  vex::task matchloadDeploy([]{
    vex::wait(800, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(6, 24, 1, 2000, false, 5);
  matchloader.set(true);
  vex::task matchloadDeploy2([]{
    vex::wait(1000, msec);
    matchloader.set(true);
    return 0;
  });
  boomerang(32, 45, 1, 40, 0.1, 3000, true, 12);
  matchloader.set(true);
  vex::wait(80, msec);
  heading_correction_kp = 0.3;
  moveToPoint(28, 13, -1, 3000, false, 8);
  stopIntake();
  boomerang(48, 13, -1,-90, 0.1, 3000, true, 8);
  turnToAngle(180, 1000, true, 7);
  driveToHeading(-14, 180, 3000, true, 7);
  scoreLongGoal();
  vex::wait(1500, msec);
  matchloader.set(true);
  moveToPoint(48.5, 6, 1, 3000, false, 6);
  storeIntake();
  turnToAngle(180, 3000);
  driveChassis(6,6);
  vex::wait(1000, msec);
  vex::task scoreL([]{
    vex::wait(1100, msec);
    scoreLongGoal();
    return 0;
  });
  moveToPoint(49, 10, -1, 3000, false, 6);
  driveToHeading(-20, 180, 3000, true, 6);
  scoreLongGoal();
  vex::wait(1500, msec);
  driveToHeading(12, 180, 3000, true, 6);
  vex::wait(20, msec);
  driveToHeading(-20, 180, 3000, true, 6);

}

void leftLongAndMid(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  driveTo(2, 1000, true, 2);
  /*leftWing.set(true);
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(850, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(-11.2, 24, 1, 2000, false, 7);
  matchloader.set(false);
  vex::task matchloadDeploy2([]{
    vex::wait(850, msec);
    //matchloader.set(true);
    return 0;
  });
  correct_angle = -40;
  moveToPoint(-22, 31, 1, 3000, true, 6);
  driveChassis(4,4);
  vex::wait(100,msec);
  driveChassis(1,1);
  vex::wait(300,msec);
  moveToPoint(-7, 23, -1, 3000, false, 5);
  //matchloader.set(false);
  turnToAngle(-138, 1000, true, 7);
  vex::task middleready([]{
    outtake();
   vex::wait(60, msec);
     stopIntake();
    matchloader.set(true);
   return 0;
  });
  driveTo(-11,2000, true, 5);
  middleGoal.set(true);
  scoreMiddleGoal();
  vex::wait(600, msec);
  stopIntake();
  middleGoal.set(false);
  matchloader.set(true);
  matchloader.set(true);
  max_slew_accel_fwd = 24;
max_slew_decel_fwd = 24;
max_slew_accel_rev = 24;
 max_slew_decel_rev = 24;
dir_change_end = true;   
  moveToPoint(-26.5, 0, 1, 3000, true, 8);
  storeIntake();
  turnToAngle(180, 3000);
  driveChassis(5,5);
  vex::wait(1200, msec);
  vex::task scoreL([]{
    vex::wait(1100, msec);
    scoreLongGoal();
    return 0;
  });
  moveToPoint(-26.5, 5, -1, 3000, false, 8);
  driveToHeading(-20, 180, 1000, true, 5);
  scoreLongGoal();
  vex::wait(1200, msec);
  curveCircle(120, -16, 1000, false, 9);
  driveTo(2, 3000, false, 10);
  vex::task wingdep([]{
    vex::wait(350, msec);
    leftWing.set(false);
    return 0;
  });
  turnToAngle(180, 800, true, 7);
  driveTo(-31, 3000, true,4);
  turnToAngle(-160, 900, true, 10);
 
  stopChassis(brakeType::hold);
*/
}


void leftLongAndMidDisrupt(){
  min_output = 100;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(850, msec);
    matchloader.set(true);
    return 0;
  });
  moveToPoint(-7, 24, 1, 2000, false, 5);
  matchloader.set(true);
  vex::task matchloadDeploy2([]{
    vex::wait(850, msec);
    matchloader.set(true);
    return 0;
  });
  boomerang(-30, 34, 1, -39, 0.1, 3000, true, 12);
  vex::wait(80, msec);
  moveToPoint(-0.5, 23, -1, 3000, false, 5);
  driveChassis(-1,-1);
  vex::wait(10, msec);
  turnToAngle(-138, 1000, true, 5);
  driveTo(-7,2000, true, 5);
  middleGoal.set(true);
  scoreMiddleGoal();
  vex::wait(450, msec);
  stopIntake();
  middleGoal.set(false);
  moveToPoint(-23.6, -2, 1, 3000, false, 6);
  turnToAngle(178, 300, true, 6);
  driveToHeading(-18, 180, 3000, true, 6);
  scoreLongGoal();
  vex::wait(850, msec);
  matchloader.set(true);
  moveToPoint(-23.5, -7, 1, 3000, false, 6);
  storeIntake();
  turnToAngle(180, 3000);
  driveChassis(7,7);
  vex::wait(900, msec);
  vex::task scoreL([]{
    vex::wait(1100, msec);
    scoreLongGoal();
    return 0;
  });
  moveToPoint(-23, 5, -1, 3000, false, 6);
  driveToHeading(-10, 180, 3000, true, 6);
  scoreLongGoal();
  vex::wait(1500, msec);
  driveToHeading(10, 180, 3000, true, 6);
  driveToHeading(-20, 180, 3000, true, 6);

}

void rightLongAndLow(){
  leftWing.set(true);
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  manualIntake(12,0);
  moveToPoint(11, 24, 1, 2000, false, 7);
  turnToAngle(-80, 800, true, 8);
  moveToPoint(8, 20, 1, 2000, true, 7);
  turnToAngle(-60, 800, true, 8);
  driveChassis(5,5);
  vex::wait(500, msec);
  manualIntake(-7, 0);
  driveChassis(0,0);
  vex::wait(200, msec);
  driveChassis(-5, -5);
  vex::wait(500, msec);
  driveChassis(5,5);
  vex::wait(500, msec);
  driveChassis(-5, -5);
  vex::wait(500, msec);
  moveToPoint(11, 24, -1, 2000, false, 9);
  correct_angle = 45;
  moveToPoint(20, 27, -1, 2000, true, 7);


}


//todo
void left7LongandWing(){
  heading_correction_kp = 0.8;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(600, msec);
    matchloader.set(true);
    return 0;
  });
  //goes to stack
  moveToPoint(-9.3, 24, 1, 2000, false, 8);
  turnToAngle(-150, 300, false, 7);
  heading_correction_kp = 0.67;
  correct_angle = normalizeTarget(-160);
  max_slew_accel_fwd = 24;
max_slew_decel_fwd = 24;
max_slew_accel_rev = 24;
 max_slew_decel_rev = 24;
dir_change_end = true;
  moveToPoint(-23, -10, 1, 2000, true, 9);
  turnToAngle(180, 800, true, 7);
  driveChassis(5,5);
  vex::wait(0.8, sec);
  moveToPoint(-22.5, 5, -1, 2000, false, 8);
  turnToAngle(180, 800, true, 7);
  driveChassis(-7,-7);
  vex::wait(0.4, sec);
  
  scoreLongGoal();
  driveChassis(0,0);
  vex::wait(2, sec);
  stopIntake();
  resetOdom(-21.5, 5);
  leftWing.set(true);
  //curveCircle(120, -14, 1000, false, 8);
  curveCircle(120, -14, 1000, false, 9);
  driveTo(2, 3000, false, 10);
  vex::task wingdep([]{
    vex::wait(350, msec);
    leftWing.set(false);
    return 0;
  });
  turnToAngle(180, 800, true, 7);
  driveTo(-31, 3000, true,4);
  turnToAngle(-160, 900, true, 10);
 
  stopChassis(brakeType::hold);
  //

}

void right7LongandWing(){
  heading_correction_kp = 0.8;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = 45;
  vex::task matchloadDeploy([]{ 
    vex::wait(600, msec);
    matchloader.set(true);
    return 0;
  });
  //goes to stack
  moveToPoint(9.4, 24, 1, 2000, false, 8);
  max_slew_accel_fwd = 24;
max_slew_decel_fwd = 24;
max_slew_accel_rev = 24;
 max_slew_decel_rev = 24;
dir_change_end = true;
  turnToAngle(140, 300, false, 7);
  heading_correction_kp = 0.67;
  correct_angle = normalizeTarget(160);
  //moveToPoint(31, 10, 1, 2000, false, 12);
  moveToPoint(42.6, -1, 1, 2000, false, 9);
  turnToAngle(-180, 800, true, 7);
  driveChassis(6,6);
  vex::wait(0.95, sec);
  moveToPoint(43.6, 5, -1, 2000, false, 8);
  turnToAngle(-180, 800, true, 7);
  driveChassis(-8,-8);
  vex::wait(0.35, sec);
  driveChassis(-1,-1);
  scoreLongGoal();
  driveChassis(0,0);
  vex::wait(2, sec);
  stopIntake();
  leftWing.set(true);
  curveCircle(120, -14, 1000, false, 9);
  driveTo(2.25, 3000, false, 10);
  
  vex::task wingdep([]{
    vex::wait(150, msec);
    leftWing.set(false);
    return 0;
  });
  turnToAngle(-180, 800, true, 7);
  driveTo(-31.5, 20000, true,4);
  turnToAngle(-165, 900, true, 10);
  stopChassis(brakeType::hold);
  //
}
void left4(){
  heading_correction_kp = 0.8;
  vex::task antiJamF([]{
    while(1){
      antiJamTask();
      vex::wait(20, msec);
    }
    return 0;
  });
  // Use this for tuning linear and turn pid
  storeIntake();
  correct_angle = -45;
  vex::task matchloadDeploy([]{
    vex::wait(600, msec);
    matchloader.set(true);
    return 0;
  });
  //goes to stack
  moveToPoint(-9.3, 24, 1, 2000, false, 8);
  turnToAngle(-150, 300, false, 7);
  heading_correction_kp = 0.67;
  correct_angle = normalizeTarget(-160);
  max_slew_accel_fwd = 24;
max_slew_decel_fwd = 24;
max_slew_accel_rev = 24;
 max_slew_decel_rev = 24;
dir_change_end = true;
  moveToPoint(-23, -4, 1, 2000, true, 9);
  turnToAngle(180, 800, true, 7);
  driveToHeading(-17, 180, 1000, true, 8);
  scoreLongGoal();
  vex::wait(2, sec);
  stopIntake();
  curveCircle(120, -14, 1000, false, 9);
  driveTo(1.9, 3000, false, 10);
  vex::task wingdep([]{
    vex::wait(350, msec);
    leftWing.set(false);
    return 0;
  });
  turnToAngle(180, 800, true, 7);
  matchloader.set(false);
  driveTo(-29, 3000, true,4);
  turnToAngle(-160, 900, true, 10);
  stopChassis(brakeType::hold);
}
//   heading_correction_kp = 0.8;
//   vex::task antiJamF([]{
//     while(1){
//       antiJamTask();
//       vex::wait(20, msec);
//     }
//     return 0;
//   });
//   // Use this for tuning linear and turn pid
//   storeIntake();
//   correct_angle = -45;
//   vex::task matchloadDeploy([]{
//     vex::wait(600, msec);
//     matchloader.set(true);
//     return 0;
//   });
//   //goes to stack
//   moveToPoint(-9.3, 24, 1, 2000, false, 8);
//   max_slew_accel_fwd = 24;
// max_slew_decel_fwd = 24;
// max_slew_accel_rev = 24;
//  max_slew_decel_rev = 24;
// dir_change_end = true;
//   turnToAngle(50, 300, false, 7);
//   heading_correction_kp = 0.67;
  
  //
void rifour(){
  driveTo(2,2000,true,2);
  vex::wait(1000,msec);
  moveToPoint(0,0,1,2000,true,2,false);
  scoreLongGoal();
  vex::wait(100000,msec);
  driveTo(1,2000,true,1);



}






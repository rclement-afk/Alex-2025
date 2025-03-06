#include <kipr/wombat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>
//#define LIBSSH_STATIC 1
//#include <libssh/libssh.h>
////////////////////////////////////////////////////////////////
//ALERT OMNI_STRAFE IS HARD CODED TO 90 DEGREES and 45 DEGREES//
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//COMMENT TOP VARIABLES IN AFTER RUNNING ALL PARTS OF DIAG();///
////////////////////////////////////////////////////////////////


int main()
{



//////////////////////////////////////////////////
    /*FILE *file997 = fopen ("Arm.txt","r");
    char line[16];
    fgets(line, sizeof(line) ,file997);

    msleep(5);
    fclose(file997);
    int arm=atof(line);
    printf("\n arm: %d ", arm);
///////////////////////////////////////////////////

    FILE *file996 = fopen ("Claw.txt","r");
    char line1[16];
    while(fgets(line1, sizeof(line1),file996)){}

    msleep(5);
    fclose(file996);
    int  claw=atof(line1);
    printf("\n claw: %d", claw);
//////////////////////////////////////////////////
    FILE *file988 = fopen ("Turret.txt","r");
    char line2[16];
    while(fgets(line2, sizeof(line2),file988)){}

    msleep(5);
    fclose(file988);
    int turret=atof(line2);
    printf("\n turret: %d", turret);
    
//////////////////////////////////////////////////

 FILE *file950 = fopen ("four.txt","r");
    char line8[16];
    while(fgets(line1, sizeof(line8),file950))

    {printf("Fourth Servo: %s\n", line);}
    fclose(file950);
    int  claw=atof(line8);
    printf(" Fourth Servo: %d\n", fourth);
*/
    new_calibrate_z();
    Diag();

    return 0;
}




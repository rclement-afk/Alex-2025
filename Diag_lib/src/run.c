#include <stdlib.h>
#include <math.h>
#include <kipr/wombat.h>
#include <constants.h>



int motor_def()
{
    display_clear();
    double number;

    printf(" do you have 2 or 4 motors? A = 2 B = 4");
    while(1)
    {
        if(side_button() == 1)
        {
            while(side_button() == 1){}
            return 8008;   
        }
        if(a_button() == 1)
        {
            while(a_button() == 1){}
            printf("Define Left Motor port. A=0, B=1, C=2, X=3 \n");
            printf("A");

            while(1)
            {
                if(side_button() ==1) {
                    while(side_button() == 1){}
                    return 8008;
                }
                if(a_button() == 1)
                {
                    while(a_button() ==1){}
                    number = 0;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 0 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 0 for Left Motor");

                    break;
                }else if(b_button() == 1)
                {
                    while(b_button() ==1){}
                    number = 1;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 1 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 1 for Left Motor");

                    break;
                }else if(c_button() == 1)
                {
                    while(c_button() ==1){}
                    number = 2;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 2 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 2 for Left Motor");

                    break;
                }else if(x_button() == 1)
                {
                    while(x_button() ==1){}
                    number = 3;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 3 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 3 for Left Motor");

                    break;

                }

            }
            printf( " Define Right Motor port. A=0, B=1, C=2, X=3 Y=Exit ");
            while(1)
            {
                if(side_button() == 1) {
                    while(side_button() ==1){}
                    return 8008;
                }
                if(a_button() == 1)
                {
                    while(a_button() == 1){}
                    number = 0;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 0 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 0 for Right Motor");

                    break;
                }else if(b_button() == 1)
                {
                    while(b_button() == 1){}
                    number = 1;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 1 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 1 for Right Motor");

                    break;
                }else if(c_button() == 1)
                {
                    while(c_button() == 1){}
                    number = 2;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 2 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 2 for Right Motor");

                    break;
                }else if(x_button() == 1)
                {
                    while(x_button() == 1){}
                    number = 3;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 3 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 3 for Right Motor");

                    break;

                }

            }
            FILE * file993= fopen("BackLeftMotor.txt", "w"); 
            fprintf(file993, "%f",5678.0);
            fclose(file993);
            display_clear();

            FILE * file992= fopen("BackRightMotor.txt", "w"); 
            fprintf(file992, "%f",9876.0);
            fclose(file992);
            display_clear();
        }else if( b_button() == 1)
        {
            while(b_button() == 1){}

            printf("Define Left Motor port. A=0, B=1, C=2, X=3 \n");

            while(1)
            {
                if(side_button() ==1) {
                    while(side_button() == 1){}
                    return 8008;
                }
                if(a_button() == 1)
                {
                    while(a_button() ==1){}
                    number = 0;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 0 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 0 for Left Motor");

                    break;
                }else if(b_button() == 1)
                {
                    while(b_button() ==1){}
                    number = 1;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 1 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 1 for Left Motor");

                    break;
                }else if(c_button() == 1)
                {
                    while(c_button() ==1){}
                    number = 2;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 2 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 2 for Left Motor");

                    break;
                }else if(x_button() == 1)
                {
                    while(x_button() ==1){}
                    number = 3;
                    FILE *file999 = fopen("LeftMotor.txt","w"); 
                    printf("\n You have chosen Port 3 for Left Motor");
                    fprintf(file999, "%f",number);
                    fclose(file999);
                    display_clear();
                    printf("\n You have chosen Port 3 for Left Motor");

                    break;

                }


            }
            printf( " Define Right Motor port. A=0, B=1, C=2, X=3 Y=Exit ");
            while(1)
            {
                if(side_button() == 1) {
                    while(side_button() ==1){}
                    return 8008;
                }
                if(a_button() == 1)
                {
                    while(a_button() == 1){}
                    number = 0;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 0 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 0 for Right Motor");

                    break;
                }else if(b_button() == 1)
                {
                    while(b_button() == 1){}
                    number = 1;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 1 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 1 for Right Motor");

                    break;
                }else if(c_button() == 1)
                {
                    while(c_button() == 1){}
                    number = 2;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 2 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 2 for Right Motor");

                    break;
                }else if(x_button() == 1)
                {
                    while(x_button() == 1){}
                    number = 3;
                    FILE * file998= fopen("RightMotor.txt", "w"); 
                    printf("\n You have chosen Port 3 for Right Motor");
                    fprintf(file998, "%f",number);
                    fclose(file998);
                    display_clear();
                    printf("\n You have chosen Port 3 for Right Motor");

                    break;

                }

            }
            display_clear();
            printf("Define Back Left Motor port. A=0, B=1, C=2, X=3 \n");

            while(1)
            {
                if(side_button() ==1) {
                    while(side_button() == 1){}
                    return 8008;
                }
                if(a_button() == 1)
                {
                    while(a_button() ==1){}
                    number = 0;
                    FILE * file993= fopen("BackLeftMotor.txt", "w"); 
                    printf("\n You have chosen Port 0 for Back Left Motor");
                    fprintf(file993, "%f",number);
                    fclose(file993);
                    display_clear();
                    printf("\n You have chosen Port 0 for Back Left Motor");

                    break;
                }else if(b_button() == 1)
                {
                    while(b_button() ==1){}
                    number = 1;
                    FILE * file993= fopen("BackLeftMotor.txt", "w"); 
                    printf("\n You have chosen Port 1 for Back Left Motor");
                    fprintf(file993, "%f",number);
                    fclose(file993);
                    display_clear();
                    printf("\n You have chosen Port 1 for Back Left Motor");

                    break;
                }else if(c_button() == 1)
                {
                    while(c_button() ==1){}
                    number = 2;
                    FILE * file993= fopen("BackLeftMotor.txt", "w"); 
                    printf("\n You have chosen Port 2 for Back Left Motor");
                    fprintf(file993, "%f",number);
                    fclose(file993);
                    display_clear();
                    printf("\n You have chosen Port 2 for Back Left Motor");

                    break;
                }else if(x_button() == 1)
                {
                    while(x_button() ==1){}
                    number = 3;
                    FILE * file993= fopen("BackLeftMotor.txt", "w"); 
                    printf("\n You have chosen Port 3 for Back Left Motor");
                    fprintf(file993, "%f",number);
                    fclose(file993);
                    display_clear();
                    printf("\n You have chosen Port 3 for Back Left Motor");

                    break;

                }

            }
            printf( " Define Back Right Motor port. A=0, B=1, C=2, X=3 Y=Exit ");
            while(1)
            {
                if(side_button() == 1) {
                    while(side_button() ==1){}
                    return 8008;
                }
                if(a_button() == 1)
                {
                    while(a_button() == 1){}
                    number = 0;
                    FILE * file992= fopen("BackRightMotor.txt", "w"); 
                    printf("\n You have chosen Port 0 for Back Right Motor");
                    fprintf(file992, "%f",number);
                    fclose(file992);
                    display_clear();
                    printf("\n You have chosen Port 0 for Back Right Motor");

                    return 85;
                }else if(b_button() == 1)
                {
                    while(b_button() == 1){}
                    number = 1;
                    FILE * file992= fopen("BackRightMotor.txt", "w"); 
                    printf("\n You have chosen Port 1 for Back Right Motor");
                    fprintf(file992, "%f",number);
                    fclose(file992);
                    display_clear();
                    printf("\n You have chosen Port 1 for Back Right Motor");

                    return 85;
                }else if(c_button() == 1)
                {
                    while(c_button() == 1){}
                    number = 2;
                    FILE * file992= fopen("BackRightMotor.txt", "w"); 
                    printf("\n You have chosen Port 2 for Back Right Motor");
                    fprintf(file992, "%f",number);
                    fclose(file992);
                    display_clear();
                    printf("\n You have chosen Port 2 for Back Right Motor");

                    return 85;
                }else if(x_button() == 1)
                {
                    while(x_button() == 1){}
                    number = 3;
                    FILE * file992= fopen("BackRightMotor.txt", "w"); 
                    printf("\n You have chosen Port 3 for Back Right Motor");
                    fprintf(file992, "%f",number);
                    fclose(file992);
                    display_clear();
                    printf("\n You have chosen Port 3 for Back Right Motor");

                    return 85;


                }

            }

        }

    }

    return 5318008; 

}




int servo_def()
{
    display_clear();
    double number;
    printf("Define Arm port. A=0, B=1, C=2, X=3 /n");
    while(1)
    {
        if(side_button() == 1) {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            while(a_button() ==1){}
            number = 0;
            FILE * file997= fopen("Arm.txt", "w"); 
            printf("\n You have chosen Port 0 for Arm");
            fprintf(file997, "%f",number);
            fclose(file997);
            display_clear();
            printf("\n You have chosen Port 0 for Arm");
            break;
        }else if(b_button() == 1)
        {
            while(b_button() ==1){}
            number = 1;
            FILE * file997= fopen("Arm.txt", "w"); 
            printf("\n You have chosen Port 1 for Arm");
            fprintf(file997, "%f",number);
            fclose(file997);
            display_clear();
            printf("\n You have chosen Port 1 for Arm");
            break;
        }else if(c_button() == 1)
        {
            while(c_button() ==1){}
            number = 2;
            FILE * file997= fopen("Arm.txt", "w"); 
            printf("\n You have chosen Port 2 for Arm");
            fprintf(file997, "%f",number);
            fclose(file997);
            display_clear();
            printf("\n You have chosen Port 2 for Arm");
            break;
        }else if(x_button() == 1)
        {
            while(x_button() ==1){}
            number = 3;
            FILE * file997= fopen("Arm.txt", "w"); 
            printf("\n You have chosen Port 3 for Arm");
            fprintf(file997, "%f",number);
            fclose(file997);
            display_clear();
            printf("\n You have chosen Port 3 for Arm");
            break;

        }

    }
    printf( " Define Claw port. A=0, B=1, C=2, X=3 Y=Exit ");
    while(1)
    {
        if(side_button() ==1) {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            while(a_button() == 1){}
            number = 0;
            FILE * file996= fopen("Claw.txt", "w"); 
            printf("\n You have chosen Port 0 for Claw");
            fprintf(file996, "%f",number);
            fclose(file996);
            display_clear();
            printf("\n You have chosen Port 0 for Claw");
            break;
        }else if(b_button() == 1)
        {
            while(b_button() == 1){}
            number = 1;
            FILE * file996= fopen("Claw.txt", "w"); 
            printf("\n You have chosen Port 1 for Claw");
            fprintf(file996, "%f",number);
            fclose(file996);
            display_clear();
            printf("\n You have chosen Port 1 for Claw");
            break;
        }else if(c_button() == 1)
        {
            while(c_button() == 1){}
            number = 2;
            FILE * file996= fopen("Claw.txt", "w"); 
            printf("\n You have chosen Port 2 for Claw");
            fprintf(file996, "%f",number);
            fclose(file996);
            display_clear();
            printf("\n You have chosen Port 2 for Claw");
            break;
        }else if(x_button() == 1)
        {
            while(x_button() == 1){}
            number = 3;
            FILE * file996= fopen("Claw.txt", "w"); 
            printf("\n You have chosen Port 3 for Claw");
            fprintf(file996, "%f",number);
            fclose(file996);
            display_clear();
            printf("\n You have chosen Port 3 for Claw");
            break;

        }

    }
    display_clear();
    printf(" Define Turret port");

    while(1)
    {
        if(side_button() ==1) {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            while(a_button() == 1){}
            number = 0;
            FILE * file988= fopen("Turret.txt", "w"); 
            printf("\n You have chosen Port 0 for Turret");
            fprintf(file988, "%f",number);
            fclose(file988);
            display_clear();
            printf("\n You have chosen Port 0 for Turret");
            break;
        }else if(b_button() == 1)
        {
            while(b_button() == 1){}
            number = 1;
            FILE * file988= fopen("Turret.txt", "w"); 
            printf("\n You have chosen Port 1 for Turret");
            fprintf(file988, "%f",number);
            fclose(file988);
            display_clear();
            printf("\n You have chosen Port 1 for Turret");
            break;
        }else if(c_button() == 1)
        {
            while(c_button() == 1){}
            number = 2;
            FILE * file988= fopen("Turret.txt", "w"); 
            printf("\n You have chosen Port 2 for Turret");
            fprintf(file988, "%f",number);
            fclose(file988);
            display_clear();
            printf("\n You have chosen Port 2 for Turret");
            break;
        }else if(x_button() == 1)
        {
            while(x_button() == 1){}
            number = 3;
            FILE * file988= fopen("Turret.txt", "w"); 
            printf("\n You have chosen Port 3 for Turret");
            fprintf(file988, "%f",number);
            fclose(file988);
            display_clear();
            printf("\n You have chosen Port 3 for Turret");
            break;

        }
    }
    display_clear();
    printf("\n Define fourth servo A=0, B=1, C=2 ,X=3");


    while(1)
    {
        if(side_button() ==1) {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            while(a_button() == 1){}
            number = 0;
            FILE * file950= fopen("four.txt", "w"); 
            printf("\n You have chosen Port 0 for Turret");
            fprintf(file950, "%f",number);
            fclose(file950);
            display_clear();
            printf("\n You have chosen Port 0 for Turret");
            break;
        }else if(b_button() == 1)
        {
            while(b_button() == 1){}
            number = 1;
            FILE * file950= fopen("four.txt", "w"); 
            printf("\n You have chosen Port 1 for Turret");
            fprintf(file950, "%f",number);
            fclose(file950);
            display_clear();
            printf("\n You have chosen Port 1 for Turret");
            break;
        }else if(c_button() == 1)
        {
            while(c_button() == 1){}
            number = 2;
            FILE * file950= fopen("four.txt", "w"); 
            printf("\n You have chosen Port 2 for Turret");
            fprintf(file950, "%f",number);
            fclose(file950);
            display_clear();
            printf("\n You have chosen Port 2 for Turret");
            break;
        }else if(x_button() == 1)
        {
            while(x_button() == 1){}
            number = 3;
            FILE * file950= fopen("four.txt", "w"); 
            printf("\n You have chosen Port 3 for Turret");
            fprintf(file950, "%f",number);
            fclose(file950);
            display_clear();
            printf("\n You have chosen Port 3 for Turret");
            break;

        }


    }

    return 80085;
}
int digital_def()
{
    display_clear();
    double number;
    printf("Define front clicker port. A=0, B=1, C=2, X=3 \n");

    while(1)
    {
        if(side_button() ==1) {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            while(a_button() ==1){}
            number = 0;
            FILE * file995= fopen("FrontClicker.txt", "w"); 
            printf("\n You have chosen Port 0 for Front Clicker");
            fprintf(file995, "%f",number);
            fclose(file995);
            display_clear();
            printf("\n You have chosen Port 0 for Front Clicker");
            break;
        }else if(b_button() == 1)
        {
            while(b_button() ==1){}
            number = 1;
            FILE * file995= fopen("FrontClicker.txt", "w"); 
            printf("\n You have chosen Port 1 for Front Clicker");
            fprintf(file995, "%f",number);
            fclose(file995);
            display_clear();
            printf("\n You have chosen Port 1 for Front Clicker");
            break;
        }else if(c_button() == 1)
        {
            while(c_button() ==1){}
            number = 2;
            FILE * file995= fopen("FrontClicker.txt", "w"); 
            printf("\n You have chosen Port 2 for Front Clicker");
            fprintf(file995, "%f",number);
            fclose(file995);
            display_clear();
            printf("\n You have chosen Port 2 for Front Clicker");
            break;
        }else if(x_button() == 1)
        {
            while(x_button() ==1){}
            number = 3;
            FILE * file995= fopen("FrontClicker.txt", "w"); 
            printf("\n You have chosen Port 3 for Front Clicker");
            fprintf(file995, "%f",number);
            fclose(file995);
            display_clear();
            printf("\n You have chosen Port 3 for Front Clicker");
            break;

        }

    }
    printf( " Define Back Clicker port. A=0, B=1, C=2, X=3 Y=Exit ");
    while(1)
    {
        if(side_button() == 1) {
            while(side_button() ==1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            while(a_button() == 1){}
            number = 0;
            FILE * file994= fopen("BackClicker.txt", "w"); 
            printf("\n You have chosen Port 0 for Back Clicker");
            fprintf(file994, "%f",number);
            fclose(file994);
            display_clear();
            printf("\n You have chosen Port 0 for Back Clicker");
            break;
        }else if(b_button() == 1)
        {
            while(b_button() == 1){}
            number = 1;
            FILE * file994= fopen("BackClicker.txt", "w"); 
            printf("\n You have chosen Port 1 for Back Clicker");
            fprintf(file994, "%f",number);
            fclose(file994);
            display_clear();
            printf("\n You have chosen Port 1 for Back Clicker");
            break;
        }else if(c_button() == 1)
        {
            while(c_button() == 1){}
            number = 2;
            FILE * file994= fopen("BackClicker.txt", "w"); 
            printf("\n You have chosen Port 2 for Back Clicker");
            fprintf(file994, "%f",number);
            fclose(file994);
            display_clear();
            printf("\n You have chosen Port 2 for Back Clicker");
            break;
        }else if(x_button() == 1)
        {
            while(x_button() == 1){}
            number = 3;
            FILE * file994= fopen("BackClicker.txt", "w"); 
            printf("\n You have chosen Port 3 for Back Clicker");
            fprintf(file994, "%f",number);
            fclose(file994);
            display_clear();
            printf("\n You have chosen Port 3 for Back Clicker");
            break;

        }

    }

    return 5318008; 

}


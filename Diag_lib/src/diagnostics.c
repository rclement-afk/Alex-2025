#include <kipr/wombat.h>
#include <constants.h>

int Diag() 
{  
    printf("hey ");
    set_extra_buttons_visible(1);
    
    int button=1;
    int temp_fix; //now permanent
    int cal_fix = 1;

    while (1) {
        display_clear();
        printf("The A Button = CALIBRATION ROUTINE\n");
        printf("The B Button = MOTORS\n");
        printf("The C Button = Digital/Clicker ports\n");
        printf("The X Button = SERVOS\n");
        printf("The Y Button = White and Black values + IR ports\n");
        printf("The Z Button = Ticks to Inch Cal.");
        printf("\nThe Side Button Exits Program");
        if (side_button()==1 && temp_fix != 5){
            while(side_button() == 1){}
            display_clear();
            return 1;
        }




        msleep(30);

        switch(button)
        {
            case 1:
                if(a_button(1)) 
                {
                    display_clear();
                    printf("Welcome to the calibration routine homepage!");

                    while(1){//insert calibration routine here
                        while(a_button(1)){}
                        ////////////////////////////////////////////
                        //insert calibration routine here		  //	
                        ////////////////////////////////////////////
                        if(cal_fix == 1)
                        {
                            cal_fix = 2;
                         	break;   
                        }
                        if(side_button()==1)
                        {msleep(30);
                         while(side_button()==1){msleep(30);}                               
                         break;
                        }
                    }
                    //wandbval();
                    //return wandbval();//Error rn
                    if(cal_fix == 2)
                    {
                     	break;   
                    }
                }

            case 2:
                if(b_button(1)) {
                    display_clear();

                    printf("Welcome to the MOTORS homepage!");

                    //insert calibration routine here
                    while(b_button(1)){}
                    ////////////////////////////////////////////

                    ///////////////////////////////////////////
                    if(motor_def() ==8008) {

                        break;

                    }else{
                        Diag();   
                    }

                    /*  if(side_button()==1)
                    {msleep(30);
                     while(side_button()==1){msleep(30);}                               
                     break;
                    }
                    */
                }

                /*
                        while(b_button(1)){}

                        display_clear();
                        motor_def();

                        if(side_button() ==1) 
                        {
                            printf(" wiener ");
                            while(side_button() ==1)
                            {

                            }
                            printf("gygfiawdgdgf");

                            break;

                        }*/

            case 3:
                if(c_button(1)) 
                {

                    while(c_button(1)) {
                        while(c_button() == 1){}
                        if(digital_def() ==8008)
                        {
                            break;
                        }
                    }

                }


            case 4:
                if(x_button(1)) 
                {
                    while(x_button(1)) {
                        display_clear();
                        printf("Welcome to the Servo Widget\n");
                        msleep(2000);

                        display_clear();

                        if(servo_def() ==8008) {


                            break;

                        }



                    }
                }
            case 5:
                if(y_button() ==1) 
                {

                    while(y_button() == 1) {}
                    if( IR_Ports() == 8008)
                    {
                        break;
                    }
                    temp_fix = 5;
                    display_clear();
                    wandbval();
                    msleep(5000);
                    temp_fix = 0;
                }  



            case 6:
                if(z_button() ==1) 
                {

                    while(z_button() == 1) {}
                    display_clear();
                    ticks_to_inches(1200,12.0);
                    msleep(1000);
                    while(side_button()==0){}
                    while(side_button()==1){}
                    Diag();   



                }





        }

    }

}




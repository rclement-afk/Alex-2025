#include <constants.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>




// Version 3.99

// The degree-theta ratio changes depending on the speed used.
// Current value is calibrated for speed 1000
//original ratio was 890
#define locolib_gyro_turn_degree_theta_ratio 900
#define locolib_gyro_turn_speed 1000
#define locolib_demobot_wheel_width 7.8


//// ==== ==== ==== ==== ==== ==== ==== ==== ====



int blue=0;
int red=1;
int green=2;

int follow_object()
{
    int n = 0;
    int q = systime();
    printf("object y = %d",get_object_center_y(green,0));
    int adjustment_for_y =0;
    while(1)
    {
        camera_update();
        adjustment_for_y =2*(88-get_object_center_y(green,0));
        if (get_object_count(green)>1)
        {motor(0,0);
         motor(1,0);}
        if (get_object_count (green)>0)
        { motor(1,get_object_center_x(green,0)-80+adjustment_for_y);
         motor(0,80-get_object_center_x(green,0)+adjustment_for_y);}
        else
        { motor(0,0);
         motor(1,0);}
    }
    while(n<7)
    {camera_update();
     msleep(0);
     if(get_object_center_x(0,0)>0)
     {
         printf("confidence=%f\n",get_object_confidence(blue,0));
         int w = systime()-q;
         printf("total time=%d\n",w);
         return get_object_center_x(green,0);
     }
     n=n+1;
    }
    printf("object y = %d",get_object_center_y(green,0));
    int center_up_object(int green);
    return get_object_center_x(green,0);
    if(0>80)
    {motor(80,-80);}
    else if(0<80)
    {motor(-80,80);}
    else
    {motor(0,0);}
}

int rotate_object()
{
    enable_servo(2);
    set_servo_position(2,1047);


    printf("object y = %d",get_object_center_y(green,0));

    int y=get_servo_position(2);

    while(1)
    {

        camera_update();
        //adjustment_for_y =0;
        if (get_object_count(green)>1)
        { }
        if (get_object_count (green)>0)
        { 
            y= y+ 1.55*(80-get_object_center_x(green,0));
            if (y>2047){y=2047;}
            //y= y- 2.55*(80+get_object_center_x(green,0));
            //y =y - (80+get_object_center_x(green,0));
            set_servo_position(2,y);

        }

    }
}
int combined()
{  
    int y=60;
    int n=0;
    // int q = systime();
    printf("object y = %d",get_object_center_y(green,0));
    int adjustment_for_y =0;//follow object
    enable_servo(2);
    set_servo_position(2,1047);
    //int n=0;
    int q = systime();
    printf("object y = %d",get_object_center_y(green,0));
    //int adjustment_for_y =0;
    //int y=get_servo_position(2);//rotate object
    while(n<7)
    {camera_update();
     msleep(0);
     if(get_object_center_x(0,0)>0)
     {
         printf("confidence=%f\n",get_object_confidence(blue,0));
         int w = systime()-q;
         printf("total time=%d\n",w);
         return get_object_center_x(green,0);
     }
     n=n+1;
    }
    y=40;
    while(1)
    {

        camera_update();
        adjustment_for_y =2*(88-get_object_center_y(green,0));

        if (get_object_count (green)>0)
        { motor(1,get_object_center_x(green,0)-80+adjustment_for_y);
         motor(0,80-get_object_center_x(green,0)+adjustment_for_y);}
        else
        { motor(0,0);
         motor(1,0);}

        //adjustment_for_y =0;
        if (get_object_count (green)>0)
        { 
            y= y+ 1.55*(80-get_object_center_x(green,0));}
        if(y>2047){y=2047;}
        if(y<0){y=0;}
        set_servo_position(2,y);

    }

}


double new_calibrate_y(){



    int bias1 = gyro_y();  
    msleep(10);
    int bias2 = gyro_y();  
    msleep(10);
    int bias3 = gyro_y();  
    msleep(10);
    int bias4 = gyro_y();  
    msleep(10);
    int bias5 = gyro_y();  
    msleep(10);
    int bias6 = gyro_y();  
    msleep(10);
    int bias7 = gyro_y();  
    msleep(10);
    int bias8 = gyro_y();  
    msleep(10);
    int bias9 = gyro_y();  
    msleep(10);
    int bias10 = gyro_y();  
    msleep(10);
    int bias11 = gyro_y();  
    msleep(10);
    int bias12 = gyro_y();  
    msleep(10);
    int bias13 = gyro_y();  
    msleep(10);
    int bias14 = gyro_y();  
    msleep(10);
    int bias15 = gyro_y();  
    msleep(10);
    int bias16 = gyro_y();  
    msleep(10);
    int bias17 = gyro_y();  
    msleep(10);
    int bias18 = gyro_y();  
    msleep(10);
    int bias19 = gyro_y();  
    msleep(10);
    int bias20 = gyro_y();  
    msleep(10);
    double total_bias = bias1 + bias2 + bias3 + bias4 + bias5 + bias6 + bias7 + bias8 + bias9 + bias10 + bias11 + bias12 + bias13 + bias14 + bias15 + bias16 + bias17 + bias18 + bias19 + bias20;
    double bias_y = total_bias*0.05;


    printf(" new bias: %.2f ", bias_y);
    printf(" total bias: %f ", total_bias);

    FILE * file3= fopen("BIAS1.txt", "w"); 
    fprintf(file3, "%f",bias_y);
    fclose(file3);
    return 0;   

}

double new_calibrate_z(){



    int bias1 = gyro_z();  
    msleep(10);
    int bias2 = gyro_z();  
    msleep(10);
    int bias3 = gyro_z();  
    msleep(10);
    int bias4 = gyro_z();  
    msleep(10);
    int bias5 = gyro_z();  
    msleep(10);
    int bias6 = gyro_z();  
    msleep(10);
    int bias7 = gyro_z();  
    msleep(10);
    int bias8 = gyro_z();  
    msleep(10);
    int bias9 = gyro_z();  
    msleep(10);
    int bias10 = gyro_z();  
    msleep(10);
    int bias11 = gyro_z();  
    msleep(10);
    int bias12 = gyro_z();  
    msleep(10);
    int bias13 = gyro_z();  
    msleep(10);
    int bias14 = gyro_z();  
    msleep(10);
    int bias15 = gyro_z();  
    msleep(10);
    int bias16 = gyro_z();  
    msleep(10);
    int bias17 = gyro_z();  
    msleep(10);
    int bias18 = gyro_z();  
    msleep(10);
    int bias19 = gyro_z();  
    msleep(10);
    int bias20 = gyro_z();  
    msleep(10);
    double total_bias = bias1 + bias2 + bias3 + bias4 + bias5 + bias6 + bias7 + bias8 + bias9 + bias10 + bias11 + bias12 + bias13 + bias14 + bias15 + bias16 + bias17 + bias18 + bias19 + bias20;
    double bias = total_bias*0.05;


    printf(" new bias: %.2f ", bias);
    printf(" total bias: %f ", total_bias);

    FILE * file3= fopen("BIAS.txt", "w"); 
    fprintf(file3, "%f",bias);
    fclose(file3);
    return 0;   

}
void drive_ET(int measure, int speed){
    
    FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);

    FILE *file992 = fopen("BackRightMotor.txt","r"); // left motor definition 
    char line3[16];
    while(fgets(line3, sizeof(line3),file992)){}

    msleep(5);
    fclose(file992);
    int backright_motor=atof(line3);

    printf("\n Back Right motor: %d", backright_motor);

    FILE *file993 = fopen("BackLeftMotor.txt","r"); // left motor definition 
    char line4[16];
    while(fgets(line4, sizeof(line4),file993)){}

    msleep(5);
    fclose(file993);
    int backleft_motor=atof(line4);

    printf("\n Back Left motor: %d ", backleft_motor);
   

    FILE *file15 = fopen("et.txt","r"); // left motor definition 
    char line25[16];
    while(fgets(line25, sizeof(line25),file15)){}
    msleep(5);
    fclose(file15);
    int et=atof(line25);

    printf(" \n et: %d ", et);


    //double bias2 = bias_placeholder;
    //unsigned long initial = systime();

    double theta = 0;



    if(analog(et) > measure)
    {
        while(analog(et)  > measure - 10)
        {

            mav(left_motor,-1 * speed - theta * .0001);
            mav(right_motor,-1 * speed + theta * .0001);

            mav(backleft_motor, -1*speed - .0001 * theta );
            mav(backright_motor, -1*speed + .0001 * theta);

            theta += 2*(gyro_z()-bias_placeholder);
            msleep(5);
            // im gay - camden
        }
        msleep(5);
    }else{
        while(analog(et) < measure -10)
        {
            mav(left_motor, speed - .0001 * theta );
            mav(right_motor, speed + .0001 * theta);

            mav(backleft_motor, speed - .0001 * theta );
            mav(backright_motor, speed + .0001 * theta);

            theta += 2*(gyro_z()-bias_placeholder);
            msleep(5);

        }
        mav(left_motor,0);
        mav(right_motor,0);
        mav(backleft_motor, 0 );
        mav(backright_motor, 0);
        msleep(10);
    }
}
void turn1(int degrees)
{

   
   FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);

   

    double theta = 0;
    double target_theta = degrees *1000.0;
    //int angle_degrees = degrees;
    //double bias2 = bias1;
    short speed = locolib_gyro_turn_speed ;
    printf(" target_theta: %f ", target_theta);
    //theta += gyro_z() - bias2;
    // printf("Initial theta = %f",theta);
    msleep(50);
    if(degrees > 0)
    {
        while(theta < target_theta*.7 )//magic coefficient
        {
            msleep(10);
            mav(left_motor, speed + theta *0001);
            mav(right_motor, (speed*-1) - theta *0001);
            theta += gyro_z() - bias_placeholder;
        }
    }else {
        while(theta > target_theta* .7)
        {

            msleep(10);
            mav(left_motor,speed*-1 + theta *.0001);
            mav(right_motor,speed - theta*0001);
            theta += gyro_z() - bias_placeholder;
        }
    }
    printf(" theta: %.6f ", theta*.181812);

    mav(left_motor, 0);
    mav(right_motor, 0);
    msleep(50);

}
/////////////////////////////////////////////area of work above here



struct {
    short x,y,z;
}static locolib_gyro_bias;

struct {
    struct locolib_servo_entry *queue[4];
    unsigned int next_base_id, flags;
    mutex lock;
    thread thread;
}static locolib_servos = {
    .queue = {NULL,NULL,NULL},
    .next_base_id = 0
};

struct locolib_servo_entry {
    struct locolib_servo_entry *prev, *next;
    unsigned long start_ms, end_ms;
    unsigned int id;
    unsigned short start_pos, end_pos, flags;
};

//// ==== ==== ==== ==== ==== ==== ==== ==== ====

static void *safe_malloc(size_t size) {
    void *pntr = malloc(size);
    if(pntr)
        return pntr;
    // exit if malloc was unsucessfull
    printf("out of memory!\n");
    exit(EXIT_FAILURE);
}

void motor_motor(int left_mav, int right_mav) {
    mav(motors.left,   left_mav);
    mav(motors.right, right_mav);
    return;
}

unsigned int milliseconds() {
    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);
    return (now.tv_sec*1000) + (now.tv_nsec/1000000);
}

/* pid_create_integer()
| Initialize the P,I,and D values of
| the pid_int struct type. 
| Returns a pointer to the allocated struct
*/
struct pid_struct* pid_create(float p, float i, float d) {
    // Allocate and set numbers
    struct pid_struct* pid = safe_malloc(sizeof(struct pid_int));
    *pid = (struct pid_struct){
        .p=p, .i=i, .d=d, 
        .i_sum=0, 
        .error_prev=0, 
        .now_prev=milliseconds()
    };
    // Return a pointer to the pid struct on the heap
    return pid;
}

/* pid_calculate_complex()
| calculates a more configurable pid
| compared to more boilerplate pid calculations
*/
double pid_calculate_complex(
    struct pid_struct *pid, 
    double setpoint, 
    double process_var, 
    float min, 
    float max, 
    float i_min, 
    float i_max
            ) {
                unsigned long now = milliseconds();
                unsigned long deriv_now = now - pid->now_prev;
                long error = setpoint - process_var;
                long deriv_error = error - pid->error_prev;

                pid->now_prev = now;
                pid->error_prev = error;
                pid->i_sum += error * deriv_now * pid->i;

                if(pid->i_sum > i_max)
                    pid->i_sum = i_max;
                if(pid->i_sum < i_min)
                    pid->i_sum = i_min;

                double output = (error * pid->p) + pid->i_sum;

                if (0 != deriv_now) 
                    output= output - (deriv_error * pid->d);

                if(output < min) 
                    output = min;
                if(output > max)
                    output = max;

                return output;
            }

            /* pid_destroy()
| frees the allocated memory that a pid used
*/
            void pid_destroy(struct pid_struct *pid) {	//< Reminder function to clean up the pid
                free(pid);
                return;
            }

            //// ==== ==== ==== ==== ==== ==== ==== ==== ====

            int gyro_x_bias() {
                return gyro_axis_left_right() - locolib_gyro_bias.x;   
            }
            int gyro_y_bias() {
                return gyro_axis_forward_back() - locolib_gyro_bias.y;
            }
            int gyro_z_bias() {
                printf("%d	", gyro_axis_up_down() - locolib_gyro_bias.z);
                return gyro_axis_up_down() - locolib_gyro_bias.z;
            }

            /* calibrate_gyro()
| Call at the beginning of the program to calibrate locolib_gyro_bias
*/
            double calibrate_gyro() {


    //double bias2 = bias_placeholder;
              int i, loops = 100;
                // Get Sum over a duration
                for(i=0;i<loops;i++) {
                    locolib_gyro_bias.z += gyro_axis_up_down();
                    //locolib_gyro_bias.x  += gyro_axis_left_right();
                    //locolib_gyro_bias.y  += gyro_axis_forward_back();
                    msleep(7);
                };
                // Divide by the number of additions to get average
                locolib_gyro_bias.z /= loops;
                //locolib_gyro_bias.x /= loops;
                //locolib_gyro_bias.y /= loops;
                //locolib_gyro_bias.z = 30;

                //const  double bias2 = locolib_gyro_bias.z;

                //printf("bias: %f\n",bias2);
                return 0;
            }

            //// ==== ==== ==== ==== ==== ==== ==== ==== ====

            static void locolib_servo_prepend(struct locolib_servo_entry *prependee, struct locolib_servo_entry *head) {
                prependee->next = head;
                prependee->prev = head->prev;
                head->prev = prependee;
                if(NULL != prependee->prev)
                    prependee->prev->next = prependee;
                return;
            }

            static void locolib_servo_append(struct locolib_servo_entry *appendee, struct locolib_servo_entry *head) {
                appendee->prev = head;
                appendee->next = head->next;
                head->next = appendee;
                if(NULL != appendee->next )
                    appendee->next->prev = appendee;
                return;
            }

            static void locolib_servo_remove(struct locolib_servo_entry *removee) {
                if(NULL != removee->prev) 
                    removee->prev->next = removee->next;
                if(NULL != removee->next)
                    removee->next->prev = removee->prev;
                removee->next = removee;
                removee->prev = removee;
                return;
            }

            //// ==== ==== ==== ==== ==== ==== ==== ==== ====

            //user side flags defined in the .h component
            #define smart_servo_flags_servos_enabled 0x1000
            #define smart_servo_mask_servos_enabled 0xF000

            #define smart_servo_flags_thread_running 0x800

            /* smart_servo_update_position()
| Private function used to update the position of
| a given servo port agnostic to time between calls
*/
            static void smart_servo_update_position(int port) {
                mutex_lock(locolib_servos.lock);
                unsigned int now = milliseconds();
                while(1) {
                    // Get an entry
                    struct locolib_servo_entry *entry = locolib_servos.queue[port];
                    if (NULL == entry) 
                        break;

                    if (now < entry->start_ms)
                        break;

                    // Cleanup entry if the end time has passed
                    if (now > entry->end_ms) {
                        if (entry == entry->next) {
                            locolib_servos.queue[port] = NULL;
                        } else {
                            locolib_servos.queue[port] = entry->next;
                        }
                        locolib_servo_remove(entry);
                        set_servo_position(port, entry->end_pos);
                        // TODO: add in if for smart_servo_flags_servo_sleepy
                        free(entry);
                        break;
                    }
                    // Pull values from the element, normalize time to a 0-1(start-end) value
                    unsigned int flags = locolib_servos.flags ^ entry->flags;
                    float normalized_time = (now - entry->start_ms) / (float)(entry->end_ms - entry->start_ms);

                    // Enable servo if servo's enable flag not raised
                    if( 0 == (smart_servo_flags_servos_enabled<<port & flags & smart_servo_mask_servos_enabled)) {
                        enable_servo(port);
                        locolib_servos.flags |= smart_servo_flags_servos_enabled<<port;
                    }
                    // Get start_pos if undeclared(0xAAAA)
                    if(0xAAAA == entry->start_pos) {
                        entry->start_pos = get_servo_position(port);
                    }

                    // Calculate and set position
                    int new_position = normalized_time * (entry->end_pos - entry->start_pos) + entry->start_pos;
                    set_servo_position(port, new_position);
                    break;
                }
                mutex_unlock(locolib_servos.lock);
                return;
            }

            /* smart_servo_thread()
| Private function that is used as the main thread
| of smart_servo and should only be called once
*/
            static void smart_servo_thread() {
                // Set thread running flag to on if the flag isn't already set
                if(locolib_servos.flags & smart_servo_flags_thread_running) return;
                locolib_servos.flags |= smart_servo_flags_thread_running;
                int port;
                // Update Servo positions every 10ms, function is time agnostic
                while(1) {
                    msleep(10);
                    for(port=0;port<4;port+=1) {
                        smart_servo_update_position(port);   
                    }
                }
                // In the case of loop exiting (which should be impossible) print debug statement
                printf("\nUNREACHABLE: smart_servo_thread has exited the loop\n\n");
                // Make inverse of flag(mask) to disable the thread running flag
                locolib_servos.flags &= ~smart_servo_flags_thread_running;
                return;
            }

            static void smart_servo_initialize() {
                // Check that everything is initialized
                //if(locolib_servos.thread == (thread)0)


                if(locolib_servos.flags & smart_servo_flags_thread_running)
                    return;
                locolib_servos.thread = thread_create(smart_servo_thread);
                thread_start(locolib_servos.thread);
                locolib_servos.lock = mutex_create();

                return;
            }

            /* smart_servoX()
| Use smart_servo(), not smart_servoX()! 
| Smart_servo() has the same perameters, but enables variadic perameter
| functionality: the rightmost perameters can be left off and ignored. 
| The definition of smart_servo() is in the .h sibling of this file
> Used to control servos within a set range and enable slower and delayed movements
*/
            unsigned int smart_servoX(unsigned short port, short percent, unsigned long duration, unsigned long delay, unsigned short flags) {
                smart_servo_initialize();

                // Calculate end position of the servo
                unsigned short end_pos = ((servos.max[port] - servos.min[port])*percent)/100 + servos.min[port];

                // Set values of entry, which is on the heap
                unsigned long now = milliseconds();
                struct locolib_servo_entry *entry = safe_malloc(sizeof(struct locolib_servo_entry));
                *entry = (struct locolib_servo_entry) {						
                    .next = entry,
                    .prev = entry,
                    .start_ms = now + delay,
                    .end_ms = now + delay + duration,
                    .id = locolib_servos.next_base_id + (port & 0x3),
                    .start_pos = 0xAAAA,
                    .end_pos = end_pos,
                    .flags = flags
                };
                // Increment id
                locolib_servos.next_base_id += 4;

                // Grab the lock to start searching through the queue
                mutex_lock(locolib_servos.lock);
                struct locolib_servo_entry *head = locolib_servos.queue[port];

                // Case if queue is empty
                if (NULL == head) {						
                    locolib_servos.queue[port] = entry;
                }

                // Case if appending to end of queue fits
                else if (head->prev->start_ms < entry->start_ms) {
                    locolib_servo_prepend(entry,head);
                }
                /*else if (head->start_ms > entry->start_ms){
        locolib_servo_prepend(entry,head);
        locolib_servos.queue[port] = entry;
    }*/

                // Else case of searching through queue
                else {
                    struct locolib_servo_entry *itterator = head;
                    while(itterator != head) {
                        if(itterator->start_ms < entry->start_ms && 
                           itterator->next->start_ms > entry->start_ms) {
                            break;
                        }
                        itterator=itterator->next;
                    }
                    locolib_servo_append(entry,itterator);
                }
                // Release lock and return
                mutex_unlock(locolib_servos.lock);

                // TODO: add in loop for smart_servo_flags_servo_blocking
                return entry->id;
            }

            /* smart_servo_search_id
| Searches through the servo queue for the first element 
| with the given id and its pointer is returned
| The id to provide is the return of the smart_servo function
| Function returns NULL if the given id is unable to be found
> Primary usecase is to await the completion of an id via searching for it
*/
            struct locolib_servo_entry* smart_servo_search_id(unsigned int id) {
                short port = id % 4;
                struct locolib_servo_entry *head = locolib_servos.queue[port];
                // Check if queue doesn't have entries
                if (NULL == head) {
                    return NULL;   
                }
                // Check the head of list
                if(id == head->id) {
                    return head;
                }

                // Search through queue
                struct locolib_servo_entry *itterator = head->next;
                while (itterator != head) {
                    if (itterator->id == id) {
                        return itterator;
                    }
                    itterator = itterator->next;	
                }
                // return NULL as id wasn't found
                return NULL;
            }

            /* smart_servo_document_queue
| Prints out a list of all elements in each servo's
| queue in the order that they will be executed in
> Primarily for debugging of queue
*/
            void smart_servo_document_queue() {
                int port;
                struct locolib_servo_entry *head, *itterator;

                // Grab the lock for reading
                mutex_lock(locolib_servos.lock);		
                for(port=0;port<4;port+=1) {			
                    // Begin line
                    printf("port %d:",port);			
                    head = locolib_servos.queue[port];

                    // Next line if queue is empty, skipping to next port
                    if(NULL == head) {
                        printf("\n");
                        continue;
                    }
                    // Print id of head in queue
                    printf(" %d",head->id);
                    itterator = head->next;

                    // Loop through queue while printing
                    while(head != itterator) {
                        printf(", %d", itterator->id);
                        itterator = itterator->next; 
                    }
                    // End printline
                    printf("\n");
                }
                // Release the lock
                mutex_unlock(locolib_servos.lock);
            }

            // Increase width to turn more, decrease for less
            #define locolib_demobot_wheel_width 7.8
void demo_gyro_turn(short angle_degrees, float radius) {
 		FILE *file3 = fopen ("BIAS.txt","r");
   char line[16];
    while(fgets(line, sizeof(line),file3))

    {printf("%s is BIAS", line);}
    fclose(file3);
   double bias_placeholder=atof(line);
 // double bias2 = bias_placeholder;
  printf("  %f as a decimal BIAS", bias_placeholder);


              //  int bias2 = 0.5;
                short speed = locolib_gyro_turn_speed ;
                unsigned long panic_milliseconds = abs(angle_degrees) * 20 + 800 + fabs(radius) * 200;

                // sleep proven to help accuracy of turns
                msleep(40);

                struct side {float speed_modifier; unsigned int port;};
                struct side outter = {
                    .port = ((angle_degrees > 0) ? motors.left : motors.right), 
                    .speed_modifier = sign(angle_degrees) * sign(radius)
                };
                struct side inner =  {
                    // 2*(r-w) / 2*r
                    .port = ((angle_degrees > 0) ? motors.right : motors.left),
                    .speed_modifier = ((fabs(radius)-locolib_demobot_wheel_width) / locolib_demobot_wheel_width) * sign(angle_degrees) * sign(radius)
                };

                unsigned long start = milliseconds();
                unsigned long accel_end = start + abs(speed)/25;

                int target_theta = angle_degrees * locolib_gyro_turn_degree_theta_ratio ;

                struct pid_struct *pid = pid_create(
                    0.1 + fabs(radius) * 0.01, 
                    0,
                    0.065
                );

                float tolerance_theta = 0;
                float pid_out;
                int theta = 0 - bias_placeholder;           //////////////////// RIGHT HERE OWEN 
                unsigned long now;
                speed = abs(speed);

                int max = 0;

                while (
                    // Within tolerance of target
                    (theta > target_theta + tolerance_theta || theta < target_theta - tolerance_theta) ||
                    // Current speed unsafe to exit
                    abs(gyro_z_bias()) > 200
                ) {
                    msleep(10);

                    now = milliseconds();
                    pid_out = pid_calculate_complex(pid, target_theta, theta, -speed,speed, -abs(pid_out),abs(pid_out));

                    if(accel_end > now)
                        pid_out *= (float)(now-start) / (accel_end-start);

                    mav(inner.port, pid_out * inner.speed_modifier );
                    mav(outter.port,pid_out * outter.speed_modifier);

                    theta += gyro_z()-bias_placeholder * sign(radius);

                    if(panic_milliseconds < now - start) {
                        printf("\ndemo_gyro_turn - exit: PANIC MILLISECONDS REACHED\n");
                        // exit(EXIT_FAILURE);
                    }


                    if(gyro_z_bias() > max)
                        max = gyro_z_bias();
                }
                printf("tolerance: %f\n",tolerance_theta);
                free(pid);
                freeze(inner.port);
                freeze(outter.port);
                msleep(20);
            }

            void demo_gyro_drive(int target_mav_speed, double duration_sec, int_func exit_condition)
            {
                duration_sec = fabs(duration_sec);
                int sign_speed = sign(target_mav_speed);
                double start_sec = seconds();
                double accel_duration_sec = abs(target_mav_speed)*0.0003;

                int run_speed = 0 , theta = 0;
                while(1) {
                    run_speed = target_mav_speed;
                    if( seconds() - start_sec < accel_duration_sec )
                        run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec );

                    mav(motors.left, run_speed + run_speed*theta*sign_speed/10000);
                    mav(motors.right,run_speed - run_speed*theta*sign_speed/10000);
                    msleep(10);
                    theta += gyro_z()-2;//this number is wombat specific//this is the bias #

                    //  printf(""); // This fixes a random gyro drift on 2844

                    if(exit_condition != NULL && exit_condition() != 0) break;
                    if(seconds()-start_sec > duration_sec) {
                        if(exit_condition == NULL) break;
                        printf("Exit condition not reached! spd: %d, dist: %f\n", target_mav_speed, duration_sec);
                        exit(EXIT_FAILURE);
                    }
                }
                freeze(motors.left);
                freeze(motors.right);
                printf("dist: %f, spd: %d, start: %f\n",duration_sec,target_mav_speed,start_sec);
            }




void demo_gyro_square_up(int speed) 
{

    

    int theta=0; //sign_speed = sign(speed);
    //
    FILE *file11= fopen ("ITL.txt","r");
    char line[16];
    while(fgets(line, sizeof(line),file11)){}

    msleep(5);
    fclose(file11);
    double itr1=atof(line);
    int itl = itr1-0;
    printf("\n ITL: %d", itl);
    //
    FILE *file13= fopen ("ITR.txt","r");
    char line0[16];
    while(fgets(line0, sizeof(line0),file13))
    {printf("%s is ITR", line0);}

    msleep(5);
    fclose(file13);
    double it1=atof(line0);
    int itr = it1-0;

    printf("\n ITR: %d", itr);

    FILE * file14 = fopen("rmidpoint", "r"); 
    char line9[16];
    while(fgets(line9, sizeof(line9),file14)){}

    msleep(5);
    fclose(file14);
    int rmidpoint=atof(line9);

    printf("\n rmidpoint before declaration: %s", line9);
    printf("\n rmidpoint: %d",rmidpoint);

    FILE * file16 = fopen("lmidpoint", "r"); 
    char line5[16];
    while(fgets(line5, sizeof(line5),file16)){}

    msleep(5);
    fclose(file16);
    int lmidpoint=atof(line5);

    printf(" \n lmidpoint: %d", lmidpoint);
    //
    //int right_invert = ron_black(itr);
    // int left_invert = lon_black(itl);
    
    FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);

    FILE *file992 = fopen("BackRightMotor.txt","r"); // left motor definition 
    char line3[16];
    while(fgets(line3, sizeof(line3),file992)){}

    msleep(5);
    fclose(file992);
    int backright_motor=atof(line3);

    printf("\n Back Right motor: %d", backright_motor);

    FILE *file993 = fopen("BackLeftMotor.txt","r"); // left motor definition 
    char line4[16];
    while(fgets(line4, sizeof(line4),file993)){}

    msleep(5);
    fclose(file993);
    int backleft_motor=atof(line4);

    printf("\n Back Left motor: %d ", backleft_motor);
    //replace these numbers with file pull



    // Gyro drive till any hit black
    while( analog(itl)<lmidpoint && analog(itr)<rmidpoint ) 
    {
        if(speed > 0){
            mav(left_motor, (speed - 0.1*(speed * (theta *.0001))));            
            mav(right_motor, (speed + 0.1*(speed * theta *.0001)));
            //mav(backleft_motor, speed);            
            // mav(backright_motor,speed);
            mav(backleft_motor, (speed - 0.1*(speed * (theta *.0001))));            
            mav(backright_motor, (speed + 0.1*(speed * theta *.0001)));
        }


        else{
            mav(left_motor, (speed + 0.1*(speed * (theta *.0001))));            
            mav(right_motor, (speed - 0.1*(speed * theta *.0001)));
            //mav(backleft_motor, speed);            
            // mav(backright_motor,speed);
            mav(backleft_motor, (speed + 0.1*(speed * (theta *.0001))));            
            mav(backright_motor, (speed - 0.1*(speed * theta *.0001)));

        }

        msleep(10);
        theta += (gyro_z() - bias_placeholder) * 2;
    }
    printf("black hit\n");
    while(analog(itl)>lmidpoint || analog(itr)>rmidpoint)
    {
        if(analog(itl)>lmidpoint) {mav(left_motor, -.25*speed); mav(backleft_motor,  -.25*speed); printf("\n Left hit");} 
        else {mav(left_motor, -.5); mav(backleft_motor,  .5);}

        if(analog(itr)>rmidpoint) {mav(right_motor,  -.25*speed); mav(backright_motor,  -.25*speed); printf("\n right Hit");}
        else {mav(right_motor, -.5); mav(backright_motor,  .5);}
        msleep(2);
        
        if(analog(itl) < lmidpoint && analog(itr) < rmidpoint)
        {
         	break;   
        }
    }

    // Align sensors with line

    //////and then stop
    freeze(left_motor);
    freeze(right_motor);
    freeze(backleft_motor);
    freeze(backright_motor);

    printf("squared up: %ums\n", milliseconds());


    msleep(10);
}













void one_wheel_turn(int wheel, int degree)
{
    FILE *file10 = fopen ("BIAS.txt","r");
    char line[16];
    while(fgets(line, sizeof(line),file10))

    {printf("%s is BIAS", line);}
    fclose(file10);
    double bias_placeholder=atof(line);
    printf("  %f as a decimal BIAS", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line, sizeof(line1),file999))

    {printf("%s is Left Motor\n", line);}
    fclose(file999);
    int left_motor=atof(line1);

    printf(" %d ", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998))

    {printf("%s is Right Motor\n", line2);}
    fclose(file998);
    int right_motor=atof(line2);

    printf(" %d ", right_motor);



    // double bias2 = bias_placeholder;
    cmpc (right_motor);
    cmpc (left_motor);
    int GOD_ticks=degree*0.0027778*bias.lm*43.2;
    printf("GOD_ticks = %d",GOD_ticks);
    short speed = locolib_gyro_turn_speed ;
    if(wheel==Left)//if left wheel
    {
        if(degree>0)
        {
            while(gmpc(left_motor)<GOD_ticks)
            {
                mav(left_motor,speed);
                mav(right_motor,0);
                msleep(10);
            }
            mav(left_motor,0);
            msleep(30);
        }
        else
        {
            while(gmpc(left_motor)  > GOD_ticks  )
            {
                printf( " %d/n ", gmpc(left_motor));
                mav(left_motor,speed * -1);
                mav(right_motor,0);
                msleep(10);
            }
            mav(left_motor,0);
            msleep(30);
        }
    }
    else//else right wheel
    {
        if(wheel==Right){
            if(degree>0){
                while(gmpc(right_motor)<GOD_ticks){
                    mav(right_motor,speed);
                    mav(left_motor,0);
                    msleep(10);
                }
                mav(right_motor,0);
                msleep(30);
            }
            else{
                while(gmpc(left_motor)  > GOD_ticks  )
                {
                    printf( " %d/n ", gmpc(left_motor));
                    mav(left_motor,speed * -1);
                    mav(right_motor,0);
                    msleep(10);
                }
                mav(left_motor,0);
                msleep(30);
            }
        }
    }
}

/////drive follows

void Drive(int target_mav_speed,double inches)

{
    //here

    FILE * file969= fopen("l_average", "r"); 
    char line6[16];
    while(fgets(line6, sizeof(line6),file969)){}
    
    msleep(5);
    fclose(file969);
    
    int left_average=atof(line6);
    printf(" \n left average: %d ", left_average);

    

    FILE * file970= fopen("r_average", "r"); 
    char line7[16];
    while(fgets(line7, sizeof(line7),file970)){}
    
    msleep(5);
    fclose(file970);
    int right_average=atof(line7);
    printf("\n right average:  %d", right_average);

   
   FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);
    

   

    //double bias2 = bias_placeholder;
    // printf(" new new bias %f ", bias2);

    if(target_mav_speed == turn)
    {
        turn1(inches);
    }
    else if(target_mav_speed == square_up)
    {
        demo_gyro_square_up(inches);
        Drive(-1*inches,.75);
        demo_gyro_square_up(inches);
    }
    else
    {



        cmpc(left_motor);
        cmpc(right_motor);
        //  	double inches = abs(inches);
        //double duration_sec = fabs(duration_sec);
        int sign_speed = sign(target_mav_speed);
        double start_sec = seconds();
        double accel_duration_sec = abs(target_mav_speed)*0.0003;
        int ticks_left = inches * right_average;

        int run_speed = 0 ;
        double theta = 0.00;
        ticks_left = ticks_left*.979; // magic coefficient


        if(target_mav_speed<0 || inches<0)//backward movement DON'T TOUCH
        {	//DON'T TOUCH
            // double inches = abs(inches);
            if(target_mav_speed > 0)
            {
                if(target_mav_speed>0){target_mav_speed=target_mav_speed*-1;}//-1}

            }
            if(ticks_left>0){ticks_left=ticks_left*-1;}//-1


            //DON'T TOUCH

            if(1)
            {
                printf("ticks_left = %d",ticks_left);
                //printf("run_speed = %d\n", run_speed);
                while(gmpc(left_motor) > (ticks_left)) //DON'T TOUCH hhh
                { //DON'T TOUCH


                    //run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec ); //DON'T TOUCH
                    run_speed =target_mav_speed;
                    printf("run_speed = %d\n", run_speed);
                    mav(left_motor, run_speed + run_speed*theta*0.0001); //DON'T TOUCH
                    mav(right_motor,run_speed - run_speed*theta*0.0001); //DON'T TOUCH
                    msleep(10); //DON'T TOUCH
                    //DON'T TOUCH
                    printf(" theta %f ", theta);

                    // printf(" %d ", gmpc(left_motor));
                } //DON'T TOUCH
                //printf("bias2 =%f",bias2);



                //motor(right_motor, 0);//this is a placeholder
                //motor(left_motor, 0);
                //msleep(10); 


            } //DON'T TOUCH
            motor(left_motor, 0);///
            motor(right_motor, 0);///
            msleep(30);
        }
        else//////////////////////////////////////////////////////////////////////////////////////////////
        {                                                                                              ///
            printf("moving forward");///
            while(gmpc(left_motor)<(ticks_left ))                                                  ///
            { ///
                //printf(" bias is: %f  ", bias2); ///
                ///
                run_speed = target_mav_speed; ///
                if( seconds() - start_sec < accel_duration_sec )///
                    run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec );///
                ///
                mav(left_motor, run_speed - run_speed*theta*sign_speed/10000);///
                mav(right_motor,run_speed + run_speed*theta*sign_speed/10000);///
                msleep(10);///
                theta += (gyro_z()-bias_placeholder) * 2;///
                ///
            }///
            /*printf("entering deceleration");///
            while(gmpc(left_motor)< (ticks_left-10)) //decellerate///
            {///
                run_speed = 19.16*(ticks_left-gmpc(left_motor))+70;///
                mav(left_motor, run_speed - run_speed*theta*sign_speed/10000);///
                mav(right_motor,run_speed + run_speed*theta*sign_speed/10000);///
                msleep(10);///
                theta += (gyro_z()-bias_placeholder)*2;///
            }///
*/

        }///
    }///
    printf(" %d ", gmpc(right_motor));
    motor(right_motor, 0);///
    motor(left_motor, 0);///
    msleep(50);///
}


void four_wheel_drive(int target_mav_speed, double inches)
{

    FILE * file969= fopen("l_average", "r"); 
    char line6[16];
    while(fgets(line6, sizeof(line6),file969)){}
    
    msleep(5);
    fclose(file969);
    
    int left_average=atof(line6);
    printf(" \n left average: %d ", left_average);

    

    FILE * file970= fopen("r_average", "r"); 
    char line7[16];
    while(fgets(line7, sizeof(line7),file970)){}
    
    msleep(5);
    fclose(file970);
    int right_average=atof(line7);
    printf("\n right average:  %d", right_average);

   
   FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);

    FILE *file992 = fopen("BackRightMotor.txt","r"); // left motor definition 
    char line3[16];
    while(fgets(line3, sizeof(line3),file992)){}

    msleep(5);
    fclose(file992);
    int backright_motor=atof(line3);

    printf("\n Back Right motor: %d", backright_motor);

    FILE *file993 = fopen("BackLeftMotor.txt","r"); // left motor definition 
    char line4[16];
    while(fgets(line4, sizeof(line4),file993)){}

    msleep(5);
    fclose(file993);
    int backleft_motor=atof(line4);

    printf("\n Back Left motor: %d ", backleft_motor);




    cmpc(left_motor);
    cmpc(right_motor);
    //double inches = abs(inches);
    //double duration_sec = fabs(duration_sec);
    int sign_speed = sign(target_mav_speed);
    double start_sec = seconds();
    double accel_duration_sec = abs(target_mav_speed)*0.0003;
    int ticks_left = inches * right_average;

    int run_speed = 0 ;
    double theta = 0.00;
    ticks_left = ticks_left*.979; // magic coefficient


    if(target_mav_speed<0 || inches<0)//backward movement DON'T TOUCH
    {	//DON'T TOUCH
        inches = abs(inches);
        if(target_mav_speed > 0)
        {
            if(target_mav_speed>0){target_mav_speed=target_mav_speed*-1;}//-1}

        }
        if(ticks_left>0){ticks_left=ticks_left*-1;}//-1


        //DON'T TOUCH

        if(1)
        {
            printf("ticks_left = %d",ticks_left);
            //printf("run_speed = %d\n", run_speed);
            while(gmpc(left_motor) > (ticks_left)) //DON'T TOUCH hhh
            { //DON'T TOUCH


                //run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec ); //DON'T TOUCH
                run_speed =target_mav_speed;
                printf("run_speed = %d\n", run_speed);
                mav(left_motor, run_speed + run_speed*theta*0.0001); //DON'T TOUCH
                mav(right_motor,run_speed - run_speed*theta*0.0001); //DON'T TOUCH
                mav(backleft_motor, run_speed + run_speed* theta *.0001); //DON'T TOUCH
                mav(backright_motor,run_speed - run_speed *theta *.0001); //DON'T TOUCH
                msleep(10); //DON'T TOUCH
                //DON'T TOUCH
                printf(" theta %f ", theta);

                // printf(" %d ", gmpc(left_motor));
            } //DON'T TOUCH
            //printf("bias2 =%f",bias2);

            motor(left_motor, 0);///
            motor(right_motor, 0);///
            motor(backleft_motor, 0);///
            motor(backright_motor, 0);///
            msleep(30);

            motor(right_motor, 0);//this is a placeholder
            motor(left_motor, 0);
            msleep(10); 


        } //DON'T TOUCH
    }
    else//////////////////////////////////////////////////////////////////////////////////////////////
    {                                                                                              ///
        printf("moving forward");///
        while(gmpc(left_motor)<(ticks_left))                                                  ///
        { ///
            //printf(" bias is: %f  ", bias2); ///
            ///
            run_speed = target_mav_speed; ///
            if( seconds() - start_sec < accel_duration_sec )///
                run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec );///
            ///
            mav(left_motor, run_speed - run_speed*theta*sign_speed *.0001);///
            mav(right_motor,run_speed + run_speed*theta*sign_speed *.0001);///
            mav(backleft_motor, run_speed   - run_speed* theta *.0001);///
            mav(backright_motor,run_speed - run_speed *theta *.0001);///
            msleep(5);///
            theta += (gyro_z()-bias_placeholder) * 2;///
            ///
        }///
        printf("entering deceleration");///
        /* while(gmpc(left_motor)< (ticks_left-10)) //decellerate///
        {///
            run_speed = 19.16*(ticks_left-gmpc(left_motor))+70;///
            mav(left_motor, run_speed - run_speed*theta*sign_speed* .0001);///
            mav(right_motor,run_speed + run_speed*theta*sign_speed* .0001);///
            mav(backleft_motor, run_speed - theta *.0001);///
            mav(backright_motor,run_speed - theta *.0001);///
            msleep(5);///
            theta += (gyro_z()-bias_placeholder)*2;///
        }///
        */
        motor(right_motor, 0);///
        motor(left_motor, 0);///
        motor(backright_motor, 0);///
        motor(backleft_motor, 0);///
        msleep(10);///
    }///
}///


void omni_strafe(double degrees,double inches)

{

    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);
    msleep(100);


    FILE * file969= fopen("l_average", "r"); 
    char line6[16];
    while(fgets(line6, sizeof(line6),file969)){}
    
    msleep(5);
    fclose(file969);
    int left_average=atof(line6);
    printf("\n left average: %d ", left_average);

   

    FILE * file970= fopen("r_average", "r"); 
    char line7[16];
    while(fgets(line7, sizeof(line7),file970)){}
    
    msleep(5);
    fclose(file970);
    
    int right_average=atof(line7);
    printf("\n right average: %d", right_average);




    
    int ticks_left = inches * right_average;
    ticks_left = ticks_left * .979;

   

    
 FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);

    FILE *file992 = fopen("BackRightMotor.txt","r"); // left motor definition 
    char line3[16];
    while(fgets(line3, sizeof(line3),file992)){}

    msleep(5);
    fclose(file992);
    int backright_motor=atof(line3);

    printf("\n Back Right motor: %d", backright_motor);

    FILE *file993 = fopen("BackLeftMotor.txt","r"); // left motor definition 
    char line4[16];
    while(fgets(line4, sizeof(line4),file993)){}

    msleep(5);
    fclose(file993);
    int backleft_motor=atof(line4);

    printf("\n Back Left motor: %d ", backleft_motor);

    double theta = 0;
    theta = 2*(gyro_x() - bias_placeholder);





    printf(" \n hello");
    if(abs(degrees) == 90.0)
    {
        printf("degrees: %f \n", degrees);
        if(degrees<0.0)
        {
            cmpc(0);
            cmpc(1);
            cmpc(2);
            cmpc(3);
            printf("hi\n");

            while(abs(gmpc(right_motor)) < ticks_left)
            {

                mav(right_motor, -1200 + 1200 * theta *.001);
                mav(backright_motor, 1200 - 1200 * theta *.001);

                mav(left_motor, 1200 + 1200 * theta *.001);
                mav(backleft_motor,  -1200 -  1200 * theta *.001);
                theta= 2*(gyro_x() - bias_placeholder);
                msleep(10);


            }
            freeze(left_motor);
            freeze(backleft_motor);
            freeze(right_motor);
            freeze(backright_motor);
            msleep(50);
        }else if(degrees>0.0){
            printf("hi pt.2 \n");

            printf("motor right: %d\n", gmpc(right_motor));
            printf("ticks left: %d\n", ticks_left);
            while(abs(gmpc(right_motor)) < ticks_left)
            {


                mav(right_motor, 1200 - 1200 * theta *.001);
                mav(backright_motor, -1200 - 1200 * theta *.001);

                mav(left_motor, -1200 + 1200 * theta *.001);
                mav(backleft_motor,  1200 +  1200 * theta *.001);
                theta= 2.5*(gyro_x() - bias_placeholder);
                msleep(10); 
            }
            freeze(left_motor);
            freeze(backleft_motor);
            freeze(right_motor);
            freeze(backright_motor);
            msleep(50);
        }
    }
    else if(abs(degrees) == 45)
    {
        printf("hello");
        if(inches > 0)
        {

            if(degrees > 0)
            {

                while(gmpc(right_motor) < ticks_left)
                {

                    mav(right_motor, 1200 + 1200 *theta *.0001); 
                    mav(backleft_motor,1200 - 1200*theta*.0001);
                    theta = 2*(gyro_z() - bias_placeholder);
                    msleep(10);
                }
                freeze(right_motor);
                freeze(backleft_motor);
                msleep(50);
            }else if(degrees < 0)
            {


                while(abs(gmpc(left_motor)) < ticks_left)
                {

                    mav(left_motor, 1200 + (1200 *theta *.0001));
                    mav(backright_motor, 1200 - (1200 *theta*.0001));
                    theta = 2*(gyro_z() - bias_placeholder);
                    msleep(10);
                }
                freeze(left_motor);
                freeze(backright_motor);
                msleep(50);
            }
        }
        else if(inches < 0)
        {
            if(degrees > 0)
            {



                while(gmpc(right_motor) > ticks_left)
                {

                    mav(right_motor, -1200 + (1200 *theta *.0001)); 
                    mav(backleft_motor, -1200 - (1200*theta*.0001));
                    theta = 2*(gyro_z() - bias_placeholder);
                    msleep(10);
                }

                freeze(right_motor);
                freeze(backleft_motor);
                msleep(50);
            }
            else if(degrees < 0)
            {
                printf("negative, negative");
                while(gmpc(left_motor) > ticks_left )
                {

                    mav(left_motor, -1200 + (1200 *theta *.0001)); 
                    mav(backright_motor, -1200 - (1200*theta*.0001));
                    theta = 2*(gyro_z() - bias_placeholder);
                    msleep(10);
                } 
                freeze(left_motor);
                freeze(backright_motor);
                msleep(50);
            }
        }



    }

    mav(left_motor, 0);
    mav(right_motor, 0);
    mav(backleft_motor, 0);
    mav(backright_motor, 0);
    msleep(50);
}
void four_turn(double degrees)
{
    FILE *file3 = fopen ("BIAS.txt","r");
    char line12[16];
    while(fgets(line12, sizeof(line12),file3)){}

    msleep(5);
    fclose(file3);
    double bias_placeholder=atof(line12);
    printf("\n Bias: %f", bias_placeholder);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999)){}

    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf("\n Left motor: %d", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998)){}

    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" Right Motor: %d ", right_motor);

    FILE *file992 = fopen("BackRightMotor.txt","r"); // left motor definition 
    char line3[16];
    while(fgets(line3, sizeof(line3),file992)){}

    msleep(5);
    fclose(file992);
    int backright_motor=atof(line3);

    printf("\n Back Right motor: %d", backright_motor);

    FILE *file993 = fopen("BackLeftMotor.txt","r"); // left motor definition 
    char line4[16];
    while(fgets(line4, sizeof(line4),file993)){}

    msleep(5);
    fclose(file993);
    int backleft_motor=atof(line4);

    printf("\n Back Left motor: %d ", backleft_motor);

    double theta = 0;
    double target_theta = degrees *1000.0;
    //int angle_degrees = degrees;
    //double bias2 = bias1;
    short speed = locolib_gyro_turn_speed ;
    printf("\n target_theta: %f ", target_theta *.7);
    //theta += gyro_z() - bias2;
    // printf("Initial theta = %f",theta);
    msleep(50);

    if(degrees > 0)
    {
        while(theta < target_theta*.7 )//magic coefficient
        {
            printf("\n Theta: %f ", theta);
            msleep(10);
            mav(left_motor, speed);
            mav(right_motor, (speed*-1));
            mav(backleft_motor, speed);
            mav(backright_motor, (speed*-1));
            theta += 1.11*(gyro_z() - bias_placeholder);
        }
    }else {
        while(theta > target_theta* .7)
        {

            msleep(10);
            mav(left_motor,speed*-1);
            mav(backleft_motor,speed*-1);
            mav(right_motor,speed);
            mav(backright_motor,speed);
            theta += 1.11*(gyro_z() - bias_placeholder);
        }
    }
    printf(" theta: %.6f ", theta*.181812);

    mav(left_motor, 0);
    mav(right_motor, 0);
    mav(backleft_motor, 0);
    mav(backright_motor, 0);
    msleep(50);

}



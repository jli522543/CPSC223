#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main(){
printf("Welcome to Right Triangles\n");
printf("This software was built by and maintained by Systems Programmer Jackie Li.\n");

//Creates new time_t object
char str[100];
double number1,number2,area,perimeter,number3;

time_t currenttime = time(NULL);
struct tm* broken = localtime(&currenttime);

//Prints time in human readable format
strftime(str,100, "Today is %B %d, %Y at %I:%M%p.",broken);
printf("%s\n",str);

//Prompts user for two numbers

//Right Triangle Alogrithm
if(scanf("%lf %lf",&number1 ,&number2)!=2||number1<0||number2<0){ //Check if number1 or number is negative and if both values were read in
printf("You entered %lf and %lf\n",number1,number2);
printf("Invalid data among the inputs. Please run this program again\n");
}
else{
printf("You entered %lf and %lf\n",number1,number2);
area = (number1 * number2)/2;
printf("The area of this right triangle is %lf\n",area);
number3 = sqrt(pow(number1,2)+pow(number2,2));
perimeter = number1+number2+number3;
printf("The perimeter of the same right triangle is %lf linear units\n",perimeter);
}

//Prints nanosecond from Epoch
 struct timespec * rightnow = malloc(sizeof(struct timespec));

 int zz = clock_gettime(CLOCK_REALTIME,rightnow);
 if(zz == 0)
    printf("Right now = %lu.%09lu seconds after the epoch (accuracy to nearest nano sec).\n",
           rightnow->tv_sec,rightnow->tv_nsec);
 else
    printf("An error occurred during the call to clock_gettime.\n"); 


}


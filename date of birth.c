#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
main(){
	
	int days,month,year,r1,r2,r3,weeks,tdays,hours,minuts,seconds;
	int daysinmon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
	int cm,cd,cy;
	// enter date of birth 
    printf("Enter your date of birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&days,&month, &year);

	//current time
	time_t nt;
	time(&nt);
	struct tm*ct=localtime(&nt);
	
	//check for leap year
	 if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (month == 2) 
                    {
                           days+=1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (month == 2) 
            {
                  days+=1;
            }
    }
	
    cd=ct->tm_mday;
	cm=ct->tm_mon+1;
	cy=ct->tm_year+1900;
	
	//calculate age	
		if(days>cd){
				cm-=1;
				cd=cd+daysinmon[month-1];			
		}
			if(month>cm){
				cy=cy-1;
				cm=cm+12;
			}
		
			r1=cd-days;
			r2=(cm)-month;
			r3=cy-year;
weeks=(r3*12+r2)*4.34524+(r1/7);
tdays=weeks*7+r1%7;
hours=tdays*24;
minuts=hours*60;
seconds=minuts*60;
			system("cls");
//print out
printf("your date of birth is:%d/%d/%d",days,month,year);
printf("\n\ncurrent time is:%d/%d/%d",ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900);
printf("\n\nYOUR AGE IS:");
printf("\n%d years %d month %d days",r3,r2,r1);
printf("\nor %d month %d days",r3*12+r2,r1);
printf("\nor %d weeks %d days",weeks,r1%7);
printf("\nor %d days",tdays);
printf("\nor %d hours",hours);
printf("\nor %d minutes",minuts);
printf("\nor %d seconds",seconds);



	
	
	
	
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 ������ �������� ������� � ���������� ���� � ������ ������
*/
char *matrix[12][2] = {
		{"January", 31},
		{"February", 28},
		{"March", 31},
		{"April", 30},
		{"May", 31},
		{"June", 30},
		{"July", 31},
		{"August", 31},
		{"September", 30},
		{"October", 31},
		{"November", 30},
		{"December", 31}
	};


/*
	������� ���������
*/
int main(int argc, char *argv[]) {
	
	int inputMonth = 1, inputYear = 0, daysOfFebruary = 0, startWeekDays = 0, days = 0, daysBefore = 0, whatShow = 0;

	printf("===========================================\n");
	printf("\nEnter year: ");
	scanf("%d", &inputYear);

	if( inputYear <= 0 ){
		
		printf("\nYear can not be less then zero: )))");
		return 0;
		
	}
	
	printf("\nShow (month - 0, all year - 1): ");
	scanf("%d", &whatShow);

	if( whatShow < 0 || whatShow > 1 ){

		printf("\nYou need enter only 0 or 1, try again");
		return 0;

	}
	
	/*
		�������� ���������� ���� � ������� �� �������� ����
	*/
	daysOfFebruary = getNumberDaysOfFebruary(inputYear);
	
	/*
		��������  ������ ��� ������ ������ ����
	*/
	startWeekDays = getNumberOfFirstDayOfYear(inputYear);
	matrix[1][1] = daysOfFebruary;
	

	if(whatShow == 0){
		
		printf("\nEnter number of month: ");
		scanf("%d", &inputMonth);
		
		if( inputMonth <= 0 || inputMonth > 12 ){

			printf("\nYou do not khow hove many month in the year: )))");

		}else{

			/*
				���� ���������� ���� � ���������� ������
			*/
			days = matrix[inputMonth-1][1];

	  		if( inputMonth == 1 )
	  			daysBefore = days;
			else
				daysBefore = matrix[inputMonth-2][1];

			printf("\n===========================================\n");
			printf("<%s>            <%d>", matrix[inputMonth-1][0], inputYear, days);

			/*
				������� ��������� �� ������ � �������
			*/
			drawMonthCalendar(days, startWeekDays, daysBefore, inputMonth-1);

			printf("\n===========================================\n");

		}
		
	}else{
		
		int month = 0;
		for( month; month <= 11; month++ ){
			
			printf("\n===========================================\n");
			printf("<%s>            <%d>", matrix[month][0], inputYear);

			/*
				���� ���������� ���� � ���������� ������
			*/
			if( inputMonth == 1 )
	  			daysBefore = matrix[month-1][1];
			else
				daysBefore = matrix[month-2][1];

			/*
				������� ��������� �� �������� ���� � �������
			*/
			drawMonthCalendar(matrix[month][1], startWeekDays, daysBefore, month);

		}
		
	}
	
	printf("\n===========================================");
	
	return 0;
	
}

/*
	������� ���������� ���������� ���� � �������
	int: year  ������� ���
*/
int getNumberDaysOfFebruary(int year){
	
  if ( year % 400 == 0 || year % 100 == 0 || year % 4 == 0 )
   return 29;
  else
    return 28;
    
}

/*
	������� ���������� ������ ��� ������ ������
	int: year  ������� ���
*/
int getNumberOfFirstDayOfYear(int year)
{

	return ( year + ( ( year - 1 ) / 4 ) - ( ( year - 1 ) / 100 ) + ( ( year - 1 ) / 400 ) ) % 7;

}

/*
	������� ���������  ��������� �� �����
	int: days  ���� � ������
	int: startWeekDays ����� ��� ������ � ������ ���������� �����
	int: daysBeforeMonth ���������� ���� � ���������� ������
	int: defaultMonth ����� ������
*/
int drawMonthCalendar(int days, int startWeekDays, int daysBeforeMonth, int defaultMonth){

		int k = 0, startDay = getStartDayByMonth(daysBeforeMonth, startWeekDays, defaultMonth), i = 1, numberOfWeek = getNumberWeekByMonth(startDay, defaultMonth);
		if( defaultMonth  == 0 )
			startDay = startWeekDays;

    	printf("\n___ ___ ___ ___ ___ ___ ___ ___\n");
		printf("NUM|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n");
		printf("___ ___ ___ ___ ___ ___ ___ ___\n");
		printf("%3d|", numberOfWeek);
		
  		for ( k = 1; k <= startDay; k++ )
			  printf("   |");

		for( i;  i <= days; i++ ){
			
			printf("%3d|", i);

			if ( ( i + startDay ) % 7 <= 0 ){
				
				printf("\n___ ___ ___ ___ ___ ___ ___ ___\n");
				if( days != i )
					printf("%3d|", ++numberOfWeek);
					
			}
			
		}
		
		printf("\n___ ___ ___ ___ ___ ___ ___\n");
		
}

/*
	������� ������ ������ ��� ������ ��� �������� ������
	int: dayOfMonth
	int: startWeekDays ����� ��� ������
	int: defaultMonth ����� ������
*/
int getStartDayByMonth(int dayOfMonth, int startWeekDays, int defaultMonth){

	int day = startWeekDays, month = 0;

	for ( month; month <= 11; month++ ) {
		
		if( month == defaultMonth )
			return day;

		day = ( day + (int)matrix[month][1] ) % 7;

	}

	return day;
}

/*
	������� ���������� ������ ������ ��� ������
	int: startWeekDays ����� ��� ������
	int: defaultMonth ����� ������
*/
int getNumberWeekByMonth(int startWeekDays, int defaultMonth){

	int days = 1, day=0, month = 0, numberWeek = 1;

	for ( month; month <= 11; month++ ) {
		
		if( month == defaultMonth )
			break;
			
		days += (int)matrix[month][1];
		
	}
	
	numberWeek = ceil( ( days - startWeekDays + 1 + 10 ) / 7 );
	return numberWeek;
	
}

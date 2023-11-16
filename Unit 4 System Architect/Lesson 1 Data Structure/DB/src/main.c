/*
*	main.c
*	Created on: 16 Nov 2023
*	Author: Shehab Elkhaligy
*/

#include "stdio.h"
#include "stdlib.h"
#include "../inc/DB.h"


int main() {
	char Option[2];
	DB_Student * School_1 = NULL;
	while(1){
		printf("=== Student Database ===\n");
		printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Delete All Students\n");
        printf("5. Display Number of Students\n");
        printf("6. Reverse the Students Order\n");
        printf("7. Find the Middle Student\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
		gets(Option);
		switch(atoi(Option)){
			case 1:
				DB_Add_Student(&School_1);
				break;
			case 2:
				int ID;
				printf("Enter the ID: ");
				scanf("%d",&ID);
				DB_Delete_Student(&School_1,ID);
				break;
			case 3:
				DB_View_Students(School_1);
				break;
			case 4:
				DB_Delete_All(&School_1);
				break;
			case 5:
				DB_Students_Number(School_1);
				break;
			case 6:
				DB_Reverse(&School_1);
				break;
			case 7:
				DB_Middle(School_1);
				break;
			case 8:
				exit(1);
			default:
				printf("Try again.\n");
		}
	}
	return 0;
}


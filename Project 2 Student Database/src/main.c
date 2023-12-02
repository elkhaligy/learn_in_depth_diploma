/*
 * 	main.c
 *
 *  Created on: 2 Dec 2023
 *  Author: Shehab Elkhaligy
 */
#include "stdio.h"
#include "stdlib.h"
#include "fifo.h"
#include "Database.h"

int main(void) {
	system("clear");
	// Option String
	char Opt[10];
	// Create Students Buffer
	Student_T Students_Buffer[50];
	// Create Queue
	Queue_T Database_Queue;
	// Initializt the Queue
	FIFO_Init(&Database_Queue, Students_Buffer, 50);


	printf("Welcome to the Student Management System\n");
	while(1){
		printf("-----------------------------------------\n");
		printf("Choose The Task That You Want To Perform\n");
		printf("1. Add a Student Manually\n");
		printf("2. Add a Stduent From a .txt File\n");
		printf("3. Find the Student by Roll Number\n");
		printf("4. Find the Student by First Name\n");
		printf("5. Find the Student Details by Course\n");
		printf("6. Find the Total Number of Students\n");
		printf("7. Delete a Student by Roll Number\n");
		printf("8. Update a Student by Roll Number\n");
		printf("9. Show all Students' Inofmration\n");
		printf("10. Exit\n");
		printf("Enter Your Choice: ");
		fgets(Opt,sizeof(Opt),stdin);
		switch(atoi(Opt)){
			case 1:
				Get_Data_Manually(&Database_Queue);
				break;
			case 2:
				Get_Data_File(&Database_Queue);
				break;
			case 3:
				Find_By_Roll_Number(&Database_Queue);
				break;
			case 4:
				Find_By_First_Name(&Database_Queue);
				break;
			case 5:
				Find_Course(&Database_Queue);
				break;
			case 6:
				Find_Students_Count(&Database_Queue);
				break;
			case 7:
				Delete_By_Roll_Number(&Database_Queue);
				break;
			case 8:
				Update_By_Roll_Number(&Database_Queue);
				break;
			case 9:
				Show_All_Students(&Database_Queue);
				break;
			case 10:
				exit(1);
			default:
				system("clear");
				printf("Try again.\n");
		}
	}
	return 1;
}


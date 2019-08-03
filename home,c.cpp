#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include "atm.h"
int main()
{
	home();
	getchar();
	X:int psw;
	system("cls");
	printf("\t\t\tEnter Pin Code\n ");;
	scanf(" %d",&psw);
	FILE *fp;
	if((fp=fopen("file.txt","r"))==NULL){
		printf("Unable to Reach.");
		exit(0);
	}
	int psw1;
	if((fread(&psw1,sizeof(int),1,fp))!=NULL)
	{
		if(psw!=psw1){
			printf("Wrong Password.");
			goto X;
		}
		system("cls");
		choice();
		char c=tolower(getch());
		switch(c)
		{
			case 'b':{
				system("cls");
				FILE *fptr;
				if((fptr=fopen("ac.txt","r"))==0){
					printf("Sorry! The Atm is Out of Service at the Moment.\n");
					exit(0);
				}
				printf("\n\t\tAvailable Balance :%d\n",getw(fptr));
				fclose(fptr);
				break;
			}
			case 'w':{
				system("cls");
				printf("\n\t\tEnter The Amount :");
				int am;
				scanf(" %d",&am);
				FILE *fptr;
				if((fptr=fopen("ac.txt","r"))==0){
					printf("Sorry! The Atm is Out of Service at the Moment.\n");
					exit(0);
				}
				if(am>getw(fptr)){
					printf("Insufficent Balance.\n");
					exit(0);
				}
				printf("\n\t\tTransition is Being Processed.\n\t\tThank you for banking with Us.");;
				new_balance(am);
				fclose(fptr);
				break;
			}
			case 'f':{
				system("cls");
				int fc;
				fastCash();
				scanf(" %d",&fc);
				FILE *fptr;
				if((fptr=fopen("ac.txt","r"))==0){
					printf("Sorry! The Atm is Out of Service at the Moment.\n");
					exit(0);
				}
				int balance=getw(fptr);
				switch(fc)
				{
					case 1:{
						if(balance<1000){
					     printf("Insufficent Balance.\n");
					    exit(0);
				        }
				        printf("\n\t\tTransition is Being Processed.\n\t\tThank you for banking with Us.");;
				        new_balance(1000);
						break;
					}
					case 2:{
						if(balance<2000){
					     printf("Insufficent Balance.\n");
					    exit(0);
				        }
				        printf("\n\t\tTransition is Being Processed.\n\t\tThank you for banking with Us.");;
				        new_balance(2000);
						break;
					}
					case 3:{
						if(balance<5000){
					     printf("Insufficent Balance.\n");
					    exit(0);
				        }
				        printf("\n\t\tTransition is Being Processed.\n\t\tThank you for banking with Us.");;
				        new_balance(5000);
						break;
					}
					case 4:{
						if(balance<1000){
					     printf("Insufficent Balance.\n");
					    exit(0);
				        }
				        printf("\n\t\tTransition is Being Processed.\n\t\tThank you for banking with Us.");;
				        new_balance(10000);
						break;
					}
				}
				break;
			}
		case 'c':{
			
			system("cls");
			int n_psw;
			printf("\n\t\tEnter New Pin :");
			scanf(" %d",&n_psw);
			FILE *fptr;
			if((fptr=fopen("file.txt","w"))==0){
				printf("Error!");
				exit(0);
			}
			putw(n_psw,fptr);
			printf("Pin Code Reset Successfully.");
			fclose(fptr);
			break;
		}
		case 'a':{
			system("cls");
			FILE *fptr;
			if((fptr=fopen("ac.txt","r"))==0){
				printf("Unable to read.");
				exit(0);
			}
			int balance=getw(fptr);
			fclose(fptr);
			int add;
			printf("Enter the amount you want to add :");
			scanf(" %d",&add);
			if((fptr=fopen("ac.txt","w"))==0){
				printf("Unable to read.");
				exit(0);
			}
			putw(balance+add,fptr);
			printf("Money Added Successfully!");
			fclose(fptr);
			break;
		}
		default:{
			system("cls");
			printf("\n\t\tPlease Enter a Valid Choice.");
			break;
		}	
		}
	}
	fclose(fp);
	return 0;
}

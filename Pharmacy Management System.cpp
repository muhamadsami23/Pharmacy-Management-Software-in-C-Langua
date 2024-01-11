#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct medicine
{
	int no;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
};//Attributes of the Medicines

void data_1();//It shows all only the names of the Medicines
void inventory_2();//It shows Complete Inventory, Costing and Prices of the Medicines
void detail_3();//It shows all the information of One Specific Medicine
void filing_5();//It add new medicines to the inventory
void delete_6();//It deletes inventory

int main()
{
	FILE* fptr;//Pointer For File Handling
    char name [100];
    char code [5];
    int no;
    int sno;
    float total;
	int quantity;
	char choice; 
	int choice2;
	printf("\t\t\tFor better experience, view the program in full screen\n\n");
	printf("\t\t\t\tWelcome to Online-Pharmacy Portal\n");
	printf("\t\t\t\t---------------------------------\n");
label:
	printf("\nSelect the mode from the given list ");
	printf("\n1. Admin Mode ");
	printf("\n2. Customer Mode ");
	printf("\nIf you want to Exit, please type 'N'\nEnter Choice : ");
	scanf("%c",&choice);
	if(choice == '1')
	{
			printf("\n\n\nEnter 4 Digit Pin : ");//To get Access last Digit Should be 3 
			int pin;
			scanf("%d", &pin);
			if((pin%10)==3)
			{
				printf("Access Granted\n\n");
				system("pause");//To Pause system for few seconds
				system("cls");//To Clear the Screen
			}
	}
	do//Loop to run the program continously until the user exits
	{
	switch(choice)
	{
		case 'N': case 'n':
			printf("\n\nWell, It seems that you are all good.\nWe always welcome you if you need any assistance in your future.");
			printf("\nTake a good care of yours");
			printf("\n*****");
			return 0;
	
		case '1': 
			printf("\n\n");
			printf("---------------------------------\n");
		
				printf("Menu:\n");
				printf("1. Show Medicines List:\n");
				printf("2. Show Inventory:\n");
				printf("3. Show details of one specific medicine:\n");
				printf("4. Update the Inventory\n");
				printf("5. Delete Inventory\n");
				printf("6. Exit\n");
				scanf("%d",&choice2);
				printf("---------------------------------\n");
				if(choice2==1)
					{
							data_1();
							printf("\n\n");	
							system("pause");
							system("cls");
					}
				else if(choice2==2)
					{
						inventory_2();
						printf("\n\n");
						system("pause");
						system("cls");
					}
				else if(choice2==3)
					{
							data_1();
							detail_3();	
							printf("\n\n");
							system("pause");			
							system("cls");
					}
				else if(choice2==4)	
					{
						filing_5();
						printf("\n\n");
						system("pause");
						system("cls");
					}
				else if(choice2==5)
					{
						delete_6();
						printf("\n\n");
						system("pause");
						system("cls");
					}
				else if(choice2==6)
					{
						printf("\nExiting Admin Mode");
						printf("\n*****");
						printf("\n\n\n");
						system("pause");
						system("cls");
						goto label;//Jump to the Label at line 35
						
					}
					
			
		case '2': 
			printf("\n\n");
			printf("---------------------------------\n");
		
				printf("Menu:\n");
				printf("1. Show Medicines List:\n");
				printf("2. Show details of one specific medicine:\n");
				printf("3. Purchase\n");
				printf("4. Exit\n");
				scanf("%d",&choice2);
				printf("---------------------------------\n");
				if(choice2==1)
					{
							data_1();
							printf("\n\n");	
							system("pause");
							system("cls");
					}
				else if(choice2==2)
					{
							data_1();
							detail_3();	
							printf("\n\n");
							system("pause");			
							system("cls");
					}
				else if(choice2==3)	
					{
						data_1();
						printf("\n\nEnter S.No of the Medicine from the above List : ");
						scanf("%d",&sno);
						printf("Enter Code of the Medicine : ");
						scanf("%s", name);
						printf("Enter Quantity : ");
						scanf("%d", &quantity);
						int num;
						int i=0;
						FILE *ptr, *fptr; //Pointers for operating two files, one to update the count of medicine and other of the inventory
						fptr=fopen("Num.txt","r");//Open the Num file to store the number of medicine
						if (ptr == NULL)
							{
								printf("Error!");
								exit(1);
							}
						else
							{
								fscanf(fptr,"%d",&num);//Scans the number in the Num file
							}
						fclose(fptr);
						struct medicine s[num];
						ptr=fopen("inventory.txt","r");//Opens the inventory file to store medicine
						if (ptr == NULL)
							{
								printf("Error!");
								exit(1);
							}
						else
							{
							for(i=0;i<num;i++) //Loop to find the enter medicine
								{
									fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );
									if(sno == (i+1))
									{
										float total;
										total = quantity * s[i].price;
										printf("\n---------------------------------\n");
										printf("\n\nS.No\tName\t\t\tQuantity\t\tPrice\n\n");
										printf("\n%d\t%s\t\t\t%d\t\t\t%.2f",sno,s[i].name,quantity,total);	
									}
								}
							}
							printf("\n\n");
						system("pause");
						system("cls");
					}
	
				else if(choice2==4)
					{
						printf("\nTHANK YOU FOR USING OUR PROGRAM.\nWE ALWAYS WELCOME YOU IF YOU NEED ANY ASSITANCE IN THE FUTURE");
								printf("\nTake a good care of yours");
								printf("\n*****");
								return 0;
						
					}		
			}
	}while (choice!='N'||'n');
}
void data_1(){
	int no, num;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
	int i=0;
	
	FILE *ptr, *fptr;
	fptr=fopen("Num.txt","r");//Open the Num file to read count of medicine
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		fscanf(fptr,"%d",&num);
	}
	fclose(fptr);
	ptr=fopen("inventory.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		struct medicine s[num];
	for(i=0;i<num;i++)
		{
			fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );//Store each line as per the structure respectively
		};
		for(i=0;i<num-1;i++)
		{
			printf("\n%d\t%s  %s", s[i].no, s[i].name, s[i].code);//Print the medicine name on the console
		}
			fclose(ptr);
	}

}
void inventory_2(){
	int no,num;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
	int i=0;
	
	FILE *ptr, *fptr;
	fptr=fopen("Num.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		fscanf(fptr,"%d",&num);
	}
	fclose(fptr);
	ptr=fopen("inventory.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		struct medicine s[num];
	for(i=0;i<num;i++)
		{
			fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );
		}
			for(i=0;i<num-1;i++)
		{
			printf("\b\b%d\t%s %s\t\t\t%s\t%s\t%.2f\t%.2f\n", s[i].no,s[i].name,s[i].code,s[i].mfg_date,s[i].exp_date,s[i].cost,s[i].price);
		}
			fclose(ptr);
	}

}

void detail_3()
{
    int num;
    FILE *fptr;
    fptr = fopen("Num.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        fscanf(fptr, "%d", &num);
    }
    fclose(fptr);

    FILE *ptr;
    ptr = fopen("inventory.txt", "r");
    if (ptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        struct medicine s[num];
        for (int i = 0; i < num; i++)
        {
            fscanf(ptr, "%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price);
        }
        fclose(ptr);
        
        printf("\n\nEnter medicine code:");
        char coded[5];
        scanf("%s", coded);
        printf("S.No\tName\t\t\tMFG Date\tExp Date\tCost\t\tPrice\n\n");
        
        for (int i = 0; i < num; i++)
        {
            if (strcmp(coded, s[i].code) == 0)
            {
                printf("%d\t%s %s\t\t%s\t%s\t%.2f\t\t%.2f\n", s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, s[i].cost, s[i].price);
            }
        }
    }
}	
void filing_5()
	{
			FILE *fptr, *ptr;
			int count,num;
			ptr=fopen("Num.txt","r");
			if (ptr == NULL)
			{
				printf("Error!");
				exit(1);
			}
			else
			{
				fscanf(ptr,"%d",&num);
			}
			fclose(ptr);
			count = num;
			fptr=fopen("inventory.txt","a"); 
			if(fptr==NULL)
			{
				printf("Error");
				exit(1);
			}
			else
			{
				struct medicine s1;
				printf("\nEnter Name of the medicine : ");
				scanf("%s",s1.name);
				printf("\nEnter code of the medicine : ");
				scanf("%s",s1.code);
				printf("Enter MFG Date of the medicine : ");
				scanf("%s",s1.mfg_date);
				printf("Enter EXP Date : ");
				scanf("%s", s1.exp_date);
				printf("Enter Cost : ");
				scanf("%f", &s1.cost);
				printf("Enter Price : ");
				scanf("%f", &s1.price);
				fprintf(fptr,"%d\t%s %s\t\t\t\t%s\t%s\t%.2f\t%.2f\n",count,s1.name,s1.code,s1.mfg_date,s1.exp_date,s1.cost,s1.price);
				printf("\n\nInventory Updated");
				fclose(fptr);	   
				count++;
				ptr=fopen("Num.txt","w+");
				if (ptr == NULL)
				{
					printf("Error!");
					exit(1);
				}
				else
				{
					fprintf(ptr,"%d",count);
				}
				fclose(ptr);
				}
}
void delete_6(){
	int i,j,sno,cur_line=1,lno=0;
	printf("\nEnter serial number to delete: ");
	scanf("%d",&sno);
	FILE *ptr;
	ptr =fopen("Num.txt","r");
	int counter;
	if(ptr!=NULL){
		fscanf(ptr,"%d",&counter);
	}
	fclose (ptr);
	FILE *fptr;
	int no[counter];
	char name[counter-1][100];
	fptr=fopen("inventory.txt","r+");
	if(fptr!= NULL){
	printf("OLD LIST\n");
	for(i=0;i<(counter-1);i++){
		fscanf(fptr,"%d %[^\n]s",&no[i],name[i]);
		puts(name[i]);
	}}else{printf("ERROR!");
	}
	fclose(fptr);
	FILE *temp;
	temp=fopen("inventory.txt","w");
	if(temp!=NULL){
		printf("\n-------------------\nUpdated List: \n");
		for (j=0;j<(counter-1);j++,cur_line++){
			
			if(cur_line!=sno){
				lno++;	
				fprintf(temp,"%d\t%s\n",lno,name[j]);
			}
		}
	}else{printf("ERROR");
	}printf("%d",counter);
	
fclose(temp);
	counter--;
	ptr=fopen("Num.txt","w");
	fprintf(ptr,"%d",counter);
	fclose(ptr);
	
}



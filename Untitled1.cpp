#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
struct user
{
	char username[20];
	char userpass[20];
	int pin;
	int dob;

} b;
int main()
{
	int choice = 0;
functionmenu:
	printf("\n\t\t==================================================================");
	printf("\n\t\t||\t\t\t [  MENU  ]                         \t||");
	printf("\n\t\t||\t1.ENCRYPTION                                  \t\t||");
	printf("\n\t\t||\t2.DECRYPTION                                  \t\t||");
	printf("\n\t\t||\t3.LOGIN MENU                                  \t\t||");
	printf("\n\t\t||\t4.EXIT                                        \t\t||");
	printf("\n\t\t||\tNOTE: For the encryption of file              \t\t||");
	printf("\n\t\t||\t      the file must be saved in program folder\t\t||");
	printf("\n\t\t||\t      with name(data.txt)                     \t\t||");
	printf("\n\t\t||\t      To decrypt the file save file with name \t\t||");
	printf("\n\t\t||\t      (encrypted.txt)                         \t\t||");
	printf("\n\t\t==================================================================");
	printf("\n\n\t\t OPTION: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{ // encryption program
		FILE *data;
		char name[20], password[20];
		data = fopen("logindata.dat", "rb+");
		fflush(stdin);
		system("cls");
		if (data == NULL)
		{
			printf("\t\tMake an account to run program.(option 3)");
			goto functionmenu;
		}
		printf("\t\t\tUSERNAME: ");
		gets(name);
		printf("\t\t\tPASSWORD: ");
		gets(password);
		fread(&b, sizeof(b), 1, data);
		if (strcmp(b.username, name) == 0 && strcmp(b.userpass, password) == 0)
		{
			FILE *read, *encode;
			char alph, option, x = 219;
			int num = 0, fnum = 0, i = 0;
			read = fopen("G:\\hideandseek\\data.txt", "r");
			encode = fopen("G:\\hideandseek\\encrypted.txt", "w+");
			if (read == NULL)
			{
				printf("The file isnt available. Save your file in the folder where the program is saved. ");
			}
			else
			{
				while (fscanf(read, "%c", &alph) != EOF)
				{
					if (alph >= 97 && alph <= 109) // a to m
					{
						num = alph - 73;
						fprintf(encode, "%d", num);
					}
					else if (alph >= 65 && alph <= 77) // A to M
					{
						num = alph - 9;
						fprintf(encode, "%d", num);
					}
					else if (alph >= 110 && alph <= 122) // n to z
					{
						num = alph - 41;
						fprintf(encode, "%d", num);
					}
					else if (alph >= 78 && alph <= 90) // N to Z
					{
						num = alph - 41;
						fprintf(encode, "%d", num);
					}
					else if (alph >= 48 && alph <= 57) // numbers
					{
						num = alph - 38;
						fprintf(encode, "%d", num);
					}
					else if (alph >= 32 && alph <= 37) // special character i.e( space ! " # $ %)
					{
						num = alph + 18;
						fprintf(encode, "%d", num);
					}
					else if (alph == 40 || alph == 41) //()
					{
						num = alph - 20;
						fprintf(encode, "%d", num);
					}
					else if (alph == ',') //,
					{
						num = alph - 22;
						fprintf(encode, "%d", num);
					}
					else if (alph == '.') //.
					{
						num = alph - 23;
						fprintf(encode, "%d", num);
					}
					else if(alph == 10)//enter and ?
					{
						num=alph+80;
						fprintf(encode, "%d", num);
					}
					else if(alph == 63)//?
					{
						num=alph+28;
						fprintf(encode, "%d", num);
					}
				} // while end
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n");
				printf("\t\t\t\t\t\t ");
				printf("Please wait.......\n");
				printf("\t\t\t\t\t\t");
				for (i = 1; i <= 20; i++)
				{
					printf("%c", x);
				
				}
				fclose(read);
				fclose(encode);
				remove("G:\\hideandseek\\data.txt");
				system("cls");
				fflush(stdin);
				printf("\n\t\t\tThe file has been Encrypted.(check in the folder of program).");
				printf("\n\t\t\tDo you want to continue yes/no(Y/N)?");
				scanf("%c", &option);
				system("cls");
				if (option == 'Y' || option == 'y')
				{
					goto functionmenu;
				}
				else if (option == 'N' || option == 'n')
				{
					exit(0);
				}
			} // 2else end
		}	  // if end
		else
		{
			system("cls");
			printf("The user/password is invalid.In the case of forggoten reset the data from login option.");
			goto functionmenu;
		}

		break;
	} // case 1 end

	case 2:
	{
		fflush(stdin);
		system("cls");
		FILE *data, *check, *ptr;
		int n = 0;
		char name[20], password[20];
		data = fopen("logindata.dat", "rb+");
		check = fopen("check1.txt", "r+");
		fread(&b, sizeof(b), 1, data);
		fscanf(check, "%d", &n);
		if (data == NULL)
		{
			printf("\t\t\t Make an Account.");
			goto functionmenu;
		}
		printf("\t\t\tUSERNAME: ");
		gets(name);
		printf("\t\t\tPASSWORD: ");
		gets(password);
		if ((strcmp(b.username, name)) == 0 && (strcmp(b.userpass, password)) == 0)
		{
			system("cls");
			FILE *encode, *write;
			char str[2], x = 219;
			int fnum = 0, num1 = 0, i = 0;
			encode = fopen("G:\\hideandseek\\encrypted.txt", "r");
			if (encode == NULL)
			{
				printf("\t\t\t The file to encrypt doesnt exsit in folder.");
				goto functionmenu;
			}
			write = fopen("G:\\hideandseek\\decrypted.txt", "w+");
			while (fgets(str, 3, encode) != NULL)
			{
				sscanf(str, "%d", &fnum);
				if (fnum >= 24 && fnum <= 36) // a to m
				{
					num1 = fnum + 73;
					fprintf(write, "%c", num1);
				}
				else if (fnum >= 56 && fnum <= 68) // A to M
				{
					num1 = fnum + 9;
					fprintf(write, "%c", num1);
				}
				else if (fnum >= 69 && fnum <= 81) // n to z
				{
					num1 = fnum + 41;
					fprintf(write, "%c", num1);
				}
				else if (fnum >= 37 && fnum <= 49) // N to Z
				{
					num1 = fnum + 41;
					fprintf(write, "%c", num1);
				}
				else if (fnum >= 10 && fnum <= 19) // numbers
				{
					num1 = fnum + 38;
					fprintf(write, "%c", num1);
				}
				else if (fnum >= 50 && fnum <= 55) // special character i.e( space ! " # $ %)
				{
					num1 = fnum - 18;
					fprintf(write, "%c", num1);
				}
				else if (fnum == 20 || fnum == 21) //()
				{
					num1 = fnum + 20;
					fprintf(write, "%c", num1);
				}
				else if (fnum == 22) //,
				{
					num1 = fnum + 22;
					fprintf(write, "%c", num1);
				}
				else if (fnum == 23) //.
				{
					num1 = fnum + 23;
					fprintf(write, "%c", num1);
				}
				else if(fnum==90)
				{
					num1=fnum-80;
					fprintf(write, "%c", num1);
				}
				else if(fnum==91)
				{
					num1=fnum-28;
					fprintf(write, "%c", num1);
				}
			} // while end
			fclose(encode);
			printf("\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t ");
			printf("File Decrypting....\n");
			printf("\t\t\t\t\t\t");
			for (i = 1; i <= 20; i++)
			{
				printf("%c", x);
				
			}
			printf("\n\t\t\t\t      The file has been decrypted sucessfully.\n\n");
			remove("G:\\hideandseek\\encrypted.txt");
		}
		else
		{
			system("cls");

			if (n == 0)
			{
				remove("G:\\hideandseek\\encrypted.txt");
				printf("\t\t\tThe files have been deleted");
				goto functionmenu;
			}
			else
			{
				system("cls");
				n--;
				ptr = fopen("check1.txt", "w");
				fprintf(ptr, "%d", n);
				fclose(ptr);
				printf("\t\tThe user/password is invalid.(In the case of forggoten reset the data from login option.)");
				printf("\n\t\tYou have %d tries left.AFter 0 tries the files will be deleted.", n);
				goto functionmenu;
			}
		} // 1

		break;
	} // casse end

	case 3:
	{
		system("cls");
	log:
		fflush(stdin);

		FILE *data, *check, *ptr;
		int cpin = 0, lpin = 0, ldob = 0, p = 0;
		char lname[20], lpass[20];
		data = fopen("logindata.dat", "rb");
		ptr = fopen("check1.txt", "r+");
		check = fopen("check2.txt", "r+");
		fscanf(check, "%d", &p);
		fread(&b, sizeof(b), 1, data);
		if (data == NULL) // 1
		{
			FILE *fp1, *fp2, *fp3;
			system("cls");
			fflush(stdin);
			printf("\t\tNEW USER:\n");
			printf("\t\tUSERNAME:");
			gets(b.username);
			printf("\t\tPASSWORD:");
			gets(b.userpass);
			printf("\t\tPIN: ");
			scanf("%d", &b.pin);
			printf("\t\tDOB: ");
			scanf("%d", &b.dob);
			fp1 = fopen("logindata.dat", "wb+");
			fp2 = fopen("check1.txt", "w");
			fp3 = fopen("check2.txt", "w");
			fwrite(&b, sizeof(b), 1, fp1);
			fprintf(fp2, "%d", 3);
			fprintf(fp3, "%d", 3);
			fclose(fp1);
			fclose(fp2);
			fclose(fp3);
			system("cls");
			goto functionmenu; // if1 end
		}
		else
		{
			printf("\t\t\tEnter the PIN/DOB:");
			scanf("%d", &cpin);
			if (b.pin == cpin || b.dob == cpin) // 2
			{
				FILE *data1, *fp;
				system("cls");
				fflush(stdin);
				printf("\t\tTHE DATA RESEt:\n");
				printf("\t\tUSERNAME:");
				gets(b.username);
				printf("\t\tPASSWORD:");
				gets(b.userpass);
				printf("\t\tPIN: ");
				scanf("%d", &b.pin);
				printf("\t\tDOB: ");
				scanf("%d", &b.dob);
				data1 = fopen("logindata.dat", "wb+");
				fp = fopen("check2.txt", "w+");
				ptr = fopen("check1.txt", "w");
				fwrite(&b, sizeof(b), 1, data1);
				fprintf(fp, "%d", 3);
				fprintf(ptr, "%d", 3);
				fclose(ptr);
				fclose(check);
				fclose(data);
				fclose(data1);
				fclose(fp);
				system("cls");
				goto functionmenu;
			} // if1 end
			else
			{
				fclose(data);
				fclose(ptr);
				fclose(check);
				
				if (p == 0)
				{   
					system("cls");
					remove("G:\\hideandseek\\Private\\logindata.dat");
					remove("G:\\hideandseek\\Private\\check1.txt");
					remove("G:\\hideandseek\\Private\\check2.txt");
					remove("G:\\hideandseek\\encrypted.txt");
					remove("G:\\hideandseek\\data.txt");
					printf("\t\tThe files have been deleted");
					exit(0);
				}
				else
				{
					system("cls");
					p--;
					printf("%d", p);
					check = fopen("check2.txt", "w");
					fprintf(check, "%d", p);
					fclose(check);
					printf("\t\tThe PIN/DOB is invalid.");
					printf("\n\t\tYou have %d tries left.AFter 0 tries all the files & data will be deleted.\n", p);
					goto log;
				}
			}
		} // if1 end
		break;
	}
	case 4:
	{
		exit(0);
	}
	default:
	{
		printf("Choose the right opiton.");
		break;
	}

	} // switch end
	return 0;
} // int main end

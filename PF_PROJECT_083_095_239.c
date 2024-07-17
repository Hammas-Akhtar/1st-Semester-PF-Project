#include <stdio.h>
#include <string.h>

// Structure for account information
struct account 
{
    int pin;
    char name[100];
    char amount[100];
};

// Structure for balance information
struct balance
{
 	float previous, user, balance;
};

// Function prototypes
void create();
void login();
void logout();
void deposit();
void withdraw();
void check();
void detail();
void change();

// int main function  
int main() 
{	
	// define structure
	struct account c;
    int choice;
	
	// print project information
    printf("**************************\n");
    printf("* WELCOME TO OUR PROJECT *\n");
    printf("**************************\n\n");
    printf("**BANK MANAGEMENT SYSTEM**\n\n");
	
	// Use do while loop for print menu
	do {
        printf("\n        **MENU**\n\n");
        printf(" 1. Create New Account\n");
        printf(" 2. Login Your Account\n");
        printf(" 3. Exit\n");

		// Take input choice from user to call functions
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                create();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 3);

    return 0;
}

// Funtion to create account
void create() 
{
	// define structure
    struct account c;
    
    // make file pointer
    FILE *accountFile, *balanceFile;
    int choice, x = 0;
	
	// Take input from user to username and Pin code
    printf("\nEnter Phone Number or Username (Without Space): ");
    scanf("%s", c.name);
    printf("Enter Pin Code: ");
    scanf("%d", &c.pin);
	
	// use strcpy function to copy string into another string
	strcpy(c.amount,c.name);
	
	// use strcat function to combine string and file extension
    strcat(c.name, ".txt");
    
    // open a file and write a username and pin code
    accountFile = fopen(c.name, "w");
    fprintf(accountFile, "%s %d", c.name, c.pin);
    fclose(accountFile);

	// use strcat function to combine string and file extension
    strcat(c.amount, "balance.txt");
    
    // open a file and write a balance zero
    balanceFile = fopen(c.amount, "w");
    fprintf(balanceFile, "%.2f", x);
    fclose(balanceFile);

	// give information to user for sucessful create account
    printf("\nAccount Created Successfully!\n");
    printf("Now You Can Login Your Account!\n");
	
	// Use do while loop for print menu
    do {
        printf("\n        **MENU**\n\n");
        printf(" 1. Create New Account\n");
        printf(" 2. Login Your Account\n");
        printf(" 3. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
		
		// Take input choice from user to call functions
        switch (choice) 
		{
            case 1:
                create();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 3);

}

// Function to login account
void login()
{
	// define structure
    struct account l;
    int pin, choice;
    char name[100];
    char username[100];
    
    // make file pointer
    FILE *loginFile;
	
	// take input from user for username
    printf("\nEnter Phone Number or Username (Without Space): ");
    scanf("%s", l.name);
    
    // use strcpy function to copy string into another string
    strcpy(username,l.name);
    
    // use strcat function to combine string and file extension
    strcat(l.name, ".txt");
	
	// open a file and read a username and pin code
    loginFile = fopen(l.name, "r");
    fscanf(loginFile, "%s %d", name, &pin);
    fclose(loginFile);

	// use if function to check given username or file username are not equal
    if (strcmp(l.name, name) != 0) 
	{
		// use do while loop for if username is incorrect so take information again
        do {
            printf("Incorrect Phone Number or Username!");
            printf("\n\nEnter Phone Number or Username (Without Space): ");
            scanf("%s", l.name);
            strcpy(l.amount,l.name);
            strcat(l.name, ".txt");

            loginFile = fopen(l.name, "r");
            fscanf(loginFile, "%s %d", name, &pin);
            fclose(loginFile);
        } while (strcmp(l.name, name) != 0);
    }
    
	// take input from user for pin code 
    printf("Enter Pin Code: ");
    scanf("%d", &l.pin);
	
	// use if condition to check given pin code or file pin code are not equal
    if (l.pin != pin) 
	{
		// use do while loop for if pin code is incorrect so take information again
        do {
            printf("Incorrect Pin Code!\n");
            printf("\nEnter Pin Code: ");
            scanf("%d", &l.pin);
        } while (l.pin != pin);
    }

    printf("\nLogin Successful!\n");
    
    // use strcpy function to copy string into another string
    strcpy(l.amount,username);
    
    // use strcat function to combine string and file extension
    strcat(l.amount,"balance.txt");
	
	// Use do while loop for print menu
    do {
        printf("\n       **MENU**\n\n");
        printf(" 1. Deposit Amount\n");
        printf(" 2. Withdraw Amount\n");
        printf(" 3. Check Balance\n");
        printf(" 4. Account Detail\n");
        printf(" 5. Change Pin Code\n");
        printf(" 6. Logout\n");
        printf(" 7. Exit\n");
	
		// Take input choice from user to call functions
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                deposit(l.amount);
                break;
            case 2:
                withdraw(l.amount);
                break;
            case 3:
                check(l.amount);
                break;
            case 4:
                detail(l.amount, l.name);
                break;
            case 5:
            	change(l.name);
            	break;
            case 6:
                logout(l.amount);
                break;
            case 7:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6 && choice != 7);
}

// Function to deposit amount
void deposit(char *damount) 
{	
	// define structure
    struct balance d;
    
    // make file pointer
    FILE *depositFile;;
    
    // open file to read previous amount
    depositFile = fopen(damount, "r");
    fscanf(depositFile, "%f", &d.previous);
    fclose(depositFile);
	
	// take input from user for deposit amount
    printf("\nEnter Deposit Amount: ");
    scanf("%f", &d.user);
    
	// use if condition for check given deposit amount < 0
    if (d.user < 0) 
	{
        printf("Invalid Deposit Amount!\n");
	}
	else
	{
	// combine a previous and new amount and store in new variable
	d.balance = d.previous + d.user;
	
	// open file in write mode and write a updated balance
	depositFile = fopen(damount, "w");
    fprintf(depositFile, "%.2f\n", d.balance);
    fclose(depositFile);
	
	// gives information from user for successful deposit
    printf("\nSuccessfully Deposited %.2fRs\n", d.user);
    printf("Your Updated Amount is %.2fRs\n",d.balance);
	}
}	

// function to withdraw amount
void withdraw(char *wamount) 
{
	// define structure 
    struct balance w;
    
    // make file pointer
    FILE *withdrawFile;
	
	// open a file in read mode and read previous amount
    withdrawFile = fopen(wamount, "r");
    fscanf(withdrawFile, "%f", &w.previous);
    fclose(withdrawFile);
	
	// take input from user fro withdraw amount
    printf("\nEnter Withdraw Amount: ");
    scanf("%f", &w.user);
    
    // use if condition for check given withdraw amount < 0
    if (w.user < 0) 
	{
        printf("Invalid Withdrawal Amount!\n");
	}
	else
	{
	// use if condition for check given withdraw amount > previous amount
	if(w.user > w.previous)
	{
		printf("Insufficiant Withdrawal Amount!\n");
	}
	else 
	{	
		// substract giver amount from previous amount and store in new variable
		w.balance = w.previous - w.user;
		
		// open a file in write mode and print updated balance
        withdrawFile = fopen(wamount, "w");
        fprintf(withdrawFile, "%.2f\n", w.balance);
        fclose(withdrawFile);
		
		// give information from user to successful withdrawl
        printf("\nSuccessfully Withdraw %.2fRs\n", w.user);
        printf("Your Remaining Amount is %.2fRs\n",w.balance);
    }
	}
}

// function to check amount
void check(char *camount) 
{
	// define structure
    struct balance b;
    
    // make file pointer
    FILE *checkFile;

	// open file in read mode and read balance
    checkFile = fopen(camount, "r");
    fscanf(checkFile, "%f", &b.balance);
    fclose(checkFile);

    printf("\nYour Current Balance is %.2fRs\n", b.balance);
}

// function to check account detail
void detail(char *aamount, char *aaccount) 
{
	// define structure
    struct account de;
    struct balance d;
    
    // make file pointer
    FILE *accountFile, *balanceFile;
	
	// open file in read mode and read user name and pin code
    accountFile = fopen(aaccount, "r");
    fscanf(accountFile, "%s %d", de.name, &de.pin);
    fclose(accountFile);
	
	// use strtok function to break string and file extention
	strtok(de.name,".txt");
	
	// print account detail
    printf("\n**Account Detail**\n");
    printf("\n Username: %s", de.name);
    printf("\n Pin Code: %d", de.pin);
    
    // open file in read mode and read balance 
    balanceFile = fopen(aamount, "r");
    fscanf(balanceFile, "%f", &d.balance);
    fclose(balanceFile);
	
	// print current balance
    printf("\n Current Balance: %.2fRs\n", d.balance);
}

// Function to change pin code
void change(char *caccount)
{
	// define structure
    struct account p;
    int pin, newpin;
    // make file pointer
    FILE *ChangePin;
    
    // open file in read mode and read user name and pin code
    ChangePin = fopen(caccount, "r");
    fscanf(ChangePin, "%s %d", p.name, &p.pin);
    fclose(ChangePin);
    
    // take input from user for pin code
    printf("\nEnter Pin code: ");
    scanf("%d", &pin);
    
    // use if condition to check given pin code or file pin code are not equal
    if (p.pin != pin) 
	{
		// use do while loop for if pin code is incorrect so take information again
        do {
            printf("Incorrect Pin Code!\n");
            printf("\nEnter Pin Code: ");
            scanf("%d", &pin);
        } while (p.pin != pin);
    }
    
    // use if condition to check given pin code or file pin code are equal
  	if(p.pin == pin)
   	{
   		// take input from user for new pin code
    	printf("Enter New Pin code: ");
    	scanf("%d", &newpin);
    		
    	// open file in write mode and write user name and pin code
    	ChangePin = fopen(caccount, "w");
   		fprintf(ChangePin, "%s %d", p.name, newpin);
    	fclose(ChangePin);
    		
    	printf("\nSuccessfully Changed Pin Code!\n");
	}
}

// Function to logout from the account
void logout() 
{
    int choice;

    printf("\nLogout Successful!\n");
	
	// Use do while loop for print menu
    do {
        printf("\n        **MENU**\n\n");
        printf(" 1. Create New Account\n");
        printf(" 2. Login Your Account\n");
        printf(" 3. Exit\n");
	
		// Take input choice from user to call functions
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                create();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 3);
}


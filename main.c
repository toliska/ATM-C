#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu(){
	char op1[] = "Deposit";
	char op2[] = "Withdraw";
	char op3[] = "Check Balance";
	int answ;
	system("cls");
	printf("Select an option:\n1. %s\n2. %s\n3. %s\n",op1,op2,op3);
	scanf(" %d",&answ);
	system("cls");
	return answ;
}

void deposit(int*bal){
	int dp;
	printf("\t\t\tDeposit Menu\nBalance: %d EUR\n", *bal);
	printf("Please insert the prefered amount for deposit: ");
	scanf(" %d",&dp);
	printf("Amount: %d has been succesfully deposited to the account\n",dp);
	*bal += dp;
	printf("New Balance: %d EUR\n",*bal);
}

void withdraw(int* bal){
	int wd;
	if (*bal == 0){
		printf("Insufficient funds for withdraw\n");
	}
	else {
		printf("Balance: %d EUR\nPlease insert the prefered amount for withdraw: ",*bal);
		scanf("%d",&wd);
		if (wd > *bal){
			printf("Insufficient funds\n");			
		}else {
			printf("Amount: %d has been succesfully withdrawn from the account\n",wd);
			*bal -= wd;
			printf("New Balance: %d EUR\n",*bal);
		}
	}
	
}

void checkBalance(int* bal){
	printf("Current balance: %d EUR\n",*bal);	
}

int main(int argc, char *argv[]) {
	system("title ATM System");
	char op1[] = "Deposit";
	char op2[] = "Withdraw";
	char op3[] = "Check Balance";
	int answ;
	int bal = 0;
	int dp;
	
	char answ1 = 'y';
	
	while (answ1 == 'y'){
		answ = menu();
		if (answ == 1){
			deposit(&bal);
		}else if (answ == 2){
			withdraw(&bal);			
		}
		else if (answ ==3){
			checkBalance(&bal);
		}
		printf("\nWould you like to make another transaction (y/n)?");
		scanf(" %c",&answ1);
	}
	system("cls");
	printf("Thank you for using ATM!!!");		
	return 0;
}



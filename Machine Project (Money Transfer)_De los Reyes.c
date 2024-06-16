/*
Description: <The program performs as a digital bank wherein a user can do multiple transcation similar to 
			a kiosk, the following are the features that the program can do:
			withdraw money, transfer money, foreign currency exchange, pay bills, and more.> 
Programmed by: <Carl Justin B. De los Reyes> <S24B>
Last modified: <03/13/22> 
Version: <version number 1.0>
[Acknowledgements: <https://www.programiz.com/c-programming/examples/fibonacci-series
					https://www.programiz.com/c-programming/examples/prime-number	>]
*/

#include <stdio.h>

/*Function Prototype*/
void withdrawal(int, int, float, float , float );
void mTransfer(int, int, float , float , float );
void forEx(int, int, float, float , float );
void bPayment(int, int, float, float, float);
void onlineshop(int, int, float, float, float);
void logout(int, int , float, float, float);
void newtransaction(int, int, float, float, float);
void displayUI(float , float);
void menu(int, int, float, float, float);

/*
	<This Function displays the Login header>
*/

void displayHeader()
{
	printf("%51s\n", " -------------------------------");
	printf("%50s\n", " Bank X Digital Banking System");
	printf("%51s\n\n", " -------------------------------");
	printf("%39s\n\n", "L O G I N");
}

/*	
	<This function displays the GUI once the user succesfully logged in, this includes the 
	features of the program and the available money (balance and forexbalance) of the digital bank (Kiosk).>

	@param <bal> <to display the existing balance of the digital bank(kiosk)>
	@param <forexbal> <to display the existing foreign exchange balance of the digital bank(kiosk)>
*/

void displayUI (float bal, float forexbal)
{
	printf("%29s\n", "\n--------------------------------------------------------------------------------");
	printf( " Bank X Digital Banking System - Remaining Balance: %.2f PHP, %.2f ForEx ", bal, forexbal);
	printf("%29s\n", "\n--------------------------------------------------------------------------------");
	printf("%44s\n","[1] Withdrawal");
	printf("%46s\n", "[2] Money Transfer");
	printf("%52s\n", "[3] Foreign Currency Exchange");
	printf("%46s\n", "[4] Bills Payment"); 
	printf("%44s\n", "[5] Online Shop"); 
	printf("%42s\n", "[6] Logout");
	printf("%29s\n\n", "-------------------------------------------------------------------------------");
	printf(" Enter your Choice: ");
}

/*
	<This Function recognizes the choice of the user from displayUI ()>
	Precondition: All positive integers and non characters
	@param <pin> < this param is used to be recognized in doing another
	 			 transaction since pin will be needed to be input once again>
	@param <uid> <this param is used to be recognized in doing a specific feature>
	@param <bal> <Kiosk Balance: to store the existing balance of the whole program, 
				this also helps to update the bal in displayUI() and throughout the program>
	@param <forexbal> <Foreign Exchange Balance: to store the existing foreign exchange balance of the whole program, 
					this also helps to update the forexbal in displayUI() and throughout the program>
	@param <accbal> <User's Account Balance:to store the existing balance of the user in the whole program, 
					this also helps to update the balance of the user in displayUI() and throughout the program>
*/  

void menu (int pin, int uid, float bal, float forexbal, float accbal)
{
	int choice, choice2;
	displayUI(bal, forexbal);
	scanf("%d", &choice);
		switch(choice)
		{
			case 1: withdrawal(pin, uid, bal, accbal,forexbal); break;
			case 2: mTransfer(pin, uid, bal, accbal, forexbal);break;
			case 3: forEx(pin, uid, forexbal, bal, accbal); break;
			case 4: bPayment(pin, uid, forexbal,  accbal,  bal); break;
			case 5: onlineshop(pin, uid, forexbal, bal, accbal);break;
			case 6: logout( pin, uid, bal, forexbal, accbal);break;
			default: printf(" Error! Invalid Choice!");
	printf(" \n\n Do you want to do another transaction?\n"); /*Allows another transcation*/
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1: newtransaction( pin, uid, bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!\n"); break;
		default: printf(" Error! Invalid Choice!"); break;
	}	
}
}

/*
	<This fucntion allows the user to withdraw their money from the digital bank (kiosk)>
	Precondition: All positive integers and non characters
	@param <pin> <this param is used to be recognized in doing another
				transaction since pin will be needed to be input once again>
	@param <uid> <this param is used to store its value in doing another transaction>
	@param <bal> <Kiosk balance where an amount will be deducted to it.>
	@param <accbal> <User's account balance where an amount will be deducted to it>			 
	@param <forexbal> <retains the value of foreign exchange balance and will be used in newtranscation()>
	@return the new balance of the user and kiosk, and the withdrew amount 
*/

void withdrawal(int pin, int uid, float bal, float accbal, float forexbal)
{
	float amount;
	int wchoice;
	
	printf("----------------------------------------------------------------------");
	printf("\n%40s","WITHDRAWAL\n");
	printf("----------------------------------------------------------------------");
	printf("\n Enter Amount: ") ;
	scanf("%f", &amount);
	if (amount<=accbal && amount<=bal && amount>=0) /*Checks if the amount is over 1000 and 5000*/
	{
	accbal=accbal-amount;
	bal=bal-amount;
	printf("\n You withdraw an amount of %.2f PHP\n", amount);
	printf("\n Your new balance is now %.2f PHP", accbal);
	printf("\n The kiosk's new balance is %.2f PHP", bal);
	}
	else
	{
	printf("\n Error! Insufficient Balance!");
	}
	printf(" \n\nDo you want to do another transaction?\n"); /*Allows new transaction*/
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &wchoice); 
	switch (wchoice)
	{
		case 1: newtransaction( pin,uid,bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!\n"); break;
		default: printf(" Error! Invalid Choice!"); break;
	}
}

/*
	<This function allows the user to transfer a money to another user>
	Precondition: All positive integers and non characters
	@param <pin> <this param is used to be recognized in doing another
			transaction since pin will be needed to be input once again>
	@param <uid> <this param is used to recognize the uid of the other user and the user itself>
	@param <bal> <Kiosk balance where an amount will be deducted to it.>
	@param <accbal> <User's account balance where an amount will be deducted to it>			 
	@param <forexbal> <to retain the value of foreign exchange balance, and will be used in newtranscation()>
	@return the new balance of the user and kiosk, and the other user
*/

void mTransfer(int pin, int uid, float bal, float accbal, float forexbal)
{
	int mtuid, mtchoice; 
	float tamount, otherbal=1000; 
	printf("\n----------------------------------------------------------------------");
	printf("\n%42s"," MONEY TRANSFER\n");
	printf("----------------------------------------------------------------------");
	printf("\n Enter the uid where you want to transfer the money: ");
	scanf("%d", &mtuid);
	/*checks if the uid exist and uid is not similar to what the user's uid*/
			if (mtuid==315 && mtuid!=uid || mtuid==975 && mtuid!=uid 
		|| mtuid==269 && mtuid!=uid|| mtuid==503 && mtuid!=uid
		|| mtuid==172 && mtuid!=uid || mtuid==644&& mtuid!=uid 
		|| mtuid==211 && mtuid!=uid || mtuid==820 && mtuid!=uid
		|| mtuid==610 && mtuid!=uid || mtuid==987 && mtuid!=uid)
	{
	printf(" Enter Amount: ");
	scanf("%f", &tamount);
	if(tamount<=accbal && tamount>=0){ /*check if the amount is not over 1000*/		
	accbal=accbal-tamount;
	bal=bal-tamount;
	otherbal=otherbal+tamount;
	printf("\n You transferred an amount of %.2f PHP\n ", tamount);
	printf(" \n Your new balance is %.2f PHP", accbal);
	printf(" \n The uid: %d has now a balance of %.2f PHP", mtuid, otherbal);
	printf("\n The kiosk's new balance is %.2f PHP", bal);}
		else{
		printf(" Error! Insufficient Balance!");
	}
	}
	else{  
		printf("\n Error! Invalid User!\n\n");
	}
	printf(" \n\nDo you want to do another transaction?\n"); /*allows new transaction*/
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &mtchoice);
	switch (mtchoice)
	{
		case 1: newtransaction(pin,uid, bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!\n"); break;
		default: printf(" Error!Invalid Choice!"); break;
	}
}

/*
	<This Function converts a Foreign currency to peso, and the user will be able to withdraw the converted money>
	Precondition: All positive integers and non characters
	@param <pin> <this param is used to be recognized in doing another
			transaction since pin will be needed to be input once again>
	@param <uid> <this param is used to store its value in doing another transaction>
	@param <bal> <Kiosk Balance: this param is used to store and retain its value in doing another transcation>
	@param <accbal> <User's account balance where an amount will be deducted to it>			 
	@param <forexbal> <A balance specific for foreign exchange currency wherein an amount will be deducted to it>
	@return the new balance of the user and Kiosk foreign exchange, and the withdrew converted amount
*/

void forEx(int pin, int uid, float forexbal, float bal, float accbal)
{
	float amount, newbal, converted, TAX=0.12;
	float usd, jyp, gbp, hkd, chf;
	int choice, fechoice;
	
	printf("\n----------------------------------------------------------------------");
	printf("\n%49s"," FOREIGN CURRENCY EXCHANGE\n");
	printf("----------------------------------------------------------------------");
	printf("%s\n", "\nFollowing Currency Available:\n ");
	printf("%42s\n", "[1] US Dollar (USD)");
	printf("%44s\n", "[2] Japanese Yen (JYP)");
	printf("%49s\n", "[3] British Pound Sterling (GBP)");
	printf("%47s\n", "[4] Hong Kong Dollar (HKD)");
	printf("%43s\n", "[5] Swiss franc (CHF)");
	printf("\n Enter the currency to convert the amount you want to withdraw: ");
	scanf("%d", &choice);
	printf(" Enter the amount you want to withdraw: ");
	scanf("%f", &amount);
	
	switch(choice)
	{
		case 1: 	
		converted=amount*58.4060;						/*converts(USD)amount into peso */
		forexbal=forexbal-(converted+(converted*TAX));  /*Computes total with the tax*/
		accbal=accbal-(converted+(converted*TAX));		/*Computes total with the tax*/
		usd=converted;
		if(converted>=0 && converted<=1000){			/*checks if amount is not over 1000*/
		printf("\n You withdraw an amount of %.2f USD = %.2f PHP\n", amount, usd);
		printf("\n Your new balance is %.2f PHP", accbal);
		printf("\n The kiosk's new balance is %.2f PHP", forexbal);}
		else{
			printf(" \n Error! Insufficient Balance");
		}
 		break; 
 		
		case 2:
		converted=amount*0.4104;							/*converts(JYP)amount into peso */
		forexbal=forexbal-(converted+(converted*TAX));		/*Computes total with the tax*/
		accbal=accbal-(converted+(converted*TAX));			/*Computes total with the tax*/
		jyp=converted;
		if(converted>=0 && converted<=1000){				/*checks if amount is not over 1000*/
		printf("\n You withdraw an amount of %.2f JYP = %.2f PHP\n", amount, jyp);
		printf("\n Your new balance is %.2f PHP", accbal);
		printf("\n The kiosk's new balance is %.2f PHP", forexbal);}
		else{
			printf(" \n Error! Insufficient Balance!");
		}
 		break; 
 		
 		case 3:														/*converts(GBP)amount into peso */
 		converted=amount*65.7418;
		forexbal=forexbal-(converted+(converted*TAX));				/*Computes total with the tax*/
		accbal=accbal-(converted+(converted*TAX));					/*Computes total with the tax*/
		gbp=converted;
		if(converted>=0 && converted<=1000){						/*checks if amount is not over 1000*/
		printf("\n\n You withdraw an amount of %.2f GBP = %.2f PHP\n", amount, gbp);
		printf("\n Your new balance is %.2f PHP", accbal);
		printf("\n The kiosk's new balance is %.2f PHP", forexbal);}
		else{
			printf(" \n Error! Insufficient Balance!");
		}
 		break; 
		 
		 case 4:
		converted=amount*7.4413;									/*converts(HKD)amount into peso */
		forexbal=forexbal-(converted+(converted*TAX));				/*Computes total with the tax*/
		accbal=accbal-(converted+(converted*TAX));					/*Computes total with the tax*/
		hkd=converted;
		if(converted>=0 && converted<=1000){						/*checks if amount is not over 1000*/
		printf("\n You withdraw an amount of %.2f HKD = %.2f PHP\n", amount, hkd);
		printf("\n Your new balance is %.2f PHP", accbal);
		printf("\n The kiosk's new balance is %.2f PHP", forexbal);
		}
		else{
			printf(" \n Error! Insufficient Balance!");
		}
 		break; 	
 		
 		case 5:
		converted=amount*59.7809;									/*converts(CHF)amount into peso */
		forexbal=forexbal-(converted+(converted*TAX));				/*Computes total with the tax*/
		accbal=accbal-(converted+(converted*TAX));					/*Computes total with the tax*/
		chf=converted;
		if(converted>=0 && converted<=1000){						/*checks if amount is not over 1000*/
		printf("\n You withdraw an amount of %.2f CHF = %.2f PHP\n", amount, chf);
		printf("\n Your new balance is %.2f PHP", accbal);
		printf("\n The kiosk's new balance is %.2f PHP", forexbal);}
		else{
			printf(" \n Error! Insufficient Balance");
		}
 		break; 
 		default: printf(" Invalid Choice!");break;
	}
	printf(" \n\nDo you want to do another transaction?\n"); /*Allows user new transcation*/
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &fechoice);
	switch (fechoice)
	{
		case 1: newtransaction( pin, uid, bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!\n"); break;
		default: printf(" Error! Invalid Choice!"); break;
	}
}

/*
	<This function allows the user to pay their bills to different corporations with 5% interest, 
	however corporations depends on their uid>
	Precondition: All positive integers and non characters
	@param <pin> <this param is used to be recognized in doing another
			transaction since pin will be needed to be input once again>
	@param <uid> <this param is used to store its value in doing another transaction, 
				also this is the basis on what corporations are available for the user>
	@param <bal> <Kiosk balance where an amount will be deducted to it>
	@param <accbal> <User's account balance where an amount will be deducted to it with an additional of 5% interest>			 
	@param <forexbal> <Foreign Exchange Balance: this param is used to store and retain its value in doing another transcation>
	@return the new balance of the user and kiosk foreign exchange, and the amount of paid bills
*/

void bPayment( int pin, int uid, float forexbal, float accbal, float bal)
{
	float amount, interest=0.05, tamount;
	int j=0, i, a=0, b=1, c;
	int bpchoice, bpchoice2;
	printf("%29s\n", "\n-------------------------------------------------------------------------------");
	printf( "  Bank X Digital Banking System - Remaining Balance: %.2f PHP, %.2f ForEx ", bal, forexbal);
	printf("%29s\n", "\n-------------------------------------------------------------------------------");
	printf("                           Bills Payment (User: %d)", uid);
	printf("\n              -------------------------------------------------\n\n");
	
	if (uid % 3 == 0 && uid % 5== 0)					/*Checks if uid divisible by 3 and 5*/
	{
	printf("%56s","Select an available biller: \n\n");
	printf("%48s","[1] Cebu Pacific\n");
	printf("%58s", "[2] Philcare (Philhealth care) Inc.\n");
	printf("%49s", "[3] Paramount Life\n");
	printf("%48s", "[4] Loyola Plans\n");
	printf("%48s", "[5] ICC-Bayantel\n");
	printf("%44s", "[6] Back\n");
	printf("%29s\n", "\n-------------------------------------------------------------------------------");
	printf("\n Enter choice: ");
	scanf("%d", &bpchoice);
	
	switch (bpchoice){
		case 1: 
		printf("\n Cebu Pacific\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){								/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);				/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Cebu Pacific \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 2: 
		printf("\n Philcare (Philhealth care) Inc.\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Philcare (Philhealth care) Inc.\n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 3: 		
		printf("\n Paramount Life\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Paramount Life \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error!Insuficient Balance!");
		}
		break;
		
		case 4: 		
		printf("\n Loyola Plans\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Loyola Plans \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 5: 		
		printf("\n ICC-Bayantel\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){										/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);						/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to ICC-Bayantel \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 6: menu(pin, uid, bal,forexbal, accbal); break;			/*back option*/
		default: printf(" Error! Invalid Choice!");break;
	}
	}
	else{
		for (i = 1; i <= uid; i++) {
      if (uid % i == 0) {
         j++;
      }
	}
  if (j == 2) {								/* Checks if uid is Prime Numbers*/
  		printf("%56s","Select an available biller: \n\n");
        printf("%48s","[1] Cebu Pacific\n");
		printf("%58s", "[2] Philcare (Philhealth care) Inc.\n");
		printf("%49s", "[3] Paramount Life\n");
		printf("%54s", "[4] Toyota Financial Services\n");
		printf("%58s", "[5] Bankard-RCBC/JCB/Mastercard/Visa\n");
		printf("%47s", "[6] City Loft\n");
		printf("%44s", "[7] Back\n");
		printf("%29s\n", "-------------------------------------------------------------------------------");
		printf("\n Enter choice: ");
		scanf("%d", &bpchoice);
		switch (bpchoice){
		
		case 1: 
		printf("\n Cebu Pacific\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){									/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);					/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n\n You have successfully paid an amount of %.2f PHP to Cebu Pacific \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 2: 
		printf("\n Philcare (Philhealth care) Inc.\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){										/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);						/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Philcare (Philhealth care) Inc. \n", tamount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 3: 		
		printf("\n Paramount Life\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&& amount >=0){								/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);				/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Paramount Life \n", tamount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 4: 		
		printf("\n Toyota Financial Services\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){									/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);					/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Toyota Financial Services \n", tamount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 5: 		
		printf("\n Bankard-RCBC/JCB/Mastercard/Visa\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){									/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);					/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Bankard-RCBC/JCB/Mastercard/Visa \n", tamount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 6: 		
		printf("\n City Loft\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){								/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);				/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to City Loft \n", tamount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 7: menu(pin, uid, bal,forexbal, accbal); break;			/*back option*/
		default: printf(" Error! Invalid Choice!");break;
	}	
}
  	else if (uid%4==0){						/*Checks if uid is a Composite Number and Divisible by 4*/
  		printf("%56s","Select an available biller: \n\n");
		printf("%48s","[1] Cebu Pacific\n");
		printf("%58s", "[2] Philcare (Philhealth care) Inc.\n");
		printf("%49s", "[3] Paramount Life\n");
		printf("%53s", "[4] Unionbank Credit Cards\n");
		printf("%46s", "[5] Unistar\n");
		printf("%44s", "[6] Back\n");
		printf("%29s\n", "-------------------------------------------------------------------------------");
		printf("\n Enter choice: ");
		scanf("%d", &bpchoice);
		switch (bpchoice){
			
		case 1: 
		printf("\n Cebu Pacific\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal && amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n\n You have successfully paid an amount of %.2f PHP to Cebu Pacific \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 2: 
		printf("\n Philcare (Philhealth care) Inc.\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Philcare (Philhealth care) Inc. \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 3: 		
		printf("\n Paramount Life\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Paramount Life \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 4: 
		printf("\n Unionbank Credit Cards\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){												/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);								/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n\n You have successfully paid an amount of %.2f PHP to Unionbank Credit Cards \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 5: 
		printf("\n Unistar\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){										/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);						/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Unistar \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 6:menu(pin, uid, bal,forexbal, accbal); break;		/*back option*/
		default: printf(" Error! Invalid Choice!");break;
 	 }
	}
  else{							
   c=a+b;
   while(c<uid)
   {
   	a=b;
   	b=c;
    c=a+b;
   }
   if(c==uid){									/*Checks if number is included in Fibonacci Sequence*/
   	printf("%56s","Select an available biller: \n\n");
	printf("%48s","[1] Cebu Pacific\n");
	printf("%58s", "[2] Philcare (Philhealth care) Inc.\n");
	printf("%49s", "[3] Paramount Life\n");
	printf("%53s", "[4] HSCBC Personal Loans\n");
	printf("%46s", "[5] Easytrip\n");
	printf("%48s", "[6] PSBank Loans\n");
	printf("%44s", "[7] PLDT\n");
	printf("%44s", "[8] Back\n");
		printf("%29s\n", "-------------------------------------------------------------------------------");
		printf("\n Enter choice: ");
		scanf("%d", &bpchoice);
		switch (bpchoice){
		
		case 1: 
		printf("\n Cebu Pacific\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){										/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);						/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n\n You have successfully paid an amount of %.2f PHP to Cebu Pacific \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 2: 
		printf("\n Philcare (Philhealth care) Inc.\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){										/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);								/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Philcare (Philhealth care) Inc. \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 3: 		
		printf("\n Paramount Life\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){										/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);						/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to Paramount Life \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 4: 
		printf("\n HSCBC Personal Loans\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to HSCBC Personal Loans \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 5: 
		printf("\n Easytrip\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){									/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);					/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\nYou have successfully paid an amount of %.2f PHP to Easy Trip \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 6: 
		printf("\n PSBank Loans\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){								/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);				/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to PSBank Loans \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
		}
		break;
		
		case 7: 		
		printf("\n PLDT\n");
		printf(" Enter Amount: ");
		scanf("%f", &amount);
		if (amount<=accbal&&amount>=0){											/*checks amount is not over 1000*/
			tamount=amount+(amount*interest);							/*computes total with 5% interest*/
			accbal=accbal-tamount;
			bal=bal-tamount;
			printf("\n You have successfully paid an amount of %.2f PHP to PLDT  \n", amount);
			printf(" Your new balance is now %.2f PHP\n", accbal);
			printf(" The kisok's new balance is no %.2f PHP", bal); 	
		}
		else {
			printf(" Error! Insuficient Balance!");
			}
		break;
		
		case 8: menu(pin, uid, bal,forexbal, accbal); break;		/*back option*/
		default: printf(" Error! Invalid Choice!");break;
			}
		}
   	}
}
  	printf(" \n\n Do you want to do another transaction?\n");		/*Allow the user new transaction*/
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &bpchoice2);
	switch (bpchoice2)
	{
		case 1: newtransaction(pin, uid, bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!"); break;
		default: printf(" \n Error! Invalid Choice!"); break;
	}	
} 

/*
	<This Function is invalid>
		@param <pin> <this param is used to be recognized in doing another
			transaction since pin will be needed to be input once again>
		@param <uid> <this param is used to store and retain its value in doing another transcation>
		@param <forexbal> <Foreign Exchange Blance: this param is used to store and retain its value in doing another transcation>
		@param <bal> <Kiosk Balance: this param is used to store and retain its value in doing another transcation>
		@param <accbal> <User's Account Balance: this param is used to store and retain its value in doing another transcation>
*/

void onlineshop (int pin, int uid, float forexbal, float bal, float accbal)
{
	int oschoice;
	printf("\n Invalid Choice. Try Again!");
	printf(" \n\n Do you want to do another transaction?\n");
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &oschoice);
	switch (oschoice)
	{
		case 1: newtransaction( pin, uid, bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!"); break;
		default: printf(" \n Error! Invalid Choice!\n"); break;
	}	
}

/*
 	<This function do either terminate the program or not>
 	
 	@param <pin> <If the user did not chose to logout, thus, this param is used to store and retain its value for another feature>
	@param <uid> <If the user did not chose to logout, this param is used to store and retain its value for another feature>
	@param <forexbal> <Foreign Exchange Balance: this param is used to store and retain its value for another feature>
	@param <bal> <Kiosk Balance: this param is used to store and retain its value for another feature>
	@param <accbal> <User's Account Balance: this param is used to store and retain its value for another feature>
*/

void logout(int pin, int uid, float bal, float forexbal, float accbal)
{
	int choice, lochoice;
	printf("\n Are you done using the system?\n");
	printf(" [1] Yes\n");
	printf(" [2] No\n");
	printf(" Choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1: printf("\n Thank You for using the system!");break;	
		case 2: menu ( pin, uid, bal, forexbal,accbal); break;
		default: printf(" \n Error! Invalid Choice!");
		printf(" \n\n Do you want to do another transaction?\n");		/*Allow the user new transaction*/
	printf(" [1] Yes\n");
	printf(" [2] No\n\n");
	printf(" Enter your choice: ");
	scanf("%d", &lochoice);
	switch (lochoice)
	{
		case 1: newtransaction(pin, uid, bal, forexbal, accbal); break;
		case 2: printf(" \n Thank You!"); break;
		default: printf(" \n Error! Invalid Choice!"); break;
	}	break;
	}	
}

/*
	This function allows the user to do another transaction after a specific transaction 
	Precondition: All positive integers and non characters
	param <pin> <to check the value of pin in this function is equal to the pin in main()>
	param <uid> <stores the original value of uid as this will be used for billspayment ();
	param <bal> <Kiosk Balance:updates and stores the existing value of bal as this param will be used in another function>
	param <forexbal> <Foreign Exchange Balance: updates and stores the existing value of forexbal as this param will be used in another function>
	param <accbal> <User's Account Balance: updates and stores the remaining balance of user's bal as this param will be used in another function>
*/

void newtransaction (int pin, int uid, float bal, float forexbal, float accbal)
	{ 
	int ntchoice, npin;				
	printf(" Enter pin: ");					/*First Try*/
	scanf("%d", &npin);
       if ( npin==pin){						/*checks if the initial pin is equal to original pin*/
	printf("%29s\n", "\n--------------------------------------------------------------------------------");
	printf( " Bank X Digital Banking System - Remaining Balance: %.2f PHP, %.2f ForEx ", bal, forexbal );
	printf("%29s\n", "\n--------------------------------------------------------------------------------");
	printf("%42s\n","[1] Withdrawal");
	printf("%44s\n", "[2] Money Transfer");
	printf("%50s\n", "[3] Foreign Currency Exchange");
	printf("%44s\n", "[4] Bills Payment"); 
	printf("%42s\n", "[5] Online Shop"); 
	printf("%40s\n", "[6] Logout");
	printf("%29s\n\n", "-------------------------------------------------------------------------");
	printf(" Enter your Choice: ");
	scanf("%d", &ntchoice);

	switch (ntchoice)
	{
			case 1: withdrawal(pin, uid, bal, accbal,  forexbal); break;
			case 2: mTransfer(pin, uid,  bal, accbal, forexbal);break;
			case 3: forEx(pin,uid, forexbal,  bal, accbal); break;
			case 4: bPayment( pin, uid, forexbal,  accbal,  bal); break;
			case 5: onlineshop(pin, uid, forexbal, bal, accbal);break;
			case 6: logout(pin, uid, bal, forexbal, accbal);break;
			default: printf(" Invalid Choice!");break;
		}
	}
	else {
		printf("   \n Login Failed! Please try again.\n\n");			/*Second Try*/
		printf(" Enter pin: ");
		scanf("%d", &npin);
       if ( npin==pin){									/*checks if the initial pin is equal to original pin*/
		printf("%29s\n", "\n--------------------------------------------------------------------------------");
		printf( " Bank X Digital Banking System - Remaining Balance: %.2f PHP, %.2f ForEx ", bal, forexbal );
		printf("%29s\n", "\n--------------------------------------------------------------------------------");
		printf("%42s\n","[1] Withdrawal");
		printf("%44s\n", "[2] Money Transfer");
		printf("%50s\n", "[3] Foreign Currency Exchange");
		printf("%44s\n", "[4] Bills Payment"); 
		printf("%42s\n", "[5] Online Shop"); 
		printf("%40s\n", "[6] Logout");
		printf("%29s\n\n", "-------------------------------------------------------------------------");
		printf(" Enter your Choice: ");
		scanf("%d", &ntchoice);

		switch (ntchoice)
			{
				case 1: withdrawal(pin, uid, bal, accbal,  forexbal); break;
				case 2: mTransfer(pin, uid,  bal, accbal, forexbal);break;
				case 3: forEx(pin,uid, forexbal,  bal, accbal); break;
				case 4: bPayment( pin, uid, forexbal,  accbal,  bal); break;
				case 5: onlineshop(pin, uid, forexbal, bal, accbal);break;
				case 6: logout(pin, uid, bal, forexbal,  accbal);break;
				default: printf(" Error! Invalid Choice!");break;
			}
		}
		else {
			printf("   \n Login Failed! Please try again.\n\n");			/*Third Try*/
			printf(" Enter pin: ");
			scanf("%d", &npin);
       			if ( npin==pin){							/*checks if the initial pin is equal to original pin*/
				printf("%29s\n", "\n--------------------------------------------------------------------------------");
				printf( " Bank X Digital Banking System - Remaining Balance: %.2f PHP, %.2f ForEx ", bal, forexbal );
				printf("%29s\n", "\n--------------------------------------------------------------------------------");
				printf("%42s\n","[1] Withdrawal");
				printf("%44s\n", "[2] Money Transfer");
				printf("%50s\n", "[3] Foreign Currency Exchange");
				printf("%44s\n", "[4] Bills Payment"); 
				printf("%42s\n", "[5] Online Shop"); 
				printf("%40s\n", "[6] Logout");
				printf("%29s\n\n", "-------------------------------------------------------------------------");
				printf(" Enter your Choice: ");
				scanf("%d", &ntchoice);

				switch (ntchoice)
				{
					case 1: withdrawal(pin, uid, bal, accbal,  forexbal); break;
					case 2: mTransfer(pin, uid,  bal, accbal, forexbal);break;
					case 3: forEx(pin,uid, forexbal,  bal, accbal); break;
					case 4: bPayment( pin, uid, forexbal,  accbal,  bal); break;
					case 5: onlineshop(pin, uid, forexbal, bal, accbal);break;
					case 6: logout( pin, uid, bal, forexbal, accbal);break;
					default: printf(" Error! Invalid Choice!");break;
				}
			}
		else {
			printf("   \n Login Failed! Stolen Card!\n\n");
		}
		}
		}
	}

/*	
	Main Function
	Precondition: All positive integers and non characters
*/
int main()
{
	int uid, pin, choice, choice2;
	float bal=5000, forexbal=3000, accbal=1000; 
	displayHeader();
	printf("%37s", "  Enter user id: "); 							/*first Try*/
	scanf("%d", &uid);
	printf("%38s", "  Enter your pin: ");
	scanf("%d", &pin);
	printf("%51s\n", " -------------------------------");
	
		if (uid==315 && pin==111111 || uid==975 && pin==222222 		/*Provided Account include UID and PIN*/
		||uid==269 && pin==333333|| uid==503 && pin==444444 
		|| uid==172 && 555555 || uid==644 && pin==777777 
		|| uid==211 && pin== 666666|| uid==820&& pin==888888 
		|| uid==610 && pin== 999999 || uid==987 && pin==101010)
	{			
	printf("   \n Login Successfully!\n");
	menu(pin, uid, bal, forexbal, accbal);}
	else{
		printf("   \n Login Failed! Please try again.\n\n");		/*Second Try*/
		displayHeader();
		printf("%37s", "  Enter user id: ");
		scanf("%d", &uid);
		printf("%38s", "  Enter your pin: ");
		scanf("%d", &pin);
		printf("%51s\n", " -------------------------------");
	
		if (uid==315 && pin==111111 || uid==975 && pin==222222 		/*Provided Account include UID and PIN*/
		||uid==269 && pin==333333|| uid==503 && pin==444444 
		|| uid==172 && 555555 || uid==644 && pin==777777 
		|| uid==211 && pin== 666666|| uid==820&& pin==888888 
		|| uid==610 && pin== 999999 || uid==987 && pin==101010 )
	{			
	printf("   \n Login Successfully!\n");
	menu(pin, uid, bal, forexbal, accbal);
		}	
		else{
			printf("   \n Login Failed! Please try again.\n\n");		/*Third Try*/
		displayHeader();
		printf("%37s", "  Enter user id: ");
		scanf("%d", &uid);
		printf("%38s", "  Enter your pin: ");
		scanf("%d", &pin);
		printf("%51s\n", " -------------------------------");
	
	if (uid==315 && pin==111111 || uid==975 && pin==222222 				/*Provided Account include UID and PIN*/
		||uid==269 && pin==333333|| uid==503 && pin==444444 
		|| uid==172 && 555555 || uid==644 && pin==777777 
		|| uid==211 && pin== 666666|| uid==820&& pin==888888 
		|| uid==610 && pin== 999999 || uid==987 && pin==101010 )
	{			
	printf("   \n Login Successfully!\n");
	menu(pin, uid, bal, forexbal, accbal);
	}
		else{
			printf("   \n Login Failed! Stolen Card!\n\n");
			}
		}
	}
	return 0;
}


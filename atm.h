void home()
{
	printf("\t\t\t************WELCOME TO ATM************\n");
	printf("\t\t\t--------------------------------------\n\n");
	printf("\t\t\t>>Enter Your Card\n");
}
void choice()
{
	printf("\t\t\t>>Press 'B' for Balance Inquiry\n");
	printf("\t\t\t>>Press 'W' for Withdraw\n");
	printf("\t\t\t>>Press 'F' for fast Cash\n");
	printf("\t\t\t>>Press 'C' to Change Pin Code\n");
	printf("\t\t\t>>Press 'A' to Add Money.\n");
}
void fastCash()
{
	printf(">>Enter 1 for 1000\t\t\t>>Enter 2 for 2000\n>>Enter 3 for 5000\t\t\t>>Enter 4 for 10000\n");
}
void new_balance(int x)
{
	FILE *nfp;
	if((nfp=fopen("ac.txt","r"))==0){
		printf("Not able to access.");
		exit(0);
	}
	int bal=getw(nfp);
	fclose(nfp);
	if((nfp=fopen("ac.txt","w"))==0){
		printf("Not able to access.");
		exit(0);
	}
	putw(bal-x,nfp);
}

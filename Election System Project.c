#include <stdio.h>
#include <string.h>
#include <process.h>

struct party
{
	char name[40] ;
	int code, vc;
} pt;

FILE *fp;

int retPcode()
{
	return pt.code;
}

int retVC()
{
	return pt.vc;
}

char* retName()
{
	return pt.name;
}

/* Write records into binary file */
void Enter()
{	
	char another = 'Y' ;
	pt.vc=0;
	fp = fopen ( "EVOTING.DAT", "a+b" ) ;
	if ( fp == NULL )
		puts ( "Cannot open file" ) ;
	while ( another == 'Y' || another == 'y')
	{
		printf ( "\nEnter Political Party name and Party Code: " ) ;
		scanf ( "%s %d", pt.name, &pt.code) ;
		fwrite ( &pt, sizeof ( pt ), 1, fp ) ;
		printf ( "Add another record (Y/N) " );
		fflush ( stdin ) ;
		another = getche( ) ;
	}
	fclose ( fp ) ;
}

/* Reads records from binary file and displays them on VDU */
void Display()
{
	fp = fopen ( "EVOTING.DAT", "rb" ) ;
	if ( fp == NULL )
		puts ( "Cannot open file" ) ;
	printf("\n Code \t Name \t Vote Count");
	while ( fread ( &pt, sizeof ( pt ), 1, fp ) == 1 )
	printf ( "\n %d \t %s \t %d", pt.code, pt.name, pt.vc ) ;
	fclose ( fp ) ;
}

void CastVote()
{
	int pv, cd, pos;
	fp = fopen ( "EVOTING.DAT", "rb" ) ;
	if ( fp == NULL )
		puts ( "Cannot open file" ) ;
	printf("\n Code \t Name");
	while ( fread ( &pt, sizeof ( pt ), 1, fp ) == 1 )
	printf ( "\n %d \t %s", pt.code, pt.name) ;
	fclose ( fp ) ;
	
	printf("\n ======== Cast your Vote ======= ");
	printf("\n Enter the code for party: ");
	scanf("%d", &cd);
	
	fp = fopen("EVOTING.DAT","r+w");
	while(fread(&pt,sizeof(pt), 1, fp) == 1)
	{
		if(retPcode()==cd)
		{
			pv=retVC();
			pos=sizeof(pt);
			pt.vc=pv+1;
			fseek(fp,-pos,SEEK_CUR);
			fwrite(&pt,sizeof(pt),1, fp);
			break;
		}
	}
	fclose(fp);
	printf("\n Thanks for your vote......\n\n");
}

void Result()
{
	int maxCode=0, maxVote=0;
	char *n;
	
	fp = fopen("EVOTING.DAT","r+w");
	while(fread(&pt,sizeof(pt), 1, fp) == 1)
	{
		if(retVC()>maxVote)
		{
			maxVote=retVC();
			strcpy(n, retName());
			maxCode=retPcode();
		}
	}
	fclose(fp);
	
	printf("\n === Winner Party ===\n");
	printf("\n\t%d-%s with %d Votes\n\n", maxCode, n, maxVote);
}


void main( )
{
	int ch;
	
	do
	{
		printf("\n =========== MENU ==========");
		printf("\n 1. Enter Party Details ");
		printf("\n 2. Display Party Details ");
		printf("\n 3. Cast Vote ");
		printf("\n 4. Results ");
		printf("\n 0. Exit ");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				Enter(); break;
			case 2:
				Display(); break;
			case 3:
				CastVote(); break;
			case 4:
				Result(); break;
			case 0: 
				exit(0);
		}
	}while(ch!=0);
}

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int Key[11],Rndr[12]={10000,10000,10000,100000,1000,100,10,100,10000,10000,10000,1000};
int key,rndr;
char book[20],lowercheck='u';

/*Key[11] holds the key for computer
Rndr[12] is useful for randomizing the key
key is for showing it to the user
rndr is used for seeding srand
book[20] will hold the name of book selected*/

struct Node
/*Node-for the linked list
data-stores the character
*next-stores the link of next
*/
{
        char cdata;
        int idata;
        int iorc;
    struct Node *next; }*first=NULL;
    struct Node *t,*curr;

void create()
//creates a first node
{

    first=(struct Node *)malloc(sizeof(struct Node));
    first->next=NULL;
    t=first;
    }
void nxt()
//creates the next node |t|
{
    t->next=(struct Node *)malloc(sizeof(struct Node));
    t=t->next;
    t->iorc=0;
    t->cdata='-';
    t->next=(struct Node *)malloc(sizeof(struct Node));
    t=t->next;
    t->next=NULL;
}
void showall()
{
    t=first;
    while(t!=NULL)
    {
        if(t->iorc==0)
        {
            printf("%c",t->cdata);
        }
        else
        {
            printf("%d",t->idata);
        }
        t=t->next;
    }
}
void postscript()
{
    printf("");
}
void clearall()
{
    curr=first;
    while(t!=NULL)
    {
        t=curr->next;
        free(curr);
        curr=t;
    }
}














int randm()
{
    rndr++;
    srand(rndr);
    rndr=rand();
    return rndr%10000;
}

void clr()
//Clears the screen while taking a little delay for better transaction between functions than quick clearing.//
{
    rndr++;
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("@cls||clear");
}

void setkey()
/*
(1) Takes a random key.
(1) Remove the duplicate integers from the key ....
(2) Stores them in an array 'Key', sorted in ascending order.
*/
{

    //Variable Declaration//
    clr();
    int *i=(int*)malloc(4),*j=(int*)malloc(4),*k=(int*)malloc(4),*tkey=(int*)malloc(4);
    int arr[11]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    //setting  and printing key to a random value, this key will be visible to the user//
    *tkey=randm();
    *tkey=*tkey%Rndr[randm()%12];
    key=*tkey;
    printf("\n Key is : %d",key);
    printf("\n(Note this key safely for decryption. Otherwise decryption will not be possible)\n");

    //sorting a key in ascending order into an integer array, 'Key' using a spare array 'arr'//
    while(key>0)
    {
        *j=key%10;
        if(arr[*j]==-1)
            arr[*j]=1;
        key=key/10;
    }
    key=*tkey;
    *k=0;
    for(*i=0;*i<10;*i=*i+1)
    {
        if(arr[*i]==1)
        {
            Key[*k]=*i;
            *k=*k+1;
        }
    }
    Key[*k]=-1;
    free(i);
    free(j);
    free(k);
    free(tkey);
    //Last value of Key is set to -1 to find the end of the key.//
}

void encinp()
{
    //Takes the input of data and enters key and data into a temporary file.//
    FILE *tbe=(FILE *) malloc(sizeof(FILE));
    tbe=fopen("tempfile.txt","w");
    fprintf(tbe,"Key is - %d\n",key);
    char *data=(char *)malloc(sizeof(char)*1000);
    int check=1;
    while(check==1){
            check=2;
            printf("\n Enter data in turns of 1000 or less characters.\n ");
    scanf("%[^\n]",data);
    fputs(data,tbe);
    puts(data);
    fflush(stdin);
    printf("\n Enter 1 to enter more data. Enter any other key to continue. : ");
    scanf("%d",&check);
    fflush(stdin);
    }
    free(data);
    fprintf(tbe,"\n");
    fclose(tbe);
    free(tbe);
}
void usekey()
{
    char spccr[]={'1','2','3','4','5','6','7','8','9','0','=','q','w','e','r','t','y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','!','@','#','$','%','^','&','*','(',')','+','Q','W','E','R','T','Y','U','I','O','P','{','}','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M',',','.','/','<','>','?'};
    int i=0,x=1;
    t=first->next;
    while(Key[i]!=-1)
    {
        for(x;x<(Key[i]);x++)
        {
            t=t->next;
            t=t->next;
        }
        if (Key[i]==0)
        {
            struct Node *qw=first;
        first=(struct Node *)malloc(sizeof(struct Node));
        first->iorc=0;
        first->cdata=spccr[randm()%strlen(spccr)];
        first->next=(struct Node *)malloc(sizeof(struct Node));
        t=first->next;
        t->iorc=0;
        t->cdata='-';
        t->next=qw;
        x=0;
        }
        else{
        struct Node *qw=t->next;
        t->next=(struct Node *)malloc(sizeof(struct Node));
        t=t->next;
        t->iorc=0;
        t->cdata=spccr[randm()%strlen(spccr)];
        t->next=(struct Node *)malloc(sizeof(struct Node));
        t=t->next;
        t->iorc=0;
        t->cdata='-';
        t->next=qw;
        }
        x+=1;
        i+=1;
    }
}
void searit(char c)
{
    FILE *fptr=fopen(book,"r");

    if (fptr == NULL)
        {
            perror("Failed: ");
    }
    else
    {
    int pc=0,i;
	char cursor='g';
	fscanf(fptr,"%c",&cursor);
	while(((int)cursor<48) || ((int)cursor>58))
    {
        fscanf(fptr,"%c",&cursor);
    }
	while (cursor!='\n')
	{
		pc=(pc*10)+(int)cursor-48;
		fscanf(fptr,"%c",&cursor);
	}
	int pn;
	pn=randm()%(pc-1);
	pn++;
	for (i=1;i<pn;i++)
	{
    fscanf(fptr,"%c",&cursor);
    while(cursor!='\n')
		{
			fscanf(fptr,"%c",&cursor);
		}
	}
	char waste;
	justincase:
	    waste='w';
	int worc=1,posic=1,counting[100][2];
	cursor='a';
	i=0;
	while(cursor!='\n')
	{
		fscanf(fptr,"%c",&cursor);
		if (cursor==' ')
		{
			worc++;
			posic=0;
		}
		if (cursor==c)
		{
			counting[i][0]=worc;
			counting[i][1]=posic;
			i++;
		}
		posic++;
		if(i>=100)
		break;
		}
		if(i==0)
        {
            bser(c);
            return;
        }
		int j=randm()%i;
		t->idata=2;
		t->iorc=1;
		nxt();
		t->iorc=1;
		t->idata=j;
		nxt();
		t->iorc=1;
		t->idata=pn;
		nxt();
		t->iorc=1;
		t->idata=counting[j][0];
		nxt();
		t->iorc=1;
		t->idata=counting[j][1];
		nxt();
		t->iorc=0;
		t->cdata=lowercheck;
		usekey();
    }
}
void bser(char c)
{
    int n=randm()%4;
    int i,bc;
    switch(n)
    {
        case 0:
        book[0]='H';
        book[1]='R';
        book[2]='P';
        book[3]='R';
        create();
        t=first;
        for(i=0;i<4;i++)
        {
            t->cdata=book[i];
            t->iorc=0;
            nxt();
        }
        book[4]='(';
        t->cdata='(';
        t->iorc=0;
        nxt();
        bc=randm()%7;
        t->idata=bc+1;
        t->iorc=1;
        nxt();
        book[5]=49+bc;
        book[6]=')';
        t->cdata=')';
        t->iorc=0;
        nxt();
        book[7]='2';
        book[8]='.';
        book[9]='t';
        book[10]='x';
        book[11]='t';
        book[12]='\0';
        searit(c);
        break;

        case 1:
        book[0]='H';
        book[1]='N';
        book[2]='G';
        book[3]='M';
        create();
        t=first;
        for(i=0;i<4;i++)
        {
            t->cdata=book[i];
            t->iorc=0;
            nxt();
        }
        book[4]='(';
        t->cdata='(';
        t->iorc=0;
        nxt();
        bc=randm()%3;
        t->idata=bc+1;
        t->iorc=1;
        nxt();
        book[5]=49+bc;
        book[6]=')';
        t->cdata=')';
        t->iorc=0;
        nxt();
        book[7]='2';
        book[8]='.';
        book[9]='t';
        book[10]='x';
        book[11]='t';
        book[12]='\0';
        searit(c);
        break;

        case 2:
        book[0]='L';
        book[1]='C';
        book[2]='D';
        book[3]='N';
        create();
        t=first;
        for(i=0;i<4;i++)
        {
            t->cdata=book[i];
            t->iorc=0;
            nxt();
        }
        book[4]='(';
        t->cdata='(';
        t->iorc=0;
        nxt();
        bc=randm()%7;
        t->idata=bc+1;
        t->iorc=1;
        nxt();
        book[5]=49+bc;
        book[6]=')';
        t->cdata=')';
        t->iorc=0;
        nxt();
        book[7]='2';
        book[8]='.';
        book[9]='t';
        book[10]='x';
        book[11]='t';
        book[12]='\0';
        searit(c);
        break;

        case 3:
        book[0]='T';
        book[1]='L';
        book[2]='T';
        book[3]='R';
        create();
        t=first;
        for(i=0;i<4;i++)
        {
            t->cdata=book[i];
            t->iorc=0;
            nxt();
        }
        book[4]='(';
        t->cdata='(';
        t->iorc=0;
        nxt();
        bc=randm()%4;
        t->idata=bc+1;
        t->iorc=1;
        nxt();
        book[5]=49+bc;
        book[6]=')';
        t->cdata=')';
        t->iorc=0;
        nxt();
        book[7]='2';
        book[8]='.';
        book[9]='t';
        book[10]='x';
        book[11]='t';
        book[12]='\0';
        searit(c);

        }
}
void prser(char c)
{
    book[0]='S';
    book[1]='Q';
    if(c=='\n')
    {
        book[1]='P';
    }
    book[2]='2';
        book[3]='Y';
        create();
        t=first;
        int i;
        for(i=0;i<4;i++)
        {
            t->cdata=book[i];
            t->iorc=0;
            nxt();
        }
        book[4]='E';
        t->cdata='E';
        t->iorc=0;
        nxt();
        int bc;
        bc=randm()%7;
        t->idata=bc+1;
        t->iorc=1;
        nxt();
        book[5]=49+bc;
        book[6]='>';
        t->cdata='>';
        t->iorc=0;
        nxt();
        t->cdata=c;
		t->iorc=0;
		nxt();
		t->iorc=1;
		t->idata=9;
		nxt();
		t->iorc=0;
		t->cdata='e';
		nxt();
		t->iorc=1;
		t->idata=1;
		nxt();
		t->iorc=1;
		t->idata=5;
		nxt();
		t->iorc=0;
		t->cdata=lowercheck;
		usekey();
}
void encr()
{
    clr();
    //Sets and prints the key.//
    setkey();
    encinp();

    FILE *dinp=fopen("tempfile.txt","r");
    FILE *denc=fopen("Encry.txt","w");
    int x;
    int eqeq=0;
    char c;
    while(c!='\n')
    {
    fscanf(dinp,"%c",&c);
    }
    while(fscanf(dinp,"%c",&c)==1)
    {fprintf(denc,"\n");
            if (eqeq%500==0){
        system("@cls||clear");
    printf("\t\t\t\tEnigma Transcriber\n");
    printf("\n\n Last milestone crossed of converting the characters(500 minimum). : %d\n",eqeq);
    postscript();
        }

        postscript();
    eqeq+=1;
        lowercheck='s';
        if(((int)c>64) &&(int)c<91)
        {
            lowercheck='c';
          int fq=(int)c+32;
          c=fq;
          bser((char)c);
        }
        else if(((int)c>47) && ((int)c<58))
        {
            lowercheck='n';
        bser((char)c);
        }
        else if(((int)c>96)&&((int)c<123))
        {
            lowercheck='s';
            bser((char)c);
        }
        else
        {
            prser(c);
        }
        t=first;
        while(t!=NULL)
        {
            if (t->iorc==0)
            {
                fprintf(denc,"%c",t->cdata);
            }
            if(t->iorc==1)
            {
                fprintf(denc,"%d",t->idata);
            }
            t=t->next;
        }
    }
printf("Your file has been encrypted. It will be present as 'Encry.txt' in the same folder as program.\n\nFor safety purpose, we have created a file 'tempfile.txt' in the folder. In case you forget your key, you may check it from there. \nFor safety purposes, it only saves the most recent key.\n ");

}

void encrf()
{
    clr();
    //Sets and prints the key.//
    setkey();
    encrferror:
    printf("Kindly enter the exact file name you want to encrypt for example \n'Example.txt' \n Or enter 'BACK' to go to the previous menu\n:- ");
    char userfile[1000];
    scanf("%s",userfile);
    FILE *dinp=fopen(userfile,"r");
    if(dinp==NULL)
    {
        char back[]={'B','A','C','K'};
        if (strcmp(userfile,back)==0)
            {
                menu();
            }
        printf("There was some technical error. Kindly re enter your filename\n\n");
        goto encrferror;
    }
    FILE *denc=fopen("Encry.txt","w");
    int x;
    char c;
    while(c!='\n')
    {
    fscanf(dinp,"%c",&c);
    }
    int eqeq=0;
    while(fscanf(dinp,"%c",&c)==1)
    {
        fprintf(denc,"\n");
        if (eqeq%500==0){
        system("@cls||clear");
    printf("\t\t\t\tEnigma Transcriber\n");
    printf("\n\n Last milestone crossed of converting the characters(500 minimum). : %d\n",eqeq);
        postscript();}
    eqeq+=1;
        lowercheck='s';
        if(((int)c>64) &&(int)c<91)
        {
            lowercheck='c';
          int fq=(int)c+32;
          c=fq;
          bser((char)c);
        }
        else if(((int)c>47) && ((int)c<58))
        {
            lowercheck='n';
        bser((char)c);
        }
        else if(((int)c>96)&&((int)c<123))
        {
            lowercheck='s';
            bser((char)c);
        }
        else
        {
            prser(c);
        }
        t=first;
        while(t!=NULL)
        {
            if (t->iorc==0)
            {
                fprintf(denc,"%c",t->cdata);
            }
            if(t->iorc==1)
            {
                fprintf(denc,"%d",t->idata);
            }
            t=t->next;
        }
    }
printf("Your file has been encrypted. It will be present as 'Encry.txt' in the same folder as program.\n\nFor safety purpose, we have created a file 'tempfile.txt' in the folder. In case you forget your key, you may check it from there. \nFor safety purposes, it only saves the most recent key.\n ");

}

void decr()
{
    clr();
    int k,i,s,j=0,x=1,codlen=0;
    char bookd[8],c;
    printf("\nEnter the key please : ");
    scanf("%d",&k);
    static int a[11];
    if(k==0)
    {
        a[0]=1;
    }
    while (k!=0){
      s=k%10;
      a[s]=1;
      k=k/10;
    }
    for(i=0;i<11;i++)
    {
        if (a[i]==1)
        {
            codlen+=1;
        }
    }
    char tdecr[1000];
    printf("\n Kindly enter the name of your file to decrypt, if changed or enter the default name.\n(Default name - 'Encry.txt', without the quotations.) :- ");
    scanf("%s",tdecr);
    FILE *e=fopen(tdecr,"r");
    if(e==NULL)
    {
        printf("Galti boss");
    }
    x=1;
    while(c!='\n')
    {
        i=0;
        fscanf(e,"%c",&c);
    }
    FILE *outpd=fopen("DecryptedFile.txt","w");
    if (e==NULL)
    {
        printf("\nThe file seems missing. Kindly recheck and place it in the same folder as the Enigma Transcriber.");
        return;
    }
    while(fscanf(e,"%c",&c)==1)
    {
        if(c!='S'){
                i=0;
        x=1;
        char decob[16];
        while(x<=8)
        {
        if(c=='-')
        {
            i+=1;
            fscanf(e,"%c",&c);
        }
        if(c!='-')
        {
            if(a[i]!=1)
            {
                decob[x-1]=c;
                x+=1;
            }
        }
        fscanf(e,"%c",&c);
    }
    decob[8]='.';
    decob[9]='t';
    decob[10]='x';
    decob[11]='t';
    decob[12]='\0';
    FILE *fptr=fopen(decob,"r");
    fscanf(e,"%c",&c);
    while(x!=10)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        fscanf(e,"%c",&c);
        int pn=0,posic=0,wc=0;
        while(x!=11)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {

                while(c!='-')
            {
                pn=(pn*10)+(int)c-48;
                fscanf(e,"%c",&c);
            }
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        while(x!=12)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {

                while(c!='-')
            {
                wc=(wc*10)+(int)c-48;
                fscanf(e,"%c",&c);
            }
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        while(x!=13)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {

                while(c!='-')
            {
                posic=(posic*10)+(int)c-48;
                fscanf(e,"%c",&c);
            }
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        fscanf(e,"%c",&c);
        char uln=c;
        if(fptr==NULL)
        {
            printf("GAlti mil gyi");
            printf("%s",decob);
        }
        for(i=0;i<pn;i++)
        {
            while(c!='\n')
            {
                fscanf(fptr,"%c",&c);
            }
            fscanf(fptr,"%c",&c);
        }
        int wtra=1;
        while(wtra<wc)
        {
            fscanf(fptr,"%c",&c);
        if(c==' ')
            {
                wtra+=1;
            }
        }
        for(i=1;i<=posic;i++)
        {
            fscanf(fptr,"%c",&c);
        }
        if(uln=='c')
        {
            int fq=(int)c-32;
            c=fq;
        }
        fprintf(outpd,"%c",c);
        fscanf(e,"%c",&c);
    }
    else
    {
                i=0;
        x=1;
        char decob[16];
        while(x<=8)
        {
        if(c=='-')
        {
            i+=1;
            fscanf(e,"%c",&c);
        }
        if(c!='-')
        {
            if(a[i]!=1)
            {
                decob[x-1]=c;
                x+=1;
            }
        }
        fscanf(e,"%c",&c);
    }
    decob[8]='.';
    decob[9]='t';
    decob[10]='x';
    decob[11]='t';
    decob[12]='\0';
    fscanf(e,"%c",&c);
    while(x!=10)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        fscanf(e,"%c",&c);
        int pn=0,posic=0,wc=0;
        while(x!=11)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {

                while(c!='-')
            {
                pn=(pn*10)+(int)c-48;
                fscanf(e,"%c",&c);
            }
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        while(x!=12)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {

                while(c!='-')
            {
                wc=(wc*10)+(int)c-48;
                fscanf(e,"%c",&c);
            }
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        while(x!=13)
        {
            if(c=='-')
            {
                i+=1;
                fscanf(e,"%c",&c);
            }
            if(a[i]!=1)
            {

                while(c!='-')
            {
                posic=(posic*10)+(int)c-48;
                fscanf(e,"%c",&c);
            }
                x+=1;
            }
            while(c!='-')
            {
                fscanf(e,"%c",&c);
            }
        }
        fscanf(e,"%c",&c);
        char uln=c;
        fprintf(outpd,"%c",decob[7]);
        fscanf(e,"%c",&c);
    }
    }
    printf("Your file has been decrypted. It will be present as 'DecryptedFile.txt' in the same folder as program.\n\n\n\n");
}


void menu()
{
    //It gives the choice to user to select what user wants to do.
     int *i=(int *) malloc(sizeof(int));
     *i=0;
    remenu:
        fflush(stdin);
    printf("\nKindly note that the dash(-) is not encrypted and might even lead the program to crash. \n\n  Please select what you would like to do.");
    printf("\n1.) Encrypt the data.\n2.) Decrypt the data.\n3.) Encrypt a custom file.\n Enter the option number you would like to use. : ");
     int *x=(int *) malloc(sizeof(int));
    *x=0;
     char *c=(char *) malloc(sizeof(char));
    //Checking for non numeric input by the user.
    if(scanf("%d%c",x,c)!=2||*c!='\n')
        {
        *x=0;
        printf("\n Seems like the system received non integer input. Kindly renter your choice.");
        free(c);
        goto remenu;
    }
    else{
    switch(*x)
    {
        case 1:
            free(x);
            free(i);
            encr();
        break;
        case 2:
            free(x);
            free(i);
            decr();
        break;
        case 3:
            free(x);
            free(i);
            encrf();
        break;
        default:
            free(x);
            clr();
            *i=*i+1;
            if (*i>1)
            {
                printf("\n The system again did the mistake in taking your input.\n The value system received is : %d.\n Kindly renter your choice.",*x);
            }
            else
            printf("\n  Seems like the system made a mistake in taking your input.\n  Kindly renter your choice.");
        goto remenu;
        break;
    }}
}


int main()
{
    //This simply calls the menu function and prints basic starting and ending formalities.
    rndr=time(NULL);

    rndr=(rndr%1231)+(rndr*3123)*(rndr/3)+(rndr%12);
    printf("\t\tWelcome to the Enigma Transcriber.");
    menu();
    printf("\n\n  Thank you for using the program. We were glad to be of help.\n\n\n\n");
		return 0;
}

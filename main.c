// mohammed ayed ahmad shadeed - id: 1242602 -lecture : 3- lab :7
#include <stdio.h>
#define  MAXSIZE 100
#define NAMESIZE 50
#include <string.h>
void addBook(int bins[],double price[], int*size,char[][NAMESIZE]);
void removeBook(int bins[],double price[],int*size,char[][NAMESIZE]);
void searchForBook(int bins[],double price[],int size,char [][NAMESIZE]);
void uploadDataFile(int bins[], double price[],int*size,char[][NAMESIZE]);
void updateDataFile(int bins[], double price[],int size,char [][NAMESIZE]);
void printBooks(int bins[],double price[],int size,char [][NAMESIZE]);


int main()
{
    int size=0,bins[MAXSIZE];
    double price[MAXSIZE];
    char name[MAXSIZE][NAMESIZE];
    uploadDataFile(bins,price,&size,name);
    printf("uploading data...\n");
    printf("data uploaded\n");
      int n=0;
    printf("Please Select an Operation (1-5):\n 1- Add a Book\n 2-Remove a Book\n 3- Search for a Book\n 4-Print Book List\n 5-Exit System\n");
    while(n!=5)

    {
        printf("your choice \n");
        scanf("%d",&n);
        switch(n)
        {
        case(1):
            addBook(bins,price,&size,name);
            break;
        case(2):
            removeBook(bins,price,&size,name);
            break;
        case(3):
            searchForBook(bins,price,size,name);
            break;
        case(4):
            printBooks(bins,price,size,name);
            break;
        case(5):
            updateDataFile(bins,price,size,name);
            printf("file updated \n");
            break;
        default:
            printf("error wrong number entered\n");
            break;
        }
        printf("Please Select an Operation (1-5):\n 1- Add a Book\n 2-Remove a Book\n 3- Search for a Book\n 4-Print Book List\n 5-Exit System\n");
    }



return 0;
}






void addBook(int bins[],double price[],int *size,char name[][NAMESIZE])
{
    if(*size<MAXSIZE)
    {
        int nbin;
        double npin;
        char newname[NAMESIZE];
        printf("enter new bin number\n");
        scanf("%d",&nbin);
        for (int i = 0; i < *size; i++)
        {
            if (bins[i] == nbin)
            {
                printf("error book bin number already in use\n");
                break;
            }
        }
        printf("enter the price of the book\n");
        scanf("%lf",&npin);
        printf("enter name of the book\n");
        scanf("%s",newname);
        int position = 0;
        while (position < *size && nbin > bins[position])
        {
            position++;
        }

        for (int i = *size; i > position; i--)
        {
            bins[i] = bins[i - 1];
            price[i] = price[i - 1];
            int len=strlen(name[i-1]);
            for(int k=0; k<len; k++)
            {
                name[i][k]=name[i-1][k];
            }
        }

        bins[position] = nbin;
        price[position] = npin;
        int len2=strlen(newname);
        for(int u=0; u<len2; u++)
        {
            name[position][u]=newname[u];
        }
        (*size)++;


    }

    else
        printf("error you cant add more books (you have reached maximum size)\n");
}
void removeBook(int bins[],double price[],int*size, char name[][NAMESIZE])
{
    if(*size!=0)
    {
        int binx;
        printf("enter the bin number of the book you want to delete\n");
        scanf("%d",&binx);
        int x=0;
        for(int i=0; i<*size; i++)
        {
            if (bins[i]==binx)
            {
                for (int j = i; j < *size - 1; j++)
                {
                    bins[j] = bins[j+1];
                    price[j] = price[j+1];
                    int len=strlen(name[j+1]);
                    for(int k=0; k<len; k++)
                    {
                        name[j][k]=name[j+1][k];
                    }

                }
                (*size)--;
                x=1;
                break;
            }


        }
        if(x==0)
            printf("error book not found\n");


    }
    else
        printf("no books to remove\n");
}
void searchForBook(int bins[],double price[],int size,char name[][NAMESIZE])
{
    if(size!=0)
    {
        int currentbin;
        printf("enter the book bin\n");
        scanf("%d",&currentbin);
        int y=0;
        for(int i=0; i<size; i++)
        {
            if (bins[i]==currentbin)
            {

                printf("book bin is %d and its price is %lf and name is %s\n",currentbin,price[i],name[i]);
                y=1;
                break;
            }
        }
        if(y==0)
            printf("no such a book found\n");

    }
    else
        printf("no books in the system\n");

}
void uploadDataFile(int bins[], double price[],int*size,char name[][NAMESIZE])
{
    FILE *fpt=fopen("books.txt","r");
    if(fpt==NULL)
    {
        printf("file empty ");
    }
    else
    {
        *size=0;

while (*size < MAXSIZE && fscanf(fpt, "%d %lf %s", &bins[*size], &price[*size], name[*size]) == 3) {
    (*size)++;
}
        fclose(fpt);
    }
}

void updateDataFile(int bins[], double price[],int size,char name [][NAMESIZE])
{
    FILE *fptw=fopen("books.txt","w");
    for(int k=0; k<size; k++)
    {
        fprintf(fptw,"%d %lf %s\n",bins[k],price[k],name[k]);
    }
    fclose(fptw);
}
void printBooks(int bins[],double price[],int size,char name[][NAMESIZE])
{
    if(size==0)
        printf("no books to print\n");
    else
    {
        printf("book bins \t price \t name \n------------------------------\n");
        for(int l=0; l<size; l++)
        {
            printf("%d     \t %lf \t %s \n",bins[l],price[l],name[l]);
        }
    }
}

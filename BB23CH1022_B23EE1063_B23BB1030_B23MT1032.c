#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>


// function to show the count the number of x's and o's
void show_cnt(char *a[][8],char x[],char o[])
{
    int count_x=0,count_y=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (a[i][j]=="x ")
            {
                count_x++;
            }
        }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (a[i][j]=="o ")
            {
                count_y++;
            }
        }
    }
    printf("\nCount of %s : %d\n",x,count_x);
    printf("Count of %s : %d\n",o,count_y);
    return;
}


// function to show the othello board after each turn
void show(char *a[][8])
{
    printf("  ");
    for(int i=1; i<9; i++)
    {
        printf("%d  ",i);
    }
    printf("\n");

    for(int i=0; i<8; i++)
    {
        printf("%d ",i+1);
        for(int j=0; j<8; j++)
        {
            printf("%s ",a[i][j]);
        }
        printf("\n");
    }
}


// function that is checking the right side horizontal conditions aand updating the scenario
void right_condition_x(char *a[][8],int row,int col)
{
    if (strcmp(a[row-1][col-1],"x ")==0)
    {
        for(int i=col-2; i>-1; i--)
        {
            if (strcmp(a[row-1][i],"x ")==0)
            {
                int c=0;
                for(int j=i+1; j<col-1; j++)
                {
                    if (strcmp(a[row-1][j],"o ")==0)
                        c++;
                }
                if (c==(col-i-2))
                {
                    for(int j=i+1; j<col-1; j++)
                    {
                        a[row-1][j]="x ";
                    }
                }
                break;
            }
        }
    }
}


// function that is checking the left side horizontal conditions aand updating the scenario
void left_condition_x(char *a[][8],int row,int col)
{
    if (strcmp(a[row-1][col-1],"x ")==0)
    {
        for(int i=col; i<8; i++)
        {
            if (strcmp(a[row-1][i],"x ")==0)
            {
                int c=0;
                for(int j=col; j<i; j++)
                {
                    if (strcmp(a[row-1][j],"o ")==0)
                    {
                        c++;
                    }
                }
                if (c==(i-col))
                {
                    for(int j=col; j<i; j++)
                    {
                        a[row-1][j]="x ";
                    }
                }
                break;
            }
        }
    }
}


// function that is checking the below first diagonal conditions aand updating the scenario
void diag1_x_down(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=8 && m!=8)
    {
        if (strcmp(a[j][m],"x ")==0)
        {
            c=c+1;
        }
        j=j+1;
        m=m+1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        r++;
        q++;
        while(strcmp(a[r][q],"x ")!=0)
        {
            i=i+1;
            r=r+1;
            q=q+1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r+1][q+1],"o ")==0)
            {
                c=c+1;
            }
            r=r+1;
            q=q+1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r+1][q+1]="x ";
            r=r+1;
            q=q+1;
        }
    }
}


// function that is checking the upper first diagonal conditions aand updating the scenario
void diag1_x_up(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=-1 && m!=-1)
    {
        if (strcmp(a[j][m],"x ")==0)
        {
            c=c+1;
        }
        j=j-1;
        m=m-1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        while(strcmp(a[r-1][q-1],"x ")!=0)
        {
            i=i+1;
            r=r-1;
            q=q-1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r-1][q-1],"o ")==0)
            {
                c=c+1;
            }
            r=r-1;
            q=q-1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r-1][q-1]="x ";
            r=r-1;
            q=q-1;


        }
    }
}

// function that is checking the below condition for diagonal 2 and updating the scenario
void diag2_x_down(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=8 && m!=-1)
    {
        if (strcmp(a[j][m],"x ")==0)
        {
            c=c+1;
        }
        j=j+1;
        m=m-1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        r++;
        q--;
        while(strcmp(a[r][q],"x ")!=0)
        {
            i=i+1;
            r=r+1;
            q=q-1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r+1][q-1],"o ")==0)
            {
                c=c+1;
            }
            r=r+1;
            q=q-1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r+1][q-1]="x ";
            r=r+1;
            q=q-1;
        }
    }
}


// function that is checking the upper diagonal 2 conditions aand updating the scenario
void diag2_x_up(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=-1 && m!=8)
    {
        if (strcmp(a[j][m],"x ")==0)
        {
            c=c+1;
        }
        j=j-1;
        m=m+1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        while(strcmp(a[r-1][q+1],"x ")!=0)
        {
            i=i+1;
            r=r-1;
            q=q+1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r-1][q+1],"o ")==0)
            {
                c=c+1;
            }
            r=r-1;
            q=q+1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r-1][q+1]="x ";
            r=r-1;
            q=q+1;


        }
    }
}


// function that is checking the upper vertical conditions aand updating the scenario
void top_condition_x(char *a[][8],int row,int col)
{
    if (strcmp(a[row-1][col-1],"x ")==0)
    {
        for(int i=row-2; i>-1; i--)
        {
            if (strcmp(a[i][col-1],"x ")==0)
            {
                int c=0;
                for(int j=i+1; j<row-1; j++)
                {
                    if (strcmp(a[j][col-1],"o ")==0)
                        c++;
                }
                if (c==(row-i-2))
                {
                    for(int j=i+1; j<row-1; j++)
                    {
                        a[j][col-1]="x ";
                    }
                }
                break;
            }
        }
    }
}


// function that is checking the bottom vertical conditions aand updating the scenario
void bottom_condition_x(char *a[][8],int row,int col,char y[],char z[])
{
    if (strcmp(a[row-1][col-1],"x ")==0)
    {
        for(int i=row; i<8; i++)
        {
            if (strcmp(a[i][col-1],"x ")==0)
            {
                int c=0;
                for(int j=row; j<i; j++)
                {
                    if (strcmp(a[j][col-1],"o ")==0)
                    {
                        c++;
                    }
                }
                if (c==(i-row))
                {
                    for(int j=row; j<i; j++)
                    {
                        a[j][col-1]="x ";
                    }
                }
                break;
            }
        }
    }
    printf("\nUpdated Game View -\n");
    show(a);
    show_cnt(a,y,z);
}


// function that is checking the left side horizontal conditions and updating the scenario
void left_condition_o(char *a[][8],int row,int col)
{
    if (strcmp(a[row-1][col-1],"o ")==0)
    {
        for(int i=col-2; i>-1; i--)
        {
            if (strcmp(a[row-1][i],"o ")==0)
            {
                int c=0;
                for(int j=i+1; j<col-1; j++)
                {
                    if (strcmp(a[row-1][j],"x ")==0)
                        c++;
                }
                if (c==(col-i-2))
                {
                    for(int j=i+1; j<col-1; j++)
                    {
                        a[row-1][j]="o ";
                    }
                }
                break;
            }
        }
    }
}


// function that is checking the right side horizontal conditions aand updating the scenario
void right_condition_o(char *a[][8],int row,int col)
{
    if (strcmp(a[row-1][col-1],"o ")==0)
    {
        for(int i=col; i<8; i++)
        {
            if (strcmp(a[row-1][i],"o ")==0)
            {
                int c=0;
                for(int j=col; j<i; j++)
                {
                    if (strcmp(a[row-1][j],"x ")==0)
                    {
                        c++;
                    }
                }
                if (c==(i-col))
                {
                    for(int j=col; j<i; j++)
                    {
                        a[row-1][j]="o ";
                    }
                }
                break;
            }
        }
    }
}



// function that is checking the below first diagonal conditions aand updating the scenario
void diag1_o_down(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=8 && m!=8)
    {
        if (strcmp(a[j][m],"o ")==0)
        {
            c=c+1;
        }
        j=j+1;
        m=m+1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        r++;
        q++;
        while(strcmp(a[r][q],"o ")!=0)
        {
            i=i+1;
            r=r+1;
            q=q+1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r+1][q+1],"x ")==0)
            {
                c=c+1;
            }
            r=r+1;
            q=q+1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r+1][q+1]="o ";
            r=r+1;
            q=q+1;
        }
    }
}


// function that is checking the upper first diagonal conditions and updating the scenario
void diag1_o_up(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=-1 && m!=-1)
    {
        if (strcmp(a[j][m],"o ")==0)
        {
            c=c+1;
        }
        j=j-1;
        m=m-1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        while(strcmp(a[r-1][q-1],"o ")!=0)
        {
            i=i+1;
            r=r-1;
            q=q-1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r-1][q-1],"x ")==0)
            {
                c=c+1;
            }
            r=r-1;
            q=q-1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r-1][q-1]="o ";
            r=r-1;
            q=q-1;


        }
    }
}


// function that is checking the below second diagonal conditions aand updating the scenario
void diag2_o_down(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=8 && m!=-1)
    {
        if (strcmp(a[j][m],"o ")==0)
        {
            c=c+1;
        }
        j=j+1;
        m=m-1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        r++;
        q--;
        while(strcmp(a[r][q],"o ")!=0)
        {
            i=i+1;
            r=r+1;
            q=q-1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r+1][q-1],"x ")==0)
            {
                c=c+1;
            }
            r=r+1;
            q=q-1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r+1][q-1]="o ";
            r=r+1;
            q=q-1;
        }
    }
}


// function that is checking the upper second diagonal conditions aand updating the scenario
void diag2_o_up(char *a[][8],int row,int col)
{
    int i=0,j=row-1,m=col-1;
    int c=0;
    while(j!=-1&&m!=8)
    {
        if (strcmp(a[j][m],"o ")==0)
        {
            c=c+1;
        }
        j=j-1;
        m=m+1;
    }

    int r=row-1,q=col-1;
    if (c>1)
    {
        while(strcmp(a[r-1][q+1],"o ")!=0)
        {
            i=i+1;
            r=r-1;
            q=q+1;
        }

    }
    r=row-1,q=col-1;
    c=0;
    if (i>0)
    {
        for (int z=0; z<i; z++)
        {
            if(strcmp(a[r-1][q+1],"x ")==0)
            {
                c=c+1;
            }
            r=r-1;
            q=q+1;
        }
    }
    r=row-1,q=col-1;

    if(i==c)
    {
        for (int z=0; z<i; z++)
        {
            a[r-1][q+1]="o ";
            r=r-1;
            q=q+1;
        }
    }
}


// function that is checking the upper vertical conditions aand updating the scenario
void top_condition_o(char *a[][8],int row,int col)
{
    if (strcmp(a[row-1][col-1],"o ")==0)
    {
        for(int i=row-2; i>-1; i--)
        {
            if (strcmp(a[i][col-1],"o ")==0)
            {
                int c=0;
                for(int j=i+1; j<row-1; j++)
                {
                    if (strcmp(a[j][col-1],"x ")==0)
                        c++;
                }
                if (c==(row-i-2))
                {
                    for(int j=i+1; j<row-1; j++)
                    {
                        a[j][row-1]="o ";
                    }
                }
                break;
            }
        }
    }
}


// function that is checking the below vertical conditions aand updating the scenario
void bottom_condition_o(char *a[][8],int row,int col,char y[],char z[])
{
    if (strcmp(a[row-1][col-1],"o ")==0)
    {
        for(int i=row; i<8; i++)
        {
            if (strcmp(a[i][col-1],"o ")==0)
            {
                int c=0;
                for(int j=row; j<i; j++)
                {
                    if (strcmp(a[j][row-1],"x ")==0)
                    {
                        c++;
                    }
                }
                if (c==(i-row))
                {
                    for(int j=row; j<i; j++)
                    {
                        a[j][col-1]="o ";
                    }
                }
                break;
            }
        }
    }
    printf("\nUpdated Game View -\n");
    show(a);
    show_cnt(a,y,z);
}


// this is the menu function that contains all sorts of calling statements of X for checking and updating the scenario of the game
void menu_x(char *a[][8],int n,int m,char y[],char z[])
{
    if (n>8 || n<1 || m>8 || m<1)
    {
        printf("Wrong input,try again!\n");
        printf("Again %s's turn\n",z);
        printf("Write the row and column:");
        scanf("%d %d",&n,&m);
        menu_x(a,n,m,y,z);
    }
    else if((strcmp(a[n-1][m-1],"x ")==0)||(strcmp(a[n-1][m-1],"o ")==0))
    {
        printf("Wrong input,try again!\n");
        printf("Again %s's turn\n",z);
        printf("Write the row and column:");
        scanf("%d %d",&n,&m);
        menu_x(a,n,m,y,z);

    }
    else
    {
        a[n-1][m-1]="x ";
        printf("\n");
        show(a);
        left_condition_x(a,n,m);
        right_condition_x(a,n,m);
        diag1_x_up(a,n,m);
        diag1_x_down(a,n,m);
        diag2_x_up(a,n,m);
        diag2_x_down(a,n,m);
        top_condition_x(a,n,m);
        bottom_condition_x(a,n,m,y,z);
    }
    return;


}
// this is the menu function that contains all sorts of calling statements of Y for checking and updating the scenario of the game
void menu_o(char *a[][8],int n,int m,char y[],char z[])
{
    if (n>8 || n<1 || m>8 || m<1)
    {
        printf("Wrong input,try again!\n");
        printf("Again %s's turn\n",z);
        printf("Write the row and column:");
        scanf("%d %d",&n,&m);
        menu_o(a,n,m,y,z);
    }
    else if((strcmp(a[n-1][m-1],"x ")==0)||(strcmp(a[n-1][m-1],"o ")==0))
    {
        printf("Wrong input,try again!\n");
        printf("Again %s's turn\n",z);
        printf("Write the row and column:");
        scanf("%d %d",&n,&m);
        menu_o(a,n,m,y,z);

    }
    else
    {
        a[n-1][m-1]="o ";
        printf("\n");
        show(a);
        left_condition_o(a,n,m);
        right_condition_o(a,n,m);
        diag1_o_up(a,n,m);
        diag1_o_down(a,n,m);
        diag2_o_up(a,n,m);
        diag2_o_down(a,n,m);
        top_condition_o(a,n,m);
        bottom_condition_o(a,n,m,y,z);
    }

    return;
}



int main()
{
    char message[] = "* WELCOME TO THE WORLD OF GAMES *\n\tOTHELLO ORCHESTRATION: \n    Unveiling the Reversal Symphony\n\n";
    int i;
    for (i=0; message[i]!='\0'; i++)
    {
        putchar(message[i]);
        fflush(stdout);  // Flush the output buffer to ensure immediate display
        usleep(100000);  //usleep takes input in microseconds
    }
    while(1)
    {
        char table[]="TABLE OF CONTENT-\nEnter 1 for viewing the Team Members\nEnter 2 for viewing the Rules of the Othello Game\nEnter 3 for playing the Game\nEnter 4 for Exit\n";
        int j;
        for(j=0; table[j]!='\0'; j++)
        {
            putchar(table[j]);
            fflush(stdout);
            usleep(10000);
        }
        int b;
        printf("Enter your choice: ");
        scanf("%d",&b);

        if (b==1)
        {
            printf("\nHi Guys\nThis is Team- 'The Code Crafters'\nTeam Members are :\nJatin Purbia (B23CH1022)\nOm Kumar (B23BB1030)\nRudra Gupta (B23EE1063)\nRajat Kumar (B23BB1032)\n\n");
        }

        else if (b==2)
        {
            printf("%s","\n\nFollowing are the Basic rules which are to be considered while playing the game:\n\
                   \nBoard Setup:\n\
                   The game is played on an 8x8 grid board.\n\
                   Each player starts with two discs of their color placed diagonally in the center.\n\
                   \nTurns:\n\
                   Players take turns placing one disc of their color on an empty square.\n\
                   A player must place a disc so that it 'sandwiches' at least one opponent's disc between two of their own discs horizontally, vertically, or diagonally.\n\
                   \nFlipping Discs:\n\
                   When a player surrounds the opponent's discs with their own on opposite sides, all the enclosed discs of the opponent's color are flipped to the current player's color.\n\
                   \nPassing:\n\
                   If a player has no legal moves, they must pass, and their opponent continues to play.\n\
                   \nEnd of the Game:\n\
                   The game ends when the board is full or when neither player can make a legal move.\n\
                   The player with the most discs of their color on the board wins.\n\
                   \nWinning:\n\
                   The player with the most discs of their color on the board at the end of the game is the winner.\n\
                   \nTiebreaker:\n\
                   If both players have the same number of discs of their color, the game is a tie.\n\n");
        }
        else if (b==3)
        {
            char p1[20],p2[20];
            printf("Enter name of player 1:");
            scanf("%s",p1);
            printf("Enter name of player 2:");
            scanf("%s",p2);
            char *a[8][8];
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                {
                    a[i][j]=(char *)malloc(2);
                    a[i][j]="_ ";
                }
            }
            a[3][3]="x ";
            a[3][4]="o ";
            a[4][3]="o ";
            a[4][4]="x ";
            show(a);
            int end1,end2,c=0;
            int count_x,count_y;
            for(int i=0; i<30; i++)
            {
                int n,m;
                printf("%s's turn\n",p1);
                printf("Write the row and column:");
                scanf("%d %d",&n,&m);
                menu_x(a,n,m,p1,p2);
                c=c+1;
                printf("\nDo you want to exit the game? \nif yes-->press 1\nif no--> press 2\n");
                printf("Enter your choice: ");
                scanf("%d",&end1);
                if(end1==1)
                {
                    c=0;
                    printf("\nDo you want to evaluate the winner? \nif yes-->press 1\nif no-->press 2\n");
                    printf("Enter your choice: ");
                    scanf("%d",&end2);
                    if(end2==1)
                    {
                        count_x=0,count_y=0;

                        for(int i=0; i<8; i++)
                        {
                            for(int j=0; j<8; j++)
                            {
                                if(strcmp(a[i][j],"x ")==0)
                                {
                                    count_x++;
                                }
                                else if(strcmp(a[i][j],"o ")==0)
                                {
                                    count_y++;
                                }
                            }
                        }

                        if (count_x > count_y)
                        {
                            printf("\nCONGRATULATIONS...Winner is %s !!!\n\n",p1);
                        }
                        else if(count_y > count_x)
                        {
                            printf("\nCONGRATULATIONS...Winner is %s !!!\n\n",p2);
                        }
                        else
                        {
                            printf("\nOH IT'S A TIE\n\n");
                        }
                        break;
                    }
                    else if(end2==2)
                    {
                        break;

                    }
                }


                int p,q;
                printf("%s's turn\n",p2);
                printf("Write the row and column:");
                scanf("%d %d",&p,&q);
                menu_o(a,p,q,p1,p2);
                c=c+1;
                printf("\nDo you want to exit the game? \nif yes-->press 1\nif no--> press 2\n");
                printf("Enter your choice: ");
                scanf("%d",&end1);
                if(end1==1)
                {
                    c=0;
                    printf("\nDo you want to evaluate the winner? \nif yes-->press 1\nif no-->press 2\n");
                    printf("Enter your choice: ");
                    scanf("%d",&end2);
                    if(end2==1)
                    {
                        count_x=0,count_y=0;

                        for(int i=0; i<8; i++)
                        {
                            for(int j=0; j<8; j++)
                            {
                                if(strcmp(a[i][j],"x ")==0)
                                {
                                    count_x++;
                                }
                                else if(strcmp(a[i][j],"o ")==0)
                                {
                                    count_y++;
                                }
                            }
                        }

                        if (count_x > count_y)
                        {
                            printf("CONGRATULATIONS...Winner is %s !!!\n\n",p1);
                        }
                        else if(count_y > count_x)
                        {
                            printf("CONGRATULATIONS...Winner is %s !!!\n\n",p2);
                        }
                        else
                        {
                            printf("OH IT'S A TIE\n\n");
                        }
                        break;
                    }
                    else if(end2==2)
                    {
                        break;
                    }
                }


                if(c!=0)
                {
                    count_x=0,count_y=0;
                    for(int i=0; i<8; i++)
                    {
                        for(int j=0; j<8; j++)
                        {
                            if(strcmp(a[i][j],"x ")==0)
                            {
                                count_x++;
                            }
                            else if(strcmp(a[i][j],"o ")==0)
                            {
                                count_y++;
                            }
                        }
                    }


                    if(count_x > count_y)
                    {
                        printf("CONGRATULATIONS...Winner is %s !!!\n\n",p1);
                    }
                    else if(count_y > count_x)
                    {
                        printf("CONGRATULATIONS...Winner is %s !!!\n\n",p2);
                    }
                    else
                    {
                        printf("OH IT'S A TIE\n\n");
                    }

                }
            }
        }

        else if(b==4)
        {
            printf("\nTHANK YOU For Playing\nHave A Nice Day!!");
            break;
        }
    }
}

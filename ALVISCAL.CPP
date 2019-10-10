#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

using namespace std;

void delay(int delay)
{
    int now=time(NULL);
    int later=now+delay;
	cout<<"Adding Delay";
    while(now<=later)
        now=time(NULL);
}

struct conversation
{
	int slno;
	char input[20][5];
	string output;
	int len;
	conversation();
	void learn();
	void say();
	void clean();

};
conversation :: conversation(){
		for (int i=0;i<6;i++)
			input[0][i]='.';
		len=0;
}
void conversation :: learn(){
		int flag=1;
		char take[10];

		cout<<"SPECIFY THE SR. NO. FOR THIS ENTRY:	";
		cin>>slno;

		while (flag==1){
		cout<<"PROVIDE THE KEY WORDS:"	;
		cin>>take;

		for(int i=0; i<strlen(take); i++)
		{
			input[i][len]=take[i];
		}

		len++;
		cout<<"DO YOU WANT TO ENTER MORE?(1/0)	";
		cin>>flag;
		}
		cout<<"WHAT SHOULD I SAY? Tell Me please	";
		cin>>output;
}

void conversation::say(){
		cout<<output;
}

void conversation::clean(){
		for (int r=0; r<6;r++)
		{
		for (int t=0;t<20;t++)
			{
			if (t==0)
				input[t][r]='.';
			else
			input[t][r]='\0';
			}
		}
		for (int r=0; r<50;r++)
			output[r]=0;
}

int main()
{
	int ch=0;
	do{
	system("cls");
	cout<<"HEY THERE! HOW CAN I HELP YOU?\n";
	cout<<"LEARN						(1)\n";
	cout<<"TAKE A LOOK AT THE ENTRIES  			(2)\n";
	cout<<"FORGET						(3)\n";
	cout<<"TALK						(4)\n";
	cout<<"BYE?						(5)\n";
	cout<<"PRINT 'HELLO WORLD!'?				(6)\n";
	cin>>ch;

	/*conversation q;
	for(int z=0;z<6;z++)
	{for(int y=0;y<20;y++)
	cout<<q.input[y][z];
	cout<<"\n";}*/

	switch(ch)
	{
		case 1:
		    {

			conversation a;
			ofstream ofile;
			ofile.open("CONVERSA.DAT",ios::binary|ios::app);
			a.clean();
			a.learn();
			ofile.write((char*)&a,sizeof(a));
			ofile.close();
			break;
		    }

		case 2:
		    {
			conversation c;
			ifstream infile;
			infile.open("CONVERSA.DAT",ios::binary);
			while(infile.read((char*)&c,sizeof(c)))
				{
				cout<<"ENTRY NUMBER:	"<<c.slno<<"\n";

				for(int w=0;w<6;w++)
				{for(int e=0;e<20;e++)
					cout<<c.input[e][w];
					cout<<"\n";}
				c.say();
				delay(1);
				}
			infile.close();
			break;
		    }
		case 3:
		    {
			int ent;
			conversation z;
			cout<<"ENTER THE SERIAL NUMBER OF THE ENTRY TO BE DELETED:	";
			cin>>ent;
			ifstream ipfile;
			ipfile.open("CONVERSA.DAT",ios::binary);
			ofstream opfile;
			opfile.open("TEMP.DAT",ios::binary);
			while(ipfile.read((char*)&z,sizeof(z)))
			{
				if(ent!=z.slno)
				opfile.write((char*)&z,sizeof(z));

			}
			opfile.close();
			ipfile.close();
			remove("CONVERSA.DAT");
			rename("TEMP.DAT","CONVERSA.DAT");
			break;
		    }
		case 4:
		    {
			cout<<"*ASK IN CAPS AND INCLUDE A SPACE AT THE END*\n*TO END TYPE 'BYEE'*\n";
			char hear[50];
			int j=0,number=0;
			char check[10];
			char stat[10];
			for (int p=0;p<strlen(hear);p++)
				hear[p]='\0';
			while(strcmp(hear,"BYEE")!=0)
			{
			int c=0,random=0;
			for (int i=0; i<10;i++)
				check[i]=stat[i]='\0';

			int chck=0,curr=0,flag=0,ctr=0;
			conversation b;
			b.clean();
			cout<<"HI! HOW CAN I HELP YOU?\n";
			gets(hear);
			ifstream ifile;
			ifile.open("CONVERSA.DAT",ios::binary);
			while(ifile.read((char*)&b,sizeof(b))&&chck<=b.len)
			{
				int start=0;
				ctr=0;
				int c=0;

				do{
				  for(int i=0;i<10;i++)
					check[i]='\0';

				  for(int i=0;b.input[i][j]!='\0';i++)
					check[i]=b.input[i][j];


				  for(int k=0;k<strlen(hear);k++)
					if(hear[k]==' ')
					  {
					  curr=k-1;
					  //cout<<start<<"\t"<<curr<<"\n";

					  for(int z=0;z<10;z++)
						stat[z]='\0';

					  for(int l=start, m=0; l<=curr; l++,m++)
						stat[m]=hear[l];

					  //cout<<stat<<"\t"<<check<<"\n";

					  start=curr+2;

					  if(strcmp(stat,check)==0)
						j++;

					  if(strcmp(stat,"CALCULATOR")==0 || strcmp(stat,"CALCULATE")==0 || strcmp(stat,"CALCULATION")==0)
						{
						c++;
						for(int i=0;i<10;i++)
							stat[i]='\0';
						}

					  }
					  ctr++;
					  //cout<<ctr<<"\t"<<b.len<<"\n";

				  }while(ctr<b.len);
				chck=j;
				j=0;

				if(chck==b.len)
					{cout<<b.output; random=1;}


				if(c!=0)
				{
				    random=1;
					char calc[15];
					int num1,num2;
					cout<<"\nCALCULATOR MODE ACTIVATED!\n";
					cout<<"WHAT DO YOU WANT TO DO?     ";
					cin>>calc;
					cout<<"ENTER THE FIRST NUMBER:     ";
					cin>>num1;
					cout<<"ENTER THE SECOND NUMBER:    ";
					cin>>num2;

					if(strcmp(calc,"ADD")==0)
						cout<<num1<<" + "<<num2<<" = "<<num1+num2<<"\n";

					if(strcmp(calc,"SUBTRACT")==0)
						cout<<num1<<" - "<<num2<<" = "<<num1-num2<<"\n";

					if(strcmp(calc,"DIVIDE")==0)
						cout<<num1<<" / "<<num2<<" = "<<num1/num2<<"\n";

					if(strcmp(calc,"MULTIPLY")==0)
						cout<<num1<<" * "<<num2<<" = "<<num1*num2<<"\n";

						break;
				}
			}
				if (random==0)
				{
				switch(number)
					{
					case 0:cout<<"I don't want to talk about that.\n";number++;break;
					case 1:cout<<"I can't answer that. Sorry!\n";number++;break;
					case 2:cout<<"I don't know.\n";number++;break;
					case 3:cout<<"It's hard to answer.\n";number++;break;
					case 4:cout<<"Stop troubling me!\n";number=0;break;
					case 5:cout<<"Hello World!\n";number=0;break;
					}
				}

			ifile.close();
			}
		    }
	}
	}while(ch!=5);
return 0;
}

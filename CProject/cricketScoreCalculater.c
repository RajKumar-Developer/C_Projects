#include <stdio.h>
#include <stdlib.h>

void req_rate(float a, float b, float c,float d,float e);
void runs_needed(int a,int b,int c,int d, int e);
void projected_score(int a,int b,int c,int d,float e);
void result(int a,int b,int e,int g,char f,char c[],char d[]);
float curr_rate(float a, float b, float c);
void ball_played(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i, int *j);
int string_comp(char a[],char b[],char c[]);
float curr_rate(float a, float b, float c);
int main(int argc, char *argv[]) {
	int wd=0,nb=0,lb=0,b=0,extras=0,overs=0,T_overs=0, k=0,balls=0, T=0,score=0,wickets=0, target=0,q=0,c[11],j=1,f=0,s=0;
	float c_rate;
	char toss[15], team_1[15], team_2[15], choice, runs;
	printf("Match between:\n");
	gets(team_1);
	printf("versus\n");
	gets(team_2);
	printf("Toss won by: ");
	gets(toss);
	printf("Enter B to choose bat first and F to field first: ");
	scanf("%c",&choice);
	printf("Enter overs to be played by each side: ");
	scanf("%d",&T_overs);
	system("cls");
	T=string_comp(team_1,team_2,toss);
	while(overs<=T_overs||overs>=T_overs){
		do{
			if(wickets>q){
				*(c+wickets)=score;
			}
			q=wickets;
			system("cls");
			printf("\t\t\t%s vs %s (%d-overs match)\n",team_1,team_2,T_overs);
			if(T==1){
				if(choice=='B'||choice=='b'){
					printf("%s won the toss and elected to bat first\n",team_1);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_1,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s won the toss and elected to field first\n",team_1);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_2,score,wickets,overs,balls);
				}
			}
			else if(T==2){
				if(choice=='B'||choice=='b'){
					printf("%s won the toss and elected to bat first\n",team_2);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_2,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s won the toss and elected to field first\n",team_2);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_1,score,wickets,overs,balls);
				}
			}
			if (overs>0&&score>20){
				if(overs==T_overs||wickets==10){
					printf("\n");
					k++;
					break;
				}
				c_rate= curr_rate(score,overs,balls);
				printf("run rate %0.2f\n",c_rate);
			}
			if(balls==0){
				printf("\n");
				if(extras>0){
					printf("extras: %d(wd %d,nb %d,lb %d,b %d)\t",extras,wd,nb,lb,b);
				}
				if(f>0||s>0){
					printf("boundaries: %d fours,%d sixes\n",f,s);
				}
				else
				printf("\n");
			}
			if (overs>0&&score>20&&balls==0){
				projected_score(score,overs,T_overs,balls,c_rate);
			}
			printf("\n");
			if(overs==T_overs||wickets==10){
				k++;
				break;
			}
			ball_played(&balls,&score,&wickets,&extras,&wd,&nb,&lb,&b,&f,&s);
		}while(balls<6);
		if(balls==6){
			balls=0;
		}
		if(overs<T_overs){
			overs++;
		}
		if(k>0){
			break;
		}
	}
	printf("\nextras: %d(wd %d,nb %d,lb %d,b %d)\tboundaries: %d fours,%d sixes\n",extras,wd,nb,lb,b,f,s);
	if(wickets>0){
		printf("\nfall of wickets:  ");
		for(j=1;j<=wickets;j++){
			if(j==1||j==6)
			printf("\n");
			else
			printf("\t");
			printf("%d-%d",j,c[j]);
		}
	}
	printf("\n\ninnings completed.");
	sleep(10);
	for(k=10;k>=0;k--){
		system("cls");
		printf("\n\n\n\n\t\t\tINNINGS BREAK...\n\t\t\t\t%d",k);
		sleep(1);
	}
	target=score+1,score=0,overs=0,k=0,wd=0,nb=0,lb=0,b=0,balls=0,wickets=0,extras=0,j=1,q=0,f=0,s=0;
	while(overs<=T_overs||overs>=T_overs){
		do{
			if(wickets>q){
				*(c+wickets)=score;
			}
			q=wickets;
			system("cls");
			printf("\t\t\t%s vs %s (%d-overs match)\n",team_1,team_2,T_overs);
			if(T==1){
				if(choice=='B'||choice=='b'){
					printf("%s gives target of %d runs to %s to win\n",team_1,target,team_2);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_2,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s gives target of %d runs to %s to win\n",team_2,target,team_1);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_1,score,wickets,overs,balls);
				}
			}
			else if(T==2){
				if(choice=='B'||choice=='b'){
					printf("%s gives target of %d runs to %s to win\n",team_2,target,team_1);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_1,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s gives target of %d runs to %s to win\n",team_1,target,team_2);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_2,score,wickets,overs,balls);
				}
			}
			if (overs>0&&score>20){
				if(overs==T_overs||wickets==10||target<=score){
					printf("\n");
					k++;
					break;
				}
				c_rate= curr_rate(score,overs,balls);
				printf("run rate %0.2f",c_rate);
				req_rate(score,overs,T_overs,balls,target);
			}
			if(balls==0){
				printf("\n");
				if(extras>0){
					printf("extras: %d(wd %d,nb %d,lb %d,b %d)\t",extras,wd,nb,lb,b);
				}
				if(f>0||s>0){
					printf("boundaries: %d fours,%d sixes\n",f,s);
				}
				else
				printf("\n");
			}
			if (overs>0&&score>20){
				runs_needed(score,overs,T_overs,balls,target);
			}
			printf("\n");
			if(wickets==10||target<=score||overs==T_overs){
				k++;
				break;
			}
			ball_played(&balls,&score,&wickets,&extras,&wd,&nb,&lb,&b,&f,&s);
		}while(balls<6&&overs<T_overs);
		if(balls==6){
			balls=0;
		}
		if(overs<T_overs){
			overs++;
		}
		if(k>0){
			break;
		}
	}
	printf("\nextras: %d(wd %d,nb %d,lb %d,b %d)\tboundaries: %d fours,%d sixes\n",extras,wd,nb,lb,b,f,s);
	if(wickets>0){
		printf("\nfall of wickets:  ");
		for(j=1;j<=wickets;j++){
			if(j==1||j==6)
			printf("\n");
			else
			printf("\t");
			printf("%d-%d",j,c[j]);
		}
	}
	printf("\n\ninnings completed.");
	sleep(10);
	for(k=0;k<=7;k++){
		system("cls");
		sleep(1);
		printf("\n\n\n");
		result(target,score,T,wickets,choice,team_1,team_2);
		sleep(1);
	}
	getche();
	return 0;
}
float curr_rate(float a, float b, float c){
	float d;
	if (c==0)
		d=a/b;
	else
		d=a/(b+(c/10));
	return d;
}
int string_comp(char a[],char b[],char c[]){
	int i=0,ab=0,j=0,k=0;
	strupr(a);
	strupr(b);
	strupr(c);
	for(i=0;i<3;i++){
		if(a[i]==c[i])
		j++;
		else if(b[i]==c[i])
		k++;
		else
		break;
	}
	if(j==3)
	ab=1;
	else if(k==3)
	ab=2;
	else
	ab=0;
	return ab;
}
void ball_played(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j){
	char runs;
	int t;
	scanf("%c",&runs);
	switch(runs){
		case '0':
			*a=*a+1;
			break;
		case '1':
			*b=*b+1;
			*a=*a+1;
			break;
		case '2':
			*b=*b+2;
			*a=*a+1;
			break;
		case '3':
			*b=*b+3;
			*a=*a+1;
			break;
		case '4':
			*b=*b+4;
			*a=*a+1;
			*i=*i+1;
			break;
		case '5':
			*b=*b+5;
			*a=*a+1;
			break;
		case '6':
			*b=*b+6;
			*a=*a+1;
			*j=*j+1;
			break;
		case 'w':
		case 'W':
			printf("enter runs on wide ball: ");
			scanf("%d",&t);
			*b=*b+1+t;
			*d=*d+1+t;
			*e=*e+1+t;
			break;
		case 'n':
		case 'N':
		    printf("enter runs on no ball: ");
			scanf("%d",&t);
			*b=*b+t+1;
			*d=*d+1;
			*f=*f+1;
			break;
		case 'l':
		case 'L':
			printf("enter runs as leg byes: ");
			scanf("%d",&t);
			*b=*b+t;
			*a=*a+1;
			*d=*d+t;
			*g=*g+t;
			break;
		case 'b':
		case 'B':
			printf("enter runs as byes: ");
			scanf("%d",&t);
			*b=*b+t;
			*a=*a+1;
			*d=*d+t;
			*h=*h+t;
			break;
		case 'o':
		case 'O':
			*a=*a+1;
			*c=*c+1;
			printf("enter runs if wicket is runout: ");
			scanf("%d",&t);
			*b=*b+t;
			break;
	}
}
void result(int a,int b,int e,int g,char f,char c[],char d[]){
	int h,i;
	h=(a-1)-b;
	i=10-g;
	if((a-1)==b){
		printf("\t\t\tMATCH DRAWN.");
	}
	else if(a>b){	
		if(e==1){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",c,h,c);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",d,h,d);
		}
		else if(e==2){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",d,h,d);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",c,h,c);
		}
	}
	else if(a<b||a==b){
		if(e==1){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",d,i,d);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",c,i,c);
		}
		else if(e==2){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",c,i,c);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",d,i,d);
		}
	}
}
void projected_score(int a,int b,int c,int d,float e){
	int ab,ba;
	ab=(c-b)+(d/10);
	ba=(ab*e)+a;
	printf("\nPROJECTED SCORE:\n%d at %0.2f RPO(curr. rate)\n%d at 6 RPO\n%d at 8 RPO\n%d at 10 RPO\n",ba,e,(ab*6)+a,(ab*8)+a,(ab*10)+a);
}
void runs_needed(int a,int b,int c,int d, int e){
	int f,h;
	f=(c*6)-((b*6)+d);
	h=e-a;
	printf("%d runs needed to win from %d balls",h,f);
}
void req_rate(float a, float b, float c,float d,float e){
	float f,g,h,i;
	f=e-a;
	if(d==0){
		h=c;
	}
	else{
		h=(c-1)+0.6;
	}
	i=b+(d/10);
	g=f/(h-i);
	printf("\t  req. run rate %0.2f\n",g);
} 


// 프로그램개요: 여러가지함수를 라인에디터를 이용하여 출력값을 받아오는것입니다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // pow 함수를 쓰기위해서 선언
#define prime_max 10000 //미리 준비한 소수의 

/* 한 줄의 최대문자수를 256으로 정의 */
#define MAXLEN 256

/* 프로토타입 선언 */
void Greatest_c_Divisor();	// 최대공약수 함수 gcd
void Least_c_m();		// 최소공배수 함수 ls		
void Through_s();		// 덧셈 함수 ts			
void Prime_f();			// 소인수분해 함수 pf	
void Multiple_e();		// 제곱 함수  me			
void Bar_g();			// 그래프 함수 bg
void showHelp();		// 도움말 함수

/* 전역 변수 선언 */
char fname[256] = "";
char (*buf)[MAXLEN] = NULL;
int lines = 0;

/* 메뉴 */
int main(int argc, char * argv[]) //메인함수 선언
{
	char cmd[20];				//cmd에들어가는비트수는 20개

	while(1){					//입력후꺼짐을방지
		printf("command:");		//커맨드
		scanf("%s", cmd);		//커맨드 %s 입력

		if(strcmp(cmd, "gcd") == 0)	Greatest_c_Divisor();   //gcd을 실행하는 함수
		else if(strcmp(cmd, "ls") == 0)	Least_c_m();		//ls을 실행하는 함수
		else if(strcmp(cmd, "ts") == 0)	 Through_s();		//ts 실행하는 함수
		else if(strcmp(cmd, "pf") == 0)	 Prime_f();		//pf 를 실행하는 함수
		else if(strcmp(cmd, "me") == 0)  Multiple_e(); 		//me 을 실행하는 함수
		else if(strcmp(cmd, "bg") == 0)	 Bar_g();		//bg 를 실행하는 함수
		else if(strcmp(cmd, "help") == 0)  showHelp();		//도움말표시하는 함수
		else if(strcmp(cmd, "exit") == 0)  break;		//프로그램에서 탈출하는 함수
		else								printf("%s?\n", cmd); 
	}
	clearBuffer(); //규정된 명령 이외의것을 입력했을때 처리
	return 0;
}

// 둘중 큰 수를구별하여 '나머지'를구하고 다음에 '나눠질수'는 앞에서 '나눈수'로하고 
// 다음에 '나눌수'는 앞에서 나눈 '나머지'로 한다
void Greatest_c_Divisor() //최대공약수 
{
	int a,b; // 최대 공약수를 구할 두개의 자연수 
	int r; //나머지
	int c; 
	
	printf("a와b의 값을 입력하시오. 단 값은 자연수만")
	scanf("%d %d", &a, &b);
	
	if(a <= 0 || b <= 0) {
	printf("자연수가 아닙니다.\n);
	exit(1); //자연수 이외의 수가 입력된 경우 프로그램을 종료합니다.
	
	printf("%d %d"의 최대 공약수는 ", a, b);
	if(a<b){
		c=a;
		a=b;
		b=c;
	}
	while(r != 0){
		r = a % b;
		a = b;
		b = r;
	}
	printf("최대공약수는 %d입니다 \n",a);
}

//
void Least_c_m() // 최소공배수
{
	int a,b;
	if(a<b){
		c=a;
		a=b;
		b=c;
		d=a*b;
	}
	while(r != 0){
		r = a % b;
		a = b;
		b = r;
	}
	printf("최소공배수는 %d\n",d/a);
}

void Through_s() // a부터 b 까지덧셈  
{
 	int a,b;
 	int i,s;
	
	printf("a와b의값을입력하시오.")
	scanf("%d %d\n", &a,&b)
	
 	if(a<b){
		c=a;
		a=b;
		b=c;
	}
	for{ a = i; i<=b; i++)
	n += i;
	printf("a부터b까지의합은%d\n", n);
		
}



void Prime_f()	// 소인수분해 함수 
{
	char num[prime_max+1];
	int primelist [prime_max];
	int i,j,k; 
	int m,l; //입력할 두수의 값
	
	printf("소인수분해할 수를 입력하세요.");
	scanf("%d %d", &m,&l);
	
	//배열의 초기화
	for(i = 0; i <= prime_max; i++)
	   	num[i]= 0;
	
	//소수를 구한다
	k=0;
	for(i= 2; i<= prime_max; i++){
		if(num[i]==0){
			primelist[k] = i;
			k++;
			for(j =2*i; j <= prime_max; j += i)
				num[j] = 1;
		}
	}	
}




void Multiple_e()// 제곱 함수  	
{

}

void Bar_g()// 그래프 함수 b
{

}


/* 도움말 표시 */
void showHelp()
{
	printf("COMMAND HELP	 :\"help\"\n");   //사용법을모를시 쓰는 구문
	printf("Greatest Common Divisor:\"gcd\"\n");	  //
	printf("Least Common Multiple:\"ls\"\n"); //
	printf("Through Sum	 :\"ts\"\n");		// 
	printf("Prime Factorization	 :\"pf\"\n");		// 
	printf("Multiple Exponential:\"me\"\n");	// 
	printf("Bar Graph	 :\"bg\"\n");		// 
	printf("QUIT PROGRAM	 :\"exit\"\n");		// 프로그램을 종료한다.
}

// 검토,업그레이드및 결론:행과열을 입력할때 그리고 문자열을 입력할때 오류가 많이나와서 
                        //이부분을 업그레이드했으면하는바이다.



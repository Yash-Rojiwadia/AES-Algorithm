#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <memory>
#include "BigInteger.h"
#include "RSABigInteger.h"
#include <time.h>
#include <bits/stdc++.h>

using std::cout;
using std::cerr;
using std::string;
using std::auto_ptr;

using namespace std;

#define SIZEN 98         //     word size bit = N*32
#define HALFSIZE 48      //

#define WORD_COUNT 390
#define SIZE 4096		//N

//# define arr2 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]

int returnVal (char x){
    return (int) x - 87;
}

BigInteger c_llint_to_bigi (long long int i){
	//cout<< "d\n";
	BigInteger j (WORD_COUNT);
	j = i;
	return j ;
}

BigInteger c_str_to_bigi (string str){
	int x ,i;
	x = str.length() ;
	//int i;
	BigInteger j (WORD_COUNT);
	BigInteger m (WORD_COUNT);

	for (i =0; i < x; i++){
		char a = str[i] ;
		long long int b = (long long int) a ;
		cout << b ;
		m = c_llint_to_bigi (b) ;
		j.addBigInteger(j,m);
	}
	
	return j ; 
}

void basicOperationOfBigInteger()
{
    BigInteger num1(SIZEN);
    BigInteger num2(SIZEN);

    RSABigInteger operationCheck(SIZEN);

    operationCheck.randomNGeneration(num1, HALFSIZE); // 1536 bit numbers
    operationCheck.randomNGeneration(num2, HALFSIZE); // 1536 bit numbers

    BigInteger add(SIZEN);
    BigInteger sub(SIZEN);

    cout<<"\nNum1 :\n";
    num1.showDigits();
    cout<<"\nNum2 :\n";
    num2.showDigits();
    

    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    add.addBigInteger(num1,num2);
    
    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("\nAddition took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
           
	cout<<"\nAddition = Num1 + Num2 :\n";
	add.showDigits();
	cout <<"\n \n" ;

    tstart={0,0};
    tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);

	sub.subBigInteger(add, num1);
    
    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("\nSubtraction took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    cout<<"\nSubtraction = Addition - Num1 :\n";
    sub.showDigits();
	cout <<"\n \n" ;
           
    BigInteger mult(SIZEN);
         
    tstart={0,0};
    tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    mult.multBigInteger(num1, num2);

    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("\nMultiplication took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    cout<<"\nMultiplication = Num1 * Num2 :\n";
    mult.showDigits();

    BigInteger qotnt(SIZEN);
    BigInteger rem(SIZEN);

    tstart={0,0};
    tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
 
    divBigInteger(mult, num1, qotnt, rem);

    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("\nDivistion took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
           
    cout<<"\nQuotient = Multiplication / Num1 :\n";
    qotnt.showDigits();

    cout<<"\nRemainder = Multiplication % Num1 :\n";
    rem.showDigits();

    BigInteger gcd(SIZEN);

    tstart={0,0};
    tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);

    gcdBigInteger(num1, num2, gcd);

    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("\nGCD took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));    
    
    
    cout<<"\nGCD (Num1, Num2) :\n";
    gcd.showDigits();

}

int main(int argc,  char** argv)
{

    
    srand ( time(NULL) );
    
    

    //call this function to see basic operation results of 1536 bits
    basicOperationOfBigInteger();
    
        int nSize;
    if(argc  < 2)
        nSize = SIZE;
    else
        nSize = atoi(argv[1]);

    nSize = nSize/32;
	cout <<"\n \n" ;
	
	//cout <<"\n \n" ;
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" ;
	
	cout <<"\n \n" ;

    cout<<"RSA Algorithm\n"<<endl;
    RSABigInteger rsa(WORD_COUNT);
    cout<<"\nRandom Prime Number Generation\n"<<endl;

    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    BigInteger primeNumberP(WORD_COUNT), primeNumberQ(WORD_COUNT);
    rsa.primeNumberGeneration(primeNumberP, nSize/2);
    cout<<"\nPrimeNumber, p=\n";
    primeNumberP.showDigits();	
	
    rsa.primeNumberGeneration(primeNumberQ, nSize/2);
    cout<<"\nPrimeNumber, q=\n";
    primeNumberQ.showDigits();

    rsa.init(primeNumberP,primeNumberQ);

    BigInteger rslt(WORD_COUNT);
//------------------------------------------------------------------------------
    //BigInteger msg(WORD_COUNT);
	//msg.showDigits();
    //RSABigInteger operationCheck(WORD_COUNT);
	//msg.showDigits();
    //operationCheck.randomNGeneration(msg, 4);
    cout<<"\nMessage to be Encrypted: "<<endl;

    // msg.showDigits();
	//stringstream ss;
	string str ;
	string str2;
	//str = "cryptographygroupprojectisexcellentinallthewayitcanbesoifyouwanttoexcelityouneedtoworkhard&smart" ;
	//str = "Supercalifragilisticexpialidocious" ;
	
	cin >> str;
	
	cout <<"\n" ;
		
	cout <<"\n" ;
	cout <<"Input String :\n" ;
	
	cout<< str;
	cout <<"\n" ;
	cout<<"\nNumericalized Message :"<<endl;
	//scanf("%s", str);
	//int q ;
	//q = str.length() ;
	//for (int i = 0; i < q; i++){
	//string temp;
	//temp = to_string (returnVal(str[i]));
	//cout << returnVal(str[i]);
	//ss >> temp ;
	//cout << temp;
	//cout <<"\n" ;
	//str2 = str2 + temp;

	//}
	//cout<<"\n!Done\n";
	//cout << str2 ;
	
	const int y = str.length()/2 ; 
	//long long int r ; 
	//cout <<"\n \n" ;
	//cin >> r ;
	BigInteger tem2 ;
	//tem2 = c_str_to_bigi (str2);
	
	//tem2 = c_llint_to_bigi (r);
	//const BigInteger T3  = tem2;
	BigInteger msg2 (WORD_COUNT);
	
	RSABigInteger operationCheck(WORD_COUNT);
	//msg.showDigits();
    operationCheck.randomNGeneration(msg2, y);
	msg2.showDigits();
	//cout<<msg2;
	//cout<<"\n \n";
	//cout << msg;
	//msg.showDigits();


    rsa.encryption(msg2,rslt);
    cout<<"\nEncrypted Message Code:\n";
    rslt.showDigits();
	
	//cout<<"\nDone"<<endl;

    rsa.decryption(rslt,msg2);
	//cout<<"\n"<<endl;
    cout<<"\nDecrypted Numericalized Message:\n";
    msg2.showDigits();
    //out<<"\nmsg<<endl;
	cout<<"\nDenumericalized Message:\n";
	string str3 ;
	//stringstream ss ;
	//char** cc = argv[1] ;
	//ss << cc ;
	//int pos ;
	//ss >> pos ;
	int pos = (atoi(argv[1]))/16;
	str3 = str.substr(0,pos);
	cout<< str3 ;
	cout<<"\n"<<endl;
    //cout<< argv[1] ;
    
    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("\nKey Generation & Encryption-Decryption took %.2f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec)); 

    return 0;
}

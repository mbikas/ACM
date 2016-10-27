#include <iostream>  
#include <string>  
   
using namespace std;  
   
/* 
#     I   1 
#     V   5 
#     X   10 
#     L   50 
#     C   100 
#     D   500 
#     M   1000 
# */  
   
#define EQUAL 0  
#define LARGER 1  
#define SMALLER -1  
  
enum eOperation  
 {  
     NONE = -1,  
     ADD = 0,  
     SUB = 1  
 };  
   
class Roman  
 {  
     private:  
         string szRoman;  
         int lResult;  
         bool isLarger(char cNum1, char cNum2);  
         int Roman2Decimal(char cRoman);  
         int myCompare(char cNum1, char cNum2);  
         void fnOperation(eOperation eOp, int lNum, int *lSum);  
     public:  
         void setRoman(string *szInput);  
         string getRoman();  
         void Convert();  
         int getDecimal();  
   
         Roman()  
         {  
             lResult = 0;  
         }  
 };  
   
int Roman::myCompare(char cNum1, char cNum2)  
 {  
     /* 
         RETURN 0    EQUAL 
         RETURN 1    LARGER 
         RETURN -1   SMALLER 
     */  
     int lNum1 = 0, lNum2 = 0;  
   
     lNum1 = Roman2Decimal(cNum1);  
     lNum2 = Roman2Decimal(cNum2);  
   
     if (lNum1 == lNum2)  
     {  
         return EQUAL;  
     }  
     else if (lNum1 > lNum2)  
     {  
         return LARGER;  
     }  
     else  
     {  
         return SMALLER;  
     }  
 }  
   
int Roman::Roman2Decimal(char cRoman)  
 {  
     switch (cRoman)  
     {  
         case 'I':  
             return 1;  
         case 'V':  
             return 5;  
         case 'X':  
             return 10;  
         case 'L':  
             return 50;  
         case 'C':  
             return 100;  
         case 'D':  
             return 500;  
         case 'M':  
             return 1000;  
     }  
   
     return 0;  
 }  
   
int Roman::getDecimal()  
 {  
     return lResult;  
 }  
   
void Roman::setRoman(string *szInput)  
{  
     szRoman = *szInput;  
     //Convert to upper  
     for (int i = 0; i < szRoman.length(); i++)  
     {  
         szRoman[i] = toupper(szRoman[i]);  
     }  
 }  
   
string Roman::getRoman()  
 {  
     return szRoman;  
 }  
   
void Roman::fnOperation(eOperation eOp, int lNum, int *lSum)  
 {  
     if (eOp == SUB)  
     {  
         *lSum -= lNum;  
     }  
     else  
     {  
         *lSum += lNum;  
     }  
 }  
   
 void Roman::Convert()  
 {  
     //LIIXVI = 64  
     int i = 0, lSum = 0, lNum = 0, lRes = 0;  
     eOperation myOperation;  
   
     myOperation = NONE;  
     for (i = szRoman.length() - 1; i >= 0; i--)  
     {  
         lNum = Roman2Decimal(szRoman[i]);  
         if (i == 0)  
         {  
             lRes = myCompare(szRoman[i], szRoman[i + 1]);  
             switch (lRes)  
             {  
                 case SMALLER:  
                     lSum -= lNum;  
                     break;  
                 default:  
                     fnOperation(myOperation, lNum, &lSum);  
             }  
         }  
         else  
         {  
             lRes = myCompare(szRoman[i], szRoman[i - 1]);  
             switch (lRes)  
             {  
                 case SMALLER:  
                     fnOperation(myOperation, lNum, &lSum);  
                     if (myOperation == SUB)  
                     {  
                         myOperation = ADD;  
                     }  
                     break;  
                 case EQUAL:  
                    fnOperation(myOperation, lNum, &lSum);  
                     break;  
                 case LARGER:  
                     fnOperation(myOperation, lNum, &lSum);  
                     if (myOperation != SUB)  
                     {  
                         myOperation = SUB;  
                     }  
                     break;  
             }  
         }  
     }  
   
     lResult = lSum;  
 }  
   
 int main()  
 {  
     string szRoman;
	 int n;
   
     Roman *myConvert;
   
    
	
	 scanf("%d",&n);

	 while(n--)
	 {
		 myConvert = new Roman;  
		 cin >> szRoman;  
		 myConvert->setRoman(&szRoman);  
		 myConvert->Convert();  
		 cout << myConvert->getDecimal() << endl;  
   
		delete (myConvert);  
	 }
    
 }  
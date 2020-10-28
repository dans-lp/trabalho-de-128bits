/* Daniel_Lages_de_Altavila_Peralta 1811442 3WA */
#include<stdio.h>
#include "bigInt.h"

void dumpArray(BigInt res);


int main(void){
  long a = -2, b = -3, c = -4;
  BigInt bi1, bi2, bi3, ArrayRes;

  /*signed int x = 0x4b;
  signed int y = 0x05;
  signed int z = 0xfffffffb;
  */

  printf("\n --------->teste<---------\n");
  big_val(bi1,a);
  
  /*

  printf("\n-----> teste oq entrou em res <-----\n");
  dumpArray(bi1);
  
  printf("\n\n-----> teste negação <-----\n");
  big_comp2(ArrayRes,bi1);
  dumpArray(ArrayRes);
  */
  printf("\n\n-----> teste soma <-----\n\n");
  big_val(bi2,b);
  big_val(bi3,c);
  
  printf("\n-----> 1º array <------\n");
  dumpArray(bi2);
  
  printf("\n-----> 2º array <------\n");
  dumpArray(bi3);


  big_sum(ArrayRes, bi2, bi3);
  printf("\n\n-----> soma dos arrays <------\n");
  dumpArray(ArrayRes);

  printf("\n");
  return 0;
}

void dumpArray(BigInt res){
  for (int k = 0; k < 16; k++)
    printf("%02X || ",res[k]);  
}
//printf(">>>>>>>> %dº byte de res: %02X\n",k,res[k]);  
void big_val (BigInt res, long val){
  signed char *c = (signed char*)&val;
  int i = 0;
  int n = 16;
  while (n--)
  {
    if (n < sizeof(val))
    {
      if (val >= 0)
        res[i] = 0x00;
      else
        res[i] = 0xFF;
    }
    else
    {
      //printf(">>>>>>>> %dº byte: ",i+1);
      //printf("%p - %02X\n", c, *c);
      res[i] = *c;
      c++;
    }
    i+=1;
  }
}

void big_comp2(BigInt res, BigInt a){  
  for(int i = 0; i < 16; i++)
    res[i] = ~ a[i];  

  if (a[15] == 0x00)
    res[0] =  res[0]-1;
  else
    res[0] = res[0]+1;
}


void big_sum (BigInt res, BigInt a, BigInt b){
  int carry = 0;
  
  for (int i = 0; i<16; i++){
  res[i] = a[i]+b[i]+carry;
  if (res[i]>= 0xFF)
  {
    /* code */
  }
  
  }

}
//Objetivo do código: tenho dois arrays que representam uma sequencia de bytes
//eu apenas tenho que somar os arrays e colocar a resposta em res
//o problema é na soma de bits ocorrer um overflow e ser necessarios passar o bit excente na proxima casa do array
//não to sabendo como acionar carry quando ocorre esse excedente

#include "Tamil.h"
#include "TamilFont.h"

char inputlist[40][8];
uint8_t mb[8][8];

void clean()
{
  for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
          mb[i][j]=0x00;
}

void charcreator(LiquidCrystal LC)
{
  for(int i=0;i<8;i++)
      LC.createChar(i,mb[i]);
}

void setcreator(int len,LiquidCrystal LC)
{
  int i,j,c=0,z=0;
  do
  {
    clean();
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            mb[i][j]=inputlist[c+z][j];
        c++;
    }
    z++;
    c=0;
    len--;
    charcreator(LC);
    paint(LC);
  }
  while(len>0);
}

void paint(LiquidCrystal LC)
{ 
   for(int i=0;i<8;i++)
   {
       LC.setCursor(i,0);
       LC.write(i);
       delay(300);
   }
}

void searchandadd(int len,int datainput[]){
  int l,u,mid,y=0;
  for(int i=0;i<len;i++)
  {
    l=0,u=80;
    while(l<=u)
    {
      mid=(l+u)/2;
      if(datainput[i]==t_engref[mid])
      {
        for(int k=0;k<8;k++)
             inputlist[y][k]=tamilref[mid][k];
        y++;
        break;
      }
      else if(datainput[i]<t_engref[mid])
        u=mid-1;
      else
        l=mid+1;
     }
  }
}


void tamilDisplay(LiquidCrystal LC,String input)
{
    int index=input.length(); 
    int datainput[index];
    for(int i=0;i<index;i++)
    {
	datainput[i]=(int)input.charAt(i);
    }
    searchandadd(index,datainput);
    setcreator(index,LC);
    LC.clear();
}

//Pedro Lucas Santana
//202017049

//Radares

#include <stdio.h>

double calculo(int tA, int tB, double distancia){
  double T, velocidadeMedia;
  T=tB-tA;
  velocidadeMedia = distancia/(T/3600);
  return velocidadeMedia;
}

int recebmulta(int tA, int tB, double distancia, double velocidadeMaxima){
  double multa=0;
  double velocidadeMedia = calculo(tA, tB, distancia);
  if(velocidadeMedia > velocidadeMaxima) multa++;
  return multa;
}

int main(){
  int tA, tB;
  double distancia, velocidadeMaxima;
  int multa = recebmulta(54169, 57346, 170.0, 120.0);
  printf("%d\n", multa);

  return 0;
}
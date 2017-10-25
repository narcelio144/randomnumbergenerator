#include <climits>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>

using namespace std;

long double seed = 0;
unsigned int ulseed;
int roll=10;

unsigned int seed_(int x=3,int y=1, int z=-2,int w=-2) {
  long sysTime = time(0);
  long double div = 1.0;
  seed = 0;
  for(long double k = 0; div != 0; k++, div /= 16)
    seed += div*(x/(8*k+1) + y/(8*k+4) + z/(8*k+5) + w/(8*k+6));
    //Como sugerido pelo artigo, existem centenas de opções aqui, caberá ao usuario modificar os coeficientes ou nao.
  ostringstream sstseed;
  sstseed.precision(58);
  sstseed << seed;
  string subseed = sstseed.str().substr(roll,10);
  string::size_type sz;
  long lseed = stol(subseed.c_str(),&sz);
  ulseed = lseed*sysTime;
  roll=((roll+1)%10)+10;
  return ulseed;
}


unsigned int rand_(){
  return ulseed = (ulseed*120764733119ull + 120764733659ull);
}

void test_(){
  const int TOTAL = 1000000;
  const int ONE_PERCENT = UINT_MAX/100;

  unsigned int rnumber;
  map<unsigned int, int> hst;
  int cnt=0, i=1, cycle = 0;
  for(; i <= TOTAL; i++) {
    rnumber = rand_();
    if (rnumber < ONE_PERCENT) cnt++;
    if (hst[rnumber] and !cycle) cycle = hst[rnumber] - i;
    hst[rnumber] = i;
  }

  printf("\nGerados %d numeros dos quais %d são menores que %d (1%%).\n", TOTAL, cnt, ONE_PERCENT);
  if (cycle) printf("Encontrado ciclo de tamanho %d\n", cycle);
}

int main(int argc, char const *argv[]) {
  int op=1;
  seed_();
  printf("\tBem vindo ao: \n\n");
  printf(" $$$$$$\\                                        $$$$$$\\ $$\\      $$\\ $$$$$$$$\\ \n");
  printf("$$  __$$\\                                       \\_$$  _|$$$\\    $$$ |$$  _____|\n");
  printf("$$ /  \\__| $$$$$$\\  $$$$$$$\\   $$$$$$\\   $$$$$$\\  $$ |  $$$$\\  $$$$ |$$ |  \n");    
  printf("$$ |$$$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$ |  $$\\$$\\$$ $$ |$$$$$\\    \n");
  printf("$$ |\\_$$ |$$$$$$$$ |$$ |  $$ |$$$$$$$$ |$$ |  \\__|$$ |  $$ \\$$$  $$ |$$  __|   \n");
  printf("$$ |  $$ |$$   ____|$$ |  $$ |$$   ____|$$ |      $$ |  $$ |\\$  /$$ |$$ |      \n");
  printf("\\$$$$$$  |\\$$$$$$$\\ $$ |  $$ |\\$$$$$$$\\ $$ |    $$$$$$\\ $$ | \\_/ $$ |$$$$$$$$\\ \n");
  printf(" \\______/  \\_______|\\__|  \\__| \\_______|\\__|    \\______|\\__|     \\__|\\________|\n");

  printf("\nO gerador de números aleatórios do IME\n\n");


  do{
    printf("Escolha uma das opções abaixo...\n");
    printf("1) Gerar e imprimir o seed.\n");
    printf("2) Modificar parametros do seed.\n");
    printf("3) Gerar um número aleatório.\n");
    printf("4) Testar aleatoridade da funcao.\n");
    printf("0) Para sair.\n");
    scanf("%d",&op);
    switch(op){
      case 0:
        printf("Obrigado, volte sempre\n");
      break;
      case 1:
        seed_();
        printf("Seed gerado com sucesso...\n%u\n\n", ulseed);
      break;
      case 2:
        int x,y,z,w;
        printf("Conforme proposto no artigo, existem 4 parâmetros que são cambiáveis. \n Tratam-se de inteiros que  são os numeradores das frações.\n");
        printf("x: ");
        scanf("%d",&x);
        printf("y: ");
        scanf("%d",&y);
        printf("z: ");
        scanf("%d",&z);
        printf("w: ");
        scanf("%d",&w);
        seed_(x,y,z,w);
        printf("Seed gerado com sucesso...\n%u\n\n", ulseed);
      break;
      case 3:
        printf("Seed: %u \nNumero gerado com sucesso... \n%u \n\n", ulseed, rand_());
      break;
      case 4:
        test_();
      break;
      default:
        printf("Opcao invalida.");
      break;
    }

  }while(op!=0);
  return 0;
}

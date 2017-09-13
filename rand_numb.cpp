#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;
long double seed = 0;
unsigned int ulseed;

long double seed_(int x=3,int y=1, int z=-2,int w=-2) {

	long sysTime = time(0);
  	long double div = 1.0;
  	seed = 0;
  	for(long double k = 0; div != 0; k++, div /= 16)
    	seed += div*(x/(8*k+1) + y/(8*k+4) + z/(8*k+5) + w/(8*k+6));		//Como sugerido pelo artigo, existem centenas de opções aqui, caberá ao usuario modificar os coeficientes ou nao.
  	printf("%ld\n", sysTime);
  	printf("%.60Lf\n", seed);
  	ostringstream sstseed;
  	sstseed.precision(58);
  	sstseed << seed;
  	cout << sstseed.str() << endl;
  	string subseed = sstseed.str().substr(15,10);
  	printf("Substring: %s\n", subseed.c_str());
  	string::size_type sz;
  	long lseed = stol(subseed.c_str(),&sz);
  	printf("%lu\n", lseed);
  	ulseed = lseed*sysTime;
  	return seed;
}


long rand_()
  {
  	printf("%Lf\n", seed);
  	printf("%u\n", ulseed);
    return ulseed =  (ulseed*5086967+982482349169);
  }

int main(int argc, char const *argv[])
{
	int op=1;
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
	            printf("Conforme proposto no artigo, existem 4 parâmetros que são cambiáveis. \n Tratam-se de inteiros que  são os numeradores das frações.\n ");
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
	            printf("Gerando numero... \n... \nNumero gerado com sucesso... \n%lu \n\n", rand_());
	            break;

        	default:
	            printf("Opcao invalida.");
	            break;
    	}

		// for(int i=0;i<1;i++)
		// 	rand_();
		
	}while(op!=0);
	return 0;
}



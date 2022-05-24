#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binario(int x){
    
    return (x == 0) ? 0: (binario (x / 2) * 10) | (x % 2); 
}

int main()
{
    unsigned char armario = 0;
    int opcao, j, libera, numeroArmario[8] = {1,2,3,4,5,6,7,8};
    srand(time(NULL));
    
    do{
        puts("Digite uma das opcoes:\n(1)Ocupar armario.\n(2)Liberar armario.\n(3)Sair.");
        scanf("%d",&opcao);
        
        if(opcao == 1){
            do{
                j = rand() % 8; 
                }while(numeroArmario[j] == 0);
            
    printf("%d° armario agora esta ocupado.",numeroArmario[j]);
    switch(numeroArmario[j]){
        case 1:
        armario = armario | 128; 
        break;
        case 2:
        armario = armario | 64; 
        break;
        case 3:
        armario = armario | 32; 
        break;
        case 4:
        armario = armario | 16; 
        break;
        case 5:
        armario = armario | 8; 
        break;
        case 6:
        armario = armario | 4; 
        break;
        case 7:
        armario = armario | 2; 
        break;
        case 8:
        armario = armario | 1; 
        break;
        
        }
        numeroArmario[j] = 0; 
        continue;
        }
    else if(opcao == 2){
        printf("Qual armario voce quer desocupar? %d ",binario(armario));
        scanf("%d",&libera);
        switch(libera){
            case 1:
            armario = armario & ~128; 
            break;
            case 2:
            armario = armario & ~64;
            break;
            case 3:
            armario = armario & ~32;
            break;
            case 4:
            armario = armario & ~16; 
            break;
            case 5:
            armario = armario & ~8; 
            break;
            case 6:
            armario = armario & ~4;
            break;
            case 7:
            armario = armario & ~2; 
            break;
            case 8:
            armario = armario & ~1; 
            break;
            }
        printf("Armarios: %d\n",binario(armario));
        continue;
        }

    } while(opcao != 3);
    puts("Finalizado.");
    
    return 0;
}
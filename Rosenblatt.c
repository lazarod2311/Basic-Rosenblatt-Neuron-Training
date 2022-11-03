#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
    int ep,valru = 0,valcomp = 0, comp[7],out, ref,erro=1,sig; //definindo o vetor inteiro que receberá os valores do RU e a variavel soma
    int *valaleat; //ponteiro para alocar um vetor com os numeros aleatorios gerados e permitir que esses não se repitam
    double w[7];//vetor para os pesos de ponto duplo
    double bias = -1, soma = 0,taxa;//definindo valores para o limiar de ativação (bias), a soma (wi*xi) e a taxa de aprendizado
    char ru[8];//definindo um vetor de caracteres para receber o RU
    printf("Digite o RU: ");
    fflush(stdin);
    fgets(ru,8,stdin);//lendo o RU
    printf("Digite o numero de epocas de treinamento: ");
    scanf("%d",&ep);//lendo o número de épocas
    printf("Digite a taxa de aprendizado (valor entre 0 e 1): ");
    scanf("%lf",&taxa);//lendo a taxa de aprendizado
    srand(time(NULL));//definindo a semente dos números aleatórios como não sendo o tempo do relógio
    valaleat = (int)malloc(sizeof(int)*(ep-1));//alocando o vetor dos numeros aleatorios
    for (int i=0; i<ep;i++) {//enchendo o vetor aleatorio com zeros
        valaleat[i] =0;
    }
    for (int i=0; i<7; i++) {//gerando o valor do RU em um único inteiro e atribuindo 1 aos pesos
        valru = valru + ((int)(ru[i])-48)*pow(10,(6-i));
        w[i] = 1;
    }
    printf("\nEpoca em treino : \n");
    for (int i=0; i<ep-1; i++) {//realizando o treinamento
    printf ("\r%d" ,i+1);
    sig = 1;
        do {//só sai quando o número aleatorio não se repetir
            for (int j=0; j<7; j++) {//gerando um vetor aleatorio e convertendo para um valor inteiro
                comp[j] = (int)(rand()%10);
                valcomp = valcomp + comp[j]*pow(10,(6-j));           
            }
            if (i ==0){
                valaleat[i] = valcomp;
                sig = 0;
            }
            for (int k=0; k<i;k++){
                if(valaleat[k] != valcomp) {
                    sig = 0;
                    valaleat[i] = valcomp;
                }else{
                    sig = 1;
                }
            }
        }while (sig != 0);
        if (valcomp >= valru) {//comparando o valor ao RU e estabelecendo a referencia de saída
            ref = 1;
        }else {//caso seja menor que o valor do RU, o valor de referência receberá -1
            ref = -1;
        }
        valcomp = 0;// atribui zero ao valor de comparação, pois o mesmo será usado outra vez na próxima época
        for (int j=0; j<7; j++) {//operação de soma do neurônio
            soma = soma + (double)(comp[j])*w[j];        
        }
        soma = soma + bias;//soma + limiar (bias)
        if (soma >= 0) {//função de ativação
            out = 1;
        }else {
            out = -1;
        }
        erro = out - ref;//cálculo do erro
        soma = 0;
        while (erro != 0){//realiza as operações de treinamento
            for(int j=0; j<7; j++) {
                w[j] =w[j] - ((double)(comp[j]*erro)*taxa);
            }
            bias = bias + ((double)(erro)*taxa);
            for (int j=0; j<7; j++) {
                soma = soma + (double)(comp[j])*w[j];        
            }
            soma = soma + bias;
            if (soma >= 0) {
                out = 1;
            }else {
                out = -1;
            }
            erro = out - ref;
            soma = 0;    
        }
    }
    printf ("\r%d" ,ep);
    ref = 1;
    for (int i=0; i<7; i++) {//ultima época do neurônio é com o valor do RU
        soma = soma + (double)(((int)(ru[i])-48))*w[i];        
    }
    soma = soma + bias;//soma + limiar (bias)
    if (soma >= 0) {//função de ativação
        out = 1;
    }else {
        out = -1;
    }
    erro = out - ref;//cálculo do erro
    soma = 0;
    while (erro != 0){//realiza as operações de treinamento
        for(int j=0; j<7; j++) {
            w[j] =w[j] - ((double)(comp[j]*erro)*taxa);
        }
        bias = bias + ((double)(erro)*taxa);
        for (int j=0; j<7; j++) {
            soma = soma + (double)(comp[j])*w[j];        
        }
        soma = soma + bias;
        if (soma >= 0) {
            out = 1;
        }else {
            out = -1;
        }
        erro = out - ref;
        soma = 0;    
    }
    printf("\n\nPesos:\n");//mostrando os pesos
    for (int i=0; i<7; i++) {//imprimindo cada peso por vez
        printf("w[%d]: %.4f\n" ,i ,w[i]);
    }
    printf("\nBias: %.4f\n" ,bias);//mostrando o bias
    system("pause");
    return 0;
}
#include <stdio.h>

int main() {
    double preco_alcool, preco_gasolina, rendimento_alcool, rendimento_gasolina;
    
    // Lê os valores de entrada
    scanf("%lf %lf %lf %lf", &preco_alcool, &preco_gasolina, &rendimento_alcool, &rendimento_gasolina);
    
    // Calcula o custo por quilômetro para o álcool e a gasolina
    double custo_km_alcool = preco_alcool / rendimento_alcool;
    double custo_km_gasolina = preco_gasolina / rendimento_gasolina;
    
    // Verifica se é mais econômico abastecer com álcool ou gasolina e imprime o resultado
    if (custo_km_alcool < custo_km_gasolina) {
        printf("A\n");
    } else {
        printf("G\n");
    }
    
    return 0;
}
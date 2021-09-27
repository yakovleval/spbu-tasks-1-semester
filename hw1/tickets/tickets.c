#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// компилятор не позволил указать размер массива
// даже с помощью const переменных, не придумал как это сделать
// без дефайнов или магических констант :(
#define maxTerms 3
#define maxTermsSum 27

void main()
{
    setlocale(LC_ALL, "Russian");

    long long numberOfTermSums[maxTerms + 1][maxTermsSum + 1] = {{1}, {1}, {1}, {1}};
    for (int termsNumber = 1; termsNumber <= maxTerms; termsNumber++)
    {
        long long prefixSum = 0;
        for (int termsSum = 0; termsSum <= maxTermsSum; termsSum++)
        {
            prefixSum += numberOfTermSums[termsNumber - 1][termsSum];
            const int digitsNumber = 10;
            if (termsSum >= digitsNumber)
            {
                prefixSum -= numberOfTermSums[termsNumber - 1][termsSum - digitsNumber];
            }
            numberOfTermSums[termsNumber][termsSum] = prefixSum;
        }
    }
    long long happyTickets = 0;
    for (int termsSum = 0; termsSum <= maxTermsSum; termsSum++)
    {
        numberOfTermSums[maxTerms][termsSum] *= numberOfTermSums[maxTerms][termsSum];
        happyTickets += numberOfTermSums[maxTerms][termsSum];
    }
    printf("количество счастливых билетиков равно %lld", happyTickets);
}
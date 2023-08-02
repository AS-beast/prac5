#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int lab(int n) {     /* Функція перевірки, чи є в числі три послідовних 1 */
    int lab_count = 0;
    int consecutiveOnes = 0;
    while (n > 0) {
        int number = n % 10;
        n /= 10;
        if (number == 1) {
            consecutiveOnes++;
            if (consecutiveOnes >= 3) {
                lab_count++;
                break;
            }
        }
        else {
            consecutiveOnes = 0;
        }
    }
    return lab_count;
}
int countNumbers(int p) {  /* Функція підрахунку кількості допустимих чисел з p */
    if (p == 1)
        return 2; 
    if (p == 2)
        return 4; 

    int current = 0;
    int total_count = pow(2, p);
    for (int i = 0; i < total_count; i++) {
        int combinedNumber = 0;
        for (int j = p - 1; j >= 0; j--) {
            int bit = (i >> j) & 1;
            int digit = bit ? 1 : 0;
            combinedNumber += digit * pow(10, j);
        }
        current += lab(combinedNumber); /* Викликати функцію для перевірки комбінованого числа з трьома або більше одиницями підряд і оновити підрахунок.  */
    }
    return (total_count - current);
}

int main() {
    int p; 
    printf("Введіть довжину послідовності n: ");
    scanf("%d", &p);
    if (p>=1){
       int count = countNumbers(p);
        printf("Кількість шуканих послідовностей: %u\n",count);
    }
    return 0;
}
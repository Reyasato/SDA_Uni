

<!-- Start of picture text -->
inn ee<br><!-- End of picture text -->

**Міністерство освіти і науки України Національний технічний університет України Київський політехнічний інститут імені Ігоря Сікорського** 

# **Лабораторна робота № 1** 

«Розгалужені алгоритми» 

Роботу виконала Студентка групи ІО-63 Малова В. А. Номер у списку групи: 13 Роботу перевірив: Русінов В.В 

Київ 2026 

## **1.Мета лабораторної роботи** 

Метою лабораторної роботи «Розгалужені алгоритми» є засвоєння теоретичного матеріалу та набуття практичних навичок використання керуючих конструкцій розгалуження та булевих (логічних) операцій. 

## **2. Постановка завдання** 

Задано дійсне число x. Визначити значення заданої за варіантом кусковонеперервної функції y(x), якщо воно існує, або вивести на екран повідомлення про неіснування функції для заданого x. 

Необхідно розв'язати задачу двома способами: 

1. У програмі дозволяється використовувати тільки одиничні операції порівняння (=, <>, <, <=, >, >=) і не дозволяється використовувати булеві (логічні) операції (not, and, or тощо). 

2. У програмі необхідно обов'язково використати булеві (логічні) операції (not, and, or тощо). Використання булевих операцій не повинно бути надлишковим. 

## **3.Завдання за варіантом:** 



<!-- Start of picture text -->
3, 13,23 -14x-<br>20, x € (-21,3] U (12, +00) 13x?/11 — 6, x € (00, 41]<br><!-- End of picture text -->

**4. Блок-схема алгоритму 1:** 



<!-- Start of picture text -->
Bapiair 13, nporpanea 1 603 <_Besin ><br>input x /<br>1 oN °<br>Se par nH<br>~~ [tris xr<br>output y = /<br>=n ‘output “Function is<br>(ema >)<br><!-- End of picture text -->

## **Блок-схема алгоритму 2:** 



<!-- Start of picture text -->
Bapiaur13, nporpawa23 Ge ben<br>weoutx—/<br>=<br>f << 6-21 88 x29) I-12 ><br>ya420 [Eey/<br>Ta dieady: /<br>ci<br>CzlEna<br><!-- End of picture text -->

**5. Код програми 1:** 

#include <stdio.h> 

**int** main() { **double** x, y; y = 0; x = 0; printf("Enter x: "); scanf("%lf", &x); **if** (x <= -41) { y = 13 * x * x / 11 - 6; printf("y = %.2lf\n", y); } **else** { **if** (x > 12) { y = -14 * x - 20; printf("y = %.2lf\n", y); } **else** { **if** (x > -21) { **if** (x <= 3) { y = -14 * x - 20; printf("y = %.2lf\n", y); } **else** { printf("Function is not defined for this x.\n"); } } **else** { printf("Function is not defined for this x.\n"); } } } **return** 0; } 

## **Код програми 2:** 

#include <stdio.h> 

**int** main() { **double** x, y; printf("Enter x: "); scanf("%lf", &x); **if** (x <= -41) { y = 13 * x * x / 11 - 6; printf("y = %.2lf\n", y); } **else if** ((x > -21 && x <= 3) || x > 12) { y = -14 * x - 20; printf("y = %.2lf\n", y); } **else** { printf("Function is not defined for this x.\n"); } **return** 0; } **6. Тест програми 1:** 



<!-- Start of picture text -->
C:\Users\MLVMLK\CLionProjects\LearnCGreat\1ab1_1.exe<br>Enter x:-88<br>y = 9146.00<br>Process finished with exit code 0<br><!-- End of picture text -->



<!-- Start of picture text -->
C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_1.exe<br>Enter x:-20<br>y = 260.00<br>Process finished with exit code 0<br><!-- End of picture text -->



<!-- Start of picture text -->
5 3<br>C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_1.exe<br>Enter x:-38<br>‘Function is not defined for this x<br>in Alt+4 ss finished with exit code @<br><!-- End of picture text -->



<!-- Start of picture text -->
C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_1.exe<br>Enter x:3<br>y = -62.00<br>Process finished with exit code 0<br>|<br><!-- End of picture text -->



<!-- Start of picture text -->
ic}<br>C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_1.exe<br>Enter x:4<br>=° Function is not defined for this x.<br>Zu<br>(Process finished with exit code 0<br>fn |<br><!-- End of picture text -->



<!-- Start of picture text -->
& :<br>C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_1.exe<br>Enter x:33<br>= y = -482.00<br>EY<br>& Process finished with exit code 0<br>| |<br><!-- End of picture text -->

**Тест програми 2:** 

C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_2.exe Enter x:-42 

y = 2078.73 Process finished with exit code 0 

C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_2.exe Enter x:-40 

Function is not defined for this x. 

Process finished with exit code 0 

C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_2.exe Enter x:3 Py = -62.00 L ) Process finished with exit code 0 I 

C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_2.exe Enter x:-22 

Function is not defined for this x. Process finished with exit code 0 



<!-- Start of picture text -->
C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_2.exe<br>Enter x:12<br>Function is not defined for this x.<br>Process finished with exit code 0<br><!-- End of picture text -->



<!-- Start of picture text -->
IGS :<br>C:\Users\MLVMLK\CLionProjects\LearnCGreat\lab1_2.exe<br>Enter x:13<br>“© y = -202.00<br>=u<br>() Process finished with exit code 0<br>a |<br><!-- End of picture text -->

**Висновок:** У ході виконання лабораторної роботи було розглянуто два варіанти виконання розгалуджениї алгоритмів, в програмі 1 використано одиничні операції порівняння, в програмі 2 було використано логічні(булеві) операції. Також виконуючи лабораторну роботу навчились будувати блоксхеми до розгалуджених алгоритмів, а в кінці виконання протестували написані програми в середовищі розробки Clion. 


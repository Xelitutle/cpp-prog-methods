#include <stdio.h>
#include <limits.h>
#include <math.h>


namespace task_1_1_2
{
  /*
  Задача 1-1-2.
  Найдите максимум из целых чисел a и b.
  */

  int get_max(int first, int second)
  {
    return first > second ? first : second;
  }

  void test(int first, int second, int expected, int test_num) {
    int result = get_max(first, second);
    if (result == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! get_max(%d, %d) = %d, expected %d\n",
        test_num, first, second, result, expected);
    }
  }

  // Прогон всех тестов
  void all_tests()
  {
    test(5, 3, 5, 1);
    test(-10, 4, 4, 2);
    test(100, -100, 100, 3);
    test(0, 0, 0, 4);
    test(INT_MAX, INT_MAX, INT_MAX, 5);
    test(INT_MIN, INT_MIN, INT_MIN, 6);
    test(INT_MAX, 1, INT_MAX, 7);
    test(INT_MIN, -1, -1, 8);
    test(INT_MAX, INT_MIN, INT_MAX, 9);
    test(-5, -10, -5, 10);
    test(-25, -25, -25, 11);
    test(-1, -999, -1, 12);
    test(10, 20, 20, 13);
    test(20, 10, 20, 14);
  }
}


namespace task_1_1_4
{
  /*
  Задача 1-1-4.
  Замените содержимое a на |a|.
  */

  void replace_with_absolute(int &a)
  {
    if (a < 0) {
      a = -a;
    }
  }

  void test(int initial, int expected, int test_num) {
    int value = initial;
    replace_with_absolute(value);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! replace_with_absolute(%d) = %d, expected %d\n",
        test_num, initial, value, expected);
    }
  }

  // Прогон всех тестов
  void all_tests()
  {
    test(5, 5, 1);
    test(-5, 5, 2);
    test(0, 0, 3);
    test(-100, 100, 4);
    test(100, 100, 5);
    test(INT_MIN, INT_MAX + 1U, 6); // Особый случай для минимального int
    test(INT_MAX, INT_MAX, 7);
    test(-1, 1, 8);
    test(1, 1, 9);
    test(-99999, 99999, 10);
  }
}


namespace task_1_1_5
{
  /*
  Задача 1-1-5.
  Найдите знак целого числа a, т. е. реализуйте функцию int sign(int a).
  */

  int sign(int value)
  {
    return (value > 0) ? 1 : ((value < 0) ? -1 : 0);
  }

  void test(int initial, int expected, int test_num)
  {
    int value = sign(initial);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! sign(%d) = %d, expected %d\n",
        test_num, initial, value, expected);
    }
  }

  void all_tests()
  {
    test(0, 0, 1);
    test(1, 1, 2);
    test(-1, -1, 3);
    test(INT_MIN, -1, 4);
    test(INT_MAX, 1, 5);
    test(255, 1, 6);
    test(-255, -1, 7);
  }
}


namespace task_1_1_6
{
  /*
  Задание 1-1-6.
  Для заданных целых чисел a, b, c найдите количество целочисленных решений уравнения a · x + b = c.
  */

  unsigned root_count(int a, int b, int c)
  {
    if (a != 0 && (c - b) % a == 0) return 1;
    else return 0;
  }

  void test(int a, int b, int c, int expected, int test_num)
  {
    int value = root_count(a, b, c);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! root_count(%d, %d, %d) = %d, expected %d\n",
        test_num, a, b, c, value, expected);
    }
  }
  
  void all_tests()
  {
    test(2, 1, 5, 1, 1);
    test(-3, 4, 10, 1, 2);
    test(1, 0, 100, 1, 3);
    test(7, -5, 2, 1, 4);
    test(3, 1, 5, 0, 5);
    test(2, 0, 1, 0, 6);
    test(-4, 3, 2, 0, 7);
    test(0, 5, 5, 0, 8);
    test(0, 5, 3, 0, 9);
    test(0, 0, 0, 0, 10);
    test(0, -100, 50, 0, 11);
    test(2, 1, 3, 1, 12);
    test(2, 1, 4, 0, 13);
    test(-2, 5, 1, 1, 14);
    test(-3, 2, -7, 1, 15);
    test(-3, 2, -8, 0, 16);
    test(1000000, 500000, 1500000, 1, 17);
    test(1000000, 500000, 1500001, 0, 18);
  }
}


namespace task_1_1_8
{
  /*
  Задание 1-1-8.
  Для заданного действительного x выберите наибольшее из следующих чисел:
  x2 − 3, 
  5(x − 12)(x + 2), 
  17x + 1, 
  (x + 1)(x + 2)(x − 3) − 10.
  */

  double f1(double x)
  {
    return x * x - 3;
  };

  double f2(double x)
  {
    return 5 * (x - 12) * (x + 2);
  }

  double f3(double x)
  {
    return 17 * x + 1;
  }

  double f4(double x)
  {
    return (x + 1) * (x + 2) * (x - 3) - 10;
  }
  
  double max(double a, double b)
  {
    return a > b ? a : b;
  }

  double find_max(double x)
  {
    double a = f1(x);
    double b = f2(x);
    double c = f3(x);
    double d = f4(x);
    return max(max(max(a, b), c), d);
  }

  void test(double initial, double expected, double eps, int test_num)
  {
    double value = find_max(initial);
    if (fabs(value - expected) < eps) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! find_max(%lf) = %lf, expected %lf\n",
        test_num, initial, value, expected);
    }
  }

  void all_tests()
  {
    test(-1000.0, 5049880.0, 1e-10, 1);
    test(-100.0, 54880.0, 1e-10, 2);
    test(-10.0, 880.0, 1e-10, 3);
    test(-5.0, 255.0, 1e-10, 4);
    test(-2.0, 1.0, 1e-10, 5);
    test(-1.0, -2.0, 1e-10, 6);
    test(0.0, 1.0, 1e-10, 7);
    test(1.0, 18.0, 1e-10, 8);
    test(5.0, 86.0, 1e-10, 9);
    test(10.0, 914.0, 1e-10, 10);
    test(12.0, 1628.0, 1e-10, 11);
    test(15.0, 3254.0, 1e-10, 12);
  }
}


namespace task_1_1_9
{
  /*
  Задача 1-1-9.
  Проверьте, принадлежит ли вещественное число x отрезку [a, b].
  */

  int check_range(double a, double b, double x)
  {
    if (x > a)
    {
      if (x < b) 
        return 0;
      else 
        return 1;
    }
    else return -1;
  }

  void test(double a, double b, double x, int expected, int test_num)
  {
    int value = check_range(a, b, x);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! check_range(%lf, %lf, %lf) = %d, expected %d\n",
        test_num, a, b, x, value, expected);
    }
  }

  void all_tests()
  {
    test(0.0, 2.0, 1.0, 0, 1);
    test(0.0, 2.0, -1.0, -1, 2);
    test(0.0, 2.0, 3.0, 1, 3);
    test(-3.0, -1.0, -2.0, 0, 4);
    test(-3.0, -1.0, -4.0, -1, 5);
    test(-3.0, -1.0, -0.5, 1, 6);
  }
}


namespace task_1_1_10
{
  using namespace task_1_1_9;
  
  int check_two_range(double num)
  {
    return (check_range(1.0, 11.0, num) == 0) || (check_range(101.0, 1001.0, num) == 0 );
  }

  void test(double x, int expected, int test_num)
  {
    int value = check_two_range(x);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! find_max(%lf) = %d, expected %d\n",
        test_num, x, value, expected);
    }
  }

  void all_tests()
  {
    test(0.0, 0, 1);
    test(1.1, 1, 2);
    test(2.0, 1, 3);
    test(10.9, 1, 4);
    test(12.0, 0, 5);
    test(102.0, 1, 6);
    test(1002.0, 0, 7);
  }
}


namespace task_1_1_11
{
  /*
  Задание 1-1-11
  Проверьте, принадлежит ли число x объединению и/или пересечению отрезков [a1, b1], [a2, b2].
  */

  int check_two_range(double a1, double b1, double a2, double b2, double num)
  {
    using namespace task_1_1_9;
    return (check_range(a1, b1, num) == 0) || (check_range(a2, b2, num) == 0 );
  }

  void test(double a1, double b1, double a2, double b2, double x, int expected, int test_num)
  {
    int value = check_two_range(a1, b1, a2, b2, x);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! check_two_range(%lf, %lf, %lf, %lf, %lf) = %d, expected %d\n",
        test_num, a1, b1, a2, b2, x, value, expected);
    }
  }

  void all_tests()
  {
    test(1.0, 11.0, 101.0, 1001.0, 0.0, 0, 1);
    test(1.0, 11.0, 101.0, 1001.0, 1.1, 1, 2);
    test(1.0, 11.0, 101.0, 1001.0, 2.0, 1, 3);
    test(1.0, 11.0, 101.0, 1001.0, 10.9, 1, 4);
    test(1.0, 11.0, 101.0, 1001.0, 12.0, 0, 5);
    test(1.0, 11.0, 101.0, 1001.0, 102.0, 1, 6);
    test(1.0, 11.0, 101.0, 1001.0, 1002.0, 0, 7);
  }
}


namespace task_1_1_12
{
  /*
  Задача 1-1-12.
  Проверьте, принадлежит ли число x интервалам (a1, b1), (a2, b2), (a3, b3), 
  и если принадлежит, то укажите номер каждого такого интервала.
  */

  int check_two_range(
    double a1, double b1, 
    double a2, double b2, 
    double a3, double b3,
    double num)
  {
    using namespace task_1_1_9;
    return (check_range(a1, b1, num) == 0) || (check_range(a2, b2, num) == 0 ) || (check_range(a3, b3, num) == 0);
  }

  void test(double a1, double b1, double a2, double b2, double a3, double b3, double x, int expected, int test_num)
  {
    int value = check_two_range(a1, b1, a2, b2, a3, b3, x);
    if (value == expected) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! check_two_range(%lf, %lf, %lf, %lf, %lf, %lf, %lf) = %d, expected %d\n",
        test_num, a1, b1, a2, b2, a3, b3, x, value, expected);
    }
  }

  void all_tests()
  {
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 0.0, 0, 1);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 1.1, 1, 2);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 2.0, 1, 3);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 10.9, 1, 4);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 12.0, 0, 5);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 102.0, 1, 6);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, 1002.0, 0, 7);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, -7.0, 1, 8);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, -11.0, 0, 9);
    test(1.0, 11.0, 101.0, 1001.0, -10.0, -5.0, -4.0, 0, 10);
  }
}


namespace task_1_1_13
{
  /*
  Задача 1-1-13.
  Вычислите |a| + |b|, ||a| - |b||, ||a + b| - |a - b||
  */

  double abs_sum(double a, double b)
  {
    return fabs(a) + fabs(b);
  }

  double abs_sub(double a, double b)
  {
    return fabs(fabs(a) - fabs(b));
  }

  double abs_expr(double a, double b)
  {
    return fabs(fabs(a + b) - fabs(a - b));
  }

  void test(double a, double b, double exp_sum, double exp_sub, double exp_expr, double eps, int test_num)
  {
    double value = abs_sum(a, b);
    if (fabs(value - exp_sum) < eps) {
      printf("Test %d.1: PASS\n", test_num);
    }
    else {
      printf("Test %d.1: FAIL! abs_sum(%lf, %lf) = %lf, expected %lf\n",
        test_num, a, b, value, exp_sum);
    }

    value = abs_sub(a, b);
    if (fabs(value - exp_sub) < eps) {
      printf("Test %d.2: PASS\n", test_num);
    }
    else {
      printf("Test %d.2: FAIL! abs_sub(%lf, %lf) = %lf, expected %lf\n",
        test_num, a, b, value, exp_sub);
    }

    value = abs_expr(a, b);
    if (fabs(value - exp_expr) < eps) {
      printf("Test %d.3: PASS\n", test_num);
    }
    else {
      printf("Test %d.3: FAIL! abs_expr(%lf, %lf) = %lf, expected %lf\n",
        test_num, a, b, value, exp_expr);
    }
  }

  void all_tests()
  {
    test(1.0, -1.0, 2.0, 0.0, 2.0, 1e-10, 1);
    test(-1.0, 1.0, 2.0, 0.0, 2.0, 1e-10, 2);
    test(2.0, -1.0, 3.0, 1.0, 2.0, 1e-10, 3);
  }
}


namespace task_1_1_14
{
  /*
  Задача 1-1-14.
  Замените содержимое a на значение a + b, содержимое b на значение a − b без использования дополнительных переменных.
  */

  void swap(int& a, int& b)
  {
    a = a + b;
    b = a - b - b;
  }

  void test(int a, int b, int exp_sum, int exp_sub, int test_num)
  {
    int _a = a;
    int _b = b;
    swap(_a, _b);
    if (_a == exp_sum && _b == exp_sub) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! swap(%d, %d) = %d, %d, expected %d, %d\n",
        test_num, a, b, _a, _b, exp_sum, exp_sub);
    }
  }

  void all_tests()
  {
    test(1, 2, 3, -1, 1);
    test(-1, 2, 1, -3, 2);
    test(1, -2, -1, 3, 3);
    test(-1, -2, -3, 1, 4);
  }
}


namespace task_1_1_15
{
  /*
  Задача 1-1-15.
  Поменяйте содержимое a и b местами без использования дополнительных переменных.
  */

  void swap(int& a, int& b)
  {
    a = a + b;
    b = a - b;
    a = a - b;
  }

  void test(int a, int b, int exp_sum, int exp_sub, int test_num)
  {
    int _a = a;
    int _b = b;
    swap(_a, _b);
    if (_a == exp_sum && _b == exp_sub) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! swap(%d, %d) = %d, %d, expected %d, %d\n",
        test_num, a, b, _a, _b, exp_sum, exp_sub);
    }
  }

  void all_tests()
  {
    test(1, 2, 2, 1, 1);
    test(10, 20, 20, 10, 2);
    test(-1, -2, -2, -1, 3);
  }
}


namespace task_1_1_16
{
  /*
  Задача 1-1-16.
  Поменяйте содержимое a и b местами без использования дополнительных переменных.
  */

  int sum(int n)
  {
    int s = 0;
    for (int i = 0; i <= n; ++i)
      s += i;

    return s;
  }

  void test(int x, int test_num)
  {
    int value = sum(x);
    int exp = (x * (x + 1) / 2);
    if (value == exp) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! sum(%d) = %d, expected %d\n",
        test_num, x, value, exp);
    }
  }

  void all_tests()
  {
    test(1, 1);
    test(2, 2);
    test(3, 3);
    test(4, 4);
  }
}


namespace task_1_1_17
{
  /*
  Задача 1-1-17.
  Найдите величину n! = 1 · 2 · . . . · n.
  */

  unsigned long long fact(unsigned long long n)
  {
    unsigned long long s = 1;
    for (unsigned long long i = 1; i <= n; ++i)
      s *= i;

    return s;
  }

  void test(unsigned long long x, unsigned long long exp, int test_num)
  {
    unsigned long long value = fact(x);
    if (value == exp) {
      printf("Test %d: PASS\n", test_num);
    }
    else {
      printf("Test %d: FAIL! fact(%llu) = %llu, expected %llu\n",
        test_num, x, value, exp);
    }
  }

  void all_tests()
  {
    test(1, 1, 1);
    test(2, 2, 2);
    test(3, 6, 3);
    test(4, 24, 4);
  }
}


namespace task_1_1_21
{
  /*
  Задача 1-1-21.
  Реализуйте «калькулятор» для выполнения базовых действий с целыми числами
  */

  void print_menu()
  {
    printf(
      "For use enter operation code\n" \
      "  0) Print menu;\n" \
      "  1) a + b;\n" \
      "  2) a - b;\n" \
      "  3) a * b;\n" \
      "  4) a / b;\n" \
      "  5) a ^ b;\n" \
      "  6) a %% b;\n"
    );
  }

  bool read_values(int& a, int& b)
  {
    printf("Enter a and b by space: ");
    return (2 == scanf("%d%d", &a, &b));
  }

  void calculator()
  {
    bool f_work = true;
    int code = 0;

    print_menu();

    while (f_work)
    {
      printf("Enter code: ");
      scanf("%d", &code);

      if (code == 0) print_menu();
      else if (code <= 6)
      {
        int a = 0, b = 0;
        if (!read_values(a, b))
          printf("Read error!\n");
        else{
          switch (code)
          {
            case 1: printf("%d + %d = %d\n", a, b, a + b); break;
            case 2: printf("%d - %d = %d\n", a, b, a - b); break;
            case 3: printf("%d * %d = %d\n", a, b, a * b); break;
            case 4: printf("%d / %d = %d\n", a, b, a / b); break;
            case 5: printf("%d ^ %d = %d\n", a, b, static_cast<int>(pow(a, b))); break;
            case 6: printf("%d %% %d = %d\n", a, b, a % b); break;
            default: printf("Error!\n"); break;
          }
        }
      }
      else 
        break;
    }
  }
}


namespace task_1_1_22
{
  /*
  Задача 1-1-22.
  По заданным параметрам изображений ыведите на экран псевдографические картинки.
  */

  /// @brief Нарисовать прямоугольник
  /// @param a Количество строк
  /// @param b Количество столбцов
  void print_rect(unsigned a, unsigned b)
  {
    if (a > 20 || b > 20) 
      printf("Error params!");
    else
    {
      for (unsigned i = 0; i < a; ++i)
      {
        for (unsigned j = 0; j < b; ++j)
          printf("*");
        printf("\n");
      }
      printf("\n");
    }
  }

  /// @brief Нарисовать прямоугольный треугольник
  /// @param h Высота
  void print_top_triangle(unsigned h)
  {
    if (h > 20)
      printf("Error params!");
    else
    {
      for (unsigned i = 1; i <= h; ++i)
      {
        for (unsigned j = 0; j < i; ++j)
          printf("*");
        printf("\n");
      }
    printf("\n");
    }
  }

  /// @brief Нарисовать перевернутый прямоугольный треугольник
  /// @param h Высота треугольника
  void print_bottom_triangle(unsigned h)
  {
    if (h > 20)
      printf("Error params!");
    else
    {
      for (unsigned i = h; i > 0; --i)
      {
        for (unsigned k = 0; k < (h - i); k++)
          printf(" ");
        for (unsigned j = 0; j < i; ++j)
          printf("*");
        printf("\n");
      }
      printf("\n");
    }
  }

  void print_tree(unsigned b)
  {
    
  }

  void all_tests()
  {
    print_rect(5, 8);
    print_top_triangle(5);
    print_bottom_triangle(5);
  }
}


int main()
{
  task_1_1_22::all_tests();
  return 0;
}
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
      if (x < b) return 0;
      else return 1;
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
      printf("Test %d: FAIL! find_max(%lf, %lf, %lf) = %d, expected %d\n",
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
  int check_range()
}


int main()
{
  task_1_1_9::all_tests();
  return 0;
}
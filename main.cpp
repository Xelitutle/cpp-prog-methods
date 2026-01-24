#include <stdio.h>
#include <limits.h>


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
  
}

int main()
{
  task_1_1_4::all_tests();
  return 0;
}
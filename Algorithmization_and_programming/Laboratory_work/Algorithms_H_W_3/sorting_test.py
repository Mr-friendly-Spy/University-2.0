from unittest import TestCase, main
from Sorting_algorithms_t import *


class TestSorting(TestCase):
    def test_shell_sort(self):
        self.assertEqual(shell_sort([35, 33, 42, 10, 14, 19, 27, 44]), [10, 14, 19, 27, 33, 35, 42, 44])

    def test_bubble_sort(self):
        self.assertEqual(bubble_sort([35, 33, 42, 10, 14, 19, 27, 44]), [10, 14, 19, 27, 33, 35, 42, 44])

    def test_radix_sort(self):
        self.assertEqual(radix_sort([35, 33, 42, 10, 14, 19, 27, 44]), [10, 14, 19, 27, 33, 35, 42, 44])

    def test_gnom_sort(self):
        self.assertEqual(gnom_sort([35, 33, 42, 10, 14, 19, 27, 44]), [10, 14, 19, 27, 33, 35, 42, 44])

    def test_quick_sort(self):
        array = [35, 33, 42, 10, 14, 19, 27, 44, 55]
        self.assertEqual(quick_sort(0, len(array) - 1, array), [10, 14, 19, 27, 33, 35, 42, 44])

if __name__ == '__main__':
    main()











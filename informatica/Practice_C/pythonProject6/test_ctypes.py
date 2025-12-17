import ctypes
import os
import sys
import time

def test_dll_with_full_path():
    print("=== Тест функционала DLL===\n")

    # Определяем путь к DLL
    current_dir = os.path.dirname(os.path.abspath(__file__))

    try:
        # Загружаем DLL с полным путем
        print(f"\nЗагрузка DLL: { os.path.join(current_dir, "DLL2_Proj.dll")}")
        dll = ctypes.WinDLL( os.path.join(current_dir, "DLL2_Proj.dll"))
        print("✓ DLL успешно загружена!")

        # Пробуем простейшую функцию
        print("\nПоиск экспортируемых функций...")

        # Список возможных функций
        functions_to_try = [
            ("FindMaxInt", [ctypes.POINTER(ctypes.c_int), ctypes.c_int], ctypes.c_int),
            ("GetDLLInfo", [], ctypes.c_char_p),
        ]

        for func_name, argtypes, restype in functions_to_try:
            try:
                # Получаем указатель на функцию
                func_ptr = getattr(dll, func_name)

                # Настраиваем типы
                func_ptr.argtypes = argtypes
                func_ptr.restype = restype

                print(f"✓ Найдена функция: {func_name}")

                # Тестируем функцию
                if func_name in ["FindMaxInt", "find_max"]:
                    arr = [10 for x in range(90000000)]
                    c_arr = (ctypes.c_int * len(arr))(*arr)
                    result = func_ptr(c_arr, len(arr))
                    print(f"  Тест: максимум = {result}")

                elif func_name == "GetDLLInfo":
                    result = func_ptr()
                    print(f"  Информация: {result.decode('utf-8')}")

            except AttributeError:
                print(f"✗ Функция {func_name} не найдена")
            except Exception as e:
                print(f"✗ Ошибка в функции {func_name}: {e}")

        return True

    except Exception as e:
        print(f"\n✗ Ошибка загрузки DLL: {e}")
        print("\nВозможные причины:")
        print("1. Несовместимая архитектура (32-bit vs 64-bit)")
        print("2. Отсутствуют зависимости DLL")
        print("3. DLL повреждена")

        return False


if __name__ == "__main__":
    test_dll_with_full_path()

print("--------------------------------------------------------")

start_time = time.time()
arr = [10 for x in range(90000000)]
def find_max_basic(arr):
    """Находит максимальное значение в списке"""
    if not arr:  # Проверка на пустой список
        return None

    max_val = arr[0]
    for num in arr[1:]:
        if num > max_val:
            max_val = num

    return max_val


end_time = time.time()
print(f"Время в Python: {end_time - start_time} секунд")
/** @file
* @author Молодык С.А.
* @version 1.0
* @date 03.06.2019
* @copyright ИБСТ ПГУ
* @warning Это учебный пример
* @brief Заголовочный файл для модуля кодирования методом Хэмминга
*/
#pragma once
#include <string>
#include <cmath>
/**
 * @brief Кодирование методом Хэмминга
 * @details Код Хэмминга - самокорректирующийся код.Построен применительно к двоичной системе счисления.
 * Позволяет исправлять одиночную ошибку (ошибка в одном бите) и находить двойную.
 * Полином устанавливается в конструкторе.
 * Для кодирования и декодирования используются методы encode и decode.
 * @warning Реализован только для полиномов (7,4), (15,11), (31,26).
 */
class coder
{
private:
    int polynomal1;///< Максимальная разрядность числа в коде Хэмминга
    int polynomal2;///< Максимальная разрядность кодируемого числа
public:
    coder()=delete;///< Конструктор без параметров автоматически удаляет переменную
    /**
    * @brief Конструктор.
    * @param [in] input_polynomal1, input_polynomal2 -  значения полинома. Допустимые значения - 7 и 4, 15 и 11, 31 и 26.
    * @throw string, если введен недопустимый полином.
    */
    coder(int input_polynomal1, int input_polynomal2);
    /**
    * @brief Метод для кодирования.
    * @param [in] num_s число для кодирования.
    * @return Число в коде Хэмминга
    * @throw string, если число отрицательное, или его разрядность больше соответствующего значения полинома.
    */
    int encode(int num_s);
    /**
    * @brief Метод для декодирования.
    * @details Метод encode может найти и исправить ошибку в закодированном числе, если она одна.
    *  Метод encode может найти ошибку в закодированном числе и предпринять попытку ее исправления, если их две.
    * @param [in] num_s число для декодирования.
    * @return Исходное число
    * @throw string, если число отрицательное, или его разрядность больше соответствующего значения полинома.
    */
    int decode(int num_s);
};

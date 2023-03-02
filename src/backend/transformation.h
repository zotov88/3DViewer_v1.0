#ifndef SRC_BACKEND_TRANSFORMATION_H_
#define SRC_BACKEND_TRANSFORMATION_H_

#define M_PI 3.14159265358979323846

#include <math.h>

#include "parcer.h"

#define RANGE 0.5

/**
 * @brief Функция, предназначенная для поворота модели по оси X
 * @param data указатель на структуру
 * @param shift величина сдвига
 */
void move_x(MainStruct *data, double shift);

/**
 * @brief Функция, предназначенная для поворота модели по оси Y
 * @param data указатель на структуру
 * @param shift величина сдвига
 */
void move_y(MainStruct *data, double shift);

/**
 * @brief Функция, предназначенная для поворота модели по оси Z
 * @param data указатель на структуру
 * @param shift величина сдвига
 */
void move_z(MainStruct *data, double shift);

/**
 * @brief Функция, предназначенная для поворота модели по любым осям
 * @details Функция нужна, чтобы не дублировать код
 * @param data указатель на структуру
 * @param shift величина сдвига
 * @param coordinate 1 - X, 2 - Y, 3 - Z
 */
void move(MainStruct *data, double shift, int coordinate);

/**
 * @brief Функция, предназначенная для поворота модели по всем осям
 * @param data указатель на структуру
 * @param shift_x величина сдвига по оси X
 * @param shift_y величина сдвига по оси Y
 * @param shift_z величина сдвига по оси Z
 */
void moving(MainStruct *data, double shift_x, double shift_y, double shift_z);

/**
 * @brief Функция, предназначенная для вращения модели по оси X
 * @param data указатель на структуру
 * @param angle угол вращения
 */
void rotate_x(MainStruct *data, double angle);

/**
 * @brief Функция, предназначенная для вращения модели по оси Y
 * @param data указатель на структуру
 * @param angle угол вращения
 */
void rotate_y(MainStruct *data, double angle);

/**
 * @brief Функция, предназначенная для вращения модели по оси Z
 * @param data указатель на структуру
 * @param angle угол вращения
 */
void rotate_z(MainStruct *data, double angle);

/**
 * @brief Функция, предназначенная для определения величины смещения модели к
 * центру графика
 * @param min минимальное значение по оси
 * @param max максимальное значение по оси
 * @return  величина смещения к центру
 */
double offset(double min, double max);

/**
 * @brief Функция, предназначенная для смещения модели к центру графика
 * @param data указатель на структуру
 */
void offset_to_center(MainStruct *data);

/**
 * @brief Функция, предназначенная для определения максимального значения из
 * всех минимальных и максимальных
 * @details Значение получается путем сравнения трех разностей между
 * максимальными и минимальными величинами точек по всем трем осям
 * @param data указатель на структуру
 * @return максимальное значение из полученных разностей
 */
double max_amoung_minmax(MainStruct *data);

/**
 * @brief Функция, предназначенная для определения величины коэффициента
 * масштабирования
 * @param range диапазон для масштабирования
 * @param max максимальное значение по оси
 * @return максимальное значение из разностей максимальных и минимальных величин
 * точек по осям
 */
double get_scale(double range, double max);

/**
 * @brief Функция, предназначенная для масштабирования модели
 * @param data указатель на структуру
 * @param scale коэффициент масштабирования
 */
void scale_model(MainStruct *data, double scale);

/**
 * @brief Функция, предназначенная для перевода градусов в радианты
 * @param angle величина угла
 * @return радианты
 */
double to_radians(double angle);

#endif  // SRC_BACKEND_TRANSFORMATION_H_

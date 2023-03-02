#ifndef SRC_BACKEND_PARCER_H_
#define SRC_BACKEND_PARCER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 512
enum { OK, ERROR };

/**
 * @brief Главная структура, объединяющая в себе все координаты и полигоны
 * @param vertex указатель на структуру вершин
 * @param polygon указатель на структуру полигонов
 *
 */
typedef struct MainStruct {
  struct Vertex *vertex;
  struct Polygon *polygon;
} MainStruct;

/**
 * @brief Структура, хранящая указатель на структуру координат и минимальные с
 * максимальными значениями по осям X, Y, Z
 * @param coordinate указатель на структуру координат
 * @param X_minmax массив, содержащий min и max значения точек по X
 * @param Y_minmax массив, содержащий min и max значения точек по Y
 * @param Z_minmax массив, содержащий min и max значения точек по Z
 * @param count_coordinates всего координат
 */
typedef struct Vertex {
  struct Coordinate *coordinate;
  double X_minmax[2];
  double Y_minmax[2];
  double Z_minmax[2];
  int count_coordinates;
} Vertex;

/**
 * @brief Структура, хранящая одну координату
 * @param coordinate указатель на структуру координат
 * @param x значение по оси X
 * @param y значение по оси Y
 * @param z значение по оси Z
 */
typedef struct Coordinate {
  double x;
  double y;
  double z;
} Coordinate;

/**
 * @brief Структура, хранящая указатель на последовательность полигонов
 * @param sequence указатель на последовательность полигонов
 * @param count_sequences всего полигонов
 */
typedef struct Polygon {
  struct Sequence *sequence;
  int count_sequences;
} Polygon;

/**
 * @brief Структура для одного полигона
 * @param points указатель на структуру, в которой хранятся индексы вершин
 * полигона
 */
typedef struct Sequence {
  struct Queue *points;
} Sequence;

/**
 * @brief Структура типа "очередь" для хранения списка вершин отдельного
 * полигона
 * @param val значение индекса координаты
 * @param next указатель на следующий узел структуры
 */
typedef struct Queue {
  int val;
  struct Queue *next;
} Queue;

/**
 * @brief Связующая функция, внутри которой происходит вся работа функций
 * @param path путь к файлу
 * @return указатель стурктуру
 */
MainStruct *main_function(char *path);

/**
 * @brief Функция, определяющая количество строк в файле для определения объема
 * выделяемой памяти
 * @param path путь к файлу
 * @return количество строк в файле
 */
int get_count_lines(char *path);

/**
 * @brief Функция, в которой выделяется память под структуру для конкретного
 * объектного файла выделяемой памяти
 * @param size объем выделяемой памяти
 * @return статус чтения файла
 */
MainStruct *init(int size);

/**
 * @brief Парсер объектного файла
 * @param data указатель на главную структуру
 * @param path путь к файлу
 */
void parcer(MainStruct *data, char *path);

/**
 * @brief Построчная обработка координат в файле
 * @details происходит заполнение структуры Vertex
 * @param data указатель на главную структуру
 * @param line строка из файла
 */
void push_V(MainStruct *data, char *line);

/**
 * @brief Построчная обработка полигонов в файле
 * @details происходит заполнение структуры Polygon
 * @param data указатель на главную структуру
 * @param line путь к файлу
 */
void push_F(MainStruct *data, char *line);

/**
 * @brief Функция, возвращающая указатели в их начало
 * @details Возвращаются в начало указатели на структуры Coordinate и Sequence.
 * @param data указатель на главную структуру
 */
void ptrs_to_start(MainStruct *data);

/**
 * @brief Функция очистки главной структуры
 * @param data указатель на главную структуру
 */
void destroy_main_struct(MainStruct *data);

/**
 * @brief Функция, помещающая в очередь новое значение
 * @param head указатель на начало очереди
 * @param val целочисленное значение
 * @return указатель на начало очереди
 */
Queue *push(Queue *head, int val);

/**
 * @brief Функция, получения значения из очереди
 * @details Значение берется из начала очереди, голова перемещается на следующий
 * узел, а предыдущий элемент очищается
 * @param head указатель на начало очереди
 * @return значение из начала очереди
 */
int pop(Queue **head);  // Вернет -1 в конце, т.к. отрицательного индекса нет

/**
 * @brief Функция очистки структуры
 * @param head указатель на начало очереди
 */
void destroy_queue(Queue *head);

#endif  // SRC_BACKEND_PARCER_H_

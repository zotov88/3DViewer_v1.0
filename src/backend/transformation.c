#include "transformation.h"

void move_x(MainStruct *data, double shift) { move(data, shift, 1); }

void move_y(MainStruct *data, double shift) { move(data, shift, 2); }

void move_z(MainStruct *data, double shift) { move(data, shift, 3); }

void move(MainStruct *data, double shift, int coordinate) {
  int count = 0;
  while (count < data->vertex->count_coordinates) {
    switch (coordinate) {
      case 1:
        data->vertex->coordinate->x += shift;
        break;
      case 2:
        data->vertex->coordinate->y += shift;
        break;
      case 3:
        data->vertex->coordinate->z += shift;
        break;
    }
    count++;
    data->vertex->coordinate++;
  }
  data->vertex->coordinate -= data->vertex->count_coordinates;
}

void moving(MainStruct *data, double shift_x, double shift_y, double shift_z) {
  move_x(data, shift_x);
  move_y(data, shift_y);
  move_z(data, shift_z);
}

void rotate_x(MainStruct *data, double angle) {
  angle = to_radians(angle);
  int count = 0;
  while (count < data->vertex->count_coordinates) {
    double y = data->vertex->coordinate->y;
    double z = data->vertex->coordinate->z;
    data->vertex->coordinate->y = y * cos(angle) - z * sin(angle);
    data->vertex->coordinate->z = y * sin(angle) + z * cos(angle);
    count++;
    data->vertex->coordinate++;
  }
  data->vertex->coordinate -= data->vertex->count_coordinates;
}

void rotate_y(MainStruct *data, double angle) {
  angle = to_radians(angle);
  int count = 0;
  while (count < data->vertex->count_coordinates) {
    double x = data->vertex->coordinate->x;
    double z = data->vertex->coordinate->z;
    data->vertex->coordinate->x = x * cos(angle) + z * sin(angle);
    data->vertex->coordinate->z = -x * sin(angle) + z * cos(angle);
    count++;
    data->vertex->coordinate++;
  }
  data->vertex->coordinate -= data->vertex->count_coordinates;
}

void rotate_z(MainStruct *data, double angle) {
  angle = to_radians(angle);
  int count = 0;
  while (count < data->vertex->count_coordinates) {
    double x = data->vertex->coordinate->x;
    double y = data->vertex->coordinate->y;
    data->vertex->coordinate->x = x * cos(angle) - y * sin(angle);
    data->vertex->coordinate->y = x * sin(angle) + y * cos(angle);
    count++;
    data->vertex->coordinate++;
  }
  data->vertex->coordinate -= data->vertex->count_coordinates;
}

double offset(double min, double max) { return min + (max - min) / 2; }

void offset_to_center(MainStruct *data) {
  int count = 0;
  while (count < data->vertex->count_coordinates) {
    data->vertex->coordinate->x -=
        offset(data->vertex->X_minmax[0], data->vertex->X_minmax[1]);
    data->vertex->coordinate->y -=
        offset(data->vertex->Y_minmax[0], data->vertex->Y_minmax[1]);
    data->vertex->coordinate->z -=
        offset(data->vertex->Z_minmax[0], data->vertex->Z_minmax[1]);
    count++;
    data->vertex->coordinate++;
  }
  data->vertex->coordinate -= data->vertex->count_coordinates;
}

double max_amoung_minmax(MainStruct *data) {
  double x = data->vertex->X_minmax[1] - data->vertex->X_minmax[0];
  double y = data->vertex->Y_minmax[1] - data->vertex->Y_minmax[0];
  double z = data->vertex->Z_minmax[1] - data->vertex->Z_minmax[0];
  return (x > y && x > z) ? x : ((y > z) ? y : z);
}

double get_scale(double range, double max) {
  return (range - range * (-1)) / max;
}

void scale_model(MainStruct *data, double scale) {
  int count = 0;
  while (count < data->vertex->count_coordinates) {
    data->vertex->coordinate->x *= scale;
    data->vertex->coordinate->y *= scale;
    data->vertex->coordinate->z *= scale;
    count++;
    data->vertex->coordinate++;
  }
  data->vertex->coordinate -= data->vertex->count_coordinates;
}

double to_radians(double angle) { return angle * M_PI / 180; }

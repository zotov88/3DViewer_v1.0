#include "parcer.h"

#include "transformation.h"

MainStruct* main_function(char* path) {
  MainStruct* data = NULL;
  int size = get_count_lines(path);
  if (size > 0) {
    data = init(size);
    parcer(data, path);
    ptrs_to_start(data);
    offset_to_center(data);
    scale_model(data, get_scale(RANGE, max_amoung_minmax(data)));
  }
  return data;
}

void destroy_main_struct(MainStruct* data) {
  int count = 0;
  while (count < data->polygon->count_sequences) {
    destroy_queue(data->polygon->sequence->points);
    data->polygon->sequence++;
    count++;
  }
  free(data->polygon->sequence -= data->polygon->count_sequences);
  free(data->vertex->coordinate);
  free(data->polygon);
  free(data->vertex);
  free(data);
}

int get_count_lines(char* path) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    return ERROR;
  }
  int count = 0;
  char line[LENGTH];
  while (fgets(line, LENGTH, file) != NULL) {
    count++;
  }
  fclose(file);
  return count;
}

MainStruct* init(int size) {
  MainStruct* data = calloc(1, sizeof(MainStruct));
  data->vertex = calloc(1, sizeof(Vertex));
  data->polygon = calloc(1, sizeof(Polygon));
  data->vertex->coordinate = calloc(size, sizeof(Coordinate));
  data->polygon->sequence = calloc(size, sizeof(Sequence));
  return data;
}

void parcer(MainStruct* data, char* path) {
  FILE* file = fopen(path, "r");
  char line[LENGTH];
  while (fgets(line, LENGTH, file) != NULL) {
    char c = line[0];
    if (c == 'v') {
      push_V(data, line);
    }
    if (c == 'f') {
      push_F(data, line);
    }
  }
  fclose(file);
}

void push_V(MainStruct* data, char* line) {
  double point1, point2, point3;
  char first;
  if (sscanf(line, "%c%lf%lf%lf", &first, &point1, &point2, &point3) == 4) {
    data->vertex->coordinate->x = point1;
    data->vertex->coordinate->y = point2;
    data->vertex->coordinate->z = point3;
    data->vertex->count_coordinates++;
    data->vertex->coordinate++;
    if (point1 < data->vertex->X_minmax[0]) data->vertex->X_minmax[0] = point1;
    if (point1 > data->vertex->X_minmax[1]) data->vertex->X_minmax[1] = point1;
    if (point2 < data->vertex->Y_minmax[0]) data->vertex->Y_minmax[0] = point2;
    if (point2 > data->vertex->Y_minmax[1]) data->vertex->Y_minmax[1] = point2;
    if (point3 < data->vertex->Z_minmax[0]) data->vertex->Z_minmax[0] = point3;
    if (point3 > data->vertex->Z_minmax[1]) data->vertex->Z_minmax[1] = point3;
  }
}

void push_F(MainStruct* data, char* line) {
  int tmp;
  char* pos = line;
  while (strchr(pos, ' ')) {
    pos = strchr(pos, ' ') + 1;
    if (sscanf(pos, "%d", &tmp) == 1) {
      data->polygon->sequence->points =
          push(data->polygon->sequence->points, tmp);
    }
  }
  data->polygon->count_sequences++;
  data->polygon->sequence++;
}

void ptrs_to_start(MainStruct* data) {
  data->vertex->coordinate -= data->vertex->count_coordinates;
  data->polygon->sequence -= data->polygon->count_sequences;
}

Queue* push(Queue* head, int val) {
  Queue* current = NULL;
  if (head == NULL) {
    head = calloc(1, sizeof(Queue));
    head->val = val;
    head->next = NULL;
  } else {
    current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = calloc(1, sizeof(Queue));
    current->next->val = val;
    current->next->next = NULL;
  }
  return head;
}

int pop(Queue** head) {
  Queue* ptr = NULL;
  int num = -1;
  if (*head != NULL) {
    ptr = *head;
    num = ptr->val;
    *head = ptr->next;
    free(ptr);
  }
  return num;
}

void destroy_queue(Queue* head) {
  Queue* tmp = NULL;
  while (head != NULL) {
    tmp = head->next;
    free(head);
    head = tmp;
  }
}

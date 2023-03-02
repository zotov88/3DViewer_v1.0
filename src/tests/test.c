#include <check.h>

#include "../backend/parcer.h"
#include "../backend/transformation.h"

START_TEST(test_1) {
#line 5
  char* path = "objs/cube.obj";
  MainStruct* data = main_function(path);
  ck_assert_int_eq(8, data->vertex->count_coordinates);
  ck_assert_int_eq(12, data->polygon->count_sequences);
  destroy_main_struct(data);
}
END_TEST

START_TEST(test_2) {
#line 12
  char* path = "objs/cube.obj";
  MainStruct* data = main_function(path);
  ck_assert_int_eq(1, pop(&data->polygon->sequence->points));
  ck_assert_int_eq(2, pop(&data->polygon->sequence->points));
  ck_assert_int_eq(3, pop(&data->polygon->sequence->points));
  destroy_main_struct(data);
}
END_TEST

START_TEST(test_3) {
#line 20
  char* path = "objs/circle.obj";
  MainStruct* data = main_function(path);
  data->vertex->coordinate += 10;
  ck_assert_double_eq_tol(data->vertex->coordinate->x, 0.157700, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->y, 0.140740, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->z, -0.453182, 1e-6);
  data->vertex->coordinate -= 10;
  destroy_main_struct(data);
}
END_TEST

START_TEST(test_4) {
#line 30
  char* path = "objs/cube.obj";
  MainStruct* data = main_function(path);
  moving(data, -0.2, -0.2, 0);
  rotate_x(data, 33);
  rotate_y(data, 33);
  ck_assert_double_eq_tol(data->vertex->coordinate->x, -0.566325, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->y, -0.859389, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->z, 0.413191, 1e-6);
  destroy_main_struct(data);
}
END_TEST

START_TEST(test_5) {
#line 41
  char* path = "objs/cube.obj";
  MainStruct* data = main_function(path);
  moving(data, 0.212, 0.212, -0.11);
  rotate_x(data, 111);
  rotate_y(data, 222);
  rotate_z(data, 333);
  data->vertex->coordinate += 7;
  ck_assert_double_eq_tol(data->vertex->coordinate->x, -0.136083, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->y, 0.824320, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->z, 0.513776, 1e-6);
  data->vertex->coordinate -= 7;
  destroy_main_struct(data);
}
END_TEST

START_TEST(test_6) {
#line 55
  char* path = "objs/circle.obj";
  MainStruct* data = main_function(path);
  data->vertex->coordinate += 19;
  scale_model(data, get_scale(123, max_amoung_minmax(data)));
  ck_assert_double_eq_tol(data->vertex->coordinate->x, 0.228642, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->y, 19.988971, 1e-6);
  ck_assert_double_eq_tol(data->vertex->coordinate->z, -29.012507, 1e-6);
  data->vertex->coordinate -= 19;
  destroy_main_struct(data);
}
END_TEST

START_TEST(test_7) {
#line 66
  char* path = "objs/circle.obj";
  MainStruct* data = main_function(path);
  data->vertex->coordinate += 19;
  scale_model(data, get_scale(123, max_amoung_minmax(data)));
  ck_assert_double_eq_tol(data->vertex->X_minmax[0], -1.742230, 1e-6);
  ck_assert_double_eq_tol(data->vertex->X_minmax[1], 1.742230, 1e-6);
  ck_assert_double_eq_tol(data->vertex->Y_minmax[0], -1.739946, 1e-6);
  ck_assert_double_eq_tol(data->vertex->Y_minmax[1], 1.739946, 1e-6);
  ck_assert_double_eq_tol(data->vertex->Z_minmax[0], -1.745721, 1e-6);
  ck_assert_double_eq_tol(data->vertex->Z_minmax[1], 1.745721, 1e-6);
  data->vertex->coordinate -= 19;
  destroy_main_struct(data);
}
END_TEST

int main(void) {
  Suite* s1 = suite_create("Core");
  TCase* tc1_1 = tcase_create("Core");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

/*
** mrb_stringscanner.c - StringScanner class
**
** Copyright (c) OKURA Masafumi 2023
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_stringscanner.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  mrb_int len;
} mrb_stringscanner_data;

static const struct mrb_data_type mrb_stringscanner_data_type = {
  "mrb_stringscanner_data", mrb_free,
};

static mrb_value mrb_stringscanner_init(mrb_state *mrb, mrb_value self)
{
  mrb_stringscanner_data *data;
  char *str;
  mrb_int len;

  data = (mrb_stringscanner_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_stringscanner_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_stringscanner_data *)mrb_malloc(mrb, sizeof(mrb_stringscanner_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_stringscanner_hello(mrb_state *mrb, mrb_value self)
{
  mrb_stringscanner_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_stringscanner_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_strscan_gem_init(mrb_state *mrb)
{
  struct RClass *stringscanner;
  stringscanner = mrb_define_class(mrb, "StringScanner", mrb->object_class);
  mrb_define_method(mrb, stringscanner, "initialize", mrb_stringscanner_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, stringscanner, "hello", mrb_stringscanner_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, stringscanner, "hi", mrb_stringscanner_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_strscan_gem_final(mrb_state *mrb)
{
}


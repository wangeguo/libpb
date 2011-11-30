/* Automatically generated libpb header */
#ifndef _PB_UNITTESTPROTO_PB_H_
#define _PB_UNITTESTPROTO_PB_H_
#include <pb/pb.h>

/* Enum definitions */
/* Struct definitions */
typedef struct {
    pb_callback_t data;
} CallbackArray;

typedef struct {
    size_t data_count;
    float data[10];
} FloatArray;

typedef struct {
    size_t data_count;
    int32_t data[10];
} IntegerArray;

typedef struct {
    CallbackArray submsg;
} CallbackContainer;

typedef struct {
    IntegerArray submsg;
} IntegerContainer;

typedef struct {
    CallbackContainer submsg;
} CallbackContainerContainer;

/* Default values for struct fields */

/* Struct field encoding specification for nanopb */
extern const pb_field_t IntegerArray_fields[2];
extern const pb_field_t FloatArray_fields[2];
extern const pb_field_t CallbackArray_fields[2];
extern const pb_field_t IntegerContainer_fields[2];
extern const pb_field_t CallbackContainer_fields[2];
extern const pb_field_t CallbackContainerContainer_fields[2];

#endif

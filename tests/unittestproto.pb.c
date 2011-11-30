/* Automatically generated nanopb constant definitions */
#include "unittestproto.pb.h"



const pb_field_t IntegerArray_fields[2] = {
    {1, PB_HTYPE_ARRAY | PB_LTYPE_VARINT,
    offsetof(IntegerArray, data),
    pb_delta(IntegerArray, data_count, data),
    pb_membersize(IntegerArray, data[0]),
    pb_membersize(IntegerArray, data) / pb_membersize(IntegerArray, data[0]), 0},

    PB_LAST_FIELD
};

const pb_field_t FloatArray_fields[2] = {
    {1, PB_HTYPE_ARRAY | PB_LTYPE_FIXED32,
    offsetof(FloatArray, data),
    pb_delta(FloatArray, data_count, data),
    pb_membersize(FloatArray, data[0]),
    pb_membersize(FloatArray, data) / pb_membersize(FloatArray, data[0]), 0},

    PB_LAST_FIELD
};

const pb_field_t CallbackArray_fields[2] = {
    {1, PB_HTYPE_CALLBACK | PB_LTYPE_VARINT,
    offsetof(CallbackArray, data), 0,
    pb_membersize(CallbackArray, data), 0, 0},

    PB_LAST_FIELD
};

const pb_field_t IntegerContainer_fields[2] = {
    {1, PB_HTYPE_REQUIRED | PB_LTYPE_SUBMESSAGE,
    offsetof(IntegerContainer, submsg), 0,
    pb_membersize(IntegerContainer, submsg), 0,
    &IntegerArray_fields},

    PB_LAST_FIELD
};

const pb_field_t CallbackContainer_fields[2] = {
    {1, PB_HTYPE_REQUIRED | PB_LTYPE_SUBMESSAGE,
    offsetof(CallbackContainer, submsg), 0,
    pb_membersize(CallbackContainer, submsg), 0,
    &CallbackArray_fields},

    PB_LAST_FIELD
};

const pb_field_t CallbackContainerContainer_fields[2] = {
    {1, PB_HTYPE_REQUIRED | PB_LTYPE_SUBMESSAGE,
    offsetof(CallbackContainerContainer, submsg), 0,
    pb_membersize(CallbackContainerContainer, submsg), 0,
    &CallbackContainer_fields},

    PB_LAST_FIELD
};


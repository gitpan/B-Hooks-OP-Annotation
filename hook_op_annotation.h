#ifndef __HOOK_OP_ANNOTATION_H__
#define __HOOK_OP_ANNOTATION_H__

#include "perl.h"

START_EXTERN_C

typedef struct OPAnnotationGroup *OPAnnotationGroup;
typedef  OP *(*OPAnnotationPPAddr)(pTHX);
typedef void (*OPAnnotationDtor)(pTHX_ void *data);

typedef struct {
    void *data;
    OPAnnotationPPAddr ppaddr;
} OPAnnotation;

OPAnnotationGroup op_annotation_group_new(OPAnnotationDtor dtor);
OPAnnotation * op_annotation_new(OPAnnotationGroup group, OPAnnotationPPAddr ppaddr, void *data);
void op_annotation_group_free(OPAnnotationGroup group);
void op_annotation_free(OPAnnotation *annotation);

END_EXTERN_C

#endif

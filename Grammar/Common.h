#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifndef __COMMON_H__
#define __COMMON_H__

typedef enum Type
{
	id,
	op_add,
	op_mul,
	open,
	close,

	expr
} Type;


typedef struct SyntaxTree SyntaxTree;
struct SyntaxTree{
	Type type;
	char* text;

	int children_num;
	SyntaxTree** children;
};

void SyntaxTree_print(SyntaxTree* st, int depth);

#endif // ifndef __COMMON_H__
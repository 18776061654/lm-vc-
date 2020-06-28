
#include "stdafx.h"
#include"win32.h"
char* pchar()
{
	return "从动态链接库取得的字符串";
}

int F1::GetA(){
	return a + 1;
}
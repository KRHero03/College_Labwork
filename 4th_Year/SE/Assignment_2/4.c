#include <stdio.h>

struct TempStruct
{
	int x, y, z;
};

int main()
{
	/*@ unused @*/ struct TempStruct t1 = {.y = 0, .z = 1};
	return 0;
}
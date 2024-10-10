#include "array_operations.hh"

int greatest_v1(int* itemptr, int size)
{
int* ptr = itemptr;
int result = *itemptr;

for (int i = 1; i < size; i++)
{
    if (*(ptr+i) > result)
    {
        result = *(ptr+i);
    }
i++;
}
return result;
}


int greatest_v2(int* itemptr, int* endptr)
{
int* ptr = itemptr;
int* target = endptr;
int result = 0;
while (ptr < target) {
    if (*ptr > result)
    {
        result = *ptr;
    }
++ptr;
}
return result;
}

void copy(int* itemptr, int* endptr, int* targetptr)
{
while(itemptr < endptr)
{
    *targetptr = *itemptr;
    itemptr++;
    targetptr++;
}
}

void reverse(int* leftptr, int* rightptr)
{
int* pointer1 = leftptr;
int* pointer2 = rightptr-1;
while (pointer1 < pointer2) {
        swap(pointer1, pointer2);
        pointer1++;
        pointer2--;
}
}
 void swap(int* a, int* b)
 {
     int temp = *a;
        *a = *b;
        *b = temp;
 }

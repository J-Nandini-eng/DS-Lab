//Quadratic Probing//
#include <stdio.h>
#define SIZE 10
#define EMPTY -1
int c1 = 1;
int c2 = 3;
int hash(int key)
{
return key % SIZE;
}
void insertQuadratic(int table[], int key)
{
int index = hash(key);
int probe = 0;
while (probe < SIZE)
{
int newIndex = (index + c1 * probe + c2 * probe * probe) % SIZE;
if (table[newIndex] == EMPTY)
{
table[newIndex] = key;
return;
}
probe++;

}
printf("Table Overflow! Could not insert %d\n", key);
}
int main()
{
int table[SIZE];
int i;
for (i = 0; i < SIZE; i++)
{
table[i] = EMPTY;
}
int keys[] = {72, 27, 36, 24, 63, 81, 101};
int n = 8;
printf("Inserting using Quadratic Probing...\n");
for (i = 0; i < n; i++)
{
insertQuadratic(table, keys[i]);
}
printf("\nHash Table:\n");
for (i = 0; i < SIZE; i++)
{
printf("Index %d ? %d\n", i, table[i]);
}
return 0;
}

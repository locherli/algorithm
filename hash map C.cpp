#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

typedef struct Entry
{
	char key[50];
	int value;
	struct Entry* next;
}Entry;

typedef struct
{
	Entry* entries[SIZE];
}HashMap;

int hash(const char* str)
{
	return *str % SIZE;
}

HashMap* hash_initialize()
{
	HashMap* newMap = new HashMap;
	for (int i = 0; i < SIZE; i++)
		newMap->entries[i] = nullptr;
	return newMap;
}

void hash_insert(HashMap& hashmap, const char* key, int value)
{
	//create a new entry
	Entry* newEntry = new Entry;
	strcpy_s(newEntry->key, key);
	newEntry->next = nullptr;
	newEntry->value = value;

	int index = ::hash(key);
	if (hashmap.entries[index] == nullptr)
		hashmap.entries[index] = newEntry;
	else
	{
		Entry* current = hashmap.entries[index];
		while (current->next != nullptr)
			current = current->next;
		current->next = newEntry;
	}

}



int main()
{
	HashMap* map_user = hash_initialize();


	hash_insert(*map_user, "mike", 12345);
	hash_insert(*map_user, "mike", 12333);
	hash_insert(*map_user, "mike", 12444);
	hash_insert(*map_user, "mike", 12777);


	return 0;
}
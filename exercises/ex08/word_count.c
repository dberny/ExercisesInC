#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <gmodule.h>
#define MAXLENGTH 50

int main() {
	printf("start\n");
	gchar *filename = "ArtOfWar.txt";
	FILE *file = g_fopen(filename, "r");
	printf("open\n");
	if (file == NULL) {
		printf("%s not found\n", filename);
		exit(-1);
	}

	char str[MAXLENGTH];
	// guint hashFunc = g_string_hash;
	GHashTable *hashTable = g_hash_table_new(g_str_hash, g_str_equal);
	while (fgets(str, MAXLENGTH, file) != NULL) {
		// int val = g_hash_table_lookup(hashTable, str);
		if (g_hash_table_lookup(hashTable, str) == NULL) {
			guint one = 1;
			g_hash_table_insert(hashTable, g_strdup(str), &one);
		}
		else {
			gpointer val = g_hash_table_lookup(hashTable, str);
			int newVal = *(int *)val +1;
			g_hash_table_replace(hashTable, str, &newVal);
		}
	}


	GHashTableIter iter;
	gpointer key, value;

	g_hash_table_iter_init (&iter, hashTable);
	while (g_hash_table_iter_next (&iter, &key, &value)) {
	    	// do something with key and value
			printf("key: %s, val: %i\n", (char *)key, *(int *)value);
	}
	return 0;
}

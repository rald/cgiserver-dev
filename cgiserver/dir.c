#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

bool is_hidden (const char *name) {
  return (name[0] == '.');
}

int main () {
  DIR *dir;
  struct dirent *entry;
  struct stat fileStat;
  char path[1024];

  // Replace "your_directory_path" with the actual path
  const char *dir_path = ".";

  dir = opendir (dir_path);

  if (dir == NULL) {
    perror ("Error opening directory");
    return 1;
  }

  while ((entry = readdir (dir)) != NULL) {
    // Skip "." and ".."
    if (  strcmp (entry->d_name, ".") == 0 ||
          strcmp (entry->d_name, "..") == 0) {
	    continue;
	  }

    // Check if the entry is hidden
    if (is_hidden (entry->d_name)) {
	    continue;
	  }

    // Construct the full path to the file/directory
    snprintf (path, sizeof (path), "%s/%s", dir_path, entry->d_name);

    // Get file attributes to check if it's a directory
    if (stat (path, &fileStat) == 0) {
	    if (S_ISDIR (fileStat.st_mode)) {
	      printf ("<%s>\n", entry->d_name);
	    } else {
	      printf ("%s\n", entry->d_name);
	    }
	  } else {
	    perror ("Error getting file stats");
	  }
  }

  closedir (dir);
  return 0;
}

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "cli.h"

//
// Read a line of text from the command line.  Handles backspaces
//
char *
readline(char *prompt)
{
	char *buf;
	int pos;
	char c;

	buf = (char *) malloc(BUFSIZE);
	if (buf == NULL)
		return NULL;

	memset(buf, 0, BUFSIZE);

	std::cout << prompt;
	for (pos = 0; pos < BUFSIZE - 1; pos++) {
		std::cin.get(c);
		if (c == '\n')
			break;
		buf[pos] = c;
	}
	return buf;
}

//
// Search a list of separator characters for a given char
//
static int
issep(char *sep, char ch)
{
	int i, len;

	if (sep == NULL)
		return 0;

	for (len = strlen(sep), i = 0; i < len; i++)
		if (ch == sep[i])
			return 1;
	return 0;
}

//
// Determine the next argument on the command line using a list of
//   separator characters to determine the split
//
void
nextarg(char *ln, int *pos, char *sep, char *arg)
{
	char *s;
	char ch;

	if (ln == NULL || pos == NULL || arg == NULL)
		return;

	s = arg;

	/* Skip whitespace */
	ch = ln[*pos];
	while (isspace(ch))
		ch = ln[++(*pos)];

	/* Fill in arg until a separator is reached */
	strcpy(s, "");
	while (ch != '\0' && !issep(sep, ch)) {
		*(s++) = ch;
		ch = ln[++(*pos)];
	};
	*s = '\0';
}

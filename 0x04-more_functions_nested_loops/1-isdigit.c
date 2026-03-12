cd ~/0x04-more_functions_nested_loops
cat > 1-isdigit.c << 'EOF'
#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
EOF
git add 1-isdigit.c
git commit -m "Fix Betty style in _isdigit"
git push -u origin master

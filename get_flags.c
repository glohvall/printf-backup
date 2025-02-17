#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
        /* - + 0 # ' ' */
        /* 1 2 4 8  16 */
        int j, curr_i;
        int flags = 0;
        const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

        for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
        {
                for (j = 0; FLAGS_CH[j] != '\0'; j++)
                        if (format[curr_i] == FLAGS_CH[j])
                        {
                                flags |= FLAGS_ARR[j];
                                break;
                        }

                if (FLAGS_CH[j] == 0)
                        break;
        }

        *i = curr_i - 1;

        return (flags);
}





get_precision.c


#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
        int curr_i = *i + 1;
        int precision = -1;

        if (format[curr_i] != '.')
                return (precision);

        precision = 0;

        for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
        {
                if (is_digit(format[curr_i]))
                {
                        precision *= 10;
                        precision += format[curr_i] - '0';
                }
                else if (format[curr_i] == '*')
                {
                        curr_i++;
                        precision = va_arg(list, int);
                        break;
                }
                else
                        break;
        }

       *i = curr_i - 1;

        return (precision);
}

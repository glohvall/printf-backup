void print_float(double val)
{
	int dec = 1000000;
	int i = (int)val;

	_print_int(i);
	val = (val - i) * dec;
	i = (int)val;
	_putchar('.');
	_print_int(i);
}

#include "str_utils.h"
#include <math.h>
#include <stdio.h>
#include <string.h>


void buf_reset(char *buf)
{
	buf[0] = 0;
}


void buf_append_int(char *buf, int d)
{
	buf += strlen(buf);
	sprintf(buf, "%d", d);
}


void buf_append_flt(char *buf, float f, uint8_t places)
{
	buf += strlen(buf);

	if (isnan(f)) {
		sprintf(buf, "NAN");
		return;
	}

	if (isinf(f)) {
		sprintf(buf, "INF");
		return;
	}

	if (isinf(f) && f < 0) {
		sprintf(buf, "-INF");
		return;
	}

	bool minus = 0;
	if (f < 0) {
		minus = 1;
		f = -f;
	}

	int ones = 0, dec = 0;

	ones = (int)f;
	f -= ones;

	if (minus) {
		buf[0] = '-';
		buf++;
	}

	switch (places) {
		case 0:
			sprintf(buf, "%d", ones);
			return;
		case 1:
			dec = (f * 10);
			sprintf(buf, "%d.%01d", ones, dec);
			return;
		case 2:
			dec = (f * 100);
			sprintf(buf, "%d.%02d", ones, dec);
			return;
		default:
		case 3:
			dec = (f * 1000);
			sprintf(buf, "%d.%03d", ones, dec);
			return;
	}
}


void buf_append_str(char *buf, const char *app)
{
	sprintf(buf + strlen(buf), "%s", app);
}

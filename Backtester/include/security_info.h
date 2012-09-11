#ifndef _SECURITY_INFO_H
#define _SECURITY_INFO_H

#include "date.h"
#include <string>

struct SecurityInfo {
	unsigned int 	id;
	Date			date;
	double			open;
	double 			close;
	double			high;
	double			low;
	unsigned int	volume;
};

#endif

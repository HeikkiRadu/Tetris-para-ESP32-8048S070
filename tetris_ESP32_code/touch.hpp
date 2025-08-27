#ifndef TOUCH_H
#define TOUCH_H

#define TOUCH_SDA       19
#define TOUCH_SCL       20
#define TOUCH_INT       NULL
#define TOUCH_RST       38
#define TOUCH_WIDTH     800
#define TOUCH_HEIGHT    480

#include <TAMC_GT911.h>
#include <Wire.h>

extern TAMC_GT911 tp;

void initTouch(void);


#endif

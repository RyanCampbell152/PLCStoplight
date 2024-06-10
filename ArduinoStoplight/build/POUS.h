#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM STOPLIGHT
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,REDEW)
  __DECLARE_LOCATED(BOOL,REDEW0)
  __DECLARE_LOCATED(BOOL,YELLEW)
  __DECLARE_LOCATED(UINT,GREENEWLIGHT)
  __DECLARE_LOCATED(BOOL,YELLNS)
  __DECLARE_LOCATED(BOOL,GREENNS)
  __DECLARE_LOCATED(UINT,REDNSLIGHT)
  __DECLARE_VAR(BOOL,REDNS)
  __DECLARE_VAR(BOOL,GREENEW)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_LOCATED(BOOL,CAREW1)
  __DECLARE_LOCATED(BOOL,CAREW2)
  TP TP0;
  TP TP1;
  TP TP2;
  TP TP3;
  TP TP4;
  TP TP5;
  TON TON0;
  TON TON1;
  __DECLARE_VAR(UINT,_TMP_SEL17_OUT)
  __DECLARE_VAR(UINT,_TMP_SEL4_OUT)
  F_TRIG F_TRIG1;
  F_TRIG F_TRIG2;
  R_TRIG R_TRIG1;
  F_TRIG F_TRIG3;
  F_TRIG F_TRIG4;

} STOPLIGHT;

void STOPLIGHT_init__(STOPLIGHT *data__, BOOL retain);
// Code part
void STOPLIGHT_body__(STOPLIGHT *data__);
#endif //__POUS_H

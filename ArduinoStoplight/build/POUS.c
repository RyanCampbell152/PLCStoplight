void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void STOPLIGHT_init__(STOPLIGHT *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__QX0_3,data__->REDEW,retain)
  __INIT_LOCATED_VALUE(data__->REDEW,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->REDEW0,retain)
  __INIT_LOCATED_VALUE(data__->REDEW0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->YELLEW,retain)
  __INIT_LOCATED_VALUE(data__->YELLEW,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(UINT,__QW2,data__->GREENEWLIGHT,retain)
  __INIT_LOCATED_VALUE(data__->GREENEWLIGHT,0)
  __INIT_LOCATED(BOOL,__QX0_1,data__->YELLNS,retain)
  __INIT_LOCATED_VALUE(data__->YELLNS,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->GREENNS,retain)
  __INIT_LOCATED_VALUE(data__->GREENNS,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(UINT,__QW0,data__->REDNSLIGHT,retain)
  __INIT_LOCATED_VALUE(data__->REDNSLIGHT,0)
  __INIT_VAR(data__->REDNS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREENEW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__IX0_0,data__->CAREW1,retain)
  __INIT_LOCATED_VALUE(data__->CAREW1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->CAREW2,retain)
  __INIT_LOCATED_VALUE(data__->CAREW2,__BOOL_LITERAL(FALSE))
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  TP_init__(&data__->TP2,retain);
  TP_init__(&data__->TP3,retain);
  TP_init__(&data__->TP4,retain);
  TP_init__(&data__->TP5,retain);
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  __INIT_VAR(data__->_TMP_SEL17_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SEL4_OUT,0,retain)
  F_TRIG_init__(&data__->F_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG3,retain);
  F_TRIG_init__(&data__->F_TRIG4,retain);
}

// Code part
void STOPLIGHT_body__(STOPLIGHT *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_SEL17_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->GREENEW,),
    (UINT)0,
    (UINT)60000));
  __SET_LOCATED(data__->,GREENEWLIGHT,,__GET_VAR(data__->_TMP_SEL17_OUT,));
  __SET_VAR(data__->,_TMP_SEL4_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->REDNS,),
    (UINT)0,
    (UINT)60000));
  __SET_LOCATED(data__->,REDNSLIGHT,,__GET_VAR(data__->_TMP_SEL4_OUT,));
  __SET_VAR(data__->TP0.,IN,,(__GET_LOCATED(data__->CAREW1,) || __GET_LOCATED(data__->CAREW2,)));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->TON0.,IN,,(((((!(__GET_LOCATED(data__->YELLNS,)) && !(__GET_LOCATED(data__->YELLEW,))) && !(__GET_VAR(data__->GREENEW,))) && __GET_LOCATED(data__->REDEW,)) && !(__GET_LOCATED(data__->CAREW2,))) && !(__GET_LOCATED(data__->CAREW1,))));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_LOCATED(data__->,GREENNS,,(__GET_VAR(data__->TON0.Q,) || __GET_VAR(data__->TP0.Q,)));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->START,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->F_TRIG1.Q,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_LOCATED(data__->,YELLNS,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_LOCATED(data__->YELLNS,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->F_TRIG2.Q,));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 12000, 0, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,REDNS,,(!(__GET_LOCATED(data__->GREENNS,)) && __GET_VAR(data__->TP2.Q,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->REDNS,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->TP3.,IN,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->TP3.,PT,,__time_to_timespec(1, 7000, 0, 0, 0, 0));
  TP_body__(&data__->TP3);
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->TP3.Q,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,GREENEW,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->F_TRIG3.,CLK,,__GET_VAR(data__->GREENEW,));
  F_TRIG_body__(&data__->F_TRIG3);
  __SET_VAR(data__->TP4.,IN,,__GET_VAR(data__->F_TRIG3.Q,));
  __SET_VAR(data__->TP4.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TP_body__(&data__->TP4);
  __SET_LOCATED(data__->,YELLEW,,__GET_VAR(data__->TP4.Q,));
  __SET_VAR(data__->F_TRIG4.,CLK,,__GET_LOCATED(data__->YELLEW,));
  F_TRIG_body__(&data__->F_TRIG4);
  __SET_VAR(data__->TP5.,IN,,__GET_VAR(data__->F_TRIG4.Q,));
  __SET_VAR(data__->TP5.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TP_body__(&data__->TP5);
  __SET_LOCATED(data__->,REDEW,,((!(__GET_LOCATED(data__->YELLEW,)) && !(__GET_VAR(data__->GREENEW,))) || __GET_VAR(data__->TP5.Q,)));
  __SET_VAR(data__->,START,,__GET_VAR(data__->TP0.Q,));

  goto __end;

__end:
  return;
} // STOPLIGHT_body__() 






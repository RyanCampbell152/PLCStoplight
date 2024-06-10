TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM Stoplight
  VAR
    redEW AT %QX0.3 : BOOL;
    redEW0 AT %QX0.4 : BOOL;
    yellEW AT %QX0.2 : BOOL;
    greenEWLight AT %QW2 : UINT;
    yellNS AT %QX0.1 : BOOL;
    greenNS AT %QX0.0 : BOOL;
    redNSLight AT %QW0 : UINT;
  END_VAR
  VAR
    redNS : BOOL;
    greenEW : BOOL;
    start : BOOL;
  END_VAR
  VAR
    carEW1 AT %IX0.0 : BOOL;
    carEW2 AT %IX0.1 : BOOL;
  END_VAR
  VAR
    TP0 : TP;
    TP1 : TP;
    TP2 : TP;
    TP3 : TP;
    TP4 : TP;
    TP5 : TP;
    TON0 : TON;
    TON1 : TON;
    _TMP_SEL17_OUT : UINT;
    _TMP_SEL4_OUT : UINT;
    F_TRIG1 : F_TRIG;
    F_TRIG2 : F_TRIG;
    R_TRIG1 : R_TRIG;
    F_TRIG3 : F_TRIG;
    F_TRIG4 : F_TRIG;
  END_VAR

  _TMP_SEL17_OUT := SEL(greenEW, 0, 60000);
  greenEWLight := _TMP_SEL17_OUT;
  _TMP_SEL4_OUT := SEL(redNS, 0, 60000);
  redNSLight := _TMP_SEL4_OUT;
  TP0(IN := carEW1 OR carEW2, PT := T#3000ms);
  TON0(IN := NOT(yellNS) AND NOT(yellEW) AND NOT(greenEW) AND redEW AND NOT(carEW2) AND NOT(carEW1), PT := T#2000ms);
  greenNS := TON0.Q OR TP0.Q;
  F_TRIG1(CLK := start);
  TP1(IN := F_TRIG1.Q, PT := T#3000ms);
  yellNS := TP1.Q;
  F_TRIG2(CLK := yellNS);
  TP2(IN := F_TRIG2.Q, PT := T#12000ms);
  redNS := NOT(greenNS) AND TP2.Q;
  R_TRIG1(CLK := redNS);
  TP3(IN := R_TRIG1.Q, PT := T#7000ms);
  TON1(IN := TP3.Q, PT := T#2000ms);
  greenEW := TON1.Q;
  F_TRIG3(CLK := greenEW);
  TP4(IN := F_TRIG3.Q, PT := T#3000ms);
  yellEW := TP4.Q;
  F_TRIG4(CLK := yellEW);
  TP5(IN := F_TRIG4.Q, PT := T#3000ms);
  redEW := NOT(yellEW) AND NOT(greenEW) OR TP5.Q;
  start := TP0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Stoplight;
  END_RESOURCE
END_CONFIGURATION

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.h
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 2.6
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Oct 15 00:48:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Encoder_reader_simulink_h_
#define Encoder_reader_simulink_h_
#ifndef Encoder_reader_simulink_COMMON_INCLUDES_
#define Encoder_reader_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#include "mw_stm32_utils.h"
#endif                            /* Encoder_reader_simulink_COMMON_INCLUDES_ */

#include "Encoder_reader_simulink_types.h"
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S17>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S17>/Digital Port Read' */
} B_DigitalPortRead_Encoder_rea_T;

/* Block states (default storage) for system '<S17>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S17>/Digital Port Read' */
  boolean_T objisempty;                /* '<S17>/Digital Port Read' */
} DW_DigitalPortRead_Encoder_re_T;

/* Block states (default storage) for system '<Root>/Homing1' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Homing1' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/Homing1' */
} DW_Homing1_Encoder_reader_sim_T;

/* Block states (default storage) for system '<Root>/WrapAround1' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/WrapAround1' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/WrapAround1' */
} DW_WrapAround1_Encoder_reader_T;

/* Block signals (default storage) */
typedef struct {
  real_T Sum7;                         /* '<Root>/Sum7' */
  real_T DataTypeConversion4;          /* '<Root>/Data Type Conversion4' */
  real_T Count2Deg3;                   /* '<Root>/Count2Deg3' */
  real_T Derivative16;                 /* '<Root>/Derivative16' */
  real_T Derivative17;                 /* '<Root>/Derivative17' */
  real_T Count2Rad3;                   /* '<Root>/Count2Rad3' */
  real_T Derivative12;                 /* '<Root>/Derivative12' */
  real_T Derivative13;                 /* '<Root>/Derivative13' */
  real_T DataTypeConversion5;          /* '<Root>/Data Type Conversion5' */
  real_T Count2Deg4;                   /* '<Root>/Count2Deg4' */
  real_T Derivative20;                 /* '<Root>/Derivative20' */
  real_T Derivative21;                 /* '<Root>/Derivative21' */
  real_T Count2Rad4;                   /* '<Root>/Count2Rad4' */
  real_T Derivative18;                 /* '<Root>/Derivative18' */
  real_T Derivative19;                 /* '<Root>/Derivative19' */
  real_T DataTypeConversion6;          /* '<Root>/Data Type Conversion6' */
  real_T Count2Deg5;                   /* '<Root>/Count2Deg5' */
  real_T Derivative14;                 /* '<Root>/Derivative14' */
  real_T Derivative15;                 /* '<Root>/Derivative15' */
  real_T Count2Rad5;                   /* '<Root>/Count2Rad5' */
  real_T Derivative22;                 /* '<Root>/Derivative22' */
  real_T Derivative23;                 /* '<Root>/Derivative23' */
  real_T wrapsout;                     /* '<Root>/WrapAround5' */
  real_T wrapsout_c;                   /* '<Root>/WrapAround4' */
  real_T wrapsout_cm;                  /* '<Root>/WrapAround1' */
  real_T out_m;                        /* '<Root>/Homing5' */
  real_T homing_pos_out;               /* '<Root>/Homing5' */
  real_T out_a;                        /* '<Root>/Homing4' */
  real_T homing_pos_out_f;             /* '<Root>/Homing4' */
  real_T out_h;                        /* '<Root>/Homing1' */
  real_T homing_pos_out_o;             /* '<Root>/Homing1' */
  uint32_T TIM4_Encoder2;              /* '<Root>/TIM4_Encoder2' */
  uint32_T TIM3_Encoder1;              /* '<Root>/TIM3_Encoder1' */
  uint32_T TIM20_Encoder1;             /* '<Root>/TIM20_Encoder1' */
  boolean_T DigitalPortRead_b;         /* '<S31>/Digital Port Read' */
  boolean_T DigitalPortRead_o;         /* '<S29>/Digital Port Read' */
  boolean_T DigitalPortRead_bb;        /* '<S25>/Digital Port Read' */
  boolean_T DigitalPortRead_d;         /* '<S23>/Digital Port Read' */
  boolean_T DigitalPortRead_g;         /* '<S19>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead_oc;/* '<S17>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead_f;/* '<S17>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead;/* '<S17>/Digital Port Read' */
} B_Encoder_reader_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S31>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_n;/* '<S29>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_h;/* '<S25>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_a;/* '<S23>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_o;/* '<S21>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_m;/* '<S19>/Digital Port Read' */
  stm32cube_blocks_EncoderBlock_T obj_e;/* '<Root>/TIM4_Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_c;/* '<Root>/TIM3_Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_hg;/* '<Root>/TIM20_Encoder1' */
  real_T UnitDelay6_DSTATE;            /* '<Root>/Unit Delay6' */
  real_T UnitDelay7_DSTATE;            /* '<Root>/Unit Delay7' */
  real_T UnitDelay8_DSTATE;            /* '<Root>/Unit Delay8' */
  real_T UnitDelay9_DSTATE;            /* '<Root>/Unit Delay9' */
  real_T UnitDelay10_DSTATE;           /* '<Root>/Unit Delay10' */
  real_T UnitDelay11_DSTATE;           /* '<Root>/Unit Delay11' */
  real_T Memory3_PreviousInput;        /* '<Root>/Memory3' */
  real_T TimeStampA;                   /* '<Root>/Derivative16' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative16' */
  real_T TimeStampB;                   /* '<Root>/Derivative16' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative16' */
  real_T TimeStampA_d;                 /* '<Root>/Derivative17' */
  real_T LastUAtTimeA_a;               /* '<Root>/Derivative17' */
  real_T TimeStampB_m;                 /* '<Root>/Derivative17' */
  real_T LastUAtTimeB_o;               /* '<Root>/Derivative17' */
  real_T TimeStampA_p;                 /* '<Root>/Derivative12' */
  real_T LastUAtTimeA_g;               /* '<Root>/Derivative12' */
  real_T TimeStampB_n;                 /* '<Root>/Derivative12' */
  real_T LastUAtTimeB_a;               /* '<Root>/Derivative12' */
  real_T TimeStampA_e;                 /* '<Root>/Derivative13' */
  real_T LastUAtTimeA_c;               /* '<Root>/Derivative13' */
  real_T TimeStampB_mf;                /* '<Root>/Derivative13' */
  real_T LastUAtTimeB_i;               /* '<Root>/Derivative13' */
  real_T Memory4_PreviousInput;        /* '<Root>/Memory4' */
  real_T TimeStampA_m;                 /* '<Root>/Derivative20' */
  real_T LastUAtTimeA_a2;              /* '<Root>/Derivative20' */
  real_T TimeStampB_m5;                /* '<Root>/Derivative20' */
  real_T LastUAtTimeB_h;               /* '<Root>/Derivative20' */
  real_T TimeStampA_n;                 /* '<Root>/Derivative21' */
  real_T LastUAtTimeA_a0;              /* '<Root>/Derivative21' */
  real_T TimeStampB_e;                 /* '<Root>/Derivative21' */
  real_T LastUAtTimeB_b;               /* '<Root>/Derivative21' */
  real_T TimeStampA_pz;                /* '<Root>/Derivative18' */
  real_T LastUAtTimeA_l;               /* '<Root>/Derivative18' */
  real_T TimeStampB_k;                 /* '<Root>/Derivative18' */
  real_T LastUAtTimeB_l;               /* '<Root>/Derivative18' */
  real_T TimeStampA_k;                 /* '<Root>/Derivative19' */
  real_T LastUAtTimeA_cs;              /* '<Root>/Derivative19' */
  real_T TimeStampB_eu;                /* '<Root>/Derivative19' */
  real_T LastUAtTimeB_h5;              /* '<Root>/Derivative19' */
  real_T Memory5_PreviousInput;        /* '<Root>/Memory5' */
  real_T TimeStampA_mk;                /* '<Root>/Derivative14' */
  real_T LastUAtTimeA_n;               /* '<Root>/Derivative14' */
  real_T TimeStampB_c;                 /* '<Root>/Derivative14' */
  real_T LastUAtTimeB_g;               /* '<Root>/Derivative14' */
  real_T TimeStampA_j;                 /* '<Root>/Derivative15' */
  real_T LastUAtTimeA_p;               /* '<Root>/Derivative15' */
  real_T TimeStampB_l;                 /* '<Root>/Derivative15' */
  real_T LastUAtTimeB_e;               /* '<Root>/Derivative15' */
  real_T TimeStampA_dq;                /* '<Root>/Derivative22' */
  real_T LastUAtTimeA_gv;              /* '<Root>/Derivative22' */
  real_T TimeStampB_p;                 /* '<Root>/Derivative22' */
  real_T LastUAtTimeB_k;               /* '<Root>/Derivative22' */
  real_T TimeStampA_ki;                /* '<Root>/Derivative23' */
  real_T LastUAtTimeA_k;               /* '<Root>/Derivative23' */
  real_T TimeStampB_h;                 /* '<Root>/Derivative23' */
  real_T LastUAtTimeB_c;               /* '<Root>/Derivative23' */
  DW_WrapAround1_Encoder_reader_T sf_WrapAround5;/* '<Root>/WrapAround5' */
  DW_WrapAround1_Encoder_reader_T sf_WrapAround4;/* '<Root>/WrapAround4' */
  DW_WrapAround1_Encoder_reader_T sf_WrapAround1;/* '<Root>/WrapAround1' */
  DW_Homing1_Encoder_reader_sim_T sf_Homing5;/* '<Root>/Homing5' */
  DW_Homing1_Encoder_reader_sim_T sf_Homing4;/* '<Root>/Homing4' */
  DW_Homing1_Encoder_reader_sim_T sf_Homing1;/* '<Root>/Homing1' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead_oc;/* '<S17>/Digital Port Read' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead_f;/* '<S17>/Digital Port Read' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead;/* '<S17>/Digital Port Read' */
} DW_Encoder_reader_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_Encoder_reader_simuli_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
extern DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Model entry point functions */
extern void Encoder_reader_simulink_initialize(void);
extern void Encoder_reader_simulink_step(void);
extern void Encoder_reader_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Encoder_reader_simulink'
 * '<S1>'   : 'Encoder_reader_simulink/Digital Port Read10'
 * '<S2>'   : 'Encoder_reader_simulink/Digital Port Read11'
 * '<S3>'   : 'Encoder_reader_simulink/Digital Port Read12'
 * '<S4>'   : 'Encoder_reader_simulink/Digital Port Read13'
 * '<S5>'   : 'Encoder_reader_simulink/Digital Port Read14'
 * '<S6>'   : 'Encoder_reader_simulink/Digital Port Read15'
 * '<S7>'   : 'Encoder_reader_simulink/Digital Port Read16'
 * '<S8>'   : 'Encoder_reader_simulink/Digital Port Read17'
 * '<S9>'   : 'Encoder_reader_simulink/Digital Port Read9'
 * '<S10>'  : 'Encoder_reader_simulink/Homing1'
 * '<S11>'  : 'Encoder_reader_simulink/Homing4'
 * '<S12>'  : 'Encoder_reader_simulink/Homing5'
 * '<S13>'  : 'Encoder_reader_simulink/WrapAround1'
 * '<S14>'  : 'Encoder_reader_simulink/WrapAround4'
 * '<S15>'  : 'Encoder_reader_simulink/WrapAround5'
 * '<S16>'  : 'Encoder_reader_simulink/Digital Port Read10/ECSoC'
 * '<S17>'  : 'Encoder_reader_simulink/Digital Port Read10/ECSoC/ECSimCodegen'
 * '<S18>'  : 'Encoder_reader_simulink/Digital Port Read11/ECSoC'
 * '<S19>'  : 'Encoder_reader_simulink/Digital Port Read11/ECSoC/ECSimCodegen'
 * '<S20>'  : 'Encoder_reader_simulink/Digital Port Read12/ECSoC'
 * '<S21>'  : 'Encoder_reader_simulink/Digital Port Read12/ECSoC/ECSimCodegen'
 * '<S22>'  : 'Encoder_reader_simulink/Digital Port Read13/ECSoC'
 * '<S23>'  : 'Encoder_reader_simulink/Digital Port Read13/ECSoC/ECSimCodegen'
 * '<S24>'  : 'Encoder_reader_simulink/Digital Port Read14/ECSoC'
 * '<S25>'  : 'Encoder_reader_simulink/Digital Port Read14/ECSoC/ECSimCodegen'
 * '<S26>'  : 'Encoder_reader_simulink/Digital Port Read15/ECSoC'
 * '<S27>'  : 'Encoder_reader_simulink/Digital Port Read15/ECSoC/ECSimCodegen'
 * '<S28>'  : 'Encoder_reader_simulink/Digital Port Read16/ECSoC'
 * '<S29>'  : 'Encoder_reader_simulink/Digital Port Read16/ECSoC/ECSimCodegen'
 * '<S30>'  : 'Encoder_reader_simulink/Digital Port Read17/ECSoC'
 * '<S31>'  : 'Encoder_reader_simulink/Digital Port Read17/ECSoC/ECSimCodegen'
 * '<S32>'  : 'Encoder_reader_simulink/Digital Port Read9/ECSoC'
 * '<S33>'  : 'Encoder_reader_simulink/Digital Port Read9/ECSoC/ECSimCodegen'
 */
#endif                                 /* Encoder_reader_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

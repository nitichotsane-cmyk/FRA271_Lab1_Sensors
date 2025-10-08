/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.h
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 2.5
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Oct  9 02:03:35 2025
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

/* Block states (default storage) for system '<Root>/Homing' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Homing' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/Homing' */
} DW_Homing_Encoder_reader_simu_T;

/* Block states (default storage) for system '<Root>/WrapAround' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/WrapAround' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/WrapAround' */
} DW_WrapAround_Encoder_reader__T;

/* Block signals (default storage) */
typedef struct {
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T Count2Deg;                    /* '<Root>/Count2Deg' */
  real_T Derivative2;                  /* '<Root>/Derivative2' */
  real_T Derivative3;                  /* '<Root>/Derivative3' */
  real_T Count2Rad;                    /* '<Root>/Count2Rad' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T Derivative1;                  /* '<Root>/Derivative1' */
  real_T DataTypeConversion2;          /* '<Root>/Data Type Conversion2' */
  real_T Count2Deg1;                   /* '<Root>/Count2Deg1' */
  real_T Derivative6;                  /* '<Root>/Derivative6' */
  real_T Derivative7;                  /* '<Root>/Derivative7' */
  real_T Count2Rad1;                   /* '<Root>/Count2Rad1' */
  real_T Derivative4;                  /* '<Root>/Derivative4' */
  real_T Derivative5;                  /* '<Root>/Derivative5' */
  real_T DataTypeConversion3;          /* '<Root>/Data Type Conversion3' */
  real_T Count2Deg2;                   /* '<Root>/Count2Deg2' */
  real_T Derivative10;                 /* '<Root>/Derivative10' */
  real_T Derivative11;                 /* '<Root>/Derivative11' */
  real_T Count2Rad2;                   /* '<Root>/Count2Rad2' */
  real_T Derivative8;                  /* '<Root>/Derivative8' */
  real_T Derivative9;                  /* '<Root>/Derivative9' */
  real_T wrapsout;                     /* '<Root>/WrapAround3' */
  real_T wrapsout_h;                   /* '<Root>/WrapAround2' */
  real_T wrapsout_d;                   /* '<Root>/WrapAround' */
  real_T out_e;                        /* '<Root>/Homing3' */
  real_T homing_pos_out;               /* '<Root>/Homing3' */
  real_T out_j;                        /* '<Root>/Homing2' */
  real_T homing_pos_out_g;             /* '<Root>/Homing2' */
  real_T out_m;                        /* '<Root>/Homing' */
  real_T homing_pos_out_g4;            /* '<Root>/Homing' */
  uint32_T TIM4_Encoder1;              /* '<Root>/TIM4_Encoder1' */
  uint32_T TIM3_Encoder;               /* '<Root>/TIM3_Encoder' */
  uint32_T TIM20_Encoder2;             /* '<Root>/TIM20_Encoder2' */
  boolean_T DigitalPortRead_m;         /* '<S33>/Digital Port Read' */
  boolean_T DigitalPortRead_o;         /* '<S31>/Digital Port Read' */
  boolean_T DigitalPortRead_b;         /* '<S27>/Digital Port Read' */
  boolean_T DigitalPortRead_g;         /* '<S25>/Digital Port Read' */
  boolean_T DigitalPortRead_op;        /* '<S21>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead_dw;/* '<S17>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead_l;/* '<S17>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead;/* '<S17>/Digital Port Read' */
} B_Encoder_reader_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S33>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_h;/* '<S31>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_p;/* '<S27>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_n;/* '<S25>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_d;/* '<S23>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_g;/* '<S21>/Digital Port Read' */
  stm32cube_blocks_EncoderBlock_T obj_ng;/* '<Root>/TIM4_Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_pe;/* '<Root>/TIM3_Encoder' */
  stm32cube_blocks_EncoderBlock_T obj_dx;/* '<Root>/TIM20_Encoder2' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<Root>/Unit Delay2' */
  real_T UnitDelay3_DSTATE;            /* '<Root>/Unit Delay3' */
  real_T UnitDelay4_DSTATE;            /* '<Root>/Unit Delay4' */
  real_T UnitDelay5_DSTATE;            /* '<Root>/Unit Delay5' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T TimeStampA;                   /* '<Root>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative2' */
  real_T TimeStampB;                   /* '<Root>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative2' */
  real_T TimeStampA_b;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeA_d;               /* '<Root>/Derivative3' */
  real_T TimeStampB_b;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeB_l;               /* '<Root>/Derivative3' */
  real_T TimeStampA_o;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<Root>/Derivative' */
  real_T TimeStampB_l;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeB_h;               /* '<Root>/Derivative' */
  real_T TimeStampA_p;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_g;               /* '<Root>/Derivative1' */
  real_T TimeStampB_n;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_c;               /* '<Root>/Derivative1' */
  real_T Memory1_PreviousInput;        /* '<Root>/Memory1' */
  real_T TimeStampA_k;                 /* '<Root>/Derivative6' */
  real_T LastUAtTimeA_h;               /* '<Root>/Derivative6' */
  real_T TimeStampB_k;                 /* '<Root>/Derivative6' */
  real_T LastUAtTimeB_i;               /* '<Root>/Derivative6' */
  real_T TimeStampA_p0;                /* '<Root>/Derivative7' */
  real_T LastUAtTimeA_p;               /* '<Root>/Derivative7' */
  real_T TimeStampB_d;                 /* '<Root>/Derivative7' */
  real_T LastUAtTimeB_ck;              /* '<Root>/Derivative7' */
  real_T TimeStampA_f;                 /* '<Root>/Derivative4' */
  real_T LastUAtTimeA_l;               /* '<Root>/Derivative4' */
  real_T TimeStampB_dj;                /* '<Root>/Derivative4' */
  real_T LastUAtTimeB_lu;              /* '<Root>/Derivative4' */
  real_T TimeStampA_pr;                /* '<Root>/Derivative5' */
  real_T LastUAtTimeA_gx;              /* '<Root>/Derivative5' */
  real_T TimeStampB_p;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeB_j;               /* '<Root>/Derivative5' */
  real_T Memory2_PreviousInput;        /* '<Root>/Memory2' */
  real_T TimeStampA_n;                 /* '<Root>/Derivative10' */
  real_T LastUAtTimeA_j;               /* '<Root>/Derivative10' */
  real_T TimeStampB_bx;                /* '<Root>/Derivative10' */
  real_T LastUAtTimeB_m;               /* '<Root>/Derivative10' */
  real_T TimeStampA_m;                 /* '<Root>/Derivative11' */
  real_T LastUAtTimeA_gb;              /* '<Root>/Derivative11' */
  real_T TimeStampB_ne;                /* '<Root>/Derivative11' */
  real_T LastUAtTimeB_b;               /* '<Root>/Derivative11' */
  real_T TimeStampA_ne;                /* '<Root>/Derivative8' */
  real_T LastUAtTimeA_c;               /* '<Root>/Derivative8' */
  real_T TimeStampB_ly;                /* '<Root>/Derivative8' */
  real_T LastUAtTimeB_d;               /* '<Root>/Derivative8' */
  real_T TimeStampA_d;                 /* '<Root>/Derivative9' */
  real_T LastUAtTimeA_ha;              /* '<Root>/Derivative9' */
  real_T TimeStampB_p1;                /* '<Root>/Derivative9' */
  real_T LastUAtTimeB_p;               /* '<Root>/Derivative9' */
  DW_WrapAround_Encoder_reader__T sf_WrapAround3;/* '<Root>/WrapAround3' */
  DW_WrapAround_Encoder_reader__T sf_WrapAround2;/* '<Root>/WrapAround2' */
  DW_WrapAround_Encoder_reader__T sf_WrapAround;/* '<Root>/WrapAround' */
  DW_Homing_Encoder_reader_simu_T sf_Homing3;/* '<Root>/Homing3' */
  DW_Homing_Encoder_reader_simu_T sf_Homing2;/* '<Root>/Homing2' */
  DW_Homing_Encoder_reader_simu_T sf_Homing;/* '<Root>/Homing' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead_dw;/* '<S17>/Digital Port Read' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead_l;/* '<S17>/Digital Port Read' */
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
 * '<S1>'   : 'Encoder_reader_simulink/Digital Port Read'
 * '<S2>'   : 'Encoder_reader_simulink/Digital Port Read1'
 * '<S3>'   : 'Encoder_reader_simulink/Digital Port Read2'
 * '<S4>'   : 'Encoder_reader_simulink/Digital Port Read3'
 * '<S5>'   : 'Encoder_reader_simulink/Digital Port Read4'
 * '<S6>'   : 'Encoder_reader_simulink/Digital Port Read5'
 * '<S7>'   : 'Encoder_reader_simulink/Digital Port Read6'
 * '<S8>'   : 'Encoder_reader_simulink/Digital Port Read7'
 * '<S9>'   : 'Encoder_reader_simulink/Digital Port Read8'
 * '<S10>'  : 'Encoder_reader_simulink/Homing'
 * '<S11>'  : 'Encoder_reader_simulink/Homing2'
 * '<S12>'  : 'Encoder_reader_simulink/Homing3'
 * '<S13>'  : 'Encoder_reader_simulink/WrapAround'
 * '<S14>'  : 'Encoder_reader_simulink/WrapAround2'
 * '<S15>'  : 'Encoder_reader_simulink/WrapAround3'
 * '<S16>'  : 'Encoder_reader_simulink/Digital Port Read/ECSoC'
 * '<S17>'  : 'Encoder_reader_simulink/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S18>'  : 'Encoder_reader_simulink/Digital Port Read1/ECSoC'
 * '<S19>'  : 'Encoder_reader_simulink/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S20>'  : 'Encoder_reader_simulink/Digital Port Read2/ECSoC'
 * '<S21>'  : 'Encoder_reader_simulink/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S22>'  : 'Encoder_reader_simulink/Digital Port Read3/ECSoC'
 * '<S23>'  : 'Encoder_reader_simulink/Digital Port Read3/ECSoC/ECSimCodegen'
 * '<S24>'  : 'Encoder_reader_simulink/Digital Port Read4/ECSoC'
 * '<S25>'  : 'Encoder_reader_simulink/Digital Port Read4/ECSoC/ECSimCodegen'
 * '<S26>'  : 'Encoder_reader_simulink/Digital Port Read5/ECSoC'
 * '<S27>'  : 'Encoder_reader_simulink/Digital Port Read5/ECSoC/ECSimCodegen'
 * '<S28>'  : 'Encoder_reader_simulink/Digital Port Read6/ECSoC'
 * '<S29>'  : 'Encoder_reader_simulink/Digital Port Read6/ECSoC/ECSimCodegen'
 * '<S30>'  : 'Encoder_reader_simulink/Digital Port Read7/ECSoC'
 * '<S31>'  : 'Encoder_reader_simulink/Digital Port Read7/ECSoC/ECSimCodegen'
 * '<S32>'  : 'Encoder_reader_simulink/Digital Port Read8/ECSoC'
 * '<S33>'  : 'Encoder_reader_simulink/Digital Port Read8/ECSoC/ECSimCodegen'
 */
#endif                                 /* Encoder_reader_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

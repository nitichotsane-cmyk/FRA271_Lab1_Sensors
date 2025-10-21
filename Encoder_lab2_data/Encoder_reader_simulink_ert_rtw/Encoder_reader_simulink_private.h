/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink_private.h
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 2.6
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Mon Oct 13 23:05:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Encoder_reader_simulink_private_h_
#define Encoder_reader_simulink_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Encoder_reader_simulink.h"
#include "Encoder_reader_simulink_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void Encoder_re_DigitalPortRead_Init(DW_DigitalPortRead_Encoder_re_T
  *localDW);
extern void Encoder_reader__DigitalPortRead(B_DigitalPortRead_Encoder_rea_T
  *localB);
extern void Encoder_reader_sim_Homing1_Init(DW_Homing1_Encoder_reader_sim_T
  *localDW);
extern void Encoder_reader_simulink_Homing1(real_T rtu_raw, boolean_T
  rtu_homing_sig, real_T rtu_homing_pos_in, real_T *rty_out, real_T
  *rty_homing_pos_out, DW_Homing1_Encoder_reader_sim_T *localDW);
extern void Encoder_reader_WrapAround1_Init(DW_WrapAround1_Encoder_reader_T
  *localDW);
extern void Encoder_reader_simu_WrapAround1(real_T rtu_raw, real_T rtu_diff,
  real_T rtu_wrapsin, real_T *rty_out, real_T *rty_wrapsout,
  DW_WrapAround1_Encoder_reader_T *localDW);
extern void Encoder_re_DigitalPortRead_Term(DW_DigitalPortRead_Encoder_re_T
  *localDW);

#endif                                 /* Encoder_reader_simulink_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

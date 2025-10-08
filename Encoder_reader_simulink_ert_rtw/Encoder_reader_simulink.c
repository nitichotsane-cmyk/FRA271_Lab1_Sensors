/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.c
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

#include "Encoder_reader_simulink.h"
#include "rtwtypes.h"
#include "Encoder_reader_simulink_types.h"
#include "Encoder_reader_simulink_private.h"
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/Homing' */
#define Encoder_reader_simul_CALL_EVENT (-1)

/* Named constants for MATLAB Function: '<Root>/WrapAround' */
#define Encoder_reader_sim_CALL_EVENT_e (-1)

/* Block signals (default storage) */
B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Real-time model */
static RT_MODEL_Encoder_reader_simul_T Encoder_reader_simulink_M_;
RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M =
  &Encoder_reader_simulink_M_;

/* Forward declaration for local functions */
static void Encoder_read_SystemCore_setup_j(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_rea_SystemCore_setup_j2(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_reader_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);

/* System initialize for atomic system: */
void Encoder_re_DigitalPortRead_Init(DW_DigitalPortRead_Encoder_re_T *localDW)
{
  /* Start for MATLABSystem: '<S17>/Digital Port Read' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Encoder_reader__DigitalPortRead(B_DigitalPortRead_Encoder_rea_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S17>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S17>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 8192U) != 0U);
}

/* Termination for atomic system: */
void Encoder_re_DigitalPortRead_Term(DW_DigitalPortRead_Encoder_re_T *localDW)
{
  /* Terminate for MATLABSystem: '<S17>/Digital Port Read' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S17>/Digital Port Read' */
}

/*
 * System initialize for atomic system:
 *    '<Root>/Homing'
 *    '<Root>/Homing2'
 *    '<Root>/Homing3'
 */
void Encoder_reader_simu_Homing_Init(DW_Homing_Encoder_reader_simu_T *localDW)
{
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/Homing'
 *    '<Root>/Homing2'
 *    '<Root>/Homing3'
 */
void Encoder_reader_simulink_Homing(real_T rtu_raw, boolean_T rtu_homing_sig,
  real_T rtu_homing_pos_in, real_T *rty_out, real_T *rty_homing_pos_out,
  DW_Homing_Encoder_reader_simu_T *localDW)
{
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
  if (rtu_homing_sig) {
    *rty_homing_pos_out = rtu_raw;
    *rty_out = 0.0;
  } else {
    *rty_homing_pos_out = rtu_homing_pos_in;
    *rty_out = rtu_raw - rtu_homing_pos_in;
  }
}

/*
 * System initialize for atomic system:
 *    '<Root>/WrapAround'
 *    '<Root>/WrapAround2'
 *    '<Root>/WrapAround3'
 */
void Encoder_reader__WrapAround_Init(DW_WrapAround_Encoder_reader__T *localDW)
{
  localDW->sfEvent = Encoder_reader_sim_CALL_EVENT_e;
}

/*
 * Output and update for atomic system:
 *    '<Root>/WrapAround'
 *    '<Root>/WrapAround2'
 *    '<Root>/WrapAround3'
 */
void Encoder_reader_simul_WrapAround(real_T rtu_raw, real_T rtu_diff, real_T
  rtu_wrapsin, real_T *rty_out, real_T *rty_wrapsout,
  DW_WrapAround_Encoder_reader__T *localDW)
{
  localDW->sfEvent = Encoder_reader_sim_CALL_EVENT_e;
  if (rtu_diff >= 30719.5) {
    *rty_out = (rtu_wrapsin + 1.0) * 61439.0 - rtu_raw;
    *rty_wrapsout = rtu_wrapsin - 1.0;
  } else if (rtu_diff <= -30719.5) {
    *rty_out = (rtu_wrapsin + 1.0) * 61439.0 + rtu_raw;
    *rty_wrapsout = rtu_wrapsin + 1.0;
  } else {
    *rty_out = rtu_wrapsin * 61439.0 + rtu_raw;
    *rty_wrapsout = rtu_wrapsin;
  }
}

static void Encoder_read_SystemCore_setup_j(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_rea_SystemCore_setup_j2(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM4_Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_reader_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM20;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM20_Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Encoder_reader_simulink_step(void)
{
  {
    real_T out_b;
    real_T out_d;
    real_T *lastU;
    uint32_T pinReadLoc;

    /* MATLABSystem: '<S23>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* Sum: '<Root>/Sum3' incorporates:
     *  MATLABSystem: '<S23>/Digital Port Read'
     * */
    Encoder_reader_simulink_B.Sum3 = (real_T)((pinReadLoc & 64U) != 0U) - 1.5;
    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead);

    /* MATLABSystem: '<Root>/TIM3_Encoder' */
    Encoder_reader_simulink_B.TIM3_Encoder = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_pe.TimerHandle, false, NULL);

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Encoder_reader_simulink_B.DataTypeConversion1 =
      Encoder_reader_simulink_B.TIM3_Encoder;

    /* MATLAB Function: '<Root>/WrapAround' incorporates:
     *  Sum: '<Root>/Sum'
     *  UnitDelay: '<Root>/Unit Delay'
     *  UnitDelay: '<Root>/Unit Delay1'
     */
    Encoder_reader_simul_WrapAround
      (Encoder_reader_simulink_B.DataTypeConversion1,
       Encoder_reader_simulink_B.DataTypeConversion1 -
       Encoder_reader_simulink_DW.UnitDelay_DSTATE,
       Encoder_reader_simulink_DW.UnitDelay1_DSTATE, &out_d,
       &Encoder_reader_simulink_B.wrapsout_d,
       &Encoder_reader_simulink_DW.sf_WrapAround);

    /* MATLAB Function: '<Root>/Homing' incorporates:
     *  Memory: '<Root>/Memory'
     */
    Encoder_reader_simulink_Homing(out_d,
      Encoder_reader_simulink_B.DigitalPortRead.DigitalPortRead,
      Encoder_reader_simulink_DW.Memory_PreviousInput,
      &Encoder_reader_simulink_B.out_m,
      &Encoder_reader_simulink_B.homing_pos_out_g4,
      &Encoder_reader_simulink_DW.sf_Homing);

    /* Gain: '<Root>/Count2Deg' */
    Encoder_reader_simulink_B.Count2Deg = 3.75 * Encoder_reader_simulink_B.out_m;

    /* Derivative: '<Root>/Derivative2' incorporates:
     *  Derivative: '<Root>/Derivative'
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative10'
     *  Derivative: '<Root>/Derivative11'
     *  Derivative: '<Root>/Derivative3'
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative6'
     *  Derivative: '<Root>/Derivative7'
     *  Derivative: '<Root>/Derivative8'
     *  Derivative: '<Root>/Derivative9'
     */
    out_d = Encoder_reader_simulink_M->Timing.t[0];
    if ((Encoder_reader_simulink_DW.TimeStampA >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB >= out_d)) {
      /* Derivative: '<Root>/Derivative2' */
      Encoder_reader_simulink_B.Derivative2 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
      if (Encoder_reader_simulink_DW.TimeStampA <
          Encoder_reader_simulink_DW.TimeStampB) {
        if (Encoder_reader_simulink_DW.TimeStampB < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative2' */
      Encoder_reader_simulink_B.Derivative2 =
        (Encoder_reader_simulink_B.Count2Deg - *lastU) / (out_d - out_b);
    }

    /* End of Derivative: '<Root>/Derivative2' */
    /* Derivative: '<Root>/Derivative3' */
    if ((Encoder_reader_simulink_DW.TimeStampA_b >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_b >= out_d)) {
      /* Derivative: '<Root>/Derivative3' */
      Encoder_reader_simulink_B.Derivative3 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_b;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
      if (Encoder_reader_simulink_DW.TimeStampA_b <
          Encoder_reader_simulink_DW.TimeStampB_b) {
        if (Encoder_reader_simulink_DW.TimeStampB_b < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_b;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_b >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_b;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
      }

      /* Derivative: '<Root>/Derivative3' */
      Encoder_reader_simulink_B.Derivative3 =
        (Encoder_reader_simulink_B.Derivative2 - *lastU) / (out_d - out_b);
    }

    /* Gain: '<Root>/Count2Rad' */
    Encoder_reader_simulink_B.Count2Rad = 0.065449846949787352 *
      Encoder_reader_simulink_B.out_m;

    /* Derivative: '<Root>/Derivative' */
    if ((Encoder_reader_simulink_DW.TimeStampA_o >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_l >= out_d)) {
      /* Derivative: '<Root>/Derivative' */
      Encoder_reader_simulink_B.Derivative = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_o;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
      if (Encoder_reader_simulink_DW.TimeStampA_o <
          Encoder_reader_simulink_DW.TimeStampB_l) {
        if (Encoder_reader_simulink_DW.TimeStampB_l < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_l;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_o >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_l;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
      }

      /* Derivative: '<Root>/Derivative' */
      Encoder_reader_simulink_B.Derivative =
        (Encoder_reader_simulink_B.Count2Rad - *lastU) / (out_d - out_b);
    }

    /* Derivative: '<Root>/Derivative1' */
    if ((Encoder_reader_simulink_DW.TimeStampA_p >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_n >= out_d)) {
      /* Derivative: '<Root>/Derivative1' */
      Encoder_reader_simulink_B.Derivative1 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_p;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
      if (Encoder_reader_simulink_DW.TimeStampA_p <
          Encoder_reader_simulink_DW.TimeStampB_n) {
        if (Encoder_reader_simulink_DW.TimeStampB_n < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_n;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_p >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_n;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative1' */
      Encoder_reader_simulink_B.Derivative1 =
        (Encoder_reader_simulink_B.Derivative - *lastU) / (out_d - out_b);
    }

    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead_l);

    /* MATLABSystem: '<Root>/TIM4_Encoder1' */
    Encoder_reader_simulink_B.TIM4_Encoder1 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_ng.TimerHandle, false, NULL);

    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    Encoder_reader_simulink_B.DataTypeConversion2 =
      Encoder_reader_simulink_B.TIM4_Encoder1;

    /* MATLAB Function: '<Root>/WrapAround2' incorporates:
     *  Sum: '<Root>/Sum1'
     *  UnitDelay: '<Root>/Unit Delay2'
     *  UnitDelay: '<Root>/Unit Delay3'
     */
    Encoder_reader_simul_WrapAround
      (Encoder_reader_simulink_B.DataTypeConversion2,
       Encoder_reader_simulink_B.DataTypeConversion2 -
       Encoder_reader_simulink_DW.UnitDelay2_DSTATE,
       Encoder_reader_simulink_DW.UnitDelay3_DSTATE, &out_b,
       &Encoder_reader_simulink_B.wrapsout_h,
       &Encoder_reader_simulink_DW.sf_WrapAround2);

    /* MATLAB Function: '<Root>/Homing2' incorporates:
     *  Memory: '<Root>/Memory1'
     */
    Encoder_reader_simulink_Homing(out_b,
      Encoder_reader_simulink_B.DigitalPortRead_l.DigitalPortRead,
      Encoder_reader_simulink_DW.Memory1_PreviousInput,
      &Encoder_reader_simulink_B.out_j,
      &Encoder_reader_simulink_B.homing_pos_out_g,
      &Encoder_reader_simulink_DW.sf_Homing2);

    /* Gain: '<Root>/Count2Deg1' */
    Encoder_reader_simulink_B.Count2Deg1 = 7.5 * Encoder_reader_simulink_B.out_j;

    /* Derivative: '<Root>/Derivative6' */
    if ((Encoder_reader_simulink_DW.TimeStampA_k >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_k >= out_d)) {
      /* Derivative: '<Root>/Derivative6' */
      Encoder_reader_simulink_B.Derivative6 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_k;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_h;
      if (Encoder_reader_simulink_DW.TimeStampA_k <
          Encoder_reader_simulink_DW.TimeStampB_k) {
        if (Encoder_reader_simulink_DW.TimeStampB_k < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_k;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_k >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_k;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
      }

      /* Derivative: '<Root>/Derivative6' */
      Encoder_reader_simulink_B.Derivative6 =
        (Encoder_reader_simulink_B.Count2Deg1 - *lastU) / (out_d - out_b);
    }

    /* Derivative: '<Root>/Derivative7' */
    if ((Encoder_reader_simulink_DW.TimeStampA_p0 >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_d >= out_d)) {
      /* Derivative: '<Root>/Derivative7' */
      Encoder_reader_simulink_B.Derivative7 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_p0;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
      if (Encoder_reader_simulink_DW.TimeStampA_p0 <
          Encoder_reader_simulink_DW.TimeStampB_d) {
        if (Encoder_reader_simulink_DW.TimeStampB_d < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_d;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_ck;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_p0 >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_d;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_ck;
      }

      /* Derivative: '<Root>/Derivative7' */
      Encoder_reader_simulink_B.Derivative7 =
        (Encoder_reader_simulink_B.Derivative6 - *lastU) / (out_d - out_b);
    }

    /* Gain: '<Root>/Count2Rad1' */
    Encoder_reader_simulink_B.Count2Rad1 = 0.1308996938995747 *
      Encoder_reader_simulink_B.out_j;

    /* Derivative: '<Root>/Derivative4' */
    if ((Encoder_reader_simulink_DW.TimeStampA_f >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_dj >= out_d)) {
      /* Derivative: '<Root>/Derivative4' */
      Encoder_reader_simulink_B.Derivative4 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_f;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_l;
      if (Encoder_reader_simulink_DW.TimeStampA_f <
          Encoder_reader_simulink_DW.TimeStampB_dj) {
        if (Encoder_reader_simulink_DW.TimeStampB_dj < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_dj;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_lu;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_f >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_dj;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_lu;
      }

      /* Derivative: '<Root>/Derivative4' */
      Encoder_reader_simulink_B.Derivative4 =
        (Encoder_reader_simulink_B.Count2Rad1 - *lastU) / (out_d - out_b);
    }

    /* Derivative: '<Root>/Derivative5' */
    if ((Encoder_reader_simulink_DW.TimeStampA_pr >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_p >= out_d)) {
      /* Derivative: '<Root>/Derivative5' */
      Encoder_reader_simulink_B.Derivative5 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_pr;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gx;
      if (Encoder_reader_simulink_DW.TimeStampA_pr <
          Encoder_reader_simulink_DW.TimeStampB_p) {
        if (Encoder_reader_simulink_DW.TimeStampB_p < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_p;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_pr >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_p;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
      }

      /* Derivative: '<Root>/Derivative5' */
      Encoder_reader_simulink_B.Derivative5 =
        (Encoder_reader_simulink_B.Derivative4 - *lastU) / (out_d - out_b);
    }

    Encoder_reader__DigitalPortRead
      (&Encoder_reader_simulink_B.DigitalPortRead_dw);

    /* MATLABSystem: '<Root>/TIM20_Encoder2' */
    Encoder_reader_simulink_B.TIM20_Encoder2 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_dx.TimerHandle, false, NULL);

    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    Encoder_reader_simulink_B.DataTypeConversion3 =
      Encoder_reader_simulink_B.TIM20_Encoder2;

    /* MATLAB Function: '<Root>/WrapAround3' incorporates:
     *  Sum: '<Root>/Sum2'
     *  UnitDelay: '<Root>/Unit Delay4'
     *  UnitDelay: '<Root>/Unit Delay5'
     */
    Encoder_reader_simul_WrapAround
      (Encoder_reader_simulink_B.DataTypeConversion3,
       Encoder_reader_simulink_B.DataTypeConversion3 -
       Encoder_reader_simulink_DW.UnitDelay4_DSTATE,
       Encoder_reader_simulink_DW.UnitDelay5_DSTATE, &out_b,
       &Encoder_reader_simulink_B.wrapsout,
       &Encoder_reader_simulink_DW.sf_WrapAround3);

    /* MATLAB Function: '<Root>/Homing3' incorporates:
     *  Memory: '<Root>/Memory2'
     */
    Encoder_reader_simulink_Homing(out_b,
      Encoder_reader_simulink_B.DigitalPortRead_dw.DigitalPortRead,
      Encoder_reader_simulink_DW.Memory2_PreviousInput,
      &Encoder_reader_simulink_B.out_e,
      &Encoder_reader_simulink_B.homing_pos_out,
      &Encoder_reader_simulink_DW.sf_Homing3);

    /* Gain: '<Root>/Count2Deg2' */
    Encoder_reader_simulink_B.Count2Deg2 = 15.0 *
      Encoder_reader_simulink_B.out_e;

    /* Derivative: '<Root>/Derivative10' */
    if ((Encoder_reader_simulink_DW.TimeStampA_n >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_bx >= out_d)) {
      /* Derivative: '<Root>/Derivative10' */
      Encoder_reader_simulink_B.Derivative10 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_n;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_j;
      if (Encoder_reader_simulink_DW.TimeStampA_n <
          Encoder_reader_simulink_DW.TimeStampB_bx) {
        if (Encoder_reader_simulink_DW.TimeStampB_bx < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_bx;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_n >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_bx;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
      }

      /* Derivative: '<Root>/Derivative10' */
      Encoder_reader_simulink_B.Derivative10 =
        (Encoder_reader_simulink_B.Count2Deg2 - *lastU) / (out_d - out_b);
    }

    /* Derivative: '<Root>/Derivative11' */
    if ((Encoder_reader_simulink_DW.TimeStampA_m >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_ne >= out_d)) {
      /* Derivative: '<Root>/Derivative11' */
      Encoder_reader_simulink_B.Derivative11 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_m;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gb;
      if (Encoder_reader_simulink_DW.TimeStampA_m <
          Encoder_reader_simulink_DW.TimeStampB_ne) {
        if (Encoder_reader_simulink_DW.TimeStampB_ne < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_ne;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_m >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_ne;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
      }

      /* Derivative: '<Root>/Derivative11' */
      Encoder_reader_simulink_B.Derivative11 =
        (Encoder_reader_simulink_B.Derivative10 - *lastU) / (out_d - out_b);
    }

    /* Gain: '<Root>/Count2Rad2' */
    Encoder_reader_simulink_B.Count2Rad2 = 0.26179938779914941 *
      Encoder_reader_simulink_B.out_e;

    /* Derivative: '<Root>/Derivative8' */
    if ((Encoder_reader_simulink_DW.TimeStampA_ne >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_ly >= out_d)) {
      /* Derivative: '<Root>/Derivative8' */
      Encoder_reader_simulink_B.Derivative8 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_ne;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_c;
      if (Encoder_reader_simulink_DW.TimeStampA_ne <
          Encoder_reader_simulink_DW.TimeStampB_ly) {
        if (Encoder_reader_simulink_DW.TimeStampB_ly < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_ly;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_ne >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_ly;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
      }

      /* Derivative: '<Root>/Derivative8' */
      Encoder_reader_simulink_B.Derivative8 =
        (Encoder_reader_simulink_B.Count2Rad2 - *lastU) / (out_d - out_b);
    }

    /* Derivative: '<Root>/Derivative9' */
    if ((Encoder_reader_simulink_DW.TimeStampA_d >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_p1 >= out_d)) {
      /* Derivative: '<Root>/Derivative9' */
      Encoder_reader_simulink_B.Derivative9 = 0.0;
    } else {
      out_b = Encoder_reader_simulink_DW.TimeStampA_d;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_ha;
      if (Encoder_reader_simulink_DW.TimeStampA_d <
          Encoder_reader_simulink_DW.TimeStampB_p1) {
        if (Encoder_reader_simulink_DW.TimeStampB_p1 < out_d) {
          out_b = Encoder_reader_simulink_DW.TimeStampB_p1;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_p;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_d >= out_d) {
        out_b = Encoder_reader_simulink_DW.TimeStampB_p1;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_p;
      }

      /* Derivative: '<Root>/Derivative9' */
      Encoder_reader_simulink_B.Derivative9 =
        (Encoder_reader_simulink_B.Derivative8 - *lastU) / (out_d - out_b);
    }

    /* MATLABSystem: '<S21>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S21>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_op = ((pinReadLoc & 16U) != 0U);

    /* MATLABSystem: '<S25>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S25>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_g = ((pinReadLoc & 2048U) != 0U);

    /* MATLABSystem: '<S27>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S27>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_b = ((pinReadLoc & 4096U) != 0U);

    /* MATLABSystem: '<S31>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S31>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_o = ((pinReadLoc & 8U) != 0U);

    /* MATLABSystem: '<S33>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

    /* MATLABSystem: '<S33>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_m = ((pinReadLoc & 4U) != 0U);
  }

  {
    real_T *lastU;

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    Encoder_reader_simulink_DW.UnitDelay_DSTATE =
      Encoder_reader_simulink_B.DataTypeConversion1;

    /* Update for UnitDelay: '<Root>/Unit Delay1' */
    Encoder_reader_simulink_DW.UnitDelay1_DSTATE =
      Encoder_reader_simulink_B.wrapsout_d;

    /* Update for Memory: '<Root>/Memory' */
    Encoder_reader_simulink_DW.Memory_PreviousInput =
      Encoder_reader_simulink_B.homing_pos_out_g4;

    /* Update for Derivative: '<Root>/Derivative2' */
    if (Encoder_reader_simulink_DW.TimeStampA == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else if (Encoder_reader_simulink_DW.TimeStampB == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    } else if (Encoder_reader_simulink_DW.TimeStampA <
               Encoder_reader_simulink_DW.TimeStampB) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    }

    *lastU = Encoder_reader_simulink_B.Count2Deg;

    /* End of Update for Derivative: '<Root>/Derivative2' */

    /* Update for Derivative: '<Root>/Derivative3' */
    if (Encoder_reader_simulink_DW.TimeStampA_b == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
    } else if (Encoder_reader_simulink_DW.TimeStampB_b == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    } else if (Encoder_reader_simulink_DW.TimeStampA_b <
               Encoder_reader_simulink_DW.TimeStampB_b) {
      Encoder_reader_simulink_DW.TimeStampA_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    }

    *lastU = Encoder_reader_simulink_B.Derivative2;

    /* End of Update for Derivative: '<Root>/Derivative3' */

    /* Update for Derivative: '<Root>/Derivative' */
    if (Encoder_reader_simulink_DW.TimeStampA_o == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_o =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
    } else if (Encoder_reader_simulink_DW.TimeStampB_l == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_l =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
    } else if (Encoder_reader_simulink_DW.TimeStampA_o <
               Encoder_reader_simulink_DW.TimeStampB_l) {
      Encoder_reader_simulink_DW.TimeStampA_o =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_l =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for Derivative: '<Root>/Derivative1' */
    if (Encoder_reader_simulink_DW.TimeStampA_p == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else if (Encoder_reader_simulink_DW.TimeStampB_n == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    } else if (Encoder_reader_simulink_DW.TimeStampA_p <
               Encoder_reader_simulink_DW.TimeStampB_n) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    }

    *lastU = Encoder_reader_simulink_B.Derivative;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for UnitDelay: '<Root>/Unit Delay2' */
    Encoder_reader_simulink_DW.UnitDelay2_DSTATE =
      Encoder_reader_simulink_B.DataTypeConversion2;

    /* Update for UnitDelay: '<Root>/Unit Delay3' */
    Encoder_reader_simulink_DW.UnitDelay3_DSTATE =
      Encoder_reader_simulink_B.wrapsout_h;

    /* Update for Memory: '<Root>/Memory1' */
    Encoder_reader_simulink_DW.Memory1_PreviousInput =
      Encoder_reader_simulink_B.homing_pos_out_g;

    /* Update for Derivative: '<Root>/Derivative6' */
    if (Encoder_reader_simulink_DW.TimeStampA_k == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_h;
    } else if (Encoder_reader_simulink_DW.TimeStampB_k == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
    } else if (Encoder_reader_simulink_DW.TimeStampA_k <
               Encoder_reader_simulink_DW.TimeStampB_k) {
      Encoder_reader_simulink_DW.TimeStampA_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_h;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
    }

    *lastU = Encoder_reader_simulink_B.Count2Deg1;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Encoder_reader_simulink_DW.TimeStampA_p0 == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_p0 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
    } else if (Encoder_reader_simulink_DW.TimeStampB_d == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_ck;
    } else if (Encoder_reader_simulink_DW.TimeStampA_p0 <
               Encoder_reader_simulink_DW.TimeStampB_d) {
      Encoder_reader_simulink_DW.TimeStampA_p0 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_ck;
    }

    *lastU = Encoder_reader_simulink_B.Derivative6;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Encoder_reader_simulink_DW.TimeStampA_f == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_f =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_l;
    } else if (Encoder_reader_simulink_DW.TimeStampB_dj == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_dj =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_lu;
    } else if (Encoder_reader_simulink_DW.TimeStampA_f <
               Encoder_reader_simulink_DW.TimeStampB_dj) {
      Encoder_reader_simulink_DW.TimeStampA_f =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_l;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_dj =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_lu;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad1;

    /* End of Update for Derivative: '<Root>/Derivative4' */

    /* Update for Derivative: '<Root>/Derivative5' */
    if (Encoder_reader_simulink_DW.TimeStampA_pr == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_pr =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gx;
    } else if (Encoder_reader_simulink_DW.TimeStampB_p == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
    } else if (Encoder_reader_simulink_DW.TimeStampA_pr <
               Encoder_reader_simulink_DW.TimeStampB_p) {
      Encoder_reader_simulink_DW.TimeStampA_pr =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gx;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
    }

    *lastU = Encoder_reader_simulink_B.Derivative4;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for UnitDelay: '<Root>/Unit Delay4' */
    Encoder_reader_simulink_DW.UnitDelay4_DSTATE =
      Encoder_reader_simulink_B.DataTypeConversion3;

    /* Update for UnitDelay: '<Root>/Unit Delay5' */
    Encoder_reader_simulink_DW.UnitDelay5_DSTATE =
      Encoder_reader_simulink_B.wrapsout;

    /* Update for Memory: '<Root>/Memory2' */
    Encoder_reader_simulink_DW.Memory2_PreviousInput =
      Encoder_reader_simulink_B.homing_pos_out;

    /* Update for Derivative: '<Root>/Derivative10' */
    if (Encoder_reader_simulink_DW.TimeStampA_n == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_j;
    } else if (Encoder_reader_simulink_DW.TimeStampB_bx == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_bx =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
    } else if (Encoder_reader_simulink_DW.TimeStampA_n <
               Encoder_reader_simulink_DW.TimeStampB_bx) {
      Encoder_reader_simulink_DW.TimeStampA_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_j;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_bx =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
    }

    *lastU = Encoder_reader_simulink_B.Count2Deg2;

    /* End of Update for Derivative: '<Root>/Derivative10' */

    /* Update for Derivative: '<Root>/Derivative11' */
    if (Encoder_reader_simulink_DW.TimeStampA_m == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gb;
    } else if (Encoder_reader_simulink_DW.TimeStampB_ne == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_ne =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
    } else if (Encoder_reader_simulink_DW.TimeStampA_m <
               Encoder_reader_simulink_DW.TimeStampB_ne) {
      Encoder_reader_simulink_DW.TimeStampA_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gb;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_ne =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
    }

    *lastU = Encoder_reader_simulink_B.Derivative10;

    /* End of Update for Derivative: '<Root>/Derivative11' */

    /* Update for Derivative: '<Root>/Derivative8' */
    if (Encoder_reader_simulink_DW.TimeStampA_ne == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_ne =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_c;
    } else if (Encoder_reader_simulink_DW.TimeStampB_ly == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_ly =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
    } else if (Encoder_reader_simulink_DW.TimeStampA_ne <
               Encoder_reader_simulink_DW.TimeStampB_ly) {
      Encoder_reader_simulink_DW.TimeStampA_ne =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_c;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_ly =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad2;

    /* End of Update for Derivative: '<Root>/Derivative8' */

    /* Update for Derivative: '<Root>/Derivative9' */
    if (Encoder_reader_simulink_DW.TimeStampA_d == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_ha;
    } else if (Encoder_reader_simulink_DW.TimeStampB_p1 == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_p1 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_p;
    } else if (Encoder_reader_simulink_DW.TimeStampA_d <
               Encoder_reader_simulink_DW.TimeStampB_p1) {
      Encoder_reader_simulink_DW.TimeStampA_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_ha;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_p1 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_p;
    }

    *lastU = Encoder_reader_simulink_B.Derivative8;

    /* End of Update for Derivative: '<Root>/Derivative9' */
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Encoder_reader_simulink_M->Timing.clockTick1) * 0.01);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder_reader_simulink_M->Timing.t[0] =
    ((time_T)(++Encoder_reader_simulink_M->Timing.clockTick0)) *
    Encoder_reader_simulink_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Encoder_reader_simulink_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Encoder_reader_simulink_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Encoder_reader_simulink_M->solverInfo,
                          &Encoder_reader_simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&Encoder_reader_simulink_M->solverInfo, &rtmGetTPtr
                (Encoder_reader_simulink_M));
    rtsiSetStepSizePtr(&Encoder_reader_simulink_M->solverInfo,
                       &Encoder_reader_simulink_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Encoder_reader_simulink_M->solverInfo,
                          (&rtmGetErrorStatus(Encoder_reader_simulink_M)));
    rtsiSetRTModelPtr(&Encoder_reader_simulink_M->solverInfo,
                      Encoder_reader_simulink_M);
  }

  rtsiSetSimTimeStep(&Encoder_reader_simulink_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Encoder_reader_simulink_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&Encoder_reader_simulink_M->solverInfo, false);
  rtsiSetSolverName(&Encoder_reader_simulink_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Encoder_reader_simulink_M,
             &Encoder_reader_simulink_M->Timing.tArray[0]);
  rtmSetTFinal(Encoder_reader_simulink_M, -1);
  Encoder_reader_simulink_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Encoder_reader_simulink_M->Sizes.checksums[0] = (631317792U);
  Encoder_reader_simulink_M->Sizes.checksums[1] = (982919758U);
  Encoder_reader_simulink_M->Sizes.checksums[2] = (2382462814U);
  Encoder_reader_simulink_M->Sizes.checksums[3] = (3582268664U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    Encoder_reader_simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_reader_simulink_M->extModeInfo,
      &Encoder_reader_simulink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_reader_simulink_M->extModeInfo,
                        Encoder_reader_simulink_M->Sizes.checksums);
    rteiSetTPtr(Encoder_reader_simulink_M->extModeInfo, rtmGetTPtr
                (Encoder_reader_simulink_M));
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  Encoder_reader_simulink_DW.TimeStampA = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative3' */
  Encoder_reader_simulink_DW.TimeStampA_b = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_b = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Encoder_reader_simulink_DW.TimeStampA_o = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_l = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  Encoder_reader_simulink_DW.TimeStampA_p = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_n = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative6' */
  Encoder_reader_simulink_DW.TimeStampA_k = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_k = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative7' */
  Encoder_reader_simulink_DW.TimeStampA_p0 = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_d = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative4' */
  Encoder_reader_simulink_DW.TimeStampA_f = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_dj = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative5' */
  Encoder_reader_simulink_DW.TimeStampA_pr = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_p = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative10' */
  Encoder_reader_simulink_DW.TimeStampA_n = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_bx = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative11' */
  Encoder_reader_simulink_DW.TimeStampA_m = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_ne = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative8' */
  Encoder_reader_simulink_DW.TimeStampA_ne = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_ly = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative9' */
  Encoder_reader_simulink_DW.TimeStampA_d = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_p1 = (rtInf);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround' */
  Encoder_reader__WrapAround_Init(&Encoder_reader_simulink_DW.sf_WrapAround);

  /* SystemInitialize for MATLAB Function: '<Root>/Homing' */
  Encoder_reader_simu_Homing_Init(&Encoder_reader_simulink_DW.sf_Homing);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround2' */
  Encoder_reader__WrapAround_Init(&Encoder_reader_simulink_DW.sf_WrapAround2);

  /* SystemInitialize for MATLAB Function: '<Root>/Homing2' */
  Encoder_reader_simu_Homing_Init(&Encoder_reader_simulink_DW.sf_Homing2);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround3' */
  Encoder_reader__WrapAround_Init(&Encoder_reader_simulink_DW.sf_WrapAround3);

  /* SystemInitialize for MATLAB Function: '<Root>/Homing3' */
  Encoder_reader_simu_Homing_Init(&Encoder_reader_simulink_DW.sf_Homing3);

  /* Start for MATLABSystem: '<S23>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_d.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_d.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_d.isSetupComplete = true;
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead);

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  Encoder_reader_simulink_DW.obj_pe.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_pe.matlabCodegenIsDeleted = false;
  Encoder_read_SystemCore_setup_j(&Encoder_reader_simulink_DW.obj_pe);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead_l);

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder1' */
  Encoder_reader_simulink_DW.obj_ng.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_ng.matlabCodegenIsDeleted = false;
  Encoder_rea_SystemCore_setup_j2(&Encoder_reader_simulink_DW.obj_ng);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead_dw);

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder2' */
  Encoder_reader_simulink_DW.obj_dx.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_dx.matlabCodegenIsDeleted = false;
  Encoder_reader_SystemCore_setup(&Encoder_reader_simulink_DW.obj_dx);

  /* Start for MATLABSystem: '<S21>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_g.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_g.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S25>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_n.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_p.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_h.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_h.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj.isInitialized = 1;
  Encoder_reader_simulink_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Encoder_reader_simulink_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S23>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_d.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S23>/Digital Port Read' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead);

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
  if (!Encoder_reader_simulink_DW.obj_pe.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_pe.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_pe.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_pe.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_pe.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_pe.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_pe.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_pe.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead_l);

  /* Terminate for MATLABSystem: '<Root>/TIM4_Encoder1' */
  if (!Encoder_reader_simulink_DW.obj_ng.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_ng.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_ng.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_ng.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_ng.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_ng.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_ng.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_ng.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM4_Encoder1' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead_dw);

  /* Terminate for MATLABSystem: '<Root>/TIM20_Encoder2' */
  if (!Encoder_reader_simulink_DW.obj_dx.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_dx.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_dx.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_dx.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_dx.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_dx.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_dx.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_dx.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM20_Encoder2' */
  /* Terminate for MATLABSystem: '<S21>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_g.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S21>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S25>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S27>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S27>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S31>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_h.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S31>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S33>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S33>/Digital Port Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

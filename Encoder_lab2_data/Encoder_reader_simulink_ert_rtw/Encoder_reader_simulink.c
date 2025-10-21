/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.c
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

#include "Encoder_reader_simulink.h"
#include "rtwtypes.h"
#include "Encoder_reader_simulink_types.h"
#include "Encoder_reader_simulink_private.h"
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/Homing1' */
#define Encoder_reader_simul_CALL_EVENT (-1)

/* Named constants for MATLAB Function: '<Root>/WrapAround1' */
#define Encoder_reader_sim_CALL_EVENT_d (-1)

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
 *    '<Root>/Homing1'
 *    '<Root>/Homing4'
 *    '<Root>/Homing5'
 */
void Encoder_reader_sim_Homing1_Init(DW_Homing1_Encoder_reader_sim_T *localDW)
{
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/Homing1'
 *    '<Root>/Homing4'
 *    '<Root>/Homing5'
 */
void Encoder_reader_simulink_Homing1(real_T rtu_raw, boolean_T rtu_homing_sig,
  real_T rtu_homing_pos_in, real_T *rty_out, real_T *rty_homing_pos_out,
  DW_Homing1_Encoder_reader_sim_T *localDW)
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
 *    '<Root>/WrapAround1'
 *    '<Root>/WrapAround4'
 *    '<Root>/WrapAround5'
 */
void Encoder_reader_WrapAround1_Init(DW_WrapAround1_Encoder_reader_T *localDW)
{
  localDW->sfEvent = Encoder_reader_sim_CALL_EVENT_d;
}

/*
 * Output and update for atomic system:
 *    '<Root>/WrapAround1'
 *    '<Root>/WrapAround4'
 *    '<Root>/WrapAround5'
 */
void Encoder_reader_simu_WrapAround1(real_T rtu_raw, real_T rtu_diff, real_T
  rtu_wrapsin, real_T *rty_out, real_T *rty_wrapsout,
  DW_WrapAround1_Encoder_reader_T *localDW)
{
  localDW->sfEvent = Encoder_reader_sim_CALL_EVENT_d;
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

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_rea_SystemCore_setup_j2(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM4_Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_reader_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM20;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM20_Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Encoder_reader_simulink_step(void)
{
  {
    real_T out_d;
    real_T out_j;
    real_T *lastU;
    uint32_T pinReadLoc;

    /* MATLABSystem: '<S21>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* Sum: '<Root>/Sum7' incorporates:
     *  MATLABSystem: '<S21>/Digital Port Read'
     * */
    Encoder_reader_simulink_B.Sum7 = (real_T)((pinReadLoc & 64U) != 0U) - 1.5;
    Encoder_reader__DigitalPortRead
      (&Encoder_reader_simulink_B.DigitalPortRead_oc);

    /* MATLABSystem: '<Root>/TIM3_Encoder1' */
    Encoder_reader_simulink_B.TIM3_Encoder1 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_c.TimerHandle, false, NULL);

    /* DataTypeConversion: '<Root>/Data Type Conversion4' */
    Encoder_reader_simulink_B.DataTypeConversion4 =
      Encoder_reader_simulink_B.TIM3_Encoder1;

    /* MATLAB Function: '<Root>/WrapAround1' incorporates:
     *  Sum: '<Root>/Sum4'
     *  UnitDelay: '<Root>/Unit Delay6'
     *  UnitDelay: '<Root>/Unit Delay7'
     */
    Encoder_reader_simu_WrapAround1
      (Encoder_reader_simulink_B.DataTypeConversion4,
       Encoder_reader_simulink_B.DataTypeConversion4 -
       Encoder_reader_simulink_DW.UnitDelay6_DSTATE,
       Encoder_reader_simulink_DW.UnitDelay7_DSTATE, &out_d,
       &Encoder_reader_simulink_B.wrapsout_cm,
       &Encoder_reader_simulink_DW.sf_WrapAround1);

    /* MATLAB Function: '<Root>/Homing1' incorporates:
     *  Memory: '<Root>/Memory3'
     */
    Encoder_reader_simulink_Homing1(out_d,
      Encoder_reader_simulink_B.DigitalPortRead_oc.DigitalPortRead,
      Encoder_reader_simulink_DW.Memory3_PreviousInput,
      &Encoder_reader_simulink_B.out_h,
      &Encoder_reader_simulink_B.homing_pos_out_o,
      &Encoder_reader_simulink_DW.sf_Homing1);

    /* Gain: '<Root>/Count2Deg3' */
    Encoder_reader_simulink_B.Count2Deg3 = 0.0439453125 *
      Encoder_reader_simulink_B.out_h;

    /* Derivative: '<Root>/Derivative16' incorporates:
     *  Derivative: '<Root>/Derivative12'
     *  Derivative: '<Root>/Derivative13'
     *  Derivative: '<Root>/Derivative14'
     *  Derivative: '<Root>/Derivative15'
     *  Derivative: '<Root>/Derivative17'
     *  Derivative: '<Root>/Derivative18'
     *  Derivative: '<Root>/Derivative19'
     *  Derivative: '<Root>/Derivative20'
     *  Derivative: '<Root>/Derivative21'
     *  Derivative: '<Root>/Derivative22'
     *  Derivative: '<Root>/Derivative23'
     */
    out_d = Encoder_reader_simulink_M->Timing.t[0];
    if ((Encoder_reader_simulink_DW.TimeStampA >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB >= out_d)) {
      /* Derivative: '<Root>/Derivative16' */
      Encoder_reader_simulink_B.Derivative16 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
      if (Encoder_reader_simulink_DW.TimeStampA <
          Encoder_reader_simulink_DW.TimeStampB) {
        if (Encoder_reader_simulink_DW.TimeStampB < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative16' */
      Encoder_reader_simulink_B.Derivative16 =
        (Encoder_reader_simulink_B.Count2Deg3 - *lastU) / (out_d - out_j);
    }

    /* End of Derivative: '<Root>/Derivative16' */
    /* Derivative: '<Root>/Derivative17' */
    if ((Encoder_reader_simulink_DW.TimeStampA_d >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_m >= out_d)) {
      /* Derivative: '<Root>/Derivative17' */
      Encoder_reader_simulink_B.Derivative17 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_d;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a;
      if (Encoder_reader_simulink_DW.TimeStampA_d <
          Encoder_reader_simulink_DW.TimeStampB_m) {
        if (Encoder_reader_simulink_DW.TimeStampB_m < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_m;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_d >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_m;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
      }

      /* Derivative: '<Root>/Derivative17' */
      Encoder_reader_simulink_B.Derivative17 =
        (Encoder_reader_simulink_B.Derivative16 - *lastU) / (out_d - out_j);
    }

    /* Gain: '<Root>/Count2Rad3' */
    Encoder_reader_simulink_B.Count2Rad3 = 0.00076699039394282058 *
      Encoder_reader_simulink_B.out_h;

    /* Derivative: '<Root>/Derivative12' */
    if ((Encoder_reader_simulink_DW.TimeStampA_p >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_n >= out_d)) {
      /* Derivative: '<Root>/Derivative12' */
      Encoder_reader_simulink_B.Derivative12 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_p;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
      if (Encoder_reader_simulink_DW.TimeStampA_p <
          Encoder_reader_simulink_DW.TimeStampB_n) {
        if (Encoder_reader_simulink_DW.TimeStampB_n < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_n;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_p >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_n;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
      }

      /* Derivative: '<Root>/Derivative12' */
      Encoder_reader_simulink_B.Derivative12 =
        (Encoder_reader_simulink_B.Count2Rad3 - *lastU) / (out_d - out_j);
    }

    /* Derivative: '<Root>/Derivative13' */
    if ((Encoder_reader_simulink_DW.TimeStampA_e >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_mf >= out_d)) {
      /* Derivative: '<Root>/Derivative13' */
      Encoder_reader_simulink_B.Derivative13 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_e;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_c;
      if (Encoder_reader_simulink_DW.TimeStampA_e <
          Encoder_reader_simulink_DW.TimeStampB_mf) {
        if (Encoder_reader_simulink_DW.TimeStampB_mf < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_mf;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_e >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_mf;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
      }

      /* Derivative: '<Root>/Derivative13' */
      Encoder_reader_simulink_B.Derivative13 =
        (Encoder_reader_simulink_B.Derivative12 - *lastU) / (out_d - out_j);
    }

    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead);

    /* MATLABSystem: '<Root>/TIM4_Encoder2' */
    Encoder_reader_simulink_B.TIM4_Encoder2 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_e.TimerHandle, false, NULL);

    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    Encoder_reader_simulink_B.DataTypeConversion5 =
      Encoder_reader_simulink_B.TIM4_Encoder2;

    /* MATLAB Function: '<Root>/WrapAround4' incorporates:
     *  Sum: '<Root>/Sum5'
     *  UnitDelay: '<Root>/Unit Delay8'
     *  UnitDelay: '<Root>/Unit Delay9'
     */
    Encoder_reader_simu_WrapAround1
      (Encoder_reader_simulink_B.DataTypeConversion5,
       Encoder_reader_simulink_B.DataTypeConversion5 -
       Encoder_reader_simulink_DW.UnitDelay8_DSTATE,
       Encoder_reader_simulink_DW.UnitDelay9_DSTATE, &out_j,
       &Encoder_reader_simulink_B.wrapsout_c,
       &Encoder_reader_simulink_DW.sf_WrapAround4);

    /* MATLAB Function: '<Root>/Homing4' incorporates:
     *  Memory: '<Root>/Memory4'
     */
    Encoder_reader_simulink_Homing1(out_j,
      Encoder_reader_simulink_B.DigitalPortRead.DigitalPortRead,
      Encoder_reader_simulink_DW.Memory4_PreviousInput,
      &Encoder_reader_simulink_B.out_a,
      &Encoder_reader_simulink_B.homing_pos_out_f,
      &Encoder_reader_simulink_DW.sf_Homing4);

    /* Gain: '<Root>/Count2Deg4' */
    Encoder_reader_simulink_B.Count2Deg4 = 0.087890625 *
      Encoder_reader_simulink_B.out_a;

    /* Derivative: '<Root>/Derivative20' */
    if ((Encoder_reader_simulink_DW.TimeStampA_m >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_m5 >= out_d)) {
      /* Derivative: '<Root>/Derivative20' */
      Encoder_reader_simulink_B.Derivative20 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_m;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a2;
      if (Encoder_reader_simulink_DW.TimeStampA_m <
          Encoder_reader_simulink_DW.TimeStampB_m5) {
        if (Encoder_reader_simulink_DW.TimeStampB_m5 < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_m5;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_m >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_m5;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
      }

      /* Derivative: '<Root>/Derivative20' */
      Encoder_reader_simulink_B.Derivative20 =
        (Encoder_reader_simulink_B.Count2Deg4 - *lastU) / (out_d - out_j);
    }

    /* Derivative: '<Root>/Derivative21' */
    if ((Encoder_reader_simulink_DW.TimeStampA_n >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_e >= out_d)) {
      /* Derivative: '<Root>/Derivative21' */
      Encoder_reader_simulink_B.Derivative21 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_n;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a0;
      if (Encoder_reader_simulink_DW.TimeStampA_n <
          Encoder_reader_simulink_DW.TimeStampB_e) {
        if (Encoder_reader_simulink_DW.TimeStampB_e < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_e;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_n >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_e;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
      }

      /* Derivative: '<Root>/Derivative21' */
      Encoder_reader_simulink_B.Derivative21 =
        (Encoder_reader_simulink_B.Derivative20 - *lastU) / (out_d - out_j);
    }

    /* Gain: '<Root>/Count2Rad4' */
    Encoder_reader_simulink_B.Count2Rad4 = 0.0015339807878856412 *
      Encoder_reader_simulink_B.out_a;

    /* Derivative: '<Root>/Derivative18' */
    if ((Encoder_reader_simulink_DW.TimeStampA_pz >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_k >= out_d)) {
      /* Derivative: '<Root>/Derivative18' */
      Encoder_reader_simulink_B.Derivative18 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_pz;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_l;
      if (Encoder_reader_simulink_DW.TimeStampA_pz <
          Encoder_reader_simulink_DW.TimeStampB_k) {
        if (Encoder_reader_simulink_DW.TimeStampB_k < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_k;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_pz >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_k;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
      }

      /* Derivative: '<Root>/Derivative18' */
      Encoder_reader_simulink_B.Derivative18 =
        (Encoder_reader_simulink_B.Count2Rad4 - *lastU) / (out_d - out_j);
    }

    /* Derivative: '<Root>/Derivative19' */
    if ((Encoder_reader_simulink_DW.TimeStampA_k >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_eu >= out_d)) {
      /* Derivative: '<Root>/Derivative19' */
      Encoder_reader_simulink_B.Derivative19 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_k;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_cs;
      if (Encoder_reader_simulink_DW.TimeStampA_k <
          Encoder_reader_simulink_DW.TimeStampB_eu) {
        if (Encoder_reader_simulink_DW.TimeStampB_eu < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_eu;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h5;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_k >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_eu;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h5;
      }

      /* Derivative: '<Root>/Derivative19' */
      Encoder_reader_simulink_B.Derivative19 =
        (Encoder_reader_simulink_B.Derivative18 - *lastU) / (out_d - out_j);
    }

    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead_f);

    /* MATLABSystem: '<Root>/TIM20_Encoder1' */
    Encoder_reader_simulink_B.TIM20_Encoder1 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_hg.TimerHandle, false, NULL);

    /* DataTypeConversion: '<Root>/Data Type Conversion6' */
    Encoder_reader_simulink_B.DataTypeConversion6 =
      Encoder_reader_simulink_B.TIM20_Encoder1;

    /* MATLAB Function: '<Root>/WrapAround5' incorporates:
     *  Sum: '<Root>/Sum6'
     *  UnitDelay: '<Root>/Unit Delay10'
     *  UnitDelay: '<Root>/Unit Delay11'
     */
    Encoder_reader_simu_WrapAround1
      (Encoder_reader_simulink_B.DataTypeConversion6,
       Encoder_reader_simulink_B.DataTypeConversion6 -
       Encoder_reader_simulink_DW.UnitDelay10_DSTATE,
       Encoder_reader_simulink_DW.UnitDelay11_DSTATE, &out_j,
       &Encoder_reader_simulink_B.wrapsout,
       &Encoder_reader_simulink_DW.sf_WrapAround5);

    /* MATLAB Function: '<Root>/Homing5' incorporates:
     *  Memory: '<Root>/Memory5'
     */
    Encoder_reader_simulink_Homing1(out_j,
      Encoder_reader_simulink_B.DigitalPortRead_f.DigitalPortRead,
      Encoder_reader_simulink_DW.Memory5_PreviousInput,
      &Encoder_reader_simulink_B.out_m,
      &Encoder_reader_simulink_B.homing_pos_out,
      &Encoder_reader_simulink_DW.sf_Homing5);

    /* Gain: '<Root>/Count2Deg5' */
    Encoder_reader_simulink_B.Count2Deg5 = 0.17578125 *
      Encoder_reader_simulink_B.out_m;

    /* Derivative: '<Root>/Derivative14' */
    if ((Encoder_reader_simulink_DW.TimeStampA_mk >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_c >= out_d)) {
      /* Derivative: '<Root>/Derivative14' */
      Encoder_reader_simulink_B.Derivative14 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_mk;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_n;
      if (Encoder_reader_simulink_DW.TimeStampA_mk <
          Encoder_reader_simulink_DW.TimeStampB_c) {
        if (Encoder_reader_simulink_DW.TimeStampB_c < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_c;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_mk >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_c;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
      }

      /* Derivative: '<Root>/Derivative14' */
      Encoder_reader_simulink_B.Derivative14 =
        (Encoder_reader_simulink_B.Count2Deg5 - *lastU) / (out_d - out_j);
    }

    /* Derivative: '<Root>/Derivative15' */
    if ((Encoder_reader_simulink_DW.TimeStampA_j >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_l >= out_d)) {
      /* Derivative: '<Root>/Derivative15' */
      Encoder_reader_simulink_B.Derivative15 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_j;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
      if (Encoder_reader_simulink_DW.TimeStampA_j <
          Encoder_reader_simulink_DW.TimeStampB_l) {
        if (Encoder_reader_simulink_DW.TimeStampB_l < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_l;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_j >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_l;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
      }

      /* Derivative: '<Root>/Derivative15' */
      Encoder_reader_simulink_B.Derivative15 =
        (Encoder_reader_simulink_B.Derivative14 - *lastU) / (out_d - out_j);
    }

    /* Gain: '<Root>/Count2Rad5' */
    Encoder_reader_simulink_B.Count2Rad5 = 0.0030679615757712823 *
      Encoder_reader_simulink_B.out_m;

    /* Derivative: '<Root>/Derivative22' */
    if ((Encoder_reader_simulink_DW.TimeStampA_dq >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_p >= out_d)) {
      /* Derivative: '<Root>/Derivative22' */
      Encoder_reader_simulink_B.Derivative22 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_dq;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gv;
      if (Encoder_reader_simulink_DW.TimeStampA_dq <
          Encoder_reader_simulink_DW.TimeStampB_p) {
        if (Encoder_reader_simulink_DW.TimeStampB_p < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_p;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_k;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_dq >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_p;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_k;
      }

      /* Derivative: '<Root>/Derivative22' */
      Encoder_reader_simulink_B.Derivative22 =
        (Encoder_reader_simulink_B.Count2Rad5 - *lastU) / (out_d - out_j);
    }

    /* Derivative: '<Root>/Derivative23' */
    if ((Encoder_reader_simulink_DW.TimeStampA_ki >= out_d) &&
        (Encoder_reader_simulink_DW.TimeStampB_h >= out_d)) {
      /* Derivative: '<Root>/Derivative23' */
      Encoder_reader_simulink_B.Derivative23 = 0.0;
    } else {
      out_j = Encoder_reader_simulink_DW.TimeStampA_ki;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_k;
      if (Encoder_reader_simulink_DW.TimeStampA_ki <
          Encoder_reader_simulink_DW.TimeStampB_h) {
        if (Encoder_reader_simulink_DW.TimeStampB_h < out_d) {
          out_j = Encoder_reader_simulink_DW.TimeStampB_h;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_ki >= out_d) {
        out_j = Encoder_reader_simulink_DW.TimeStampB_h;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative23' */
      Encoder_reader_simulink_B.Derivative23 =
        (Encoder_reader_simulink_B.Derivative22 - *lastU) / (out_d - out_j);
    }

    /* MATLABSystem: '<S19>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S19>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_g = ((pinReadLoc & 16U) != 0U);

    /* MATLABSystem: '<S23>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S23>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_d = ((pinReadLoc & 2048U) != 0U);

    /* MATLABSystem: '<S25>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S25>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_bb = ((pinReadLoc & 4096U) != 0U);

    /* MATLABSystem: '<S29>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S29>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_o = ((pinReadLoc & 8U) != 0U);

    /* MATLABSystem: '<S31>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

    /* MATLABSystem: '<S31>/Digital Port Read' */
    Encoder_reader_simulink_B.DigitalPortRead_b = ((pinReadLoc & 4U) != 0U);
  }

  {
    real_T *lastU;

    /* Update for UnitDelay: '<Root>/Unit Delay6' */
    Encoder_reader_simulink_DW.UnitDelay6_DSTATE =
      Encoder_reader_simulink_B.DataTypeConversion4;

    /* Update for UnitDelay: '<Root>/Unit Delay7' */
    Encoder_reader_simulink_DW.UnitDelay7_DSTATE =
      Encoder_reader_simulink_B.wrapsout_cm;

    /* Update for Memory: '<Root>/Memory3' */
    Encoder_reader_simulink_DW.Memory3_PreviousInput =
      Encoder_reader_simulink_B.homing_pos_out_o;

    /* Update for Derivative: '<Root>/Derivative16' */
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

    *lastU = Encoder_reader_simulink_B.Count2Deg3;

    /* End of Update for Derivative: '<Root>/Derivative16' */

    /* Update for Derivative: '<Root>/Derivative17' */
    if (Encoder_reader_simulink_DW.TimeStampA_d == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a;
    } else if (Encoder_reader_simulink_DW.TimeStampB_m == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
    } else if (Encoder_reader_simulink_DW.TimeStampA_d <
               Encoder_reader_simulink_DW.TimeStampB_m) {
      Encoder_reader_simulink_DW.TimeStampA_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
    }

    *lastU = Encoder_reader_simulink_B.Derivative16;

    /* End of Update for Derivative: '<Root>/Derivative17' */

    /* Update for Derivative: '<Root>/Derivative12' */
    if (Encoder_reader_simulink_DW.TimeStampA_p == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else if (Encoder_reader_simulink_DW.TimeStampB_n == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
    } else if (Encoder_reader_simulink_DW.TimeStampA_p <
               Encoder_reader_simulink_DW.TimeStampB_n) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad3;

    /* End of Update for Derivative: '<Root>/Derivative12' */

    /* Update for Derivative: '<Root>/Derivative13' */
    if (Encoder_reader_simulink_DW.TimeStampA_e == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_e =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_c;
    } else if (Encoder_reader_simulink_DW.TimeStampB_mf == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_mf =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
    } else if (Encoder_reader_simulink_DW.TimeStampA_e <
               Encoder_reader_simulink_DW.TimeStampB_mf) {
      Encoder_reader_simulink_DW.TimeStampA_e =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_c;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_mf =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_i;
    }

    *lastU = Encoder_reader_simulink_B.Derivative12;

    /* End of Update for Derivative: '<Root>/Derivative13' */

    /* Update for UnitDelay: '<Root>/Unit Delay8' */
    Encoder_reader_simulink_DW.UnitDelay8_DSTATE =
      Encoder_reader_simulink_B.DataTypeConversion5;

    /* Update for UnitDelay: '<Root>/Unit Delay9' */
    Encoder_reader_simulink_DW.UnitDelay9_DSTATE =
      Encoder_reader_simulink_B.wrapsout_c;

    /* Update for Memory: '<Root>/Memory4' */
    Encoder_reader_simulink_DW.Memory4_PreviousInput =
      Encoder_reader_simulink_B.homing_pos_out_f;

    /* Update for Derivative: '<Root>/Derivative20' */
    if (Encoder_reader_simulink_DW.TimeStampA_m == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a2;
    } else if (Encoder_reader_simulink_DW.TimeStampB_m5 == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_m5 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
    } else if (Encoder_reader_simulink_DW.TimeStampA_m <
               Encoder_reader_simulink_DW.TimeStampB_m5) {
      Encoder_reader_simulink_DW.TimeStampA_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a2;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_m5 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h;
    }

    *lastU = Encoder_reader_simulink_B.Count2Deg4;

    /* End of Update for Derivative: '<Root>/Derivative20' */

    /* Update for Derivative: '<Root>/Derivative21' */
    if (Encoder_reader_simulink_DW.TimeStampA_n == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a0;
    } else if (Encoder_reader_simulink_DW.TimeStampB_e == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_e =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
    } else if (Encoder_reader_simulink_DW.TimeStampA_n <
               Encoder_reader_simulink_DW.TimeStampB_e) {
      Encoder_reader_simulink_DW.TimeStampA_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_a0;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_e =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_b;
    }

    *lastU = Encoder_reader_simulink_B.Derivative20;

    /* End of Update for Derivative: '<Root>/Derivative21' */

    /* Update for Derivative: '<Root>/Derivative18' */
    if (Encoder_reader_simulink_DW.TimeStampA_pz == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_pz =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_l;
    } else if (Encoder_reader_simulink_DW.TimeStampB_k == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    } else if (Encoder_reader_simulink_DW.TimeStampA_pz <
               Encoder_reader_simulink_DW.TimeStampB_k) {
      Encoder_reader_simulink_DW.TimeStampA_pz =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_l;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad4;

    /* End of Update for Derivative: '<Root>/Derivative18' */

    /* Update for Derivative: '<Root>/Derivative19' */
    if (Encoder_reader_simulink_DW.TimeStampA_k == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_cs;
    } else if (Encoder_reader_simulink_DW.TimeStampB_eu == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_eu =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h5;
    } else if (Encoder_reader_simulink_DW.TimeStampA_k <
               Encoder_reader_simulink_DW.TimeStampB_eu) {
      Encoder_reader_simulink_DW.TimeStampA_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_cs;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_eu =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_h5;
    }

    *lastU = Encoder_reader_simulink_B.Derivative18;

    /* End of Update for Derivative: '<Root>/Derivative19' */

    /* Update for UnitDelay: '<Root>/Unit Delay10' */
    Encoder_reader_simulink_DW.UnitDelay10_DSTATE =
      Encoder_reader_simulink_B.DataTypeConversion6;

    /* Update for UnitDelay: '<Root>/Unit Delay11' */
    Encoder_reader_simulink_DW.UnitDelay11_DSTATE =
      Encoder_reader_simulink_B.wrapsout;

    /* Update for Memory: '<Root>/Memory5' */
    Encoder_reader_simulink_DW.Memory5_PreviousInput =
      Encoder_reader_simulink_B.homing_pos_out;

    /* Update for Derivative: '<Root>/Derivative14' */
    if (Encoder_reader_simulink_DW.TimeStampA_mk == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_mk =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_n;
    } else if (Encoder_reader_simulink_DW.TimeStampB_c == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_c =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
    } else if (Encoder_reader_simulink_DW.TimeStampA_mk <
               Encoder_reader_simulink_DW.TimeStampB_c) {
      Encoder_reader_simulink_DW.TimeStampA_mk =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_n;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_c =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
    }

    *lastU = Encoder_reader_simulink_B.Count2Deg5;

    /* End of Update for Derivative: '<Root>/Derivative14' */

    /* Update for Derivative: '<Root>/Derivative15' */
    if (Encoder_reader_simulink_DW.TimeStampA_j == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_j =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
    } else if (Encoder_reader_simulink_DW.TimeStampB_l == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_l =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
    } else if (Encoder_reader_simulink_DW.TimeStampA_j <
               Encoder_reader_simulink_DW.TimeStampB_l) {
      Encoder_reader_simulink_DW.TimeStampA_j =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_l =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
    }

    *lastU = Encoder_reader_simulink_B.Derivative14;

    /* End of Update for Derivative: '<Root>/Derivative15' */

    /* Update for Derivative: '<Root>/Derivative22' */
    if (Encoder_reader_simulink_DW.TimeStampA_dq == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_dq =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gv;
    } else if (Encoder_reader_simulink_DW.TimeStampB_p == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_k;
    } else if (Encoder_reader_simulink_DW.TimeStampA_dq <
               Encoder_reader_simulink_DW.TimeStampB_p) {
      Encoder_reader_simulink_DW.TimeStampA_dq =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gv;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_k;
    }

    *lastU = Encoder_reader_simulink_B.Count2Rad5;

    /* End of Update for Derivative: '<Root>/Derivative22' */

    /* Update for Derivative: '<Root>/Derivative23' */
    if (Encoder_reader_simulink_DW.TimeStampA_ki == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_ki =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_k;
    } else if (Encoder_reader_simulink_DW.TimeStampB_h == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_h =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    } else if (Encoder_reader_simulink_DW.TimeStampA_ki <
               Encoder_reader_simulink_DW.TimeStampB_h) {
      Encoder_reader_simulink_DW.TimeStampA_ki =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_k;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_h =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    }

    *lastU = Encoder_reader_simulink_B.Derivative22;

    /* End of Update for Derivative: '<Root>/Derivative23' */
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
  Encoder_reader_simulink_M->Sizes.checksums[0] = (2309023899U);
  Encoder_reader_simulink_M->Sizes.checksums[1] = (816595673U);
  Encoder_reader_simulink_M->Sizes.checksums[2] = (1498330105U);
  Encoder_reader_simulink_M->Sizes.checksums[3] = (3823201318U);

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

  /* InitializeConditions for Derivative: '<Root>/Derivative16' */
  Encoder_reader_simulink_DW.TimeStampA = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative17' */
  Encoder_reader_simulink_DW.TimeStampA_d = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_m = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative12' */
  Encoder_reader_simulink_DW.TimeStampA_p = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_n = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative13' */
  Encoder_reader_simulink_DW.TimeStampA_e = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_mf = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative20' */
  Encoder_reader_simulink_DW.TimeStampA_m = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_m5 = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative21' */
  Encoder_reader_simulink_DW.TimeStampA_n = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_e = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative18' */
  Encoder_reader_simulink_DW.TimeStampA_pz = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_k = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative19' */
  Encoder_reader_simulink_DW.TimeStampA_k = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_eu = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative14' */
  Encoder_reader_simulink_DW.TimeStampA_mk = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative15' */
  Encoder_reader_simulink_DW.TimeStampA_j = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_l = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative22' */
  Encoder_reader_simulink_DW.TimeStampA_dq = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_p = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative23' */
  Encoder_reader_simulink_DW.TimeStampA_ki = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_h = (rtInf);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround1' */
  Encoder_reader_WrapAround1_Init(&Encoder_reader_simulink_DW.sf_WrapAround1);

  /* SystemInitialize for MATLAB Function: '<Root>/Homing1' */
  Encoder_reader_sim_Homing1_Init(&Encoder_reader_simulink_DW.sf_Homing1);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround4' */
  Encoder_reader_WrapAround1_Init(&Encoder_reader_simulink_DW.sf_WrapAround4);

  /* SystemInitialize for MATLAB Function: '<Root>/Homing4' */
  Encoder_reader_sim_Homing1_Init(&Encoder_reader_simulink_DW.sf_Homing4);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround5' */
  Encoder_reader_WrapAround1_Init(&Encoder_reader_simulink_DW.sf_WrapAround5);

  /* SystemInitialize for MATLAB Function: '<Root>/Homing5' */
  Encoder_reader_sim_Homing1_Init(&Encoder_reader_simulink_DW.sf_Homing5);

  /* Start for MATLABSystem: '<S21>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_o.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_o.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_o.isSetupComplete = true;
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead_oc);

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  Encoder_reader_simulink_DW.obj_c.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_c.matlabCodegenIsDeleted = false;
  Encoder_read_SystemCore_setup_j(&Encoder_reader_simulink_DW.obj_c);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead);

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder2' */
  Encoder_reader_simulink_DW.obj_e.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_e.matlabCodegenIsDeleted = false;
  Encoder_rea_SystemCore_setup_j2(&Encoder_reader_simulink_DW.obj_e);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead_f);

  /* Start for MATLABSystem: '<Root>/TIM20_Encoder1' */
  Encoder_reader_simulink_DW.obj_hg.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_hg.matlabCodegenIsDeleted = false;
  Encoder_reader_SystemCore_setup(&Encoder_reader_simulink_DW.obj_hg);

  /* Start for MATLABSystem: '<S19>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_m.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_m.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S23>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_a.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_a.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S25>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_h.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_h.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S29>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_n.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj.isInitialized = 1;
  Encoder_reader_simulink_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Encoder_reader_simulink_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S21>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_o.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S21>/Digital Port Read' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead_oc);

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder1' */
  if (!Encoder_reader_simulink_DW.obj_c.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_c.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_c.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_c.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_c.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_c.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_c.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder1' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead);

  /* Terminate for MATLABSystem: '<Root>/TIM4_Encoder2' */
  if (!Encoder_reader_simulink_DW.obj_e.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_e.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_e.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_e.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_e.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_e.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM4_Encoder2' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead_f);

  /* Terminate for MATLABSystem: '<Root>/TIM20_Encoder1' */
  if (!Encoder_reader_simulink_DW.obj_hg.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_hg.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_hg.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_hg.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_hg.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_hg.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_hg.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_hg.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM20_Encoder1' */
  /* Terminate for MATLABSystem: '<S19>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_m.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S19>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S23>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_a.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S23>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S25>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_h.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S29>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S29>/Digital Port Read' */
  /* Terminate for MATLABSystem: '<S31>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S31>/Digital Port Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

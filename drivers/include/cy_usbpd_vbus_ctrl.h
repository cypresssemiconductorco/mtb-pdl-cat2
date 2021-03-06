/***************************************************************************//**
* \file cy_usbpd_vbus_ctrl.h
* \version 1.0
*
* Provides API declarations of the USBPD VBUS Control driver.
*
********************************************************************************
* \copyright
* Copyright 2021 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
#ifndef _CY_USBPD_VBUS_CTRL_H_
#define _CY_USBPD_VBUS_CTRL_H_

#include "cy_usbpd_common.h"

/**
* \addtogroup group_usbpd_vbus_ctrl
* \{
* USBPD VBus Control driver.
*
* \defgroup group_usbpd_vbus_ctrl_enums Enumerated Types
* \defgroup group_usbpd_vbus_ctrl_functions Functions
*/

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_usbpd_vbus_ctrl_enums
* \{
*/
/** List of RefGen Outputs **/
typedef enum
{
    CY_USBPD_VREF_VBUS_UV = 2,              /**< Vref used for UVP on PMG1S1. */
    CY_USBPD_VREF_VBUS_OV = 3,              /**< Vref used for OVP on PMG1S1. */
    CY_USBPD_VREF_CSA_OCP = 5,              /**< Vref used for CSA OCP on PMG1S1. */
    CY_USBPD_VREF_CSA_SCP = 7,              /**< Vref used for CSA SCP on PMG1S1. */
    CY_USBPD_VREF_RCP_CSA = 8,              /**< Vref used for Reverse current sensing on PMG1S1. */
    CY_USBPD_VREF_RCP_OVP = 10              /**< Vref used for RCP based on VBus over-voltage on PMG1S1. */
} cy_en_usbpd_refgen_op_t;

/** \} group_usbpd_vbus_ctrl_enums */

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_vbus_ctrl_functions
* \{
*/

cy_en_usbpd_status_t Cy_USBPD_Adc_Init(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId);

uint8_t Cy_USBPD_Adc_VoltToLevel(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint16_t volt);

uint16_t Cy_USBPD_Adc_LevelToVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint8_t level);

uint16_t Cy_USBPD_Adc_GetVbusVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint8_t level);

cy_en_usbpd_status_t  Cy_USBPD_Adc_FreeRunCtrl(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, 
                                            cy_en_usbpd_adc_input_t input, uint8_t level);

void Cy_USBPD_Adc_CompCtrl(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input,
                            uint8_t level, cy_en_usbpd_adc_int_t intCfg, cy_cb_adc_events_t cb);
                            
bool Cy_USBPD_Adc_CompSample(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input, uint8_t level);

bool Cy_USBPD_Adc_GetCompStatus(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId);

uint8_t Cy_USBPD_Adc_Sample(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input);

uint16_t Cy_USBPD_Adc_Calibrate(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId);

cy_en_usbpd_status_t Cy_USBPD_Adc_SelectVref(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_vref_t vrefSel);

uint8_t Cy_USBPD_Adc_GetVbusLevel(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint16_t volt, int8_t per);

uint16_t Cy_USBPD_Adc_MeasureVbusIn(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  cy_en_usbpd_adc_input_t input);

uint16_t Cy_USBPD_Adc_MeasureVbus(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  cy_en_usbpd_adc_input_t input);
                                

void Cy_USBPD_Vbus_SetDetachParams(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t adcInp);

void Cy_USBPD_Adc_IntrHandler(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_vbus_ctrl_functions */


/**
* \addtogroup group_usbpd_vbus_ctrl_functions
* \{
*/

bool Cy_USBPD_V5V_IsSupplyOn(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_VConn_Enable(cy_stc_usbpd_context_t *context, uint8_t channel);

cy_en_usbpd_status_t Cy_USBPD_VConn_Disable(cy_stc_usbpd_context_t *context, uint8_t channel);

bool Cy_USBPD_VConn_IsPresent(cy_stc_usbpd_context_t *context, uint8_t channel);

bool Cy_USBPD_VbusDiv_To_AMuxDiscon(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsRxEnable(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsRxDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_FrsRx_IntrHandler(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsTxEnable(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsTxDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_GdrvRstEdgeDet(cy_stc_usbpd_context_t *context, bool pgdoType);

void Cy_USBPD_Vbus_RemoveIntrnlFbDiv(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_GdrvIsSnkFetOn(cy_stc_usbpd_context_t *context);

/** \cond DOXYGEN_HIDE */
void Cy_USBPD_Vbus_GdrvPfetOn(cy_stc_usbpd_context_t *context, bool turnOnSeq);

void Cy_USBPD_Vbus_GdrvPfetOff(cy_stc_usbpd_context_t *context, bool turnOffSeq);

void Cy_USBPD_Vbus_GdrvCfetOn(cy_stc_usbpd_context_t *context, bool turnOnSeq);

void Cy_USBPD_Vbus_GdrvCfetOff(cy_stc_usbpd_context_t *context, bool turnOffSeq);

void Cy_USBPD_Vbus_DischargeOn(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_DischargeOff(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VbusIn_DischargeOn(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VbusIn_DischargeOff(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_LoadChangeISR_En(cy_stc_usbpd_context_t *context, uint32_t cur, 
                                   uint8_t filter, cy_cb_usbpd_vbus_load_chg_t cbk);

/** \endcond */

void Cy_USBPD_Vbus_Mon_SetDivider(cy_stc_usbpd_context_t *context, uint8_t divider);

/** \} group_usbpd_vbus_ctrl_functions */

/**
* \addtogroup group_usbpd_vbus_ctrl_functions
* \{
*/

/** \cond DOXYGEN_HIDE */
uint8_t Cy_USBPD_SysFault_OcpEn(cy_stc_usbpd_context_t *context, uint32_t cur, cy_cb_vbus_fault_t cbk);

uint8_t Cy_USBPD_SysFault_OcpDis(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VbusOcpHandler(cy_stc_usbpd_context_t *context);

uint8_t Cy_USBPD_SysFault_ScpEn(cy_stc_usbpd_context_t *context, uint32_t cur, cy_cb_vbus_fault_t cbk);

uint8_t Cy_USBPD_SysFault_ScpDis(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VbusScpHandler(cy_stc_usbpd_context_t *context);

uint8_t Cy_USBPD_SysFault_RcpEn(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cbk);

uint8_t Cy_USBPD_SysFault_RcpDis(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VbusRcpHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vconn_OcpEn(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vconn_OcpDis(cy_stc_usbpd_context_t *context);

uint16_t Cy_USBPD_Vbus_MeasureCur(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_OcpEn(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vbus_OcpDis(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbus_OvpEn(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb, bool pctrl);

void Cy_USBPD_Fault_Vbus_OvpDis(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbus_UvpEn(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb, bool pctrl);

void Cy_USBPD_Fault_Vbus_UvpDis(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbus_ScpEn(cy_stc_usbpd_context_t *context, uint32_t vsense, uint8_t filterSel, bool pctrl);

void Cy_USBPD_Fault_Vbus_ScpDis(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbus_RcpEn(cy_stc_usbpd_context_t *context, bool pctrl, uint8_t csaDetEn, uint8_t cmpDeEn, uint8_t ovpDetEn);

void Cy_USBPD_Fault_Vbus_RcpDis(cy_stc_usbpd_context_t *context, bool pctrl);
/** \endcond */

void Cy_USBPD_Fault_FetAutoModeEn(cy_stc_usbpd_context_t *context, bool pctrl, cy_en_usbpd_vbus_filter_id_t filterIndex);

void Cy_USBPD_Fault_FetAutoModeDis(cy_stc_usbpd_context_t *context, bool pctrl, cy_en_usbpd_vbus_filter_id_t filterIndex);

/** \cond DOXYGEN_HIDE */
void Cy_USBPD_Fault_CcSbuSetCB(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_CcOvp_SetPending(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_SetCsaRsense(cy_stc_usbpd_context_t *context, uint8_t rsense);

bool Cy_USBPD_Vbus_CompGetStatus(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbus_filter_id_t id, bool isFiltered);

void Cy_USBPD_Fault_VconnOcp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VbusOvp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VbusUvp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_CcOvp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_SbuOvp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_V5vChangeDetectHandler(cy_stc_usbpd_context_t *context);
/** \endcond */
/** \} group_usbpd_vbus_ctrl_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_VBUS_CTRL_H_ */

/** \} group_usbpd_vbus_ctrl */

/* [] END OF FILE */

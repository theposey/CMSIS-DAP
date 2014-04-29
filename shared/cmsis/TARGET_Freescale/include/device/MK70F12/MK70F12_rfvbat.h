/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_RFVBAT_REGISTERS_H__
#define __HW_RFVBAT_REGISTERS_H__

#include "regs.h"

/*
 * MK70F12 RFVBAT
 *
 * VBAT register file
 *
 * Registers defined in this header file:
 * - HW_RFVBAT_REGn - VBAT register file register
 *
 * - hw_rfvbat_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_RFVBAT_BASE
#define HW_RFVBAT_INSTANCE_COUNT (1U) //!< Number of instances of the RFVBAT module.
#define REGS_RFVBAT_BASE (0x4003E000U) //!< Base address for RFVBAT.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_RFVBAT_REGn - VBAT register file register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RFVBAT_REGn - VBAT register file register (RW)
 *
 * Reset value: 0x00000000U
 *
 * Each register can be accessed as 8-, 16-, or 32-bits.
 */
typedef union _hw_rfvbat_regn
{
    uint32_t U;
    struct _hw_rfvbat_regn_bitfields
    {
        uint32_t LL : 8;               //!< [7:0]
        uint32_t LH : 8;               //!< [15:8]
        uint32_t HL : 8;               //!< [23:16]
        uint32_t HH : 8;               //!< [31:24]
    } B;
} hw_rfvbat_regn_t;
#endif

/*!
 * @name Constants and macros for entire RFVBAT_REGn register
 */
//@{
#define HW_RFVBAT_REGn_COUNT (8U)

#define HW_RFVBAT_REGn_ADDR(n)   (REGS_RFVBAT_BASE + 0x0U + (0x4U * n))

#ifndef __LANGUAGE_ASM__
#define HW_RFVBAT_REGn(n)        (*(__IO hw_rfvbat_regn_t *) HW_RFVBAT_REGn_ADDR(n))
#define HW_RFVBAT_REGn_RD(n)     (HW_RFVBAT_REGn(n).U)
#define HW_RFVBAT_REGn_WR(n, v)  (HW_RFVBAT_REGn(n).U = (v))
#define HW_RFVBAT_REGn_SET(n, v) (HW_RFVBAT_REGn_WR(n, HW_RFVBAT_REGn_RD(n) |  (v)))
#define HW_RFVBAT_REGn_CLR(n, v) (HW_RFVBAT_REGn_WR(n, HW_RFVBAT_REGn_RD(n) & ~(v)))
#define HW_RFVBAT_REGn_TOG(n, v) (HW_RFVBAT_REGn_WR(n, HW_RFVBAT_REGn_RD(n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual RFVBAT_REGn bitfields
 */

/*!
 * @name Register RFVBAT_REGn, field LL[7:0] (RW)
 */
//@{
#define BP_RFVBAT_REGn_LL    (0U)          //!< Bit position for RFVBAT_REGn_LL.
#define BM_RFVBAT_REGn_LL    (0x000000FFU) //!< Bit mask for RFVBAT_REGn_LL.
#define BS_RFVBAT_REGn_LL    (8U)          //!< Bit field size in bits for RFVBAT_REGn_LL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RFVBAT_REGn_LL field.
#define BR_RFVBAT_REGn_LL(n) (HW_RFVBAT_REGn(n).B.LL)
#endif

//! @brief Format value for bitfield RFVBAT_REGn_LL.
#define BF_RFVBAT_REGn_LL(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_RFVBAT_REGn_LL), uint32_t) & BM_RFVBAT_REGn_LL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LL field to a new value.
#define BW_RFVBAT_REGn_LL(n, v) (HW_RFVBAT_REGn_WR(n, (HW_RFVBAT_REGn_RD(n) & ~BM_RFVBAT_REGn_LL) | BF_RFVBAT_REGn_LL(v)))
#endif
//@}

/*!
 * @name Register RFVBAT_REGn, field LH[15:8] (RW)
 */
//@{
#define BP_RFVBAT_REGn_LH    (8U)          //!< Bit position for RFVBAT_REGn_LH.
#define BM_RFVBAT_REGn_LH    (0x0000FF00U) //!< Bit mask for RFVBAT_REGn_LH.
#define BS_RFVBAT_REGn_LH    (8U)          //!< Bit field size in bits for RFVBAT_REGn_LH.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RFVBAT_REGn_LH field.
#define BR_RFVBAT_REGn_LH(n) (HW_RFVBAT_REGn(n).B.LH)
#endif

//! @brief Format value for bitfield RFVBAT_REGn_LH.
#define BF_RFVBAT_REGn_LH(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_RFVBAT_REGn_LH), uint32_t) & BM_RFVBAT_REGn_LH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LH field to a new value.
#define BW_RFVBAT_REGn_LH(n, v) (HW_RFVBAT_REGn_WR(n, (HW_RFVBAT_REGn_RD(n) & ~BM_RFVBAT_REGn_LH) | BF_RFVBAT_REGn_LH(v)))
#endif
//@}

/*!
 * @name Register RFVBAT_REGn, field HL[23:16] (RW)
 */
//@{
#define BP_RFVBAT_REGn_HL    (16U)         //!< Bit position for RFVBAT_REGn_HL.
#define BM_RFVBAT_REGn_HL    (0x00FF0000U) //!< Bit mask for RFVBAT_REGn_HL.
#define BS_RFVBAT_REGn_HL    (8U)          //!< Bit field size in bits for RFVBAT_REGn_HL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RFVBAT_REGn_HL field.
#define BR_RFVBAT_REGn_HL(n) (HW_RFVBAT_REGn(n).B.HL)
#endif

//! @brief Format value for bitfield RFVBAT_REGn_HL.
#define BF_RFVBAT_REGn_HL(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_RFVBAT_REGn_HL), uint32_t) & BM_RFVBAT_REGn_HL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HL field to a new value.
#define BW_RFVBAT_REGn_HL(n, v) (HW_RFVBAT_REGn_WR(n, (HW_RFVBAT_REGn_RD(n) & ~BM_RFVBAT_REGn_HL) | BF_RFVBAT_REGn_HL(v)))
#endif
//@}

/*!
 * @name Register RFVBAT_REGn, field HH[31:24] (RW)
 */
//@{
#define BP_RFVBAT_REGn_HH    (24U)         //!< Bit position for RFVBAT_REGn_HH.
#define BM_RFVBAT_REGn_HH    (0xFF000000U) //!< Bit mask for RFVBAT_REGn_HH.
#define BS_RFVBAT_REGn_HH    (8U)          //!< Bit field size in bits for RFVBAT_REGn_HH.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RFVBAT_REGn_HH field.
#define BR_RFVBAT_REGn_HH(n) (HW_RFVBAT_REGn(n).B.HH)
#endif

//! @brief Format value for bitfield RFVBAT_REGn_HH.
#define BF_RFVBAT_REGn_HH(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_RFVBAT_REGn_HH), uint32_t) & BM_RFVBAT_REGn_HH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HH field to a new value.
#define BW_RFVBAT_REGn_HH(n, v) (HW_RFVBAT_REGn_WR(n, (HW_RFVBAT_REGn_RD(n) & ~BM_RFVBAT_REGn_HH) | BF_RFVBAT_REGn_HH(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_rfvbat_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All RFVBAT module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_rfvbat
{
    __IO hw_rfvbat_regn_t REGn[8];         //!< [0x0] VBAT register file register
} hw_rfvbat_t;
#pragma pack()

//! @brief Macro to access all RFVBAT registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_RFVBAT</code>.
#define HW_RFVBAT      (*(hw_rfvbat_t *) REGS_RFVBAT_BASE)
#endif

#endif // __HW_RFVBAT_REGISTERS_H__
// v22/130726/0.9
// EOF

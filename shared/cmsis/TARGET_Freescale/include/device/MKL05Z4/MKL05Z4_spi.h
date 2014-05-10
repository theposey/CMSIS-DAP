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
#ifndef __HW_SPI_REGISTERS_H__
#define __HW_SPI_REGISTERS_H__

#include "MKL05Z4.h"
#include "fsl_bitband.h"

/*
 * MKL05Z4 SPI
 *
 * Serial Peripheral Interface
 *
 * Registers defined in this header file:
 * - HW_SPI_C1 - SPI control register 1
 * - HW_SPI_C2 - SPI control register 2
 * - HW_SPI_BR - SPI baud rate register
 * - HW_SPI_S - SPI status register
 * - HW_SPI_D - SPI data register
 * - HW_SPI_M - SPI match register
 *
 * - hw_spi_t - Struct containing all module registers.
 */

#define HW_SPI_INSTANCE_COUNT (1U) /*!< Number of instances of the SPI module. */

/*******************************************************************************
 * HW_SPI_C1 - SPI control register 1
 ******************************************************************************/

/*!
 * @brief HW_SPI_C1 - SPI control register 1 (RW)
 *
 * Reset value: 0x04U
 *
 * This read/write register includes the SPI enable control, interrupt enables,
 * and configuration options.
 */
typedef union _hw_spi_c1
{
    uint8_t U;
    struct _hw_spi_c1_bitfields
    {
        uint8_t LSBFE : 1;             /*!< [0] LSB first (shifter direction) */
        uint8_t SSOE : 1;              /*!< [1] Slave select output enable */
        uint8_t CPHA : 1;              /*!< [2] Clock phase */
        uint8_t CPOL : 1;              /*!< [3] Clock polarity */
        uint8_t MSTR : 1;              /*!< [4] Master/slave mode select */
        uint8_t SPTIE : 1;             /*!< [5] SPI transmit interrupt enable */
        uint8_t SPE : 1;               /*!< [6] SPI system enable */
        uint8_t SPIE : 1;              /*!< [7] SPI interrupt enable: for SPRF and MODF */
    } B;
} hw_spi_c1_t;

/*!
 * @name Constants and macros for entire SPI_C1 register
 */
/*@{*/
#define HW_SPI_C1_ADDR(x)        ((x) + 0x0U)

#define HW_SPI_C1(x)             (*(__IO hw_spi_c1_t *) HW_SPI_C1_ADDR(x))
#define HW_SPI_C1_RD(x)          (HW_SPI_C1(x).U)
#define HW_SPI_C1_WR(x, v)       (HW_SPI_C1(x).U = (v))
#define HW_SPI_C1_SET(x, v)      (BME_OR8(HW_SPI_C1_ADDR(x), (uint8_t)(v)))
#define HW_SPI_C1_CLR(x, v)      (BME_AND8(HW_SPI_C1_ADDR(x), (uint8_t)(~(v))))
#define HW_SPI_C1_TOG(x, v)      (BME_XOR8(HW_SPI_C1_ADDR(x), (uint8_t)(v)))
/*@}*/

/*
 * Constants & macros for individual SPI_C1 bitfields
 */

/*!
 * @name Register SPI_C1, field LSBFE[0] (RW)
 *
 * This bit does not affect the position of the MSB and LSB in the data
 * register. Reads and writes of the data register always have the MSB in bit 7.
 *
 * Values:
 * - 0 - SPI serial data transfers start with most significant bit
 * - 1 - SPI serial data transfers start with least significant bit
 */
/*@{*/
#define BP_SPI_C1_LSBFE      (0U)          /*!< Bit position for SPI_C1_LSBFE. */
#define BM_SPI_C1_LSBFE      (0x01U)       /*!< Bit mask for SPI_C1_LSBFE. */
#define BS_SPI_C1_LSBFE      (1U)          /*!< Bit field size in bits for SPI_C1_LSBFE. */

/*! @brief Read current value of the SPI_C1_LSBFE field. */
#define BR_SPI_C1_LSBFE(x)   (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_LSBFE, BS_SPI_C1_LSBFE))

/*! @brief Format value for bitfield SPI_C1_LSBFE. */
#define BF_SPI_C1_LSBFE(v)   ((uint8_t)((uint8_t)(v) << BP_SPI_C1_LSBFE) & BM_SPI_C1_LSBFE)

/*! @brief Set the LSBFE field to a new value. */
#define BW_SPI_C1_LSBFE(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_LSBFE), BP_SPI_C1_LSBFE, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field SSOE[1] (RW)
 *
 * This bit is used in combination with the mode fault enable (MODFEN) bit in
 * the C2 register and the master/slave (MSTR) control bit to determine the
 * function of the SS pin.
 *
 * Values:
 * - 0 - When MODFEN is 0: In master mode, SS pin function is general-purpose
 *     I/O (not SPI). In slave mode, SS pin function is slave select input. When
 *     MODFEN is 1: In master mode, SS pin function is SS input for mode fault. In
 *     slave mode, SS pin function is slave select input.
 * - 1 - When MODFEN is 0: In master mode, SS pin function is general-purpose
 *     I/O (not SPI). In slave mode, SS pin function is slave select input. When
 *     MODFEN is 1: In master mode, SS pin function is automatic SS output. In
 *     slave mode: SS pin function is slave select input.
 */
/*@{*/
#define BP_SPI_C1_SSOE       (1U)          /*!< Bit position for SPI_C1_SSOE. */
#define BM_SPI_C1_SSOE       (0x02U)       /*!< Bit mask for SPI_C1_SSOE. */
#define BS_SPI_C1_SSOE       (1U)          /*!< Bit field size in bits for SPI_C1_SSOE. */

/*! @brief Read current value of the SPI_C1_SSOE field. */
#define BR_SPI_C1_SSOE(x)    (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_SSOE, BS_SPI_C1_SSOE))

/*! @brief Format value for bitfield SPI_C1_SSOE. */
#define BF_SPI_C1_SSOE(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_C1_SSOE) & BM_SPI_C1_SSOE)

/*! @brief Set the SSOE field to a new value. */
#define BW_SPI_C1_SSOE(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_SSOE), BP_SPI_C1_SSOE, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field CPHA[2] (RW)
 *
 * This bit selects one of two clock formats for different kinds of synchronous
 * serial peripheral devices. Refer to the description of "SPI Clock Formats" for
 * details.
 *
 * Values:
 * - 0 - First edge on SPSCK occurs at the middle of the first cycle of a data
 *     transfer
 * - 1 - First edge on SPSCK occurs at the start of the first cycle of a data
 *     transfer
 */
/*@{*/
#define BP_SPI_C1_CPHA       (2U)          /*!< Bit position for SPI_C1_CPHA. */
#define BM_SPI_C1_CPHA       (0x04U)       /*!< Bit mask for SPI_C1_CPHA. */
#define BS_SPI_C1_CPHA       (1U)          /*!< Bit field size in bits for SPI_C1_CPHA. */

/*! @brief Read current value of the SPI_C1_CPHA field. */
#define BR_SPI_C1_CPHA(x)    (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_CPHA, BS_SPI_C1_CPHA))

/*! @brief Format value for bitfield SPI_C1_CPHA. */
#define BF_SPI_C1_CPHA(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_C1_CPHA) & BM_SPI_C1_CPHA)

/*! @brief Set the CPHA field to a new value. */
#define BW_SPI_C1_CPHA(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_CPHA), BP_SPI_C1_CPHA, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field CPOL[3] (RW)
 *
 * This bit selects an inverted or non-inverted SPI clock. To transmit data
 * between SPI modules, the SPI modules must have identical CPOL values. This bit
 * effectively places an inverter in series with the clock signal either from a
 * master SPI device or to a slave SPI device. Refer to the description of "SPI Clock
 * Formats" for details.
 *
 * Values:
 * - 0 - Active-high SPI clock (idles low)
 * - 1 - Active-low SPI clock (idles high)
 */
/*@{*/
#define BP_SPI_C1_CPOL       (3U)          /*!< Bit position for SPI_C1_CPOL. */
#define BM_SPI_C1_CPOL       (0x08U)       /*!< Bit mask for SPI_C1_CPOL. */
#define BS_SPI_C1_CPOL       (1U)          /*!< Bit field size in bits for SPI_C1_CPOL. */

/*! @brief Read current value of the SPI_C1_CPOL field. */
#define BR_SPI_C1_CPOL(x)    (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_CPOL, BS_SPI_C1_CPOL))

/*! @brief Format value for bitfield SPI_C1_CPOL. */
#define BF_SPI_C1_CPOL(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_C1_CPOL) & BM_SPI_C1_CPOL)

/*! @brief Set the CPOL field to a new value. */
#define BW_SPI_C1_CPOL(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_CPOL), BP_SPI_C1_CPOL, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field MSTR[4] (RW)
 *
 * This bit selects master or slave mode operation.
 *
 * Values:
 * - 0 - SPI module configured as a slave SPI device
 * - 1 - SPI module configured as a master SPI device
 */
/*@{*/
#define BP_SPI_C1_MSTR       (4U)          /*!< Bit position for SPI_C1_MSTR. */
#define BM_SPI_C1_MSTR       (0x10U)       /*!< Bit mask for SPI_C1_MSTR. */
#define BS_SPI_C1_MSTR       (1U)          /*!< Bit field size in bits for SPI_C1_MSTR. */

/*! @brief Read current value of the SPI_C1_MSTR field. */
#define BR_SPI_C1_MSTR(x)    (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_MSTR, BS_SPI_C1_MSTR))

/*! @brief Format value for bitfield SPI_C1_MSTR. */
#define BF_SPI_C1_MSTR(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_C1_MSTR) & BM_SPI_C1_MSTR)

/*! @brief Set the MSTR field to a new value. */
#define BW_SPI_C1_MSTR(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_MSTR), BP_SPI_C1_MSTR, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field SPTIE[5] (RW)
 *
 * This is the interrupt enable bit for SPI transmit buffer empty (SPTEF). An
 * interrupt occurs when the SPI transmit buffer is empty (SPTEF is set).
 *
 * Values:
 * - 0 - Interrupts from SPTEF inhibited (use polling)
 * - 1 - When SPTEF is 1, hardware interrupt requested
 */
/*@{*/
#define BP_SPI_C1_SPTIE      (5U)          /*!< Bit position for SPI_C1_SPTIE. */
#define BM_SPI_C1_SPTIE      (0x20U)       /*!< Bit mask for SPI_C1_SPTIE. */
#define BS_SPI_C1_SPTIE      (1U)          /*!< Bit field size in bits for SPI_C1_SPTIE. */

/*! @brief Read current value of the SPI_C1_SPTIE field. */
#define BR_SPI_C1_SPTIE(x)   (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_SPTIE, BS_SPI_C1_SPTIE))

/*! @brief Format value for bitfield SPI_C1_SPTIE. */
#define BF_SPI_C1_SPTIE(v)   ((uint8_t)((uint8_t)(v) << BP_SPI_C1_SPTIE) & BM_SPI_C1_SPTIE)

/*! @brief Set the SPTIE field to a new value. */
#define BW_SPI_C1_SPTIE(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_SPTIE), BP_SPI_C1_SPTIE, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field SPE[6] (RW)
 *
 * This bit enables the SPI system and dedicates the SPI port pins to SPI system
 * functions. If SPE is cleared, the SPI is disabled and forced into an idle
 * state, and all status bits in the S register are reset.
 *
 * Values:
 * - 0 - SPI system inactive
 * - 1 - SPI system enabled
 */
/*@{*/
#define BP_SPI_C1_SPE        (6U)          /*!< Bit position for SPI_C1_SPE. */
#define BM_SPI_C1_SPE        (0x40U)       /*!< Bit mask for SPI_C1_SPE. */
#define BS_SPI_C1_SPE        (1U)          /*!< Bit field size in bits for SPI_C1_SPE. */

/*! @brief Read current value of the SPI_C1_SPE field. */
#define BR_SPI_C1_SPE(x)     (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_SPE, BS_SPI_C1_SPE))

/*! @brief Format value for bitfield SPI_C1_SPE. */
#define BF_SPI_C1_SPE(v)     ((uint8_t)((uint8_t)(v) << BP_SPI_C1_SPE) & BM_SPI_C1_SPE)

/*! @brief Set the SPE field to a new value. */
#define BW_SPI_C1_SPE(x, v)  (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_SPE), BP_SPI_C1_SPE, 1))
/*@}*/

/*!
 * @name Register SPI_C1, field SPIE[7] (RW)
 *
 * This bit enables the interrupt for SPI receive buffer full (SPRF) and mode
 * fault (MODF) events.
 *
 * Values:
 * - 0 - Interrupts from SPRF and MODF are inhibited-use polling
 * - 1 - Request a hardware interrupt when SPRF or MODF is 1
 */
/*@{*/
#define BP_SPI_C1_SPIE       (7U)          /*!< Bit position for SPI_C1_SPIE. */
#define BM_SPI_C1_SPIE       (0x80U)       /*!< Bit mask for SPI_C1_SPIE. */
#define BS_SPI_C1_SPIE       (1U)          /*!< Bit field size in bits for SPI_C1_SPIE. */

/*! @brief Read current value of the SPI_C1_SPIE field. */
#define BR_SPI_C1_SPIE(x)    (BME_UBFX8(HW_SPI_C1_ADDR(x), BP_SPI_C1_SPIE, BS_SPI_C1_SPIE))

/*! @brief Format value for bitfield SPI_C1_SPIE. */
#define BF_SPI_C1_SPIE(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_C1_SPIE) & BM_SPI_C1_SPIE)

/*! @brief Set the SPIE field to a new value. */
#define BW_SPI_C1_SPIE(x, v) (BME_BFI8(HW_SPI_C1_ADDR(x), ((uint8_t)(v) << BP_SPI_C1_SPIE), BP_SPI_C1_SPIE, 1))
/*@}*/

/*******************************************************************************
 * HW_SPI_C2 - SPI control register 2
 ******************************************************************************/

/*!
 * @brief HW_SPI_C2 - SPI control register 2 (RW)
 *
 * Reset value: 0x00U
 *
 * This read/write register is used to control optional features of the SPI
 * system. Bit 6 is not implemented and always reads 0.
 */
typedef union _hw_spi_c2
{
    uint8_t U;
    struct _hw_spi_c2_bitfields
    {
        uint8_t SPC0 : 1;              /*!< [0] SPI pin control 0 */
        uint8_t SPISWAI : 1;           /*!< [1] SPI stop in wait mode */
        uint8_t RXDMAE : 1;            /*!< [2] Receive DMA enable */
        uint8_t BIDIROE : 1;           /*!< [3] Bidirectional mode output enable */
        uint8_t MODFEN : 1;            /*!< [4] Master mode-fault function enable */
        uint8_t TXDMAE : 1;            /*!< [5] Transmit DMA enable */
        uint8_t RESERVED0 : 1;         /*!< [6]  */
        uint8_t SPMIE : 1;             /*!< [7] SPI match interrupt enable */
    } B;
} hw_spi_c2_t;

/*!
 * @name Constants and macros for entire SPI_C2 register
 */
/*@{*/
#define HW_SPI_C2_ADDR(x)        ((x) + 0x1U)

#define HW_SPI_C2(x)             (*(__IO hw_spi_c2_t *) HW_SPI_C2_ADDR(x))
#define HW_SPI_C2_RD(x)          (HW_SPI_C2(x).U)
#define HW_SPI_C2_WR(x, v)       (HW_SPI_C2(x).U = (v))
#define HW_SPI_C2_SET(x, v)      (BME_OR8(HW_SPI_C2_ADDR(x), (uint8_t)(v)))
#define HW_SPI_C2_CLR(x, v)      (BME_AND8(HW_SPI_C2_ADDR(x), (uint8_t)(~(v))))
#define HW_SPI_C2_TOG(x, v)      (BME_XOR8(HW_SPI_C2_ADDR(x), (uint8_t)(v)))
/*@}*/

/*
 * Constants & macros for individual SPI_C2 bitfields
 */

/*!
 * @name Register SPI_C2, field SPC0[0] (RW)
 *
 * This bit enables bidirectional pin configurations.
 *
 * Values:
 * - 0 - SPI uses separate pins for data input and data output (pin mode is
 *     normal). In master mode of operation: MISO is master in and MOSI is master
 *     out. In slave mode of operation: MISO is slave out and MOSI is slave in.
 * - 1 - SPI configured for single-wire bidirectional operation (pin mode is
 *     bidirectional). In master mode of operation: MISO is not used by SPI; MOSI is
 *     master in when BIDIROE is 0 or master I/O when BIDIROE is 1. In slave
 *     mode of operation: MISO is slave in when BIDIROE is 0 or slave I/O when
 *     BIDIROE is 1; MOSI is not used by SPI.
 */
/*@{*/
#define BP_SPI_C2_SPC0       (0U)          /*!< Bit position for SPI_C2_SPC0. */
#define BM_SPI_C2_SPC0       (0x01U)       /*!< Bit mask for SPI_C2_SPC0. */
#define BS_SPI_C2_SPC0       (1U)          /*!< Bit field size in bits for SPI_C2_SPC0. */

/*! @brief Read current value of the SPI_C2_SPC0 field. */
#define BR_SPI_C2_SPC0(x)    (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_SPC0, BS_SPI_C2_SPC0))

/*! @brief Format value for bitfield SPI_C2_SPC0. */
#define BF_SPI_C2_SPC0(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_C2_SPC0) & BM_SPI_C2_SPC0)

/*! @brief Set the SPC0 field to a new value. */
#define BW_SPI_C2_SPC0(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_SPC0), BP_SPI_C2_SPC0, 1))
/*@}*/

/*!
 * @name Register SPI_C2, field SPISWAI[1] (RW)
 *
 * This bit is used for power conservation while the device is in wait mode.
 *
 * Values:
 * - 0 - SPI clocks continue to operate in wait mode
 * - 1 - SPI clocks stop when the MCU enters wait mode
 */
/*@{*/
#define BP_SPI_C2_SPISWAI    (1U)          /*!< Bit position for SPI_C2_SPISWAI. */
#define BM_SPI_C2_SPISWAI    (0x02U)       /*!< Bit mask for SPI_C2_SPISWAI. */
#define BS_SPI_C2_SPISWAI    (1U)          /*!< Bit field size in bits for SPI_C2_SPISWAI. */

/*! @brief Read current value of the SPI_C2_SPISWAI field. */
#define BR_SPI_C2_SPISWAI(x) (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_SPISWAI, BS_SPI_C2_SPISWAI))

/*! @brief Format value for bitfield SPI_C2_SPISWAI. */
#define BF_SPI_C2_SPISWAI(v) ((uint8_t)((uint8_t)(v) << BP_SPI_C2_SPISWAI) & BM_SPI_C2_SPISWAI)

/*! @brief Set the SPISWAI field to a new value. */
#define BW_SPI_C2_SPISWAI(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_SPISWAI), BP_SPI_C2_SPISWAI, 1))
/*@}*/

/*!
 * @name Register SPI_C2, field RXDMAE[2] (RW)
 *
 * This is the enable bit for a receive DMA request. When this bit is set to 1,
 * a receive DMA request is asserted when both SPRF and SPE are set, and the
 * interrupt from SPRF is disabled.
 *
 * Values:
 * - 0 - DMA request for receive is disabled and interrupt from SPRF is allowed
 * - 1 - DMA request for receive is enabled and interrupt from SPRF is disabled
 */
/*@{*/
#define BP_SPI_C2_RXDMAE     (2U)          /*!< Bit position for SPI_C2_RXDMAE. */
#define BM_SPI_C2_RXDMAE     (0x04U)       /*!< Bit mask for SPI_C2_RXDMAE. */
#define BS_SPI_C2_RXDMAE     (1U)          /*!< Bit field size in bits for SPI_C2_RXDMAE. */

/*! @brief Read current value of the SPI_C2_RXDMAE field. */
#define BR_SPI_C2_RXDMAE(x)  (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_RXDMAE, BS_SPI_C2_RXDMAE))

/*! @brief Format value for bitfield SPI_C2_RXDMAE. */
#define BF_SPI_C2_RXDMAE(v)  ((uint8_t)((uint8_t)(v) << BP_SPI_C2_RXDMAE) & BM_SPI_C2_RXDMAE)

/*! @brief Set the RXDMAE field to a new value. */
#define BW_SPI_C2_RXDMAE(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_RXDMAE), BP_SPI_C2_RXDMAE, 1))
/*@}*/

/*!
 * @name Register SPI_C2, field BIDIROE[3] (RW)
 *
 * When bidirectional mode is enabled, because SPI pin control 0 (SPC0) is set
 * to 1, the BIDIROE bit determines whether the SPI data output driver is enabled
 * to the single bidirectional SPI I/O pin. Depending on whether the SPI is
 * configured as a master or a slave, it uses the MOSI (MOMI) or MISO (SISO) pin,
 * respectively, as the single SPI data I/O pin. When SPC0 is 0, BIDIROE has no
 * meaning or effect.
 *
 * Values:
 * - 0 - Output driver disabled so SPI data I/O pin acts as an input
 * - 1 - SPI I/O pin enabled as an output
 */
/*@{*/
#define BP_SPI_C2_BIDIROE    (3U)          /*!< Bit position for SPI_C2_BIDIROE. */
#define BM_SPI_C2_BIDIROE    (0x08U)       /*!< Bit mask for SPI_C2_BIDIROE. */
#define BS_SPI_C2_BIDIROE    (1U)          /*!< Bit field size in bits for SPI_C2_BIDIROE. */

/*! @brief Read current value of the SPI_C2_BIDIROE field. */
#define BR_SPI_C2_BIDIROE(x) (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_BIDIROE, BS_SPI_C2_BIDIROE))

/*! @brief Format value for bitfield SPI_C2_BIDIROE. */
#define BF_SPI_C2_BIDIROE(v) ((uint8_t)((uint8_t)(v) << BP_SPI_C2_BIDIROE) & BM_SPI_C2_BIDIROE)

/*! @brief Set the BIDIROE field to a new value. */
#define BW_SPI_C2_BIDIROE(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_BIDIROE), BP_SPI_C2_BIDIROE, 1))
/*@}*/

/*!
 * @name Register SPI_C2, field MODFEN[4] (RW)
 *
 * When the SPI is configured for slave mode, this bit has no meaning or effect.
 * (The SS pin is the slave select input.) In master mode, this bit determines
 * how the SS pin is used. For details, refer to the description of the SSOE bit
 * in the C1 register.
 *
 * Values:
 * - 0 - Mode fault function disabled, master SS pin reverts to general-purpose
 *     I/O not controlled by SPI
 * - 1 - Mode fault function enabled, master SS pin acts as the mode fault input
 *     or the slave select output
 */
/*@{*/
#define BP_SPI_C2_MODFEN     (4U)          /*!< Bit position for SPI_C2_MODFEN. */
#define BM_SPI_C2_MODFEN     (0x10U)       /*!< Bit mask for SPI_C2_MODFEN. */
#define BS_SPI_C2_MODFEN     (1U)          /*!< Bit field size in bits for SPI_C2_MODFEN. */

/*! @brief Read current value of the SPI_C2_MODFEN field. */
#define BR_SPI_C2_MODFEN(x)  (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_MODFEN, BS_SPI_C2_MODFEN))

/*! @brief Format value for bitfield SPI_C2_MODFEN. */
#define BF_SPI_C2_MODFEN(v)  ((uint8_t)((uint8_t)(v) << BP_SPI_C2_MODFEN) & BM_SPI_C2_MODFEN)

/*! @brief Set the MODFEN field to a new value. */
#define BW_SPI_C2_MODFEN(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_MODFEN), BP_SPI_C2_MODFEN, 1))
/*@}*/

/*!
 * @name Register SPI_C2, field TXDMAE[5] (RW)
 *
 * This bit enables a transmit DMA request. When this bit is set to 1, a
 * transmit DMA request is asserted when both SPTEF and SPE are set, and the interrupt
 * from SPTEF is disabled.
 *
 * Values:
 * - 0 - DMA request for transmit is disabled and interrupt from SPTEF is allowed
 * - 1 - DMA request for transmit is enabled and interrupt from SPTEF is disabled
 */
/*@{*/
#define BP_SPI_C2_TXDMAE     (5U)          /*!< Bit position for SPI_C2_TXDMAE. */
#define BM_SPI_C2_TXDMAE     (0x20U)       /*!< Bit mask for SPI_C2_TXDMAE. */
#define BS_SPI_C2_TXDMAE     (1U)          /*!< Bit field size in bits for SPI_C2_TXDMAE. */

/*! @brief Read current value of the SPI_C2_TXDMAE field. */
#define BR_SPI_C2_TXDMAE(x)  (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_TXDMAE, BS_SPI_C2_TXDMAE))

/*! @brief Format value for bitfield SPI_C2_TXDMAE. */
#define BF_SPI_C2_TXDMAE(v)  ((uint8_t)((uint8_t)(v) << BP_SPI_C2_TXDMAE) & BM_SPI_C2_TXDMAE)

/*! @brief Set the TXDMAE field to a new value. */
#define BW_SPI_C2_TXDMAE(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_TXDMAE), BP_SPI_C2_TXDMAE, 1))
/*@}*/

/*!
 * @name Register SPI_C2, field SPMIE[7] (RW)
 *
 * This is the interrupt enable bit for the SPI receive data buffer hardware
 * match (SPMF) function.
 *
 * Values:
 * - 0 - Interrupts from SPMF inhibited (use polling)
 * - 1 - When SPMF is 1, requests a hardware interrupt
 */
/*@{*/
#define BP_SPI_C2_SPMIE      (7U)          /*!< Bit position for SPI_C2_SPMIE. */
#define BM_SPI_C2_SPMIE      (0x80U)       /*!< Bit mask for SPI_C2_SPMIE. */
#define BS_SPI_C2_SPMIE      (1U)          /*!< Bit field size in bits for SPI_C2_SPMIE. */

/*! @brief Read current value of the SPI_C2_SPMIE field. */
#define BR_SPI_C2_SPMIE(x)   (BME_UBFX8(HW_SPI_C2_ADDR(x), BP_SPI_C2_SPMIE, BS_SPI_C2_SPMIE))

/*! @brief Format value for bitfield SPI_C2_SPMIE. */
#define BF_SPI_C2_SPMIE(v)   ((uint8_t)((uint8_t)(v) << BP_SPI_C2_SPMIE) & BM_SPI_C2_SPMIE)

/*! @brief Set the SPMIE field to a new value. */
#define BW_SPI_C2_SPMIE(x, v) (BME_BFI8(HW_SPI_C2_ADDR(x), ((uint8_t)(v) << BP_SPI_C2_SPMIE), BP_SPI_C2_SPMIE, 1))
/*@}*/

/*******************************************************************************
 * HW_SPI_BR - SPI baud rate register
 ******************************************************************************/

/*!
 * @brief HW_SPI_BR - SPI baud rate register (RW)
 *
 * Reset value: 0x00U
 *
 * Use this register to set the prescaler and bit rate divisor for an SPI
 * master. This register may be read or written at any time.
 */
typedef union _hw_spi_br
{
    uint8_t U;
    struct _hw_spi_br_bitfields
    {
        uint8_t SPR : 4;               /*!< [3:0] SPI baud rate divisor */
        uint8_t SPPR : 3;              /*!< [6:4] SPI baud rate prescale divisor */
        uint8_t RESERVED0 : 1;         /*!< [7]  */
    } B;
} hw_spi_br_t;

/*!
 * @name Constants and macros for entire SPI_BR register
 */
/*@{*/
#define HW_SPI_BR_ADDR(x)        ((x) + 0x2U)

#define HW_SPI_BR(x)             (*(__IO hw_spi_br_t *) HW_SPI_BR_ADDR(x))
#define HW_SPI_BR_RD(x)          (HW_SPI_BR(x).U)
#define HW_SPI_BR_WR(x, v)       (HW_SPI_BR(x).U = (v))
#define HW_SPI_BR_SET(x, v)      (BME_OR8(HW_SPI_BR_ADDR(x), (uint8_t)(v)))
#define HW_SPI_BR_CLR(x, v)      (BME_AND8(HW_SPI_BR_ADDR(x), (uint8_t)(~(v))))
#define HW_SPI_BR_TOG(x, v)      (BME_XOR8(HW_SPI_BR_ADDR(x), (uint8_t)(v)))
/*@}*/

/*
 * Constants & macros for individual SPI_BR bitfields
 */

/*!
 * @name Register SPI_BR, field SPR[3:0] (RW)
 *
 * This 4-bit field selects one of nine divisors for the SPI baud rate divider.
 * The input to this divider comes from the SPI baud rate prescaler. Refer to the
 * description of "SPI Baud Rate Generation" for details.
 *
 * Values:
 * - 0000 - Baud rate divisor is 2
 * - 0001 - Baud rate divisor is 4
 * - 0010 - Baud rate divisor is 8
 * - 0011 - Baud rate divisor is 16
 * - 0100 - Baud rate divisor is 32
 * - 0101 - Baud rate divisor is 64
 * - 0110 - Baud rate divisor is 128
 * - 0111 - Baud rate divisor is 256
 * - 1000 - Baud rate divisor is 512
 */
/*@{*/
#define BP_SPI_BR_SPR        (0U)          /*!< Bit position for SPI_BR_SPR. */
#define BM_SPI_BR_SPR        (0x0FU)       /*!< Bit mask for SPI_BR_SPR. */
#define BS_SPI_BR_SPR        (4U)          /*!< Bit field size in bits for SPI_BR_SPR. */

/*! @brief Read current value of the SPI_BR_SPR field. */
#define BR_SPI_BR_SPR(x)     (BME_UBFX8(HW_SPI_BR_ADDR(x), BP_SPI_BR_SPR, BS_SPI_BR_SPR))

/*! @brief Format value for bitfield SPI_BR_SPR. */
#define BF_SPI_BR_SPR(v)     ((uint8_t)((uint8_t)(v) << BP_SPI_BR_SPR) & BM_SPI_BR_SPR)

/*! @brief Set the SPR field to a new value. */
#define BW_SPI_BR_SPR(x, v)  (BME_BFI8(HW_SPI_BR_ADDR(x), ((uint8_t)(v) << BP_SPI_BR_SPR), BP_SPI_BR_SPR, 4))
/*@}*/

/*!
 * @name Register SPI_BR, field SPPR[6:4] (RW)
 *
 * This 3-bit field selects one of eight divisors for the SPI baud rate
 * prescaler. The input to this prescaler is the bus rate clock (BUSCLK). The output of
 * this prescaler drives the input of the SPI baud rate divider. Refer to the
 * description of "SPI Baud Rate Generation" for details.
 *
 * Values:
 * - 000 - Baud rate prescaler divisor is 1
 * - 001 - Baud rate prescaler divisor is 2
 * - 010 - Baud rate prescaler divisor is 3
 * - 011 - Baud rate prescaler divisor is 4
 * - 100 - Baud rate prescaler divisor is 5
 * - 101 - Baud rate prescaler divisor is 6
 * - 110 - Baud rate prescaler divisor is 7
 * - 111 - Baud rate prescaler divisor is 8
 */
/*@{*/
#define BP_SPI_BR_SPPR       (4U)          /*!< Bit position for SPI_BR_SPPR. */
#define BM_SPI_BR_SPPR       (0x70U)       /*!< Bit mask for SPI_BR_SPPR. */
#define BS_SPI_BR_SPPR       (3U)          /*!< Bit field size in bits for SPI_BR_SPPR. */

/*! @brief Read current value of the SPI_BR_SPPR field. */
#define BR_SPI_BR_SPPR(x)    (BME_UBFX8(HW_SPI_BR_ADDR(x), BP_SPI_BR_SPPR, BS_SPI_BR_SPPR))

/*! @brief Format value for bitfield SPI_BR_SPPR. */
#define BF_SPI_BR_SPPR(v)    ((uint8_t)((uint8_t)(v) << BP_SPI_BR_SPPR) & BM_SPI_BR_SPPR)

/*! @brief Set the SPPR field to a new value. */
#define BW_SPI_BR_SPPR(x, v) (BME_BFI8(HW_SPI_BR_ADDR(x), ((uint8_t)(v) << BP_SPI_BR_SPPR), BP_SPI_BR_SPPR, 3))
/*@}*/

/*******************************************************************************
 * HW_SPI_S - SPI status register
 ******************************************************************************/

/*!
 * @brief HW_SPI_S - SPI status register (RO)
 *
 * Reset value: 0x20U
 *
 * This register contains read-only status bits. Writes have no meaning or
 * effect. Bits 3 through 0 are not implemented and always read 0.
 */
typedef union _hw_spi_s
{
    uint8_t U;
    struct _hw_spi_s_bitfields
    {
        uint8_t RESERVED0 : 4;         /*!< [3:0]  */
        uint8_t MODF : 1;              /*!< [4] Master mode fault flag */
        uint8_t SPTEF : 1;             /*!< [5] SPI transmit buffer empty flag */
        uint8_t SPMF : 1;              /*!< [6] SPI match flag */
        uint8_t SPRF : 1;              /*!< [7] SPI read buffer full flag */
    } B;
} hw_spi_s_t;

/*!
 * @name Constants and macros for entire SPI_S register
 */
/*@{*/
#define HW_SPI_S_ADDR(x)         ((x) + 0x3U)

#define HW_SPI_S(x)              (*(__I hw_spi_s_t *) HW_SPI_S_ADDR(x))
#define HW_SPI_S_RD(x)           (HW_SPI_S(x).U)
/*@}*/

/*
 * Constants & macros for individual SPI_S bitfields
 */

/*!
 * @name Register SPI_S, field MODF[4] (RO)
 *
 * MODF is set if the SPI is configured as a master and the slave select input
 * goes low, indicating some other SPI device is also configured as a master. The
 * SS pin acts as a mode fault error input only when MSTR is 1, MODFEN is 1, and
 * SSOE is 0; otherwise, MODF will never be set. MODF is cleared by reading MODF
 * while it is 1 and then writing to the SPI control register 1 (C1).
 *
 * Values:
 * - 0 - No mode fault error
 * - 1 - Mode fault error detected
 */
/*@{*/
#define BP_SPI_S_MODF        (4U)          /*!< Bit position for SPI_S_MODF. */
#define BM_SPI_S_MODF        (0x10U)       /*!< Bit mask for SPI_S_MODF. */
#define BS_SPI_S_MODF        (1U)          /*!< Bit field size in bits for SPI_S_MODF. */

/*! @brief Read current value of the SPI_S_MODF field. */
#define BR_SPI_S_MODF(x)     (BME_UBFX8(HW_SPI_S_ADDR(x), BP_SPI_S_MODF, BS_SPI_S_MODF))
/*@}*/

/*!
 * @name Register SPI_S, field SPTEF[5] (RO)
 *
 * This bit is set when the transmit data buffer is empty. When the transmit DMA
 * request is disabled (TXDMAE is 0), SPTEF is cleared by reading the S register
 * with SPTEF set and then writing a data value to the transmit buffer at D. The
 * S register must be read with SPTEF set to 1 before writing data to the D
 * register; otherwise, the D write is ignored. When the transmit DMA request is
 * enabled (TXDMAE is 1), SPTEF is automatically cleared when the DMA transfer for
 * the transmit DMA request is completed (TX DMA Done is asserted). SPTEF is
 * automatically set when all data from the transmit buffer transfers into the transmit
 * shift register. For an idle SPI, data written to D is transferred to the
 * shifter almost immediately so that SPTEF is set within two bus cycles, allowing a
 * second set of data to be queued into the transmit buffer. After completion of
 * the transfer of the data in the shift register, the queued data from the
 * transmit buffer automatically moves to the shifter, and SPTEF is set to indicate
 * that room exists for new data in the transmit buffer. If no new data is waiting
 * in the transmit buffer, SPTEF simply remains set and no data moves from the
 * buffer to the shifter. If a transfer does not stop, the last data that was
 * transmitted is sent out again.
 *
 * Values:
 * - 0 - SPI transmit buffer not empty
 * - 1 - SPI transmit buffer empty
 */
/*@{*/
#define BP_SPI_S_SPTEF       (5U)          /*!< Bit position for SPI_S_SPTEF. */
#define BM_SPI_S_SPTEF       (0x20U)       /*!< Bit mask for SPI_S_SPTEF. */
#define BS_SPI_S_SPTEF       (1U)          /*!< Bit field size in bits for SPI_S_SPTEF. */

/*! @brief Read current value of the SPI_S_SPTEF field. */
#define BR_SPI_S_SPTEF(x)    (BME_UBFX8(HW_SPI_S_ADDR(x), BP_SPI_S_SPTEF, BS_SPI_S_SPTEF))
/*@}*/

/*!
 * @name Register SPI_S, field SPMF[6] (RO)
 *
 * SPMF is set after SPRF is 1 when the value in the receive data buffer matches
 * the value in the M register. To clear the flag, read SPMF when it is set and
 * then write a 1 to it.
 *
 * Values:
 * - 0 - Value in the receive data buffer does not match the value in the M
 *     register
 * - 1 - Value in the receive data buffer matches the value in the M register
 */
/*@{*/
#define BP_SPI_S_SPMF        (6U)          /*!< Bit position for SPI_S_SPMF. */
#define BM_SPI_S_SPMF        (0x40U)       /*!< Bit mask for SPI_S_SPMF. */
#define BS_SPI_S_SPMF        (1U)          /*!< Bit field size in bits for SPI_S_SPMF. */

/*! @brief Read current value of the SPI_S_SPMF field. */
#define BR_SPI_S_SPMF(x)     (BME_UBFX8(HW_SPI_S_ADDR(x), BP_SPI_S_SPMF, BS_SPI_S_SPMF))
/*@}*/

/*!
 * @name Register SPI_S, field SPRF[7] (RO)
 *
 * SPRF is set at the completion of an SPI transfer to indicate that received
 * data may be read from the SPI data (D) register. When the receive DMA request is
 * disabled (RXDMAE is 0), SPRF is cleared by reading SPRF while it is set and
 * then reading the SPI data register. When the receive DMA request is enabled
 * (RXDMAE is 1), SPRF is automatically cleared when the DMA transfer for the
 * receive DMA request is completed (RX DMA Done is asserted).
 *
 * Values:
 * - 0 - No data available in the receive data buffer
 * - 1 - Data available in the receive data buffer
 */
/*@{*/
#define BP_SPI_S_SPRF        (7U)          /*!< Bit position for SPI_S_SPRF. */
#define BM_SPI_S_SPRF        (0x80U)       /*!< Bit mask for SPI_S_SPRF. */
#define BS_SPI_S_SPRF        (1U)          /*!< Bit field size in bits for SPI_S_SPRF. */

/*! @brief Read current value of the SPI_S_SPRF field. */
#define BR_SPI_S_SPRF(x)     (BME_UBFX8(HW_SPI_S_ADDR(x), BP_SPI_S_SPRF, BS_SPI_S_SPRF))
/*@}*/

/*******************************************************************************
 * HW_SPI_D - SPI data register
 ******************************************************************************/

/*!
 * @brief HW_SPI_D - SPI data register (RW)
 *
 * Reset value: 0x00U
 *
 * This register is both the input and output register for SPI data. A write to
 * the register writes to the transmit data buffer, allowing data to be queued
 * and transmitted. When the SPI is configured as a master, data queued in the
 * transmit data buffer is transmitted immediately after the previous transmission
 * has completed. The SPTEF bit in the S register indicates when the transmit data
 * buffer is ready to accept new data. When the transmit DMA request is disabled
 * (TXDMAE is 0): The S register must be read when SPTEF is set before writing to
 * the SPI data register; otherwise, the write is ignored. When the transmit DMA
 * request is enabled (TXDMAE is 1) when SPTEF is set, the SPI data register can
 * be written automatically by DMA without reading the S register first. Data
 * may be read from the SPI data register any time after SPRF is set and before
 * another transfer is finished. Failure to read the data out of the receive data
 * buffer before a new transfer ends causes a receive overrun condition, and the
 * data from the new transfer is lost. The new data is lost because the receive
 * buffer still held the previous character and was not ready to accept the new
 * data. There is no indication for a receive overrun condition, so the application
 * system designer must ensure that previous data has been read from the receive
 * buffer before a new transfer is initiated.
 */
typedef union _hw_spi_d
{
    uint8_t U;
    struct _hw_spi_d_bitfields
    {
        uint8_t Bits : 8;              /*!< [7:0] Data (low byte) */
    } B;
} hw_spi_d_t;

/*!
 * @name Constants and macros for entire SPI_D register
 */
/*@{*/
#define HW_SPI_D_ADDR(x)         ((x) + 0x5U)

#define HW_SPI_D(x)              (*(__IO hw_spi_d_t *) HW_SPI_D_ADDR(x))
#define HW_SPI_D_RD(x)           (HW_SPI_D(x).U)
#define HW_SPI_D_WR(x, v)        (HW_SPI_D(x).U = (v))
#define HW_SPI_D_SET(x, v)       (BME_OR8(HW_SPI_D_ADDR(x), (uint8_t)(v)))
#define HW_SPI_D_CLR(x, v)       (BME_AND8(HW_SPI_D_ADDR(x), (uint8_t)(~(v))))
#define HW_SPI_D_TOG(x, v)       (BME_XOR8(HW_SPI_D_ADDR(x), (uint8_t)(v)))
/*@}*/

/*
 * Constants & macros for individual SPI_D bitfields
 */

/*!
 * @name Register SPI_D, field Bits[7:0] (RW)
 */
/*@{*/
#define BP_SPI_D_Bits        (0U)          /*!< Bit position for SPI_D_Bits. */
#define BM_SPI_D_Bits        (0xFFU)       /*!< Bit mask for SPI_D_Bits. */
#define BS_SPI_D_Bits        (8U)          /*!< Bit field size in bits for SPI_D_Bits. */

/*! @brief Read current value of the SPI_D_Bits field. */
#define BR_SPI_D_Bits(x)     (HW_SPI_D(x).U)

/*! @brief Format value for bitfield SPI_D_Bits. */
#define BF_SPI_D_Bits(v)     ((uint8_t)((uint8_t)(v) << BP_SPI_D_Bits) & BM_SPI_D_Bits)

/*! @brief Set the Bits field to a new value. */
#define BW_SPI_D_Bits(x, v)  (HW_SPI_D_WR(x, v))
/*@}*/

/*******************************************************************************
 * HW_SPI_M - SPI match register
 ******************************************************************************/

/*!
 * @brief HW_SPI_M - SPI match register (RW)
 *
 * Reset value: 0x00U
 *
 * This register contains the hardware compare value. When the value received in
 * the SPI receive data buffer equals this hardware compare value, the SPI match
 * flag (SPMF) sets.
 */
typedef union _hw_spi_m
{
    uint8_t U;
    struct _hw_spi_m_bitfields
    {
        uint8_t Bits : 8;              /*!< [7:0] Hardware compare value (low byte) */
    } B;
} hw_spi_m_t;

/*!
 * @name Constants and macros for entire SPI_M register
 */
/*@{*/
#define HW_SPI_M_ADDR(x)         ((x) + 0x7U)

#define HW_SPI_M(x)              (*(__IO hw_spi_m_t *) HW_SPI_M_ADDR(x))
#define HW_SPI_M_RD(x)           (HW_SPI_M(x).U)
#define HW_SPI_M_WR(x, v)        (HW_SPI_M(x).U = (v))
#define HW_SPI_M_SET(x, v)       (BME_OR8(HW_SPI_M_ADDR(x), (uint8_t)(v)))
#define HW_SPI_M_CLR(x, v)       (BME_AND8(HW_SPI_M_ADDR(x), (uint8_t)(~(v))))
#define HW_SPI_M_TOG(x, v)       (BME_XOR8(HW_SPI_M_ADDR(x), (uint8_t)(v)))
/*@}*/

/*
 * Constants & macros for individual SPI_M bitfields
 */

/*!
 * @name Register SPI_M, field Bits[7:0] (RW)
 */
/*@{*/
#define BP_SPI_M_Bits        (0U)          /*!< Bit position for SPI_M_Bits. */
#define BM_SPI_M_Bits        (0xFFU)       /*!< Bit mask for SPI_M_Bits. */
#define BS_SPI_M_Bits        (8U)          /*!< Bit field size in bits for SPI_M_Bits. */

/*! @brief Read current value of the SPI_M_Bits field. */
#define BR_SPI_M_Bits(x)     (HW_SPI_M(x).U)

/*! @brief Format value for bitfield SPI_M_Bits. */
#define BF_SPI_M_Bits(v)     ((uint8_t)((uint8_t)(v) << BP_SPI_M_Bits) & BM_SPI_M_Bits)

/*! @brief Set the Bits field to a new value. */
#define BW_SPI_M_Bits(x, v)  (HW_SPI_M_WR(x, v))
/*@}*/

/*******************************************************************************
 * hw_spi_t - module struct
 ******************************************************************************/
/*!
 * @brief All SPI module registers.
 */
#pragma pack(1)
typedef struct _hw_spi
{
    __IO hw_spi_c1_t C1;                   /*!< [0x0] SPI control register 1 */
    __IO hw_spi_c2_t C2;                   /*!< [0x1] SPI control register 2 */
    __IO hw_spi_br_t BR;                   /*!< [0x2] SPI baud rate register */
    __I hw_spi_s_t S;                      /*!< [0x3] SPI status register */
    uint8_t _reserved0[1];
    __IO hw_spi_d_t D;                     /*!< [0x5] SPI data register */
    uint8_t _reserved1[1];
    __IO hw_spi_m_t M;                     /*!< [0x7] SPI match register */
} hw_spi_t;
#pragma pack()

/*! @brief Macro to access all SPI registers. */
/*! @param x SPI module instance base address. */
/*! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
 *     use the '&' operator, like <code>&HW_SPI(SPI0_BASE)</code>. */
#define HW_SPI(x)      (*(hw_spi_t *)(x))

#endif /* __HW_SPI_REGISTERS_H__ */
/* v33/140401/2.1.0 */
/* EOF */

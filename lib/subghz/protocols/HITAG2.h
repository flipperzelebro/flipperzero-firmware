#pragma once

#include "base.h"

#define SUBGHZ_PROTOCOL_HITAG2_NAME "HITAG2"

typedef struct SubGhzProtocolDecoderHITAG2 SubGhzProtocolDecoderHITAG2;
typedef struct SubGhzProtocolEncoderHITAG2 SubGhzProtocolEncoderHITAG2;

extern const SubGhzProtocolDecoder subghz_protocol_HITAG2_decoder;
extern const SubGhzProtocolEncoder subghz_protocol_HITAG2_encoder;
extern const SubGhzProtocol subghz_protocol_HITAG2;

/**
 * Allocate SubGhzProtocolDecoderHITAG2.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolDecoderHITAG2* pointer to a SubGhzProtocolDecoderHITAG2 instance
 */
void* subghz_protocol_decoder_HITAG2_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolDecoderHITAG2.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 */
void subghz_protocol_decoder_HITAG2_free(void* context);

/**
 * Reset decoder SubGhzProtocolDecoderHITAG2.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 */
void subghz_protocol_decoder_HITAG2_reset(void* context);

/**
 * Parse a raw sequence of levels and durations received from the air.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 * @param level Signal level true-high false-low
 * @param duration Duration of this level in, us
 */
void subghz_protocol_decoder_HITAG2_feed(void* context, bool level, uint32_t duration);

/**
 * Getting the hash sum of the last randomly received parcel.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 * @return hash Hash sum
 */
uint8_t subghz_protocol_decoder_HITAG2_get_hash_data(void* context);

/**
 * Serialize data SubGhzProtocolDecoderHITAG2.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param preset The modulation on which the signal was received, SubGhzRadioPreset
 * @return status
 */
SubGhzProtocolStatus subghz_protocol_decoder_HITAG2_serialize(
    void* context,
    FlipperFormat* flipper_format,
    SubGhzRadioPreset* preset);

/**
 * Deserialize data SubGhzProtocolDecoderHITAG2.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return status
 */
SubGhzProtocolStatus
    subghz_protocol_decoder_HITAG2_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Getting a textual representation of the received data.
 * @param context Pointer to a SubGhzProtocolDecoderHITAG2 instance
 * @param output Resulting text
 */
void subghz_protocol_decoder_HITAG2_get_string(void* context, FuriString* output);

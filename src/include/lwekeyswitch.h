#ifndef LweKEYSWITCH_H
#define LweKEYSWITCH_H

///@file
///@brief This file contains the declaration of LWE keyswitch structures

#include "tfhe_core.h"
#include "lweparams.h"
#include "lwesamples.h"

struct LweKeySwitchKey {
    int basebit; ///< log_2(base)
    int base; ///< decomposition base: a power of 2 
    int n; ///< length of the input key: s'
    int l; ///< decomposition length
    uint32_t mask; ///< mask=base-1, used for mod base ops
    const LweParams* in_params; ///< params of the input key s'
    const LweParams* out_params; ///< params of the output key s 
    LweSample* ks0_raw; //tableau qui contient tout les Lwe samples de taille nlbase
    LweSample** ks1_raw;// de taille nl  pointe vers un tableau ks0_raw dont les cases sont espaceés de base positions
    LweSample*** ks; ///< the keyswitch elements: a n.l.base matrix
    // de taille n pointe vers ks1 un tableau dont les cases sont espaceés de ell positions

#ifdef __cplusplus
    LweKeySwitchKey(int basebit, int kslength, const LweParams* in_params, const LweParams* out_params);
    ~LweKeySwitchKey();
    LweKeySwitchKey(const LweKeySwitchKey&) = delete;
    void operator=(const LweKeySwitchKey&) = delete;
#endif
};

//allocate memory space for a LweKeySwitchKey
EXPORT LweKeySwitchKey* alloc_LweKeySwitchKey();
EXPORT LweKeySwitchKey* alloc_LweKeySwitchKey_array(int nbelts);

//free memory space for a LweKeySwitchKey
EXPORT void free_LweKeySwitchKey(LweKeySwitchKey* ptr);
EXPORT void free_LweKeySwitchKey_array(int nbelts, LweKeySwitchKey* ptr);

//initialize the LweKeySwitchKey structure
//(equivalent of the C++ constructor)
EXPORT void init_LweKeySwitchKey(LweKeySwitchKey* obj, int basebit, int kslength, const LweParams* in_params, const LweParams* out_params);
EXPORT void init_LweKeySwitchKey_array(int nbelts, LweKeySwitchKey* obj, int basebit, int kslength, const LweParams* in_params, const LweParams* out_params);

//destroys the LweKeySwitchKey structure
//(equivalent of the C++ destructor)
EXPORT void destroy_LweKeySwitchKey(LweKeySwitchKey* obj);
EXPORT void destroy_LweKeySwitchKey_array(int nbelts, LweKeySwitchKey* obj);
 
//allocates and initialize the LweKeySwitchKey structure
//(equivalent of the C++ new)
EXPORT LweKeySwitchKey* new_LweKeySwitchKey(int basebit, int kslength, const LweParams* in_params, const LweParams* out_params);
EXPORT LweKeySwitchKey* new_LweKeySwitchKey_array(int nbelts, int basebit, int kslength, const LweParams* in_params, const LweParams* out_params);

//destroys and frees the LweKeySwitchKey structure
//(equivalent of the C++ delete)
EXPORT void delete_LweKeySwitchKey(LweKeySwitchKey* obj);
EXPORT void delete_LweKeySwitchKey_array(int nbelts, LweKeySwitchKey* obj);

#endif // LweKEYSWITCH_H
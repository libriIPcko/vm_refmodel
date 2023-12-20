#ifndef MODULE_DEFS_H
#define MODULE_DEFS_H

/**
 * @defgroup vm_refModule_test_defs  vm_refModule test definitions
 * @ingroup vm_refModule_test
 * @brief vm_refModule private definitions
 * 
 * Definitions accessible for vm_refModule tests
 * @{
 */

/**
 * @brief voting_module definitions
 * 
 * Define values used @ simulation time to generate i/o sequence
 */
#define L_ERROR_ASSERT_CYCLES   2 /**< Number of cycles until light error counter fires. */
#define F_ERROR_ASSERT_CYCLES   2 /**< Number of cycles until fatal error counter fires. */
#define L_RECOVERY_CYCLES       3 /**< Number of cycles after which vm recovers from a light error. */
#define F_RECOVERY_CYCLES       3 /**< Number of cycles after which vm recovers from a fatal error. */

/** @} */

#endif//MODULE_DEFS_H
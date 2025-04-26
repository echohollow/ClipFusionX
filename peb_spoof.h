#ifndef PEB_SPOOF_H
#define PEB_SPOOF_H

#include <windows.h>
#include <winternl.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Spoofs the Process Environment Block (PEB) with fake command line and path
 * 
 * This function modifies the process's PEB to replace the command line and image path
 * with custom strings. It uses advanced techniques including:
 * - Memory section mirroring for hidden string storage
 * - Direct PEB modification
 * - API hooking of GetCommandLineW
 * - Module list manipulation
 * 
 * @param fakeCmdLine The fake command line to display (null-terminated wide string)
 * @param fakePath The fake image path to display (null-terminated wide string)
 * @return BOOL TRUE if successful, FALSE otherwise
 */
BOOL SpoofPEB(const wchar_t* fakeCmdLine, const wchar_t* fakePath);

/**
 * @brief Cleans up resources allocated by SpoofPEB
 * 
 * Call this function when spoofing is no longer needed to release:
 * - Memory section handles
 * - Mapped views
 * - Other allocated resources
 */
VOID CleanupSpoofingResources();

#ifdef __cplusplus
}
#endif

#endif // PEB_SPOOF_H
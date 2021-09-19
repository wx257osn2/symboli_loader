.model FLAT
.code
extern C version_dll_proxy_original_procs:DWORD
GetFileVersionInfoA_orig proc
  jmp version_dll_proxy_original_procs[0 * 4]
GetFileVersionInfoA_orig endp
GetFileVersionInfoW_orig proc
  jmp version_dll_proxy_original_procs[1 * 4]
GetFileVersionInfoW_orig endp
GetFileVersionInfoByHandle_orig proc
  jmp version_dll_proxy_original_procs[2 * 4]
GetFileVersionInfoByHandle_orig endp
GetFileVersionInfoExA_orig proc
  jmp version_dll_proxy_original_procs[3 * 4]
GetFileVersionInfoExA_orig endp
GetFileVersionInfoExW_orig proc
  jmp version_dll_proxy_original_procs[4 * 4]
GetFileVersionInfoExW_orig endp
GetFileVersionInfoSizeA_orig proc
  jmp version_dll_proxy_original_procs[5 * 4]
GetFileVersionInfoSizeA_orig endp
GetFileVersionInfoSizeW_orig proc
  jmp version_dll_proxy_original_procs[6 * 4]
GetFileVersionInfoSizeW_orig endp
GetFileVersionInfoSizeExA_orig proc
  jmp version_dll_proxy_original_procs[7 * 4]
GetFileVersionInfoSizeExA_orig endp
GetFileVersionInfoSizeExW_orig proc
  jmp version_dll_proxy_original_procs[8 * 4]
GetFileVersionInfoSizeExW_orig endp
VerFindFileA_orig proc
  jmp version_dll_proxy_original_procs[9 * 4]
VerFindFileA_orig endp
VerFindFileW_orig proc
  jmp version_dll_proxy_original_procs[10 * 4]
VerFindFileW_orig endp
VerInstallFileA_orig proc
  jmp version_dll_proxy_original_procs[11 * 4]
VerInstallFileA_orig endp
VerInstallFileW_orig proc
  jmp version_dll_proxy_original_procs[12 * 4]
VerInstallFileW_orig endp
VerLanguageNameA_orig proc
  jmp version_dll_proxy_original_procs[13 * 4]
VerLanguageNameA_orig endp
VerLanguageNameW_orig proc
  jmp version_dll_proxy_original_procs[14 * 4]
VerLanguageNameW_orig endp
VerQueryValueA_orig proc
  jmp version_dll_proxy_original_procs[15 * 4]
VerQueryValueA_orig endp
VerQueryValueW_orig proc
  jmp version_dll_proxy_original_procs[16 * 4]
VerQueryValueW_orig endp
end

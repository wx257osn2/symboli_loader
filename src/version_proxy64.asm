.code
extern version_dll_proxy_original_procs:QWORD
GetFileVersionInfoA_orig proc
  jmp version_dll_proxy_original_procs[0 * 8]
GetFileVersionInfoA_orig endp
GetFileVersionInfoW_orig proc
  jmp version_dll_proxy_original_procs[1 * 8]
GetFileVersionInfoW_orig endp
GetFileVersionInfoByHandle_orig proc
  jmp version_dll_proxy_original_procs[2 * 8]
GetFileVersionInfoByHandle_orig endp
GetFileVersionInfoExA_orig proc
  jmp version_dll_proxy_original_procs[3 * 8]
GetFileVersionInfoExA_orig endp
GetFileVersionInfoExW_orig proc
  jmp version_dll_proxy_original_procs[4 * 8]
GetFileVersionInfoExW_orig endp
GetFileVersionInfoSizeA_orig proc
  jmp version_dll_proxy_original_procs[5 * 8]
GetFileVersionInfoSizeA_orig endp
GetFileVersionInfoSizeW_orig proc
  jmp version_dll_proxy_original_procs[6 * 8]
GetFileVersionInfoSizeW_orig endp
GetFileVersionInfoSizeExA_orig proc
  jmp version_dll_proxy_original_procs[7 * 8]
GetFileVersionInfoSizeExA_orig endp
GetFileVersionInfoSizeExW_orig proc
  jmp version_dll_proxy_original_procs[8 * 8]
GetFileVersionInfoSizeExW_orig endp
VerFindFileA_orig proc
  jmp version_dll_proxy_original_procs[9 * 8]
VerFindFileA_orig endp
VerFindFileW_orig proc
  jmp version_dll_proxy_original_procs[10 * 8]
VerFindFileW_orig endp
VerInstallFileA_orig proc
  jmp version_dll_proxy_original_procs[11 * 8]
VerInstallFileA_orig endp
VerInstallFileW_orig proc
  jmp version_dll_proxy_original_procs[12 * 8]
VerInstallFileW_orig endp
VerLanguageNameA_orig proc
  jmp version_dll_proxy_original_procs[13 * 8]
VerLanguageNameA_orig endp
VerLanguageNameW_orig proc
  jmp version_dll_proxy_original_procs[14 * 8]
VerLanguageNameW_orig endp
VerQueryValueA_orig proc
  jmp version_dll_proxy_original_procs[15 * 8]
VerQueryValueA_orig endp
VerQueryValueW_orig proc
  jmp version_dll_proxy_original_procs[16 * 8]
VerQueryValueW_orig endp
end

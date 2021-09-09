#include<will/_windows.hpp>

static constexpr LPCSTR import_names[] = {
	"GetFileVersionInfoA",
	"GetFileVersionInfoW",
	"GetFileVersionInfoByHandle",
	"GetFileVersionInfoExA",
	"GetFileVersionInfoExW",
	"GetFileVersionInfoSizeA",
	"GetFileVersionInfoSizeW",
	"GetFileVersionInfoSizeExA",
	"GetFileVersionInfoSizeExW",
	"VerFindFileA",
	"VerFindFileW",
	"VerInstallFileA",
	"VerInstallFileW",
	"VerLanguageNameA",
	"VerLanguageNameW",
	"VerQueryValueA",
	"VerQueryValueW"
};
extern "C" void* version_dll_proxy_original_procs[sizeof(import_names)/sizeof(LPCSTR)] = {};
struct version_dll_proxy{
	will::module_handle version_dll;
	static will::expected<version_dll_proxy, will::winapi_last_error> create(){
		return will::get_system_directory().bind([](will::tstring&& str){
		return will::load_library((str+_T("\\version.dll")).c_str()).bind([](will::module_handle&& mod)->will::expected<version_dll_proxy, will::winapi_last_error>{
			constexpr std::size_t size = sizeof(import_names)/sizeof(LPCSTR);
			for(std::size_t i = 0; i < size; ++i){
				auto addr = mod.get_proc_address<void>(import_names[i]);
				if(!addr)
					return will::make_unexpected(addr.error());
				version_dll_proxy_original_procs[i] = *addr;
			}
			return version_dll_proxy{std::move(mod)};
		});});
	}
};
static const version_dll_proxy _proxy = version_dll_proxy::create().value();


static inline BOOL process_attach(HINSTANCE hinst, bool is_dynamic_load){
	return TRUE;
}

static inline BOOL thread_attach(HINSTANCE hinst){
	return TRUE;
}

static inline BOOL thread_detach(HINSTANCE hinst){
	return TRUE;
}

static inline BOOL process_detach(HINSTANCE hinst, bool process_terminating){
	return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
	switch(fdwReason){
	case DLL_PROCESS_ATTACH:
		return process_attach(hinstDLL, lpvReserved == nullptr);
	case DLL_THREAD_ATTACH:
		return thread_attach(hinstDLL);
	case DLL_THREAD_DETACH:
		return thread_detach(hinstDLL);
	case DLL_PROCESS_DETACH:
		return process_detach(hinstDLL, lpvReserved != nullptr);
	}
}

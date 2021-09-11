#include<will/_windows.hpp>
#include<vector>
#include<fstream>
#include<filesystem>
#include<ranges>

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
				const auto addr = mod.get_proc_address<void>(import_names[i]);
				if(!addr)
					return will::make_unexpected(addr.error());
				version_dll_proxy_original_procs[i] = *addr;
			}
			return version_dll_proxy{std::move(mod)};
		});});
	}
};
static const version_dll_proxy _proxy = version_dll_proxy::create().value();

static std::vector<will::module_handle> modules;

static inline BOOL process_attach(HINSTANCE hinst, bool is_dynamic_load){
	const auto process_name = std::filesystem::path{will::get_module_file_name(nullptr).value()}.filename();
	const auto dll_dir = std::filesystem::path{will::get_module_file_name(hinst).value()}.parent_path();
	const auto dir_path = dll_dir / "symboli_loader" / process_name;
	if(!std::filesystem::exists(dir_path) || !std::filesystem::is_directory(dir_path))
		return TRUE;
	const std::ranges::subrange dir{std::filesystem::directory_iterator{dir_path}, std::filesystem::directory_iterator{}};
	for(auto&& x : dir)
		if(!x.is_directory() && x.path().extension() == ".symboli")
			modules.emplace_back(will::load_library(will::tchar::to_tstring(x.path())).value());
	return TRUE;
}

static inline BOOL process_detach(HINSTANCE hinst, bool process_terminating){
	modules.clear();
	return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)try{
	switch(fdwReason){
	case DLL_PROCESS_ATTACH:
		return process_attach(hinstDLL, lpvReserved == nullptr);
	case DLL_PROCESS_DETACH:
		return process_detach(hinstDLL, lpvReserved != nullptr);
	default:
		return TRUE;
	}
}catch(std::exception& e){
	::MessageBoxA(nullptr, e.what(), "Symboli Loader exception", MB_OK|MB_ICONERROR|MB_SETFOREGROUND);
	return FALSE;
}

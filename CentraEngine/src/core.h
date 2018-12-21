/*
Header incluant CT_API.
*/

#pragma once

#ifdef CT_BUILD_DLL
	#define CT_API __declspec(dllexport) // API a l'export.
#else
	#define CT_API __declspec(dllimport) // API a l'import.
#endif 
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include "Disassembler.h"

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hFile, hMap;
	LPBYTE lpFile;

	LPCTSTR lpFileName = argv[1];
	hFile = CreateFile(lpFileName, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		std::cout << "CreateFile() failed\n";
		return 0;
	}

	DWORD dwFileSize = GetFileSize(hFile, NULL);
	hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, dwFileSize, NULL);
	if (hMap == NULL) {
		std::cout << "CreateFileMapping() failed\n";
		return 0;
	}

	lpFile = (LPBYTE)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (lpFile == NULL) {
		std::cout << "MapViewOfFile() failed\n";
		return 0;
	}

	PIMAGE_DOS_HEADER pidh = (PIMAGE_DOS_HEADER)lpFile;
	PIMAGE_NT_HEADERS64 pinh = (PIMAGE_NT_HEADERS64)((LPBYTE)pidh + pidh->e_lfanew);
	PIMAGE_FILE_HEADER pifh = (PIMAGE_FILE_HEADER)&pinh->FileHeader;
	PIMAGE_OPTIONAL_HEADER64 pioh = (PIMAGE_OPTIONAL_HEADER64)&pinh->OptionalHeader;

	DWORD dwEntryPoint = pioh->AddressOfEntryPoint;
	DWORD dwCSraw = 0, dwCSsize = 0;
	for (int i = 0; i < pifh->NumberOfSections; ++i) {
		auto f = IMAGE_FIRST_SECTION(pinh) + i;
		auto va = f->VirtualAddress;
		if (va <= dwEntryPoint && dwEntryPoint <= va + f->Misc.VirtualSize) {
			dwEntryPoint = dwEntryPoint - va + f->PointerToRawData;
			dwCSraw = f->PointerToRawData;
			dwCSsize = f->SizeOfRawData;
		}
	}

	Disassembler disass;
	switch (pifh->Machine) {
	case IMAGE_FILE_MACHINE_I386:
		break;
	case IMAGE_FILE_MACHINE_AMD64:
		disass.Run(lpFile, dwCSraw, dwCSsize);
		break;
	}

	UnmapViewOfFile(lpFile);
	CloseHandle(hMap);

	CloseHandle(hFile);

	return 0;
}
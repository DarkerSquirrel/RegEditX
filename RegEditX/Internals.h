#pragma once

#define REG_MAX_KEY_VALUE_NAME_LENGTH 32767
#define REG_MAX_KEY_NAME_LENGTH 512

typedef enum _KEY_INFORMATION_CLASS {
	KeyBasicInformation, // KEY_BASIC_INFORMATION
	KeyNodeInformation, // KEY_NODE_INFORMATION
	KeyFullInformation, // KEY_FULL_INFORMATION
	KeyNameInformation, // KEY_NAME_INFORMATION
	KeyCachedInformation, // KEY_CACHED_INFORMATION
	KeyFlagsInformation, // KEY_FLAGS_INFORMATION
	KeyVirtualizationInformation, // KEY_VIRTUALIZATION_INFORMATION
	KeyHandleTagsInformation, // KEY_HANDLE_TAGS_INFORMATION
	KeyTrustInformation, // KEY_TRUST_INFORMATION
	KeyLayerInformation, // KEY_LAYER_INFORMATION
	MaxKeyInfoClass
} KEY_INFORMATION_CLASS;

typedef struct _KEY_BASIC_INFORMATION {
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG NameLength;
	WCHAR Name[1];
} KEY_BASIC_INFORMATION, * PKEY_BASIC_INFORMATION;

typedef struct _KEY_NODE_INFORMATION {
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG ClassOffset;
	ULONG ClassLength;
	ULONG NameLength;
	WCHAR Name[1];
	// ...
	// WCHAR Class[1];
} KEY_NODE_INFORMATION, * PKEY_NODE_INFORMATION;

typedef struct _KEY_FULL_INFORMATION {
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG ClassOffset;
	ULONG ClassLength;
	ULONG SubKeys;
	ULONG MaxNameLen;
	ULONG MaxClassLen;
	ULONG Values;
	ULONG MaxValueNameLen;
	ULONG MaxValueDataLen;
	WCHAR Class[1];
} KEY_FULL_INFORMATION, * PKEY_FULL_INFORMATION;

typedef struct _KEY_NAME_INFORMATION {
	ULONG NameLength;
	WCHAR Name[1];
} KEY_NAME_INFORMATION, * PKEY_NAME_INFORMATION;

typedef struct _KEY_CACHED_INFORMATION {
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG SubKeys;
	ULONG MaxNameLen;
	ULONG Values;
	ULONG MaxValueNameLen;
	ULONG MaxValueDataLen;
	ULONG NameLength;
	WCHAR Name[1];
} KEY_CACHED_INFORMATION, * PKEY_CACHED_INFORMATION;

typedef struct _KEY_FLAGS_INFORMATION {
	ULONG UserFlags;
} KEY_FLAGS_INFORMATION, * PKEY_FLAGS_INFORMATION;

extern "C" NTSYSCALLAPI NTSTATUS NTAPI NtQueryKey(
	_In_ HANDLE KeyHandle,
	_In_ KEY_INFORMATION_CLASS KeyInformationClass,
	_Out_writes_bytes_opt_(Length) PVOID KeyInformation,
	_In_ ULONG Length,
	_Out_ PULONG ResultLength
);

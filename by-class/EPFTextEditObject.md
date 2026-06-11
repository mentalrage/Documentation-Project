*** UID:00004H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPFTextEditObject

## Status

- Confidence: strong for function boundaries, vtable identity, caller fan-in, resource selection, and `TextEditPane` support-object ownership; medium for final field names and exact original header/source split.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x005954c0-0x00595590` and `0x00595630-0x0059566e`
- Reconstruction status: documentation-only child of `TextEditPane`; final C++ is intentionally blank because this does not meet the 95/95 source-quality bar.

## Class Purpose

`EPFTextEditObject` is a [UID:0000EN][TextEditObject](by-class/TextEditObject.md) derivative that attaches a symbol image frame to a text-edit object. It constructs the base text-edit payload, initializes the embedded frame-like object at `this + 0x14`, chooses `SYMBOLS.EPF` or `SYMBOLS.EPD` based on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, checks the frame count through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), and loads the requested frame when the byte-sized frame index is in range.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x005954c0-0x00595590` | `EPFTextEditObject::EPFTextEditObject` | Initializes `TextEditObject`, installs the EPF text-object vtable, initializes the embedded frame storage, and loads the requested symbol frame when present. |
| `0x00595630-0x0059566e` | scalar deleting destructor | Reinstalls the base `TextEditObject` vtable, releases base storage, and handles scalar-delete flags, including the 0x3c-byte sized-delete path. |

## Evidence Notes

2026-06-04 live IDA pass:

- Binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA functions are `0x005954c0-0x00595590` for the constructor and `0x00595630-0x0059566e` for the scalar deleting destructor.
- Direct constructor callers are `0x00566da3` in function `0x00565890`, `0x005707c1` in function `0x005700e0`, and `0x005a0277` in function `0x0059f610`.
- The constructor calls the base initializer at `0x004f4a80`, writes `0` to `+0x04`, stores the caller argument at `+0x08`, clears `+0x0c/+0x10`, writes vtable `0x0062e124`, and initializes frame storage at `this + 0x14` through `0x00457a60`.
- The constructor reads [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`; when it is `1`, it checks and loads from `SYMBOLS.EPF` at `0x00610ca4`, otherwise it checks and loads from `SYMBOLS.EPD` at `0x0062e16c`.
- Both branches read [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) at `0x0067a744`, call `0x004d1780` to get the frame count, compare the byte-sized frame index against that count, and call `0x004d02f0` to load into `this + 0x14`.
- Vtable slot `0x0062e124` points to `0x00595630`; the constructor stores that slot at `0x00595517`, and the scalar deleting destructor restores the base [UID:0000EN][TextEditObject](by-class/TextEditObject.md) vtable at `0x0062e048`.
- Boundary bytes show `0x005954b3-0x005954c0` is `0xcc` padding before the constructor and `0x0059566e-0x00595670` is padding before the next text-edit deleting destructor. The bytes between `0x00595590` and `0x00595630` belong to a separate unmodeled helper body, not to `EPFTextEditObject`.

## Current Caveats

- The class behavior and binary ownership are strong, but final field names remain provisional: `this + 0x14` behaves as embedded frame storage, while the exact original type name and header declaration are not proven.
- The support-object file placement is strong enough to attach this page to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), but final reconstruction still waits on source-quality names for the text-edit object and frame helper APIs.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EN][TextEditObject](by-class/TextEditObject.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- 2026-06-07 A008 alias cleanup: normalized the constructor's `byte_66DA97` resource branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-06-04:
  - Before: scored `72/80`, left unattached for autogen, used stale provenance/caveats, and recorded end addresses one byte short of the IDA exclusive function bounds.
  - After: scored `84/88`, marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and kept final C++ blank because the page remains below 95/95.
  - Summary/evidence: live IDA MCP confirmed the binary identity, exact constructor/destructor ranges, three direct constructor callers, the single `EPFTextEditObject` vtable slot at `0x0062e124`, base-vtable restoration at `0x0062e048`, resource branch between `SYMBOLS.EPF` and `SYMBOLS.EPD`, `g_pEPFLib` use through `0x004d1780`/`0x004d02f0`, object/frame offsets, delete-size evidence, and boundary padding.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: symbol-frame text-edit object role, constructor/destructor ranges, EPF/EPD resource selection, and constructor callers were documented; remaining work was exact original file split and fuller embedded frame layout detail.

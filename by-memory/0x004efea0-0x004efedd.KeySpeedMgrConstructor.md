*** UID:0002IP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004efea0-0x004efedd KeySpeedMgr Constructor

## Status

- Confidence: strong for exact IDA function boundary, object layout effects, singleton write, and startup caller.
- Entity kind: constructor.
- Covered class: [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md).
- Likely source file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- Parent aggregate: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md).
- Disposition: reconstructable NexusTK input/platform code.
- Generated parent: attached to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md); both pages clear the 80/80 parent gate.

## Function

| Range | Function | Notes |
| --- | --- | --- |
| `0x004efea0-0x004efedd` | `KeySpeedMgr::KeySpeedMgr` | Calls the `LObject` base constructor, stores `g_pKeySpeedMgr`, initializes saved delay/speed fields to `0xffffffff`, installs the `KeySpeedMgr` vtable, and returns `this`. |

## Raw Evidence

- 2026-05-31 IDA MCP reports `sub_4EFEA0` at `0x004efea0-0x004efedd`.
- IDA decompilation writes `dword_67AB48 = this` at `0x004efebd`, `this[1] = -1` at `0x004efec3`, vtable `0x0061c9c8` at `0x004efecb`, and `this[2] = -1` at `0x004efed1`.
- Caller xrefs show construction from `Application::Initialize` at `0x00463a9a`, after an allocation of `0x0c` bytes.
- The three bytes `0x004efedd-0x004efee0` are confirmed `0xcc` alignment padding before the non-deleting destructor.

## 2026-06-06 Live IDA Refresh

- `0x004efea0` is still modeled as `sub_4EFEA0` with exact bounds `0x004efea0-0x004efedd` and a single direct caller at `0x00463a9a`.
- The only internal call remains `0x004efeaa -> 0x004f4a80`, matching the `LObject` base-constructor setup described by the layout page.
- The successor gap `0x004efedd-0x004efee0` is three `0xcc` bytes before the ordinary destructor.

## Reconstruction Notes

- Source should model the fields as saved Windows keyboard repeat delay and speed values, not as generic `mbr_0x4`/`mbr_0x8` names.
- The invalid sentinel should be represented source-style, such as `UINT(-1)`, only when the surrounding header/source rewrite is ready.
- Do not emit final C++ from this page until the full `KeySpeedMgr` file rewrite is audited at the required high confidence/completion threshold.

## Cross-References

- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)

## Changes

### 2026-06-06 - Attached constructor to KeySpeedMgr class

- What existed before: the constructor was reconstructable but unassigned in autogen metadata.
- What changed: `AUTOGEN_PARENT_UID` now points to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md), scores are raised to `84/90`, and live IDA evidence was added for the current bounds, caller, base-constructor call, and padding.
- Summary/evidence: live IDA MCP reports `sub_4EFEA0` at `0x004efea0-0x004efedd`, direct caller `0x00463a9a`, `call sub_4F4A80` at `0x004efeaa`, and three `0xcc` bytes at `0x004efedd-0x004efee0`. Final C++ remains blank below the 95/95 source gate.

*** UID:0002IP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Live IDA confirms exact constructor bounds, `Application::Initialize` caller at `0x00463a9a`, `LObject` base constructor call at `0x004efeaa`, singleton/vtable/field initialization evidence, class parent attachment, and blank final C++ below the source gate. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x004efea0-0x004efedd KeySpeedMgr Constructor

## Status

- Confidence: strong for exact IDA function boundary, object layout effects, singleton write, and startup caller.
- Entity kind: constructor.
- Covered class: [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md).
- Likely source file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- Parent aggregate: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md).
- Disposition: reconstructable NexusTK input/platform code.
- Generated parent: attached to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md), which routes through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) to `NexusTK/input/KeySpeedMgr.cpp`; target, class, and file route clear the current 85/85+ source-entry gate.

## Function

| Range | Function | Notes |
| --- | --- | --- |
| `0x004efea0-0x004efedd` | `KeySpeedMgr::KeySpeedMgr` | Constructor body publishes `g_pKeySpeedMgr`, initializes saved keyboard delay/speed fields to the invalid `UINT(-1)` sentinel, and relies on normal compiler emission for `LObject` base construction, vptr setup, and constructor return mechanics. |

## Raw Evidence

- 2026-05-31 IDA MCP reports `sub_4EFEA0` at `0x004efea0-0x004efedd`.
- IDA decompilation writes `dword_67AB48 = this` at `0x004efebd`, `this[1] = -1` at `0x004efec3`, vtable `0x0061c9c8` at `0x004efecb`, and `this[2] = -1` at `0x004efed1`.
- Caller xrefs show construction from `Application::Initialize` at `0x00463a9a`, after an allocation of `0x0c` bytes.
- The three bytes `0x004efedd-0x004efee0` are confirmed `0xcc` alignment padding before the non-deleting destructor.
- 2026-06-19 B014 raw PE check on `NexusTK.exe` SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` confirms the constructor body is 61 bytes (`0x3d`, verified with `int_convert.py`) at `0x004efea0-0x004efedd`.
- Capstone disassembly decodes the source effects as `call 0x4f4a80` at `0x004efeaa`, singleton write `mov dword ptr [0x67ab48], ecx` at `0x004efebd`, saved delay write `mov dword ptr [eax], 0xffffffff` at `0x004efec3`, vptr write `mov dword ptr [esi], 0x61c9c8` at `0x004efecb`, saved speed write `mov dword ptr [esi + 8], 0xffffffff` at `0x004efed1`, and `ret` at `0x004efedc`.
- Raw bytes at `0x004efedd-0x004efee0` are `cc cc cc`, confirming three-byte alignment before the ordinary destructor.
- Raw rel32 scan found the only direct constructor call at `0x00463a9a`; the same startup window calls `LoadSystemKeyboardSettings` at `0x00463aae` and `ApplyFastKeyboardRepeatSettings` at `0x00463ab5`.
- Local IDA export RTTI shows `KeySpeedMgr` has `LObject` and `Singleton<KeySpeedMgr>` base-class descriptors. Treat the singleton publish as source-visible constructor behavior, while leaving final base-list spelling to class/header reconstruction.

## 2026-06-06 Live IDA Refresh

- `0x004efea0` is still modeled as `sub_4EFEA0` with exact bounds `0x004efea0-0x004efedd` and a single direct caller at `0x00463a9a`.
- The only internal call remains `0x004efeaa -> 0x004f4a80`, matching the `LObject` base-constructor setup described by the layout page.
- The successor gap `0x004efedd-0x004efee0` is three `0xcc` bytes before the ordinary destructor.

## Reconstruction Notes

- First-draft formal source should be `KeySpeedMgr::KeySpeedMgr() { g_pKeySpeedMgr = this; m_savedKeyboardDelay = UINT(-1); m_savedKeyboardSpeed = UINT(-1); }`.
- Source should model fields as saved Windows keyboard repeat delay/speed values, not `mbr_0x4`, `mbr_0x8`, `this[1]`, or `this[2]`.
- `UINT(-1)` is the preferred source-style invalid sentinel. It is outside the valid restore ranges (`0..3` for keyboard delay, `0..31` for keyboard speed), so restore remains a no-op until the load method captures real system settings.
- Do not emit explicit vtable assignment, `return this`, raw `0xffffffff`, `KeySpeedMgr*` constructor return type, or the generated `this == reinterpret_cast<KeySpeedMgr*>(-4)` branch.
- IDA RTTI exposes `Singleton<KeySpeedMgr>` in the class hierarchy, so final header reconstruction should decide whether the singleton publish belongs to an explicit singleton base. This does not block target-level first-draft C++ because current docs, generated-source practice, and raw behavior all support recording the constructor's source-visible singleton effect as `g_pKeySpeedMgr = this;`.
- The stale 95/95 no-code note is obsolete under the current source-entry gate. This target is reconstructable, has a valid owner/emitter route, and should emit first-draft C++ after the B014 score update.

## Cross-References

- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)

## Changes

### 2026-06-19 B014 constructor source-quality recheck

- Changed recommendation from the older `84/90`, blank formal C++, to `88/92` with first-draft constructor C++; current page already had the B010 score/body incorporated, and this pass adds the missing B014 evidence detail.
- Evidence: B014 raw PE/Capstone recheck confirmed the exact 61-byte body, sole startup caller at `0x00463a9a`, `LObject` base-constructor call at `0x004efeaa`, singleton write to `g_pKeySpeedMgr` at `0x0067ab48`, saved keyboard delay/speed sentinel writes at offsets `+0x04` and `+0x08`, `0x0061c9c8` vptr store, and three `0xcc` padding bytes before the ordinary destructor.
- Source decision: emit only the source-shaped constructor effects `g_pKeySpeedMgr = this;`, `m_savedKeyboardDelay = UINT(-1);`, and `m_savedKeyboardSpeed = UINT(-1);`; leave base construction, vptr setup, return-this lowering, and singleton-base/null-adjust mechanics to compiler/header reconstruction.

### 2026-06-06 - Attached constructor to KeySpeedMgr class

- What existed before: the constructor was reconstructable but unassigned in autogen metadata.
- What changed: `AUTOGEN_PARENT_UID` now points to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md), scores are raised to `84/90`, and live IDA evidence was added for the current bounds, caller, base-constructor call, and padding.
- Summary/evidence: live IDA MCP reports `sub_4EFEA0` at `0x004efea0-0x004efedd`, direct caller `0x00463a9a`, `call sub_4F4A80` at `0x004efeaa`, and three `0xcc` bytes at `0x004efedd-0x004efee0`. Final C++ remains blank below the 95/95 source gate.

### 2026-06-20 B006 Rule 26 source-quality incorporation

- Changed scores from `84/90` to `87/91` and added first-draft constructor C++.
- Evidence: B006 direct PE/Capstone recheck confirmed the `Application::Initialize` caller at `0x00463a9a` after `0x0c` allocation, the base-constructor call, `g_pKeySpeedMgr` publication, saved delay/speed initialization to `UINT(-1)`, vptr compiler emission, and three-byte successor padding.

### 2026-06-21 B010 source-quality sync

- Changed score to `88/92` after B010 aggregate review reconfirmed the exact `0x3d` constructor body, single startup caller `0x00463a9a`, `0x0c` object allocation context, singleton publication, saved-field sentinel writes, vptr compiler emission, and three-byte successor padding.
- Formal C++ remains the source body only: `g_pKeySpeedMgr = this; m_savedKeyboardDelay = UINT(-1); m_savedKeyboardSpeed = UINT(-1);`. Base construction, vptr installation, null-adjust mechanics, and return-this lowering remain compiler/decompiler mechanics.

*** UID:0000QT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pEffectObjImageLib

## Status

- Confidence: strong for storage address and owner, medium for final source-facing name.
- Backing storage: [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md), IDA `dword_69B44C`.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Observed aliases include `g_pEffectObjImageLib` and raw `dword_69B44C`.

## Role

`g_pEffectObjImageLib` is the process-wide pointer to the effect sprite image library. Runtime effect panes and map/living-object code read this pointer to resolve effect descriptors, effect sprite bounds, and effect-frame rendering.

## IDA Xref Summary

IDA MCP on 2026-05-26 reports xrefs to `0x0069b44c`.

| Site | Role |
| --- | --- |
| `0x004ddf9f` / `0x004ddfa6` | [UID:00017K][0x004ddf60-0x004e6455.EffectObjImageLib](by-memory/0x004ddf60-0x004e6455.EffectObjImageLib.md) writes the singleton. |
| `0x004de167` | [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) clears the singleton. |
| `0x004e5b70` | [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) clears the singleton. |
| `0x004e640e` | Scalar deleting destructor clears the singleton. |
| `0x004f65d2` | `Application::Shutdown` reads the singleton for teardown. |
| `0x0050e331` / `0x0050e893` / `0x005a2ee5` | Map/living-object paths read effect descriptor data. |
| `0x005388fa` / `0x00538982` / `0x00538b97` | `EffectObjectPane` setup/render paths read the singleton for bounds and rendering. |

## Ownership

`g_pEffectObjImageLib` is source-owned by `EffectObjImageLib`, not by `MapPane`, `LivingObjectPane`, or `EffectObjectPane`. Those classes are consumers.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:00017K][0x004ddf60-0x004e6455.EffectObjImageLib](by-memory/0x004ddf60-0x004e6455.EffectObjImageLib.md)
- [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/82`. Summary/evidence: the page documents storage, owner file, runtime role, IDA xref summary, consumer paths, ownership decision, and vtable/layout refs; final source-facing name remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Evidence: live IDA MCP reports 12 xrefs to `0x0069b44c`; decompilation confirms `0x004ddf60` writes `dword_69B44C`, `0x004de050` clears it in ordinary teardown, `0x004e5b70` is the clear helper, and `0x004e62f0` clears it in the deleting destructor path.

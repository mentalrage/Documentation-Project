*** UID:0000QT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class EffectObjImageLib;

EffectObjImageLib *g_pEffectObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pEffectObjImageLib

## Status

- Confidence: very strong for storage address, pointer type, owner, external linkage, one-definition route, direct Singleton-base lifecycle lowering, and consumer/non-owner split; exact original spelling remains the bounded confidence cap.
- Backing storage: [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md), IDA `dword_69B44C`.
- Direct owner/parent: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), the sole `NexusTK/render/EffectObjImageLib.cpp` source route.
- Class support: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md), which carries the one matching `extern` declaration and direct `Singleton<EffectObjImageLib>` base.
- Observed aliases include `g_pEffectObjImageLib` and raw `dword_69B44C`.

## Role

`g_pEffectObjImageLib` is the process-wide pointer to the effect sprite image library. Runtime effect panes and map/living-object code read this pointer to resolve effect descriptors, effect sprite bounds, and effect-frame rendering.

This page owns the one externally linked definition, `EffectObjImageLib *g_pEffectObjImageLib = 0;`, at file emitter position 4. The complete class/header contract carries one `extern EffectObjImageLib *g_pEffectObjImageLib;`; UID0001PQ is only the false/non-emitting loader-zero backing slot. A second definition, file-static definition, template static-member definition, or physical-page marker would violate the observed cross-module use and the accepted one-definition route.

## IDA Xref Summary

IDA MCP on 2026-06-13 reports exactly 12 xrefs to `0x0069b44c`; the live IDB bytes are `00 00 00 00` and `u32le` value `0`.

| Site | Role |
| --- | --- |
| `0x004ddf9f` / `0x004ddfa6` | [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md) writes the singleton. |
| `0x004de167` | [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) clears the singleton. |
| `0x004e5b70` | [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) clears the singleton. |
| `0x004e640e` | Scalar deleting destructor clears the singleton. |
| `0x004f65d2` | `Application::Shutdown` reads the singleton for teardown. |
| `0x0050e331` / `0x0050e893` / `0x005a2ee5` | Map/living-object paths read effect descriptor data. |
| `0x005388fa` / `0x00538982` / `0x00538b97` | `EffectObjectPane` setup/render paths read the singleton for bounds and rendering. |

## Ownership

`g_pEffectObjImageLib` is source-owned by `EffectObjImageLib`, not by `MapPane`, `LivingObjectPane`, or `EffectObjectPane`. Those classes are consumers.

The direct parent remains [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md): the compiler-generated constructor/base path publishes this slot, reverse base teardown and cleanup wrappers clear it, and the image-library file owns the `EFFECT.TBL`, `EFFECT.FRM`, EPF/EPD, palette, descriptor, bounds, and render helper behavior consumed by the map/living/effect-object paths. RTTI proves direct base order `LObject, Singleton<EffectObjImageLib>` and Singleton PMD `+4/-1/0`; this EBO-adjusted base is the source cause of publication and clear. The consumer xrefs prove runtime use but do not transfer ownership to `MapPane`, `LivingObjectPane`, or `EffectObjectPane`.

The five observed writes are therefore binary lifecycle effects, not evidence for explicit `g_pEffectObjImageLib = this` or `g_pEffectObjImageLib = 0` statements in the authored constructor/destructor. The human source declares the direct Singleton base, while this global page retains the sole definition needed by that base contract.

## 2026-06-13 Evidence Refresh

- Live IDA MCP session `a001_goal2_0002UM` read backing storage [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md) as bytes `00 00 00 00` and `u32le` value `0`, correcting older stale `0xffffffff` wording in the storage/coverage evidence.
- `xrefs_to 0x0069b44c` returned exactly 12 direct data xrefs: five lifecycle writes/clears at `0x004ddf9f`, `0x004ddfa6`, `0x004de167`, `0x004e5b70`, and `0x004e640e`, plus seven reads at `0x004f65d2`, `0x0050e331`, `0x0050e893`, `0x005388fa`, `0x00538982`, `0x00538b97`, and `0x005a2ee5`.
- Function-size lookup confirms the ownership/consumer split: constructor `0x004ddf60` is `0xee` / 238 bytes, ordinary destructor `0x004de050` is `0x13a` / 314 bytes, clear helper `0x004e5b70` is `0x0b` / 11 bytes, scalar deleting destructor `0x004e62f0` is `0x166` / 358 bytes, shutdown reader `0x004f6490` is `0x215` / 533 bytes, map readers `0x0050e320` and `0x0050e850` are `0x196` / 406 and `0x1e0` / 480 bytes, effect-object readers `0x005388c0`, `0x00538960`, and `0x00538af0` are `0x96` / 150, `0x69` / 105, and `0xba` / 186 bytes, and the living/effect path `0x005a2e00` is `0x8de` / 2270 bytes (all decimal conversions verified with `tools/int_convert.py` / IDA MCP `int_convert`).
- B008's 2026-06-30 callback attaches the formal source declaration through the file owner at emitter position `4`. The declaration spelling remains medium-high confidence because IDA and existing docs use both `g_pEffectObjImageLib` and raw `dword_69B44C`, but the singleton role, zero initialization, lifecycle, and ownership are strong.
- UID0001PQ source-quality reanalysis confirms that backing storage is in loader-zero `.data` virtual tail with no valid raw-file bytes. The zero initializer is the highest-probability human spelling and produces the observed initial state; omitted initialization is behaviorally possible but weaker than the established source convention.
- Direct RTTI and construction/destruction order reject explicit authored lifecycle writes, a source-authored clear helper, and a standalone deleting-wrapper body. The direct Singleton base produces those binary effects while preserving the single external definition here.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md)
- [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)

## Changes

- 2026-07-21 B004 UID0001PQ source-quality callback:
  - Raised `88/90` to `92/94` while retaining owner UID0000IY, emitter position 4, and the exact managed definition byte-for-byte.
  - Added external-linkage, one-definition, one-header-extern, loader-zero backing, direct `Singleton<EffectObjImageLib>` PMD `+4/-1/0` EBO, and implicit publication/reverse-clear evidence. Preserved all 12 xrefs, exact function sizes, resource ownership, consumers, and the source-name confidence cap.
  - Rejected duplicate physical-page source, file-static/template-member alternatives, and explicit constructor/destructor lifecycle statements because they would duplicate or misrepresent compiler-lowered direct-base behavior.

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `86/89`, blank formal C++ block and no emitter position.
  - After: `88/90`, formal singleton declaration attached at emitter position `4` under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, storage xrefs, constructor/destructor/helper/scalar clear evidence, shutdown/map/living/effect-object consumer reads, and adjacent-singleton separation to keep this as the file-owned process-wide `EffectObjImageLib *` declaration rather than a consumer-owned global or duplicate storage-page definition.

- 2026-06-13 A002 Goal 2 global-quality refresh:
  - Before: `86/82`.
  - After: `86/89`.
  - Summary/evidence: live IDA MCP reconfirmed the current zero-initialized backing slot, complete 12-xref set, five lifecycle writes/clears, seven runtime reads, exact function-size anchors, direct parent [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) at `89/86`, class support [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) at `85/87`, and consumer/non-owner separation for map/living/effect-object paths.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/82`. Summary/evidence: the page documents storage, owner file, runtime role, IDA xref summary, consumer paths, ownership decision, and vtable/layout refs; final source-facing name remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Evidence: live IDA MCP reports 12 xrefs to `0x0069b44c`; decompilation confirms `0x004ddf60` writes `dword_69B44C`, `0x004de050` clears it in ordinary teardown, `0x004e5b70` is the clear helper, and `0x004e62f0` clears it in the deleting destructor path.

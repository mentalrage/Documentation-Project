*** UID:0000R5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HumanImageLib;

HumanImageLib *g_pHumanImageLib = 0;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pHumanImageLib

## Status

- Confidence: very strong for type, zero initializer, sole definition, owner/emitter, source placement, exact four-write/no-read lifetime, old-human class route, and one-definition behavior; original PDB spelling alone remains unavailable.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PM][0x0069b43c-0x0069b440.g_pHumanImageLib](by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md), IDA `dword_69B43C`.
- Canonical owner: [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) in [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).

## Meaning

`g_pHumanImageLib` is the global pointer to the legacy human/equipment image library. This is the old archive-family renderer that loads body-part and equipment frame tables such as `HEAD`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`.

Keep this global with `render/HumanImageLib.cpp`. Do not confuse it with the newer table-driven [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) singleton at `0x0067a760`.

`g_pHumanImageLib` is the project-canonical source-facing name and this page is the sole source-definition emitter. The definition is `HumanImageLib *g_pHumanImageLib = 0;` at position 20 in [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Physical UID0001PM, Singleton cleanup lowering, scalar deletion, and RTTI/vtable data must not emit duplicate storage or helper definitions.

## Write Evidence

IDA MCP on 2026-05-26 reports these writes to `0x0069b43c`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004d277b` | `HumanImageLib::HumanImageLib` | Stores the constructed `HumanImageLib*` singleton. |
| `0x004d2782` | `HumanImageLib::HumanImageLib` | Clears the singleton on the null/guard path. |
| `0x004d4f44` | [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5b80` | [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |

The constructor also installs the [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) and initializes many embedded `ProtectedArray<...Info>` members recorded in [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## 2026-06-14 C001 IDA Recheck

The current live IDA MCP session is active on `NexusTK.exe.i64` with auto-analysis and Hex-Rays ready. `lookup_funcs` reconfirmed `0x0069b43c` is not a function; `0x004d2720` is the large HumanImageLib constructor/local method body, `0x004d4ad0` is the ordinary destructor, `0x004e5b80` is the singleton-clear helper, and `0x004e6460` is the scalar deleting destructor.

Current `xrefs_to 0x0069b43c` reports exactly four refs and no additional pages: constructor publish/null-clear at `0x004d277b` / `0x004d2782`, ordinary destructor clear at `0x004d4f44`, and clear helper at `0x004e5b80`. `analyze_component` reconfirmed the constructor references old-human resource table names including `headtable.txt`, `headsptable.txt`, `swordtable.txt`, `speartable.txt`, and `bowtable.txt`; the constructor/destructor share the old-human `ProtectedArray<...Info>` vtables and `HumanImageLib` vtable at `0x0061b6d4`; and the scalar deleting destructor delegates to the ordinary destructor before optional deallocation.

## Ownership Decision

This is source-owned by `HumanImageLib`, not by [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), or consumers that only draw a resolved human image. The shared frame-table loader remains in `ImageFrameTable.cpp`; the old-human array fields, frame handles, and singleton lifetime belong here.

The direct `Singleton<HumanImageLib>` base explains publication and clearing in generated machine code. Its RTTI PMD `{mdisp=4,pdisp=-1,vdisp=0}` and EBO overlap at `+0x04` prove that the apparent constructor/destructor stores are base-lifetime lowering, not a second handwritten storage declaration. Exactly one observed slot and the project source contract therefore require this one definition only.

## Score Rationale

Completion is `92` because the page records exact loader-zero backing storage, type, initializer, owner/emitter, position, source file, all four write-only lifetime refs, zero direct reads, Singleton source cause, class/layout/vtable route, and one-definition exclusions. Confidence is `94`: all behavioral and placement questions are closed; only unrecoverable original lexical spelling prevents a higher score.

## Historical / Superseded Assumptions

- Earlier wording left definition placement and formal C++ blank pending coordination with UID0001PM. The accepted one-definition analysis now makes UID0000R5 the sole emitter and UID0001PM false/non-emitting.
- The old physical-page `0xffffffff` premise was a raw-mapping error. Current MCP and PE arithmetic prove zero-filled storage; this source definition therefore uses the ordinary null initializer `0`.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:00017A][0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster](by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md)
- [UID:0001PM][0x0069b43c-0x0069b440.g_pHumanImageLib](by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)

## Changes

- 2026-06-14 C001 low-confidence global refresh:
  - Changed score from `88/82` to `89/86`.
  - Summary/evidence: current IDA MCP reconfirmed active IDB health, exact four-ref storage xref set, constructor publish/null-clear, destructor/helper clears, scalar deleting destructor delegation, old-human resource table strings, and `HumanImageLib`/`ProtectedArray<...Info>` vtable context. Owner/emitter remain [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md); no C++ or IDA database edits were made because final original symbol spelling remains open.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents backing storage, owner, legacy human/equipment image-library role, write/clear evidence, vtable/layout refs, ownership decision, and distinction from `NewHumanImageLib`; final original symbol spelling remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Evidence: live IDA MCP reports four xrefs to `0x0069b43c`, with constructor writes at `0x004d277b`/`0x004d2782`, non-deleting destructor clear at `0x004d4f44`, and singleton clear helper at `0x004e5b80`.
- 2026-06-20 B004 Rule 26 source-name note: kept owner/emitter [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), retained `g_pHumanImageLib` as the best descriptive source-facing name for `dword_69B43C`, and recorded that exact original symbol spelling and duplicate global definition placement remain unresolved.
- 2026-07-21 B001 accepted UID0001PM callback: set `92/94`, position 20, inserted the sole typed zero definition, documented direct Singleton lifetime lowering and four-write/no-read behavior, and historicalized the superseded blank-definition and `0xffffffff` assumptions.

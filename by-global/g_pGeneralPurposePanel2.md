*** UID:0000R1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel2;

GeneralPurposePanel2 *g_pGeneralPurposePanel2 = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pGeneralPurposePanel2

## Status

- Confidence: very strong for address, pointer type, external linkage, zero initializer, one-definition route, and complete reference inventory.
- Address: `0x0069b358`
- Source-facing name: `g_pGeneralPurposePanel2`; current MCP did not expose that spelling as a saved global, so the name is a strong project inference rather than a current saved-name claim.
- Owner/source file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), emitter position 20.
- Exact storage: [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md)

## Symbol Role

`g_pGeneralPurposePanel2` is the sole externally linked, zero-initialized `GeneralPurposePanel2 *` definition for the smaller alternate one-child side-panel shell. The direct Singleton base publishes and clears the slot through compiler lowering; MapPane/UserPane code reads it to reach the child-zero `NewSystemMessagePane` interface.

## Definition And Storage Evidence

- Physical [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md) is four loader-zero bytes in the `.data` virtual tail, not source-initialized `0xffffffff` data.
- This semantic page carries the only C++ definition. UID00005R supplies one matching extern declaration after the complete class; the physical page is false/non-emitting and cannot duplicate the definition.
- UID0004UU constructor lowering publishes the adjusted complete object at `0x004b8872` and emits a null fallback at `0x004b8879`.
- UID0004UV ordinary destructor lowering clears the slot at `0x004b8925`; [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) clears it during constructor unwind; UID0004UZ scalar-wrapper lowering clears it at `0x004b8adc`.
- Direct RTTI has only `GeneralPurposePanel2`, `LObject`, and `Singleton<GeneralPurposePanel2>`; the Singleton PMD `{4,-1,0}` plus the 12-byte allocation proves empty-base overlap and compiler-managed publication/clear.
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) is called from `UserPane::OnServerMessage` at `0x005a771b`.
- Historical 2026-06-07 `0xffffffff` and 2026-06-16 saved-name observations remain provenance. Fresh 2026-07-21 raw/PE/MCP checks prove loader zero and did not expose the source spelling as a current saved global.

## Complete Fourteen-Reference Inventory

| Address | Classification and role |
| --- | --- |
| `0x004b8872`, `0x004b8879` | UID0004UU compiler Singleton publication and null fallback. |
| `0x004b8925` | UID0004UV implicit Singleton clear. |
| `0x004b8a80` | UID00015Z constructor-unwind Singleton clear. |
| `0x004b8adc` | UID0004UZ inlined Singleton clear in scalar destruction. |
| `0x005049ee` | UID0002QH null-tested read and virtual scalar deletion with flag 1. |
| `0x0050fef7` | UID0003TY child-zero NewSystemMessagePane stop/reset route. |
| `0x005a7711` | UID0003VB one-time `SwitchActiveChild(0, NULL)` publication before dispatch. |
| `0x005a792e`, `0x005a7ed5`, `0x005a7fb9` | UID0003VB child-zero decoded text/empty operation branches. |
| `0x005a9143` | Raw UserPane per-record text route, mode 1, then pending-state clear. |
| `0x005aac2b` | Raw UserPane code 1..52 system-message mapping route. |
| `0x005aacda` | UID0003UN child-zero `RefreshSpelledPane` route. |

MCP returned `xref_count:14` with `more:false`: five lifetime writes and nine reads. All nine readers are consumers; none allocates, publishes, clears, or owns this global.

## Ownership Notes

Keep the definition in the same source module as `GeneralPurposePanel2`, after the complete primary panel family and before the GP2 class declaration. The source form is exactly one forward declaration plus `GeneralPurposePanel2 *g_pGeneralPurposePanel2 = 0;`.

The class/source closure is now complete: six authored methods live on exact children, compiler helper/scalar/vtable pages are non-emitting, and UID0002VS documents physical storage only. Raw address labels, static/function-local linkage, manual singleton assignments, `-1` initialization, duplicate definitions, and consumer ownership are rejected.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0004UU][0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor](by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md)
- [UID:0004UV][0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor](by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md)
- [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md)
- [UID:0004UZ][0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor](by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, owner, alternate side-panel role, constructor/destructor/clear-helper evidence, child accessor/switch helper, migration caveat, and refs.
- 2026-06-05: Marked reconstructable under [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). Evidence: live IDA MCP reports 14 xrefs to `0x0069b358`; decompilation confirms `0x004b8830` stores `dword_69B358`, while `0x004b88f0`, `0x004b8a80`, and `0x004b8aa0` clear it from the `GeneralPurposePanel2` lifecycle.
- 2026-06-07: Raised confidence from `84` to `86` during Batch 039 parent-gate follow-up after splitting exact storage [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md). The parent now satisfies the corrected `85/85` gate for the storage child.
- 2026-06-16 C001 Goal 2 global/IDA refresh: raised `86/86` to `88/89` after live IDA reconfirmed storage bytes, xrefs, lifecycle writers/clears, owner route through [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), and saved the singleton and lifecycle names in the IDB. No final C++ was added because member/method spelling and source-level helper names remain below final confidence.
- 2026-07-21 B005 accepted UID0002VS callback: raised `88/89 -> 92/94`, set emitter position 20, added the sole zero-initialized typed definition, documented all 14 references and the direct Singleton compiler lifecycle, corrected active ff/saved-name claims while preserving them as history, and closed the one-definition/source-placement/consumer/negative-evidence blockers.

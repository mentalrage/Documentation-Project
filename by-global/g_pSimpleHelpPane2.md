*** UID:0000SA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SimpleHelpPane2 *g_pSimpleHelpPane2 = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pSimpleHelpPane2

## Status

- Address: [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Preferred source name: `g_pSimpleHelpPane2`.
- Confidence: strong.

## Purpose

`g_pSimpleHelpPane2` points to the active [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md), the `HelpPane`-derived anchored tooltip and direct `Singleton<SimpleHelpPane2>` specialization. This page emits the one external era-consistent definition with `NULL`; the complete class declaration supplies the matching `extern` declaration. Exact storage child [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md) records binary storage and inserts only a covered-by marker, never a second definition. The adjacent factory replaces an active instance, while helper UID00022O wraps factory calls and checks anchor/cursor state.

## Evidence Notes

- 2026-06-16 C001 live IDA MCP reports `0x0067a7d4` as an exact four-byte `.data` singleton slot, initialized to `0x00 0x00 0x00 0x00`, with 9 data references; the surrounding `0x0067a7d0-0x0067a7f0` window is still zero-filled.
- IDA already had `g_pSimpleHelpPane2`; C001 saved source-quality labels for `SimpleHelpPane2_Constructor`, `SimpleHelpPane2Factory`, and `SimpleHelpPane2_ScalarDeletingDestructor`. `ClearSimpleHelpPane2Singleton` was already present and was rechecked.
- References include both the direct `SimpleHelpPane2` constructor path and [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md): adjusted construction stores at `0x004c751b/0x004c7522` are compiler-inlined Singleton base construction; the factory source reads/replaces the active singleton at `0x004c76ad` and observes the constructed/fallback result at `0x004c772a/0x004c7731`.
- Clears at `0x004c75fa`, `0x004ce320`, and `0x004ce520` are ordinary reverse Singleton destruction, construction-unwind cleanup, and scalar-wrapper inlining respectively. They are one source lifecycle, not three handwritten assignments.
- A UI feature caller at `0x00451adb` reads the pointer before using or closing the active `SimpleHelpPane2` tooltip.
- 2026-05-28 IDA MCP raw disassembly confirms [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) immediately after the factory; the helper page does not add a new global, but it is part of the same singleton management neighborhood.
- 2026-05-30 live IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearSimpleHelpPane2Singleton` at `0x004ce320`, which writes zero to this storage from constructor/factory unwind cleanup.

## Source-Quality Notes

- Owner/emitter remains [UID:0000JU][HelpPanes](by-file/HelpPanes.md). The constructor, factory, ordinary destructor, unwind helper, and deleting wrapper all belong to the HelpPanes tooltip neighborhood.
- External linkage is required: MiniMapDialog code at `0x00451adb` reads this storage outside the HelpPanes executable cluster. A file-static definition cannot satisfy that cross-translation-unit source use.
- The formal block emits one external definition plus `[[CHILDREN]]`; UID0000D7 emits the `extern` declaration before qualified child definitions. `NULL` matches the accepted mid-2000s project convention and does not alter zero initialization.
- RTTI direct base descriptor `0x00648078` proves `Singleton<SimpleHelpPane2>` at PMD `+0x224`. Constructor/ordinary/scalar lifecycle stores are therefore compiler/base output; no human constructor or destructor duplicates them.
- Reject static linkage, `nullptr`, a second storage definition, generic singleton-registry ownership, MiniMap ownership, and explicit lifecycle assignments. Exact name/type/address, external consumer, source module, and one-definition route are resolved.
- Skipped unsafe IDA edits: no prototypes, struct/member names, locals, or helper signatures were changed. The only saved edits were function labels already backed by class/vtable/global evidence.

## Nine-Reference Classification

| Address | Role | Source classification |
| --- | --- | --- |
| `0x00451adb` | MiniMapDialog read/use | External source consumer; proves non-static linkage. |
| `0x004c751b/0x004c7522` | constructor publish/fallback | Inlined Singleton base construction. |
| `0x004c75fa` | ordinary destructor clear | Inlined reverse Singleton base destruction. |
| `0x004c76ad/0x004c772a/0x004c7731` | factory read/result/fallback | Source-facing replacement flow plus inlined construction result. |
| `0x004ce320` | construction-unwind clear | Compiler EH cleanup of the Singleton base. |
| `0x004ce520` | scalar wrapper clear | Compiler deleting-wrapper inlining of the same destruction. |

## Score Rationale

- Completion `92`: exact type/name/address, zero initializer, all nine refs, external consumer/linkage, class declaration, one-definition route, implicit lifecycle source cause, and source placement are complete.
- Confidence `94`: storage bytes, xrefs, RTTI, class/factory/destructor routes, and accepted HourPane/SimpleHelpPane comparators independently agree. Original header placement spelling remains the only lexical cap.

## Cross-References

- [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)

## Changes

- 2026-07-14 B003 UID00048L implementation callback: raised `87/92 -> 92/94`, retained UID0000JU owner/emitter and blank optional position, replaced the stale file-static `nullptr` declaration with the exact external `NULL` definition, classified all nine refs by source/compiler role, and added direct Singleton RTTI, MiniMap linkage, one-definition, rejected-alternative, and score evidence. Earlier static/explicit-lifecycle text below is historical provenance only.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to `SimpleHelpPane2` construction, replacement factory, cleanup helpers, and the same HelpPanes tooltip-support neighborhood. No score change and no reconstruction C++ were added.
- What existed before: the page had correct address and role notes but unevaluated completion/confidence metadata and only summarized the xrefs.
- What changed to: the page now records the current live IDA MCP xref set for constructor, factory, cleanup, clear-helper, and UI caller paths. Completion/confidence were set to `78/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0067a7d4` as a four-byte `.data` singleton pointer with 9 xrefs: UI caller read at `0x00451adb`, constructor assignment/fallback at `0x004c751b`/`0x004c7522`, destructor/helper clear at `0x004c75fa`, factory read/write/fallback at `0x004c76ad`/`0x004c772a`/`0x004c7731`, and clear-helper/destructor cleanup at `0x004ce320`/`0x004ce520`.
- 2026-06-06: Raised completion/confidence from `78/88` to `84/90` and removed raw storage-label wording.
  - Reasoning: current live IDA MCP verifies exact zero-initialized storage, all nine data references, constructor publish/fallback clear, ordinary destructor clear, factory read/write/fallback, support-helper clear, deleting-destructor clear, and UI dismissal use.
  - Summary and evidence: `0x0067a7d4` is an exact four-byte `.data` singleton slot initialized to `0x00 0x00 0x00 0x00`; xrefs cover UI read `0x00451adb`, constructor publish/fallback `0x004c751b`/`0x004c7522`, ordinary destructor clear `0x004c75fa`, factory read/write/fallback `0x004c76ad`/`0x004c772a`/`0x004c7731`, support clear `0x004ce320`, and deleting-destructor clear `0x004ce520`.
- 2026-06-16 C001 Goal 2 refresh: Raised `84/90` to `87/92`; live IDA reconfirmed zero storage and the exact 9-reference lifecycle/consumer set, and saved `SimpleHelpPane2_Constructor`, `SimpleHelpPane2Factory`, and `SimpleHelpPane2_ScalarDeletingDestructor` labels. The parent/emitter route remains HelpPanes; final C++ stays blank pending helper visibility, field names, and declaration placement.
- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added formal singleton declaration `static SimpleHelpPane2 *g_pSimpleHelpPane2 = nullptr;` plus `[[CHILDREN]]`.
  - Preserved owner/emitter routing through [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and recorded that exact storage child [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md) is a covered/no-duplicate route, not a second definition.

*** UID:0000FA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeItor<EventHandler *> concrete-instantiation marker. Generic authored source
// is emitted by UID0004YK Tree.h; destructor/vtable glue is compiler-covered.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TreeItor_near_class_EventHandler___

## Current Accepted UID0004YK Instantiation Disposition

This page documents the 12-byte TreeItor<EventHandler *> instantiation: vptr at +0, Tree<EventHandler *>* at +4, and current index at +8. The generic declaration and movement source live in Tree.h. The concrete ordinary/scalar destructors, vtable, RTTI, EH references, and alignment are compiler consequences; EventHandlerIterator and the near-class spelling are superseded analysis aliases.

## Status

- Confidence: strong for dispatcher-local iterator support behavior; medium-high for final source-facing template/header placement.
- Source-facing type: `TreeItor<EventHandler *>` / `TreeItor<EventHandler*>`. The filename/title spelling `TreeItor_near_class_EventHandler___` is a generated documentation alias from Ghidra/Wave2's `near class` artifact, not plausible original C++.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), as the concrete `TreeItor<EventHandler *>` iterator used by dispatcher traversal.
- Historical generated-output lead: `class_TreeItor_near_class_EventHandler___.cpp`; use IDA, local PE bytes, and the linked by-* docs as current scoring authority.
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

`TreeItor<EventHandler *>` is the generated/source-facing iterator helper for the event-handler tree. [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) constructs stack iterator records with this vtable while routing events through child handlers, translated child coordinates, ordering, and removal paths. It remains dispatcher-local support; the generated `near_class` spelling is retained only for the documentation filename.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~TreeItor<EventHandler *>` | `0x004a7cf0-0x004a7cf7` | Reinstalls iterator vtable and returns. |
| `ScalarDeletingDestructor` | `0x004a7dd0-0x004a7df4` | Reinstalls vtable and conditionally frees heap storage through compiler delete glue. |

The previous `0x004a7cf0-0x004a7cf6` and `0x004a7dd0-0x004a7df3` rows used inclusive terminal-byte notation. The corrected ranges above are half-open. B008's local PE audit also verifies `0x004a7cf7-0x004a7d00` and `0x004a7df4-0x004a7e00` as `0xcc` alignment.

## Ownership Notes

Keep this with the dispatcher handler-tree support code. It should not be a standalone source migration target unless the original project used a broad template implementation file and other `TreeItor<>` specializations point to the same source.

## Evidence Notes

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) is scored `89/85`, has the valid proposed path `NexusTK/ui/core/`, and explicitly lists `TreeItor<EventHandler *>` as dispatcher handler traversal/support content.
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) records the exact iterator destructor at `0x004a7cf0-0x004a7cf7` and scalar deleting destructor at `0x004a7dd0-0x004a7df4`.
- The same memory page records stack iterator construction with `TreeItor<EventHandler*>::vftable` during `RouteEventToHandlers`, `DispatchToChildren`, and `DispatchToTranslatedChildren`.
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) documents the iterator record layout: vtable at `+0x00`, tree pointer at `+0x04`, and current index at `+0x08`.
- [UID:000258][0x00619340-0x006196bc.ErrorEventReadOnlyData](by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md) places the `TreeItor<EventHandler*>` vtable in the Error/Event read-only data run with neighboring EventDispatcher/Event/EventMan vtables.
- 2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed the iterator destructor at `0x004a7cf0` size `0x7` and the scalar deleting destructor at `0x004a7dd0` size `0x24`; boundary bytes show the vtable store to `0x00619650`, a compact return body, and `0xcc` alignment after `0x004a7df3` before `EventDispatcher` deleting-destructor code.
- 2026-06-14 xrefs keep this iterator local to dispatcher traversal: `0x004a7cf0` has five stack-construction refs from `SetPaneOrder`, `RemovePaneEntry`, `RouteEventToHandlers`, `DispatchToChildren`, and `DispatchToTranslatedChildren`; `0x00619650` has eleven refs from the same dispatcher traversal family plus destructor/deleting-destructor bodies.
- 2026-06-14 callee refresh keeps the iterator destructor leaf-like and the scalar deleting destructor as compiler deletion glue calling only the heap-free helper path, so this remains dispatcher support metadata rather than standalone feature logic.
- 2026-06-19 B008 local PE verification confirms the exact half-open body ranges, the `0x004a7cf7-0x004a7d00` and `0x004a7df4-0x004a7e00` padding spans, and the `TreeItor<EventHandler *>` source-facing spelling policy. No new live-MCP claims are made because the MCP endpoint was unavailable during that pass.

## Autogen Status

- Reconstructable: true for dispatcher-local iterator support.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). Both parent and child now meet the confidence threshold for attachment.
- Code: route marker with `[[CHILDREN]]` for target-specific source-shape reasons. The iterator destructor and scalar deleting wrapper behavior are clear, but this class page should not emit weak duplicate destructor/glue code; the source belongs to dispatcher-local support declarations and exact children rather than a standalone iterator class body.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page now records the destructor pair, dispatcher-local stack iterator xrefs, iterator layout, vtable-data child, direct EventDispatcher file parent, current IDA boundary/callee refresh, and accepted `[[CHILDREN]]` route marker. Completion remains capped because original template/header spelling is still unresolved and destructor/deleting-destructor glue is not hand-authored. |
| Confidence `88` | Confidence is strong that this specialization is EventDispatcher traversal infrastructure: the direct file parent, exact helper island, layout page, and current IDA xrefs remain local to dispatcher traversal. Confidence is not higher because final source declaration shape is still inferred. |

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)
- [UID:000258][0x00619340-0x006196bc.ErrorEventReadOnlyData](by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md)

## Changes

- 2026-06-30 B010 accepted EventDispatcher implementation callback:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, with formal C++ described as blank/no duplicate code.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter unchanged as [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and formal `RECONSTRUCTION_CPP` now emits an accepted `TreeItor<EventHandler *>` route marker with `[[CHILDREN]]`.
  - Evidence: accepted B010 report used existing iterator destructor/deleting-destructor evidence, the UID000146 support-island route, and current EventDispatcher source-family routing to preserve no duplicate destructor/glue output while keeping child emission active.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the iterator destructor/deleting-destructor mapping, dispatcher ownership notes, and layout/memory cross-references; score remains moderate because the page covers a small generated specialization and final template source placement is not proven.
- 2026-06-02: Raised to `78/84`, marked reconstructable, attached to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and added parent/path, layout, helper-island, stack-iterator, and read-only-data evidence. C++ remained blank in that historical pass because final template/header spelling was still not source-quality; B010 supersedes this with the route marker above.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with generated-output wording and no current direct xref refresh on the class page.
  - After: `85/86`, preserving EventDispatcher owner/emitter routing and blank C++ under the then-current code-entry wording; the 2026-06-29 B012 implementation supersedes this with the target-specific no-duplicate-code rationale above.
  - Summary/evidence: live IDA MCP reconfirmed iterator destructor/deleting-destructor sizes, stack iterator construction refs, vtable-data refs, boundary bytes, and the lack of standalone feature behavior.
- 2026-06-29 B012 implementation of UID000146 empty-emitter report:
  - Score unchanged at `85/86`.
  - Summary/evidence: replaced the stale active `90/90+` gate wording with the current target-specific no-code proof. The iterator support page remains reconstructable and routed through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), but UID000146 now emits the formal split/index marker while this page avoids duplicate destructor/compiler-glue output.
- 2026-06-21 Rule 26 incorporation of B008 source-quality report:
  - Score unchanged at `85/86`.
  - Summary/evidence: B008's local PE pass corrected the iterator destructor to half-open `0x004a7cf0-0x004a7cf7`, corrected the iterator scalar deleting destructor to `0x004a7dd0-0x004a7df4`, recorded the neighboring `0xcc` padding spans, and clarified that `TreeItor<EventHandler *>` is the source-facing spelling while the generated `near_class` title remains a documentation alias.

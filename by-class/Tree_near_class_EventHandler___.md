*** UID:0000F8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Tree<EventHandler *> concrete-instantiation marker. Generic authored source is
// emitted by UID0004YK Tree.h; vector/destructor/vtable glue is compiler-covered.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Tree_near_class_EventHandler___

## Current Accepted UID0004YK Instantiation Disposition

This page documents the concrete Tree<EventHandler *> instantiation, not an EventDispatcher-local class declaration. Its vptr plus std::vector object is 0x10 bytes and its TreeNode<EventHandler *> records are 0x1c bytes. All generic authored behavior comes from Tree.h; concrete destructor, scalar wrapper, vtable, RTTI, EH, vector, and alignment bodies are compiler-generated. The near-class filename and historical EventHandlerRecord wrapper remain analysis aliases only.

## Status

- Confidence: strong for dispatcher-embedded tree behavior and resolved UID0004YK generic template/header placement.
- Source-facing type: `Tree<EventHandler *>` / `Tree<EventHandler*>`. The filename/title spelling `Tree_near_class_EventHandler___` is a generated documentation alias from Ghidra/Wave2's `near class` artifact, not plausible original C++.
- Generic source file: [UID:0004YK][Tree](by-file/Tree.md), emitted through `NexusTK/util/Tree.h`; [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) is the concrete consumer and evidence route.
- Historical generated-output leads: `class_Tree_near_class_EventHandler___.cpp` and `Tree_near_class_EventHandler___.cpp`; use IDA, local PE bytes, and the linked by-* docs as current scoring authority rather than standalone generated-source filenames.
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

This is the concrete `Tree<EventHandler *>` instantiation used by [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) for handler traversal. It is embedded at `EventDispatcher + 0x04` and consists of the `LObject`-derived Tree object plus direct `std::vector<TreeNode<EventHandler *> >` storage. The dispatcher constructor installs this instantiation's vtable, while all generic authored declarations and algorithms come from UID0004YK `Tree.h`.

The current source-facing storage model is `Tree<EventHandler *>` with a direct vector member. Its 28-byte nodes use five generic links, `EventHandler *data` at `+0x14`, and `disabled` at `+0x18`.

### Historical Superseded Event Record Wrapper Draft

The following draft is retained verbatim as prior analysis provenance; it is not current authored source:

The source-facing storage model is:

```cpp
struct EventHandlerRecordVector {
    EventHandlerRecord *begin;
    EventHandlerRecord *end;
    EventHandlerRecord *capacityEnd;
};

struct EventHandlerTree {
    void *vtable;
    EventHandlerRecordVector records;
};
```

The vector header begins at tree offset `+0x04`, corresponding to dispatcher offsets `+0x08`, `+0x0c`, and `+0x10`. This historical wrapper used `EventHandlerRecordVector records`; the current model reads the same bytes as direct `std::vector<TreeNode<EventHandler *> >` storage. `TreeNodeData` and `cls_0x4a87a0` are likewise historical/generated placeholder terminology.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~Tree<EventHandler *>` | `0x004a7cd0-0x004a7ce9` | Compiler-generated instantiation support: reinstalls the Tree vtable, destroys direct `std::vector<TreeNode<EventHandler *> >` storage through [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), then tail-jumps to `LObject` cleanup. The inline virtual destructor in Tree.h is the source cause. |
| `ScalarDeletingDestructor` | `0x004a7d80-0x004a7dc8` | Repeats the destructor body, reads MSVC delete flags, optionally calls the operator-delete wrapper, and includes compiler vector-delete/guard glue. |

The previous `0x004a7cd0-0x004a7ce8` and `0x004a7d80-0x004a7dc7` rows used inclusive terminal-byte notation. The corrected ranges above are half-open.

## Local PE Byte Evidence

B008's 2026-06-19 local PE audit against `NexusTK.exe` confirms exact bytes and padding:

| Span | Interpretation |
| --- | --- |
| `0x004a7cd0-0x004a7ce9` | 25-byte ordinary tree destructor: save `esi`, set `ecx = this + 4`, store `Tree<EventHandler *>::vftable` at `[this]`, call `0x004a87a0` / `FreeHandlerRecordVector`, restore `ecx = this`, and tail-jump to `0x004f4a90` / `LObject` non-deleting destructor body. |
| `0x004a7ce9-0x004a7cf0` | Seven bytes of `0xcc` alignment before the iterator destructor. |
| `0x004a7d80-0x004a7dc8` | 72-byte scalar deleting destructor: vtable restore, vector free, `LObject` cleanup, delete-flag test, optional `0x004f4ac0` operator-delete wrapper, and compiler vector-delete/guard-shaped path. |
| `0x004a7dc8-0x004a7dd0` | Eight bytes of `0xcc` alignment before the iterator scalar deleting destructor. |

The ordinary destructor remains a raw/no-function-object caveat in IDA: existing docs record `lookup_funcs 0x004a7cd0` resolving inside a broader constructor/unwind context, while Wave2/Ghidra records a 25-byte destructor body and local bytes prove the exact complete body. Treat it as source-declared/generated-binary destructor/EH cleanup support for the concrete tree wrapper, not as independent feature logic.

## Vtable Slot Notes

Local `.rdata` dword evidence for `0x00619628-0x00619638`:

| Address | Value | Interpretation |
| --- | --- | --- |
| `0x00619628` | `0x00646eb4` | `Tree<EventHandler *>` complete-object-locator pointer. |
| `0x0061962c` | `0x004a7d80` | `Tree<EventHandler *>::ScalarDeletingDestructor`. |
| `0x00619630` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` / runtime-class accessor slot. |
| `0x00619634` | `0x0041b6c0` | inherited `LObject::VirtualNoop(int, int)` / default no-op slot. |

These inherited slots are not Tree-specific methods. The tree vtable is source-declared/generated-binary data for the concrete dispatcher support type.

## Ownership Notes

Do not treat this as a standalone container source file. The only observed concrete role is the EventDispatcher handler tree at `EventDispatcher + 0x04`, but concrete use does not transfer generic source ownership. UID0004YK `NexusTK/util/Tree.h` owns the Tree declaration and algorithms; [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) retains only consumer code and concrete instantiation evidence.

The resolved declaration route is reusable project `Tree.h`, also used by FolderTreePane. `EventDispatcher.h` includes it and embeds `Tree<EventHandler *>`; only `HandlerFindFunc` and dispatcher-specific list/routing declarations remain local. No standalone `Tree<EventHandler*>.cpp` or custom Event record/tree declaration is authored.

Rejected owner/source alternatives:

- `Tree_near_class_EventHandler___` as final source spelling: generated alias only.
- `Tree<near class EventHandler *>` / `Tree<near_class_EventHandler_*>`: Ghidra artifact; IDA/MSVC decorated vtable names support `Tree<EventHandler *>`.
- `EventHandler` ownership: `EventHandler` is the stored element/interface type, not the owner of vector lifecycle or traversal.
- `LObject` ownership: `LObject` supplies inherited slots and base cleanup only.
- Read-only Error/Event aggregate ownership: [UID:000258][0x00619340-0x006196bc.ErrorEventReadOnlyData](by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md) is a mixed data container; exact child [UID:0003I5][0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData](by-memory/0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData.md) routes this subset through EventDispatcher.

## Historical Binary Evidence Under Superseded Event Record Labels

The observations below retain earlier `EventHandlerRecordVector records` terminology as exact dated analysis provenance. Those labels describe the direct vector bytes and do not establish custom authored types or EventDispatcher-local generic ownership.

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) is scored `89/85`, has the valid proposed path `NexusTK/ui/core/`, and explicitly lists `Tree<EventHandler *>` as handler traversal/support content.
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) records the corrected half-open destructor range at `0x004a7cd0-0x004a7ce9` and scalar deleting destructor at `0x004a7d80-0x004a7dc8`.
- The same memory page records the dispatcher constructor installing `Tree<EventHandler*>::vftable` on the embedded tree and sentinel-node setup for traversal.
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) documents the embedded tree at dispatcher offset `+0x04`, 28-byte handler records, and the `EventHandlerRecordVector records` field accessed through tree offset `+0x04`.
- [UID:000258][0x00619340-0x006196bc.ErrorEventReadOnlyData](by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md) places the `Tree<EventHandler*>` vtable in the Error/Event read-only data run with the neighboring EventDispatcher/Event/EventMan vtables.
- 2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed the tree destructor bytes at `0x004a7cd0-0x004a7ce8` and the scalar deleting destructor at `0x004a7d80` size `0x48`; `lookup_funcs 0x004a7cd0` still resolves inside the broader constructor body, so the raw destructor start remains documented as a source-shaped body rather than an IDA-promoted function object.
- 2026-06-14 xrefs show `0x004a7cd0` referenced from EventDispatcher constructor read-only/unwind data, while `0x004a7d80` is referenced by the `Tree<EventHandler*>` vtable at `0x0061962c`. Vtable refs to `0x0061962c` come from the EventDispatcher constructor/destructor/reset family and the tree scalar deleting destructor.
- 2026-06-14 callee/byte refresh confirms the scalar deleting destructor calls the handler-record vector free helper `0x004a87a0`, inherited cleanup `0x004f4a90`, conditional heap free `0x004f4ac0`, and guard helper; boundary bytes after the body are `0xcc` alignment before the iterator deleting-destructor range.
- 2026-06-19 B008 local PE verification confirms the exact half-open ranges, padding spans, vtable dwords, inherited `LObject` slot names, and generated-name rejection summarized above. The local MCP endpoint was unavailable during that pass, so no new live-MCP claims are made beyond existing pages.

## Autogen Status

- Reconstructable: true for dispatcher-local tree support.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). Both parent and child now meet the confidence threshold for attachment.
- Code: route marker with `[[CHILDREN]]`. The active combined-score/emitter gate is a minimum eligibility gate, but this class/specialization page should not emit weak or duplicate method code: the only target-owned bodies are destructor/destructor-glue bodies, the ordinary destructor is raw/EH-cleanup shaped, the scalar deleting destructor is MSVC compiler glue, and a concrete `class Tree<EventHandler *>` shell could conflict with a later shared `Tree<T>` template/header model. Exact vector/relink/allocation helper children carry safe draft code where behavior and source names are stronger.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page records the `Tree<EventHandler *>` instantiation, generated-alias rejection, exact half-open destructor ranges, padding spans, direct vector storage, inherited vtable slots, local PE evidence, resolved UID0004YK source ownership, and EventDispatcher consumer route. |
| Confidence `91` | The helper island, layout pages, vtable data, PE bytes, dual Tree instantiations, and generated Tree.h readback agree. Remaining uncertainty concerns the raw/no-function-object destructor boundary, not generic source placement. |

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)
- [UID:000258][0x00619340-0x006196bc.ErrorEventReadOnlyData](by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md)

## Changes

- 2026-06-30 B010 accepted EventDispatcher implementation callback:
  - Before: `COMPLETION:87`, `CONFIDENCE:90`, with formal C++ described as blank/no duplicate code.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter unchanged as [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and formal `RECONSTRUCTION_CPP` now emits an accepted `Tree<EventHandler *>` route marker with `[[CHILDREN]]`.
  - Evidence: accepted B010 report used existing tree destructor/deleting-destructor evidence, UID000146 support-island routing, and child vector/relink/allocation emitters to preserve no duplicate destructor/glue output while keeping exact child emission active.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the destructor/deleting-destructor behavior, dispatcher-embedded ownership, and memory/layout links; score remains moderate because this is a small generated specialization rather than a proven standalone source file.
- 2026-06-02: Raised to `78/84`, marked reconstructable, attached to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and added parent/path, layout, helper-island, and read-only-data evidence. C++ remained blank in that historical pass because final template/header spelling was still not source-quality; B010 supersedes this with the route marker above.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with generated-output wording and no current direct xref refresh on the class page.
  - After: `85/86`, preserving EventDispatcher owner/emitter routing and blank C++ under the active `90/90+` gate.
  - Summary/evidence: live IDA MCP reconfirmed tree destructor bytes, scalar deleting destructor size/callees, vtable refs, boundary bytes, and the remaining raw-destructor/function-object caveat.
- 2026-06-21 Rule 26 incorporation of B008 source-quality report:
  - Before: `85/86`, generated `near_class` alias treated too prominently, stale inclusive-looking method ranges, `TreeNodeData` storage wording, and old code-entry-gate language.
  - After: `87/90`, owner/emitter unchanged, formal C++ still blank for target-specific template/header and compiler-glue reasons.
  - Summary/evidence: B008 verified local PE bytes for the ordinary destructor `0x004a7cd0-0x004a7ce9`, scalar deleting destructor `0x004a7d80-0x004a7dc8`, padding spans, vtable dwords, inherited `LObject` slots, `EventHandlerRecordVector records` storage, and EventDispatcher-only reachability. The page now rejects standalone generated source ownership and records why no class-page C++ should be emitted yet.

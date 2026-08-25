*** UID:0000R2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewSystemMessageModifyHeightPane;

NewSystemMessageModifyHeightPane *g_pHeightModifyPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pHeightModifyPane

## Status

- Confidence: strong for singleton address and owner.
- Address: `0x0069bc0c`
- Proposed owner: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Primary class: [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- Exact storage: [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md)
- Parent gate: target `88/92`, direct owner file [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) `89/86`, primary class [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md) `85/87`, and singleton storage [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) `88/92` clear the strict `85/85` gate.

## Role

`g_pHeightModifyPane` stores the active new-system-message resize handle singleton. The constructor writes it, cleanup/destructor helpers clear it, and `NewSystemMessagePane` construction creates the owned handle.

## Evidence

- IDA `xrefs_to 0x0069bc0c` reports writes from `0x005881f0` and inlined construction inside `0x00588560`.
- IDA confirms clear paths at `0x005882c0`, `0x0058aaa0`, and `0x0058acc0`.
- The xref cluster keeps the symbol with `NewSystemMessageModifyHeightPane` inside `SystemMessagePanes`.
- 2026-05-25 IDA recheck reports concrete xrefs at `0x00588239`, `0x00588240`, `0x005882da`, `0x00588620`, `0x00588627`, `0x0058aaa0`, and `0x0058ace0`.
- 2026-06-13 A002 live IDA MCP session `a001_goal2_0002UM` rechecked the exact singleton cluster. `get_bytes` at `0x0069bc0c` returns twelve zero bytes, and `get_int` reads `0` at `0x0069bc0c`, `0x0069bc10`, and `0x0069bc14`, correcting the older support-page wording that described the static bytes as all `0xff`.
- 2026-06-13 `xrefs_to(0x0069bc0c)` reconfirmed exactly seven data xrefs: constructor publish/fallback null writes at `0x00588239`/`0x00588240`, cleanup clear at `0x005882da`, nested `NewSystemMessagePane` child-construction publish/fallback null writes at `0x00588620`/`0x00588627`, standalone clear helper at `0x0058aaa0`, and scalar deleting destructor clear at `0x0058ace0`.
- 2026-07-07 B005 current MCP session `507affd6` reconfirmed the same seven refs to `0x0069bc0c`, zero-initialized storage, non-function data status, no bounded names/globals/strings/functions around `0x0069bc04-0x0069bc20`, and UID0002AO aggregate routing; the raw label `dword_69BC0C` remains IDA-only and should not replace this source-facing declaration.
- 2026-06-13 decompilation confirms the source-level lifecycle: standalone constructor `0x005881f0` stores `this` or `0` to `unk_69BC0C`; cleanup `0x005882c0`, clear helper `0x0058aaa0`, and scalar deleting destructor `0x0058acc0` clear it; and `NewSystemMessagePane` constructor `0x00588560` allocates `0x114` / 276 bytes for the owned height-modify child and publishes that child to the same singleton slot.
- 2026-06-13 `lookup_funcs` reconfirmed the relevant bounds: constructor `0x005881f0` size `0xc5`, cleanup `0x005882c0` size `0x29`, drag handler `0x005882f0` size `0x1bc`, nested owner constructor `0x00588560` size `0x238`, clear helper `0x0058aaa0` size `0x0b`, and scalar deleting destructor `0x0058acc0` size `0x5f`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records exact storage, current bytes/values, complete xref set, constructor/nested-constructor publish paths, cleanup/helper/destructor clears, primary class, direct owner file, storage support page, and parent-gate status. It remains below final-source completion because exact original global spelling and surrounding field/helper names are not proven. |
| Confidence | 89 | Live IDA confirms the singleton address, current zero-initialized storage, all seven direct xrefs, constructor and destructor behavior, class/file ownership, and storage support. Confidence is capped below final-source certainty by unresolved original declaration spelling. |
| Reconstructable | true | This is source-owned `SystemMessagePanes.cpp` singleton state, not compiler glue; C++ remains blank until the 95/95 reconstruction-code bar is met. |

## B011 Emission Disposition

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` emits this singleton as formal source in `social/SystemMessagePanes.cpp`:

```cpp
class NewSystemMessageModifyHeightPane;

NewSystemMessageModifyHeightPane *g_pHeightModifyPane = 0;
```

The declaration is source-ready because `0x0069bc0c` has seven current refs through constructor writes, cleanup/destructor clears, nested owner construction, and the clear helper, all under the `NewSystemMessageModifyHeightPane` source family. The aggregate singleton-slot page [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) should not duplicate this declaration; it documents the surrounding cluster and the unreferenced `0x0069bc14` dword.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)

## Changes

- 2026-07-07 B005 UID0002AO support sync:
  - Updated parent-gate/storage score references to `88/92`.
  - Added current MCP session `507affd6` seven-ref reconfirmation for `0x0069bc0c` and preserved the formal declaration unchanged; the UID0002AO aggregate page remains covered-by/reserved proof and does not duplicate this pointer.
- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted formal singleton pointer declaration into `RECONSTRUCTION_CPP CODE`.
  - Added emission disposition tying this declaration to the seven-ref `0x0069bc0c` lifecycle and [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) aggregate storage proof.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/84`. Summary/evidence: the page documents address, owner, resize-handle singleton role, constructor/clear xrefs, IDA recheck sites, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). Evidence: live IDA MCP reports seven xrefs to `0x0069bc0c`, covering constructor writes, inlined construction inside `0x00588560`, clear helper `0x0058aaa0`, and destructor clear at `0x0058acc0`.
- 2026-06-13 A002 Goal 2 global-quality refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`, parent unchanged as [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).
  - Reason: refreshed live IDA evidence documents the exact zero-initialized storage, complete seven-xref lifecycle, nested owner construction, class/file/storage support pages, and strict `85/85` gate status.
  - Evidence: IDA MCP session `a001_goal2_0002UM` `get_bytes`, `get_int`, `xrefs_to`, `lookup_funcs`, `disasm`, and `decompile` confirmed the singleton's current zero bytes/value, publish writes at `0x00588239` and `0x00588620`, fallback null writes at `0x00588240` and `0x00588627`, clears at `0x005882da`, `0x0058aaa0`, and `0x0058ace0`, and the owned child allocation size `0x114` / 276 bytes.

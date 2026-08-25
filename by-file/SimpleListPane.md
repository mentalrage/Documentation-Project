*** UID:0000NQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SimpleListPane

## Status

- Confidence: very strong for current source-root ownership, reusable-control placement, exact whole-file inventory, and standalone CPP/H routing; original lexical helper names remain the principal confidence cap.
- Proposed module: `ui/controls/SimpleListPane.cpp`
- Required sibling header: `ui/controls/SimpleListPane.h`
- Final placement: standalone sibling of [UID:0000KT][ListPane](by-file/ListPane.md), not folded into `ListPane.cpp`.
- Key ranges: [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md), [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md), [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)

## File Role

`SimpleListPane` is a small `ListPane`-derived adapter for fixed, bounds-driven item lists. It constructs the shared list base with fixed row/column parameters and uses caller-supplied bounds to derive list width and height.

This class should stay in reusable UI controls, not in item, clan, board, mail, or menu feature modules. It is lower-level than feature-specific list panes, but narrower than the full [UID:0000KT][ListPane](by-file/ListPane.md) base.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `SimpleListPane::SimpleListPane` | `0x005739a0-0x005739f6` | Raw constructor-shaped code now formal-constructor ready on [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md); preserves an unnamed unused ABI `int`, derives width/height from `RectBounds`, and delegates to `ListPane::ListPane(4, 10, width, height, 1, 1, 1)`. |
| destructor/helper aggregate | `0x00573a00-0x00573c38` | [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) emits the child insertion marker for exact source children. |
| `SimpleListPane::~SimpleListPane` | `0x00573a00-0x00573a98` | [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) emits the source destructor body that frees copied entry buffers. |
| `SimpleListPane::AppendText` | `0x00573aa0-0x00573b08` | [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md) allocates/copies wide text and inserts at the current item count; the spelling is descriptive/inferred. |
| `SimpleListPane::InsertText` | `0x00573b10-0x00573b6d` | [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md) allocates/copies wide text and inserts at the supplied index; the spelling is descriptive/inferred. |
| `SimpleListPane::RemoveText` | `0x00573b70-0x00573bac` | [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md) frees/clears one copied-text slot and removes one list item; the spelling is descriptive/inferred. |
| `SimpleListPane::ReplaceText` | `0x00573bb0-0x00573c38` | [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) frees/removes the old item and allocates/copies/inserts its replacement; the spelling is descriptive/inferred. |
| secondary destructor thunks | `0x00573c38`, `0x00573c43` | Compiler-generated adjustor thunks for secondary base subobjects at offsets `0xa0` and `0xa4`; track for vtable layout but ignore as handwritten source. |
| destructor wrapper | `0x00573c50-0x00573d15` | [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) is compiler-generated scalar-deleting wrapper support for [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md), not a source-emitting destructor body. |
| vtable/RTTI data | `0x00624c60-0x00624d24` | [UID:0003D5][0x00624c60-0x00624d24.SimpleListPaneVtableData](by-memory/0x00624c60-0x00624d24.SimpleListPaneVtableData.md) begins at the primary complete-object-locator pointer and documents all three source-declared/compiler-generated table views and associated RTTI. |

## Ownership Decision

Keep `SimpleListPane` as its own reusable control source/header pair beside `ListPane.cpp`.

- `SimpleListPane` depends directly on `ListPane` and the list storage cleanup path.
- It has no current direct constructor callers in IDA, so feature ownership cannot be inferred from caller fanout.
- Its destructor is virtual/destructor infrastructure reached through vtables rather than ordinary calls.
- Active generated output labels the base destructor call as `ClientItemMenuItemList::~ClientItemMenuItemList()`, but the called function is the shared `ListPane` destructor family. Treat the client-item-menu name as owner pollution.
- Folding the adapter into `ListPane.cpp` remains useful rejected historical context, but the coherent class island, dedicated file/class route, required declaration, and independent generated root now make standalone `SimpleListPane.cpp/.h` the strongest reconstruction.

## 2026-08-14 B009 Whole-File Reconciliation

The exact file-owned code interval is `0x005739a0-0x00573d20`: six source-authored bodies, three compiler-generated destruction items, and seven physical alignment spans. Code successor `0x00573d20` belongs to `ServerSelectPane` and is excluded.

| Physical item | Disposition | SHA256 / route evidence |
| --- | --- | --- |
| constructor `0x005739a0-0x005739f6` | source `SimpleListPane::SimpleListPane`; raw start | `49ACA5AA9281D5F8B45FB5EA4983AAD1C8D326C2C9AE1D5A6952B2563C98ACEA`; no direct xref or VA/RVA pointer hit |
| destructor `0x00573a00-0x00573a98` | source `SimpleListPane::~SimpleListPane` | `5357E00857B78AB093790DC02B81A6FD6AE5080283D2C82522071DB5F5BBD560`; no direct caller, reached through compiler wrapper/vtables |
| append `0x00573aa0-0x00573b08` | source inferred `AppendText` | `9705AE7C7B75FEFA72A8F75A74382D2C91E92C44543D7C850E941D6BFDF3F1A5`; no direct xref/pointer hit |
| insert `0x00573b10-0x00573b6d` | source inferred `InsertText` | `AD3D0C9314C459174BB73F8E8C89184FB4ACE0CAD72F69C0232051C311C635D3`; no direct xref/pointer hit |
| remove `0x00573b70-0x00573bac` | source inferred `RemoveText` | `0CAF736650D5DD67B5176AD7FE9D51715CC3E51313ABEB0177FA373C97AB3B24`; no direct xref/pointer hit |
| replace `0x00573bb0-0x00573c38` | source inferred `ReplaceText` | `11C41F3F9521A6D0E7BB3A4DAC9BC6E95AFFFD080AC46DB220E55E6C0EC227EF`; no direct xref/pointer hit |
| adjustor `0x00573c38-0x00573c43` | compiler-generated, no source | `BF34EED2C98CD8812D60F627A7FD012EE62A7562CA5EDF1472521E301B2A6E0C`; vtable xref `0x00624cec`, tail route to scalar destructor after `this-0xa0` |
| adjustor `0x00573c43-0x00573c4e` | compiler-generated, no source | `7DC26C20890FDBEFF1E325A5051BC1736670EAB02275B5599EF093F9CE09AA55`; vtable xref `0x00624d1c`, tail route after `this-0xa4` |
| scalar destructor `0x00573c50-0x00573d15` | compiler-generated, no source | `9D72261544A6401E3D397F9F6BE83896E99B02791A8264479D788318A518E873`; refs from both adjustors and `0x00624c64` |

All seven gaps are alignment only and remain neither functions nor source data:

| Gap | Width / bytes | SHA256 | Xref result |
| --- | ---: | --- | --- |
| `0x005739f6-0x00573a00` | 10 bytes, all `cc` | `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` | bounded both-direction total `0` |
| `0x00573a98-0x00573aa0` | 8 bytes, all `cc` | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` | bounded both-direction total `0` |
| `0x00573b08-0x00573b10` | 8 bytes, all `cc` | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` | bounded both-direction total `0` |
| `0x00573b6d-0x00573b70` | 3 bytes, all `cc` | `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` | bounded both-direction total `0` |
| `0x00573bac-0x00573bb0` | 4 bytes, all `cc` | `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA` | bounded both-direction total `0` |
| `0x00573c4e-0x00573c50` | 2 bytes, all `cc` | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` | bounded both-direction total `0` |
| `0x00573d15-0x00573d20` | 11 bytes, all `cc` | `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` | bounded both-direction total `0`; hard successor remains `0x00573d20` |

### Compiler Data And RTTI

The compiler-owned data is exact and produces no literal source table. D01 `0x00624c60-0x00624c64` is the primary COL pointer to R01; D02 `0x00624c64-0x00624ce8` is the 33-slot primary table; D03 `0x00624ce8-0x00624cec` points to secondary COL R05; D04 `0x00624cec-0x00624d18` is the 11-slot `+0xa0` table; D05 `0x00624d18-0x00624d1c` points to tertiary COL R06; and D06 `0x00624d1c-0x00624d24` is the two-slot `+0xa4` table. Constructor, source-destructor, and scalar-destructor stores are respectively `0x005739d3/0x00573a2f/0x00573c7f`, `0x005739db/0x00573a35/0x00573c85`, and `0x005739e5/0x00573a3f/0x00573c8f`. Data successor `0x00624d24` is the separate `ServerSelectPane` COL pointer.

| RTTI item | Exact physical range | Disposition / exact xref result |
| --- | --- | --- |
| R01 primary COL | `0x006501f8-0x0065020c` | compiler record; inbound `0x00624c60`, outbound type descriptor/CHD |
| R02 class hierarchy | `0x0065020c-0x0065021c` | compiler record; four COL/base-descriptor inbound refs, outbound BCA |
| R03 base-class array | `0x0065021c-0x00650240` | compiler record; one inbound, eight outbound entries; terminal zero has no xref |
| R04 base-class descriptor | `0x00650240-0x0065025c` | compiler record; inbound from R03, outbound type descriptor/CHD |
| R05 secondary COL | `0x0065025c-0x00650270` | compiler record; inbound `0x00624ce8`, outbound type descriptor/CHD |
| R06 tertiary COL | `0x00650270-0x00650284` | compiler record; inbound `0x00624d18`, outbound type descriptor/CHD |
| R07 vftable-pointer head | `0x00679184-0x00679188` | compiler type-descriptor head; four inbound RTTI refs and one outbound ref, total `5` |
| R07B internal zero | `0x00679188-0x0067918c` | compiler type-descriptor cell; bounded both-direction xrefs `0` |
| R08 descriptor name | `0x0067918c-0x006791a4` | `.?AVSimpleListPane@@` plus padding; bounded both-direction xrefs `0` |

### Dependencies, Negative Inventory, And Boundaries

| Dependency | Required source relationship |
| --- | --- |
| `ListPane` | complete base declaration comes from `ListPane.h`; `SimpleListPane.h` derives from it |
| `RectBounds` | forward declaration in `SimpleListPane.h`; complete definition included in CPP for bounds field reads |
| `MemoryMan` | CPP include supplies copied-buffer allocation/free behavior |
| `wcslen` / `wcscpy_s` | `<wchar.h>` CPP dependency for exact copied-text operations |
| compile chain | `SimpleListPane.h -> ListPane.h -> ../core/ScrollBar.h`, which supplies complete `ScrollablePane`, `RectBounds`, and `Point` dependencies |

Whole-file searches found no owned source global, static, constant, non-RTTI string, resource, import, or third-party embed. RTTI names and vtable/COL bytes are compiler output, not source globals. Code at `0x00573d20` and data at `0x00624d24` are hard `ServerSelectPane` successors; no login-resource reference enters the SimpleListPane source interval, so adjacency does not transfer ownership.

### Placement, History, And Generated Contract

Accepted research is Agent-B003 `0001HP-SimpleListPaneConstructor-source-quality.md`, SHA256 `4602EA585635D88742E0723ECAD8034D47FA74ACE4DFDB148F59034780405F80`, and Agent-B001 `000241-SimpleListPaneDestructorAndEntryHelpers-source-quality.md`, SHA256 `676E3B8CE6EF926F6A14DE9E9B1FB4203BE1ECAB861C74DAA96B2897DEAE70B5`. Historical B002 `B002-MEMTOOL-00573C38-SimpleListPaneDestructorThunks.md`, SHA256 `D0BCC2AF931F5A7080B7E798E5B13645F4C95AC420496D28549D47E69431009F`, is stale `needs-revalidation target_header_missing` and is not current authority. Wave2/Wave3 and `simroot_v2` mentions are historical leads only; no current usable `simroot_v2` artifact establishes placement.

The standalone output contract is `NexusTK/ui/controls/SimpleListPane.cpp` plus required `SimpleListPane.h`: a class include envelope, six source methods, inherited-layout and compiler-vtable comments, and no empty markers. The pre-callback command `000000023186` CPP had the six method bodies but lacked the complete include/class/header envelope; validators, not manual edits, own the generated repair.

The `94/92` score reflects complete item, boundary, xref, dependency, source/no-source, placement, and generation dispositions. It remains below final-audit confidence because original helper spellings, the historical source-file fold choice, and live constructor route are not recoverable facts.

## Batch 129 Parent-Gate Audit

Historical Batch 129 cleared the strict `85/85` gate for direct source-root ownership but left file granularity open. The 2026-08-14 whole-file reconciliation above supersedes that narrow placement state and selects the standalone CPP/H sibling while retaining the earlier uncertainty as history.

2026-06-08 live IDA MCP rechecked the relevant starts: `0x005739a0` remains `Not a function` for the raw constructor caveat; `0x00573a00` is `sub_573A00` size `0x98`; `0x00573c38` and `0x00573c43` are the two `0xb` adjustor thunks; and `0x00573c50` is the `0xc5` main destructor. `callees` for both destructor bodies still route through `ListPane` selected-entry/base cleanup helpers and copied-text allocation/free helpers, matching a thin reusable list-control adapter rather than a feature module.

## 2026-06-16 A001 Source-Quality Refresh

The historical read-only IDA MCP session `b001_0001KM_20260616` did not find evidence that would move this source root into a feature module. `lookup_funcs` reconfirmed the raw constructor and four copied-text helper starts were not IDA-modeled functions, while `0x00573a00`, `0x00573c38`, `0x00573c43`, and `0x00573c50` were modeled at the documented starts and sizes.

Reachability checks remain the limiting issue. IDA `xrefs_to` plus little-endian address searches found no direct refs or pointer hits for `0x005739a0`, `0x00573aa0`, `0x00573b10`, `0x00573b70`, or `0x00573bb0`. The only direct refs to the destructor/thunk family are the expected vtable entries and thunk jumps into `0x00573c50`. This confirms the raw-body documentation without inventing callers.

That historical source-shape investigation found RTTI/type-name strings for `SimpleListPane` and `ClientItemMenuItemList`, no embedded `SimpleListPane.cpp` or `ListPane.cpp` filename string, and no local `SimpleListPane` UDT. Its Wave3/simroot and zero-byte generated-output observations are superseded historical snapshots. Current authority is the ordinary-document route and validator-generated readback described in the whole-file reconciliation above.

The constructor-specific C++ blocker is resolved on [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md). The child emits `SimpleListPane::SimpleListPane(int /*unused*/, const RectBounds *bounds)` with the corrected `ListPane(4, 10, width, height, 1, 1, 1)` base initializer through the finalized standalone root.

The file-level destructor/helper blockers are resolved at implementation-callback quality by accepted Agent-B001 report `000241-SimpleListPaneDestructorAndEntryHelpers-source-quality.md`. Helper names remain explicitly inferred rather than recovered, but [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) now emit `AppendText`, `InsertText`, `RemoveText`, and `ReplaceText`; [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) emits the source destructor; and [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) is non-emitting compiler-generated wrapper support. The raw/no-direct-xref constructor and helper starts remain confidence caps, not blank-emitter blockers.

## 2026-06-28 B001 Destructor/Helper Implementation Callback

Accepted Agent-B001 report and live MCP session `b001_000241_20260627` keep `NexusTK/ui/controls/SimpleListPane.cpp` as the preferred generated source root. `lookup_funcs`, xrefs, pointer searches, padding checks, and raw instruction review support [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) as a child aggregate, [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) as source `~SimpleListPane`, [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) as inferred copied-text helper methods, and [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) as compiler-generated non-emitting adjustor/scalar-deleting wrapper support. Generated `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` should be refreshed only by validators.

## Evidence Notes

- IDA MCP reports `0x005739a0` as `Not a function`, but cached prewave code and Wave3 metadata both identify the raw constructor range.
- IDA MCP confirms `0x00573c38` and `0x00573c43` as 0xb-byte thunks and `0x00573c50` as a 0xc5-byte destructor.
- The constructor sets the primary vtable and two secondary vtables after constructing the `ListPane` base.
- The destructor reads the item list state, loops the list count, obtains each entry slot through the shared selected-entry/list helper, frees non-null heap buffers, nulls the slot, then destroys the base.
- 2026-05-31 IDA MCP raw-disassembly pass splits `0x00573a00-0x00573c38` into five exact child pages and confirms the copied-text append, insert, remove, and replace helper boundaries.
- The scalar deleting destructor uses sized-delete size `0x14c`, matching a thin `ListPane`-derived object with no confirmed local fields beyond inherited list control storage.
- 2026-05-26 recheck: current `simroot_v2/class_SimpleListPane.cpp` still emits only the destructor, with the base cleanup labeled as `ClientItemMenuItemList`; IDA still decompiles the two preceding functions as `this - 0xa0` and `this - 0xa4` adjustors into `0x00573c50`.
- The adjustor thunk pair is recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). The main destructor remains reconstructable project code.

## Cross-References

- [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md)
- [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md)
- [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)
- [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md)
- [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md)
- [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md)
- [UID:0003D5][0x00624c60-0x00624d24.SimpleListPaneVtableData](by-memory/0x00624c60-0x00624d24.SimpleListPaneVtableData.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: `SimpleListPane` file-level docs skipped the `0x00573a00-0x00573c38` helper span between constructor and scalar deleting destructor.
- Changed to: the missing non-scalar destructor and entry helper span is now represented by [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md).
- Evidence: 2026-05-28 IDA MCP disassembly shows `0x00573a00` frees list-entry buffers and calls base cleanup, while raw helpers at `0x00573aa0`, `0x00573b10`, and `0x00573b70` allocate/copy/free wide-string entry buffers.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers role, proposed contents, destructor/helper span, ownership decision, IDA evidence, generated-owner pollution, layout refs, and cross-references; confidence is capped by standalone-vs-ListPane source placement and raw constructor modeling.
- 2026-05-31: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/`, changed completion/confidence from `84/78` to `86/82`, and added exact child helper references.
  - Before: The validator-managed projected path was blank and the copied-text helper island was represented mostly through the aggregate page.
  - After: The file stages as `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp`, matching the proposed source tree, and the proposed contents link the exact child helper pages.
  - Evidence: `by-project-structure/proposed-source-tree.md` already places `SimpleListPane.cpp` under controls; IDA MCP confirms the child helper boundaries and the `ListPane`-derived object size/vtables.
- 2026-06-03: Corrected copied-text helper links for the append/insert children.
  - Before: the file page linked old short ranges `0x00573aa0-0x00573b05` and `0x00573b10-0x00573b6a`.
  - After: the file page links `0x00573aa0-0x00573b08` and `0x00573b10-0x00573b6d`, matching the full return-instruction boundaries.
  - Evidence: IDA MCP raw disassembly shows `retn 4` bytes at `0x00573b05-0x00573b08` and `retn 8` bytes at `0x00573b6a-0x00573b6d`.
- 2026-06-08 A002 Batch129 parent-gate refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Evidence: added the parent-gate audit for [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md). Live IDA MCP reconfirmed the raw-constructor caveat, modeled destructor/thunk starts, destructor callee sets, and copied-text/list-base cleanup behavior. The score stays at `85` confidence because the final standalone source split versus folding into [UID:0000KT][ListPane](by-file/ListPane.md) remains open.
- 2026-06-16 A001 source-quality pass: Changed completion/confidence from `86/85` to `87/86`.
  - What changed: added fresh IDA evidence for raw start reachability, modeled function starts/sizes, vtable refs, absence of embedded source filename strings and local IDA types, and the then-current generated-output state.
  - Evidence: IDA session `b001_0001KM_20260616` `lookup_funcs`, `xrefs_to`, `find_bytes`, `find_regex`, `search_structs`, `type_query`, `callees`, `decompile`, `get_bytes`, and `insn_query`; local review of `simroot_v2/ui/controls/class_SimpleListPane.cpp`, `class_SimpleListPane.cpp.disabled`, and `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp`. `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"` remain unchanged.
- 2026-06-25 B003 implementation callback: Score unchanged at `87/86`.
  - What changed: updated the constructor proposed-contents row and source-quality notes to reflect that [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md) now emits formal constructor C++ through this source root.
  - Evidence: accepted Agent-B003 report `tools/leaser/Agents/Agent-B003/research/0001HP-SimpleListPaneConstructor-source-quality.md` and live IDA MCP session `80de0a67` evidence for raw/no-function boundaries, no xrefs/pointer hits, unique raw bytes, `RectBounds` field reads, corrected `ListPane` argument order, vtable stores, and `retn 8`. `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"` remain unchanged.
- 2026-06-28 B001 implementation callback: Score unchanged at `87/86`.
  - What changed: updated proposed contents and source-quality text for the accepted destructor/helper implementation route: [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) child marker, [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) source destructor, [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) inferred helper methods, and [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) non-emitting compiler-generated support.
  - Evidence: accepted Agent-B001 report and live MCP session `b001_000241_20260627`. `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"` remain unchanged.

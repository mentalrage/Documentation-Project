** TARGET-REPORT-UID:0000WR **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Report - [UID:0000WR] FittingRoomUiCore Source Quality

## Assignment

- Agent: B003.
- Assignment ID: `B003-report-fitting-room-ui-core-source-quality-0000WR-mcp-20260623`.
- Target: [UID:0000WR] `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JE`, blank emitter position, blank aggregate C++.
- Required output: report-only source-quality rework. No by-* docs, generated files, coverage reports, IDA DB, tool state, or executed-report moves were edited.

## Final Recommendation

Implement a split/repair package for [UID:0000WR]. Do not leave the target unchanged.

Recommended parent metadata after implementation: raise [UID:0000WR] from `85/88` to `88/89`, keep `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JE`, blank emitter position, and blank aggregate C++.

The current MCP-backed pass resolves the supervisor-identified score blockers into exact child-page work. The parent remains a broad non-emitting/index aggregate owned by [UID:0000JE] `FittingRoom`, and the previously hidden source-bearing gaps now have an implementation package instead of remaining as open blockers. This revised report recommends creating exact child by-memory pages for those gaps, updating the parent/support docs with the current MCP evidence, and preserving padding/no-function tails explicitly. The score can rise because the remaining blockers are no longer open-ended: every newly confirmed modeled or raw function gap now has an exact range, source-facing name, owner/emitter decision, liveness evidence, rejected alternatives, and first-draft C++ or no-code disposition.

Do not add aggregate C++ for [UID:0000WR]. First-draft C++ is safe only for the two small user-image direction helpers at `0x00424550` and `0x00424570`. All other proposed children should be created with blank formal C++ and target-specific no-code proof.

## MCP Evidence Basis

Mandatory IDA MCP was available. Binary evidence below is from session/database `80de0a67` at `http://127.0.0.1:13337/mcp`.

- `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Tools used in this rework: `lookup_funcs`, `xrefs_to`, `xref_query`, `func_profile`, `callees`, `decompile`, `get_bytes`, `find_bytes`, and bounded local SHA256 hashing of MCP-returned bytes.
- Broad MCP scans were avoided. The pass used exact addresses and small pattern checks.

## Current Function Inventory Refresh

Current `lookup_funcs` confirms these modeled starts and sizes inside the aggregate:

- Download/control/dialog group: `0x0041ba40` size `0x38e`, `0x0041bdd0` size `0x480`, `0x0041c310` size `0x286`, `0x0041c5e0` size `0x583`, `0x0041cb70` size `0x1c8`, `0x0041cd40` size `0x7f`, `0x0041cdc0` size `0x38b`, `0x0041d150` size `0x134`, `0x0041d2c0` size `0x75`, `0x0041d340` size `0x70`, `0x0041d3b0` size `0x81`, `0x0041d440` size `0xb`, `0x0041d450` size `0x5`, `0x0041d490` size `0xe2`, `0x0041d580` size `0x55`, and `0x0041d5e0` size `0x92`.
- Scroll/list group: `0x0041d870` size `0x1e1`, `0x0041da60` size `0x5`, `0x0041da70` size `0x33`, `0x0041dab0` size `0x716`, `0x0041e1d0` size `0x31d`, `0x0041e4f0` size `0x287`, `0x0041e8b0` size `0xc0`, `0x0041e970` size `0x1b4`, `0x0041eb90` size `0x12d`, `0x0041ed00` size `0x88`, `0x0041ed90` size `0x73`, `0x0041ee10` size `0x2a0`, `0x0041f0b0` size `0x4d`, `0x0041f100` size `0x119`, `0x0041f220` size `0x66`, `0x0041f290` size `0x16`, `0x0041f2b0` size `0x8eb`, `0x0041fba0` size `0x125`, `0x0041fcd0` size `0xafe`, `0x00420840` size `0x109`, `0x00420b60` size `0x199`, `0x00420d00` size `0x50`, and `0x00420de0` size `0x10a`.
- Mixed island and resolved middle gap: `0x00421310` size `0x52`, `0x00421380` size `0x61`, `0x00421410` size `0x67`, `0x004214c0` size `0x5`, `0x004214d0` size `0x27`, `0x00421500` size `0xa`, `0x00421520` size `0x64`, `0x00421590` size `0x13b`, `0x004216d0` size `0x3a`, `0x00421710` size `0x129`, and `0x00421860` size `0x181`.
- Item-state/catalog group: `0x00421a40` size `0x598`, `0x00421fe0` size `0x3c`, `0x00422020` size `0x30a`, `0x00422330` size `0x13f`, `0x00422690` size `0x3d`, `0x004226d0` size `0x6f`, `0x00422740` size `0x1d9`, `0x00422b30` size `0x63`, and `0x00422ba0` size `0x2f1`.
- Text button/user image group: `0x00424020` size `0x3f`, `0x00424060` size `0x1f`, `0x00424080` size `0x1dd`, `0x00424260` size `0x10`, `0x00424270` size `0xb`, `0x0042427b` size `0xb`, `0x00424290` size `0x55`, `0x00424300` size `0xb0`, `0x004243b0` size `0x1f`, `0x004243d0` size `0x12b`, `0x00424500` size `0x4e`, `0x00424550` size `0x1a`, `0x00424570` size `0x14`, `0x00424584` size `0xb`, `0x0042458f` size `0xb`, and `0x004245a0` size `0x55`.

Current `lookup_funcs` confirms these important starts are still not function objects: `0x0041c250`, `0x0041d6c0`, `0x0041e780`, `0x0041e7f0`, `0x0041eb30`, `0x0041ecc0`, `0x004207ce`, `0x00420950`, `0x00420a10`, `0x00420a90`, `0x00420d50`, `0x00420db0`, `0x004219e1`, `0x004219f0`, `0x00421a20`, `0x00421a30`, and `0x004245f5`.

## Positive Evidence

- The aggregate source root remains [UID:0000JE] `FittingRoom`. `by-file/FittingRoom.md` routes the dialog/list/scroll/catalog/download/user-image/text-button family to `NexusTK/cashshop/FittingRoom.cpp`.
- `xrefs_to(0x0041ba40)` returns one data xref at `0x0060da08`, consistent with `FittingRoomDownloadControlPane::OnPaint` as a vtable-routed method.
- `decompile(0x0041ba40)` draws centered text and a progress bar using a `MulDiv(..., byte[this+0x108], 100)` progress fill and resource/frame helpers; this is source-facing `FittingRoomDownloadControlPane::OnPaint`, not a generic helper.
- `xrefs_to(0x004216d0)` returns one code xref at `0x0042112b` inside [UID:00030R] `FittingRoomItemEntryVectorInsert`. `decompile(0x004216d0)` frees `180 * count` bytes with the MSVC large-allocation guard and `0x005c7526`.
- `xrefs_to(0x00421710)` returns one code xref at `0x0041fedc` inside [UID:0002DN] `FittingRoomListPaneOnInputEvent`. `decompile(0x00421710)` erases one `0xb4` byte entry, deep-moves the nested vector triplet, releases the old tail entry through `0x00421380`, and decrements the vector end by `180`.
- `0x00421860` is a modeled function with prototype `bool __thiscall(_WORD *this, _BYTE *)`. `func_profile` reports zero callers, seven callees including JsonCpp value helpers, four string refs (`part`, `tile`, `color`, `gender`), and no ordinary caller list.
- `decompile(0x00421860)` parses a packed six-byte `FittingRoomCatalogPartRecord`: `part` byte at `+0x00`, `tile` word at `+0x02`, `color` byte at `+0x04`, and `gender` byte at `+0x05`; it rejects `part == 0xf5` and `gender == 0xff`. This matches the packed part-record layout already documented by [UID:0002E4] and [UID:0002E5].
- `xrefs_to(0x00424300)` returns the dialog constructor call at `0x0041bfda`. `decompile(0x00424300)` installs user-image vtables `0x0060e07c`, `0x0060e0e4`, `0x0060e114`, stores the appearance/sprite argument at `this+0x108`, initializes `this+0x10c`, `this+0x110`, `this+0x114 = 2`, calls the local visibility/state helper, and starts a `300` ms timer on the adjusted timer facet.
- `xrefs_to(0x004243d0)` returns vtable data xref `0x0060e0c0`; `decompile(0x004243d0)` fills a 10 by 10 tiled background using `word_66DA9C`/`word_66DAA0`, global surfaces at `dword_67A75C`/`dword_67A760`, and renders the current appearance/direction.
- `xrefs_to(0x00424500)` returns vtable data xref `0x0060e118`; `decompile(0x00424500)` handles timer id `0`, advances animation frame `this+0x10c` if not paused at `this+0x110`, invalidates through the containing pane facet, and reschedules `300` ms.
- `xrefs_to(0x00424550)` and `xrefs_to(0x00424570)` return `FittingRoomDialog::OnCommand` call sites `0x0041c486` and `0x0041c49f`, confirming rotate-forward/rotate-backward helpers. Their decompilations are exact enough for first-draft C++.
- `xrefs_to(0x00424584)` and `xrefs_to(0x0042458f)` return vtable data refs `0x0060e0e4` and `0x0060e114`; both are compiler adjustor thunks to `0x004245a0`.
- `xrefs_to(0x004245a0)` returns two thunk callers plus vtable data ref `0x0060e07c`; `decompile(0x004245a0)` is the scalar deleting destructor wrapper.

## Negative Evidence And Resolved Blockers

- `xrefs_to(0x00421860)` returns no xrefs. `xref_query(0x00421860, both)` returns only self-to-next-instruction flow inside the function, not a caller, vtable cell, or pointer route.
- `find_bytes` for `0x00421860` absolute VA pattern `60 18 42 00` and RVA-shaped pattern `60 18 02 00` returns no matches. This rejects a hidden data pointer route for the part-record parser candidate.
- `lookup_funcs(0x004219e1)`, `lookup_funcs(0x004219f0)`, `lookup_funcs(0x00421a20)`, and `lookup_funcs(0x00421a30)` all return "Not a function"; `xrefs_to(0x004219f0)` and `xrefs_to(0x00421a30)` return no xrefs. `find_bytes` for VA/RVA pointer patterns to `0x004219f0` and `0x00421a30` returns no matches.
- The `0x004219e1-0x00421a40` tail is not pure padding. MCP bytes show leading `0xcc`, a no-function entry initializer at `0x004219f0`, padding, and a no-function thunk at `0x00421a30` that adjusts by `0xb4` and jumps toward the category-entry vector destructor family. It needs a no-code child, not silent aggregate coverage.
- The download OnPaint and user-image OnPaint/OnTimer bodies are source-bearing and live, but they should not receive first-draft C++ in this callback because their behavior depends on broader render/resource/global helper names and inherited facet signatures that remain owned by other support pages. This is not a reason to leave the aggregate unchanged; it is a child-level blank-C++ disposition with exact split, score, and evidence.
- The vector free/erase helpers are exact and live, but standalone C++ would harden compiler/container helper shapes. Their source representation should be as vector/container operations in list-pane caller code, while the by-memory children document the exact emitted helper bytes.
- The part-record parser at `0x00421860` is exact but no-route. Emitting it as an active helper would either duplicate [UID:0002E4]'s existing inlined part-parse source or force a call edge not present in current IDA. It should be documented as a no-route retained out-of-line parser candidate with blank C++.
- The user-image non-deleting destructor body and scalar deleting destructor wrapper must not both emit destructor C++. Both write the same vtable views and call teardown; the scalar wrapper conditionally deletes. They are compiler lifecycle artifacts for one source destructor obligation, not two source bodies.

## Bytes And Padding Evidence

Full proposed child function SHA16 values from MCP-returned bytes:

| Range | Size | SHA16 | Interpretation |
| --- | ---: | --- | --- |
| `0x0041ba40-0x0041bdce` | `0x38e` | `a049034203d827aa` | `FittingRoomDownloadControlPane::OnPaint` vtable-routed paint routine. |
| `0x004216d0-0x0042170a` | `0x3a` | `ecfd2b5c14071dbe` | `FittingRoomItemEntryVectorStorageFree` helper. |
| `0x00421710-0x00421839` | `0x129` | `6373c0c1ef4bbbd2` | `FittingRoomItemEntryVectorErase` helper. |
| `0x00421860-0x004219e1` | `0x181` | `d3648d01be4ef864` | No-route `FittingRoomCatalogPartRecord::LoadFromJson` candidate. |
| `0x00424300-0x004243b0` | `0xb0` | `211386c0d3895ed1` | `FittingRoomUserImageControlPane` constructor. |
| `0x004243b0-0x004243cf` | `0x1f` | `854fe91dc4a6888f` | Non-deleting destructor/body reset. |
| `0x004243d0-0x004244fb` | `0x12b` | `271d1481dfa9e04e` | `FittingRoomUserImageControlPane::OnPaint`. |
| `0x00424500-0x0042454e` | `0x4e` | `254b7adb3e84b3c7` | `FittingRoomUserImageControlPane::OnTimer`. |
| `0x00424550-0x0042456a` | `0x1a` | `a9205a0255299b43` | `AdvanceFacingDirection`. |
| `0x00424570-0x00424584` | `0x14` | `c07d5af5eb4abdeb` | `RetreatFacingDirection`. |
| `0x00424584-0x0042459a` | `0x16` | `0ba2e54363ffe97f` | Two adjustor thunks to the scalar deleting destructor. |
| `0x004245a0-0x004245f5` | `0x55` | `1909c91c8a5203f1` | Scalar deleting destructor wrapper. |

Padding/no-function tail SHA16 values:

| Range | Size | SHA16 | Disposition |
| --- | ---: | --- | --- |
| `0x004216cb-0x004216d0` | `0x5` | included in `4cdab9d03d32c38e` edge read | `0xcc` alignment before `0x004216d0`; update `by-memory/-ignored.md`. |
| `0x0042170a-0x00421710` | `0x6` | `33cc4a00a0f04735` | `0xcc` alignment before `0x00421710`; update `by-memory/-ignored.md`. |
| `0x00421839-0x00421860` | `0x27` | `78f282097e63ff67` | Mostly `0xcc` plus no-route instruction bytes; preserve as ignored/no-route alignment span tied to the parser child. |
| `0x004219e1-0x00421a40` | `0x5f` | `cccd81280ec94378` | Not pure padding; create no-code child `FittingRoomCatalogEntryNoFunctionTail`. |
| `0x004243cf-0x004243d0` | `0x1` | `1dd8312636f6a0bf` | Single `0xcc` byte after non-deleting body. |
| `0x004244fb-0x00424500` | `0x5` | `992cf51486f901aa` | `0xcc` alignment before `OnTimer`. |
| `0x0042454e-0x00424550` | `0x2` | `e3966e3275be536a` | `0xcc` alignment before direction helper. |
| `0x0042456a-0x00424570` | `0x6` | `33cc4a00a0f04735` | `0xcc` alignment before reverse direction helper. |
| `0x0042459a-0x004245a0` | `0x6` | `33cc4a00a0f04735` | `0xcc` alignment before scalar deleting destructor. |

## Implementation-Ready Split Package

Validator-created UIDs were assigned during the accepted implementation callback and have been applied to parent/support docs and supervisor-owned coverage text below.

| Placeholder | New child by-memory filename | Metadata recommendation | C++ disposition |
| --- | --- | --- | --- |
| `UID:00041P` | `by-memory/0x0041ba40-0x0041bdce.FittingRoomDownloadControlPaneOnPaint.md` | `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000052`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000052`, blank emitter position | Blank C++; source-bearing live paint method, but standalone C++ would require unsupported render/resource helper signatures and class member declarations not established by current support pages. |
| `UID:00041Q` | `by-memory/0x004216d0-0x0042170a.FittingRoomItemEntryVectorStorageFree.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`, blank emitter position | Blank C++; compiler/container storage free helper for the `0xb4` entry vector. Source should be represented through vector operations in callers. |
| `UID:00041R` | `by-memory/0x00421710-0x00421839.FittingRoomItemEntryVectorErase.md` | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`, blank emitter position | Blank C++; compiler/container erase/move helper using the `0xb4` selected-entry layout and nested vector triplet. |
| `UID:00041S` | `by-memory/0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md` | `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:000051`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000051`, blank emitter position | Blank C++; exact no-route packed part-record parser candidate. Do not duplicate [UID:0002E4]'s active parser source or invent a call edge. |
| `UID:00041T` | `by-memory/0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md` | `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:000051`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000051`, blank emitter position | Blank C++; covers no-function entry initializer/destructor-thunk tail with no xrefs/pointer route. |
| `UID:00041U` | `by-memory/0x00424300-0x004243b0.FittingRoomUserImageControlPaneConstructor.md` | `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | Blank C++; exact constructor evidence is safe, but standalone C++ would require unsupported class declaration, base-facet, and timer helper signatures. |
| `UID:00041V` | `by-memory/0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md` | `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | Blank C++; one source destructor obligation must not emit here and again in the scalar deleting wrapper. |
| `UID:00041W` | `by-memory/0x004243d0-0x004244fb.FittingRoomUserImageControlPaneOnPaint.md` | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | Blank C++; source-bearing live vtable method, but rendering/global helper declarations remain cross-support dependencies. |
| `UID:00041X` | `by-memory/0x00424500-0x0042454e.FittingRoomUserImageControlPaneOnTimer.md` | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | Blank C++; standalone C++ would harden an unsupported adjusted `TimerHandler` receiver signature, inherited invalidate virtual shape, and timer helper declaration. |
| `UID:00041Y` | `by-memory/0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | First-draft C++ ready; exact direct caller, field offset, and wrap behavior. |
| `UID:00041Z` | `by-memory/0x00424570-0x00424584.FittingRoomUserImageControlPaneRetreatFacingDirection.md` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | First-draft C++ ready; exact direct caller, field offset, and wrap behavior. |
| `UID:000421` | `by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md` | `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank emitter position | Blank C++; compiler adjustor thunks only. |
| `UID:000423` | `by-memory/0x004245a0-0x004245f5.FittingRoomUserImageControlPaneScalarDeletingDestructor.md` | `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:000056`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000056`, blank emitter position | Blank C++; compiler scalar deleting wrapper. Do not emit duplicate destructor C++. |

Required padding preservation after child creation:

- Update `by-memory/-ignored.md` for `0x004216cb-0x004216d0`, `0x0042170a-0x00421710`, `0x00421839-0x00421860`, `0x004243cf-0x004243d0`, `0x004244fb-0x00424500`, `0x0042454e-0x00424550`, `0x0042456a-0x00424570`, and `0x0042459a-0x004245a0`.
- Do not mark `0x004219e1-0x00421a40` as ignored padding; create the no-code child above because it contains no-function entry-init/thunk bytes.

## Child C++ Recommendations

Only these two proposed child pages should receive first-draft C++:

```cpp
void FittingRoomUserImageControlPane::AdvanceFacingDirection()
{
    if (++m_facingDirection > 3)
        m_facingDirection = 0;
}

void FittingRoomUserImageControlPane::RetreatFacingDirection()
{
    if (--m_facingDirection < 0)
        m_facingDirection = 3;
}
```

Evidence: `decompile(0x00424550)` is exactly `if ((int)++this[69] > 3) this[69] = 0;`, and `decompile(0x00424570)` is exactly `if (--this[69] < 0) this[69] = 3;`. `xrefs_to` ties both to [UID:0002CQ] `FittingRoomDialog::OnCommand`.

Do not add C++ for:

- [UID:0000WR] aggregate: broad mixed index/container, not a source body.
- `FittingRoomDownloadControlPane::OnPaint`: render/resource helper and field declaration dependencies remain outside this child.
- `FittingRoomItemEntryVectorStorageFree` and `FittingRoomItemEntryVectorErase`: compiler/container helper bodies; source should be expressed through vector operations and caller code.
- `FittingRoomCatalogPartRecordLoadFromJsonNoRoute`: no caller/pointer route and duplicate active parser semantics in [UID:0002E4].
- `FittingRoomCatalogEntryNoFunctionTail`: no function records/xrefs/pointer route; compiler/init/thunk tail evidence only.
- `FittingRoomUserImageControlPane` constructor, paint, timer, destructor body, adjustor thunks, and scalar deleting destructor: lifecycle/facet/render dependencies or compiler thunks/wrappers make formal C++ unsafe.

## Ownership And Source Placement Ranking

1. [UID:0000JE] `FittingRoom` file/source-family aggregate: strongest for [UID:0000WR] as the parent source route and final `NexusTK/cashshop/FittingRoom.cpp` module.
2. Exact FittingRoom class pages: strongest for new children. [UID:000052] owns download OnPaint; [UID:000053] owns the list item-entry vector helpers; [UID:000051] owns the catalog part parser/no-function catalog-entry tail; [UID:000056] owns the user-image methods/wrappers except compiler-only adjustor thunks.
3. [UID:0000I1] `CashShopVersionRequest`: rejected for the aggregate and for the proposed children. The fitting-room dialog constructor submits a version request, but none of the new ranges are request payload, request vtable, or network dispatcher code.
4. [UID:0000KD]/[UID:00006T] `ItemCatalog`: rejected for the aggregate and for `0x00421860`. `ItemCatalog` remains the count/index facade over item-state category storage; the no-route parser writes a packed part record and matches [UID:000051] item-state parser layout.
5. Generic/string/vector owners: rejected for the aggregate. Accepted only as dependency owners for exact helper callees. The vector free/erase children are FittingRoom list-entry layout-specific because their only live callers are list-pane selection paths and they use the `0xb4` fitting-room entry stride.
6. No-owner/non-emitting: accepted only for compiler adjustor thunks/padding and rejected for source-bearing product methods.

## Score And Metadata Rationale

- Parent [UID:0000WR] should rise to `88/89` after implementation because current MCP resolves the previously hidden source-bearing gaps into exact children, exact padding/no-function tail treatment, and support-doc routing. It should not exceed `88` completion because it remains a broad aggregate with many exact children, raw helper children, compiler thunks, jump tables, and generic support exclusions.
- [UID:000052] `FittingRoomDownloadControlPane` should rise from `85/89` to `86/90` after the OnPaint child is created and linked. Class C++ remains blank.
- [UID:000053] `FittingRoomListPane` should rise from `85/87` to `86/88` after the storage-free and erase helpers are created and linked. Class C++ remains blank because the class-level declaration still depends on broader item-entry field/type names.
- [UID:000056] `FittingRoomUserImageControlPane` should rise from `85/87` to `87/90` after exact user-image child pages are created and the two direction helpers receive first-draft C++. Class-level C++ remains blank.
- [UID:000051] `FittingRoomDialogItemState` should remain `88/90`; add support text for the no-route `0x00421860` parser and no-function tail without changing class metadata because the class already carries strong parser/layout support.
- [UID:0000JE] `by-file/FittingRoom.md` should rise from `86/88` to `87/89` because the exact split package closes the last known broad [UID:0000WR] inventory gaps while preserving fitting-room feature-module placement.

## Target Doc Changes

Required if accepted:

- Update `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`.
- Set metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter route [UID:0000JE], reconstructable true, blank emitter position, and blank aggregate C++.
- Replace stale Wave3/currentness wording with MCP session `80de0a67` evidence. Historical Wave3 changes can remain only as historical notes.
- Replace address-only rows for `0x0041ba40-0x0041bdce`, `0x004216d0-0x0042170a`, `0x00421710-0x00421839`, `0x00421860-0x004219e1`, `0x004219e1-0x00421a40`, and `0x00424300-0x004245f5` with links to validator-created child pages once real UIDs exist.
- Preserve exact padding spans and no-function route negatives. `0x004219e1-0x00421a40` must not be called padding.
- Strengthen aggregate no-code proof: exact children carry source/no-code decisions; aggregate C++ would duplicate child output and merge unrelated class/helper bodies.

## Support Doc Changes

Required support updates if accepted:

- `by-file/FittingRoom.md`: raise from `86/88` to `87/89`; add the split package inventory; record that `FittingRoom.cpp` remains the source module; record that exact class children emit or no-code, while [UID:0000WR] remains blank aggregate C++; reject `CashShopVersionRequest`, `ItemCatalog`, generic helper, and no-owner routing for the aggregate.
- `by-class/FittingRoomDownloadControlPane.md`: raise from `85/89` to `86/90`; add [UID:00041P] once assigned; record `0x0041ba40` size `0x38e`, vtable xref `0x0060da08`, SHA16 `a049034203d827aa`, progress byte `this+0x108`, and blank-C++ child disposition.
- `by-class/FittingRoomListPane.md`: raise from `85/87` to `86/88`; add [UID:00041Q] and [UID:00041R]; record callers `0x0042112b` and `0x0041fedc`, `0xb4`/`180` entry stride, nested vector triplet at `+0xa8/+0xac/+0xb0`, and no-code compiler/container helper rationale.
- `by-class/FittingRoomDialogItemState.md`: no metadata change (`88/90`); add [UID:00041S] and [UID:00041T] support rows/notes. Preserve [UID:0002E4] as active first-draft parser and document `0x00421860` as a no-route retained/out-of-line parser candidate with no C++.
- `by-class/FittingRoomUserImageControlPane.md`: raise from `85/87` to `87/90`; replace the local-core aggregate row with exact child inventory; record vtable cells `0x0060e07c`, `0x0060e0e4`, `0x0060e114`, paint slot `0x0060e0c0`, timer slot `0x0060e118`, direction callers `0x0041c486`/`0x0041c49f`, and first-draft C++ only for the two direction helpers.
- `by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md`: add support reference to [UID:00041Q] as the storage-free callee at `0x0042112b`; no metadata change.
- `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`: add support reference to [UID:00041R] at call site `0x0041fedc`; no metadata change unless validator requires link refresh.
- `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md`: no metadata change; add a note rejecting merge/duplicate emission with [UID:00041S].
- `by-memory/-ignored.md`: update only padding spans listed above; do not edit coverage reports.

Required no-change decisions:

- `by-file/CashShopVersionRequest.md`: no change. It is a rejected owner and current docs already keep request payloads separate from fitting-room UI ownership.
- `by-file/ItemCatalog.md` and `by-class/ItemCatalog.md`: no change unless stale contradiction is found during implementation. The count/index facade split remains correct.
- Generic/string/vector/helper docs: no change for this callback. The report rejects folding GrafPort/Surface/StringUtil/VectorHelpers/JsonCpp ownership into [UID:0000WR].
- Generated output and `auto-generated/-ag-memory-coverage.md`: no manual edits. Use only as read-only evidence.

## Coverage Recommendation

Do not edit `by-memory/-coverage-report.md` during B-agent implementation. Supervisor should apply coverage after verification; real validator-assigned child UIDs are included below.

Replace the [UID:0000WR] row with:

```text
    - [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md) 0x0041ba40-0x004245f5 | aggregate | FittingRoomUiCore : reconstructable : 88% : strong : Broad non-emitting FittingRoom UI core aggregate. Current B003 MCP session 80de0a67 confirms exact child coverage for the download paint method, dialog/list/scroll/state/text-button/user-image controls, list-entry vector helpers, no-route catalog part parser/tail, raw helper islands, jump-table/data pockets, fitting-room vtable/source route, and mixed generic/string/vector exclusions; exact child pages carry source C++ or no-code proof while aggregate C++ remains blank.
```

Insert child rows under [UID:0000WR] at the appropriate address positions:

```text
        - [UID:00041P][0x0041ba40-0x0041bdce.FittingRoomDownloadControlPaneOnPaint](by-memory/0x0041ba40-0x0041bdce.FittingRoomDownloadControlPaneOnPaint.md) 0x0041ba40-0x0041bdce | method | FittingRoomDownloadControlPaneOnPaint : reconstructable : 86% : strong : MCP 80de0a67 confirms `0x38e` byte vtable-routed download/progress paint routine, vtable data xref `0x0060da08`, progress byte `this+0x108`, render/resource helper dependencies, SHA16 `a049034203d827aa`, and blank formal C++ until render/member declarations are source-quality.
        - [UID:00041Q][0x004216d0-0x0042170a.FittingRoomItemEntryVectorStorageFree](by-memory/0x004216d0-0x0042170a.FittingRoomItemEntryVectorStorageFree.md) 0x004216d0-0x0042170a | helper | FittingRoomItemEntryVectorStorageFree : reconstructable : 86% : strong : MCP 80de0a67 confirms a live list-pane entry-vector storage-free helper called from `0x0042112b`, freeing `180 * count` bytes with MSVC large-allocation validation and SHA16 `ecfd2b5c14071dbe`; formal C++ stays blank as compiler/container helper output.
        - [UID:00041R][0x00421710-0x00421839.FittingRoomItemEntryVectorErase](by-memory/0x00421710-0x00421839.FittingRoomItemEntryVectorErase.md) 0x00421710-0x00421839 | helper | FittingRoomItemEntryVectorErase : reconstructable : 86% : strong : MCP 80de0a67 confirms the live `0xb4` byte fitting-room item-entry erase/move helper called from `0x0041fedc`, deep-moving the nested vector triplet, releasing the old tail entry, and SHA16 `6373c0c1ef4bbbd2`; formal C++ stays blank as compiler/container helper output.
        - [UID:00041S][0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute](by-memory/0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md) 0x00421860-0x004219e1 | helper | FittingRoomCatalogPartRecordLoadFromJsonNoRoute : reconstructable : 85% : strong : MCP 80de0a67 confirms an exact packed part-record JsonCpp parser for `part`/`tile`/`color`/`gender`, reject sentinels `0xf5` and `0xff`, SHA16 `d3648d01be4ef864`, no callers/xrefs/pointer-route, and blank formal C++ to avoid duplicating the active [UID:0002E4] parser source.
        - [UID:00041T][0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail](by-memory/0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md) 0x004219e1-0x00421a40 | raw | FittingRoomCatalogEntryNoFunctionTail : reconstructable : 85% : strong : MCP 80de0a67 confirms no function objects, no xrefs, no VA/RVA pointer-route, `0xcc` alignment plus no-function entry initializer/destructor-thunk bytes before `0x00421a40`, SHA16 `cccd81280ec94378`, and blank formal C++ as retained compiler/init tail evidence.
        - [UID:00041U][0x00424300-0x004243b0.FittingRoomUserImageControlPaneConstructor](by-memory/0x00424300-0x004243b0.FittingRoomUserImageControlPaneConstructor.md) 0x00424300-0x004243b0 | constructor | FittingRoomUserImageControlPaneConstructor : reconstructable : 86% : strong : MCP 80de0a67 confirms dialog-constructor caller `0x0041bfda`, vtable stores `0x0060e07c/0x0060e0e4/0x0060e114`, appearance field `this+0x108`, state fields `+0x10c/+0x110/+0x114`, 300 ms timer start, SHA16 `211386c0d3895ed1`, and blank formal C++ because the required class/facet declarations would otherwise be invented.
        - [UID:00041V][0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody](by-memory/0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md) 0x004243b0-0x004243cf | cleanup | FittingRoomUserImageControlPaneNonDeletingDestructorBody : reconstructable : 85% : strong : MCP 80de0a67 confirms vtable restores and teardown call, no direct xrefs, SHA16 `854fe91dc4a6888f`, and blank formal C++ because the source destructor obligation must not duplicate the scalar deleting wrapper.
        - [UID:00041W][0x004243d0-0x004244fb.FittingRoomUserImageControlPaneOnPaint](by-memory/0x004243d0-0x004244fb.FittingRoomUserImageControlPaneOnPaint.md) 0x004243d0-0x004244fb | method | FittingRoomUserImageControlPaneOnPaint : reconstructable : 86% : strong : MCP 80de0a67 confirms vtable data xref `0x0060e0c0`, 10x10 tiled background draw, current appearance/direction render path, SHA16 `271d1481dfa9e04e`, and blank formal C++ because render/global helper declarations would otherwise be invented.
        - [UID:00041X][0x00424500-0x0042454e.FittingRoomUserImageControlPaneOnTimer](by-memory/0x00424500-0x0042454e.FittingRoomUserImageControlPaneOnTimer.md) 0x00424500-0x0042454e | method | FittingRoomUserImageControlPaneOnTimer : reconstructable : 86% : strong : MCP 80de0a67 confirms vtable data xref `0x0060e118`, timer id `0`, frame advance/wrap through `this+0x10c`, pause gate `this+0x110`, invalidate/reschedule path, SHA16 `254b7adb3e84b3c7`, and blank formal C++ because the adjusted TimerHandler source shape would otherwise be invented.
        - [UID:00041Y][0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection](by-memory/0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md) 0x00424550-0x0042456a | method | FittingRoomUserImageControlPaneAdvanceFacingDirection : reconstructable : 88% : strong : MCP 80de0a67 confirms direct command caller `0x0041c486`, exact increment/wrap behavior for `m_facingDirection`, SHA16 `a9205a0255299b43`, and first-draft C++ readiness.
        - [UID:00041Z][0x00424570-0x00424584.FittingRoomUserImageControlPaneRetreatFacingDirection](by-memory/0x00424570-0x00424584.FittingRoomUserImageControlPaneRetreatFacingDirection.md) 0x00424570-0x00424584 | method | FittingRoomUserImageControlPaneRetreatFacingDirection : reconstructable : 88% : strong : MCP 80de0a67 confirms direct command caller `0x0041c49f`, exact decrement/wrap behavior for `m_facingDirection`, SHA16 `c07d5af5eb4abdeb`, and first-draft C++ readiness.
        - [UID:000421][0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks](by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md) 0x00424584-0x0042459a | thunk | FittingRoomUserImageControlPaneAdjustorThunks : nonreconstructable : 86% : strong : MCP 80de0a67 confirms two compiler adjustor thunks from vtable cells `0x0060e0e4` and `0x0060e114` to the scalar deleting destructor, SHA16 `0ba2e54363ffe97f`, and blank formal C++.
        - [UID:000423][0x004245a0-0x004245f5.FittingRoomUserImageControlPaneScalarDeletingDestructor](by-memory/0x004245a0-0x004245f5.FittingRoomUserImageControlPaneScalarDeletingDestructor.md) 0x004245a0-0x004245f5 | destructor | FittingRoomUserImageControlPaneScalarDeletingDestructor : reconstructable : 86% : strong : MCP 80de0a67 confirms vtable data xref `0x0060e07c`, adjustor-thunk callers, vtable restores, teardown, conditional delete, SHA16 `1909c91c8a5203f1`, and blank formal C++ as compiler scalar deleting wrapper.
```

Supervisor should also add or refresh ignored-padding coverage rows for the padding spans listed in "Required padding preservation" after child validation.

## Validator Plan

If the implementation is accepted, run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every created/changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000WR-FittingRoomUiCore-source-quality-removed.md](0000WR-FittingRoomUiCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only validators for files actually changed if implementation scope is reduced by supervisor. Record command, exit code, `ok` count, warnings, and side effects.

## Implementation Tracking Checklist

Implementation callback state: checked and executed after supervisor acceptance. The validator assigned real child UIDs `[UID:00041P]`, `[UID:00041Q]`, `[UID:00041R]`, `[UID:00041S]`, `[UID:00041T]`, `[UID:00041U]`, `[UID:00041V]`, `[UID:00041W]`, `[UID:00041X]`, `[UID:00041Y]`, `[UID:00041Z]`, `[UID:000421]`, and `[UID:000423]`; the coverage text above has been updated to those real UIDs. B003 did not edit `by-memory/-coverage-report.md` or any other `-coverage-report.md` file.

- [x] Created `by-memory/0x0041ba40-0x0041bdce.FittingRoomDownloadControlPaneOnPaint.md` as `[UID:00041P]`; set `86/90`, owner/emitter `000052`, reconstructable true, blank emitter position, blank C++; incorporated MCP `80de0a67` vtable xref `0x0060da08`, size `0x38e`, SHA16 `a049034203d827aa`, progress byte `this+0x108`, render/resource callee evidence, rejected generic/GrafPort/FittingRoom-direct/no-owner alternatives, and no-code proof.
- [x] Created `by-memory/0x004216d0-0x0042170a.FittingRoomItemEntryVectorStorageFree.md` as `[UID:00041Q]`; set `86/88`, owner/emitter `000053`, reconstructable true, blank emitter position, blank C++; incorporated caller `0x0042112b`, `180 * count` free, MSVC large-allocation guard, callees `0x005c7526` and invalid-parameter guard, SHA16 `ecfd2b5c14071dbe`, rejected generic/vector/no-owner alternatives, and no-code proof.
- [x] Created `by-memory/0x00421710-0x00421839.FittingRoomItemEntryVectorErase.md` as `[UID:00041R]`; set `86/89`, owner/emitter `000053`, reconstructable true, blank emitter position, blank C++; incorporated caller `0x0041fedc`, `0xb4` entry erase/move behavior, `0x50` WCHAR copy, nested vector triplet transfer, call to `0x00421380`, SHA16 `6373c0c1ef4bbbd2`, rejected alternatives, and no-code proof.
- [x] Created `by-memory/0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md` as `[UID:00041S]`; set `85/88`, owner/emitter `000051`, reconstructable true, blank emitter position, blank C++; incorporated JsonCpp keys `part/tile/color/gender`, packed 6-byte record offsets, reject sentinels `0xf5`/`0xff`, callee set, no caller/xref/pointer-route evidence, SHA16 `d3648d01be4ef864`, rejection of active C++/merge/no-owner/ItemCatalog/JsonCpp ownership, and no-code proof.
- [x] Created `by-memory/0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md` as `[UID:00041T]`; set `85/87`, owner/emitter `000051`, reconstructable true, blank emitter position, blank C++; incorporated no-function results at `0x004219e1/0x004219f0/0x00421a20/0x00421a30`, no xrefs to `0x004219f0/0x00421a30`, no VA/RVA pointer hits, SHA16 `cccd81280ec94378`, entry initializer/thunk byte roles, rejected padding-only/active-C++ alternatives, and no-code proof.
- [x] Created `by-memory/0x00424300-0x004243b0.FittingRoomUserImageControlPaneConstructor.md` as `[UID:00041U]`; set `86/90`, owner/emitter `000056`, reconstructable true, blank emitter position, blank C++; incorporated caller `0x0041bfda`, vtable stores `0x0060e07c/0x0060e0e4/0x0060e114`, fields `+0x108/+0x10c/+0x110/+0x114`, `300` ms timer start, SHA16 `211386c0d3895ed1`, rejected generic ControlPane/TimerHandler/no-owner alternatives, and no-code proof.
- [x] Created `by-memory/0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md` as `[UID:00041V]`; set `85/90`, owner/emitter `000056`, reconstructable true, blank emitter position, blank C++; incorporated vtable restores, teardown call, no xrefs, SHA16 `854fe91dc4a6888f`, and destructor-duplicate no-code proof.
- [x] Created `by-memory/0x004243d0-0x004244fb.FittingRoomUserImageControlPaneOnPaint.md` as `[UID:00041W]`; set `86/89`, owner/emitter `000056`, reconstructable true, blank emitter position, blank C++; incorporated vtable cell `0x0060e0c0`, tiled background, appearance/direction render path, global render helper refs, SHA16 `271d1481dfa9e04e`, rejected generic renderer/no-owner alternatives, and no-code proof.
- [x] Created `by-memory/0x00424500-0x0042454e.FittingRoomUserImageControlPaneOnTimer.md` as `[UID:00041X]`; set `86/89`, owner/emitter `000056`, reconstructable true, blank emitter position, blank C++; incorporated vtable cell `0x0060e118`, timer id `0`, frame/pause fields, invalidate/reschedule path, SHA16 `254b7adb3e84b3c7`, and no-code proof.
- [x] Created `by-memory/0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md` as `[UID:00041Y]`; set `88/92`, owner/emitter `000056`, reconstructable true, blank emitter position; added accepted first-draft C++ for increment/wrap of `m_facingDirection`; incorporated caller `0x0041c486`, SHA16 `a9205a0255299b43`, and rejected no-code/no-owner/generic helper alternatives.
- [x] Created `by-memory/0x00424570-0x00424584.FittingRoomUserImageControlPaneRetreatFacingDirection.md` as `[UID:00041Z]`; set `88/92`, owner/emitter `000056`, reconstructable true, blank emitter position; added accepted first-draft C++ for decrement/wrap of `m_facingDirection`; incorporated caller `0x0041c49f`, SHA16 `c07d5af5eb4abdeb`, and rejected no-code/no-owner/generic helper alternatives.
- [x] Created `by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md` as `[UID:000421]`; set `86/92`, owner `NONE`, reconstructable false, blank emitter fields, blank C++; incorporated vtable refs `0x0060e0e4/0x0060e114`, thunk adjustment bytes, SHA16 `0ba2e54363ffe97f`, and compiler-thunk no-code proof.
- [x] Created `by-memory/0x004245a0-0x004245f5.FittingRoomUserImageControlPaneScalarDeletingDestructor.md` as `[UID:000423]`; set `86/91`, owner/emitter `000056`, reconstructable true, blank emitter position, blank C++; incorporated vtable ref `0x0060e07c`, adjustor thunk callers, teardown/delete behavior, SHA16 `1909c91c8a5203f1`, and scalar-wrapper no-code proof.
- [x] Updated `by-memory/-ignored.md` for `0x004216cb-0x004216d0`, `0x0042170a-0x00421710`, `0x00421839-0x00421860`, `0x004243cf-0x004243d0`, `0x004244fb-0x00424500`, `0x0042454e-0x00424550`, `0x0042456a-0x00424570`, and `0x0042459a-0x004245a0`; preserved `0x004219e1-0x00421a40` as no-code child `[UID:00041T]`, not ignored padding.
- [x] Updated parent `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`: set `88/89`, kept owner/emitter `0000JE`, reconstructable true, blank emitter position and blank aggregate C++; linked all real child UIDs; replaced stale Wave3/currentness wording with MCP `80de0a67`; preserved rejected alternatives, negative route checks, bytes/SHA, and aggregate no-code proof.
- [x] Updated `by-file/FittingRoom.md`: set `87/89`; added split inventory, source-module route, no-aggregate-C++ policy, and rejected owner/source-placement alternatives.
- [x] Updated `by-class/FittingRoomDownloadControlPane.md`: set `86/90`; linked `[UID:00041P]`; added current-session evidence and blank-C++ policy.
- [x] Updated `by-class/FittingRoomListPane.md`: set `86/88`; linked `[UID:00041Q]` and `[UID:00041R]`; added current-session evidence and no-code vector-helper policy.
- [x] Updated `by-class/FittingRoomDialogItemState.md`: kept `88/90`; added no-route part-parser `[UID:00041S]` and catalog-tail `[UID:00041T]` support notes; preserved active `[UID:0002E4]` parser source ownership.
- [x] Updated `by-class/FittingRoomUserImageControlPane.md`: set `87/90`; replaced local-core aggregate row with the real child inventory; recorded direction-helper C++ readiness and blank-C++ policy for constructor/paint/timer/destructor/thunks.
- [x] Updated `by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md` with `[UID:00041Q]` link and caller/callee proof; metadata unchanged.
- [x] Updated `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md` with `[UID:00041R]` link and call-site proof; metadata unchanged.
- [x] Updated `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md` with the no-route parser sibling rejection and duplicate-C++ note; metadata unchanged.
- [x] Confirmed no accepted callback edit was applied to `by-file/CashShopVersionRequest.md`, `by-file/ItemCatalog.md`, `by-class/ItemCatalog.md`, generic/string/vector/helper docs, generated files, IDA DB, tool state, or any `-coverage-report.md` file. They were outside accepted implementation scope unless a direct contradiction was found; none was needed for this callback.
- [x] Lease rule followed for existing docs: B003 took leases for the existing target/support docs before editing. On release, `leaser.py` reported `Rejected[No active lease]` because the leases had already expired; the lease report showed no active B003 lease after cleanup. New child files could not be leased before creation.
- [x] Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for every created/changed by-* doc. Every command exited `0`, every warning count was `0`, and the validator reported only backup/autogen-noop side effects. `by-class\FittingRoomDialogItemState.md` returned `ok` count `15`; all other files returned `ok` count `14`.

Validator command/result ledger:

| File argument | Exit | ok | Warnings |
| --- | ---: | ---: | ---: |
| `by-memory\0x0041ba40-0x0041bdce.FittingRoomDownloadControlPaneOnPaint.md` | 0 | 14 | 0 |
| `by-memory\0x004216d0-0x0042170a.FittingRoomItemEntryVectorStorageFree.md` | 0 | 14 | 0 |
| `by-memory\0x00421710-0x00421839.FittingRoomItemEntryVectorErase.md` | 0 | 14 | 0 |
| `by-memory\0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md` | 0 | 14 | 0 |
| `by-memory\0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md` | 0 | 14 | 0 |
| `by-memory\0x00424300-0x004243b0.FittingRoomUserImageControlPaneConstructor.md` | 0 | 14 | 0 |
| `by-memory\0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md` | 0 | 14 | 0 |
| `by-memory\0x004243d0-0x004244fb.FittingRoomUserImageControlPaneOnPaint.md` | 0 | 14 | 0 |
| `by-memory\0x00424500-0x0042454e.FittingRoomUserImageControlPaneOnTimer.md` | 0 | 14 | 0 |
| `by-memory\0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md` | 0 | 14 | 0 |
| `by-memory\0x00424570-0x00424584.FittingRoomUserImageControlPaneRetreatFacingDirection.md` | 0 | 14 | 0 |
| `by-memory\0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md` | 0 | 14 | 0 |
| `by-memory\0x004245a0-0x004245f5.FittingRoomUserImageControlPaneScalarDeletingDestructor.md` | 0 | 14 | 0 |
| `by-memory\0x0041ba40-0x004245f5.FittingRoomUiCore.md` | 0 | 14 | 0 |
| `by-memory\-ignored.md` | 0 | 14 | 0 |
| `by-file\FittingRoom.md` | 0 | 14 | 0 |
| `by-class\FittingRoomDownloadControlPane.md` | 0 | 14 | 0 |
| `by-class\FittingRoomListPane.md` | 0 | 14 | 0 |
| `by-class\FittingRoomDialogItemState.md` | 0 | 15 | 0 |
| `by-class\FittingRoomUserImageControlPane.md` | 0 | 14 | 0 |
| `by-memory\0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md` | 0 | 14 | 0 |
| `by-memory\0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md` | 0 | 14 | 0 |
| `by-memory\0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md` | 0 | 14 | 0 |

Validator side effects recorded: validator backup directories under `tools/validator_autogen_backup/20260623-*`; auto-generated report/C++ output was reported as unchanged/noop, including `auto-generated/-ag-*-coverage.md` reports and unchanged generated C++ outputs. B003 did not manually edit generated/project-level files.

- [x] Supervisor-owned coverage remains pending for supervisor application only. The exact coverage block above contains the real child UIDs and the padding rows to add/refresh; B003 did not edit any coverage report.
- [x] Remaining accepted implementation blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0000WR-FittingRoomUiCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0000WR"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000WR-FittingRoomUiCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0000WR-FittingRoomUiCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000WR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

** TARGET-REPORT-UID:0000ON **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000ON] TextEditPane Empty-Emitter Family Source-Quality Report

Agent: Agent-B004  
Assignment: `B004-report-0000ON-TextEditPane-empty-emitter-family-20260629`  
Target: [UID:0000ON] `by-file/TextEditPane.md`  
Generated unit: `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`  
Report path: `tools/leaser/Agents/Agent-B004/research/0000ON-TextEditPane-empty-emitter-family-source-quality.md`  
Mode: revised report accepted; corrected implementation callback applied in the proof/ledger sections below.

## Final Recommendation

[UID:0000ON] is not an empty-source file. The current generated unit is stale/incomplete because it emits only 3 of 23 TextEditPane-family contributors, while current by-* and MCP evidence support a bounded implementation batch that can resolve several direct empty emitters without changing generated files by hand.

Recommended immediate implementation batch:

1. Insert first-draft formal C++ for [UID:0002O9] `TextEditPaneCopyWideText`.
2. Insert declaration-container C++ for [UID:0000EN] `TextEditObject` and [UID:0000EP] `TextEditScrap`, using the current accepted support-object layouts. For `TextEditObject`, reject the stale `RectBounds`/`Draw`/`GetBounds`/`SetBounds` shape and use the `m_objectType` / `m_ownerHandle` / `m_payload0` / `m_payload1` layout with object-type, owner-handle, payload-pair, and provisional no-op virtual hook methods. Update the [UID:00004H] `EPFTextEditObject` support row without inventing unresolved embedded-frame fields.
3. Insert/repair module static/global declarations for [UID:0000Q7], [UID:000302], [UID:000301], and [UID:000303]. Current MCP byte reads show `0x0069bdfc`, `0x0069be00`, and `0x0069be04` initialize to zero; any stale note saying the static image sample is `0xffffffff` or `0xffff` should be corrected.
4. Convert duplicate by-item markers [UID:0000UK] and [UID:0000UM] to covered-by/canonical-owner comments: [UID:0000UK] is covered by [UID:0001JR]; [UID:0000UM] is the by-item mirror for [UID:0001JN] and must not emit a second body.
5. Update the by-file TextEditPane source-emission notes, generated-empty inventory, support ordering note, and score rationale to reflect the current MCP-backed classification.
6. Update the large real-body rows ([UID:0002ZY], [UID:0002ZZ], [UID:00030C], [UID:00030F], [UID:00030E], [UID:00030D], [UID:0001JN], [UID:0001JM], [UID:0001JP], [UID:0001JS]) with report-level evidence and explicit blockers, but do not force short formal C++ into them in this callback.

The large constructor/destructor/draw/input/formatting/navigation aggregate rows are not no-code rows. They are source-bearing rows whose current blockers are signature, table/list helper names, event-structure spelling, and remaining split inventory. The correct implementation response is to document the blockers precisely and leave their `RECONSTRUCTION_CPP` blocks blank until a dedicated first-draft or split callback is accepted.

## Report-Time Generated State

The accepted report-time generated unit header reported the following snapshot. Post-implementation validator-owned freshness is recorded in `Implementation Callback Proof`.

- Generated file: `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`
- Source UID: `0000ON`
- Validator command: `000000001482`
- Refreshed at: `2026-06-29T23:05:49-04:00`
- Refresh source: `foreground-generated-refresh`

Observed emitted/non-emitted status:

| Row | UID | Path | Current generated state | Recommended disposition |
| --- | --- | --- | --- | --- |
| 1 | 0002ZY | `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md` | Empty | Real constructor body; add evidence/blocker detail, no first-draft body yet. |
| 2 | 00004H | `by-class/EPFTextEditObject.md` | Empty | Support class formal declaration remains blocked by embedded frame type; update stale/support wording only and keep formal C++ blank unless a separate accepted support declaration exists. |
| 3 | 0000EN | `by-class/TextEditObject.md` | Empty | Emit declaration-container C++ matching the current accepted `m_objectType` / `m_ownerHandle` / `m_payload0` / `m_payload1` layout and method family; do not use the stale `RectBounds` declaration. Method bodies are covered by exact child rows. |
| 4 | 0001JM | `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md` | Empty | Real aggregate/split parent; do not insert no-code until child split is complete. |
| 5 | 0002ZZ | `by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md` | Empty | Real destructor; add evidence/blocker detail, no first-draft body yet. |
| 6 | 0002O9 | `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md` | Empty | Emit first-draft C++; route and body are narrow and MCP-backed. |
| 7 | 00030C | `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md` | Empty | Real draw body; update detailed blocker/evidence, no body yet. |
| 8 | 00030F | `by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md` | Empty | Real key/input body; update detailed blocker/evidence, no body yet. |
| 9 | 00030E | `by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md` | Empty | Real mouse body; update detailed blocker/evidence, no body yet. |
| 10 | 00030D | `by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md` | Empty | Real helper body; update evidence/blocker detail; first-draft depends on rectangle-list helper naming. |
| 11 | 0000EP | `by-class/TextEditScrap.md` | Empty | Emit declaration-container C++ matching the current accepted `m_textLength` / `m_text` / `m_payloadSize` / `m_payload` layout and clipboard helper family; body rows remain separately owned. |
| 12 | 0000Q7 | `by-global/g_pActiveTextEditPane.md` | Empty | Emit global declaration. |
| 13 | 000302 | `by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md` | Empty | Emit covered-by comment or declaration consistent with [UID:0000Q7]; initializer is zero. |
| 14 | 0000UK | `by-item/DrawTextRunCallback_00593DB0.md` | Empty | Duplicate item; no standalone body; covered by [UID:0001JR]. |
| 15 | 0000UM | `by-item/EncodeTextEditState_0058E490.md` | Empty | Duplicate item; canonical body is [UID:0001JN]. |
| 16 | 0001JN | `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` | Empty | Real serializer body; update support note, but keep formal body blocked pending exact Encoder/local buffer spelling. |
| 17 | 0001JP | `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md` | Empty | Large source-bearing formatting aggregate; keep split-before-body policy. |
| 18 | 0001JS | `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` | Empty | Large source-bearing navigation/wrap aggregate; keep split-before-body policy. |
| 19 | 000301 | `by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md` | Empty | Emit module static declaration; initializer is zero. |
| 20 | 000303 | `by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md` | Empty | Emit module static declaration; initializer is zero. |

Already filled in the generated unit:

- [UID:0000EO] `by-class/TextEditPane.md`
- [UID:0001JQ] `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`
- [UID:0001JR] `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`

## Revision After Implementation Conflict

This report was revised after the first implementation callback paused on a valid conflict in [UID:0000EN] `by-class/TextEditObject.md`.

Superseded report claim:

- The original report recommended a `TextEditObject` declaration with `Draw(GrafPort *, const RectBounds *)`, `GetBounds`, `SetBounds`, and `RectBounds m_bounds`.

Current-doc contradiction:

- Current [UID:0000EN] `by-class/TextEditObject.md` documents `TextEditObject` as an `LObject`-derived inline/payload object with `m_objectType` at `+0x04`, `m_ownerHandle` at `+0x08`, `m_payload0` at `+0x0c`, and `m_payload1` at `+0x10`.
- Current method families are `TextEditObject::TextEditObject(void *ownerHandle)`, non-deleting `~TextEditObject()`, `GetObjectType()`, `GetPayloadPair(int *outPair)`, `GetOwnerHandle()`, `SetPayloadPair(int first, int second)`, provisional `OnUpdate()`, provisional `OnAction(int,int,int)`, and the separate scalar deleting destructor/vtable support.
- Executed B011 support-object split research created/accepted the exact [UID:00040S] `0x00594e60-0x00594f23.TextEditObjectCoreMethods` child for constructor, destructor body, accessors, payload-pair helpers, and no-op virtual hooks. That evidence directly rejects the stale rectangle/bounds class shape.
- Executed B006 `DrawTextRunCallback` evidence strengthens the provisional `OnUpdate()`/inline-object hook route: when `TextRunFormatData::object` is non-null, the draw callback dispatches the object vtable slot and suppresses ordinary UTF-16 drawing. This supports keeping the virtual hook in `TextEditObject`; it does not support `RectBounds m_bounds`.
- Executed B007 `TextRunMeasureCallback` evidence uses `TextEditObject::m_payload1` as an embedded-object advance value in the measure path, while explicitly preserving the payload-pair interpretation instead of renaming the whole class to a rectangle/bounds object.

Corrected support disposition:

- [UID:0000EN] `TextEditObject`: insert a declaration-container block only if the implementation callback accepts class-page declaration emission; the block must use the current payload/object-type layout and method family shown below. Do not insert the stale `RectBounds` block. Method bodies stay on [UID:00040S] and sibling exact children.
- [UID:0000EP] `TextEditScrap`: the original report's broad shape was directionally correct, but this revision anchors it to current docs and B011/B012 evidence. Use the accepted text/payload buffer layout and clipboard helper family. Method bodies stay on [UID:00040T] and sibling exact children.
- [UID:00004H] `EPFTextEditObject`: keep formal class C++ blank in this callback. Current docs support only stale/support wording updates: the class derives from `TextEditObject`, uses embedded frame storage at `this + 0x14`, has constructor/helper/destructor ranges, and remains blocked on exact frame helper type/name. Do not invent a declaration with unresolved fields.

Implementation effect:

- The rest of the accepted TextEditPane batch remains unchanged: [UID:0002O9] first-draft body, active-editor global/storage rows, styled clipboard static, mouse-selection static, duplicate by-item rows, and large real-body blocker documentation still stand.
- The Claim And Incorporation Ledger and Implementation Tracking Checklist below now mark the stale `RectBounds` `TextEditObject` declaration as `reject-stale` and replace it with the current declaration-container block.

## MCP Availability And Database Evidence

Current MCP endpoint: `http://127.0.0.1:13337/mcp`

The server was available and backed by the required current database:

- MCP server: `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`
- Active session id: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Input path reported by server health: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready`: true
- `hexrays_ready`: true
- `strings_cache_ready`: true
- Active worker PID reported by `idb_list`: `17592`

Operator note: three early JSON-RPC requests failed because my local PowerShell helper passed an empty argument map after using `$args` as a parameter name. The returned error was `database is required`. A separate `xrefs_to` retry corrected my parameter name from unsupported `max` to schema `limit`. These were local request-construction mistakes, not MCP unavailability or timeout evidence. The successful calls below are the evidence base for this report.

## MCP Function And Data Facts

### Function lookup

MCP `lookup_funcs` on the direct family addresses returned:

| Address | MCP symbol | Size/result |
| --- | --- | --- |
| `0x0058dce0` | `sub_58DCE0` | `0x452` bytes |
| `0x0058e140` | `sub_58E140` | `0xe8` bytes |
| `0x0058e380` | `sub_58E380` | `0x57` bytes |
| `0x0058e490` | `sub_58E490` | `0x201` bytes |
| `0x00590810` | `sub_590810` | `0x1d3` bytes |
| `0x005909f0` | `sub_5909F0` | `0x3d5` bytes |
| `0x00590de0` | `sub_590DE0` | `0x38c` bytes |
| `0x00591740` | `sub_591740` | `0x89` bytes |
| `0x00591d60` | not a function | aggregate starts before child/helper functions |
| `0x00594040` | `sub_594040` | `0xd6` bytes |
| `0x00594e60` | not a function | aggregate end boundary |
| `0x00594f30` | `sub_594F30` | `0x38` bytes |
| `0x005954c0` | `sub_5954C0` | `0xd0` bytes |
| `0x0069bdfc` | not a function | static data |
| `0x0069be00` | not a function | static/global data |
| `0x0069be04` | not a function | static scratch data |

### Xrefs and routing

MCP `xrefs_to` and `xref_query` confirm:

- `0x0058dce0` has 26 constructor-like code xrefs from UI/control owners, including raw constructor calls from `0x475af2`, `0x476222`, `0x47ba8e`, `0x47c311`, `0x4840f5`, `0x4885dd`, `0x498a82`, `0x499137`, `0x4a01a1`, `0x4f1d64`, `0x4f1f27`, `0x4ff175`, `0x4ff535`, `0x56bad7`, `0x56bb81`, `0x56bc15`, `0x56c461`, `0x56c559`, `0x56c809`, `0x57fdec`, `0x58eefa`, `0x5953ee`, `0x59f333`, `0x59f3c9`, `0x5a2317`, and `0x5a2397`.
- `0x0058e140` has four destructor-like code xrefs: `0x48c4d6`, `0x514ad0`, `0x57383e`, and `0x6098b8`.
- `0x0058e380` has seven callers: `0x47c90c`, `0x495664`, `0x495aca`, `0x498c1a`, `0x4f230a`, `0x4f2a34`, and `0x580631`.
- `0x0058e490` has one direct raw code xref at `0x498c4a`; [UID:0000UM] is a by-item mirror for this canonical memory range.
- `0x00590810` is routed through nine vtable data xrefs at `0x615664`, `0x61e810`, `0x624280`, `0x624334`, `0x6243f4`, `0x62e000`, `0x62e0dc`, `0x62edc4`, and `0x62ee78`.
- `0x005909f0` is routed through seven vtable data xrefs at `0x61565c`, `0x624278`, `0x62432c`, `0x6243ec`, `0x62dff8`, `0x62edbc`, and `0x62ee70`.
- `0x00590de0` has one vtable data xref at `0x62dff4`.
- `0x00591740` has no direct external xrefs in the MCP result, matching an internal invalidation helper called from draw/key/mouse flows.
- `0x00594040` has two direct callers, `0x58ebb1` and `0x590daa`.
- `0x00593db0` has address-taking xrefs at `0x5908e6` and `0x59168c`; the body is already owned/emitted by [UID:0001JR], so [UID:0000UK] must stay non-duplicating.
- `0x0069bdfc` has six data xrefs: constructor registration at `0x58e0a1` and `0x58e0b5`, key/paste use at `0x590b58`, helper uses at `0x591a6d` and `0x591a98`, and raw use at `0x591c70`.
- `0x0069be00` has eight data xrefs: external active-pane users at `0x553e84`, `0x554520`, `0x55452b`, `0x554540`, constructor read/write at `0x58dd5c` and `0x58dd6b`, and destructor read/write at `0x58e181` and `0x58e18d`.
- `0x0069be04` has eight data xrefs, all in `TextEditPane::OnMouseEvent`: `0x590f3d`, `0x590f5f`, `0x59100a`, `0x59101c`, `0x59102b`, `0x5910e9`, `0x5910fb`, and `0x59110a`.

### Static data initializer facts

MCP `get_int` returned:

- `u32le(0x0069bdfc) == 0`
- `u32le(0x0069be00) == 0`
- `u16le(0x0069be04) == 0`

MCP `get_bytes` returned all-zero bytes for:

- `0x0069bdf8` size 16
- `0x0069be00` size 8

Therefore the current implementation callback should correct stale notes in [UID:000301] and [UID:000303] if they still describe a sample initializer of `0xffffffff` or `0xffff`. The live IDB evidence supports zero-initialized module/static data.

## Body Shape Evidence

### [UID:0002O9] `TextEditPaneCopyWideText`

MCP decompile for `0x0058e380`:

- Prototype shape: `__int16 __thiscall sub_58E380(_DWORD *this, void *a2, __int16 a3)`
- Calls allocation/string helpers `0x516030` and `0x516220`.
- Reads a text storage pointer from `this + 0x134`.
- Reads a count from the storage object at offset `+0x0c`.
- Clamps the copy count against caller capacity.
- Gets the wide source buffer through a virtual method at storage vtable slot `+0x10`, with index `0`.
- Copies `2 * count` bytes into the destination.
- Writes a trailing wide NUL.
- Returns the copied character count.

This is a narrow, complete source helper with no unresolved control-flow ambiguity. It is the best direct first-draft body candidate in the current empty-emitter family.

### [UID:0002ZZ] `TextEditPaneDestructor`

MCP decompile for `0x0058e140`:

- Restores TextEditPane/TextBoxPane vtables during teardown.
- Clears `g_pActiveTextEditPane` (`0x0069be00`) if the active pointer equals `this`.
- Calls the TextEditPane-local cleanup helper at `0x5912b0`.
- Deletes several owned pointer fields at offsets `+0x134`, `+0x138`, `+0x13c`, and `+0x140` through guarded virtual delete paths.
- Unregisters from the manager/global table at `0x0069b458` through helper `0x4e80a0`.
- Falls through into base cleanup at `0x55e780`.

This is a real destructor, not a no-code row. It should remain blank until the owned-field names, manager/table type, and base destructor route are documented at source-quality level.

### [UID:00030D] `TextEditPaneInvalidateTextRegion`

MCP decompile for `0x00591740`:

- Prototype shape: `void __thiscall sub_591740(void *this, __int16 a2, __int16 a3)`.
- Constructs a temporary rectangle/list object with `sub_4F3060(v7, 16, 16)`.
- Calls `sub_591520(this, a2, a3, v7)` to build affected rectangles.
- Iterates list entries through `sub_4F32B0(v7, i)`.
- Invalidates/composites each rectangle through `sub_4BA540(this, rect)`.
- Cleans up through `sub_4F30E0(v7)`.

This is also a real helper body. It is close to first-draft quality, but the report recommends deferring the formal body until the temporary rectangle-list type and `BuildInvalidationRects` helper signature are named consistently across [UID:00030C] and [UID:00030D].

### [UID:00030C] `TextEditPaneOnDraw`

MCP `analyze_function` for `0x00590810`:

- Size: `0x1d3` bytes.
- Prototype shape: `void __thiscall(int this)`.
- Basic blocks: 19.
- Cyclomatic complexity: 7.
- Vtable routes: nine xrefs.
- Callees include clipping/draw-state helpers `0x4b9660`, external callback/table `0x69b3fc`, `0x4b96c0`, line conversion `0x592bb0`, text-run iteration `0x593500`, invalidation/list helpers `0x4f3060`, `0x591520`, `0x4f32b0`, `0x4ba540`, cleanup `0x4f30e0`, text-layout helper `0x58f740`, and draw helper `0x4baaa0`.
- It takes the already-emitted [UID:0001JR] `DrawTextRunCallback` address during text-run drawing.

This is source-bearing draw code. The current blocker is not liveness. The blocker is exact spelling and field ownership for draw-state flags at `this + 348`, text/range fields at `+68`, `+112`, `+116`, and `+128`, the selection/highlight branches, and rectangle-list helper names shared with [UID:00030D].

### [UID:00030F] `TextEditPaneOnKeyEvent`

MCP `analyze_function` for `0x005909f0`:

- Size: `0x3d5` bytes.
- Prototype shape: `char __thiscall(int this, int event)`.
- Basic blocks: 63.
- Cyclomatic complexity: 35.
- Vtable routes: seven xrefs.
- Handles key event type `8` and input/text event type `10`.
- Implements control-key flows including copy, paste, and cut.
- Uses [UID:0000EP] `TextEditScrap`.
- Checks [UID:000301] `s_styledUnicodeClipboardFormat` around paste/clipboard handling.
- Calls allocator/string wrappers `0x516030`, `0x516050`, `0x516220`, `0x516170`.
- Calls editing helpers such as `0x594120`, `0x58fc30`, `0x594f30`, `0x5901b0`, `0x593280`, `0x591400`, `0x5917d0`, `0x594f70`, `0x591a20`, `0x595140`, and `0x594040`.

This row is a real high-complexity input handler. It should not receive a condensed source body until the event struct, key constants, clipboard helper names, and TextEditScrap method spellings are accepted.

### [UID:00030E] `TextEditPaneOnMouseEvent`

MCP `analyze_function` for `0x00590de0`:

- Size: `0x38c` bytes.
- Prototype shape: `char __thiscall(int this, int event)`.
- Basic blocks: 52.
- Cyclomatic complexity: 26.
- Vtable route: one xref at `0x62dff4`.
- Uses [UID:000303] `s_mouseSelectionAnchor` at `0x0069be04`.
- Contains a five-case mouse-event switch.
- Uses hit-test/position helpers `0x4b7e80`, `0x58f690`, `0x58f1b0`, `0x58fa00`, `0x58f9a0`, `0x4e9490`, `0x5449d0`, `0x58f0d0`, `0x594b50`, `0x58f2a0`, `0x594cb0`, `0x544a00`, and `0x5449f0`.

This row is a real high-complexity mouse handler. It should not be compressed into a first-draft body until event-field names and helper names are stable.

### [UID:0001JN] `TextEditPaneSerialization`

MCP `analyze_function` for `0x0058e490`:

- Size: `0x201` bytes.
- Prototype shape: `void *__fastcall(_DWORD *this, int unused, _WORD *outSize)`.
- Basic blocks: 5.
- Uses stack allocation and security-cookie cleanup.
- Calls Encoder helpers in the `0x4a4e70` through `0x4a55e0` family.
- Calls allocation/string wrappers `0x516030`, `0x516050`, `0x516220`.
- Has a duplicate by-item row [UID:0000UM].

This is real serializer code and should remain canonical at the by-memory row. The duplicate by-item row should not emit a second body.

## Negative Evidence And Exclusions

- No evidence supports treating [UID:0001JM], [UID:0001JP], or [UID:0001JS] as no-code rows. MCP confirms function starts inside those aggregates, and the current generated empties are caused by split/first-draft incompleteness, not compiler padding.
- No evidence supports editing generated `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` by hand. Its header shows a validator-owned refresh, so implementation must edit by-* docs and let validators regenerate/refresh as designed.
- No evidence supports moving ownership for TextEditPane callbacks away from [UID:0001JQ] and [UID:0001JR]. The callback address-taking xrefs are live and the generated file already emits those bodies.
- No evidence supports duplicating [UID:0001JR] through [UID:0000UK]. [UID:0000UK] is a by-item mirror and should carry a formal covered-by comment.
- No evidence supports editing ItemObjImageLib, GrafPort, RectBounds, EPFTileContext, or unrelated support libraries during this TextEditPane callback. The direct support dependencies are TextEditPane/TextEditObject/TextEditScrap/EPFTextEditObject, Encoder helpers, MemoryMan/string helpers, rectangle/list helpers, clipboard globals, and callback state.
- No evidence supports changing IDA database, MCP process state, validator state, supervisor ledgers, generated reports, coverage reports, executed archives, or lock files.

## Formal C++ Recommendations

These blocks are intended for implementation callback use only after supervisor acceptance. They were not inserted during this report-only pass.

### [UID:0002O9] `TextEditPane::CopyWideText`

Recommended metadata after insertion:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000EO`
- `EMITTER_UIDS:0000ON`
- Keep `EMITTER_POSITION_OPTIONAL` blank unless the file-level order policy requires otherwise.

Recommended formal C++:

```cpp
short TextEditPane::CopyWideText(wchar_t *outText, short capacity) const
{
    if (capacity <= 0) {
        if (outText != NULL) {
            outText[0] = L'\0';
        }
        return 0;
    }

    short count = 0;
    const wchar_t *source = NULL;

    if (m_textStorage != NULL) {
        count = static_cast<short>(m_textStorage->GetCount());
        if (count > capacity) {
            count = capacity;
        }
        if (count > 0) {
            source = static_cast<const wchar_t *>(m_textStorage->GetData(0));
            MemoryMan::Copy(outText, source, static_cast<unsigned int>(count) * sizeof(wchar_t));
        }
    }

    outText[count] = L'\0';
    return count;
}
```

Implementation note: if accepted support docs use different local names for the list/count/data accessors or MemoryMan copy wrapper, use the accepted local names while preserving the exact logic above: clamp to capacity, copy `2 * count` bytes from the first text-storage item, terminate with wide zero, and return copied count.

### [UID:0000EN] `TextEditObject`

Recommended metadata after insertion:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000ON`
- `EMITTER_UIDS:0000ON`
- Keep class-page policy as declaration-container only; method bodies remain in exact child rows.

Corrected declaration-container C++:

```cpp
class TextEditObject : public LObject
{
public:
    TextEditObject(void *ownerHandle);
    virtual ~TextEditObject();

    int GetObjectType() const;
    void GetPayloadPair(int *outPair) const;
    void *GetOwnerHandle() const;
    void SetPayloadPair(int first, int second);

    virtual void OnUpdate();
    virtual void OnAction(int first, int second, int third);

protected:
    int m_objectType;
    void *m_ownerHandle;
    int m_payload0;
    int m_payload1;
};
```

Implementation note: this block supersedes and rejects the stale `RectBounds` / `Draw` / `GetBounds` / `SetBounds` declaration. It follows current [UID:0000EN] docs and executed B011 [UID:00040S] support-object evidence: `+0x04` object type, `+0x08` owner handle, `+0x0c/+0x10` payload pair, accessors, setter, and provisional no-op virtual hooks. Retain exact child-body ownership for [UID:00040S] and sibling support rows; the class page is a declaration container only.

### [UID:0000EP] `TextEditScrap`

Recommended metadata after insertion:

- `COMPLETION:89`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000ON`
- `EMITTER_UIDS:0000ON`
- Keep class-page policy as declaration-container only; method bodies remain separately owned.

Recommended declaration-container C++:

```cpp
class TextEditScrap : public LObject
{
public:
    TextEditScrap();
    virtual ~TextEditScrap();

    void Clear();
    bool IsEmpty() const;
    void SetText(const wchar_t *text, int length);
    void SetPayload(const void *payload, int size);
    int DuplicateText(wchar_t **outText) const;
    int DuplicatePayload(void **outPayload) const;
    int BuildClipboardBlock(void **outBlock) const;
    void SetFromClipboardBlock(const void *data, int dataSize);

private:
    int m_textLength;
    wchar_t *m_text;
    int m_payloadSize;
    void *m_payload;
};
```

Implementation note: this declaration-container block matches current [UID:0000EP] docs and executed B011/B012 evidence. Existing docs use `m_textBuffer` / `m_payloadBuffer` in prose and the child draft shortens those fields to `m_text` / `m_payload`; both naming forms refer to the same `+0x08` and `+0x10` layout slots. Do not move [UID:00040T] method bodies into the class page, and preserve the packed clipboard length-unit caveat in support notes.

### [UID:00004H] `EPFTextEditObject`

Recommended disposition:

- Do not insert a broad invented declaration with unknown embedded-frame fields in the immediate callback.
- Update the support row only if it still has stale wording that conflicts with current docs. The safe support wording is: `EPFTextEditObject` is a `TextEditObject` derivative in the TextEditPane support-object family; constructor/helper/destructor evidence is documented, embedded frame storage is at `this + 0x14`, and final formal declaration/body C++ remains blocked on the exact frame helper type/name.
- Keep the formal C++ blank unless an already-accepted support declaration exists in by-class docs and only stale TextEditPane-family wording needs repair.

### [UID:0000Q7] and [UID:000302] `g_pActiveTextEditPane`

Recommended metadata after insertion:

- [UID:0000Q7] `COMPLETION:90`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000ON`, `EMITTER_UIDS:0000ON`.
- [UID:000302] `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000Q7`, `EMITTER_UIDS:0000ON`, or use the project-approved covered-by pattern if the by-global row is the only emitter.

Recommended formal C++ for the global owner:

```cpp
TextEditPane *g_pActiveTextEditPane = NULL;
```

Recommended formal covered-by comment for the memory row if the by-global row emits the declaration:

```cpp
// Emitted code for this global storage is covered by [UID:0000Q7].
```

### [UID:000301] `s_styledUnicodeClipboardFormat`

Recommended metadata after insertion:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000ON`
- `EMITTER_UIDS:0000ON`

Recommended formal C++:

```cpp
static unsigned int s_styledUnicodeClipboardFormat = 0;
```

Evidence requirement for implementation: record that MCP `get_int` and `get_bytes` show zero initialization and supersede any stale `0xffffffff` sample note.

### [UID:000303] `s_mouseSelectionAnchor`

Recommended metadata after insertion:

- `COMPLETION:87`
- `CONFIDENCE:91`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000ON`
- `EMITTER_UIDS:0000ON`

Recommended formal C++:

```cpp
static short s_mouseSelectionAnchor = 0;
```

Evidence requirement for implementation: record that all live xrefs are inside `TextEditPane::OnMouseEvent` and that MCP byte/int reads show zero initialization, not `0xffff`.

### [UID:0000UK] `DrawTextRunCallback_00593DB0`

Recommended metadata after insertion:

- `COMPLETION:91`
- `CONFIDENCE:91`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0001JR`
- `EMITTER_UIDS:0000ON`

Recommended formal C++:

```cpp
// Emitted code for this callback item is covered by [UID:0001JR].
```

### [UID:0000UM] `EncodeTextEditState_0058E490`

Recommended metadata after insertion:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0001JN`
- `EMITTER_UIDS:0000ON`

Recommended formal C++:

```cpp
// Canonical source for this serialization item is owned by [UID:0001JN].
```

Implementation note: use the formal "Emitted code is covered by" wording only if [UID:0001JN] is also accepted as an emitter in the same callback. If [UID:0001JN] remains blank, the item row should be a canonical-owner mirror rather than claiming a body has been emitted.

## Rows To Keep Blank In The Immediate Batch

The following rows should receive report-level notes and blocker details, but no formal C++ body in the immediate callback:

- [UID:0002ZY] constructor: real source body; 26 constructor callsites; blocked on complete field/member-table naming and base-constructor route.
- [UID:0002ZZ] destructor: real source body; clears [UID:0000Q7], deletes owned fields, unregisters manager; blocked on owned-field names and manager/table type.
- [UID:00030C] draw handler: real vtable-routed draw method; blocked on draw-state fields, selection/highlight branches, and rectangle-list helper spelling.
- [UID:00030F] key/input handler: real vtable-routed input method; blocked on event struct, key constants, clipboard helper names, and TextEditScrap method names.
- [UID:00030E] mouse handler: real vtable-routed input method; blocked on event struct, five-case switch names, hit-test helper names, and selection anchor semantics.
- [UID:00030D] invalidation helper: real helper; near first-draft but blocked on shared rectangle-list helper names.
- [UID:0001JN] serializer: real source body; duplicate by-item row should be suppressed; blocked on Encoder/local buffer spelling if a full body is requested.
- [UID:0001JM] core aggregate: real aggregate and split parent; do not insert no-code until child split is complete.
- [UID:0001JP] formatting aggregate: real source-bearing aggregate; keep split-before-body policy from executed B001 research.
- [UID:0001JS] navigation/wrap aggregate: real source-bearing aggregate; keep split-before-body policy from executed B001 research.

## By-File Update Requirements

Implementation callback should update `by-file/TextEditPane.md` with these report-level details:

- The current generated unit is validator-owned and was last refreshed by command `000000001482` at `2026-06-29T23:05:49-04:00`.
- Current generated inventory is 23 contributors, 3 filled, 20 empty.
- Direct MCP-backed resolution candidates are [UID:0002O9], [UID:0000EN], [UID:0000EP], [UID:0000Q7], [UID:000302], [UID:000301], [UID:000303], [UID:0000UK], and [UID:0000UM].
- [UID:00004H] should be described as support-row follow-up, not a direct first-draft body in this callback.
- Large real-body rows must remain blank with explicit blockers, not generic "pending source names" wording.
- The generated order/support note should state that the corrected `TextEditObject` and `TextEditScrap` declarations must be available before callback/source bodies that mention them. `TextEditObject` must use the accepted payload/object-type layout, not the rejected rectangle/bounds shape. If the generator requires `EMITTER_POSITION_OPTIONAL` or by-file ordering to achieve this, set it in the implementation callback rather than editing generated output manually.
- The file-level score can reasonably move from `90/88` to `91/90` after the accepted implementation batch, because the direct empty family has current MCP classification, zero-initializer correction, duplicate-item suppression, and a bounded first-draft body. Do not claim full closeout because most large source-bearing rows remain blank.

## Dependency-Owner And Support Exclusions

Do not edit unrelated support libraries in the immediate callback unless a direct stale cross-reference contradicts this report:

- Encoder helper docs: [UID:0001JN] depends on them, but this callback does not need Encoder-body edits.
- MemoryMan/string helper docs: [UID:0002O9] and input/serializer rows use them, but this callback only needs local call-shape documentation.
- Rectangle/list helper docs: [UID:00030C] and [UID:00030D] depend on them, but their names remain a blocker rather than an accepted edit.
- Clipboard API/support docs: [UID:00030F] and [UID:000301] depend on them, but only the local static declaration/initializer needs update.
- Executed B-agent research archives and supervisor ledgers: read-only only.
- Generated files, generated reports, manual coverage reports, validator state, IDA DB, MCP process state, and lock files: no edits.

## Score Rationale

The file-level score should stay high but not close out:

- Positive: current MCP database is available; direct function ranges and data slots are live; two callbacks are already first-draft emitted; the copy helper is narrow and formal-body-ready; static/global data initializers are confirmed; duplicate by-item ownership is clear.
- Negative: major source-bearing methods remain high-complexity and need exact event/list/helper/member names; broad aggregate rows are not yet split to a full child inventory; one support class still has unresolved embedded-frame details. The accepted report-time generated output had 20 empty markers; after the implementation callback's validator-owned deferred refresh, 11 intentional empty markers remain for the blank large/support follow-up rows.
- Recommended by-file score after accepted batch: `COMPLETION:91`, `CONFIDENCE:90`.
- Recommended generated-state note after accepted batch: "not a full closeout; direct empty-family first batch applied; large body/split rows remain follow-up."

## Evidence Checked

Read-only local files checked:

- `tools/leaser/Agents/Agent-B004/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
- `project-documentation/by-file/TextEditPane.md`
- `project-documentation/by-class/TextEditObject.md`
- `project-documentation/by-class/TextEditScrap.md`
- `project-documentation/by-class/EPFTextEditObject.md`
- `project-documentation/auto-generated/NexusTK/ui/controls/TextEditPane.cpp`
- `project-documentation/auto-generated/-ag-research-tracker.md`
- Relevant executed research report names under `project-documentation/executed-b-agent-research/`, including B005 [UID:0000EO], B007 [UID:0001JQ], B006 [UID:0001JR], B011 TextEdit support objects, B001 [UID:0001JP]/[UID:0001JS], and Encoder helper reports.
- Revision-pass support-class evidence: executed B011 `0003M7-TextEditSupportObjectsBeforeTextBoxPane-source-quality.md` for [UID:00040S] / [UID:00040T] support-object split and field/method families; executed B006 `0001JR-DrawTextRunCallback-source-quality.md` for the live inline-object virtual hook route; executed B007 `0001JQ-TextRunMeasureCallback-source-quality.md` for the `TextEditObject::m_payload1` measure-path use and the explicit payload-pair caveat.

Read-only search terms used:

- `0000ON`
- `TextEditPane`
- `TextEditPane.cpp`
- `TextRunMeasureCallback`
- `DrawTextRunCallback`
- `TextEditPaneSerialization`
- `TextEditPaneCoreBeforeTextBoxPane`
- `g_pActiveTextEditPane`
- direct address prefixes `0058dc`, `0058e3`, `005908`, `005909`, `00590d`, `005917`, `00591d`, `005940`, `0069bd`, and `0069be`

MCP evidence calls used:

- `initialize` / `tools/list`
- `idb_list`
- `server_health`
- `lookup_funcs`
- `xrefs_to`
- `xref_query`
- `get_int`
- `get_bytes`
- `callees`
- `decompile`
- `analyze_function`

## Implementation Callback Proof

Implementation callback `B004-implement-0000ON-TextEditPane-empty-emitter-family-20260629-r2` was applied on 2026-06-29/2026-06-30.

Changed by-* docs:

- `by-file/TextEditPane.md`
- `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md`
- `by-class/TextEditObject.md`
- `by-class/TextEditScrap.md`
- `by-class/EPFTextEditObject.md`
- `by-global/g_pActiveTextEditPane.md`
- `by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md`
- `by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md`
- `by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md`
- `by-item/DrawTextRunCallback_00593DB0.md`
- `by-item/EncodeTextEditState_0058E490.md`
- `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`
- `by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md`
- `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md`
- `by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md`
- `by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md`
- `by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md`
- `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`
- `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`
- `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md`
- `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`

Validator commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`.

| File | command_id | command_timestamp | exit | ok | generated_refresh |
| --- | --- | --- | --- | --- | --- |
| `by-class/TextEditObject.md` | `000000001630` | `2026-06-29T23:46:04-04:00` | `0` | `1` | `deferred` |
| `by-file/TextEditPane.md` | `000000001631` | `2026-06-29T23:46:32-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md` | `000000001632` | `2026-06-29T23:46:36-04:00` | `0` | `1` | `deferred` |
| `by-class/TextEditScrap.md` | `000000001633` | `2026-06-29T23:46:38-04:00` | `0` | `1` | `deferred` |
| `by-class/EPFTextEditObject.md` | `000000001634` | `2026-06-29T23:46:39-04:00` | `0` | `1` | `deferred` |
| `by-global/g_pActiveTextEditPane.md` | `000000001635` | `2026-06-29T23:46:41-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md` | `000000001636` | `2026-06-29T23:46:48-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md` | `000000001637` | `2026-06-29T23:46:50-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md` | `000000001638` | `2026-06-29T23:46:52-04:00` | `0` | `1` | `deferred` |
| `by-item/DrawTextRunCallback_00593DB0.md` | `000000001639` | `2026-06-29T23:46:54-04:00` | `0` | `1` | `deferred` |
| `by-item/EncodeTextEditState_0058E490.md` | `000000001640` | `2026-06-29T23:46:55-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md` | `000000001641` | `2026-06-29T23:46:57-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md` | `000000001642` | `2026-06-29T23:46:59-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md` | `000000001643` | `2026-06-29T23:47:06-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md` | `000000001644` | `2026-06-29T23:47:13-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md` | `000000001645` | `2026-06-29T23:47:15-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md` | `000000001646` | `2026-06-29T23:47:16-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` | `000000001647` | `2026-06-29T23:47:18-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md` | `000000001648` | `2026-06-29T23:47:28-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md` | `000000001649` | `2026-06-29T23:47:34-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` | `000000001650` | `2026-06-29T23:47:44-04:00` | `0` | `1` | `deferred` |

Generated freshness check:

- `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` was not manually edited.
- Header check after the deferred refresh queue settled: `validator-command-id: 000000001650`, `validator-refreshed-at: 2026-06-29T23:47:44-04:00`, `validator-refresh-source: deferred-generated-refresh`, `Source by-file UID: 0000ON`.
- Every scoped validator in this callback initially reported `generated_refresh: deferred`; the validator-owned deferred refresh later advanced the generated header through the scoped command sequence and settled on command `000000001650`.
- Final generated marker scan after the deferred refresh: 11 remaining `Empty Emitter Marker` rows, all intentional follow-up blanks: [UID:0002ZY], [UID:00004H], [UID:0001JM], [UID:0002ZZ], [UID:00030C], [UID:00030F], [UID:00030E], [UID:00030D], [UID:0001JN], [UID:0001JP], and [UID:0001JS].

Lease proof:

- B004 leased the 21 changed by-* docs immediately before editing.
- Release command after validators returned `Rejected[No active lease]` for every listed path because the short leases had already expired.
- `tools/leaser/Agents/current_leases.md` was checked after the release attempt; it contains no `B004` entries and no TextEditPane-family B004 leases.

## Claim And Incorporation Ledger

| Claim | Evidence | Implementation target | Verification state |
| --- | --- | --- | --- |
| MCP database `supervisor_resume_20260629` was available and suitable. | `idb_list` and `server_health` facts above. | Report evidence section and by-file evidence note. | Applied. Evidence incorporated into `by-file/TextEditPane.md`; validated by `000000001631`. |
| Generated TextEditPane unit has 23 contributors, 3 filled, 20 empty. | Header and marker scan of generated `TextEditPane.cpp`. | `by-file/TextEditPane.md` generated-state note. | Applied. Inventory and non-closeout note inserted; validated by `000000001631`. |
| [UID:0002O9] is first-draft-ready. | MCP decompile `0x0058e380`, seven callers, narrow copy/terminate logic. | `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md`. | Applied. Formal C++ inserted; validated by `000000001632`. |
| Stale [UID:0000EN] `RectBounds` declaration must be rejected. | Current `by-class/TextEditObject.md` documents `m_objectType`, `m_ownerHandle`, `m_payload0`, `m_payload1`, object-type/owner/payload-pair helpers, and provisional no-op virtual hooks; executed B011 [UID:00040S], B006, and B007 agree. | `by-class/TextEditObject.md`, `by-class/EPFTextEditObject.md`, and by-file support-order note. | Applied/reject-stale. Rejection notes added and stale block not inserted; validated by `000000001630`, `000000001631`, and `000000001634`. |
| [UID:0000EN] should emit a declaration container only if it uses the current payload/object-type layout. | Current support docs plus B011 [UID:00040S] support-object split; B006 inline-object dispatch and B007 measure-path payload use. | `by-class/TextEditObject.md` and by-file order note. | Applied. Correct declaration-container C++ inserted; validated by `000000001630`. |
| [UID:0000EP] should emit a declaration container only, using the current text/payload buffer layout. | Current `by-class/TextEditScrap.md`, executed B011 [UID:00040T], and B012/TextPad helper-contract evidence. | `by-class/TextEditScrap.md`. | Applied. Declaration-container C++ inserted and packed length-unit caveat preserved; validated by `000000001633`. |
| [UID:00004H] should not receive invented embedded-frame fields or broad formal class C++. | Current `by-class/EPFTextEditObject.md` documents constructor/helper/destructor ranges and `this+0x14` embedded frame storage, but exact frame type/name remains unresolved. | `by-class/EPFTextEditObject.md`. | Applied/excluded-with-reason. Support wording updated, formal C++ left blank; validated by `000000001634`. |
| [UID:0000Q7]/[UID:000302] are the active TextEditPane pointer. | MCP xrefs at constructor/destructor/external users and zero initializer. | `by-global/g_pActiveTextEditPane.md`; `by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md`. | Applied. Global declaration and storage covered-by comment inserted; validated by `000000001635` and `000000001636`. |
| [UID:000301] initializer is zero, not `0xffffffff`. | MCP `get_int`/`get_bytes`. | `by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md`. | Applied. Zero static declaration inserted and older `0xffffffff` sample marked superseded; validated by `000000001637`. |
| [UID:000303] initializer is zero, not `0xffff`. | MCP `get_int`/`get_bytes`; xrefs all inside OnMouseEvent. | `by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md`. | Applied. Zero static declaration inserted and older `0xffff` sample marked superseded; validated by `000000001638`. |
| [UID:0000UK] must not duplicate [UID:0001JR]. | MCP address-taking xrefs and existing generated [UID:0001JR] body. | `by-item/DrawTextRunCallback_00593DB0.md`. | Applied. Canonical owner set to [UID:0001JR] and covered-by comment inserted; validated by `000000001639`. |
| [UID:0000UM] is a duplicate item mirror for [UID:0001JN]. | MCP xref to `0x0058e490` and canonical memory page. | `by-item/EncodeTextEditState_0058E490.md`. | Applied. Canonical owner set to [UID:0001JN] and canonical-source comment inserted without claiming a completed body; validated by `000000001640`. |
| Draw/key/mouse/serialization/aggregate rows are real source-bearing rows, not no-code rows. | MCP function lookup, xrefs, callees, and analyze/decompile evidence. | Listed by-memory rows. | Applied. Detailed blockers/evidence added while formal C++ stayed blank; validated by `000000001641` through `000000001650`. |
| No support body edits are required outside direct TextEditPane-family docs. | Dependency-owner review and negative evidence. | Exclude Encoder/MemoryMan/rectangle-list/clipboard support body docs unless direct stale cross-reference exists. | Applied/excluded-with-reason. No unrelated support body docs were edited. |

## Implementation Tracking Checklist

- [x] Update `by-file/TextEditPane.md` with the current generated inventory, MCP evidence summary, direct first-batch disposition, score rationale, and support-order note. Proof: `by-file/TextEditPane.md`, `## B004 Empty-Emitter Callback Disposition`; validator `000000001631`, exit `0`, ok `1`.
- [x] Insert first-draft C++ into `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md`; set score/metadata to the recommended values or record exact validator rejection. Proof: formal `TextEditPane::CopyWideText` block inserted; validator `000000001632`, exit `0`, ok `1`.
- [x] Insert corrected declaration-container C++ into `by-class/TextEditObject.md` only if accepted. Proof: payload/object-type declaration inserted, stale `RectBounds` shape rejected in prose; validator `000000001630`, exit `0`, ok `1`.
- [x] Insert declaration-container C++ into `by-class/TextEditScrap.md` only if accepted. Proof: text/payload declaration inserted, method bodies kept on child rows, packed length-unit caveat preserved; validator `000000001633`, exit `0`, ok `1`.
- [x] Update `by-class/EPFTextEditObject.md` only with accepted stale/support wording; keep formal C++ blank. Proof: support wording updated, no class C++ inserted; validator `000000001634`, exit `0`, ok `1`.
- [x] Update `by-global/g_pActiveTextEditPane.md` with the active pane declaration and MCP xref/initializer evidence. Proof: declaration inserted, score `90/90`; validator `000000001635`, exit `0`, ok `1`.
- [x] Update `by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md` as covered by [UID:0000Q7] or as the accepted global storage declaration. Proof: covered-by comment inserted; validator `000000001636`, exit `0`, ok `1`.
- [x] Update `by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md` with zero-initialized static declaration and stale initializer correction. Proof: `static unsigned int s_styledUnicodeClipboardFormat = 0;`; validator `000000001637`, exit `0`, ok `1`.
- [x] Update `by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md` with zero-initialized static declaration and stale initializer correction. Proof: `static short s_mouseSelectionAnchor = 0;`; validator `000000001638`, exit `0`, ok `1`.
- [x] Update `by-item/DrawTextRunCallback_00593DB0.md` as covered by [UID:0001JR]. Proof: canonical owner [UID:0001JR] and covered-by comment; validator `000000001639`, exit `0`, ok `1`.
- [x] Update `by-item/EncodeTextEditState_0058E490.md` as canonical-owned by [UID:0001JN] and not a duplicate body emitter. Proof: canonical owner [UID:0001JN] and canonical-source comment; validator `000000001640`, exit `0`, ok `1`.
- [x] Update constructor/destructor/draw/key/mouse/invalidate/serialization/aggregate rows with detailed MCP evidence and explicit blockers while leaving formal C++ blank. Proof: rows updated and validators `000000001641` through `000000001650` all exited `0`, ok `1`.
- [x] Do not edit generated `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`; check freshness only through validator-owned refresh/header metadata after validators run. Proof: final header check reports `validator-command-id: 000000001650`, refreshed `2026-06-29T23:47:44-04:00`, `validator-refresh-source: deferred-generated-refresh`; final marker scan shows 11 intentional empty follow-up rows.
- [x] Run scoped validator commands for each changed by-* doc after implementation callback edits, with `--apply --queue-timeout 240`, and record command id/timestamp/exit/ok. Proof: validator table above.
- [x] Release all short leases immediately after the edit/validator batch during implementation callback. Proof: release attempt returned `Rejected[No active lease]` for all 21 paths because leases had expired; `current_leases.md` has no B004 entries.

## Implementation Callback Compliance

No generated C++ files were edited by hand.  
No generated reports, manual coverage reports, IDA database, MCP process state, executed archives, supervisor ledgers, or lock files were edited.  
Validator/tool state was touched only by the required validator `--apply` runs.  
No subagents were spawned.  
No accepted item remains unapplied; large source-bearing rows remain intentionally blank for follow-up body/split work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0000ON-TextEditPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000ON-TextEditPane-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T23:56:28","uid":"0000ON"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

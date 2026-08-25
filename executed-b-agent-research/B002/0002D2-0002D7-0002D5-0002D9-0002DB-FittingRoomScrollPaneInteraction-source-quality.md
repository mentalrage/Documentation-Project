** TARGET-REPORT-UID:0002D2 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: FittingRoomScrollPane Interaction Cluster

Assignment id: `B002-goal2-fittingroom-scrollpane-interaction-source-quality-0002D2-0002D7-0002D5-0002D9-0002DB-20260618`

Agent: `Agent-B002`

Primary targets:

| UID | Address range | Current target | Current score | Current route |
|---|---:|---|---:|---|
| [UID:0002D2] | `0x0041d870-0x0041da51` | `FittingRoomScrollPaneOnMouseEvent` | `84/88` | owner/emitter [UID:000054] `FittingRoomScrollPane` |
| [UID:0002D7] | `0x0041e4f0-0x0041e777` | `FittingRoomScrollPaneGetPartRect` | `84/88` | owner/emitter [UID:000054] `FittingRoomScrollPane` |
| [UID:0002D5] | `0x0041e8b0-0x0041e970` | `FittingRoomScrollPaneProcessActivePart` | `84/88` | owner/emitter [UID:000054] `FittingRoomScrollPane` |
| [UID:0002D9] | `0x0041e970-0x0041eb24` | `FittingRoomScrollPaneUpdateThumbDragScroll` | `84/88` | owner/emitter [UID:000054] `FittingRoomScrollPane` |
| [UID:0002DB] | `0x0041eb30-0x0041eb8c` | `FittingRoomScrollPaneResetScrollStateRaw` | `86/89` | owner/emitter [UID:000054] `FittingRoomScrollPane` |

Required output path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002D2-0002D7-0002D5-0002D9-0002DB-FittingRoomScrollPaneInteraction-source-quality.md`

## Final Recommendation

Keep all five targets as source-bearing exact children of [UID:000054] `FittingRoomScrollPane`, emitted through [UID:0000JE] `FittingRoom` to `NexusTK/cashshop/FittingRoom.cpp`. Do not split them into [UID:0000NF] `ScrollBar` / generic `ui/core` at this time. The local scrollbar logic clearly shares idioms with inventory/spell/volume scroll panes, but the direct construction path, vtable suffix, resource strings, and list-pane synchronization are FittingRoom-local.

Populate first-draft formal C++ for all five targets. The active code-entry gate is already satisfied for each target, and the current blank C++ state is stale. The raw no-function/no-direct-caller status of [UID:0002DB] remains important metadata, but it is no longer a sufficient reason to leave the C++ block blank because the body is complete, bounded by padding, source-shaped, and matches accepted ScrollInventory/ScrollSpell reset precedents.

Recommended score changes:

| UID | Current | Recommended | Reason |
|---|---:|---:|---|
| [UID:0002D2] | `84/88` | `88/90` | Inherited EventHandler receiver adjustment, event-kind behavior, capture/timer cleanup, hot/active/drag fields, and FittingRoom-local source placement are resolved to source-entry quality. |
| [UID:0002D7] | `84/88` | `88/90` | Part enum, table purpose, orientation split, cursor/origin helper roles, disabled/range behavior, and call graph are resolved. |
| [UID:0002D5] | `84/88` | `87/90` | Dispatcher/source split and active-vs-thumb behavior are resolved; exact original source name remains inferred. |
| [UID:0002D9] | `84/88` | `87/89` | Scroll-value synchronization, owner/list route, and split from dispatcher are resolved; precise original arithmetic helper naming remains inferred. |
| [UID:0002DB] | `86/89` | `88/90` | Raw helper boundary/no-direct-route evidence is now explicit; source-equivalent reset body and C++ readiness are resolved. |

Recommended support/doc changes:

| UID | Current | Recommended | Reason |
|---|---:|---:|---|
| [UID:000054] `FittingRoomScrollPane` | `85/89` | `88/90` | Field layout, scroll-part enum, reset/helper names, receiver adjustments, `dword_60DC78`, and FittingRoom-local source placement are sufficiently resolved for the interaction cluster. |
| [UID:0002DA] raw part-state helpers | `85/89` | no score change | Keep as support child; refresh stale coverage row from `80%` to `85%` and add source-facing names. |
| [UID:0000JE] `FittingRoom` | `85/87` | no score change | Add source-placement note, but do not raise file-level score from this narrow cluster alone. |
| [UID:0003AM] `FittingRoomReadOnlyData` | `87/91` | no score change | Add exact table/vtable note for `0x0060dc78`; score already reflects high confidence. |

## Evidence Checked

Read and applied active workflow documents:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `tools/leaser/Agents/Agent-B002/research/inference_research.md`
- `project-documentation/by-structure.md`
- `project-documentation/proposed-source-tree.md`

Target/support pages checked:

- [UID:0002D2] `by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md`
- [UID:0002D7] `by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md`
- [UID:0002D5] `by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md`
- [UID:0002D9] `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md`
- [UID:0002DB] `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md`
- [UID:000054] `by-class/FittingRoomScrollPane.md`
- [UID:000053] `by-class/FittingRoomListPane.md`
- [UID:0000JE] `by-file/FittingRoom.md`
- [UID:0000WR] `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
- [UID:0003AM] `by-memory/0x0060d9c0-0x0060e174.FittingRoomReadOnlyData.md`
- [UID:00024M] `by-memory/0x0060d000-0x0066c0bd.CashShopFittingRoomReadOnlyData.md`
- [UID:0002DA] `by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md`
- [UID:0002D8] `by-memory/0x0041df80-0x0041e4ef.FittingRoomScrollPaneHitTestPart.md`
- [UID:0002D6] `by-memory/0x0041dab0-0x0041df72.FittingRoomScrollPaneOnDraw.md`
- [UID:0002D4] `by-memory/0x0041da70-0x0041dab0.FittingRoomScrollPaneOnTimer.md`
- [UID:0002DF] `by-memory/0x0041f110-0x0041f317.FittingRoomListPaneUpdateScrollBar.md`
- [UID:0001K8] `by-memory/0x005975e0-0x00597610.TimerHandlerScheduleRemoveWrappers.md`
- [UID:00015S] `by-memory/0x004b7c30-0x004b7f0a.RectGeometryHelpers.md`
- [UID:0001VH] `by-memory/0x0054c800-0x0054d713.PaneLayout.md`
- Inventory/spell/volume scrollbar precedent pages including [UID:0001H1], [UID:0001GO], [UID:0001GM], [UID:0001GN], and their layout support.

Generated/status files checked:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- `project-documentation/project-level/-auto-completion-stats.md`
- `project-documentation/project-level/-unresolved.md`

IDA/export evidence checked:

- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.asm`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`

Live MCP check:

- Attempted local MCP tool discovery at `http://127.0.0.1:13337/mcp`.
- Result: connection failed (`Unable to connect to the remote server`).
- Impact: no live IDA database mutation or live typed decompiler query was used. This report relies on the existing IDA export, target docs, generated reports, and a fresh local PE byte/reference scan.

Fresh PE evidence:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Size: `2,679,296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Sections used:
  - `.text`: `0x00401000-0x0060c4ac`
  - `.rdata`: `0x0060d000-0x0066c0be`
  - `.data`: `0x0066d000-0x0069ce24`

Fresh direct-edge scan:

| Destination | Direct calls/edges found | Evidence |
|---|---:|---|
| `0x0041d870` | `0` | Vtable-only EventHandler mouse slot; one VA data pointer at `.rdata:0x0060dcd8`. |
| `0x0041e4f0` | `13` | Calls at `0x41d8e7`, `0x41d982`, `0x41d99a`, `0x41d9b9`, `0x41e106`, `0x41e7ac`, `0x41e7c8`, `0x41e821`, `0x41e839`, `0x41e858`, `0x41e94a`, `0x41e995`, `0x41eb66`. |
| `0x0041e8b0` | `3` | Calls at `0x41d9e3`, `0x41da88`, `0x41e882`. |
| `0x0041e970` | `2` | Calls at `0x41e90b`, `0x41e934`. |
| `0x0041eb30` | `0` | Raw helper has no direct call, no VA/RVA literal pointer, and no external branch into `0x41eb30-0x41eb8c`. |
| `0x0041eb90` | `1` | Positive control: constructor caller at `0x41c01a`. |
| `0x005975e0` | `163` | Generic timer schedule wrapper. |
| `0x00597600` | `45` | Generic timer remove wrapper. |

Fresh boundary/byte evidence:

- `0x0041d870`: normal function prologue.
- `0x0041da4e`: return for [UID:0002D2], followed by padding and adjacent false virtual/thunk material.
- `0x0041e4ed`: three `0xcc` bytes before [UID:0002D7] prologue at `0x0041e4f0`.
- `0x0041e8af`: one `0xcc` byte before [UID:0002D5] prologue at `0x0041e8b0`.
- `0x0041eb24`: twelve `0xcc` bytes before raw reset body.
- `0x0041eb30-0x0041eb8b`: complete raw reset helper body.
- `0x0041eb8c-0x0041eb8f`: four `0xcc` bytes before [UID:000053] constructor prologue at `0x0041eb90`.

Fresh `.rdata` evidence:

- `0x0060dc78`: bytes `26 00 00 00 26 00 00 00 26 00 00 00 50 08 64 00`.
- Therefore `dword_60DC78` is exactly three 32-bit entries `{0x26, 0x26, 0x26}`. The following dword `0x00640850` at `0x0060dc84` is an RTTI complete-object-locator pointer for the next vtable block, not a fourth table entry.
- Primary vtable area starts immediately after the RTTI pointer at `0x0060dc88`.
- Secondary/EventHandler vtable:
  - COL pointer at `0x0060dcd0`
  - vtable at `0x0060dcd4`
  - mouse handler slot `0x0060dcd8 -> 0x0041d870`
- Tertiary/TimerHandler vtable:
  - COL pointer at `0x0060dd00`
  - vtable at `0x0060dd04`
  - timer handler slot `0x0060dd08 -> 0x0041da70`
- Constructor stores to `0x0060dcd4` and `0x0060dd04` occur at `0x41d6f8`, `0x41ec4f`, `0x41d702`, and `0x41ec59`.

## Heuristic / Inference Reanalysis And Validation

### Ownership, emitter, and source placement

Best conclusion: the interaction cluster remains owned by [UID:000054] `FittingRoomScrollPane`, emitted through [UID:0000JE] `FittingRoom` to `NexusTK/cashshop/FittingRoom.cpp`.

Evidence supporting local FittingRoom placement:

- The scroll pane is constructed inline by [UID:000053] `FittingRoomListPane` constructor at `0x0041eb90`, which allocates `0x110` bytes, stores the child pane pointer at `FittingRoomListPane +0x11c`, initializes the child vtables, and wires it to the fitting-room list state.
- The scroll pane synchronizes with `FittingRoomListPane +0x108` and calls [UID:0002DF] `FittingRoomListPaneUpdateScrollBar`.
- The draw path [UID:0002D6] uses local resource-string material such as `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL`, all in the FittingRoom read-only-data suffix.
- The relevant vtable/data suffix sits in [UID:0003AM] `FittingRoomReadOnlyData`.
- `auto-generated/-ag-memory-coverage.md` already routes these rows through [UID:000054] and `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.

Rejected alternative: move these targets directly to [UID:0000NF] `ScrollBar` or generic `ui/core/ScrollBar.cpp`.

- Reason rejected: generic-looking scroll fields and timer/pane helpers are dependencies and reusable idioms, not proof that this class was compiled from the generic scroll source unit.
- No direct constructor/caller route was found outside FittingRoom.
- The table/vtable/resource cluster is colocated with FittingRoom read-only data, not a generic UI-core read-only-data cluster.
- Existing inventory/spell/volume scroll panes show homologous layouts, but this supports a shared pattern or copy of a base scrollbar design, not a direct source-owner move for this FittingRoom-specific child.

Rejected alternative: make [UID:0000JE] `FittingRoom` the direct canonical owner for these method targets.

- Reason rejected: these targets are class methods/helpers on the scroll pane and already have the correct class owner [UID:000054].
- [UID:0000JE] remains the file/source root and emitter parent, not the direct method owner.

### Inherited receiver adjustment

Best conclusion: [UID:0002D2] receives the EventHandler secondary-base pointer, logically `FittingRoomScrollPane +0xa0`. Source C++ should be written as an ordinary `FittingRoomScrollPane::OnMouseEvent(...)` method; the decompiler's `this - 0xa0` adjustment must not be preserved in source-facing names or formal C++.

Evidence:

- [UID:0002D2] is referenced only from the secondary vtable slot at `0x0060dcd8`.
- The constructor writes secondary vtable `0x0060dcd4` into the object at the EventHandler subobject offset.
- The function accesses logical scroll-pane fields by subtracting `0xa0` from the decompiler receiver.
- The same class has a tertiary TimerHandler view at `+0xa4`, used by [UID:0002D4] `OnTimer`, which calls [UID:0002D5] with `this - 0xa4`.

Rejected alternative: model this as a free function receiving an adjusted raw pointer.

- Reason rejected: the vtable route and constructor vtable writes prove normal multiple-inheritance dispatch.
- Source should name class fields relative to the complete object.

Impact:

- [UID:0002D2] score can rise because the most important apparent field-offset confusion is resolved.
- Formal C++ should use normal member access: `m_activePart`, `m_hotPart`, `m_repeatTimer`, and so on.

### Event kinds and event fields

Best source-facing event model:

| Binary field | Best source-facing role | Evidence |
|---|---|---|
| `event + 4 == 0` | mouse move / drag tick / hover motion event | In [UID:0002D2], handled only while an active part exists, then invalidates the pane. |
| `event + 4 == 1` | mouse down / press | Performs point-in-pane/range gates, hit-test, capture, active-part setup, timer scheduling, and initial processing. |
| `event + 4 == 3` | mouse up / cancel / release | Releases capture, removes timer, clears active/hot state, and invalidates. |
| `event + 8` | cursor x or first point coordinate | Used with point-in-rect and drag offset setup. |
| `event + 0xc` | cursor y or second point coordinate | Used with point-in-rect and drag offset setup. |

Rejected alternative: treat event kind `0` as an idle timer.

- Reason rejected: it is in the EventHandler mouse vtable method and uses event point fields. Timer behavior is isolated in [UID:0002D4].

Unresolved detail:

- The exact original `MouseEvent` enum names are not proven. Use descriptive project-local names in formal C++ (`kMouseMove`, `kMouseDown`, `kMouseUp`) until the global event enum is finalized.
- This does not block first-draft C++.

### Helper names and roles

Recommended source-facing helper names:

| Binary | Current unresolved/generated label | Recommended source-facing name | Evidence and notes |
|---|---|---|---|
| `0x004a9090` | `sub_4A9090` | `EventManager::GetCursorPosition` / `GetCursorPosition` | Called through `g_pEventMan` before local-point math in scrollpane helpers. |
| `0x005447c0` | `sub_5447C0` | `Pane::GetScreenOffset` / `GetScreenOrigin` | Returns pane screen-origin information; sentinel `(-1000,-1000)` means no valid pane/screen placement. |
| `0x005449d0` | `sub_5449D0` | `Pane::CaptureMouse` | Called on mouse-down after a valid scroll part is hit. |
| `0x005449f0` | `sub_5449F0` | `Pane::ReleaseMouseCapture` | Called on mouse-up/cancel; previous trace label `ClearActivePaneEntry_5449F0` is compatible with release-capture semantics. |
| `0x005975e0` | `sub_5975E0` | `TimerHandler::ScheduleTimer` | 163 references; [UID:0001K8] confirms generic schedule wrapper. FittingRoom uses delays `200` and `30` ms for initial/repeat scroll. |
| `0x00597600` | `sub_597600` | `TimerHandler::RemovePendingTimers` | 45 references; [UID:0001K8] confirms generic remove wrapper. Raw reset calls it on `this +0xa4`. |
| `0x004b7c30` | `sub_4B7C30` | `InitPointPair` / `SetPoint` | [UID:00015S] point initializer used for drag anchor setup. |
| `0x004b7c50` | `sub_4B7C50` | `InitRectBounds` / `SetRect` | [UID:00015S] rectangle initializer. |
| `0x004b7e80` | `sub_4B7E80` | `PointInRect` | [UID:00015S] half-open rectangle containment helper. |
| virtual slot `+0x20` | generated virtual call | `Pane::InvalidateRect` | Used throughout Pane-derived docs; [UID:0001VH] and target docs agree. |
| owner virtual slot `+0x1c` in [UID:0002D9] | generated virtual call | `GetOwnerListPane` / `GetOwnerPane` | Returns the owner/list-pane object used to update `+0x108`, child `+0x11c`, and [UID:0002DF]. Exact original method name unresolved but role is high-confidence. |

Rejected alternatives:

- Do not name `sub_5975E0` or `sub_597600` as FittingRoom-local functions; they are generic TimerHandler wrappers with broad xref counts.
- Do not name `sub_5449F0` as a destructor or reset helper; its call site and known trace label show active/capture clearing.
- Do not name `sub_5447C0` as a rectangle getter; it returns origin/offset point data and is paired with cursor-local conversion.

### Scroll-part enum

Best source-facing enum:

```cpp
enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};
```

Equivalent source names `kScrollPartUp`, `kScrollPartBeforeThumb`, `kScrollPartThumb`, `kScrollPartAfterThumb`, `kScrollPartDown`, and `kNoScrollPart` are acceptable if the supervisor chooses a generic shared-scrollbar naming scheme.

Evidence:

- [UID:0002D7] builds rectangles for part IDs `0..4`.
- [UID:0002D8] hit-tests the same five part IDs.
- [UID:0002D5] and [UID:0002DB] use `0xff` as the no-part sentinel for active/hot bytes.
- [UID:0002D6] draws parts using the same ID space.

Rejected alternatives:

- Reject treating IDs `1` and `3` as separate buttons. Their zero/nonzero track behavior and disabled/range gates match page-before/page-after track regions around the thumb.
- Reject treating `0xff` as a valid sixth draw part. It is exclusively a sentinel.

### Field layout and names

Recommended field names for [UID:000054] `FittingRoomScrollPane`:

| Offset | Type | Recommended source-facing name | Confidence | Evidence |
|---:|---|---|---:|---|
| `+0xa4` | embedded `TimerHandler` subobject/view | `m_repeatTimer` or `m_timerHandler` | high | Tertiary vtable at `0x0060dd04`; [UID:0002D4] timer callback; reset calls `RemovePendingTimers` on this address. |
| `+0xf8` | `int16_t` / small signed index | `m_scrollSkinIndex` | high | Indexes `dword_60DC78`; constructor initializes it; inventory/spell/volume analogs use it as scrollbar skin/extent selector. |
| `+0xfb` | `bool` / byte | `m_thumbDragActive` | high | Set/cleared by mouse handling and used by [UID:0002D7] to derive thumb rectangle from drag anchor/cursor state. |
| `+0xfc` | `uint8_t` / enum | `m_orientation` | high | Splits horizontal/non-horizontal rectangle and drag math. Docs agree: `0` = vertical, nonzero = horizontal. |
| `+0xfe` | `int16_t` | `m_scrollPosition` | high | Compared and synchronized to `FittingRoomListPane +0x108`; updated by [UID:0002D9]. |
| `+0x100` | `int16_t` | `m_scrollRange` / `m_maxScrollPosition` | high | Range gate for enabled scroll; used in drag conversion. |
| `+0x102` | `uint8_t` / bool | `m_scrollEnabled` | high | Gate for hit/drag behavior; [UID:0002DF] updates it. |
| `+0x103` | `int8_t` / enum byte | `m_hotPart` | high | Stores highlighted/hover part; invalidated and cleared by process/reset. Alias `m_highlightPart` is acceptable. |
| `+0x104` | `int8_t` / enum byte | `m_activePart` | high | Pressed/tracking part; `0xff` sentinel; drives timer repeat and reset. |
| `+0x108` | `Point` | `m_thumbDragOffset` | high | Set from cursor minus thumb origin on thumb press; consumed by [UID:0002D7]/[UID:0002D9]. |
| owner `+0x108` | `int16_t`/scroll integer | `FittingRoomListPane::m_scrollPosition` | high | [UID:0002D9] writes owner list scroll position. |
| owner `+0x11c` | `FittingRoomScrollPane *` | `FittingRoomListPane::m_scrollPane` | high | Constructor stores child pointer and [UID:0002D9] invalidates/synchronizes it. |

Rejected alternatives:

- Do not call `+0xf8` a pointer or pixel extent directly. It is an index into a three-entry extent table; the value loaded from the table is the extent.
- Do not call `+0x103` a persistent active part. It is cleared independently from `+0x104` and invalidates highlight/hot rectangles.
- Do not call `+0x104` a previous-part field. It is the live active/pressed part used by timer and mouse handling.
- Do not call `+0xfb` an inside-pane flag only. It directly affects thumb rectangle placement during drag and is best modeled as thumb-drag-active/drag-anchor-active state.

### `dword_60DC78` table

Best name: `kFittingRoomScrollPartExtentBySkin` or `s_scrollPartExtentBySkin`.

Recommended declaration:

```cpp
static const int kFittingRoomScrollPartExtentBySkin[3] = { 38, 38, 38 };
```

Evidence:

- Fresh PE bytes at `0x0060dc78` are exactly three 32-bit `0x26` entries followed by `0x00640850`.
- `0x00640850` is an RTTI/COL pointer for the adjacent vtable block, not table data.
- [UID:0002D6], [UID:0002D7], and [UID:0002D8] use the table when vertical scrollbar geometry needs a fixed extent.
- The table is indexed by `*(int16_t *)(this +0xf8)`.
- The horizontal path uses the pane's current height as the fixed extent instead of this table.

Rejected alternatives:

- Reject a four-entry table. The apparent fourth value belongs to RTTI.
- Reject naming it a color/palette/resource table. The values are small extents and are used in rectangle math, not resource lookup.
- Reject naming it a global generic scrollbar-size table unless future evidence finds references outside this FittingRoom scroll-pane cluster. Current direct refs are all local to the cluster.

### Active-part dispatcher vs thumb-drag updater split

Best conclusion: keep [UID:0002D5] and [UID:0002D9] as separate source-bearing methods.

[UID:0002D5] role:

- Fetch current cursor and pane-origin data.
- Convert to local pane point.
- If the active part is the thumb (`2`), call [UID:0002D9] directly.
- Otherwise hit-test the current local point; update only while the cursor is still over the active non-thumb part.
- Clear and invalidate stale hot/highlight state when appropriate.

[UID:0002D9] role:

- Convert a local cursor/drag position into a new scroll value.
- Compare with old `m_scrollPosition`.
- Write owner/list scroll position (`FittingRoomListPane +0x108`).
- Mirror the child scroll pane's current value at child `+0xfe`.
- Invalidate the child and owner panes.
- Call [UID:0002DF] `FittingRoomListPaneUpdateScrollBar`.

Rejected alternatives:

- Do not merge [UID:0002D5] and [UID:0002D9]. The binary has a clean function boundary, D5 has callers from mouse/timer/raw begin-part helper, and D9 has only two calls from D5.
- Do not move D9 to `FittingRoomListPane`; D9 is a `FittingRoomScrollPane` method that reaches the list pane through a virtual owner accessor. [UID:0002DF] is the list-pane method.

### Raw reset reachability

Best conclusion: [UID:0002DB] is a complete source-shaped raw reset helper with no proven surviving static caller. It should remain a source-bearing exact child of [UID:000054] with explicit no-direct-route metadata, and its formal C++ should be populated.

Evidence:

- IDA export does not create a function record for `0x0041eb30`.
- Fresh PE scan found no direct call to `0x0041eb30`, no VA/RVA literal pointer to it, and no external branch into `0x0041eb30-0x0041eb8c`.
- The body has a normal prologue/epilogue, stack cookie, and clean padding boundaries.
- Body behavior is coherent:
  - call `TimerHandler::RemovePendingTimers` on `this +0xa4`;
  - read old `m_hotPart` from `+0x103`;
  - clear `m_activePart` at `+0x104` to `0xff`;
  - if old hot part is valid, call [UID:0002D7] `GetPartRect` and virtual `Pane::InvalidateRect`;
  - clear `m_hotPart` to `0xff`.
- The same reset sequence appears inline in [UID:0002D2] mouse-up/cancel logic.
- ScrollInventory/ScrollSpell reset targets provide accepted precedent for populating first-draft C++ on raw no-function reset helpers after body and field roles are resolved.

Rejected alternatives:

- Do not create a direct caller in the docs without evidence. The inlined mouse-up sequence is not a direct machine-code call.
- Do not mark the helper as unreachable dead code without caveat. It may be an inlined/out-of-line source helper whose reference was optimized away or table-routed in a way not preserved by direct scans.
- Do not exclude C++ solely due to raw status. Raw status affects confidence ceiling and metadata, not code-entry readiness here.

Impact:

- [UID:0002DB] can move to `88/90`.
- The report should keep the no-direct-route warning and recommend formal C++ insertion.

### Generated output corruption / blank generated source

Observed state:

- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` is `0` bytes.
- `auto-generated/-ag-memory-coverage.md` marks the target rows as emitting through [UID:000054] to `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, but `C++` is `no`.

Best conclusion:

- This is not an owner/emitter routing failure.
- It is the expected result of blank formal C++ on the emitting targets/classes.
- Once first-draft C++ is populated for the scroll-pane interaction cluster and support declarations are added, the generator should have source content to emit in the FittingRoom file.

Rejected alternative:

- Do not move the targets just because the generated file is currently blank. The auto-generation route is already correct.

## First-Draft C++ Recommendation

Populate formal C++ for all five target pages. Use [UID:000054] `FittingRoomScrollPane` as the direct class owner, with support declarations in the same source route as `FittingRoom.cpp`.

The following is first-draft source-quality C++. It intentionally uses source-facing helper/type names. If the supervisor standardizes a generic scrollbar naming scheme later, replace the `FittingRoomScrollPart` prefix with the shared `ScrollBarPart` names without changing the behavior.

### Shared support declarations for the cluster

Placement recommendation: [UID:000054] class support page and/or [UID:0000JE] `FittingRoom.cpp` support prelude before the methods.

```cpp
static const int kFittingRoomScrollPartExtentBySkin[3] = { 38, 38, 38 };

enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};
```

Recommended field aliases for first draft:

```cpp
// FittingRoomScrollPane tail after Pane/EventHandler/TimerHandler base state.
// Names are source-facing aliases; exact original member spellings are not preserved in the binary.
int16_t m_scrollSkinIndex;       // +0xf8
bool m_thumbDragActive;          // +0xfb
uint8_t m_orientation;           // +0xfc, 0 = vertical, nonzero = horizontal
int16_t m_scrollPosition;        // +0xfe
int16_t m_scrollRange;           // +0x100
bool m_scrollEnabled;            // +0x102
int8_t m_hotPart;                // +0x103, FittingRoomScrollPart or -1
int8_t m_activePart;             // +0x104, FittingRoomScrollPart or -1
Point m_thumbDragOffset;         // +0x108
TimerHandler m_repeatTimer;      // +0xa4 tertiary TimerHandler view
```

### [UID:0002D2] `FittingRoomScrollPane::OnMouseEvent`

Recommended formal C++:

```cpp
bool FittingRoomScrollPane::OnMouseEvent(const PaneMouseEvent& event)
{
    bool handled = false;
    RectBounds partRect;

    switch (event.type) {
    case kPaneMouseMove:
        if (m_activePart != kFittingRoomScrollPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kPaneMouseDown:
        if (!PointInRect(event.x, event.y, &m_bounds)) {
            return false;
        }
        if (!m_scrollEnabled || m_scrollRange <= 0) {
            return false;
        }

        if (m_activePart == kFittingRoomScrollPartNone) {
            const FittingRoomScrollPart part =
                HitTestPart(event.x, event.y);

            if (part != kFittingRoomScrollPartNone) {
                CaptureMouse();

                if (part == kFittingRoomScrollPartThumb) {
                    if (m_hotPart != kFittingRoomScrollPartThumb) {
                        if (m_hotPart != kFittingRoomScrollPartNone) {
                            GetPartRect(static_cast<FittingRoomScrollPart>(m_hotPart), &partRect);
                            InvalidateRect(&partRect);
                        }

                        GetPartRect(kFittingRoomScrollPartThumb, &partRect);
                        InvalidateRect(&partRect);
                        m_hotPart = kFittingRoomScrollPartThumb;
                    }

                    GetPartRect(kFittingRoomScrollPartThumb, &partRect);
                    m_thumbDragOffset.x = event.x - partRect.left;
                    m_thumbDragOffset.y = event.y - partRect.top;
                }

                m_activePart = static_cast<int8_t>(part);
                ProcessActivePart();
                m_repeatTimer.ScheduleTimer(0, 200, 0, 0);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kPaneMouseUp:
        if (m_activePart != kFittingRoomScrollPartNone) {
            ReleaseMouseCapture();

            // Source-equivalent inline form of ResetScrollState(); the raw helper
            // exists separately at 0x0041eb30 but no surviving direct call edge was found.
            m_repeatTimer.RemovePendingTimers();
            const int8_t oldHotPart = m_hotPart;
            m_activePart = kFittingRoomScrollPartNone;
            if (oldHotPart != kFittingRoomScrollPartNone) {
                GetPartRect(static_cast<FittingRoomScrollPart>(oldHotPart), &partRect);
                InvalidateRect(&partRect);
                m_hotPart = kFittingRoomScrollPartNone;
            }

            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_bounds);
        break;

    default:
        break;
    }

    return handled;
}
```

Notes for supervisor:

- `kPaneMouseMove`, `kPaneMouseDown`, and `kPaneMouseUp` are source-facing placeholder enum names for event kinds `0`, `1`, and `3`.
- The decompiler receiver adjustment must not appear in this formal C++.
- If the global event type later names event `3` as cancel/release instead of mouse-up, change only the enum name.

### [UID:0002D7] `FittingRoomScrollPane::GetPartRect`

Recommended formal C++:

```cpp
void FittingRoomScrollPane::GetPartRect(FittingRoomScrollPart part, RectBounds* outRect)
{
    RectBounds bounds = m_bounds;
    *outRect = bounds;

    const bool horizontal = (m_orientation != 0);
    const int fixedExtent = horizontal
        ? bounds.Height()
        : kFittingRoomScrollPartExtentBySkin[m_scrollSkinIndex];

    if (m_scrollRange <= 0 || !m_scrollEnabled) {
        switch (part) {
        case kFittingRoomScrollPartLeading:
            if (horizontal) {
                outRect->right = outRect->left + fixedExtent;
            } else {
                outRect->bottom = outRect->top + fixedExtent;
            }
            return;

        case kFittingRoomScrollPartPageBeforeThumb:
        case kFittingRoomScrollPartPageAfterThumb:
            outRect->left = outRect->right = bounds.left;
            outRect->top = outRect->bottom = bounds.top;
            return;

        case kFittingRoomScrollPartThumb:
            if (horizontal) {
                outRect->left += fixedExtent;
                outRect->right -= fixedExtent;
            } else {
                outRect->top += fixedExtent;
                outRect->bottom -= fixedExtent;
            }
            return;

        case kFittingRoomScrollPartTrailing:
            if (horizontal) {
                outRect->left = outRect->right - fixedExtent;
            } else {
                outRect->top = outRect->bottom - fixedExtent;
            }
            return;

        default:
            return;
        }
    }

    const int trackStart = horizontal ? bounds.left + fixedExtent : bounds.top + fixedExtent;
    const int trackEnd = horizontal ? bounds.right - fixedExtent : bounds.bottom - fixedExtent;
    const int trackLength = trackEnd - trackStart;
    const int thumbExtent = fixedExtent;

    int thumbStart;
    if (m_thumbDragActive) {
        Point cursor;
        Point origin;
        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);
        cursor.x -= origin.x;
        cursor.y -= origin.y;

        const int cursorAxis = horizontal ? cursor.x : cursor.y;
        const int dragAxis = horizontal ? m_thumbDragOffset.x : m_thumbDragOffset.y;
        thumbStart = cursorAxis - dragAxis;
    } else {
        const int movable = trackLength - thumbExtent;
        thumbStart = trackStart;
        if (m_scrollRange > 0 && movable > 0) {
            thumbStart += (movable * m_scrollPosition) / m_scrollRange;
        }
    }

    if (thumbStart < trackStart) {
        thumbStart = trackStart;
    }
    if (thumbStart + thumbExtent > trackEnd) {
        thumbStart = trackEnd - thumbExtent;
    }

    switch (part) {
    case kFittingRoomScrollPartLeading:
        if (horizontal) {
            outRect->right = outRect->left + fixedExtent;
        } else {
            outRect->bottom = outRect->top + fixedExtent;
        }
        break;

    case kFittingRoomScrollPartPageBeforeThumb:
        if (horizontal) {
            outRect->left = trackStart;
            outRect->right = thumbStart;
        } else {
            outRect->top = trackStart;
            outRect->bottom = thumbStart;
        }
        break;

    case kFittingRoomScrollPartThumb:
        if (horizontal) {
            outRect->left = thumbStart;
            outRect->right = thumbStart + thumbExtent;
        } else {
            outRect->top = thumbStart;
            outRect->bottom = thumbStart + thumbExtent;
        }
        break;

    case kFittingRoomScrollPartPageAfterThumb:
        if (horizontal) {
            outRect->left = thumbStart + thumbExtent;
            outRect->right = trackEnd;
        } else {
            outRect->top = thumbStart + thumbExtent;
            outRect->bottom = trackEnd;
        }
        break;

    case kFittingRoomScrollPartTrailing:
        if (horizontal) {
            outRect->left = outRect->right - fixedExtent;
        } else {
            outRect->top = outRect->bottom - fixedExtent;
        }
        break;

    default:
        break;
    }
}
```

Notes for supervisor:

- This draft uses `RectBounds::Width/Height` and `left/top/right/bottom` source aliases. If the support docs preserve the binary field-order names instead, rewrite only the accessor spellings.
- The draft intentionally names `dword_60DC78` as a fixed vertical extent table indexed by `m_scrollSkinIndex`.

### [UID:0002D5] `FittingRoomScrollPane::ProcessActivePart`

Recommended formal C++:

```cpp
void FittingRoomScrollPane::ProcessActivePart()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.x == -1000 && origin.y == -1000) {
        return;
    }

    cursor.x -= origin.x;
    cursor.y -= origin.y;

    if (m_activePart == kFittingRoomScrollPartThumb) {
        UpdateThumbDragScroll(cursor.x, cursor.y);
        return;
    }

    const FittingRoomScrollPart hitPart = HitTestPart(cursor.x, cursor.y);
    if (hitPart == m_activePart) {
        UpdateThumbDragScroll(cursor.x, cursor.y);
    }

    if (m_hotPart != kFittingRoomScrollPartNone) {
        GetPartRect(static_cast<FittingRoomScrollPart>(m_hotPart), &rect);
        InvalidateRect(&rect);
        m_hotPart = kFittingRoomScrollPartNone;
    }
}
```

Notes for supervisor:

- Source-facing candidate names: `ProcessActivePart`, `UpdateActivePart`, or `RepeatActivePart`.
- `ProcessActivePart` is currently the clearest because the method handles both timer-repeat processing and active thumb drag processing.

### [UID:0002D9] `FittingRoomScrollPane::UpdateThumbDragScroll`

Recommended formal C++:

```cpp
void FittingRoomScrollPane::UpdateThumbDragScroll(int localX, int localY)
{
    const int oldPosition = m_scrollPosition;
    RectBounds thumbRect;
    GetPartRect(kFittingRoomScrollPartThumb, &thumbRect);

    const bool horizontal = (m_orientation != 0);
    const int fixedExtent = horizontal
        ? m_bounds.Height()
        : kFittingRoomScrollPartExtentBySkin[m_scrollSkinIndex];

    const int trackStart = horizontal ? m_bounds.left + fixedExtent : m_bounds.top + fixedExtent;
    const int trackEnd = horizontal ? m_bounds.right - fixedExtent : m_bounds.bottom - fixedExtent;
    const int thumbExtent = horizontal ? thumbRect.Width() : thumbRect.Height();
    const int movablePixels = (trackEnd - trackStart) - thumbExtent;

    int thumbStart = (horizontal ? localX : localY) -
        (horizontal ? m_thumbDragOffset.x : m_thumbDragOffset.y);

    if (thumbStart < trackStart) {
        thumbStart = trackStart;
    }
    if (thumbStart > trackStart + movablePixels) {
        thumbStart = trackStart + movablePixels;
    }

    int newPosition = 0;
    if (movablePixels > 0 && m_scrollRange > 0) {
        const int numerator = (thumbStart - trackStart) * m_scrollRange;
        newPosition = numerator / movablePixels;
    }

    if (newPosition < 0) {
        newPosition = 0;
    }
    if (newPosition > m_scrollRange) {
        newPosition = m_scrollRange;
    }

    if (newPosition == oldPosition) {
        return;
    }

    FittingRoomListPane* owner = GetOwnerListPane();
    owner->m_scrollPosition = static_cast<int16_t>(newPosition);

    FittingRoomScrollPane* scrollPane = owner->m_scrollPane;
    if (scrollPane != NULL) {
        scrollPane->m_scrollPosition = static_cast<int16_t>(newPosition);
        scrollPane->InvalidateRect(&scrollPane->m_bounds);
    }

    owner->UpdateScrollBar();
    owner->InvalidateRect(&owner->m_bounds);
}
```

Notes for supervisor:

- This is first-draft source C++ for code entry. The target docs should retain a note that the exact original arithmetic spellings and any axis helper names remain inferred.
- The binary source role is certain: compute new scroll position from thumb drag, mirror it to the owner/list state, call [UID:0002DF], and invalidate.
- The owner virtual at slot `+0x1c` should be represented as `GetOwnerListPane()` or the project-standard owner accessor name.
- If later decompilation cleanup proves the horizontal branch uses the opposite logical coordinate name because of local point field order, only the `localX/localY` axis selector names should change; the method role and placement remain valid.

### [UID:0002DB] `FittingRoomScrollPane::ResetScrollState`

Recommended formal C++:

```cpp
void FittingRoomScrollPane::ResetScrollState()
{
    RectBounds rect;

    m_repeatTimer.RemovePendingTimers();

    const int8_t oldHotPart = m_hotPart;
    m_activePart = kFittingRoomScrollPartNone;

    if (oldHotPart != kFittingRoomScrollPartNone) {
        GetPartRect(static_cast<FittingRoomScrollPart>(oldHotPart), &rect);
        InvalidateRect(&rect);
        m_hotPart = kFittingRoomScrollPartNone;
    }
}
```

Notes for supervisor:

- Suggested exact source-facing name: `ResetScrollState`.
- Acceptable alternatives: `CancelScrollTracking`, `StopScrollRepeat`, or `ResetActivePart`.
- The preferred name is `ResetScrollState` because it matches the already accepted ScrollInventory/ScrollSpell precedent and describes both timer removal and active/hot part cleanup.
- Keep the raw/no-direct-caller note in metadata and analysis even after adding this formal C++.

## Exact Supervisor Edits

These are supervisor-owned replacement recommendations only. Agent-B002 did not edit by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md`.

### Metadata replacements

Apply to [UID:0002D2] `by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md`:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Apply to [UID:0002D7] `by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md`:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Apply to [UID:0002D5] `by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md`:

```text
COMPLETION: 87
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Apply to [UID:0002D9] `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md`:

```text
COMPLETION: 87
CONFIDENCE: 89
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Apply to [UID:0002DB] `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md`:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Apply to [UID:000054] `by-class/FittingRoomScrollPane.md`:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000JE
EMITTER_UIDS: 0000JE
```

### Replace stale code-entry gate wording

Placement: in each of [UID:0002D2], [UID:0002D7], [UID:0002D5], [UID:0002D9], and [UID:0002DB], replace any wording that says formal C++ remains blank because the target has not met an old `95/95` or similar final/audit gate.

Replacement text:

```text
The active code-entry gate is satisfied by this target's combined score. Formal C++ should be populated as first-draft source under [UID:000054] FittingRoomScrollPane, emitted through [UID:0000JE] FittingRoom. Remaining limitations are tracked as confidence/metadata notes, not as a reason to keep the C++ block blank.
```

For [UID:0002DB], append:

```text
This target remains a raw no-function/no-direct-caller body. Fresh PE scanning found no direct call, no VA/RVA literal pointer, and no external branch into 0x0041eb30-0x0041eb8c. The raw status must remain documented, but the bounded reset body is source-shaped and eligible for first-draft C++.
```

### Insert support section in [UID:000054] `FittingRoomScrollPane`

Placement: after the class layout or field-layout section, before method inventory.

Insert:

```text
## Scroll Interaction Layout / Source Names

The FittingRoomScrollPane interaction methods are class-owned under this page and emitted through [UID:0000JE] FittingRoom to NexusTK/cashshop/FittingRoom.cpp. They should not be rerouted directly to generic ScrollBar/ui-core code unless future evidence finds a non-FittingRoom constructor or vtable route. Current evidence keeps the class local: the child scroll pane is allocated by FittingRoomListPane, the vtable/resource suffix is in FittingRoom read-only data, and drag changes synchronize FittingRoomListPane +0x108 through child pointer +0x11c.

The EventHandler mouse receiver is a secondary-base pointer at object +0xa0; source C++ should use an ordinary FittingRoomScrollPane::OnMouseEvent method and normal complete-object fields. The TimerHandler receiver is a tertiary-base pointer at object +0xa4; source C++ should use ordinary FittingRoomScrollPane timer/reset helpers.

Recommended source-facing scroll part enum:

enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};

Recommended field aliases:

| Offset | Type | Source-facing name | Evidence |
|---:|---|---|---|
| +0xa4 | TimerHandler view | m_repeatTimer / m_timerHandler | OnTimer and ResetScrollState call TimerHandler wrappers through this subobject. |
| +0xf8 | int16_t | m_scrollSkinIndex | Indexes kFittingRoomScrollPartExtentBySkin. |
| +0xfb | bool/byte | m_thumbDragActive | Enables drag-anchor thumb rectangle placement. |
| +0xfc | uint8_t | m_orientation | 0 = vertical, nonzero = horizontal. |
| +0xfe | int16_t | m_scrollPosition | Current scroll value mirrored with FittingRoomListPane +0x108. |
| +0x100 | int16_t | m_scrollRange / m_maxScrollPosition | Maximum/range gate for scrolling. |
| +0x102 | bool/byte | m_scrollEnabled | Enables/disables hit/drag behavior. |
| +0x103 | int8_t | m_hotPart / m_highlightPart | Highlighted part; invalidated and cleared separately from active part. |
| +0x104 | int8_t | m_activePart | Pressed/tracking part; 0xff means none. |
| +0x108 | Point | m_thumbDragOffset | Cursor offset within thumb during drag. |

Recommended helper aliases:

| Address/slot | Source-facing role |
|---|---|
| 0x004a9090 | EventManager::GetCursorPosition |
| 0x005447c0 | Pane::GetScreenOffset / GetScreenOrigin |
| 0x005449d0 | Pane::CaptureMouse |
| 0x005449f0 | Pane::ReleaseMouseCapture |
| 0x005975e0 | TimerHandler::ScheduleTimer |
| 0x00597600 | TimerHandler::RemovePendingTimers |
| 0x004b7c30 | InitPointPair / SetPoint |
| 0x004b7c50 | InitRectBounds / SetRect |
| 0x004b7e80 | PointInRect |
| virtual +0x20 | Pane::InvalidateRect |
```

### Insert read-only-data table note

Placement: in [UID:0003AM] `FittingRoomReadOnlyData`, under the `0x0060d9c0-0x0060e174` data/table inventory; also mirror in [UID:000054] if it already has a data dependency section.

Insert:

```text
| `0x0060dc78-0x0060dc84` | `kFittingRoomScrollPartExtentBySkin[3]` | Three 32-bit entries `{ 38, 38, 38 }`; vertical fixed scrollbar extent table indexed by `FittingRoomScrollPane::m_scrollSkinIndex` (`+0xf8`). The following dword at `0x0060dc84` is `0x00640850`, an RTTI complete-object-locator pointer for the adjacent FittingRoomScrollPane vtable block, not a fourth table entry. |
```

If [UID:0002D6], [UID:0002D7], or [UID:0002D8] currently describe `dword_60DC78` as unresolved, replace with:

```text
`dword_60DC78` is the FittingRoom scroll-part extent table, best source name `kFittingRoomScrollPartExtentBySkin`. It contains exactly three dwords `{38, 38, 38}` and is indexed by the scroll pane field at `+0xf8` (`m_scrollSkinIndex`). The apparent fourth dword is the RTTI COL pointer for the immediately following vtable block and must not be modeled as table data.
```

### Insert source-placement note in [UID:0000JE] `FittingRoom`

Placement: in the source-placement or class inventory section.

Insert:

```text
FittingRoomScrollPane interaction methods [UID:0002D2], [UID:0002D7], [UID:0002D5], [UID:0002D9], and [UID:0002DB] remain source-owned by [UID:000054] FittingRoomScrollPane and emitted through this FittingRoom source file. The class shares scrollbar idioms with inventory/spell/volume panes and generic Pane/Timer/EventHandler helpers, but current evidence does not justify direct reroute to generic ScrollBar/ui-core: the constructor path is FittingRoomListPane-local, the child scroll pane pointer lives at FittingRoomListPane +0x11c, list scroll state lives at +0x108, and the vtable/resource suffix is in FittingRoom read-only data.
```

### Update raw helper [UID:0002DA] support names

Placement: in [UID:0002DA] `FittingRoomScrollPaneRawPartStateHelpers`, near the function summaries.

Replacement/insert:

```text
Recommended source-facing names:

- `0x0041e780-0x0041e7f0`: `FittingRoomScrollPane::SetHotPart` or `SetHighlightPart`. The helper changes `+0x103` (`m_hotPart`), invalidates old/new part rectangles through GetPartRect and Pane::InvalidateRect, and uses `0xff` as the no-part sentinel.
- `0x0041e7f0-0x0041e8af`: `FittingRoomScrollPane::BeginPartPress` or `BeginPartInteraction`. The helper initializes active/pressed state, capture/timer behavior, and calls ProcessActivePart. It remains raw/no-function/no-outside-direct-route in the current IDA export.
```

## Coverage Row Recommendation

Supervisor-owned coverage row changes are needed in `by-memory/-coverage-report.md`. Agent-B002 did not edit the coverage report.

Placement: `MasterCodeTextSection`, inside the [UID:0000WR] `FittingRoomUiCore` child cluster. Replace only the listed rows; keep surrounding padding and unrelated rows unchanged.

Replace the [UID:0002D2] row with:

```text
| [0x0041d870, 0x0041da51) | 481 | 100.0% | 88% | 90% | [UID:0002D2] | FittingRoomScrollPaneOnMouseEvent | `by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md` |
```

Replace the [UID:0002D7] row with:

```text
| [0x0041e4f0, 0x0041e777) | 647 | 100.0% | 88% | 90% | [UID:0002D7] | FittingRoomScrollPaneGetPartRect | `by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md` |
```

Replace the [UID:0002DA] row with:

```text
| [0x0041e780, 0x0041e8af) | 303 | 100.0% | 85% | 89% | [UID:0002DA] | FittingRoomScrollPaneRawPartStateHelpers | `by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md` |
```

Replace the [UID:0002D5] row with:

```text
| [0x0041e8b0, 0x0041e970) | 192 | 100.0% | 87% | 90% | [UID:0002D5] | FittingRoomScrollPaneProcessActivePart | `by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md` |
```

Replace the [UID:0002D9] row with:

```text
| [0x0041e970, 0x0041eb24) | 436 | 100.0% | 87% | 89% | [UID:0002D9] | FittingRoomScrollPaneUpdateThumbDragScroll | `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md` |
```

Replace the [UID:0002DB] row with:

```text
| [0x0041eb30, 0x0041eb8c) | 92 | 100.0% | 88% | 90% | [UID:0002DB] | FittingRoomScrollPaneResetScrollStateRaw | `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md` |
```

If the class-level coverage report is regenerated from metadata, [UID:000054] should refresh to `88%/90%`. Do not manually edit generated `auto-generated/-ag-class-coverage.md`; it should be regenerated after supervisor metadata application.

## Validation And Remaining Limits

Validation performed:

- Confirmed all five target docs and relevant support docs were read.
- Confirmed `FittingRoom.cpp` generated output is currently blank because target formal C++ is blank, not because emitter route is absent.
- Confirmed [UID:0002D2] vtable-only status through `.rdata:0x0060dcd8`.
- Confirmed [UID:0002DB] raw no-function/no-direct-route status by both IDA export and fresh PE direct-reference scan.
- Confirmed [UID:0002D7] has 13 direct call sites and is shared by draw/mouse/helper/process/reset code.
- Confirmed [UID:0002D5] has 3 direct call sites from mouse/timer/raw begin-part helper.
- Confirmed [UID:0002D9] has 2 direct call sites from [UID:0002D5].
- Confirmed `dword_60DC78` is three dwords `{38,38,38}` and not a four-entry table.

Remaining limitations:

- Exact original spellings for `m_scrollSkinIndex`, `m_hotPart`, `m_activePart`, `m_thumbDragOffset`, and the scroll-part enum are not preserved in binary. The report provides high-probability source-facing names based on usage and sibling precedent.
- Exact original `MouseEvent` enum names are not proven. The numeric behavior is resolved; names should be harmonized with the global event docs when that enum is finalized.
- [UID:0002D9] arithmetic is source-ready at behavior level, but exact original helper spelling/axis-accessor spelling remains inferred. This is why [UID:0002D9] is recommended at `87/89`, not final/audit score.
- [UID:0002DB] remains raw/no-direct-caller. This limits final confidence but does not block first-draft C++.
- Live IDA MCP was unavailable, so no live database creation/rename/check was performed.

## Files Changed

Created this report only:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002D2-0002D7-0002D5-0002D9-0002DB-FittingRoomScrollPaneInteraction-source-quality.md
```

No by-* docs, generated reports, generated source, IDA database files, source files, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002D2-0002D7-0002D5-0002D9-0002DB-FittingRoomScrollPaneInteraction-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002D2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

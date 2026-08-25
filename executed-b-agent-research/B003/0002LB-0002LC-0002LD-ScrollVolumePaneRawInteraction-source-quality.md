** TARGET-REPORT-UID:0002LB **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002LB-0002LC-0002LD ScrollVolumePane Raw Interaction Source-Quality Research

Assignment: `B003-goal2-scrollvolume-raw-interaction-source-quality-0002LB-0002LC-0002LD-20260618`

Report date: 2026-06-18

Primary targets:

- [UID:0002LB] `by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md`
- [UID:0002LC] `by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md`
- [UID:0002LD] `by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md`

## Executive Recommendation

Keep all three targets attached to [UID:0001H2] `ScrollVolumePane` and emitted through the ScrollVolumePane source route. Do not move any of them to `TextEditPane`, `DrawScrollbarPartF`, `FittingRoomDialog`, `InterfaceEfx`, `TimerMgr`, or the following [UID:0001H6] `ScrollablePaneVirtualDefaults` island.

Recommended metadata changes:

| UID | Current score | Recommended score | Owner/emitter recommendation | C++ recommendation |
| --- | ---: | ---: | --- | --- |
| `0002LB` | `85/85` | `87/89` | keep `CANONICAL_OWNER:0001H2`, keep `EMITTER_UIDS:0001H2` | eligible after score update; first draft below |
| `0002LC` | `85/85` | `86/87` | keep `CANONICAL_OWNER:0001H2`, keep `EMITTER_UIDS:0001H2` | eligible after score update, but component names remain provisional; first draft below |
| `0002LD` | `85/85` | `87/89` | keep `CANONICAL_OWNER:0001H2`, keep `EMITTER_UIDS:0001H2` | eligible after score update; first draft below |

Current `85/85` rows do not pass the current code-entry gate recorded in `by-structure.md`, because the gate is `RECONSTRUCTABLE:TRUE`, nonblank valid `EMITTER_UIDS`, and average `(COMPLETION + CONFIDENCE) / 2 > 85`. The supervisor should only populate formal C++ if it accepts the score increases above. The first-draft C++ in this report is source-quality recommendation text, not a direct edit.

Do not create IDA functions or apply IDA names/prototypes for the raw starts as part of this report. The starts are source-shaped and bounded, but live/fresh static route evidence still shows no caller or pointer-table route to `0x00565170`, `0x005651e0`, or `0x00565490`.

## Evidence Checked

Read before work:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-B003/notes.md`

Documentation and generated-source evidence checked:

- Primary target pages for `0002LB`, `0002LC`, and `0002LD`.
- Parent/support pages: [UID:0001H2] `ScrollVolumePane`, [UID:00031M], [UID:00031N], [UID:00031O], [UID:0001H3], [UID:0001H4], [UID:0001H5], [UID:0001H6], [UID:0000CO] `ScrollVolumePane`, [UID:0000NK] `ScrollVolumePane` file, [UID:0001W2] `ScrollVolumePaneLayout`, and [UID:0001YT] `ScrollVolumePaneVtables`.
- Generic helper pages: [UID:00015S] `RectGeometryHelpers`, [UID:0001K8] `TimerHandlerScheduleRemoveWrappers`, [UID:0000SI] `g_pTimerMgr`, plus the Pane vtable page documenting `Pane::InvalidateRect` at primary vtable slot `+0x20`.
- Generated and source-map files:
  - `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp`
  - `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp.source_map.json`
  - `source-3/simroot_v2/class_TextEditPane.cpp`
  - `project-documentation/wave3_data_issues.md`
- Prior agent research:
  - B002 report for [UID:0001H6] ScrollablePane boundary correction.
  - B001 report for [UID:0001H5] `ScrollVolumePaneNotifyValueChange`.

IDA MCP status:

- Fresh live IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and failed with `MCP_ERROR: Unable to connect to the remote server`.
- This report therefore does not claim a new live IDA database mutation or new live IDA function state. It relies on existing IDA-backed pages plus fresh local PE byte and pattern scans.

Fresh local PE checked:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c4ac`
- `.rdata`: `0x0060d000-0x0066c0be`
- `.data`: `0x0066d000-0x0069ce24`

## Raw Boundary And Byte Facts

The local PE scan confirms the target boundaries and the surrounding child chain.

| Range | Boundary evidence |
| --- | --- |
| `0x00565170-0x005651e0` | Function-shaped prologue at `0x00565170`, cookie-protected body, `retn 4` at `0x005651dc-0x005651df`, then aligned next prologue at `0x005651e0`. |
| `0x005651e0-0x005652a0` | Function-shaped prologue at `0x005651e0`, cookie-protected body, `retn 0Ch` at `0x00565299-0x0056529c`, `0xcc` at `0x0056529f`, next modeled helper prologue at `0x005652a0`. |
| `0x00565490-0x005654ec` | Function-shaped prologue at `0x00565490`, plain `retn` at `0x005654eb`, then the first [UID:0001H6] ScrollablePane adjustor thunk starts exactly at `0x005654ec`. |

The boundary around [UID:0002LD] also validates B002's conclusion: `0x005654ec` and later code are not ScrollVolumePane raw interaction helpers. They are ScrollablePane virtual/default/destructor-related code.

## Direct Xref And Pointer-Route Recheck

The fresh PE scan searched the full file for absolute VA dwords and image RVA dwords for the raw starts and related helper starts. It also scanned `.text` for direct relative branch/call targets.

### Target raw starts

| Start | VA literal hits | RVA literal hits | Direct branch/call hits in `.text` | Result |
| --- | ---: | ---: | ---: | --- |
| `0x00565170` | `0` | `0` | `0` | no static caller or table route found |
| `0x005651e0` | `0` | `0` | `0` | no static caller or table route found |
| `0x00565490` | `0` | `0` | `0` | no static caller or table route found |

### Related sibling and modeled helpers

| Start | Direct branch/call hits | Notes |
| --- | ---: | --- |
| `0x005647c0` | `0` | [UID:00031M] raw sibling also has no direct route. |
| `0x005647f0` | `0` | [UID:00031N] raw sibling also has no direct route. |
| `0x005648f0` | `0` | [UID:00031O] raw sibling also has no direct route. |
| `0x00564e30` | `2` | Expected calls from `0x005649f1` and `0x0056530f`. |
| `0x00565010` | `13` | Expected `GetPartRect` fan-in from OnPaint/OnMouseEvent/raw helpers/Commit/Notify/Reset. |
| `0x005652a0` | `3` | Expected calls from `0x00564a83`, `0x00564b28`, and raw BeginInteraction call `0x00565272`. |
| `0x00565360` | `2` | Expected NotifyValueChange calls from CommitInteraction at `0x005652fb` and `0x00565324`. |
| `0x00540490` | `1` | Expected NewOptionPane callback call from NotifyValueChange. |
| `0x005975e0` | high fan-in | Generic `TimerHandler::ScheduleTimer` wrapper; raw BeginInteraction call at `0x00565288`. |
| `0x00597600` | high fan-in | Generic `TimerHandler::RemovePendingTimers` wrapper; raw Reset call at `0x005654a9`. |

Zero direct/pointer hits are not proof that a computed route is impossible. They do, however, reject a simple hidden vtable/table/direct-call route for the raw starts. The positive controls above show the scanner does find ordinary direct calls for the modeled helpers in the same cluster.

## Target Semantics

### [UID:0002LB] `0x00565170-0x005651e0` SetHighlightPartRaw

Binary ABI:

- `thiscall`
- one stack argument
- returns with `retn 4`

Observed behavior:

1. Reads the new part byte from `[ebp+8]`.
2. Reads old highlight byte from `this+0x103`.
3. If old and new parts match, returns without invalidation or store.
4. If old part is not `0xff`, calls `ScrollVolumePane::GetPartRect(oldPart, &rect)` at `0x00565010`, then invalidates that rectangle through Pane vtable slot `+0x20`.
5. If new part is not `0xff`, calls `ScrollVolumePane::GetPartRect(newPart, &rect)`, then invalidates that rectangle through Pane vtable slot `+0x20`.
6. Stores the new part to `this+0x103`.

Recommended source-facing name and signature:

```cpp
void ScrollVolumePane::SetHighlightPart(char part);
```

Reasoning:

- Current `class_ScrollVolumePane.cpp` and its source map already emit/name this as `SetHighlightPart` at `0x00565170`.
- The body is exactly a highlighted-part setter with old/new dirty-rect invalidation.
- The name is semantically better than generic `SetState`, `InvalidatePart`, or `SetPendingInvalidation`, because the same field is used by paint/commit/reset as the currently highlighted/hovered slider part.
- No source route other than ScrollVolumePane is plausible: the callee chain is ScrollVolumePane `GetPartRect`, Pane invalidation, and ScrollVolumePane layout fields.

Remaining limitation:

- The raw start still has no direct caller/table route. The method name is source-defensible, but IDA function creation is still not reachability-defensible.

### [UID:0002LC] `0x005651e0-0x005652a0` BeginInteractionRaw

Binary ABI:

- `thiscall`
- three stack arguments
- returns with `retn 0Ch`

Observed behavior:

1. Reads part byte from `[ebp+8]`.
2. If part is `2` (thumb), forces/highlights the thumb:
   - reads old highlight from `this+0x103`;
   - if old highlight is not already `2`, invalidates old highlighted part when old is not `0xff`;
   - invalidates the thumb rect;
   - stores `2` to `this+0x103`.
3. In the thumb path, calls `GetPartRect(2, &thumbRect)` and stores a mouse-to-thumb offset point at `this+0x108` through `0x004b7c30` / `InitPointPair`.
4. Stores the clicked/active part to `this+0x104`.
5. Calls `CommitInteraction` at `0x005652a0`.
6. Starts the timer/update handler through `this+0xa4` by calling `TimerHandler::ScheduleTimer` at `0x005975e0` with wrapper arguments `0, 0xc8, 0, 0`.
7. Returns with `retn 0Ch`.

Recommended source-facing name and signature:

```cpp
void ScrollVolumePane::BeginInteraction(char part, int mouseY, int mouseX);
```

The ABI-level certainty is `char part` plus two integer mouse coordinates. The order of the two coordinate names should remain documented as provisional. The best source-facing order is `mouseY, mouseX`, because this code and the shared `PointInRect_4B7E80` convention use vertical coordinate first in several call paths. The observed offset store is equivalent to:

```cpp
InitPointPair(&m_thumbDragOffset, mouseY - thumbRect.top, mouseX - thumbRect.left);
```

if `RectBounds` is interpreted as `left/top/right/bottom` and `InitPointPair` stores two raw integer fields in the engine's observed order. If a later coordinate audit standardizes all UI event helper names as `mouseX, mouseY`, then the code should keep the observed component order and only rename the formals.

Rejected source names:

- Reject `TextEditPane::DrawScrollbarPartF`. The stale flat generated file `source-3/simroot_v2/class_TextEditPane.cpp` emits this exact body at lines around `2179-2212`, but it is the wrong class and the wrong action. The body does not draw; it stores active interaction state, computes drag offset, commits a value update, and starts a timer.
- Reject `DrawScrollbarPartF` even as a ScrollVolumePane name. No drawing API is called, and the only invalidation is dirty-rect invalidation of old/new parts.
- Reject `FittingRoomDialog::ScheduleTimer` as the timer helper name. `0x005975e0` is the generic `TimerHandler::ScheduleTimer` wrapper with broad fan-in through `g_pTimerMgr`.

Remaining limitation:

- Unlike SetHighlightPart and ResetInteractionState, the current ScrollVolumePane source map does not emit a ScrollVolumePane entity at `0x005651e0`; the old flat TextEditPane output does emit it with stale owner/name. The behavior and surrounding owner are strong, but the exact original source name is still a high-probability descriptive name, not recovered-symbol evidence. This is why the recommended confidence is `87`, not `89`.

### [UID:0002LD] `0x00565490-0x005654ec` ResetInteractionStateRaw

Binary ABI:

- `thiscall`
- no stack arguments
- returns with plain `retn`

Observed behavior:

1. Calls `TimerHandler::RemovePendingTimers` at `0x00597600` with `ecx = this + 0xa4`.
2. Reads old highlight byte from `this+0x103`.
3. Stores `0xff` to active interaction part at `this+0x104`.
4. If old highlight is not `0xff`, calls `GetPartRect(oldPart, &rect)`, invalidates the rectangle through Pane vtable slot `+0x20`, and stores `0xff` to `this+0x103`.
5. If old highlight is already `0xff`, no highlight store is needed because the field is already clear.

Recommended source-facing name and signature:

```cpp
void ScrollVolumePane::ResetInteractionState();
```

Reasoning:

- Current `class_ScrollVolumePane.cpp` and its source map already emit/name this as `ResetInteractionState` at `0x00565490`.
- The body exactly cancels pending timer work, clears the active part, and invalidates/clears the previous highlight.
- The name is semantically better than `StopTimer`, `ClearHighlight`, or `OnLoseFocusHelper`, because the function touches both timer and interaction fields.

Remaining limitation:

- The raw start still has no direct caller/table route. The method name is source-defensible, but IDA function creation is still not reachability-defensible.

## Heuristic / Inference Reanalysis And Validation

### Evidence checked

- Target docs already recorded no IDA function/no raw-start caller status for `0x00565170`, `0x005651e0`, and `0x00565490`.
- Existing IDA-backed support pages confirmed outgoing calls from raw spans:
  - `0x00565170` calls `0x00565010` and Pane vtable `+0x20`.
  - `0x005651e0` calls `0x00565010`, `0x004b7c30`, `0x005652a0`, `0x005975e0`, and the security-cookie helper.
  - `0x00565490` calls `0x00597600`, `0x00565010`, and Pane vtable `+0x20`.
- Fresh local PE byte checks reconfirmed the exact prologues, return opcodes, padding, and next-function starts.
- Fresh local PE full-file dword searches found zero VA and zero RVA literal references to all three target raw starts.
- Fresh local PE `.text` direct branch/call scan found zero branch/call targets to all three target raw starts.
- Positive controls found expected direct calls to `GetPartRect`, `CommitInteraction`, `NotifyValueChange`, and `NewOptionPane::OnVolumeChanged`, so the direct-scan negative result is meaningful for ordinary branch routes.
- The current generated `class_ScrollVolumePane.cpp` names/emits `SetHighlightPart` and `ResetInteractionState`, and generated OnMouseEvent source text calls those high-level methods. This confirms source-model plausibility but is not binary caller proof.
- The same generated ScrollVolumePane source has begin-interaction behavior inline in OnMouseEvent rather than as a current ScrollVolumePane method at `0x005651e0`.
- The stale flat `class_TextEditPane.cpp` emits the `0x005651e0` body as `TextEditPane::DrawScrollbarPartF(char region, int mouseX, int mouseY)`, which proves an older generator recognized a method-shaped body but also demonstrates stale owner/name contamination.
- B002's report and local bytes confirm `0x005654ec` is the start of the following ScrollablePane virtual/default island, not part of ResetInteractionState.
- B001's NotifyValueChange research confirms the value-change side of the interaction chain and the `NewOptionPane::OnVolumeChanged` callback at `0x00540490`.

### Best guesses accepted

- `0x00565170` is best represented as `ScrollVolumePane::SetHighlightPart(char part)`.
- `0x005651e0` is best represented as `ScrollVolumePane::BeginInteraction(char part, int mouseY, int mouseX)` or equivalent coordinate names preserving the same argument order.
- `0x00565490` is best represented as `ScrollVolumePane::ResetInteractionState()`.
- `+0x103` is `m_highlightPart`, with `0xff` / `-1` as no-part sentinel.
- `+0x104` is `m_activePart` or `m_trackingPart`; `m_activePart` is the clearest source-facing field name because BeginInteraction writes the clicked part, CommitInteraction reads it, and Reset clears it.
- `+0x108` is an 8-byte point holding thumb drag mouse offset. Recommended source-facing field name is `m_thumbDragOffset`. The `+0x10c` dword is the second component of this point and should not be documented as an unrelated independent field unless the layout table uses a subfield note.
- `+0xa4` is the TimerHandler/update-handler secondary/tertiary subobject view used by scheduling/canceling callbacks. The source-level representation should call `ScheduleTimer`/`RemovePendingTimers` or equivalent wrapper methods, not expose pointer arithmetic as a normal data member unless the doc is describing ABI layout.
- `0x00565010` is `ScrollVolumePane::GetPartRect(char part, RectBounds* outRect)`.
- `0x005652a0` is `ScrollVolumePane::CommitInteraction()`.
- `0x00565360` is `ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)` or equivalent coordinate names; the binary return value is not consumed by known callers, so C++ caller sites can be written as a statement call.
- `0x005975e0` is `TimerHandler::ScheduleTimer(int eventId, int delay, int arg4, int arg5)` style wrapper. In this cluster it is called as schedule event `0` after `200` ms.
- `0x00597600` is `TimerHandler::RemovePendingTimers()` style wrapper.
- Pane vtable slot `+0x20` is `Pane::InvalidateRect`.
- `0x004b7c30` is `InitPointPair` / `SetPoint`; `0x004b7c50` is `InitRectBounds`; `0x004b7e80` is `PointInRect_4B7E80` with the documented vertical-first argument convention.

### Rejected alternatives

- Reject `TextEditPane` ownership for `0x005651e0`, `0x005652a0`, and `0x00565360`. The old generated file has stale labels, while the surrounding memory island, fields, vtables, constructor, `NewOptionPane` construction sites, and class/file docs all support ScrollVolumePane.
- Reject `DrawScrollbarPartF` for `0x005651e0`. The body starts interaction and timer behavior; it is not a draw helper.
- Reject any claim that `0x00565170`, `0x005651e0`, or `0x00565490` are currently proven live through direct static callers. Fresh PE evidence found no direct branch, VA literal, or RVA literal route to the raw starts.
- Reject moving `0x00565490-0x005654ec` into [UID:0001H6]. The byte boundary shows ResetInteractionState ends at `0x005654ec`, and the first ScrollablePane adjustor thunk begins there.
- Reject `InterfaceEfx::RemoveFromUpdateScheduler` as a source owner for `0x00597600`. The timer page proves `0x00597600` is generic `TimerHandler` removal wrapper.
- Reject `FittingRoomDialog::ScheduleTimer` as a source owner for `0x005975e0`. The timer page proves generic timer-handler ownership and broad fan-in.
- Reject treating `+0xa4` as an ordinary standalone ScrollVolumePane field named only for this widget. It is a secondary/tertiary base/subobject view installed by vtable setup and shared by TimerHandler dispatch conventions.
- Reject using the old generated `TextEditPane::DrawScrollbarPartF` parameter names as final coordinate names without qualification. The coordinate order remains an engine-convention issue; preserve observed component order and mark names provisional.

### Validation or contradiction of current docs

- Validates current target ownership and emitter routes through [UID:0001H2].
- Validates current target behavior summaries for fields `+0x103`, `+0x104`, `+0x108`, and `+0xa4`.
- Validates current no-function/no-caller caution, and strengthens it with fresh PE-wide literal/direct-branch negative evidence.
- Validates stale `TextEditPane` rejection and expands it to include the still-present old flat `0x005651e0` generated body.
- Validates B002's boundary correction at `0x005654ec`.
- Validates B001's `NotifyValueChange` source-quality update and confirms the coverage row is still stale.
- Contradicts the current target-page C++ blocker wording if it still refers to an old `95/95` final-source gate. The current active gate is average score greater than 85, not arbitrary 95/95.
- Contradicts the stale `82%` coverage rows for `0001H3`, `0002LB`, `0002LC`, `0001H5`, and `0002LD`; it also updates nearby stale `76%/78%` rows for `00031M/00031N/00031O` and stale aggregate `85%` for `0001H2`.

### Unresolved blockers

- Live IDA MCP was unavailable for this pass. Existing IDA-backed docs remain usable, but this report did not mutate or freshly query the IDA DB.
- No direct caller, vtable, function-pointer table, VA literal, or RVA literal route to the three raw starts was found. A computed call route with no embedded target literal cannot be absolutely excluded, but there is no evidence for it.
- `0x005651e0` has no current ScrollVolumePane source-map entity. The name `BeginInteraction` is behavior-defensible and target-consistent, but not recovered original-symbol proof.
- Coordinate component names for BeginInteraction and NotifyValueChange should stay provisional until a broader UI event coordinate naming pass standardizes whether source helpers are written `x,y` or vertical-first.
- IDA function creation is not recommended until supervisor policy allows creating raw helper functions despite no reachability evidence. Creating functions now would improve local decompilation but overstate the caller graph.

### Impact on score, owner, emitter, source placement, and C++

- Scores should rise because the main open questions have been rechecked with fresh PE evidence and source-name analysis. Scores should remain below 90 because raw start reachability is still not proven.
- Owners and emitters should not change. All three remain ScrollVolumePane-owned and ScrollVolumePane-emitted.
- Source placement should remain under `NexusTK/ui/controls/ScrollVolumePane.cpp` via [UID:0001H2]/[UID:0000CO]/[UID:0000NK].
- Formal C++ can be populated only if the supervisor accepts score increases that pass the current code-entry gate. If scores remain `85/85`, formal C++ should remain blank.
- If populated, `0002LC` C++ should include a coordinate-order note in the page text, not in generated source comments, because the source code itself should stay clean.

## Field Name Recommendations

Recommended layout/support-doc field names:

| Offset | Recommended source-facing name | Type/role | Evidence |
| --- | --- | --- | --- |
| `+0xa4` | `TimerHandler` subobject view, source call surface `ScheduleTimer`/`RemovePendingTimers` | tertiary/timer-handler view | `0x005651e0` calls `0x005975e0` with `ecx=this+0xa4`; `0x00565490` calls `0x00597600` with `ecx=this+0xa4`; vtable layout page records tertiary view. |
| `+0x103` | `m_highlightPart` | `char`, no-part sentinel `0xff` | SetHighlightPart compares/stores it; BeginInteraction forces thumb highlight; Reset invalidates and clears it; Commit clears it after hover mismatch; Paint uses it for visual state. |
| `+0x104` | `m_activePart` | `char`, no-part sentinel `0xff` | BeginInteraction stores clicked part; CommitInteraction branches on it; ResetInteractionState clears it. |
| `+0x108` | `m_thumbDragOffset` | 8-byte point | BeginInteraction writes a point through `InitPointPair`; NotifyValueChange consumes the point to convert thumb drag coordinates to a new value. |
| `+0x10c` | second component of `m_thumbDragOffset` | point subfield, not independent state | Existing docs mention `+0x10c` as drag offset. Keep it as a subfield note under the `+0x108` point to avoid implying a separate unrelated member. |

Recommended part constants:

```cpp
const char kScrollVolumePartFirstButton = 0;
const char kScrollVolumePartPageBeforeThumb = 1;
const char kScrollVolumePartThumb = 2;
const char kScrollVolumePartPageAfterThumb = 3;
const char kScrollVolumePartLastButton = 4;
const char kScrollVolumePartNone = -1;
```

The exact visual names for part `0`, `1`, `3`, and `4` depend on the coordinate orientation and art naming in `GetPartRect`/OnPaint. The stable constants for this report are `2 = thumb` and `-1/0xff = no part`. If the supervisor does not want provisional directional names, use neutral names `kScrollVolumePart0` through `kScrollVolumePart4` plus `kScrollVolumePartThumb`.

## Helper Name And Signature Recommendations

| Address | Recommended source-facing helper | Signature status | Notes |
| --- | --- | --- | --- |
| `0x00565170` | `ScrollVolumePane::SetHighlightPart` | `void (char part)` | Strong name/signature. Source-map and generated ScrollVolumePane output agree. |
| `0x005651e0` | `ScrollVolumePane::BeginInteraction` | `void (char part, int mouseY, int mouseX)` provisional coordinate names | Strong behavior, medium-high original-name confidence. Reject stale `DrawScrollbarPartF`. |
| `0x00565490` | `ScrollVolumePane::ResetInteractionState` | `void ()` | Strong name/signature. Source-map and generated ScrollVolumePane output agree. |
| `0x00565010` | `ScrollVolumePane::GetPartRect` | `void (char part, RectBounds* outRect)` | Strong behavior and caller usage. |
| `0x005652a0` | `ScrollVolumePane::CommitInteraction` | `void ()` source-facing | Binary return not meaningful at call sites; helper samples cursor/current point, localizes, hit-tests, and calls NotifyValueChange. |
| `0x00565360` | `ScrollVolumePane::NotifyValueChange` | source-facing `void/int (int mouseY, int mouseX)` provisional | Computes/clamps value and dispatches `NewOptionPane::OnVolumeChanged` if changed. Return is not consumed by known callers. |
| `0x005975e0` | `TimerHandler::ScheduleTimer` | `int (int eventId, int delay, int arg4, int arg5)` wrapper | Generic wrapper through `g_pTimerMgr` to `0x00597910`. In this cluster called as `ScheduleTimer(0, 200, 0, 0)`. |
| `0x00597600` | `TimerHandler::RemovePendingTimers` | `int ()` wrapper | Generic wrapper through `g_pTimerMgr` to `0x00597a10`. |
| `0x004b7c30` | `InitPointPair` / `SetPoint` | `void (int* outPoint, int first, int second)` | Use source-facing `SetPoint` only if consistent with RectBounds source headers. |
| `0x004b7c50` | `InitRectBounds` | `void (RectBounds* out, int left, int top, int right, int bottom)` | Shared geometry helper. |
| `0x004b7e80` | `PointInRect_4B7E80` | `bool (int y, int x, RectBounds* rect)` | Half-open point containment helper. |
| Pane vtable `+0x20` | `Pane::InvalidateRect` | `void (RectBounds* rect)` | Dword `0x00621a08 -> 0x00544800` documented in Pane vtable support. |

## Related Children Reanalysis

| UID | Status after this pass |
| --- | --- |
| `00031M` | Keep as ScrollVolumePane raw sibling. Current page already `85/88`; stale coverage row still says `76%`. It writes `+0xf8` low state word and invalidates bounds. Fresh PE route pattern remains no direct caller/pointer route. |
| `00031N` | Keep as ScrollVolumePane raw sibling. Current page already `85/88`; stale coverage row still says `76%`. It writes `+0xfa` state byte and invalidates bounds. Fresh PE route pattern remains no direct caller/pointer route. |
| `00031O` | Keep as ScrollVolumePane raw sibling. Current page already `85/88`; stale coverage row still says `78%`. It reads `+0x102` enabled and `+0x100` positive range. Fresh PE route pattern remains no direct caller/pointer route. |
| `0001H3` | Keep as modeled ScrollVolumePane hit-test helper. Coverage row still says `82%` but page is `85/86`. It calls `GetPartRect`, `InitRectBounds`, `PointInRect`, cursor/origin helpers, and returns part ids `0..4` or `0xff`. |
| `0001H4` | Keep as modeled ScrollVolumePane commit helper. Coverage row already says `85%` and the direct calls are expected. The row should be kept but can be wording-refreshed to remove obsolete final-source blocker phrasing. |
| `0001H5` | Keep as modeled ScrollVolumePane value-change helper. Page is `85/86`; coverage row still says `82%` and still includes an old MCP timeout caveat. B001 already supplied a support refresh; this report confirms it remains needed. |
| `0001H2` | Keep aggregate owner/emitter. Page is now `86/89`; coverage row still says `85%`. Add the fresh PE raw-helper route recheck and stale `0x005651e0` TextEdit rejection. |

## First-Draft C++ Recommendation

These drafts are recommended for formal population only after the supervisor accepts the metadata score increases above. They intentionally use source-facing helper names and layout field names, not IDA temporaries.

Assumed support declarations:

```cpp
struct RectBounds {
    int left;
    int top;
    int right;
    int bottom;
};

struct PointPair {
    int first;
    int second;
};

static const char kScrollVolumePartThumb = 2;
static const char kScrollVolumePartNone = -1;
```

The names `PointPair::first/second` avoid pretending the coordinate axis names are finalized. If the support headers already define a point type with `x/y` or `y/x`, use that established type instead.

### [UID:0002LB] SetHighlightPart

```cpp
void ScrollVolumePane::SetHighlightPart(char part)
{
    RectBounds rect;
    char oldPart = m_highlightPart;

    if (oldPart == part)
        return;

    if (oldPart != kScrollVolumePartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollVolumePartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = part;
}
```

Population note: this is a high-confidence source body. It matches the binary's old/new invalidation order and `retn 4` signature.

### [UID:0002LC] BeginInteraction

```cpp
void ScrollVolumePane::BeginInteraction(char part, int mouseY, int mouseX)
{
    RectBounds rect;

    if (part == kScrollVolumePartThumb) {
        if (m_highlightPart != kScrollVolumePartThumb) {
            if (m_highlightPart != kScrollVolumePartNone) {
                GetPartRect(m_highlightPart, &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollVolumePartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart = kScrollVolumePartThumb;
        }

        GetPartRect(kScrollVolumePartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }

    m_activePart = part;
    CommitInteraction();
    ScheduleTimer(0, 200, 0, 0);
}
```

Population note: the method body is source-quality, but the coordinate names are provisional. The binary certainty is that the first integer coordinate subtracts the rectangle's second stored edge and the second integer coordinate subtracts the rectangle's first stored edge before writing `this+0x108`. If the project standardizes public source names as `mouseX, mouseY`, preserve this observed component order when renaming.

### [UID:0002LD] ResetInteractionState

```cpp
void ScrollVolumePane::ResetInteractionState()
{
    RectBounds rect;
    char oldPart;

    RemovePendingTimers();

    oldPart = m_highlightPart;
    m_activePart = kScrollVolumePartNone;

    if (oldPart != kScrollVolumePartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = kScrollVolumePartNone;
    }
}
```

Population note: this mirrors the binary's conditional highlight clear. If `m_highlightPart` is already `-1`, the binary does not need to store it again.

## Target-Doc Replacement Text For Supervisor Application

### [UID:0002LB] metadata and source-quality paragraph

Placement: top metadata block of `by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md`.

Replace:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: in the target page's source-quality/evidence notes, add or replace the final source-quality blocker paragraph with:

```text
- 2026-06-18 B003 source-quality reanalysis keeps this as `ScrollVolumePane::SetHighlightPart(char part)`: current ScrollVolumePane generated source/source_map names `0x00565170` as `SetHighlightPart`, the body only compares `+0x103`, invalidates old/new part rectangles through `GetPartRect` and Pane vtable slot `+0x20`, and stores the new highlight byte. Fresh local PE scanning found zero absolute-VA literals, zero RVA literals, and zero direct branch/call targets to `0x00565170`, so IDA function creation and live-caller claims remain blocked; the source name/signature and first-draft C++ are nevertheless defensible after the score update.
```

### [UID:0002LC] metadata and source-quality paragraph

Placement: top metadata block of `by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md`.

Replace:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: in the target page's source-quality/evidence notes, add or replace the final source-quality blocker paragraph with:

```text
- 2026-06-18 B003 source-quality reanalysis keeps this as a ScrollVolumePane begin-interaction helper with binary ABI `thiscall(char part, int coord0, int coord1)`: part `2` forces the thumb highlight in `+0x103`, stores the thumb drag point at `+0x108` through `InitPointPair`/`0x004b7c30`, writes the active part to `+0x104`, calls `CommitInteraction` at `0x005652a0`, and schedules the `+0xa4` TimerHandler view through `TimerHandler::ScheduleTimer(0, 200, 0, 0)`. Fresh local PE scanning found zero absolute-VA literals, zero RVA literals, and zero direct branch/call targets to `0x005651e0`; the old flat `class_TextEditPane.cpp` label `TextEditPane::DrawScrollbarPartF(char region, int mouseX, int mouseY)` is rejected because the body performs state/timer interaction setup, not drawing, and because the owner is the surrounding ScrollVolumePane cluster. Use `BeginInteraction` as the source-facing descriptive name, with coordinate names provisional until the UI coordinate convention pass is complete.
```

### [UID:0002LD] metadata and source-quality paragraph

Placement: top metadata block of `by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md`.

Replace:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: in the target page's source-quality/evidence notes, add or replace the final source-quality blocker paragraph with:

```text
- 2026-06-18 B003 source-quality reanalysis keeps this as `ScrollVolumePane::ResetInteractionState()`: current ScrollVolumePane generated source/source_map names `0x00565490` as `ResetInteractionState`, the body removes pending timer entries through the `+0xa4` TimerHandler view, clears active part `+0x104` to `0xff`, invalidates the old highlighted part from `+0x103` when present, and clears `+0x103`. Fresh local PE scanning found zero absolute-VA literals, zero RVA literals, and zero direct branch/call targets to `0x00565490`, so IDA function creation and live-caller claims remain blocked; the source name/signature and first-draft C++ are nevertheless defensible after the score update. The function ends at plain `retn` `0x005654eb`; `0x005654ec` starts the ScrollablePane adjustor-thunk/default island and must remain outside this target.
```

## Support-Doc Replacement Text For Supervisor Application

### `ScrollVolumePaneLayout` field rows

Placement: in `by-type/by-struct/ScrollVolumePaneLayout.md`, replace the rows for `+0xa4`, `+0x103`, `+0x104`, `+0x108`, and `+0x10c` in the layout table, or add the text below immediately after the existing rows if the supervisor wants to preserve older wording.

```text
| `+0xa4` | tertiary TimerHandler/update-handler subobject view | Used by raw begin/reset interaction helpers as `ecx=this+0xa4` for `TimerHandler::ScheduleTimer(0, 200, 0, 0)` at `0x005975e0` and `TimerHandler::RemovePendingTimers()` at `0x00597600`; do not treat as a standalone widget-local data field. |
| `+0x103` | `char m_highlightPart` | Highlighted/hovered slider part, with `0xff`/`-1` as no-part sentinel; set by `SetHighlightPart`, forced to thumb by begin-interaction, invalidated/cleared by commit/reset, and used by painting. |
| `+0x104` | `char m_activePart` | Active interaction/tracking part, with `0xff`/`-1` as no-part sentinel; written by begin-interaction, read by commit, and cleared by reset. |
| `+0x108` | `PointPair m_thumbDragOffset` | Eight-byte point/offset written by `InitPointPair` during thumb begin-interaction and consumed by NotifyValueChange while converting mouse position to volume value. |
| `+0x10c` | second component of `m_thumbDragOffset` | Document as the `+4` component of the `+0x108` point, not an unrelated independent field; current value math uses this component as the vertical drag offset. |
```

### `wave3_data_issues.md` stale generated TextEdit label

Placement: under the existing ScrollVolumePane stale TextEditPane generated-signature issue, in the `Observed` list.

```text
- The old flat generated file `source-3/simroot_v2/class_TextEditPane.cpp` still emits `0x005651e0` as `TextEditPane::DrawScrollbarPartF(char region, int mouseX, int mouseY)`, but the body is the ScrollVolumePane begin-interaction helper: it updates highlight byte `+0x103`, writes active part `+0x104`, stores the thumb drag point at `+0x108`, calls `CommitInteraction`, and schedules the `+0xa4` TimerHandler view.
```

Placement: under the same issue, in the `Expected` or resolution list.

```text
- Route `0x005651e0` as a ScrollVolumePane raw begin-interaction helper or leave it as a documented stale generated artifact; do not use `TextEditPane::DrawScrollbarPartF` as ownership, source-name, or source-signature evidence.
```

### `ScrollVolumePane` aggregate support note

Placement: in `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`, under the raw-helper/source-quality evidence notes.

```text
- 2026-06-18 B003 raw-interaction source-quality pass rechecked the no-caller/no-table status for raw helpers `0x00565170`, `0x005651e0`, and `0x00565490`: fresh local PE scanning found zero absolute-VA literals, zero RVA literals, and zero direct branch/call targets to each raw start, while positive controls found expected direct calls to `GetPartRect`, `CommitInteraction`, `NotifyValueChange`, and `NewOptionPane::OnVolumeChanged`. Keep the raw helpers source-attached to ScrollVolumePane, but do not claim live direct callers or create IDA functions solely from source-shaped bodies.
```

### Coverage report ScrollVolumePane block

Placement: in `by-memory/-coverage-report.md`, under `MasterCodeTextSection`, replace the existing ScrollVolumePane block from the line beginning `[UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane]` through the line for `[UID:0002LD]`, immediately before the `[UID:0001H6]` line.

```text
    - [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md) 0x00564710-0x005654ec | class aggregate | ScrollVolumePane : reconstructable : 86% : strong : Attached to [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md); IDA-backed docs and B003 PE recheck confirm allocation, constructor stores, vtables, helper chain, raw helper splits including 0x005647c0/0x005647f0/0x005648f0/0x00565170/0x005651e0/0x00565490, modeled hit-test/rect/commit/value helpers, NewOptionPane callback path, excluded ScrollablePane destructor/default tail at 0x005654ec, and no direct branch or VA/RVA pointer route to the raw interaction starts.
        - [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md) 0x005647c0-0x005647e7 | raw method-shaped helper | ScrollVolumePaneSetLowStateWordRaw : reconstructable : 85% : strong : Raw ScrollVolumePane helper writes low state word `+0xf8` and invalidates bounds when changed; page now records exact field/call behavior, parent attachment, raw no-function/no-xref status, and no direct PE route to the raw start.
        - [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md) 0x005647f0-0x00564814 | raw method-shaped helper | ScrollVolumePaneSetStateByteRaw : reconstructable : 85% : strong : Raw ScrollVolumePane helper writes state byte `+0xfa` and invalidates bounds when changed; page now records exact field/call behavior, parent attachment, raw no-function/no-xref status, and no direct PE route to the raw start.
        - [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) 0x005648f0-0x0056490a | raw method-shaped helper | ScrollVolumePaneCanAdjustRaw : reconstructable : 85% : strong : Raw ScrollVolumePane predicate returns enabled-and-positive-range state from `+0x102` and `+0x100`; page now records exact predicate behavior, parent attachment, raw no-function/no-xref status, and no direct PE route to the raw start.
        - [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) 0x00564e30-0x00565006 | method | ScrollVolumePaneHitTestPart : reconstructable : 85% : strong : ScrollVolumePane hit-test helper returns part ids `0..4` or `0xff`, calls cursor/origin helpers, `GetPartRect`, `InitRectBounds`, and `PointInRect`, rejects stale TextEditPane generated signatures, and remains attached to [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md).
        - [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md) 0x00565170-0x005651e0 | raw method-shaped helper | ScrollVolumePaneSetHighlightPartRaw : reconstructable : 87% : strong : B003 source-quality pass confirms source-facing `ScrollVolumePane::SetHighlightPart(char)`, old/new highlight invalidation through `GetPartRect` and Pane vtable `+0x20`, field `+0x103 = m_highlightPart`, exact raw boundary before BeginInteraction, current ScrollVolumePane generated/source-map name support, zero VA/RVA literals and zero direct branch/call targets to the raw start, and first-draft C++ readiness after the score update.
        - [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md) 0x005651e0-0x005652a0 | raw method-shaped helper | ScrollVolumePaneBeginInteractionRaw : reconstructable : 86% : strong : B003 source-quality pass confirms source-facing ScrollVolumePane begin-interaction behavior, thumb highlight setup, `+0x108` thumb drag offset point write, `+0x104 = m_activePart`, commit call, `+0xa4` TimerHandler schedule call with interval `0xc8`, rejection of stale `TextEditPane::DrawScrollbarPartF`, zero VA/RVA literals and zero direct branch/call targets to the raw start, and first-draft C++ readiness with provisional coordinate names after the score update.
        - [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) 0x005652a0-0x00565360 | method | ScrollVolumePaneCommitInteraction : reconstructable : 85% : very strong : C001 direct IDA refresh confirms exact `sub_5652A0` `0xc0` boundary, modeled mouse/focus callers `0x00564a83`/`0x00564b28`, raw begin-interaction call `0x00565272`, cursor read through `dword_67A754`/`0x004a9090`, pane-origin local-coordinate conversion through `0x005447c0`, `-1000/-1000` sentinel handling, active part `+0x104`, highlight clear `+0x103`, notify calls `0x005652fb`/`0x00565324`, hit-test/rectangle helpers, zero VA/RVA pointer hits, retained [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md) owner/emitter position `130`, rejected stale `TextEditPane::HandleScrollbarMouseF` signature, and formal C++ blank pending final helper/member naming.
        - [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) 0x00565360-0x00565488 | method | ScrollVolumePaneNotifyValueChange : reconstructable : 85% : strong : B001/B003 source-quality passes confirm ScrollVolumePane value-change helper behavior, exact boundary before ResetInteractionState padding, thumb/value math through `GetPartRect`, cursor/origin and drag-offset fields, range clamp using `+0x100`, old/current value `+0xfe`, volume type `+0xfc`, callback dispatch to `NewOptionPane::OnVolumeChanged` at `0x00540490` only when the value changes, parent attachment, stale TextEditPane generated-signature rejection, and formal C++ blank pending final coordinate/helper names.
        - [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) 0x00565490-0x005654ec | raw method-shaped helper | ScrollVolumePaneResetInteractionStateRaw : reconstructable : 87% : strong : B003 source-quality pass confirms source-facing `ScrollVolumePane::ResetInteractionState()`, `+0xa4` TimerHandler pending-timer removal, `+0x104 = m_activePart` clear, conditional old-highlight invalidation and `+0x103 = m_highlightPart` clear, exact boundary before ScrollablePane adjustor thunk at `0x005654ec`, current ScrollVolumePane generated/source-map name support, zero VA/RVA literals and zero direct branch/call targets to the raw start, and first-draft C++ readiness after the score update.
```

## IDA Function Creation Recommendation

Do not create IDA functions for `0x00565170`, `0x005651e0`, or `0x00565490` during supervisor application unless there is a separate IDA-maintenance policy allowing function creation for source-shaped but caller-unproven raw helpers.

Rationale:

- Existing target pages say the starts are not modeled functions and have no raw-start xrefs.
- Fresh local PE scans find no direct branch/call targets and no VA/RVA pointer hits for the raw starts.
- Creating functions would make decompilation easier, but it could also falsely imply a live static caller graph.
- Source names/signatures are suitable for documentation and generated C++ after score update; they should not be treated as proof of IDA function liveness.

## Source Placement

Keep all three targets in ScrollVolumePane source placement:

- Direct owner: [UID:0001H2] `0x00564710-0x005654ec.ScrollVolumePane`
- Class owner: [UID:0000CO] `ScrollVolumePane`
- File owner/emitter: [UID:0000NK] `ScrollVolumePane`
- Proposed source file: `NexusTK/ui/controls/ScrollVolumePane.cpp`

No source-placement change is needed. The generated stale flat `class_TextEditPane.cpp` item at `0x005651e0` should be treated as a stale generated artifact, not as the source route.

## Validation

No by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md` were edited. This is report-only. No project validator was run because only this research report was created.

## Files Changed By This Agent

- `tools/leaser/Agents/Agent-B003/research/0002LB-0002LC-0002LD-ScrollVolumePaneRawInteraction-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002LB-0002LC-0002LD-ScrollVolumePaneRawInteraction-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002LB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

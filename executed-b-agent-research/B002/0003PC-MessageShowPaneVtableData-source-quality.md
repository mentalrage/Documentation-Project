** TARGET-REPORT-UID:0003PC **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003PC MessageShowPane Vtable Data Source-Quality Research


## Finalized Report / Current Recommendation

- Callback disposition: Destinations 1-18 remain applied at report-level detail. Gate 2 exposed a concrete contradiction in former verify-only Destination 19; UID0003PD is now fully researched, implemented at `91/94` with an exact covered-by marker, scoped-validated, and generated-verified. Remaining dependencies are verify-only Destination 20 and remain unchanged.
- UID0003PC was preserved while its path/range was corrected to `by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md`. It is now `92/94`, retains `CANONICAL_OWNER:000087`, is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS`, position, and formal C++, and retains `Nested:0`.
- UID0003PB was preserved and corrected to `by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md`. Validator command `000000014184` serially registered real UID0004SS at `by-memory/0x0061fad0-0x0061fadc.MetaManVtableData.md`.
- UID000087 now emits the complete `Pane` plus `Singleton<MessageShowPane>` class with the exact `0x10104` layout. UID0004HO now emits `MessageShowPane::OnPaint`; constructor/destructor lowering, `RectBounds`, `GetTextWidth`, and `m_visibleBounds` are synchronized; UID0000RK emits the singleton definition exactly once.
- UID000088 now emits the complete existing MetaMan union with the RTTI-proven `Singleton<MetaMan>` direct base. UID0004SS remains compiler-generated vtable support and no duplicate MetaMan method/global source was introduced.
- Historical callback waited command `000000014231` completed the accepted Destinations 1-18. Supervisor commands `000000014244-000000014246` then registered UID0003PD and exposed its blank formal as an Empty Emitter Marker. B002 repair commands `000000014247-000000014249` populated the exact source-use marker and refreshed both generated roots.
- Current generated MessageShowPane.cpp contains one class, one singleton definition, and one constructor/destructor/OnPaint/SetWrappedText in exact order, with no stale helper definition, Empty Emitter Marker, duplicate global, or handwritten ABI source. Current generated MetaMan.cpp contains one closed Singleton-derived class, one existing singleton definition, one UID0003PD covered-by comment, zero Empty Emitter Markers, zero standalone/raw `Meta.dat` arrays, and no handwritten vtable/RTTI/adjustor/scalar-wrapper code.
- Confidence: very strong for exact bytes, hashes, range split, COL/vtable boundaries, slot targets, inheritance, EBO layout, method identity, source order, compiler/source division, and ownership. Exact original spelling of the inherited three-argument draw-style notification remains unavailable, so the report uses the strongest descriptive source name and records the evidence cap without leaving a MessageShowPane source blocker.

## Supporting Research

- Evidence-time report-first state: before callback, no ordinary `by-*` page, manual coverage file, generated file, tracker, audit, assignment, validator state, IDA database, lifecycle state, or archive was edited.
- Evidence-collection-time MCP observation: fresh `idb_list` returned one live adopted NexusTK database, session `64c11373`, worker PID `21508`. At that time `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`. This is time-scoped research provenance, not a present-availability assertion.
- A fresh bounded `get_bytes` read of `0x0061fa3c` for 160 bytes succeeded. Fresh bounded `lookup_funcs` calls reconfirmed `0x00521da0/0x220`, `0x00521fc0/0x65`, `0x00522030/0x500`, `0x00522530/0x1ba`, `0x00522720/0xa6`, and `0x005244e0/0xa1`.
- Fresh bounded `analyze_function` on `0x00522030` reconfirmed 35 basic blocks, vtable-only data xref `0x0061fa90`, exact text copy/split/measure/draw helper set, palette values `143` and `128`, and no direct code caller.
- Fresh bounded `analyze_function` on `0x005244e0` reconfirmed the MetaMan scalar deleting destructor, vptr target `0x0061fad8`, table cleanup, singleton clear, delete-flag branch, no direct code caller, and sole vtable data xref `0x0061fad8`.
- Fresh bounded analysis of `0x0041d680` reconfirmed exact bytes `c2 0c 00`, one basic block, no callees or code callers, hundreds of primary-vtable data refs including `0x0061fa5c`, and the three-explicit-argument default virtual ABI.
- Historical pre-callback generated MessageShowPane snapshot: command `000000014105`, refreshed `2026-07-16T13:48:23-04:00`, SHA256 `1B5E8BD55982693F0C36AA566F91CE27AD32DDBF842F7A59DC6DA37C1C455F18`, 6,956 bytes, 207 lines. It contained the stale helper name, four Empty Emitter Markers, no complete class, and no singleton definition.
- Historical pre-callback generated MetaMan snapshot: command `000000014140`, refreshed `2026-07-16T14:12:42-04:00`. It already emitted the preexisting class/global route but lacked the accepted Singleton base and UID0004SS compiler-child synchronization.
- Applied callback validation: scoped validator commands `000000014180` through `000000014230` covered all 18 original changed ordinary destinations. Historical waited command `000000014231`, refreshed `2026-07-16T14:55:39-04:00`, produced the accepted callback structural proof later superseded only as a generated epoch by the UID0003PD repair.
- Gate 2 repair evidence: supervisor command `000000014244` registered the formerly unregistered UID0003PD page and command `000000014246` exposed its Empty Emitter Marker. Fresh MCP reanalysis resolved the page as a pooled source-use literal range, scoped repair command `000000014248` passed cleanly, and B002 final waited MetaMan command `000000014249` established the repair semantic proof at `2026-07-16T15:28:07-04:00`. A later concurrent generated epoch is reconciled under `Validator Results`.
- The current lease report was reread after all validation and shows no B002 lease. Other agents' unrelated leases do not affect this zero-B002-lease result.

## Target

- Target UID: `0003PC`.
- Current target path: `by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md`.
- Historical pre-callback path: `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md`.
- Source queue: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`.
- Queue row at assignment time: completion `86`, confidence `90`, reconstructable true, direct report count zero.
- Current direct parent/index: UID00025V `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md`.
- Current semantic owner: UID000087 MessageShowPane; the compiler-data target itself is non-emitting.
- Current target metadata: `92/94`, `CANONICAL_OWNER:000087`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank formal C++, `Nested:0`.

## Current Target State

- UID0003PC now covers the exact 136-byte MessageShowPane compiler island `[0x0061fa48,0x0061fad0)` with SHA256 `461519F451D2F8BA4C3442BA100EA1AEBB3E1396C3C60A02311DFF8E95DDA5DB`. Its primary COL pointer, 18-slot primary table, 11-slot EventHandler view, two-slot TimerHandler view, RTTI/PMD evidence, lifecycle xrefs, and compiler no-code disposition are complete.
- The former `[0x0061fa4c,0x0061fadc)` 144-byte range and SHA256 `764FAD54EC28E133678108256AA54B47C5CF3B386A8FAC9A7BA698935555A049` remain labeled historical pre-callback evidence.
- UID0003PB now ends at `0x0061fa48`; UID0004SS now owns `0x0061fad0-0x0061fadc`; UID00025V records the exact six-child no-loss partition.
- UID000087 emits the complete `0x10104` MessageShowPane declaration. UID0004HN, UID000492, UID0004HO, and UID0001C4 emit the accepted constructor, one-statement destructor, OnPaint, and SetWrappedText at positions `20/30/40/50`.
- Manual singleton publication/clear, `PaneRect`, `MeasureTextWidth`, `m_bounds`, and `BuildMessageTextButtons` survive only as explicitly superseded history. Current source uses the Singleton base, `RectBounds`, `GetTextWidth`, `m_visibleBounds`, and `OnPaint`.
- UID0000RK emits the sole external singleton definition at position `0`; UID0001PX is non-reconstructable/non-emitting storage support. UID0001C5/UID0001C6/UID0001C7 remain compiler-only no-code support.
- UID000088 and UID0000LC preserve the complete MetaMan union and now record direct `Singleton<MetaMan>` inheritance plus UID0004SS compiler-data ownership.
- UID0003PD now records the exact 20-byte pooled literal range at `91/94`: `L"Meta.dat"` plus terminator is used by MetaMan load/save, and the final empty-wide code unit at `0x0061faee` is used by old-MSVC row insertion lowering behind `m_rows[rowKey].push_back(valueText)`. Its formal covered-by marker replaces the Gate 2 Empty Emitter Marker without inventing standalone data.
- Current ordinary hashes and validator provenance are recorded under `Changed Files`; current generated proof is recorded under `Validator Results`.

## Executive Recommendation

- Applied compiler/source policy: the `.rdata` bytes remain compiler output, while source authority resides in the class/global/method declarations that produce them.
- Applied order: UID0003PC path correction, UID0003PB path correction, serial UID0004SS registration, then UID00025V no-loss parent synchronization.
- Applied ownership: UID000087 remains semantic owner and UID0000LB remains source file; MessageShowPane was not routed into MessageDialogs.
- Applied source order: UID0000RK global position `0`, UID000087 class position `10`, constructor `20`, destructor `30`, OnPaint `40`, and SetWrappedText `50`; UID0001PX is non-emitting.
- Applied dependency disposition: UID0003UU remains an external LivingObjectPane.cpp consumer and not a MessageShowPane method/owner.
- Applied MetaMan correction: UID000088 directly derives from `Singleton<MetaMan>` while preserving the complete current APIs, fields, map abstraction, packet behavior, and source route.
- Applied UID0003PD repair: retain owner/emitter UID0000LC, reconstructable true, blank position, and `Nested:0`; use a formal source-use marker for `L"Meta.dat"` in MetaMan load/save plus the compiler/container empty-wide tail in MetaTable materialization.

## Supervisor Active Recheck

- The supervisor assigned UID0003PC specifically because the tracker classified it as reconstructable with no direct report.
- The assignment required a full slot/source declaration/range/ownership pass, not a repetition of the current blank-vtable recommendation.
- The required split has been fully resolved into two UID-preserving path corrections and one exact new child.
- Every source-bearing item required to regenerate the MessageShowPane tables has a destination-specific formal block below.
- Every compiler-only item has a destination-specific blank formal block and exact no-code disposition below.
- Supervisor Gate 1 accepted exact report SHA256 `78CC73268D6F276938B35C213581587249C30129F662984F38EB125EB3FB43FD`.
- The authorized implementation callback and bounded Gate 2 repair are complete: Destinations 1-18 remain applied, UID0003PD is applied as Destination 19, remaining verify-only dependencies are Destination 20, C01-C31 have legal terminal states, every implementation checklist item is checked, and all leases are released.
- Manual coverage remains an exact supervisor-owned handoff; B002 did not edit coverage. Report execution, movement, archive, and lifecycle state remain supervisor/validator-owned and are not asserted here.

## Inference Research Guidance Check

- IDA facts are treated as strongest evidence: bytes, hashes, named table bases, COL pointers, RTTI base descriptors, PMD offsets, vptr-store xrefs, function sizes, decompilation, slot targets, cleanup order, and generated-wrapper behavior.
- Current by-* docs are treated as source-contract evidence where already accepted: Pane slot names, EventHandler declaration order, TimerHandler callback shape, RectBounds methods, GrafPort text/bounds helpers, Message class declaration, MessageShowPane packet consumer, and MetaMan map/API documentation.
- Existing B reports are treated as leads and provenance, not authority. Their accepted facts were rechecked against current bytes, current ordinary docs, current generated output, and live MCP.
- Generated C++ is treated as a current pollution/freshness checkpoint, not source truth.
- The current broad `MessageShowPane.cpp` versus `MessageDialogs.cpp` caveat was reanalyzed rather than inherited. Address locality, the independent singleton, packet consumer boundary, dedicated generated source root, and complete class island support standalone UID0000LB `MessageShowPane.cpp`.
- Exact original private field spellings are not recoverable, but the selected names are behaviorally specific and consistent with current project conventions.
- No Wave2/Wave3 artifact was used as authority. Historical `g_pExtendedUIPane`, FittingRoom owner pollution, `BuildMessageTextButtons`, `PaneRect`, `MeasureTextWidth`, and `m_bounds` spellings are preserved only as superseded provenance.

## Heuristic / Inference Reanalysis And Validation

### Range and RTTI boundary

- The preceding Message table has three slots, not four. Its exact source-generated table is `[0x0061fa3c,0x0061fa48)`.
- `0x0061fa48` is a pointer to primary MessageShowPane COL `0x0064c188`. The corresponding vtable base is `0x0061fa4c`.
- `0x0061fa94` points to secondary COL `0x0064c238`; secondary vtable base is `0x0061fa98`.
- `0x0061fac4` points to tertiary COL `0x0064c24c`; tertiary vtable base is `0x0061fac8`.
- The tertiary table has exactly two slots and ends at `0x0061fad0`.
- `0x0061fad0` is zero/alignment, `0x0061fad4` points to MetaMan COL `0x0064c260`, and `0x0061fad8` is MetaMan's one-slot vtable.
- UTF-16 `Meta.dat` begins at `0x0061fadc`, but Gate 2 proved UID0003PD could not remain unchanged: after registry repair its blank formal produced an Empty Emitter Marker. Fresh xrefs also prove the final zero word at `0x0061faee` is a separately used empty-wide literal, not alignment.
- UID0003PD retains the exact half-open range and MetaMan.cpp owner/emitter route. Its source-facing disposition is now a covered-by marker for `MetaMan::LoadMetaDat` / `MetaMan::SaveMetaDatIfDirty` use of `L"Meta.dat"` and for the old-MSVC `m_rows[rowKey]` insertion lowering that consumes the trailing empty-wide literal.

### MessageShowPane inheritance and layout

- RTTI hierarchy contains MessageShowPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<MessageShowPane>`.
- The source direct bases are `Pane` and `Singleton<MessageShowPane>`. Pane already contains the EventHandler and TimerHandler subobjects, so listing those as additional source bases would duplicate inheritance.
- Primary complete-object offset is `0`; EventHandler adjusted view is `+0xa0`; TimerHandler adjusted view is `+0xa4`.
- `Singleton<MessageShowPane>` PMD is `+0xf8`, nonvirtual. Empty-base optimization permits it to overlap the first derived field.
- Pane occupies `0x00-0xf8`. The MessageShowPane wide buffer begins at `+0xf8`, is `0x8000` wide characters / `0x10000` bytes, and is followed by three dwords at `+0x100f8`, `+0x100fc`, and `+0x10100`.
- Complete size is `0x10104`, independently corroborated by allocation and scalar-wrapper size-guard behavior.
- Best source-facing fields are `m_messageText`, `m_lineCount`, `m_wrappedLineCount`, and `m_maxTextWidth`.

### Primary slot source declarations

- `+0x00 -> 0x00522720`: compiler scalar deleting destructor generated by source `virtual ~MessageShowPane()`.
- `+0x04 -> 0x004f4b10`: inherited `RuntimeClass *LObject::GetRuntimeClass()`.
- `+0x08 -> 0x0041b6c0`: inherited default `LObject::OnChangeMessage(LObject *owner, Message *message)`.
- `+0x0c -> 0x004b8e20`: inherited `GrafPort::UpdateRenderRegion(const RectBounds *bounds)`.
- `+0x10 -> 0x0041d680`: inherited three-argument Pane/GrafPort draw-style notification default. Exact ABI is void with three explicit dword arguments. Strongest descriptive source name is `OnDrawStyleChanged(int style, int value, int flags)`. It is inherited and intentionally not redeclared by MessageShowPane.
- `+0x14 -> 0x00544730`: inherited `Pane::Show()`.
- `+0x18 -> 0x00544750`: inherited `Pane::Hide()`.
- `+0x1c -> 0x005447a0`: inherited `Pane::Repaint()`.
- `+0x20 -> 0x00544800`: inherited `Pane::InvalidateRect(const RectBounds *bounds)`.
- `+0x24 -> 0x00544a20`: inherited `Pane::GetDescription(int selectedIndex, wchar_t *outDescription)`.
- `+0x28 -> 0x00544b80`: inherited `Pane::GetScreenBounds(RectBounds *outBounds)`.
- `+0x2c -> 0x00544bd0`: inherited `Pane::SetBounds(const RectBounds *bounds, const RectBounds *previousBounds)`.
- `+0x30 -> 0x00544c70`: inherited `Pane::AddToLayer(const RectBounds *bounds, int y, int x, Layer *layer)`.
- `+0x34 -> 0x00544cb0`: inherited `Pane::InsertInLayer(...)`.
- `+0x38 -> 0x00544ce0`: inherited `Pane::RemoveFromLayer()`.
- `+0x3c -> 0x00544d30`: inherited `Pane::SetPaneOrder(...)`.
- `+0x40 -> 0x00544d70`: inherited `Pane::UnregisterEventHandler()`.
- `+0x44 -> 0x00522030`: MessageShowPane override `void OnPaint()`.

The `+0x10` lexical name is descriptive rather than recovered, but its exact void/three-dword ABI, inherited position, empty behavior, and broad vtable reuse are proven. No MessageShowPane class declaration depends on inventing an override for it.

### Secondary EventHandler slot source declarations

- `+0x00 -> 0x005226fb`: compiler destructor adjustor subtracting `0xa0`.
- `+0x04 -> 0x00544db0`: inherited `HandlePointerOrMouseEvent(Event *event)`.
- `+0x08 -> 0x00544dc0`: inherited `HandleKeyOrTextEvent(Event *event)`.
- `+0x0c -> 0x00544dd0`: inherited `HandleImeEvent(Event *event)`.
- `+0x10 -> 0x00544de0`: inherited `HandlePacketEvent(Event *event)`.
- `+0x14 -> 0x00544df0`: inherited `HandleSystemOrControlEvent(Event *event)`.
- `+0x18 -> 0x00544e00`: inherited `HandleType19Event(Event *event)`.
- `+0x1c -> 0x004a89f0`: inherited `ForwardHandlerOrder(EventHandler *first, EventHandler *second)`.
- `+0x20 -> 0x00544e10`: inherited `GetLocalEventPair(EventPointPair *out)`.
- `+0x24 -> 0x00544e30`: inherited `GetScreenEventPair(EventPointPair *out)`.
- `+0x28 -> 0x00544e70`: inherited `ShouldAcceptEvent() const`.

MessageShowPane provides no class-specific EventHandler override in this table.

### Tertiary TimerHandler slot source declarations

- `+0x00 -> 0x00522706`: compiler destructor adjustor subtracting `0xa4`.
- `+0x04 -> 0x00544e90`: inherited Pane default `bool OnTimer(int timerId, int arg0, int arg1)` returning true.

MessageShowPane provides no class-specific TimerHandler override in this table.

### OnPaint source reconstruction

- The target at `0x00522030` is vtable-only live through primary slot `+0x44`, exactly matching the project-wide Pane `OnPaint` position.
- It first copies inherited bounds through `GrafPort::GetBounds`, sets draw color zero, and fills the pane rectangle.
- It copies `m_messageText` into a local `wchar_t[0x8000]`, splits on `g_wszNewline`, and processes every delimited line plus the final line.
- Line width uses `GrafPort::GetTextWidth(const wchar_t *)`.
- Line advance is exactly `12 * ((lineWidth - 1) / 288) + 12`.
- Each line's draw rectangle subtracts three from right and sets bottom to top plus line advance plus two.
- Shadow text color is `143`. Six cumulative offsets are `(1,0)`, `(1,0)`, `(-2,1)`, `(3,0)`, `(-2,1)`, and `(1,0)`, with one `DrawTextInRect` after each offset.
- Face text color is `128`. Two cumulative offsets are `(-1,-1)` and `(1,0)`, with one draw after each.
- The base line rectangle advances by `(0, lineAdvance + 3)` only between newline-delimited rows.
- The decompiler's residual EAX does not represent a source return. Peer Pane paint declarations and vtable use establish `void`.
- Stale helper names `GetTextButtonBounds`, `ClearTextButtons`, `ApplyMessagePaneBorder`, `SetTextPalette`, `OffsetPaneRect`, and `AddTextButton` are rejected because current direct callees resolve to GrafPort/RectBounds drawing operations.

### Singleton/global source shape

- RTTI PMD and comparator Singleton classes resolve constructor writes as inlined `Singleton<MessageShowPane>` construction, not a manual derived-body assignment.
- Reverse base destruction occurs after the authored derived destructor body and before Pane teardown. This exactly matches observed order: RemoveFromLayer, singleton clear, Pane destruction.
- Therefore constructor source includes `Singleton<MessageShowPane>()` and does not write `g_pMessageShowPane`.
- Destructor source contains only `RemoveFromLayer()` and does not clear `g_pMessageShowPane`.
- The external packet helper UID0003UU directly names the pointer, so the source definition needs external linkage rather than a file-local `static` definition.
- UID0000RK is the sole source definition destination. UID0001PX is binary storage evidence only and must not emit a duplicate definition.

### MetaMan tail source shape

- The MetaMan primary table begins at `0x0061fad8`, not at the `Meta.dat` string.
- MetaMan RTTI contains only MetaMan plus direct `Singleton<MetaMan>`.
- Singleton PMD is `+0x04`, overlapping the first source data through EBO.
- MetaMan object size remains `0x14`; no explicit Singleton storage member or padding field is added.
- The sole slot `0x005244e0` is compiler scalar deleting destructor output generated by `virtual ~MetaMan()`.
- UID000088's existing API, map abstraction, fields, packet behavior, and file route remain valid. The class base list is the only formal source correction.

### Rejected alternatives

- Reject retaining the current target endpoints. They exclude the primary COL and include MetaMan data.
- Reject merging MetaMan data into UID0003PD. UID0003PD begins exactly at the UTF-16 string and should remain literal-only.
- Reject handwritten vtable, RTTI, COL, adjustor, scalar-wrapper, or vptr-store C++.
- Reject leaving UID000087 blank. That would retain an Empty Emitter Marker and fail to provide the declaration that regenerates the target.
- Reject keeping `BuildMessageTextButtons`. The function is a primary Pane paint override and directly draws into GrafPort; it does not create or manage child button objects.
- Reject manual singleton publication/clear in MessageShowPane methods. RTTI, PMD, EBO, store order, unwind helper, and comparator Singleton classes identify those operations as base lowering.
- Reject `MessageDialogs.cpp` as canonical MessageShowPane source. Message is a separate predecessor class; the overlay has a dedicated singleton, dedicated generated file route, independent packet consumer boundary, and contiguous source method island.
- Reject MetaMan ownership for MessageShowPane bytes and MessageShowPane ownership for MetaMan bytes.
- Reject `Nested:8` for UID0003PC. The target remains a first-level exact child with current accepted `Nested:0`; only its range changes.

## Evidence Standards Used

- Live IDA MCP: `idb_list`, `server_health`, bounded `get_bytes`, `lookup_funcs`, `analyze_function`, entity/name/RTTI checks, xrefs, and function-boundary checks.
- Binary exactness: half-open ranges, byte counts, SHA256 hashes, dword decoding, COL pointers, table bases, slot counts, trailing successor bytes, and object-size guards.
- Type evidence: RTTI class hierarchy descriptors, complete-object offsets, PMD values, EBO, source base comparison, and current class/layout docs.
- Source behavior evidence: constructor/destructor order, virtual dispatch position, callers/callees, field offsets, global writers/readers, packet consumer routes, and generated-wrapper duplication.
- Current documentation evidence: target, parent, class, file, global, storage, exact source children, compiler-support children, Pane/GrafPort/EventHandler/TimerHandler/RectBounds, Message, MetaMan, and `Meta.dat`.
- Historical evidence: required executed B reports with current centralized paths and hashes.
- Generated evidence: historical pre-callback MessageShowPane.cpp and MetaMan.cpp headers, historical accepted-callback waited command `000000014231`, the supervisor registration/failure epoch `000000014244-000000014246`, B002 repair waited command `000000014249`, and latest observed concurrent header command `000000014262`; exact hashes/metrics, header-normalization equality, definition counts/order, UID0003PD marker removal, and compiler-ABI exclusion readback are all recorded.
- Source-literal evidence: exact UTF-16 bytes, the two `L"Meta.dat"` use-site xrefs, the separately referenced final empty-wide code unit, accepted MetaMan/MetaTable operations, and the absence of any independent named/global raw-string object.
- Negative evidence: no direct code callers for vtable-only OnPaint, no code xrefs to COL cells, no separate MessageShowPane event/timer overrides, no source reason for handwritten ABI tables, no standalone `Meta.dat` data declaration, no active B001-B005 direct report, and no valid source ownership for the mixed parent.
- The evidence ladder is sufficient for `92/94` because all binary/source-shape blockers are closed. Remaining exact-original lexical uncertainty is isolated to inherited base/private spellings and does not affect behavior, range, class layout, source placement, or formal C++ readiness.

## Evidence Checked

### Live MCP and binary checks

- Fresh `idb_list`: session `64c11373`, `NexusTK.exe.i64`, active, adopted, worker PID `21508`.
- Fresh `server_health`: ok; analysis, Hex-Rays, and string cache ready.
- Fresh bounded `get_bytes(0x0061fa3c,160)`: succeeded and supplied the complete Message/MessageShowPane/MetaMan boundary window.
- SHA256 recomputation from that exact current MCP byte window:
  - `[0x0061fa3c,0x0061fa48)`: 12 bytes, `7F890CB7BB9287A9CCB6F96F4300832538C739AB5DCA572490DF0E6EE1C9B1B2`.
  - `[0x0061fa48,0x0061fad0)`: 136 bytes, `461519F451D2F8BA4C3442BA100EA1AEBB3E1396C3C60A02311DFF8E95DDA5DB`.
  - `[0x0061fad0,0x0061fadc)`: 12 bytes, `FCDDBD933E0EB95CE2C0A77696FC2AA79FAB7502469A0E3DD7C0FAE043DF0679`.
  - Existing stale assigned `[0x0061fa4c,0x0061fadc)`: 144 bytes, `764FAD54EC28E133678108256AA54B47C5CF3B386A8FAC9A7BA698935555A049`.
- Fresh `lookup_funcs`: constructor, ordinary destructor, OnPaint body, SetWrappedText, scalar wrapper, and MetaMan scalar wrapper all matched current modeled boundaries.
- Fresh `analyze_function(0x00522030)`: 1,280 bytes, 35 blocks, no direct callers, one vtable data xref, exact helper/callee and text draw behavior.
- Fresh `analyze_function(0x005244e0)`: 161 bytes, generated deleting wrapper behavior, one vtable data xref.
- Fresh `analyze_function(0x0041d680)` plus bytes: one-block three-argument no-op, `retn 0x0c`, no code callers, broad vtable-only reuse.
- RTTI/COL checks: MessageShowPane primary/secondary/tertiary COL records and MetaMan primary COL; hierarchy and PMD facts recorded above.
- Xref checks: all three MessageShowPane table-base store triads and the MetaMan constructor/destructor/scalar-wrapper triad; no code xrefs to COL cells.
- Gate 2 repair `get_bytes(0x0061fadc,20)` returned `4d 00 65 00 74 00 61 00 2e 00 64 00 61 00 74 00 00 00 00 00`, SHA256 `7C262FEDC4E6CFA43F5878686E9673B7D7BCBABEB2A27AA9AEB856C0486BB4D9`.
- Gate 2 repair `xrefs_to(0x0061fadc)` returned exactly `0x005234ae` in `MetaMan::LoadMetaDat` and `0x005237fa` in `MetaMan::SaveMetaDatIfDirty`. Both build a path with `L"%s"` and the pooled `L"Meta.dat"` literal; the first opens read/share-one/open-existing and the second opens write/exclusive/create-always behind the dirty gate.
- Gate 2 repair `xrefs_to(0x0061faee)` returned exactly `0x00524b01` in the old-MSVC row-node insertion path inside `MetaTable::MaterializeRowsIfNeeded`; `xrefs_to(0x0061faec)` and `xrefs_to(0x0061faf0)` returned none. This disproves the former alignment/padding interpretation for the final two bytes.
- Fresh disassembly at `0x00524b01` shows `push offset unk_61FAEE` immediately before the row-node allocation/initialization helper. The accepted source operation remains `m_rows[rowKey].push_back(valueText)`; no explicit standalone `L""` object is source-justified.

### Evidence-time ordinary and generated docs checked

The paths in this list are the report-first names inspected before UID-preserving corrections. Current applied paths and hashes are recorded under `Changed Files`.

- `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md`
- `by-memory/0x0061fa3c-0x0061fa4c.MessageVtableData.md`
- `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md`
- `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`
- `by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md`
- `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`
- `by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md`
- `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`
- `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`
- `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`
- `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`
- `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`
- `by-memory/0x0061fadc-0x0061faf0.MetaDatFilenameString.md`
- `by-class/MessageShowPane.md`
- `by-file/MessageShowPane.md`
- `by-global/g_pMessageShowPane.md`
- `by-class/MetaMan.md`
- `by-file/MetaMan.md`
- `by-global/g_pMetaMan.md`
- `by-class/Pane.md`
- `by-type/by-struct/PaneLayout.md`
- `by-type/by-vtable/PaneVtables.md`
- `by-class/GrafPort.md`
- `by-class/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-class/LObject.md`
- `by-class/EventHandler.md`
- `by-class/TimerHandler.md`
- `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`
- `auto-generated/NexusTK/metadata/MetaMan.cpp`

Gate 2 repair reread additionally covered current UID0003PD, UID0001CC
`MetaTableMaterializeRows`, UID0001CD `MetaTableRowTreeHelpers`, current
MetaMan class/file source contracts, and the generated files after supervisor
commands `000000014244-000000014246` and repair command `000000014249`.

### Old-report searches and opened artifacts

Search terms used exactly:

`UID0003PC`, `0003PC`, `0x0061fa4c`, `0x0061fadc`, `0x0061fad0`, `MessageShowPaneVtableData`, `MessageShowPane`, `0x00522030`, `BuildMessageTextButtons`, `MessageShowPaneOnPaint`, `MetaMan`, `0x0061fad8`, `0x005244e0`, `g_pMessageShowPane`, `UID000087`, `UID0000LB`, `UID00025V`, `UID0002Y8`, `UID0001C7`, `UID0003UU`, and `UID000084`.

- Central executed root searched: `executed-b-agent-research`. It contains no report with `TARGET-REPORT-UID:0003PC`. Relevant exact-family artifacts opened:
  - `executed-b-agent-research/B001/00025V-MessageShowReadOnlyData-source-quality.md`, SHA256 `160BD6B1D905139F54FEBEF1D3B06B9DC937B688428909D33E1F39F7265895D2`, 35,913 bytes, 319 lines. Valid parent split/index evidence; its old target endpoint is superseded by current bytes.
  - `executed-b-agent-research/B004/0002Y8-MessageShowPaneMethods-source-quality.md`, SHA256 `F7B98C11BF6EEEBF79DF76B749F774E4BAEAB1040FA57A63F2C0E21D629F033F`, 68,167 bytes, 727 lines. Valid method split/formal provenance; stale helper and Singleton source-shape assumptions are corrected here.
  - `executed-b-agent-research/B008/0001C7-MessageShowPaneScalarDeletingDestructor-source-quality.md`, SHA256 `7BC2D2745FE9B191D6054ABCCCF28BE63CA02A6C90EE9CB445B6EAF70A5B90D2`, 26,103 bytes, 312 lines. Valid ordinary/scalar/adjustor split; explicit derived singleton clear is superseded by RTTI/EBO evidence.
  - `executed-b-agent-research/B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`, SHA256 `0D7FB21FBC953539E87BD2EC01554F445F95A77CE0FC29540F1A229F051AB395`, 57,570 bytes, 671 lines. Valid external packet-helper dependency and constructor/SetWrappedText consumers.
  - `executed-b-agent-research/B015/000084-Message-class-source-quality.md`, SHA256 `7F44DFC9EBF448FB453FF60501E733E52C9E397F65A2E8D3AED283C2C00C55E4`, 39,074 bytes, 563 lines. Valid Message class/source declaration and three-slot predecessor vtable evidence.
  - `executed-b-agent-research/B009/000088-MetaMan-class-source-quality.md`, SHA256 `6192924E798D2D075CA6F799CA606E35FD0E98C759E0CC5C3EAEEF86090682FA`, 43,354 bytes, 532 lines. Valid MetaMan API/layout/map/source evidence; current RTTI adds the missing Singleton direct base.
- Active B001 research root searched: no matching UID0003PC/direct-range report.
- Active B002 research root searched before report creation: no matching UID0003PC/direct-range report.
- Active B003 research root searched: no matching UID0003PC/direct-range report.
- Active B004 research root searched: no matching UID0003PC/direct-range report.
- Active B005 research root searched: no matching UID0003PC/direct-range report.
- Legacy per-agent `research/executed` roots for B001-B005 were checked and are absent in the current canonical tree.
- Broad central matches outside the six opened artifacts were screened as consumer, generic Message/MetaMan, or unrelated vtable-family references and do not substitute for an exact target report.

### Manual coverage roots checked read-only

- Evidence-time / pre-callback snapshots:
  - `by-memory/-coverage-report.md`: SHA256 `5F1B53BF748D13A74890505C037754B414C9F9BD02980E99C7C48E43B7A25FA8`, 1,774,499 bytes, 4,253 lines.
  - `by-class/-coverage-report.md`: SHA256 `9710D23ADFD1CAF806CAE8DEDE327C69420C38BEF0CDCAD1C181621A9B9B6BFA`, 229,370 bytes, 622 lines.
  - `by-file/-coverage-report.md`: SHA256 `0EBB76739F9FBC1AB22D9C04D1E4A070118F9079808E99B6EDFF477FE990D82E`, 131,915 bytes, 316 lines.
  - `by-global/-coverage-report.md`: SHA256 `61D81E3B76C64C37FDE94942FEC3399940E7793C493EE09E1FB0D28C02EDAE09`, 89,137 bytes, 210 lines.
- Historical final callback read-only snapshots before supervisor Gate 2 coverage/registry activity:
  - `by-memory/-coverage-report.md`: SHA256 `6A92D517173EFF0C118A359E3A31293A2280D2F576E550AB7AF806D2DF754D22`, 1,778,800 bytes, 4,258 lines.
  - `by-class/-coverage-report.md`: SHA256 `9FFBA580555349BD5B772434F089DE9F374A83D416FE8BC60D871653A91F077B`, 230,374 bytes, 622 lines.
  - `by-file/-coverage-report.md`: SHA256 `A6C7BC6A44CE868D990A764AB011377BEA2CBA83DB9C0C841DA28153FAF20CE1`, 132,211 bytes, 316 lines.
  - `by-global/-coverage-report.md`: SHA256 `A450395CD7C0F15D0F0BA6D681B13D2EF92EC30634B8806E638B0FD5C9C42B67`, 90,088 bytes, 212 lines.
- Latest observed Gate 2 repair read-only snapshots at the final report pass:
  - `by-memory/-coverage-report.md`: SHA256 `5C8033E8C25C274D1D138D25E4499524806A3AFB8C7A0618B7DC39F13E607BF3`, 1,781,759 bytes, 4,265 lines.
  - `by-class/-coverage-report.md`: SHA256 `7140D6E7CEBA9F552984CD66EFAD01A7DD9693D2196C4498ACBC92032E7D46BE`, 230,570 bytes, 622 lines.
  - `by-file/-coverage-report.md`: SHA256 `79DBB32440FA1EEB3DA22C3E00004B7883F05788296DBB95F1A3AB80642459DB`, 132,263 bytes, 316 lines.
  - `by-global/-coverage-report.md`: SHA256 `CA6748C2ED56235F95727DFE7C000B30B03213EF42D1F9A93BF796B550A5DB32`, 90,148 bytes, 212 lines.
- `by-type/-coverage-report.md`: SHA256 `FC82E0BA3F71F297BC40842249BB7C008991CB1DCEF41B27362D7FCA9D15A204`, 5,380 bytes, 34 lines. No affected by-type row exists; no by-type destination is proposed.
- At that latest observed readback, the accepted UID0002Y8/UID0004HN/UID000492/UID0004HO/UID0001C4/UID0001C5/UID0001C6/UID0001C7/UID00025V/UID0003PB/UID0003PC/UID0004SS/UID0001PX, UID000087/UID000088, UID0000LB/UID0000LC, and UID0000RK rows are already present at the accepted scores and detail. UID0003PD alone remains at historical `86%` wording that says it is unchanged. The only observed manual delta is therefore the exact UID0003PD supervisor-owned replacement below.

### Failed or skipped checks

- One initial fresh `get_bytes` request used the obsolete single-address schema and returned a parameter error requiring `regions`. The request was immediately corrected with current `tools/list` schema and succeeded. This was a client-shape error, not MCP unavailability.
- No IDA mutation was attempted or required.
- Evidence-time report-first phase: no implementation validator or ordinary lease was used, as required.
- Callback phase: every changed ordinary page was leased only immediately before its edit, scoped-validated, and immediately released. The exact commands are recorded under `Validator Results`; final lease state is zero.
- Gate 2 repair phase: UID0003PD alone was leased for its immediate ordinary edit. Initial command `000000014247` exposed one unstable successor UID label, the label was removed without changing the accepted range/disposition, clean command `000000014248` passed, and the lease was immediately released. Final waited command `000000014249` refreshed MetaMan and MessageShowPane output.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0003PC must preserve its UID while moving to exact range `0x0061fa48-0x0061fad0`. | Very high | Current bytes, COL pointers, table extents, hashes. | Applied Destination 1; current target path/hash and command `000000014180`. | incorporate | applied |
| C02 | The old assigned range/hash remains useful only as a labeled historical stale-boundary snapshot. | Very high | Existing page and current recomputed stale-range hash. | Applied Destination 1 history; old range/hash explicitly labeled pre-callback. | historicalize | applied |
| C03 | Primary COL is at `0x0061fa48`, primary vtable is `0x0061fa4c-0x0061fa94`, and it has 18 exact slots. | Very high | Bytes, names, xrefs, RTTI, slot map. | Applied Destination 1 observed contents and slot table. | incorporate | applied |
| C04 | Secondary COL is at `0x0061fa94`, EventHandler vtable is `0x0061fa98-0x0061fac4`, and it has 11 exact slots. | Very high | Bytes, adjusted offset `+0xa0`, EventHandler declaration. | Applied Destination 1 EventHandler table and adjustor disposition. | incorporate | applied |
| C05 | Tertiary COL is at `0x0061fac4`, TimerHandler vtable is `0x0061fac8-0x0061fad0`, and it has two exact slots. | Very high | Bytes, adjusted offset `+0xa4`, TimerHandler contract. | Applied Destination 1 TimerHandler table and adjustor disposition. | incorporate | applied |
| C06 | MessageShowPane source direct bases are Pane and `Singleton<MessageShowPane>`; EventHandler/TimerHandler are inherited Pane subobjects. | Very high | RTTI CHD/PMD, Pane layout, comparator Singleton classes. | Applied Destination 5 class declaration; command `000000014198`. | incorporate | applied |
| C07 | Complete MessageShowPane layout is Pane `0xf8`, EBO-overlapped `wchar_t[0x8000]`, three ints, total `0x10104`. | Very high | Field accesses, allocation, scalar size guard, PMD. | Applied Destination 5 layout/body and generated class readback. | incorporate | applied |
| C08 | Constructor singleton publication and destructor singleton clear are implicit Singleton base lowering, not derived authored statements. | Very high | PMD, store order, EH helper, reverse destruction, comparator classes. | Applied Destinations 6, 7, and 11-13 history/formals. | reject-stale | applied |
| C09 | `0x00522030` is `MessageShowPane::OnPaint`, not `BuildMessageTextButtons`. | Very high | Primary slot `+0x44`, no callers, direct GrafPort drawing body, peer declarations. | Applied UID-preserving Destination 8 path/body; command `000000014208`. | reject-stale | applied |
| C10 | OnPaint draws exact background, six shadow passes at 143, two face passes at 128, and exact row advances. | Very high | Fresh decompile, callees, offsets, constants. | Applied Destination 8 formal/body and generated line-order readback. | incorporate | applied |
| C11 | Constructor and SetWrappedText use current `RectBounds`, `GetTextWidth`, and `m_visibleBounds` contracts. | High | Current GrafPort/RectBounds/Pane support, direct callees and offsets. | Applied Destinations 6 and 9; commands `000000014203` and `000000014210`. | reject-stale | applied |
| C12 | UID0000RK must emit the sole external-linkage singleton definition at position 0. | High | Packet helper cross-source use, exact global storage, evidence-time generated empty marker. | Applied Destination 10; command `000000014212`; one generated definition. | incorporate | applied |
| C13 | UID0001PX remains semantic storage under UID0000RK but becomes non-reconstructable/non-emitting to prevent a duplicate definition. | Very high | One-definition policy, evidence-time empty marker, exact storage-only role. | Applied Destination 11; command `000000014214`; no storage marker/duplicate. | incorporate | applied |
| C14 | UID00025V remains an ownerless non-emitting mixed index and receives the corrected six-child partition. | Very high | Mixed owner window and exact children. | Applied Destination 4; command `000000014192`. | incorporate | applied |
| C15 | UID0003PB preserves its UID but ends at `0x0061fa48`, contains exactly three Message slots, and becomes compiler-output non-emitting support. | Very high | Current bytes, B015 Message declaration, COL boundary. | Applied Destination 2; command `000000014182`. | incorporate | applied |
| C16 | UID0004SS must cover `0x0061fad0-0x0061fadc` as MetaMan compiler vtable data. | Very high | Zero/COL/slot dwords, MetaMan xrefs/RTTI. | Applied Destination 3; registered by command `000000014184`. | incorporate | applied |
| C17 | MetaMan directly derives from `Singleton<MetaMan>` at EBO offset `+0x04`. | Very high | MetaMan RTTI CHD/PMD, object layout, lifecycle stores. | Applied Destination 12 and file support; commands `000000014229`/`000000014230`. | incorporate | applied |
| C18 | UID0002Y8 remains a non-emitting method index but must rename the source child to OnPaint and preserve exact source order. | Very high | Existing split plus current vtable/source resolution. | Applied Destination 13; command `000000014217`. | incorporate | applied |
| C19 | UID0001C5 remains compiler EH cleanup, now explicitly caused by Singleton base construction/unwind. | Very high | Tiny clear body, constructor unwind, PMD. | Applied Destination 14; command `000000014223`. | incorporate | applied |
| C20 | UID0001C6 remains compiler adjustor thunk support with exact `-0xa0/-0xa4` views. | Very high | Bytes, thunk targets, COL offsets. | Applied Destination 15; command `000000014225`. | incorporate | applied |
| C21 | UID0001C7 remains compiler scalar deleting wrapper; its singleton clear is base-destruction lowering. | Very high | Wrapper body, delete flags, size guard, ordinary destructor parity. | Applied Destination 16; command `000000014227`. | incorporate | applied |
| C22 | UID0000LB standalone MessageShowPane.cpp is the canonical source route with global/class/method order 0/10/20/30/40/50. | High | Address island, independent singleton, generated root, packet boundary. | Applied Destination 17; command `000000014228`; generated order verified. | incorporate | applied |
| C23 | UID0003UU remains an external LivingObjectPane.cpp packet-helper dependency and is verify-only. | Very high | Executed B011 report, one constructor/update caller route. | Destination 20 reread; hash unchanged and no contradiction. | already-present | already-present |
| C24 | All 18 primary slots have source-facing declarations or compiler dispositions; no slot remains unnamed. | High | Current Pane/GrafPort/LObject docs plus ABI checks. | Applied Destination 1 slot table and Destination 5 declaration. | incorporate | applied |
| C25 | All 11 secondary slots are exact inherited EventHandler declarations except the compiler adjustor. | Very high | EventHandler formal and target dwords. | Applied Destination 1 table; verify-only EventHandler remained unchanged. | incorporate | applied |
| C26 | Both tertiary slots are exact: compiler adjustor plus inherited Pane default OnTimer. | Very high | TimerHandler contract, target dwords, bytes. | Applied Destination 1 table; verify-only TimerHandler remained unchanged. | incorporate | applied |
| C27 | Target/support score increases are justified by closed range, declaration, type, ownership, emission, and C++ blockers. | High | Full report evidence. | Applied Destinations 1-18; final scores and metadata read back. | incorporate | applied |
| C28 | Final generated MessageShowPane.cpp must contain one class/global/ctor/dtor/OnPaint/SetWrappedText and no target/storage Empty Emitter Markers or handwritten ABI tables. | Very high | Evidence-time generated defects and accepted source route. | Historical callback proof came from `000000014231`; B002 repair waited proof came from `000000014249`; latest observed command `000000014262` is header-only different and preserves exact counts/semantics. | incorporate | applied |
| C29 | Latest observed manual coverage contains the accepted Destinations 1-18 rows, while UID0003PD alone remains stale at `86%` and requires the exact supervisor-owned replacement below. | Very high | Final-read five-root hashes and exact affected-row readback. | Applied rows are documented as already present; exact remaining UID0003PD handoff is preserved and B002 coverage editing is prohibited. | incorporate | excluded-with-reason |
| C30 | Historical reports, stale names, rejected alternatives, exact hashes, compiler boundaries, and negative evidence must be preserved without compression. | Very high | Rule 26 and all evidence sections. | Applied across all changed destinations and this additive callback record. | incorporate | applied |
| C31 | UID0003PD must remain source-bearing under UID0000LC but emit only a destination-specific covered-by marker for pooled `L"Meta.dat"` use and the compiler-lowered empty-wide tail, not a standalone raw string object. | Very high | Exact 20 bytes/hash, two filename xrefs, separate `0x0061faee` xref, MetaMan/MetaTable source operations, supervisor marker failure, current generated readback. | Applied Destination 19; `91/94`, owner/emitter UID0000LC, true, blank position, exact covered-by formal, command `000000014248`, B002 waited proof `000000014249`, latest observed preservation `000000014262`. | reject-stale | applied |

## Positive Evidence Summary

- The exact current byte window independently yields clean, adjacent Message, MessageShowPane, and MetaMan boundaries with no gap or overlap.
- Decorated table names and COL names align exactly with the byte split.
- Constructor, ordinary destructor, and scalar deleting wrapper write each MessageShowPane table base in matching triads.
- RTTI fully explains the three table views and establishes the direct source base list.
- The scalar object-size guard exactly matches the inferred class layout.
- Primary slot `+0x44` is the only class-specific MessageShowPane method and points to the complete text-paint body.
- Current Pane, GrafPort, RectBounds, LObject, EventHandler, and TimerHandler docs resolve every source declaration needed by the vtable.
- Packet helper UID0003UU proves real constructor and SetWrappedText liveness and cross-file singleton visibility.
- MetaMan RTTI and scalar-wrapper xref prove the trailing bytes are a separate class's compiler output.
- The strongest inference chain is: exact COL/table bytes establish the class boundaries; RTTI establishes direct bases and adjusted views; vptr stores establish lifecycle; the slot map establishes class/inherited methods; exact method bodies establish source declarations; therefore the compiler-generated target should be non-emitting while the complete class/global/method source is emitted through UID0000LB.

## IDA MCP Facts

### Exact dword inventory

| Address | Dword target/value | Classification |
| --- | --- | --- |
| `0x0061fa3c` | `0x00521d40` | Message scalar deleting destructor slot 0 |
| `0x0061fa40` | `0x004f4b10` | Message inherited GetRuntimeClass slot |
| `0x0061fa44` | `0x0041b6c0` | Message inherited OnChangeMessage default slot |
| `0x0061fa48` | `0x0064c188` | MessageShowPane primary COL pointer |
| `0x0061fa4c` | `0x00522720` | MessageShowPane primary slot `+0x00` |
| `0x0061fa50` | `0x004f4b10` | primary `+0x04` |
| `0x0061fa54` | `0x0041b6c0` | primary `+0x08` |
| `0x0061fa58` | `0x004b8e20` | primary `+0x0c` |
| `0x0061fa5c` | `0x0041d680` | primary `+0x10` |
| `0x0061fa60` | `0x00544730` | primary `+0x14` |
| `0x0061fa64` | `0x00544750` | primary `+0x18` |
| `0x0061fa68` | `0x005447a0` | primary `+0x1c` |
| `0x0061fa6c` | `0x00544800` | primary `+0x20` |
| `0x0061fa70` | `0x00544a20` | primary `+0x24` |
| `0x0061fa74` | `0x00544b80` | primary `+0x28` |
| `0x0061fa78` | `0x00544bd0` | primary `+0x2c` |
| `0x0061fa7c` | `0x00544c70` | primary `+0x30` |
| `0x0061fa80` | `0x00544cb0` | primary `+0x34` |
| `0x0061fa84` | `0x00544ce0` | primary `+0x38` |
| `0x0061fa88` | `0x00544d30` | primary `+0x3c` |
| `0x0061fa8c` | `0x00544d70` | primary `+0x40` |
| `0x0061fa90` | `0x00522030` | primary `+0x44`, MessageShowPane OnPaint |
| `0x0061fa94` | `0x0064c238` | MessageShowPane secondary COL pointer |
| `0x0061fa98` | `0x005226fb` | secondary slot `+0x00`, destructor adjustor |
| `0x0061fa9c` | `0x00544db0` | secondary `+0x04` |
| `0x0061faa0` | `0x00544dc0` | secondary `+0x08` |
| `0x0061faa4` | `0x00544dd0` | secondary `+0x0c` |
| `0x0061faa8` | `0x00544de0` | secondary `+0x10` |
| `0x0061faac` | `0x00544df0` | secondary `+0x14` |
| `0x0061fab0` | `0x00544e00` | secondary `+0x18` |
| `0x0061fab4` | `0x004a89f0` | secondary `+0x1c` |
| `0x0061fab8` | `0x00544e10` | secondary `+0x20` |
| `0x0061fabc` | `0x00544e30` | secondary `+0x24` |
| `0x0061fac0` | `0x00544e70` | secondary `+0x28` |
| `0x0061fac4` | `0x0064c24c` | MessageShowPane tertiary COL pointer |
| `0x0061fac8` | `0x00522706` | tertiary slot `+0x00`, destructor adjustor |
| `0x0061facc` | `0x00544e90` | tertiary slot `+0x04`, Pane default OnTimer |
| `0x0061fad0` | `0x00000000` | alignment/foreign MetaMan child prefix |
| `0x0061fad4` | `0x0064c260` | MetaMan primary COL pointer |
| `0x0061fad8` | `0x005244e0` | MetaMan scalar deleting destructor slot |
| `0x0061fadc` | UTF-16 `Meta.dat` | UID0003PD pooled filename literal begins |
| `0x0061faec` | UTF-16 zero | terminator for `L"Meta.dat"` |
| `0x0061faee` | UTF-16 zero | separately referenced empty-wide literal used by old-MSVC row insertion lowering |

### Function and xref facts

- `0x00521da0`: constructor, size `0x220`, sole packet-helper caller, three vptr stores.
- `0x00521fc0`: ordinary destructor, size `0x65`, no ordinary direct caller, three compiler vptr restores.
- `0x00522030`: OnPaint, size `0x500`, 35 blocks, no code caller, one data xref at `0x0061fa90`.
- `0x00522530`: SetWrappedText, size `0x1ba`, sole packet-helper caller.
- `0x005226f0`: Singleton constructor-unwind clear helper.
- `0x005226fb` and `0x00522706`: exact `-0xa0` and `-0xa4` deleting-destructor adjustors.
- `0x00522720`: scalar deleting destructor, size `0xa6`, primary vtable data xref and adjustor callers only.
- `0x005244e0`: MetaMan scalar deleting destructor, size `0xa1`, one vtable data xref at `0x0061fad8`.
- `0x0041d680`: exact `retn 0x0c`, no body, no code caller, vtable-only use.
- Primary table bases `0x0061fa4c`, secondary `0x0061fa98`, and tertiary `0x0061fac8` each have constructor/destructor/scalar-wrapper store triads.
- COL pointer cells have no code xrefs, which is normal compiler RTTI data and not a liveness defect.
- `0x0061fadc` has exactly two xrefs: `0x005234ae` in `MetaMan::LoadMetaDat` and `0x005237fa` in `MetaMan::SaveMetaDatIfDirty`.
- `0x0061faee` has exactly one xref at `0x00524b01` inside the old-MSVC row insertion lowering behind `MetaTable::MaterializeRowsIfNeeded`; the terminator at `0x0061faec` and successor boundary `0x0061faf0` have no xrefs.

### RTTI facts

| Class/view | COL | Complete-object offset | Source meaning |
| --- | --- | --- | --- |
| MessageShowPane primary | `0x0064c188` | `0` | complete object / Pane primary view |
| MessageShowPane secondary | `0x0064c238` | `0xa0` | inherited EventHandler view |
| MessageShowPane tertiary | `0x0064c24c` | `0xa4` | inherited TimerHandler view |
| MetaMan primary | `0x0064c260` | `0` | complete MetaMan object |

- MessageShowPane CHD has seven entries: MessageShowPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<MessageShowPane>`.
- `Singleton<MessageShowPane>` PMD is `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`.
- MetaMan CHD has two entries: MetaMan and `Singleton<MetaMan>`.
- `Singleton<MetaMan>` PMD is `mdisp=4`, `pdisp=-1`, `vdisp=0`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061fa3c-0x0061fafc` | UID00025V `MessageShowReadOnlyData` | mixed `.rdata` index | false | none | `90/94` | applied six-child partition |
| `0x0061fa3c-0x0061fa48` | UID0003PB corrected `MessageVtableData` | compiler Message vtable | false | UID00025V; semantic owner UID000084 | `90/93` | applied UID-preserving path/range correction |
| `0x0061fa48-0x0061fad0` | UID0003PC corrected `MessageShowPaneVtableData` | compiler RTTI and three vtable views | false | UID00025V; semantic owner UID000087 | `92/94` | applied UID-preserving target path/range correction |
| `0x0061fad0-0x0061fadc` | UID0004SS `MetaManVtableData` | alignment, COL, one-slot compiler vtable | false | UID00025V; semantic owner UID000088 | `91/94` | registered and applied |
| `0x0061fadc-0x0061faf0` | UID0003PD `MetaDatFilenameString` | pooled source-use literals represented by consuming source | true | UID00025V / UID0000LC | `91/94` | applied covered-by formal; no standalone raw object |
| `0x00521da0-0x005227c6` | UID0002Y8 `MessageShowPaneMethods` | non-emitting method index | false | UID000087 | `90/93` | applied exact source/generated child inventory |
| `0x00521da0-0x00521fc0` | UID0004HN constructor | source-authored method | true | UID000087 | `92/94` | applied Singleton/base/types/order |
| `0x00521fc0-0x00522025` | UID000492 destructor | source-authored method | true | UID000087 | `92/94` | applied one-statement source body |
| `0x00522030-0x00522530` | UID0004HO OnPaint | source-authored paint override | true | UID000087 | `92/94` | applied UID-preserving rename/body |
| `0x00522530-0x005226ea` | UID0001C4 SetWrappedText | source-authored method | true | UID000087 | `92/94` | applied types/helpers/field |
| `0x005226f0-0x005226fb` | UID0001C5 | compiler EH cleanup | false | none | `90/94` | retain blank/no-code; sync Singleton cause |
| `0x005226fb-0x00522711` | UID0001C6 | compiler adjustors | false | none | `91/94` | retain blank/no-code; exact views |
| `0x00522720-0x005227c6` | UID0001C7 | compiler scalar wrapper | false | none | `91/94` | retain blank/no-code; sync Singleton cause |
| MessageShowPane class | UID000087 `by-class/MessageShowPane.md` | source class declaration | true | UID0000LB | `92/94` | applied complete formal class at position 10 |
| MessageShowPane singleton | UID0000RK `by-global/g_pMessageShowPane.md` | sole source definition | true | UID0000LB | `92/94` | applied formal definition at position 0 |
| `0x0069b4f4-0x0069b4f8` | UID0001PX exact storage | binary storage support | false | UID0000RK | `91/94` | blank/non-emitting |
| MessageShowPane file | UID0000LB `by-file/MessageShowPane.md` | source module | true | FILE | `92/93` | applied source order and declaration route |
| MetaMan class | UID000088 `by-class/MetaMan.md` | source class declaration | true | UID0000LC | `91/93` | applied direct Singleton base with full API/layout union |
| MetaMan file | UID0000LC `by-file/MetaMan.md` | source module | true | FILE | `92/93` | applied compiler child/source-cause prose |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061fa4c` | stores at `0x00521e1d`, `0x00521fe5`, `0x0052274c` | primary table installed/restored by ctor/dtor/scalar wrapper |
| `0x0061fa98` | stores at `0x00521e23`, `0x00521feb`, `0x00522752` | EventHandler adjusted table lifecycle |
| `0x0061fac8` | stores at `0x00521e2d`, `0x00521ff5`, `0x0052275c` | TimerHandler adjusted table lifecycle |
| `0x0061fa90` | data xref to `0x00522030` | OnPaint vtable-only liveness |
| `0x00522030` | no code callers | expected virtual-only paint override |
| `0x00522530` | sole code caller `0x005ac150` | existing overlay update |
| `0x00521da0` | sole packet-side caller `0x005ac17e` | new overlay creation |
| `0x0069b4f4` | constructor/destructor/EH/scalar writers; packet/UI readers | singleton lifecycle and cross-file visibility |
| `0x0061fad8` | stores from MetaMan constructor/destructor/scalar wrapper | MetaMan one-slot vtable lifecycle |
| `0x005244e0` | no code callers, one data xref from `0x0061fad8` | compiler scalar-wrapper liveness |
| `0x0061fadc` | xrefs `0x005234ae`, `0x005237fa` | pooled `L"Meta.dat"` use in load/save paths |
| `0x0061faee` | xref `0x00524b01` | final empty-wide code unit is live compiler/container lowering, not padding |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback state: UID0003PC and UID0003PB had stale endpoints; UID00025V omitted the distinct MetaMan child; UID000087 and UID0000RK/UID0001PX produced blank-emitter routes; UID0004HO used the stale helper name; UID000088 omitted the direct Singleton base; generated MessageShowPane.cpp lacked the class/global and contained four Empty Emitter Markers. These facts are retained only as superseded implementation history.
- Current applied UID0003PC: corrected path `0x0061fa48-0x0061fad0`, `92/94`, owner UID000087, false/non-emitting, blank emitter/position/formal, `Nested:0`; validator `000000014180`.
- Current applied UID0003PB and UID0004SS: exact Message three-slot child validated by `000000014182`; exact MetaMan compiler child UID0004SS registered/validated by `000000014184`. UID00025V's six-child no-loss partition validated by `000000014192`.
- Current applied MessageShowPane source: UID000087 complete class at position 10 (`000000014198`), constructor at 20 (`000000014203`), destructor at 30 (`000000014205`), UID0004HO OnPaint at 40 (`000000014208`), SetWrappedText at 50 (`000000014210`), singleton definition at 0 (`000000014212`), and non-emitting storage (`000000014214`).
- Current applied compiler/source support: UID0002Y8 (`000000014217`), UID0001C5 (`000000014223`), UID0001C6 (`000000014225`), UID0001C7 (`000000014227`), and UID0000LB (`000000014228`) preserve exact compiler exclusions and source order without duplicate bodies.
- Current applied MetaMan support: UID000088 (`000000014229`) emits the complete accepted class union with direct `Singleton<MetaMan>` inheritance and closes `};` before `[[CHILDREN]]`; UID0000LC (`000000014230`) records UID0004SS and EBO/compiler-source causality without by-file reconstruction metadata.
- Historical callback-time UID0003PD disposition: the page was treated as verify-only because it was absent from `validator.ini`. Supervisor command `000000014244` registered it, and waited command `000000014246` exposed the blank formal as a real UID0003PD Empty Emitter Marker. That former no-change conclusion is superseded, not erased.
- Current applied UID0003PD: `91/94`, owner/emitter UID0000LC, reconstructable true, blank position, `Nested:0`, exact covered-by formal, exact 20-byte/hash and xref/source-use evidence; clean scoped validator `000000014248`.
- UID0003UU, UID000084, UID0000LA, UID0000RL, UID0001PJ, Pane, GrafPort, RectBounds, LObject, EventHandler, and TimerHandler remain same-or-greater verify-only support.
- Historical command `000000014231` remains accepted MessageShowPane callback proof. B002 command `000000014249` is the final waited UID0003PD repair proof. Latest observed concurrent command `000000014262` changes only the two generated provenance header values relative to command `14249`; exact current hashes, normalized semantic hashes, counts, ordering, marker removal, and ABI exclusions are recorded under `Validator Results`.

## Ranked Ownership Analysis

### 1. UID000087 MessageShowPane class

- Evidence for: all three table names and RTTI records name MessageShowPane; constructor/destructor/scalar wrapper write all three views; object layout and methods use one `0x10104` class; primary class-specific slot points to OnPaint.
- Evidence against: none for semantic ownership. The target itself is compiler output and should not emit.
- Decision: retain as semantic `CANONICAL_OWNER`; move source emission to the class/global/method destinations.

### 2. UID0000LB MessageShowPane source file

- Evidence for: contiguous method island, dedicated singleton, dedicated generated source route, exact class/global children, external packet consumer boundary, and no Message model field/API overlap.
- Evidence against: no recovered original source path string; a compact MessageDialogs source file remains historically plausible.
- Decision: use UID0000LB `NexusTK/ui/dialogs/MessageShowPane.cpp` as the reconstruction route. The missing original path string caps confidence but does not justify leaving source blank.

### 3. UID0000LA MessageDialogs

- Evidence for: the predecessor Message class and the broader name family use MessageDialogs.
- Evidence against: MessageShowPane has a separate method island, separate singleton, separate class hierarchy, separate generated file, and external packet consumer. Message model APIs do not participate in overlay rendering.
- Decision: reject as canonical MessageShowPane owner. Preserve Message vtable UID0003PB under UID000084/UID0000LA only.

### 4. UID000088 / UID0000LC MetaMan

- Evidence for: `0x0061fad4` names MetaMan COL, `0x0061fad8` is used by MetaMan lifecycle, RTTI proves Singleton base, and `Meta.dat` follows immediately.
- Evidence against: none for the trailing twelve-byte child or for UID0003PD's MetaMan.cpp source route.
- Decision: UID0004SS is semantic MetaMan compiler support, while UID0003PD remains source-bearing under UID0000LC and is represented through consuming source rather than a standalone object.

### 5. UID0003PD pooled literal range

- Evidence for UID0000LC: both `L"Meta.dat"` references occur in MetaMan persistence methods; current MetaMan docs already own those methods and the broad metadata source route.
- Evidence for a covered-by representation: the same literal is consumed at two use sites, no independent global/static symbol or storage xref exists, and the separately referenced final empty-wide word is generated inside the accepted `m_rows[rowKey].push_back(valueText)` lowering.
- Evidence against a standalone declaration: no pointer table, writable storage, constructor, address-taking source pattern, or original symbol supports `static const wchar_t[]`.
- Decision: retain semantic/source owner and emitter UID0000LC, reconstructable true, blank position, and exact covered-by marker. Do not emit raw bytes, a duplicate filename array, or an explicit container-helper `L""`.

### Proposed new file/grouping, if applicable

- No new source file is required.
- One new exact by-memory compiler-data child was registered as UID0004SS.
- MessageShowPane remains a narrow standalone source module containing one singleton definition, one complete class declaration, constructor, destructor, OnPaint, and SetWrappedText.
- MetaMan remains its existing broad metadata source module.
- MessageDialogs remains owner of Message, not MessageShowPane.

## Source Placement

- Recommended MessageShowPane source route: UID0000LB, `NexusTK/ui/dialogs/MessageShowPane.cpp`.
- Recommended generated order:
  - UID0000RK singleton definition at position `0`.
  - UID000087 complete class declaration at position `10`.
  - UID0004HN constructor at position `20`.
  - UID000492 destructor at position `30`.
  - UID0004HO renamed OnPaint at position `40`.
  - UID0001C4 SetWrappedText at position `50`.
- Header/source reconstruction prose should declare `MessageShowPane` and external `g_pMessageShowPane` for UID0003UU and other cross-source consumers.
- UID0003PC, UID0003PB, UID0004SS, UID0001PX, UID0001C5, UID0001C6, and UID0001C7 emit no source.
- UID00025V and UID0002Y8 remain non-emitting indices.
- Recommended MetaMan route remains UID0000LC `NexusTK/metadata/MetaMan.cpp`; UID000088's current formal class gains the Singleton base and retains existing child insertion/order.
- UID0003PD remains under UID0000LC with blank emitter position. Its formal marker documents that `L"Meta.dat"` is emitted through `MetaMan::LoadMetaDat` and `MetaMan::SaveMetaDatIfDirty`, while the trailing empty-wide literal is compiler/container lowering behind `MetaTable::MaterializeRowsIfNeeded`.
- Rejected placement: handwritten data arrays in MessageShowPane.cpp or MetaMan.cpp.
- Rejected placement: a named `static const wchar_t kMetaDatFilename[]`, raw UTF-16 array, fixed-address alias, or explicit standalone `L""`; current xrefs prove use-site/source-operation coverage instead.
- Rejected placement: MessageShowPane class/method definitions in LivingObjectPane.cpp merely because the packet helper consumes them.
- Remaining source-path uncertainty is only original disk naming, not reconstruction ownership or compile visibility.

## Range / Split / Padding / Reclassification Analysis

### Exact partition

| Range | Bytes | SHA256 | Disposition |
| --- | --- | --- | --- |
| `0x0061fa3c-0x0061fa48` | 12 | `7F890CB7BB9287A9CCB6F96F4300832538C739AB5DCA572490DF0E6EE1C9B1B2` | UID0003PB corrected Message vtable |
| `0x0061fa48-0x0061fad0` | 136 | `461519F451D2F8BA4C3442BA100EA1AEBB3E1396C3C60A02311DFF8E95DDA5DB` | UID0003PC corrected MessageShowPane RTTI/vtables |
| `0x0061fad0-0x0061fadc` | 12 | `FCDDBD933E0EB95CE2C0A77696FC2AA79FAB7502469A0E3DD7C0FAE043DF0679` | new MetaMan vtable child |
| `0x0061fadc-0x0061faf0` | 20 | `7C262FEDC4E6CFA43F5878686E9673B7D7BCBABEB2A27AA9AEB856C0486BB4D9` | UID0003PD: `L"Meta.dat"` plus terminator and a separately referenced empty-wide literal; covered by consuming source |
| `0x0061faf0-0x0061faf8` | 8 | existing UID0003PE | MetaTable compiler data |
| `0x0061faf8-0x0061fafc` | 4 | existing UID0003PF | MidiPlayer COL pointer |

### Callback-safe order

1. UID-preserving rename/path correction of UID0003PC to `0x0061fa48-0x0061fad0`.
2. UID-preserving rename/path correction of UID0003PB to `0x0061fa3c-0x0061fa48`.
3. Serial registration of UID0004SS at `0x0061fad0-0x0061fadc`; validator command `000000014184` assigned the real UID.
4. Update UID00025V child inventory after the three exact paths are stable.
5. Apply source class/method/global/support changes.

This order avoids retaining the current false overlap semantics and never requires a temporary duplicate child at the same final path.

### Padding and compiler data

- The zero dword at `0x0061fad0` is not source-visible MessageShowPane state. It is retained inside the MetaMan compiler-data child as the alignment/prefix immediately before MetaMan's COL.
- No byte in the corrected MessageShowPane target is padding; it is one COL pointer plus 18 slots, one COL pointer plus 11 slots, and one COL pointer plus two slots.
- No byte in UID0003PD is padding. The filename occupies `0x0061fadc-0x0061faec`, its terminator occupies `0x0061faec-0x0061faee`, and the final word at `0x0061faee-0x0061faf0` has a live code xref from old-MSVC row insertion lowering.
- No split is needed inside OnPaint or the source methods.
- No class-specific EventHandler or TimerHandler body is missing; their tables contain inherited defaults plus compiler adjustors.

## Negative Evidence Summary

- No direct code caller reaches OnPaint, but the primary vtable cell provides exact liveness. This rejects dead/raw-helper classification.
- No code xref reaches COL pointer cells, which is normal RTTI data and does not weaken class identity.
- No MessageShowPane-specific EventHandler or TimerHandler target appears in the secondary/tertiary tables.
- No separate MessageShowPane source field exists for EventHandler or TimerHandler; Pane layout already owns those views.
- No source statement is needed for any vptr store, COL pointer, table slot, adjustor, scalar delete flag, object size guard, EH cookie, or base destructor call.
- No evidence supports a fourth Message slot at `0x0061fa48`.
- No evidence supports MessageShowPane ownership of `0x0061fad0-0x0061fadc`.
- No evidence supports folding `Meta.dat` backward over MetaMan vtable data.
- No evidence supports a standalone named `Meta.dat` array: both filename xrefs are direct persistence-method uses, and no independent storage/pointer-table/initializer route exists.
- No evidence supports treating the final UID0003PD word as alignment; the `0x00524b01` xref proves it is live.
- No evidence supports hand-authoring an explicit empty-string declaration for MetaTable; the accepted source-level operation is container insertion and the literal appears inside compiler/library lowering.
- No evidence supports a child-button collection in OnPaint; all observed calls are direct GrafPort/RectBounds drawing helpers.
- No evidence supports manual singleton publication/clear after RTTI identifies the direct Singleton base and comparator classes establish inlined base semantics.
- The old `g_pExtendedUIPane` alias describes no separate storage or consumer family and is rejected as current naming.
- The old FittingRoomDownloadControlPane owner for SetWrappedText has no current caller/layout support and remains rejected historical pollution.
- The absence of an original PDB/source path string prevents claiming the exact original filename, but it does not block the current standalone source placement.

## IDA Rename / Type / Comment Recommendations

- No IDA mutation was requested or performed in either report-first research or the implementation callback.
- Source-facing rename recommendation for `0x00522030`: `MessageShowPane::OnPaint`.
- Source-facing class type: `MessageShowPane : public Pane, public Singleton<MessageShowPane>`.
- Source-facing object fields: `m_messageText`, `m_lineCount`, `m_wrappedLineCount`, and `m_maxTextWidth`.
- Source-facing singleton: `g_pMessageShowPane`.
- Source-facing inherited primary slot `0x0041d680`: descriptive `Pane::OnDrawStyleChanged(int style, int value, int flags)` direction, explicitly inherited and not a MessageShowPane override. Exact original spelling is not claimed.
- Source-facing MetaMan type correction: `MetaMan : public Singleton<MetaMan>`.
- Documentation comments should name all three MessageShowPane views, exact adjusted offsets, compiler adjustors, inherited handler methods, and the MetaMan boundary.
- UID0003PD source-facing literal spelling is exactly `L"Meta.dat"`. The interior IDA label `aAt_2` is retained only as an IDA artifact and is not recommended as a source symbol.
- Items intentionally left unchanged in IDA: current decorated vtable/COL symbols, Message/MetaMan type names, packet helper source owner, MetaTable, and MidiPlayer successor data. No IDA mutation was required for UID0003PD.

## First-Draft C++ Recommendation

All accepted C++ appears only in the exact destination-specific managed blocks below. The callback installed these blocks byte-for-byte; class Destinations 5 and 12 both close with `};` before `[[CHILDREN]]`.

### Destination 1 - UID0003PC corrected MessageShowPane vtable data

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the corrected range is exclusively COL pointers and vtable slots. Every slot is caused by the MessageShowPane/Pane/Singleton declaration or inherited base declarations. Handwritten arrays would duplicate compiler ABI output.

### Destination 2 - UID0003PB corrected Message vtable data

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the corrected range is the three-slot Message vtable caused by UID000084's class declaration. The removed fourth dword is the next class's COL pointer.

### Destination 3 - UID0004SS MetaMan vtable data

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the range contains alignment, a COL pointer, and one deleting-destructor slot generated by UID000088's virtual destructor and Singleton base declaration.

### Destination 4 - UID00025V mixed parent

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the parent crosses Message, MessageShowPane, MetaMan, MetaTable, string, and MidiPlayer ownership and remains an inventory only.

### Destination 5 - UID000087 MessageShowPane class

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MessageShowPane;
extern MessageShowPane *g_pMessageShowPane;

class MessageShowPane : public Pane,
                        public Singleton<MessageShowPane>
{
public:
    explicit MessageShowPane(wchar_t *messageText);
    virtual ~MessageShowPane();

protected:
    virtual void OnPaint();

public:
    void SetWrappedText(wchar_t *messageText);

private:
    wchar_t m_messageText[0x8000];
    int m_lineCount;
    int m_wrappedLineCount;
    int m_maxTextWidth;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0004HN MessageShowPane constructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MessageShowPane::MessageShowPane(wchar_t *messageText)
    : Pane(1),
      Singleton<MessageShowPane>(),
      m_lineCount(0),
      m_wrappedLineCount(0),
      m_maxTextWidth(0)
{
    wcscpy_s(m_messageText, 0x8000, messageText);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, messageText);

    wchar_t *lineStart = textCopy;
    wchar_t *lineEnd = wcsstr(lineStart, g_wszNewline);
    while (lineEnd != NULL)
    {
        *lineEnd = 0;
        ++m_lineCount;
        ++m_wrappedLineCount;

        const int lineWidth = GetTextWidth(lineStart);
        if (m_maxTextWidth < lineWidth)
            m_maxTextWidth = lineWidth;

        m_wrappedLineCount += (lineWidth - 1) / 288;
        lineStart = lineEnd + 1;
        lineEnd = wcsstr(lineStart, g_wszNewline);
    }

    ++m_lineCount;
    ++m_wrappedLineCount;

    const int finalLineWidth = GetTextWidth(lineStart);
    if (m_maxTextWidth < finalLineWidth)
        m_maxTextWidth = finalLineWidth;

    m_wrappedLineCount += (finalLineWidth - 1) / 288;

    if (m_maxTextWidth > 288)
        m_maxTextWidth = 288;

    RectBounds bounds;
    bounds.left = 806 - m_maxTextWidth;
    bounds.top = 10;
    bounds.right = 809;
    bounds.bottom = 3 * (m_lineCount + 4 * m_wrappedLineCount + 3);
    AddToLayer(&bounds, 0, 0, g_pRenderLayer1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID000492 MessageShowPane destructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MessageShowPane::~MessageShowPane()
{
    RemoveFromLayer();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID0004HO renamed MessageShowPane OnPaint

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MessageShowPane::OnPaint()
{
    RectBounds lineBounds;
    GetBounds(&lineBounds);
    SetDrawColor(0);
    FillRect(&lineBounds);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, m_messageText);

    wchar_t *lineStart = textCopy;
    wchar_t *lineEnd = wcsstr(lineStart, g_wszNewline);
    while (lineEnd != NULL)
    {
        *lineEnd = 0;

        const int lineWidth = GetTextWidth(lineStart);
        const int lineAdvance = 12 * ((lineWidth - 1) / 288) + 12;
        const int textLength = static_cast<int>(wcslen(lineStart));

        RectBounds textBounds = lineBounds;
        textBounds.right -= 3;
        textBounds.bottom = textBounds.top + lineAdvance + 2;

        SetTextColor(143);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(-2, 1);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(3, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(-2, 1);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);

        SetTextColor(128);
        textBounds.Offset(-1, -1);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);

        lineBounds.Offset(0, lineAdvance + 3);
        lineStart = lineEnd + 1;
        lineEnd = wcsstr(lineStart, g_wszNewline);
    }

    const int lineWidth = GetTextWidth(lineStart);
    const int lineAdvance = 12 * ((lineWidth - 1) / 288) + 12;
    const int textLength = static_cast<int>(wcslen(lineStart));

    RectBounds textBounds = lineBounds;
    textBounds.right -= 3;
    textBounds.bottom = textBounds.top + lineAdvance + 2;

    SetTextColor(143);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(-2, 1);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(3, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(-2, 1);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);

    SetTextColor(128);
    textBounds.Offset(-1, -1);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - UID0001C4 MessageShowPane SetWrappedText

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MessageShowPane::SetWrappedText(wchar_t *messageText)
{
    RemoveFromLayer();

    m_lineCount = 0;
    m_wrappedLineCount = 0;
    m_maxTextWidth = 0;

    wcscpy_s(m_messageText, 0x8000, messageText);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, messageText);

    wchar_t *lineStart = textCopy;
    wchar_t *lineEnd = wcsstr(lineStart, g_wszNewline);
    while (lineEnd != NULL)
    {
        *lineEnd = 0;
        ++m_lineCount;
        ++m_wrappedLineCount;

        const int lineWidth = GetTextWidth(lineStart);
        if (m_maxTextWidth < lineWidth)
            m_maxTextWidth = lineWidth;

        m_wrappedLineCount += (lineWidth - 1) / 288;
        lineStart = lineEnd + 1;
        lineEnd = wcsstr(lineStart, g_wszNewline);
    }

    ++m_lineCount;
    ++m_wrappedLineCount;

    const int finalLineWidth = GetTextWidth(lineStart);
    if (m_maxTextWidth < finalLineWidth)
        m_maxTextWidth = finalLineWidth;

    m_wrappedLineCount += (finalLineWidth - 1) / 288;

    if (m_maxTextWidth > 288)
        m_maxTextWidth = 288;

    RectBounds bounds;
    bounds.left = 806 - m_maxTextWidth;
    bounds.top = 10;
    bounds.right = 809;
    bounds.bottom = 3 * (m_lineCount + 4 * m_wrappedLineCount + 3);
    AddToLayer(&bounds, 0, 0, g_pRenderLayer1);
    InvalidateRect(&m_visibleBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10 - UID0000RK singleton definition

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MessageShowPane;
MessageShowPane *g_pMessageShowPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11 - UID0001PX exact singleton storage

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: this page is the four-byte binary backing slot for the sole definition emitted by UID0000RK. Emitting from both pages would violate one-definition policy.

### Destination 12 - UID000088 MetaMan class

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <map>

class SimpleUString;
class MetaTable;

class MetaMan : public Singleton<MetaMan>
{
public:
    MetaMan();
    virtual ~MetaMan();

    int LoadMetaDatAndRequestSync();
    bool HandleMetaPacket(const unsigned char *packet);

    unsigned int GetValueCount(const SimpleUString *tableName,
                               const SimpleUString *rowKey);
    const SimpleUString *FindEntry(const SimpleUString *tableName,
                                   const SimpleUString *rowKey,
                                   unsigned int valueIndex);
    bool LoadStatValues(const SimpleUString *tableName,
                        const SimpleUString *rowKey,
                        wchar_t ***outValues,
                        int valueCount);
    MetaTable *FindTableByName(const SimpleUString *tableName);

private:
    typedef std::map<SimpleUString, MetaTable *> TableMap;

    void ClearTables();
    void LoadMetaDat();
    void SaveMetaDatIfDirty();

    TableMap m_tables;
    unsigned int m_pendingTableRequests;
    bool m_synchronized;
    bool m_dirty;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The formal class remains `0x14` bytes because EBO overlaps the empty Singleton base with the first map state at `+0x04`.

### Destination 13 - UID0002Y8 method aggregate

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: exact source method children and compiler-support children carry every subrange; the aggregate must not duplicate them.

### Destination 14 - UID0001C5 constructor EH cleanup

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: this is constructor-unwind duplication of `Singleton<MessageShowPane>` cleanup and has no ordinary source-call route.

### Destination 15 - UID0001C6 destructor adjustor thunks

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the two 11-byte thunks adjust `this` by `-0xa0` and `-0xa4` and jump to the generated scalar wrapper.

### Destination 16 - UID0001C7 scalar deleting destructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: this wrapper duplicates ordinary/base teardown and adds delete flags, optional storage release, return-this ABI, and the `0x10104` size guard. Source is the virtual ordinary destructor declaration/body.

### Destination 19 - UID0003PD MetaDatFilenameString

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted source for L"Meta.dat" is covered by MetaMan::LoadMetaDat and
// MetaMan::SaveMetaDatIfDirty. The trailing empty-wide literal is covered by
// MetaTable::MaterializeRowsIfNeeded's m_rows[rowKey] insertion lowering.
// Do not emit a standalone string array or raw bytes for this pooled range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact source/no-code proof: the filename bytes are regenerated by the two
MetaMan use-site literals, while the final empty-wide word is old-MSVC
container lowering behind the accepted MetaTable insertion operation. The
managed marker prevents a validator Empty Emitter Marker without introducing a
duplicate named constant, raw byte array, fixed-address object, or explicit
compiler-helper literal.

## Final Recommendation

- Destinations 1-18 remain applied, UID0003PD is applied as Destination 19, and the remaining dependencies are verified as Destination 20.
- Preserve target UID0003PC and semantic owner UID000087 while correcting path/range and making the compiler-data page non-emitting.
- Preserve UID0003PB and UID00025V while correcting the child partition.
- Exactly one new MetaMan vtable-data child was registered as UID0004SS; no second MessageShowPane or Meta.dat child was created.
- Complete MessageShowPane source through UID0000LB with one global, one class, and four source method definitions in deterministic order.
- Preserve all exact behavior in constructor, destructor, OnPaint, and SetWrappedText while removing compiler/base lowering.
- Preserve UID0003UU as an external consumer, not owner.
- Only the direct Singleton base was added to the existing complete MetaMan declaration; its API and fields remain preserved.
- Preserve UID0003PD as source-bearing under UID0000LC at `91/94` with blank position and an exact covered-by marker. The source is `L"Meta.dat"` at the two persistence-method use sites plus compiler/container lowering for the final empty-wide code unit, not a standalone string object.
- Leave compiler data, EH cleanup, adjustors, and scalar wrappers non-emitting.
- There is no in-scope unresolved blocker requiring future research. Exact original spelling of the inherited draw-style base virtual remains a documented descriptive-name confidence cap only.

## Recommended Target Doc Changes

The accepted Destination 1 contract below is the current applied state, validated by command `000000014180`.

### Destination 1 - UID0003PC

- UID-preserving rename to `by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md`.
- Set `92/94`.
- Retain `CANONICAL_OWNER:000087`.
- Set `RECONSTRUCTABLE:FALSE`.
- Blank `EMITTER_UIDS`, position, and formal C++.
- Retain `Nested:0`.
- Replace range/body with exact bytes/hash, three COL/table extents, complete slot maps, RTTI/PMD, store triads, compiler/source handling, MetaMan successor, negative evidence, and no-code proof.
- Historicalize the former `0x0061fa4c-0x0061fadc` range and hash as superseded.

## Recommended Support Doc Changes

The accepted Destinations 2-18 remain applied. Destination 19 is the completed
UID0003PD Gate 2 repair. Destination 20 is the remaining verify-only reread.

### Destination 2 - UID0003PB MessageVtableData

- UID-preserving rename to `by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md`.
- Set `90/93`, semantic owner UID000084, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, `Nested:0`.
- Record exactly three slots and exclude the MessageShowPane COL pointer.

### Destination 3 - UID0004SS MetaManVtableData

- Serially register `by-memory/0x0061fad0-0x0061fadc.MetaManVtableData.md`.
- Recommended `91/94`, `CANONICAL_OWNER:000088`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, `Nested:0`.
- Record exact bytes/hash, alignment dword, COL, one slot, MetaMan RTTI/Singleton base, lifecycle triad, scalar-wrapper no-code proof, and `Meta.dat` successor.

### Destination 4 - UID00025V MessageShowReadOnlyData

- Raise `87/91 -> 90/94`.
- Retain none/false/blank metadata and blank formal.
- Replace child table with corrected UID0003PB, corrected UID0003PC, real UID0004SS, UID0003PD, UID0003PE, and UID0003PF. The child inventory remains exact; UID0003PD's later source/no-code repair does not change this parent range.
- Preserve mixed-owner/index and source-generated compiler-data policy.

### Destination 5 - UID000087 MessageShowPane

- Raise `86/88 -> 92/94`.
- Retain owner UID0000LB, reconstructable true, emitter UID0000LB.
- Set position `10`.
- Install exact class formal.
- Add exact inheritance, EBO, `0x10104` layout, all three views, complete slot declarations, method order, compiler exclusions, source route, packet consumer, history, and score rationale.

### Destination 6 - UID0004HN constructor

- Raise `89/91 -> 92/94`.
- Set position `20`.
- Install exact constructor formal.
- Preserve all behavior, callers, hashes, fields, wrap math, bounds, layer attach, EH, and negative evidence.
- Historicalize manual singleton publication, PaneRect, and MeasureTextWidth.

### Destination 7 - UID000492 destructor

- Raise `89/91 -> 92/94`.
- Set position `30`.
- Install one-statement destructor formal.
- Preserve observed singleton clear as implicit base destruction and preserve vptr/base/scalar history.

### Destination 8 - UID0004HO OnPaint

- UID-preserving rename/path correction to `by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md`.
- Raise `88/90 -> 92/94`.
- Set position `40`.
- Install exact OnPaint formal.
- Replace child-button helper fiction with direct GrafPort/RectBounds behavior while preserving exact passes/constants/offsets/range/padding/vtable-only liveness.

### Destination 9 - UID0001C4 SetWrappedText

- Raise `88/91 -> 92/94`.
- Set position `50`.
- Install corrected formal.
- Preserve sole packet caller and exact wrap/layout behavior.
- Historicalize PaneRect, MeasureTextWidth, and `m_bounds`.

### Destination 10 - UID0000RK g_pMessageShowPane

- Raise `88/90 -> 92/94`.
- Retain owner/emitter UID0000LB and reconstructable true.
- Set position `0`.
- Install sole external-linkage definition.
- Add header extern/source-placement and Singleton specialization/backing-storage explanation.

### Destination 11 - UID0001PX storage

- Raise `86/92 -> 91/94`.
- Retain `CANONICAL_OWNER:0000RK`.
- Set `RECONSTRUCTABLE:FALSE`.
- Blank emitter/position/formal; retain `Nested:0`.
- Preserve exact storage/xrefs/alias history and record covered-by one-definition route.

### Destination 12 - UID000088 MetaMan

- Raise `89/88 -> 91/93`.
- Retain owner/emitter UID0000LC and reconstructable true.
- Install exact current class union with `Singleton<MetaMan>` base and `[[CHILDREN]]`.
- Preserve all current map/API/layout/packet/helper/compiler history.

### Destination 13 - UID0002Y8 method aggregate

- Raise `88/91 -> 90/93`.
- Retain semantic owner UID000087, false/non-emitting/blank metadata.
- Replace source inventory name with OnPaint and positions `20/30/40/50`.
- Preserve exact compiler child ranges and no-duplicate policy.

### Destination 14 - UID0001C5 EH cleanup

- Raise `88/92 -> 90/94`.
- Retain none/false/blank metadata.
- Add Singleton base/unwind source-cause and preserve exact range/bytes/negative evidence.

### Destination 15 - UID0001C6 adjustors

- Raise `88/92 -> 91/94`.
- Retain none/false/blank metadata.
- Add exact view offsets, COL parity, and source virtual-destructor cause.

### Destination 16 - UID0001C7 scalar wrapper

- Raise `88/92 -> 91/94`.
- Retain none/false/blank metadata.
- Preserve wrapper behavior and update ordinary destructor source to one statement with Singleton clear implicit.

### Destination 17 - UID0000LB MessageShowPane file

- Raise `86/87 -> 92/93`.
- Retain `NexusTK/ui/dialogs/`.
- Record complete one-global/one-class/four-method order, full range split, exact dependencies, compiler exclusions, header extern route, and rejected MessageDialogs placement.
- Remove current open split/helper blockers from present-tense status and preserve them as superseded history.
- Do not add by-file reconstruction metadata.

### Destination 18 - UID0000LC MetaMan file

- Raise `91/90 -> 92/93`.
- Preserve all current content and route.
- Add MetaMan Singleton base/EBO and new vtable-data child to inventory/compiler-source policy.
- Do not add by-file reconstruction metadata.

### Destination 19 - UID0003PD MetaDatFilenameString

- Raise `86/90 -> 91/94`.
- Retain `CANONICAL_OWNER:0000LC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LC`, blank emitter position, and `Nested:0`.
- Install the exact managed covered-by block from the First-Draft section.
- Record exact 20-byte/hash evidence, the two `L"Meta.dat"` xrefs and persistence-method behaviors, the separate final empty-wide xref and MetaTable insertion lowering, exact parent/successor boundaries, source route, rejected static/raw/split/false alternatives, and score rationale.
- Do not emit a standalone filename array, raw bytes, fixed-address alias, explicit container-helper empty string, or duplicate source object.
- Scoped validator `000000014248` passed cleanly; waited command `000000014249` removed the UID0003PD Empty Emitter Marker.

### Destination 20 - verify-only dependencies

- Reread completed for UID0003UU, UID000084, UID0000LA, UID0000RL, UID0001PJ, Pane, GrafPort, RectBounds, LObject, EventHandler, TimerHandler, and current generated MetaMan.cpp.
- No concrete contradiction was found; all Destination 20 ordinary pages remain unchanged.

## Score And Metadata Recommendation

| Destination | Evidence-time / pre-callback | Applied | Metadata result |
| --- | --- | --- | --- |
| UID0003PC | `86/90`, owner/emitter UID000087, true | `92/94` | owner UID000087, false, blank emitter/position/formal, Nested 0 |
| UID0003PB | `86/90`, owner/emitter UID000084, true, Nested 8 | `90/93` | owner UID000084, false, blank emitter/position/formal, Nested 0 |
| UID0004SS | absent before callback | `91/94` | real UID registered by command `000000014184`; owner UID000088, false, blank emitter/position/formal, Nested 0 |
| UID00025V | `87/91` | `90/94` | retain none/false/blank |
| UID000087 | `86/88` | `92/94` | retain owner/emitter UID0000LB, true; position 10 |
| UID0004HN | `89/91` | `92/94` | retain owner/emitter UID000087, true; position 20 |
| UID000492 | `89/91` | `92/94` | retain owner/emitter UID000087, true; position 30 |
| UID0004HO | `88/90` | `92/94` | retain owner/emitter UID000087, true; position 40; rename |
| UID0001C4 | `88/91` | `92/94` | retain owner/emitter UID000087, true; position 50 |
| UID0001C5 | `88/92` | `90/94` | retain none/false/blank |
| UID0001C6 | `88/92` | `91/94` | retain none/false/blank |
| UID0001C7 | `88/92` | `91/94` | retain none/false/blank |
| UID0000RK | `88/90` | `92/94` | retain owner/emitter UID0000LB, true; position 0 |
| UID0001PX | `86/92`, owner/emitter UID0000RK, true | `91/94` | retain owner UID0000RK; false; blank emitter/position/formal |
| UID0002Y8 | `88/91` | `90/93` | retain owner UID000087, false, blank |
| UID0000LB | `86/87` | `92/93` | retain file path/owner |
| UID000088 | `89/88` | `91/93` | retain owner/emitter UID0000LC, true |
| UID0000LC | `91/90` | `92/93` | retain file path/owner |
| UID0003PD | `86/90`, owner/emitter UID0000LC, true, blank position | `91/94` | retain owner/emitter UID0000LC, true, blank position, Nested 0; exact covered-by formal |

Score-improvement blockers removed:

- Incorrect start and end boundaries: removed by exact byte/COL split.
- Unnamed or generic slots: all slots now have exact source declarations, compiler dispositions, or one explicit best descriptive inherited declaration.
- Missing inheritance: removed by RTTI/PMD direct-base reconstruction.
- Missing class layout: removed by EBO, fields, and size-guard parity.
- Missing class formal: removed by complete declaration.
- Stale OnPaint identity and helpers: removed by vtable/body/support reanalysis.
- Singleton source contradiction: removed by direct-base lowering and one-definition route.
- Blank global/storage emitters: removed by sole global definition and non-emitting storage.
- MetaMan tail ambiguity: removed by exact child and direct Singleton base.
- UID0003PD blank-emitter contradiction: removed by exact bytes/hash, source-use xrefs, compiler-lowered empty-tail disposition, covered-by formal, clean scoped validation, and current generated marker absence.
- File placement blocker: removed by source-island/global/consumer analysis.
- Scores remain below 95 because exact original source path, private access spelling, and inherited draw-style lexical name are not recoverable from current binary. Those are polish caps, not behavioral or implementation blockers.

## Open Questions With Attempted Resolution

- Does UID0003PC begin at the vtable base or primary COL pointer?
  - Checked bytes, decorated names, RTTI, and peer vtable page conventions.
  - Resolution: include the COL pointer; corrected start is `0x0061fa48`.
- Does UID0003PC extend to `Meta.dat`?
  - Checked all dwords and MetaMan lifecycle xrefs.
  - Resolution: no; corrected end is `0x0061fad0`.
- Is `0x0061fad0-0x0061fadc` padding or source literal?
  - Checked zero/COL/slot values, RTTI, scalar wrapper, and successor string.
  - Resolution: a distinct MetaMan compiler-data child containing one alignment dword plus RTTI/vtable cells.
- Does MessageShowPane directly derive from EventHandler and TimerHandler?
  - Checked RTTI hierarchy and PMD offsets against Pane layout.
  - Resolution: no; Pane supplies those subobjects. Direct bases are Pane and Singleton.
- Is `0x00522030` a child-button builder?
  - Checked vtable slot, direct callees, field behavior, and peer paint conventions.
  - Resolution: no; it is `void MessageShowPane::OnPaint()`.
- Should source manually write/clear `g_pMessageShowPane`?
  - Checked Singleton RTTI, store order, EH cleanup, reverse destruction, and comparator accepted classes.
  - Resolution: no; those are inlined Singleton base effects.
- Should the global be static or external?
  - Checked external UID0003UU direct use and current source placement.
  - Resolution: external definition and header extern are required for compile-visible cross-source use.
- Is MessageDialogs the better source file?
  - Checked method island, globals, generated roots, packet boundary, and predecessor Message ownership.
  - Resolution: no; use standalone MessageShowPane.cpp.
- What is the exact original name of inherited slot `0x0041d680`?
  - Checked bytes, ABI, hundreds of vtable refs, Pane/GrafPort/vtable docs, peer reports, and absence of code callers.
  - Resolution: exact original lexical name is not recoverable. The strongest source-facing descriptive contract is a three-argument Pane/GrafPort draw-style notification, `OnDrawStyleChanged(int style, int value, int flags)`. It is inherited, no-op, and not required in the MessageShowPane class declaration. This isolated lexical cap does not reduce target behavior or C++ readiness.
- Does MetaMan directly derive from Singleton?
  - Checked RTTI CHD/PMD and lifecycle.
  - Resolution: yes; add the base without changing size or fields.
- Is UID0003PD a named static filename constant, a raw string object, or use-site literal output?
  - Checked exact bytes/hash, both filename xrefs, persistence-method call shapes, current MetaMan source route, and absence of independent storage/symbol/xrefs.
  - Resolution: use-site pooled `L"Meta.dat"` source covered by the two MetaMan methods; do not emit a standalone declaration.
- Are the final two UID0003PD bytes padding?
  - Checked exact xrefs at `0x0061faec`, `0x0061faee`, and `0x0061faf0`, plus disassembly of `0x00524b01`.
  - Resolution: no. The final word is a separately referenced empty-wide literal created by old-MSVC row insertion lowering behind `m_rows[rowKey].push_back(valueText)`.
- No in-scope question remains unresolved in a way that blocks range, score, source placement, metadata, or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual files listed under `Evidence Checked` were read only at report-first,
callback, and Gate 2 repair epochs. Current direct row readback proves the
accepted Destinations 1-18 coverage text below is already present in the
current union. It is retained verbatim as historical handoff/provenance and
no-loss comparison text. UID0003PD alone remains stale at `86%`; its exact
current supervisor-owned replacement is the UID0003PD line in the by-memory
block below. B002 must not apply that remaining row directly.

### `by-memory/-coverage-report.md`

Historical accepted block, now already present byte-for-byte:

```text
        - [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md) 0x00521da0-0x005227c6 | non-emitting method index | MessageShowPaneMethods : ignored : 90% : very-strong : Exact MessageShowPane source inventory with constructor UID0004HN at position 20, destructor UID000492 at 30, OnPaint UID0004HO at 40, SetWrappedText UID0001C4 at 50, and compiler-only EH/adjustor/scalar support UID0001C5/UID0001C6/UID0001C7; the aggregate emits no duplicate source.
            - [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md) 0x00521da0-0x00521fc0 | constructor | MessageShowPane::MessageShowPane : reconstructable : 92% : very-strong : Exact Pane(1) plus Singleton<MessageShowPane> source constructor with implicit singleton publication, 0x8000-wide message storage, newline split, GetTextWidth wrapping, 288-pixel clamp, exact right-edge RectBounds, render-layer attach, one packet-helper caller, generated vptr/EH exclusions, and position 20.
            - [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) 0x00521fc0-0x00522025 | destructor | MessageShowPane::~MessageShowPane : reconstructable : 92% : very-strong : Exact ordinary destructor source contains only RemoveFromLayer; Singleton clear, three vptr restores, Pane teardown, scalar flags, size guard, and storage free are implicit/compiler-generated; position 30.
            - [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md) 0x00522030-0x00522530 | paint override | MessageShowPane::OnPaint : reconstructable : 92% : very-strong : Exact vtable-only OnPaint copies inherited bounds and message text, fills the background, splits on newline, uses GetTextWidth and DrawTextInRect, draws six palette-143 shadow passes and two palette-128 face passes with exact cumulative offsets, advances rows by the observed wrap formula, and emits at position 40.
            - [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) 0x00522530-0x005226ea | method | MessageShowPane::SetWrappedText : reconstructable : 92% : very-strong : Exact existing-overlay update with sole packet-helper caller, RemoveFromLayer, 0x8000-wide copy, newline/GetTextWidth wrap metrics, 288 clamp, RectBounds layer reattach, inherited m_visibleBounds invalidation, and position 50; stale PaneRect/MeasureTextWidth/m_bounds aliases are historical.
            - [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) : ignored : 90% : very-strong : Compiler constructor-unwind cleanup for direct Singleton<MessageShowPane> base; exact clear body remains blank/no-code and is not a handwritten helper.
            - [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) : ignored : 91% : very-strong : Exact compiler deleting-destructor adjustors for EventHandler +0xa0 and TimerHandler +0xa4 views; no handwritten source.
            - [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) : ignored : 91% : very-strong : Exact compiler scalar deleting destructor generated from virtual MessageShowPane destructor and Singleton/Pane bases; preserves vptr restores, implicit singleton clear, base teardown, delete flags, optional free, and 0x10104 size guard as no-code ABI evidence.
```

Historical accepted parent/child block, now already present except for the
UID0003PD line. Replace only the current UID0003PD line with the exact
`91%` line shown here:

```text
    - [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md) 0x0061fa3c-0x0061fafc | mixed .rdata index | MessageShowReadOnlyData : ignored : 90% : very-strong : Exact ownerless non-emitting index over corrected Message vtable UID0003PB, MessageShowPane RTTI/vtables UID0003PC, MetaMan vtable data UID0004SS, Meta.dat UID0003PD, MetaTable vtable UID0003PE, and MidiPlayer COL UID0003PF; every byte is partitioned and compiler/source ownership is carried by exact children.
        - [UID:0003PB][0x0061fa3c-0x0061fa48.MessageVtableData](by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md) 0x0061fa3c-0x0061fa48 | compiler-generated vtable | MessageVtableData : ignored : 90% : very-strong : Exact three-slot Message vtable regenerated from UID000084; corrected end excludes MessageShowPane primary COL at 0x0061fa48.
        - [UID:0003PC][0x0061fa48-0x0061fad0.MessageShowPaneVtableData](by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md) 0x0061fa48-0x0061fad0 | compiler-generated RTTI/vtables | MessageShowPaneVtableData : ignored : 92% : very-strong : Exact primary COL plus 18 slots, EventHandler COL plus 11 slots, TimerHandler COL plus two slots, complete slot/source declaration map, Pane plus Singleton<MessageShowPane> inheritance, +0xa0/+0xa4 views, compiler adjustors/wrapper policy, and corrected end before MetaMan.
        - [UID:0004SS][0x0061fad0-0x0061fadc.MetaManVtableData](by-memory/0x0061fad0-0x0061fadc.MetaManVtableData.md) 0x0061fad0-0x0061fadc | compiler-generated RTTI/vtable | MetaManVtableData : ignored : 91% : very-strong : Exact zero/alignment dword, MetaMan COL pointer, and one scalar-deleting-destructor slot generated from MetaMan plus Singleton<MetaMan>; ends before UTF-16 Meta.dat.
        - [UID:0003PD][0x0061fadc-0x0061faf0.MetaDatFilenameString](by-memory/0x0061fadc-0x0061faf0.MetaDatFilenameString.md) 0x0061fadc-0x0061faf0 | pooled UTF-16 source-use literals | MetaDatFilenameString : reconstructable : 91% : very-strong : Exact 20-byte/hash range with L"Meta.dat" used by MetaMan::LoadMetaDat and MetaMan::SaveMetaDatIfDirty and the final empty-wide code unit used by old-MSVC MetaTable row insertion lowering; owner/emitter UID0000LC, blank position, formal covered-by marker, no standalone raw string array, and no Empty Emitter Marker.
```

Historical accepted UID0001PX row, now already present byte-for-byte:

```text
    - [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md) 0x0069b4f4-0x0069b4f8 | singleton backing storage | g_pMessageShowPane : ignored : 91% : very-strong : Exact four-byte MessageShowPane Singleton backing slot with lifecycle and packet/UI xrefs; sole external source definition is emitted by UID0000RK, while constructor/destructor/EH/scalar writes are direct Singleton<MessageShowPane> lowering and this storage page emits no duplicate C++.
```

### `by-class/-coverage-report.md`

Historical accepted UID000087 and UID000088 rows, now already present
byte-for-byte:

```text
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md) : reconstructable : 92% : very-strong : Complete 0x10104 Pane plus Singleton<MessageShowPane> declaration with EBO-overlapped wchar_t[0x8000] message buffer, three wrap/layout ints, exact primary/EventHandler/TimerHandler views, constructor/destructor/OnPaint/SetWrappedText order, external singleton declaration, packet-helper consumer, and compiler RTTI/vtable/EH/adjustor/scalar exclusions.
- [UID:000088][MetaMan](by-class/MetaMan.md) : reconstructable : 91% : very-strong : Complete 0x14 MetaMan plus Singleton<MetaMan> declaration preserving the accepted std::map table abstraction, packet/cache/API surface, pending/synchronized/dirty fields, compiler vtable/scalar-wrapper policy, and metadata source route.
```

### `by-file/-coverage-report.md`

Historical accepted UID0000LB and UID0000LC rows, now already present
byte-for-byte:

```text
- [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md) : reconstructable : 92% : very-strong : Standalone ui/dialogs MessageShowPane source route with one external singleton definition, complete Pane plus Singleton<MessageShowPane> class, constructor/destructor/OnPaint/SetWrappedText at positions 20/30/40/50, corrected RTTI/vtable partition, exact packet-helper dependency, and no handwritten vtable/EH/adjustor/scalar ABI source.
- [UID:0000LC][MetaMan](by-file/MetaMan.md) : reconstructable : 92% : very-strong : Metadata manager/table source module with complete MetaMan plus Singleton<MetaMan> class route, accepted map/API/cache/packet/helper inventory, exact Meta.dat ownership, and compiler-generated MetaMan RTTI/vtable child separated from MessageShowPane data.
```

### `by-global/-coverage-report.md`

Historical accepted UID0000RK row, now already present byte-for-byte:

```text
- [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) : reconstructable : 92% : very-strong : Sole external MessageShowPane pointer definition in MessageShowPane.cpp at position 0, with exact zero-filled storage UID0001PX, direct Singleton<MessageShowPane> publication/reverse-clear source cause, packet/UI consumers, header extern route, one-definition policy, and stale g_pExtendedUIPane alias preserved only as historical pollution.
```

The current UID0000RL `g_pMetaMan` row was inspected. Its source definition and owner remain valid; no manual row change is required for this report because the direct Singleton base correction is carried by the MetaMan class/file rows and new by-memory child.

### `by-type/-coverage-report.md`

No affected row exists. No by-type page is renamed, rescored, or edited by the accepted plan. This is a read-only no-change result, not an uninspected `not applicable`.

### Tracker ownership

- The validator-owned generated research tracker must not be edited manually.
- Source by-memory metadata/path changes and ordinary scoped validation should refresh generated tracker state after callback.
- Only the supervisor may apply the manual coverage text above.

## Follow-Up Actions

- B002's accepted implementation and Gate 2 repair scope is complete: Destinations 1-18 remain applied, UID0003PD is applied as Destination 19, Destination 20 is verified, all scoped validators passed, final waited generated proof passed, every checklist row is checked, and zero leases remain.
- This same artifact is offered for independent supervisor Gate 2 review. No additional ordinary callback item or source-quality blocker remains.
- The exact remaining UID0003PD manual coverage replacement above remains a supervisor-owned handoff. All other accepted rows were verified already present; B002 did not edit any `-coverage-report.md`.
- Report validation, execution, movement, archive, and path state are supervisor/validator-owned. This report does not assert a present or future lifecycle action as global truth.
- B002 did not start a second target, run `execute_report`, invoke a report lifecycle command, edit generated output manually, or mutate IDA.

## Confidence

- Recommendation confidence: `94/100`.
- Target score confidence: `94/100`.
- Source declaration confidence: `94/100`.
- OnPaint behavior confidence: `95/100`.
- Source filename confidence: `90/100`.
- Remaining uncertainty: exact original disk path, private access-section spelling, and the inherited draw-style virtual's original lexical name. None changes executable behavior, target range, class size, owner/emitter route, or destination C++.

## Validator Results

- IDA MCP read-only research checks succeeded after one corrected `get_bytes` schema retry. No IDA mutation was performed.
- Every changed ordinary page passed one scoped validator under a one-file lease. Each lease was released immediately after that page's validation.

| Command ID | Timestamp | Scoped destination | Exit / ok |
| --- | --- | --- | --- |
| `000000014180` | `2026-07-16T14:38:53-04:00` | UID0003PC corrected target path/range | `0 / 1` |
| `000000014182` | `2026-07-16T14:39:34-04:00` | UID0003PB corrected Message vtable path/range | `0 / 1` |
| `000000014184` | `2026-07-16T14:40:16-04:00` | registered UID0004SS MetaManVtableData | `0 / 1` |
| `000000014192` | `2026-07-16T14:41:48-04:00` | UID00025V six-child partition | `0 / 1` |
| `000000014198` | `2026-07-16T14:43:04-04:00` | UID000087 MessageShowPane class | `0 / 1` |
| `000000014203` | `2026-07-16T14:44:03-04:00` | UID0004HN constructor | `0 / 1` |
| `000000014205` | `2026-07-16T14:45:02-04:00` | UID000492 destructor | `0 / 1` |
| `000000014208` | `2026-07-16T14:46:03-04:00` | UID0004HO OnPaint UID-preserving path correction | `0 / 1` |
| `000000014210` | `2026-07-16T14:46:56-04:00` | UID0001C4 SetWrappedText | `0 / 1` |
| `000000014212` | `2026-07-16T14:47:47-04:00` | UID0000RK singleton definition | `0 / 1` |
| `000000014214` | `2026-07-16T14:48:40-04:00` | UID0001PX non-emitting storage | `0 / 1` |
| `000000014217` | `2026-07-16T14:49:58-04:00` | UID0002Y8 method index | `0 / 1` |
| `000000014223` | `2026-07-16T14:50:36-04:00` | UID0001C5 EH cleanup | `0 / 1` |
| `000000014225` | `2026-07-16T14:51:16-04:00` | UID0001C6 adjustors | `0 / 1` |
| `000000014227` | `2026-07-16T14:51:55-04:00` | UID0001C7 scalar wrapper | `0 / 1` |
| `000000014228` | `2026-07-16T14:53:05-04:00` | UID0000LB MessageShowPane file prose | `0 / 1` |
| `000000014229` | `2026-07-16T14:53:51-04:00` | UID000088 MetaMan class union | `0 / 1` |
| `000000014230` | `2026-07-16T14:54:28-04:00` | UID0000LC MetaMan file prose | `0 / 1` |
| `000000014231` | `2026-07-16T14:55:39-04:00` | final authorized `by-file/MessageShowPane.md --wait-generated` refresh | `0 / 1` |
| `000000014244` | supervisor Gate 2 epoch before `2026-07-16T15:20:00-04:00` audit | registered formerly absent UID0003PD and inserted validator-owned metadata header | `0 / 1` |
| `000000014245` | supervisor Gate 2 epoch before `2026-07-16T15:20:00-04:00` audit | by-memory manual coverage revalidation resolving UID0003PD reference | `0 / 1` |
| `000000014246` | `2026-07-16T15:19:33-04:00` | supervisor final waited refresh exposing UID0003PD Empty Emitter Marker | `0 / 1` |
| `000000014247` | `2026-07-16T15:27:23-04:00` | initial UID0003PD repair validation; accepted source/no-code disposition but reported unstable successor UID label | `0 / 1` |
| `000000014248` | `2026-07-16T15:27:43-04:00` | clean scoped UID0003PD validation after removing only the unstable successor UID label | `0 / 1` |
| `000000014249` | `2026-07-16T15:28:07-04:00` | final authorized `by-file/MetaMan.md --wait-generated` refresh | `0 / 1` |

- Commands `000000014180` and `000000014182` propagated stable UID/path links and reported temporary adjacent missing-registry references while the serial child split was incomplete. Registration command `000000014184` and parent command `000000014192` resolved the accepted target partition.
- Historical callback command `000000014231` completed the accepted Destinations 1-18 generated refresh. Supervisor commands `000000014244-000000014246` later proved the former UID0003PD verify-only conclusion false by registering the page and exposing its Empty Emitter Marker.
- Initial repair command `000000014247` reported one `missing_ref_uid` warning for an unstable successor UID label. B002 removed only that label, retained the exact successor path/range and all accepted source evidence, and clean command `000000014248` passed.
- B002 final waited command `000000014249` completed the repair generated refresh. Its unrelated repository-wide warnings were `autogen_children_fallback_insert:13`, `autogen_children_marker_missing:84`, `autogen_emitter_has_no_code:143`, and `generated_metadata_refresh:280`; none identifies UID0003PC, UID0003PD, MessageShowPane, or MetaMan as defective. Side effects were validator-owned generated/tracker/registry refreshes only; B002 did not manually edit those files.
- Latest observed generated header epoch is concurrent command `000000014262`, refreshed `2026-07-16T15:36:53-04:00`. Replacing only its command/timestamp header lines with the command `14249` values reproduces the exact B002 hashes for both generated files, proving no semantic/body drift after B002's waited verification.

Current generated MessageShowPane proof:

- Path: `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`.
- Latest observed header: command `000000014262`, refreshed `2026-07-16T15:36:53-04:00`.
- Current SHA256 `327C35D019AF9D1B2DC1E86A59A5A0BBB09259AF81C72C8F51B74758C0AA3254`, 6,840 bytes, 220 lines.
- Header-normalized-to-command-14249 SHA256 `B9006053DF2F4C3E546AFA339F9162626554ACFCF4F7F9CB22D5614183738545`, exactly equal to the B002 waited artifact.
- Exact counts: class definition `1`, external singleton definition `1`, constructor `1`, destructor `1`, OnPaint `1`, SetWrappedText `1`, BuildMessageTextButtons `0`, Empty Emitter Marker `0`, handwritten vtable/RTTI `0`, adjustor source `0`, scalar-wrapper source `0`.
- Exact order: global line 9, class line 15, constructor line 36, destructor line 86, OnPaint line 92, SetWrappedText line 171.
- No UID000087, UID0003PC, UID0000RK, or UID0001PX Empty Emitter Marker remains; no duplicate global or method definition remains.

Current generated MetaMan proof:

- Path: `auto-generated/NexusTK/metadata/MetaMan.cpp`.
- Latest observed header: command `000000014262`, refreshed `2026-07-16T15:36:53-04:00`.
- Current SHA256 `5092B7E9777DE314BA64C4A47CA8D77360011023B06A7E87401EEDD40E6F52BA`, 12,391 bytes, 323 lines.
- Header-normalized-to-command-14249 SHA256 `58379505CA2C8EDEF5FD79A7DBABC37BEA23D02EA87B4130F2F0363630A9FEA8`, exactly equal to the B002 waited artifact.
- Exact structural readback: one `class MetaMan : public Singleton<MetaMan>` at line 13, its closing `};` at line 44 before generated child output, one `MetaMan *g_pMetaMan = 0;` at line 190, one UID0003PD covered-by comment at lines 309-313, zero UID0003PD Empty Emitter Markers, zero Empty Emitter Markers overall, zero UID0004SS marker output, and no vtable/RTTI/adjustor definitions.
- Exact source-data exclusion readback: one textual `L"Meta.dat"` occurrence exists only inside the covered-by comment; standalone/static `Meta.dat` declarations `0`, raw filename arrays `0`, fixed-address aliases `0`, and explicit standalone empty-wide declarations `0`.
- The two textual `scalar deleting` matches are explanatory no-code comments at lines 162 and 195; neither is a declaration or definition. No handwritten scalar-wrapper ABI source is emitted.
- Manual coverage remained read-only. No report lifecycle validator, `execute_report`, probe, move, or archive command was run.

## Changed Files

- Updated same report: `tools/leaser/Agents/Agent-B002/research/0003PC-MessageShowPaneVtableData-source-quality.md`.
- Modified ordinary files: the 18 accepted callback destinations plus the bounded UID0003PD Gate 2 repair listed below. UID-preserving path corrections were used for UID0003PC, UID0003PB, and UID0004HO; one new ordinary page was registered as UID0004SS.
- Each ordinary page had one short serial lease and one scoped validator. Every B002 lease was released immediately after validation; final current lease readback shows zero B002 leases.
- Manual coverage, generated output, tracker, audit, supervisor, validator-owned state, IDA, and lifecycle/archive files were not manually edited by B002.

Final changed ordinary hashes:

| Path | SHA256 | Bytes | Lines |
| --- | --- | --- | --- |
| `by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md` | `CD5024AE8FAA00E6C3CE60F025011D51DE5AC4F345B0F8A3F5DCFB590F3077A5` | 12,616 | 144 |
| `by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md` | `E29D55252638C71160561FA9741FD431DBC734A3793234D071E8FBA0E2993E98` | 5,544 | 71 |
| `by-memory/0x0061fad0-0x0061fadc.MetaManVtableData.md` | `581CFEB1C39170DD6E078C101DD05960819FC1014D08A7CCAD982A8C6FB62F87` | 5,820 | 83 |
| `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md` | `5EC14A4BB940EC644814821F2A881048BAC6CA9164F17A7A340B741A1F17D52C` | 12,989 | 100 |
| `by-class/MessageShowPane.md` | `A8BDAA0851633CDDA20AA92FE4CAE99FD12A41FEC0CE72A9B8899F35F4A02187` | 18,235 | 138 |
| `by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md` | `C24FC5B36CCA9FD70CB11AE3B707F6F47290D7D0D6C170107C41969E2FDA5966` | 8,758 | 137 |
| `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md` | `1F0CE6C64235BC3CAED8355DE945DAB4F8C51FD84FED7C0874293419FA547D2A` | 9,958 | 119 |
| `by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md` | `708D54D1C3AD9B94542139CBBB46AC11AFE7710C27C78E4CA4950EE4A9712120` | 9,674 | 166 |
| `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md` | `D49244466CAF61BC3D7CEEAB30B50793A9DC30CA77FD68AB59900F50EC57C8AC` | 13,249 | 155 |
| `by-global/g_pMessageShowPane.md` | `E79AEB5022248954B74EE0014F88B82052A43CC14404CF62E1E964CB102BED3E` | 13,505 | 123 |
| `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md` | `4F63D4084E27233CB787100B2C40E64CC81CE7A9E98D00BC53DF5E5177F8E7A8` | 10,721 | 96 |
| `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md` | `BA67E1974EC90F0A398EFE59FE933794C81C0A60055F090CACE7C88F678B6C82` | 13,010 | 101 |
| `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md` | `6ECF9A40B8214E4A68A454B3D0E704613488A15B467134A44AC9D09C8A38CBE6` | 6,307 | 74 |
| `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md` | `1CACA5835F042308F8D9DEDC372B09B92D63A8553C747AAAA10DFC8556152E47` | 6,869 | 74 |
| `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md` | `000C35F308256D1A31AC263C1B831E1019ADAA802038A9A699B28E6291C53774` | 11,964 | 103 |
| `by-file/MessageShowPane.md` | `BD48DB19447BDF67E47706F313416DE1544DCB7E07C1823C87DB6F8B5813C720` | 22,072 | 151 |
| `by-class/MetaMan.md` | `55F6AE041731DBC14E51A694EC00243708FA085088DD086F6DAD8FF4A148C80D` | 21,541 | 227 |
| `by-file/MetaMan.md` | `04ECC3CE7243DB22E9D4358A6D42F3B68E55D97FAF03016B8EB6838B57F06BBA` | 32,051 | 218 |
| `by-memory/0x0061fadc-0x0061faf0.MetaDatFilenameString.md` | `63BE6CEC8B287800AB8436759395E48EE6F59449B1F370A3EFD64F78E42AF9EB` | 10,487 | 170 |

Destination 20 verify-only readback:

| Dependency | SHA256 | Bytes / lines | Result |
| --- | --- | --- | --- |
| UID0003UU `LivingObjectPaneHandleMessageShowPacket` | `519241254BBE6508C32F76FD4916B8EF5CC749F8761965B815B3FEFEB0D0FCBE` | 16,147 / 188 | unchanged external consumer |
| UID000084 `Message` | `3E7C6824B9051E216F247D2E9717E8CFBE9A5226895B51F9DE095FC6ABF037FC` | 20,358 / 215 | unchanged |
| UID0000LA `MessageDialogs` | `A3860E74F5DB88918806F9B2B58FF7B602C4209DCEF90859B76E54E6C89F32A7` | 60,381 / 276 | unchanged |
| UID0000RL `g_pMetaMan` | `9B575DED1DCBBEC35F3155D9B6CA2D4EE5EED2E034887ECD6F1F75DEB6D65195` | 10,493 / 110 | unchanged sole definition |
| UID0001PJ exact `g_pMetaMan` storage | `C927EAED37663E8A0B18CA0E84FBF30E664ED3DA336921B5563C6AB0549E9206` | 9,099 / 79 | unchanged |
| `by-class/Pane.md` | `C0A7AFC85C571E1695E93DE021FB183AE65E70E7E931FED605826945981C52EA` | 20,725 / 175 | unchanged |
| `by-class/GrafPort.md` | `F1AD63407DAD2CCE4891E755A9F6271F259D3BEB40E9780A74A250A52B16053C` | 61,379 / 308 | unchanged |
| `by-type/by-struct/RectBoundsLayout.md` | `3FC01A6E920DDECDB8A2223D34244A535BF0DAF1AE838A9B36F3A42AAEEEAC33` | 12,702 / 96 | unchanged |
| `by-class/LObject.md` | `B4D92014D4703B36DF0B0ADD8B9C6341BF29D58B17D19E5D59885AE09E48B63B` | 21,205 / 159 | unchanged |
| `by-class/EventHandler.md` | `38033240D695B08EB3404F722953F1243DD2DE6B2C2724FB7B59995873AD9EB1` | 19,864 / 172 | unchanged |
| `by-class/TimerHandler.md` | `FBE38D7BEB2CCA34E3CF58C4891B526F170CF911CC39F4C065597EB3D729D017` | 17,937 / 114 | unchanged |

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor exact-artifact Gate 1 accepted SHA256 `78CC73268D6F276938B35C213581587249C30129F662984F38EB125EB3FB43FD` before ordinary implementation.
- [x] Confirm every Claim ledger Action is one of `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, or `not-applicable`.
- [x] Confirm every C01-C31 Verification state is terminal: `applied`, `already-present`, or `excluded-with-reason`.
- [x] Re-read current UID0003PC immediately before callback and preserve any same-or-greater concurrent detail.
- [x] Apply UID0003PC UID-preserving path/range correction to `0x0061fa48-0x0061fad0`.
- [x] Apply UID0003PC `92/94`, owner UID000087, false, blank emitter/position/formal, Nested 0.
- [x] Incorporate complete target bytes/hash/COL/table/slot/RTTI/xref/no-code evidence.
- [x] Re-read UID0003PB and apply UID-preserving path/range correction to `0x0061fa3c-0x0061fa48`.
- [x] Apply UID0003PB `90/93`, owner UID000084, false, blank emitter/position/formal, Nested 0.
- [x] Serially register UID0004SS for `0x0061fad0-0x0061fadc.MetaManVtableData`.
- [x] Verify every provisional new-child token has been replaced with UID0004SS in the report and ordinary docs.
- [x] Apply the new child `91/94`, owner UID000088, false, blank emitter/position/formal, Nested 0.
- [x] Update UID00025V to `90/94` and the exact six-child no-loss partition.
- [x] Update UID000087 to `92/94`, position 10, and install the complete class block.
- [x] Preserve Pane plus Singleton inheritance, EventHandler/TimerHandler inherited views, EBO, exact size, fields, and compiler exclusions.
- [x] Update UID0004HN to `92/94`, position 20, and install the exact constructor block.
- [x] Historicalize manual singleton publication and stale PaneRect/MeasureTextWidth names.
- [x] Update UID000492 to `92/94`, position 30, and install the one-statement destructor.
- [x] Preserve observed singleton clear as implicit Singleton base destruction.
- [x] UID-preserving rename UID0004HO to `MessageShowPaneOnPaint`.
- [x] Update UID0004HO to `92/94`, position 40, and install exact OnPaint body.
- [x] Preserve exact six-shadow/two-face passes, colors, offsets, line formula, final-line behavior, and vtable-only liveness.
- [x] Update UID0001C4 to `92/94`, position 50, and install corrected SetWrappedText.
- [x] Preserve exact packet-helper caller, wrap metrics, bounds, attach, invalidation, and history.
- [x] Update UID0000RK to `92/94`, position 0, and install the sole external singleton definition.
- [x] Update UID0001PX to `91/94`, owner UID0000RK, false, blank emitter/position/formal.
- [x] Update UID0002Y8 to `90/93` and exact source/generated child order without duplicate source.
- [x] Update UID0001C5 to `90/94` with exact Singleton EH no-code proof.
- [x] Update UID0001C6 to `91/94` with exact adjustor/view no-code proof.
- [x] Update UID0001C7 to `91/94` with exact scalar-wrapper/base-lowering no-code proof.
- [x] Update UID0000LB to `92/93` with complete standalone source route, order, header extern, compiler exclusions, and historicalized old split blocker.
- [x] Update UID000088 to `91/93` and install current complete class union plus `Singleton<MetaMan>`.
- [x] Update UID0000LC to `92/93` with new vtable child and Singleton/EBO compiler-source prose.
- [x] Callback-time re-read included UID0003PD, UID0003UU, UID000084, UID0000LA, UID0000RL, UID0001PJ, Pane, GrafPort, RectBounds, LObject, EventHandler, TimerHandler, and MetaMan generated output.
- [x] Preserve the callback-time UID0003PD no-change conclusion only as historical evidence; supervisor registry repair later exposed the concrete contradiction repaired below.
- [x] Preserve every valid historical report fact and label only superseded range/name/source-shape assumptions as historical.
- [x] Preserve negative evidence and rejected handwritten ABI/source alternatives.
- [x] Run one scoped validator per changed ordinary page under one short lease at a time.
- [x] Release each lease immediately after its scoped validator.
- [x] Run one final authorized `--wait-generated` validation for MessageShowPane.
- [x] Verify generated MessageShowPane.cpp has one complete class and one external global definition.
- [x] Verify generated MessageShowPane.cpp has exactly one constructor, destructor, OnPaint, and SetWrappedText in order.
- [x] Verify no `BuildMessageTextButtons` definition remains.
- [x] Verify no UID000087, UID0003PC, UID0000RK, or UID0001PX Empty Emitter Marker remains.
- [x] Verify no duplicate global and no handwritten vtable/RTTI/adjustor/scalar-wrapper source exists.
- [x] Verify generated MetaMan.cpp has one complete MetaMan plus Singleton class, one existing global definition, and no duplicate compiler ABI source.
- [x] Update C01-C31 to legal terminal states with separate destination proof.
- [x] Record validator commands, command IDs, timestamps, exit codes, ok counts, warnings, and side effects.
- [x] Record final changed-file hashes, generated hashes/metrics, actual new UID/path, and zero-lease proof.
- [x] Preserve the exact supervisor-owned manual coverage handoff; B002 did not edit coverage.
- [x] Keep report lifecycle, movement, archive, and execution supervisor/validator-owned.

Implementation callback pass:

- [x] Exact report accepted by supervisor for implementation.
- [x] Destinations 1-18 applied with no accepted ordinary exclusion.
- [x] Historical Destination 19 verify-only union re-read recorded; its UID0003PD no-change result is explicitly superseded by the Gate 2 repair.
- [x] All C01-C31 rows have legal terminal callback/repair states.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] All path, range, score, owner, emitter, reconstructable, position, formal, and history changes verified.
- [x] All placeholders replaced with real UID0004SS.
- [x] Every ordinary lease released; final active lease count zero.
- [x] Every scoped validator passed and is recorded.
- [x] Final waited generated assertions passed and are recorded.
- [x] Exact manual coverage text remains supervisor-owned; B002 made zero coverage edits.
- [x] No accepted ordinary item remains unapplied; C29 is explicitly `excluded-with-reason` because manual coverage is supervisor-owned.

Gate 2 UID0003PD repair pass:

- [x] Read the current supervisor Gate 2 repair override and exact failure audit without rewriting accepted Destinations 1-18.
- [x] Rediscover live MCP session `64c11373` and verify healthy analysis, Hex-Rays, and string-cache state before relying on current binary evidence.
- [x] Read exact UID0003PD bytes and compute the 20-byte SHA256 `7C262FEDC4E6CFA43F5878686E9673B7D7BCBABEB2A27AA9AEB856C0486BB4D9`.
- [x] Prove the two `L"Meta.dat"` xrefs and exact MetaMan load/save source operations.
- [x] Prove the final empty-wide word has a live `0x00524b01` xref and is not padding.
- [x] Reconcile the final word with accepted `m_rows[rowKey].push_back(valueText)` source and compiler/container lowering.
- [x] Reject standalone static/raw/fixed-address filename data, explicit helper-level `L""`, range split, and non-reconstructable alternatives with evidence.
- [x] Retain UID0003PD owner/emitter UID0000LC, reconstructable true, blank position, and Nested 0; raise only the page to `91/94`.
- [x] Install Destination 19's exact managed covered-by formal byte-for-byte.
- [x] Acquire only the UID0003PD ordinary lease immediately before editing.
- [x] Record initial command `000000014247` and its unstable-successor-label warning without hiding the intermediate result.
- [x] Remove only the unstable successor UID label and pass clean scoped validator `000000014248`.
- [x] Release the UID0003PD lease immediately after clean scoped validation.
- [x] Run final authorized waited MetaMan refresh `000000014249`.
- [x] Verify current MetaMan.cpp has one complete class, one existing global, one UID0003PD covered-by comment, zero UID0003PD/all Empty Emitter Markers, and no standalone/raw string object.
- [x] Verify current MetaMan.cpp has no handwritten vtable, RTTI, adjustor, or scalar-wrapper source.
- [x] Verify current MessageShowPane.cpp still has one class/global/constructor/destructor/OnPaint/SetWrappedText and no stale helper, marker, duplicate, or ABI source.
- [x] Update C31, Destination 19, Destination 20, score, open questions, manual handoff, validators, changed files, generated proof, and current-state wording.
- [x] Preserve C01-C30, Destinations 1-18, all accepted formal blocks, history, negative evidence, and supervisor-owned coverage restrictions.
- [x] Verify exactly one `READY_FOR_SUPERVISOR_GATE2_REVIEW` marker and zero B002 leases remain.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000014305","destination_path":"executed-b-agent-research/B002/0003PC-MessageShowPaneVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003PC-MessageShowPaneVtableData-source-quality.md","timestamp":"2026-07-16T15:53:03-04:00","uid":"0003PC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

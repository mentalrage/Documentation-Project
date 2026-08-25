** TARGET-REPORT-UID:00011F **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00011F PopupMenuControlPaneCore Source-Quality Report

## Finalized Report / Current Recommendation

UID00011F's false aggregate coverage has been repaired. The page is now a reviewed non-emitting split/index at `90/93`, with `CANONICAL_OWNER:0000AN`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and `Nested:11`. Validator-assigned exact children UID0004IM-UID0004IW own every source-authored body in the compact range and emit through PopupMenuControlPane class UID0000AN under file UID0000MN.

The eleven children were created and registered before the parent changed to `Nested:11`. PopupMenuControlPane is now `90/92` with the complete accepted declaration; UID0003LM is `90/94` with `GetControlType()`; DialogPane is `89/91`; UID0003KJ is `90/92`; all child scores/metadata and all sixteen literal managed blocks are applied. Callback-template invoke UID00011X and adjustor thunks UID0002Y9 were preserved unchanged. UID0002YA remains comment-only compiler support with its score/formal marker unchanged and now explicitly distinguishes the ordinary destructor UID0004IN.

The constructor's first argument is a `DialogPane *`/owning dialog pointer, not `menuType`. Ten evidence-pass constructor calls pass the surrounding dialog as argument one and a `RectBounds *` as argument two. The constructor stores that pointer at `+0x110`; the mouse and key paths pass it to `MenuPane::Show`. The complete object is `0x114` bytes with `MenuPane *m_menuPane` at `+0x108`, `long m_selectedIndex` at `+0x10c`, and `DialogPane *m_parentDialog` at `+0x110`.

Both raw islands are live source-shaped methods. `0x00498130-0x00498165` is the ordinary destructor body. `0x004981b0-0x0049821f` is a retained selection/parent-notification method that performs or inlines the normal code-10 selection update and then independently sends notification code 12. Their no-function/no-xref/no-pointer state caps exact original naming and liveness confidence; it does not turn either body into padding or compiler glue.

Final waited refresh command `000000008615` generated the PopupMenuControlPane class once, UID0004IM-UID0004IW and UID0003LM exactly once each, and no UID00011F/UID00011X/UID0002Y9 output. UID0002YA appears only as its accepted generated-support comment block, not an executable wrapper body. Final disposition confidence remains high for split, ownership, fields, behavior, source route, and formal source shape; medium-high for the descriptive name `SelectItemAndNotifyParent` and exact original event/member spellings.

## Supporting Research

Current documents read:

- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md` [UID:00011F].
- `by-class/PopupMenuControlPane.md` [UID:0000AN].
- `by-file/PopupMenuControls.md` [UID:0000MN].
- `by-class/MenuPane.md` [UID:00007W] and `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md` [UID:0001BK].
- `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md` [UID:00011X].
- `by-memory/0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks.md` [UID:0002Y9].
- `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md` [UID:0002YA].
- `by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md` [UID:0003LM].
- `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` [UID:0000AK] and `by-type/by-template/FunctionObjectTemplates.md` [UID:0001WQ].
- `by-class/DialogPane.md` [UID:00003T], `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md` [UID:0003KJ], and DialogPane helper aggregate UID00012S.
- `by-class/ControlPane.md` [UID:000038], ControlPane constructor UID0002PB, and ControlPane vtable pages UID0003J8/UID0003J9.
- `by-class/EPFTileContext.md` [UID:00004I], resource-layout/global support, GrafPort/Surface support, current generated PopupMenuControls source, `by-structure.md`, and `by-memory/-guidance.md`.

Archived-report searches used `00011F`, `0x00498040`, `PopupMenuControlPaneCore`, `PopupMenuControlPane`, `0x00498130`, `0x004981b0`, `0x00516510`, `PlainMemberFunctionObject`, and `PopupMenuControls`. Relevant precedents were B001 UID000123 callback-wrapper research, B010 UID00011X shared invoke research, B013 FolderSelectDialog popup API use, B003 popup-menu item-family source routing, and split-index reports including UID0001FX and UID0000WG. No prior executed UID00011F source-quality report was found.

Lifecycle record: the supervisor accepted Gate 1 SHA256 `B47E434007CBE8FED37564C24E03715FDF84CA5664D691702504C76B2AB679F0`, after which B005 completed the authorized implementation callback. Twenty by-* pages were created or modified under short leases, each received a scoped validator, and final generated refresh `000000008615` completed. During the B005 callback, no tracker/coverage/generated/supervisor file was edited manually and B005 ran no report execution, lifecycle, move, or archive command. Any later supervisor-owned lifecycle state is external to and not asserted by this artifact.

## Target

- Target UID: `00011F`.
- Target path: `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`.
- Queue: `auto-generated/-ag-research-tracker.md` under by-memory Not-Covered Files - Reconstructable.
- Implemented metadata: `90/93`, owner `0000AN`, reconstructable false, emitter blank, formal C++ blank, `Nested:11`.
- Implemented source root: exact children UID0004IM-UID0004IW through class UID0000AN to file UID0000MN, `NexusTK/ui/menu/PopupMenuControls.cpp`.
- Generated state at command `000000008615`: target UID00011F is intentionally absent, PopupMenuControlPane has its class shell and all eleven child bodies, and the former popup no-children defect is absent.

## Current Target State

Before callback, the target mixed modeled functions, alignment, and two raw source methods in one by-memory page. Its range table called the raw islands unresolved helpers and its formal block claimed exact-child coverage when no children existed. That historical contradiction is now preserved as superseded context; the implemented page is a blank non-emitting index with an exact child/padding table.

The implemented exact children are UID0004IM constructor, UID0004IN raw ordinary destructor, UID0004IO AppendItem, UID0004IP GetItem, UID0004IQ GetItemCount, UID0004IR GetSelectedIndex, UID0004IS raw selection/code-12 notifier, UID0004IT SetSelectedIndex, UID0004IU OnDraw, UID0004IV OnMouseEvent, and UID0004IW OnKeyDown. The raw destructor remains fenced by five and eleven `0xcc` bytes; the raw notification method by nine and one; all other documented gaps and the seven-byte successor gap are alignment.

The class page now contains the complete accepted declaration and exact method/field map. Historical `menuType`, `int *parentBlock`, `AddOrLayoutItem`, `GetItemByIndex`, `OnSelectionChanged`, generic `Event *`, and withheld-declaration claims are explicitly superseded by the parent-dialog/bounds constructor, `AppendItem`, `GetItem`, `GetItemCount`, `GetSelectedIndex`, `SetSelectedIndex(long)`, `PaneMouseEvent`, `PaneKeyEvent`, and three concrete tail fields.

UID0002Y9 remains unchanged compiler adjustor glue. UID0002YA remains the source-induced scalar deleting destructor wrapper and now distinguishes itself from ordinary destructor UID0004IN. UID00011X remains unchanged shared FunctionObjects template invoke glue. UID0003LM now emits the accepted constant-return source virtual.

Report artifact record: B005 completed the implementation callback and its required verification. Supervisor-owned review, execution, and archival state are external to and not asserted by this artifact.

## Executive Recommendation

1. UID00011F is implemented as a non-emitting split/index parent with semantic owner UID0000AN.
2. Eleven exact child pages cover every compact source body, including both raw islands.
3. PopupMenuControlPane emits the complete accepted declaration and all child bodies.
4. UID0003LM emits the fixed type-id virtual body.
5. DialogPane exposes public control-pointer lookup and two-argument control notification; UID0003KJ carries the corrected exact body.
6. UID00011X and UID0002Y9 remain unchanged; UID0002YA remains comment-only compiler support with synchronized lifetime prose.

## Supervisor Active Recheck

The supervisor accepted exact Gate 1 report SHA256 `B47E434007CBE8FED37564C24E03715FDF84CA5664D691702504C76B2AB679F0` and authorized C01-C22 plus all sixteen destinations. B005 completed that callback at report-level detail. Compiler-generated and non-contiguous support has the accepted no-duplicate disposition; any subsequent supervisor-owned review or lifecycle state is external to this artifact.

## Inference Research Guidance Check

`by-structure.md` requires exact by-memory children for understood source methods and requires a container to be `RECONSTRUCTABLE:FALSE` when it is only an index over exact children. It also forbids pasting child source into an aggregate page. That rule decides the parent disposition.

Direct IDA facts are kept separate from source-facing inference. Exact addresses, bytes, xrefs, field offsets, callback type, caller operands, resource strings, vtable cells, and notification values are facts. Names such as `m_parentDialog`, `SelectItemAndNotifyParent`, `OnDraw`, and `OnKeyDown` are evidence-backed descriptive source names where original symbols are absent. The stale `menuType` interpretation and stale DialogPane id-lookup interpretation are rejected, not carried forward as competing current claims.

No Wave2/Wave3 evidence was used as authority. Mentions in older docs were treated as stale lead material only.

## Heuristic / Inference Reanalysis And Validation

### Constructor and layout

The constructor has two explicit stack arguments and returns with `retn 8`. It calls `ControlPane(3, bounds)`, stores popup vtables at complete-object offsets `0`, `0xa0`, and `0xa4`, stores argument one at `+0x110`, allocates a 24-byte callback object, binds `void (PopupMenuControlPane::*)(long)` target `0x00498220`, allocates a `0x10c`-byte MenuPane, stores it at `+0x108`, sets `+0x10c` to `-1`, and sets inherited `m_controlFlags` at `+0xff` to one.

Ten direct constructor sites pass the owning dialog `this` as argument one and a stack `RectBounds` as argument two. FolderSelectDialog at `0x004b164b`, MusicControlDialog at `0x005292ca`, four TerminalSetupPane sites, and four UserInfoDialogPane sites all agree. `menuType` is rejected. Allocation and scalar-delete evidence fix complete size `0x114`.

### Callback ownership and lifetime

The constructor creates `PlainMemberFunctionObject<void (PopupMenuControlPane::*)(long), PopupMenuControlPane, long>` with zero this-adjust and target `SetSelectedIndex`. MenuPane constructor stores the callback at `+0xfc`; MenuPane destructor deletes every owned item, the list container, and the callback. PopupMenuControlPane therefore owns MenuPane, while MenuPane owns the callback and menu items. PopupMenuControlPane must delete only `m_menuPane` in its ordinary destructor.

### Accessors and selection notifications

The append method tail-forwards to MenuPane `0x00516400`, which appends an item and recomputes all item bounds. It has 54 direct calls. The item accessor forwards to `0x005164e0` and has 11 calls. Count forwards to the three-instruction MenuPane count body at `0x00516500` and has 12 calls. Selected-index getter reads `+0x10c` and has 17 calls.

The active setter has 16 ordinary callers plus the constructor's callback target data reference. It ignores `-1` and no-change inputs. Otherwise it stores the index, invalidates inherited `m_bounds`, gets the parent, finds this control's index, and sends parent notification code 10. FolderSelectDialog's vtable handler at `0x004b1920` explicitly handles code 10 by copying the selected item text.

The raw `0x004981b0` method caches the parent before selection handling, repeats or inlines the normal code-10 path, then finds this control in the original parent and sends code 12 when found. It is not the active callback target and has no xrefs. `SelectItemAndNotifyParent` is the narrowest behavior-descriptive name; stronger names such as `ClosePopup`, `CommitSelection`, or `DismissMenu` overstate code-12 semantics not directly proven.

### Draw and resources

The draw method is primary-vtable-only at `0x00617ffc`. It initializes three `EPFTileContext` values, loads exact UTF-16 resource `POPUPMNU.EPF` frames 0, 1, and 2, and draws with exact palette `NPAL8.PAL`. Frame 0 is the left cap, frame 1 tiles the center, and frame 2 is the right cap. The destination math uses each tile's `bounds.right - bounds.left` width.

If no selection exists, the text buffer is empty. Otherwise the method fetches `m_menuPane->GetItem(m_selectedIndex)` and dispatches MenuItem text-copy slot `+0x10` into a 256-wide-character buffer. It sets text color `0x25`, moves to `m_bounds.left + 1, m_bounds.bottom - 2`, and draws the full string. Disabled/not-visible state uses draw mode 2, color `0x8f`, and the Surface fill/invalidate callback. Visible and active state uses color `0x80`, draw mode 0, and `DrawRectFrame`.

### Mouse and key

The mouse handler is secondary-vtable-only at `0x00618024`. It handles event kind 3, tests `PointInRect(event->y, event->x, &m_bounds)`, obtains screen offset, and calls `MenuPane::Show(m_parentDialog, screenX + width - 1, screenY, m_selectedIndex)`. It always returns false.

The key handler is secondary-vtable-only at `0x00618028`. It uses `g_pEventMan->TranslateEventKey(event->payload[0], event->keyState)`, requires key-down kind 8, translated byte `0x83`, and key state zero, then opens the MenuPane at the same geometry and returns true. Other paths return false. Existing Event docs identify `0x83` as the project-specific next/down navigation byte; it is not a Win32 virtual-key constant.

### Vtable and inheritance

PopupMenuControlPane derives from ControlPane. Primary vtable base is `0x00617fb8`, secondary is `0x00618020`, and tertiary is `0x00618050`, matching inherited complete-object offsets `0`, `0xa0`, and `0xa4`. Primary slot `0x00617ffc` is draw and `0x00618018` is type id. Secondary slots `0x00618024` and `0x00618028` are mouse and key. Tertiary support is inherited. Adjustor thunks subtract `0xa0` and `0xa4`; they remain compiler-only.

### DialogPane lookup correction

`0x0049dd20` does not compare a numeric control id. It obtains each four-byte list element through manager slot `+0x10`, dereferences that element, and compares the stored ControlPane pointer to the supplied pointer. Popup code passes `this`. The current `FindControlIndexById(int)` name and declaration are contradicted. The correct source-facing direction is public `FindControlIndex(const ControlPane *)`: PopupMenuControlPane is not a DialogPane subclass, and both selection methods call the helper through a `DialogPane *`, so protected access would contradict the recovered caller surface. Parent vtable slot `+0x48` accepts `(controlIndex, notifyCode)` and is source-facing `OnControlCommand`.

### Rejected alternatives

- Complete aggregate emission: rejected because UID00011F represents eleven source methods plus padding, not one source-level body.
- Keep current `[[CHILDREN]]` comment as coverage: rejected by generated `[[No Children Attached]]`.
- Treat raw islands as padding: rejected by complete prologue/body/return or tail-jump sequences and unique exact signatures.
- Treat raw destructor as scalar wrapper: rejected because it has no delete-flags argument and exactly supplies the ordinary cleanup duplicated by UID0002YA.
- Handwrite UID0002YA or UID0002Y9: rejected as MSVC scalar-delete and adjustor glue.
- Move callback invoke UID00011X into PopupMenuControls: rejected because seven callback-template vtables share the folded invoke body.
- Direct MenuPane ownership for popup methods: rejected because MenuPane is an owned dependency; popup fields, vtables, public callers, and parent notifications identify PopupMenuControlPane.
- New `PopupMenuControlPane.cpp`: not justified. Current file root groups PopupMenuControlPane, MenuPane, and menu items coherently; possible later physical source split remains only a file-confidence cap.

## Evidence Standards Used

- Evidence-pass IDA MCP function lookup, decompilation, disassembly, byte reads, exact signatures, xrefs, caller/callee summaries, vtable reads, string bytes, and numeric conversions are primary evidence.
- Existing by-* pages and executed reports are corroborating documentation, not substitutes for current binary checks.
- Generated C++ is used only to prove the current no-children output defect and route shape.
- Negative evidence includes no modeled function, no start xrefs, no direct pointer route, no alternate owner vtable, and no adjacent-range inclusion.
- Source names are selected using late-1999 to mid-2000s class/member style already used in this subsystem. Exact behavior is favored over decompiler labels and overconfident semantic names.

## Evidence Checked

Mandatory MCP availability pass against database session `bf5519ae`:

- JSON-RPC initialize succeeded with `ida-pro-mcp 1.0.0`, protocol `2025-06-18`.
- Fresh `idb_list` returned the sole active worker session `bf5519ae`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false` at evidence time.
- `server_health(database=bf5519ae)` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2067 entries.
- An initial local PowerShell `Invoke-WebRequest` attempt failed before parsing the initialize response because `-UseBasicParsing` was omitted. The corrected transport call succeeded immediately; this was not an MCP/IDB failure.

MCP range/body checks:

- `lookup_funcs` checked every modeled start, both raw starts/ends, all alignment boundaries, and successor `0x004985a0`.
- `get_bytes` read full spans `0x0049812b-0x00498170` and `0x004981a7-0x00498220`, plus every modeled inter-function gap and endpoint padding.
- `make_signature_for_range` produced unique exact signatures for raw destructor `0x00498130-0x00498165` and raw selection method `0x004981b0-0x0049821f`.
- `decompile`/`disasm`/`analyze_function` checked constructor, active setter, draw, mouse, key, MenuPane constructor/destructor/append/get/show, DialogPane lookup, FolderSelectDialog caller/notification consumer, scalar destructor, and type id.
- `xrefs_to` checked constructor, every accessor, both raw starts, setter, draw/mouse/key, MenuPane show, scalar destructor, type id, and relevant vtable/data entries.
- `get_bytes` at `0x006187fc` and `0x0061484c` decoded exact UTF-16 `POPUPMNU.EPF` and `NPAL8.PAL`.
- `int_convert` verified `0xeb=235`, `0x24c=588`, `0x5a=90`, `0x79=121`, `0x114=276`, `0x108=264`, `0x10c=268`, and `0x110=272`.

Negative checks:

- No IDA function objects exist at `0x00498130` or `0x004981b0`.
- Both raw starts have zero incoming IDA xrefs; exact start-pointer scans from the evidence pass found no accepted VA route.
- Raw islands are bounded by `0xcc` and have unique full bodies, rejecting accidental decode or overlap.
- Draw/mouse/key are vtable-only, as expected for virtual methods.
- No in-range body belongs to ScrollableControlPane; its constructor starts at `0x004985a0` after seven `0xcc` bytes.
- No PopupMenu class-related structure was available from `search_structs`; layout is reconstructed from constructor/destructor/accessor offsets and allocation size.

The initial research pass intentionally skipped IDA mutation, renaming, type application, comments, process management, by-* validators, generated refresh, and report lifecycle commands. After Gate 1 acceptance, the implementation callback used only scoped file validators and one final waited autogen refresh; IDA remained read-only and no lifecycle command was run.

Implementation verification evidence:

- Validator commands `000000008562-000000008572` assigned and registered exact child UIDs `0004IM-0004IW` before parent nesting changed.
- Parent command `000000008575` applied `90/93`, reconstructable false, blank emitter/formal block, and `Nested:11`. Its temporary missing UID0003LM registry warning was resolved by command `000000008581`.
- Commands `000000008580`, `8581`, `8583`, `8586`, `8588`, `8590`, `8592`, and `8596` validated PopupMenuControlPane, UID0003LM, DialogPane, UID0003KJ, UID0002YA, MenuPane, UID0001BK, and PopupMenuControls respectively.
- Final `python validator.py --mode autogen --apply --wait-generated` command `000000008615`, timestamp `2026-07-12T19:41:21-04:00`, completed generated refresh. When B005 verified `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` immediately afterward, its header embedded that command id/timestamp.
- All sixteen destination managed bodies compare byte-for-byte equal between this report and their by-* documents after newline normalization.
- Generated UID0004IM-UID0004IW and UID0003LM each occur exactly once; PopupMenuControlPane class declaration occurs once; UID00011F, UID00011X, and UID0002Y9 occur zero times. UID0002YA has one generated comment-only support block and no executable wrapper body.
- Three `[[No Children Attached]]` strings remain only on unchanged MenuItemVtables UID0001Y4, MenuPane UID00007W, and MenuPaneAndItems UID0001BK support markers. None is attached to UID00011F or PopupMenuControlPane UID0000AN; the target-specific false no-children state is gone.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00011F is a non-emitting split/index parent, not a source body. | High | by-structure; 11 bodies; generated no-children marker | UID00011F metadata/status/range map | incorporated | applied: `90/93`, false, blank emitter/C++, `Nested:11`; command 8575; UID absent from generated output |
| C02 | Exact compact range and every padding fence are resolved. | Very high | lookup/get_bytes/signatures | UID00011F and all child pages | incorporated | applied: parent exact table plus UID0004IM-UID0004IW boundaries/padding |
| C03 | Constructor signature is parent dialog plus bounds, not menu type. | Very high | ten callers; `retn 8`; field flow | UID0004IM/class/file | incorporated | applied: Destination 3 and historicalized `menuType`/`parentBlock` |
| C04 | Tail layout is MenuPane pointer, selected long, parent DialogPane pointer. | Very high | offsets, accessors, show calls, object size | class/constructor/destructor/file | incorporated | applied at `+0x108/+0x10c/+0x110`, complete size `0x114` |
| C05 | MenuPane owns callback and menu items; popup owns MenuPane. | High | MenuPane ctor/dtor; popup ctor/dtor | constructor/destructor/class/MenuPane support | incorporated | applied across UID0004IM/0004IN, UID0002YA, MenuPane/UID0001BK, class/file |
| C06 | Raw `0x498130` is ordinary destructor source. | High | exact unique body; scalar-wrapper parity | UID0004IN, UID0002YA support | incorporated | applied: UID0004IN `89/91`, Destination 4; UID0002YA distinction synchronized |
| C07 | `AppendItem` forwards and relayouts; 54 callers. | Very high | `0x498170`/`0x516400` and xrefs | UID0004IO/class/file | incorporated | applied at `90/92`, Destination 5, MenuPane support |
| C08 | `GetItem`, `GetItemCount`, and `GetSelectedIndex` contracts are resolved. | Very high | forwarders/getter and 11/12/17 xrefs | UID0004IP/0004IQ/0004IR, class/file | incorporated | applied at accepted scores with Destinations 6-8 |
| C09 | Active `SetSelectedIndex(long)` is callback target and code-10 notifier. | Very high | typed callback, 16 code refs plus data ref, FolderSelect consumer | UID0004IT/class/file | incorporated | applied at `91/92`, Destination 10, callback/consumer proof |
| C10 | Raw `0x4981b0` is distinct retained code-12 parent notifier. | High behavior; medium-high name | exact body, zero routes, duplicated setter flow | UID0004IS/class/target | incorporated | applied at `88/89`, Destination 9, exhaustive raw negatives/name cap |
| C11 | Draw uses POPUPMNU.EPF 0/1/2, NPAL8.PAL, selected text, disabled/active frames. | Very high | decompile/disasm/string bytes/vtable | UID0004IU/class/file | incorporated | applied at `90/91`, Destination 11; generated literals verified |
| C12 | Mouse event 3 opens MenuPane at right edge and always returns false. | Very high | disasm, PointInRect, show helper, vtable | UID0004IV/class/file | incorporated | applied at `90/92`, Destination 12, MenuPane Show support |
| C13 | Key-down 0x83/state 0 opens MenuPane and returns true. | Very high | disasm/EventMan support/show helper/vtable | UID0004IW/class/file | incorporated | applied at `90/92`, Destination 13, successor exclusion |
| C14 | PopupMenuControlPane derives from ControlPane with three vtable views. | Very high | vtable stores/slots/adjustors | class/target/file | incorporated | applied in complete class declaration/evidence; UID0002Y9 unchanged |
| C15 | UID0003LM should emit `GetControlType()` returning 12. | Very high | exact five-byte body and primary vtable cell | UID0003LM/class | incorporated | applied at `90/94`, Destination 14; command 8581; generated once |
| C16 | UID0002Y9 remains non-reconstructable compiler thunks. | Very high | exact subtract/jump bodies and vtable refs | UID0002Y9 support wording | already present | verified unchanged; zero generated UID0002Y9 output |
| C17 | UID0002YA remains compiler scalar-delete wrapper; ordinary cleanup moves to exact raw destructor child. | Very high | wrapper flags/free path plus raw destructor parity | UID0002YA support wording | incorporated | applied prose/cross-reference only; score/formal unchanged; no executable generated wrapper body |
| C18 | UID00011X remains shared FunctionObjects invoke glue. | Very high | seven vtable refs; popup is one consumer | UID00011X/FunctionObjects | already present | verified unchanged; zero generated UID00011X output in PopupMenuControls |
| C19 | DialogPane helper is a public control-pointer lookup, not a protected id lookup. | Very high | `0x49dd20` element dereference/comparison and non-derived popup callers | UID0003KJ and by-class/DialogPane | incorporated | applied at `90/92` and `89/91`, Destinations 15-16; filename retained per callback scope |
| C20 | Parent slot `+0x48` is two-argument control command/notification dispatch. | High | popup calls; FolderSelect override/vtable | by-class/DialogPane and popup children | incorporated | applied public declaration plus code-10/code-12 caller evidence |
| C21 | Current source root remains PopupMenuControls.cpp. | High | class/file family, dependencies, no competing route | by-file/PopupMenuControls | incorporated | applied at unchanged `86/85`/path; generated source header confirms UID0000MN root |
| C22 | No raw/helper/decompiler labels belong in final source. | High | source-shape standard and resolved APIs | every formal block | incorporated | all sixteen literal blocks applied; byte-for-byte comparison passed |

## Positive Evidence Summary

- Every byte in the compact range is now classified as one of eleven source bodies or exact alignment.
- Constructor callers, callback type, field stores, accessor reads, MenuPane show arguments, and scalar delete size independently agree on the class layout.
- Public helper fanout is substantial: constructor 10, append 54, item getter 11, count 12, selected getter 17, and setter 16 direct code refs plus callback data binding.
- Draw/mouse/key/type ownership is fixed by PopupMenuControlPane vtable cells.
- Raw destructor behavior is corroborated by the scalar deleting wrapper.
- Resource names are byte-decoded, not guessed.
- DialogPane notification consumer code verifies code 10 and the two-argument parent callback shape.

## IDA MCP Facts

- Function sizes: `0xeb`, `0x0f`, `0x0f`, `0x0b`, `0x07`, `0x4d`, `0x24c`, `0x5a`, and `0x79` for the nine modeled bodies.
- Raw source sizes: destructor `0x35` bytes; selection notifier `0x6f` bytes.
- Padding: `5 + 11` bytes around raw destructor, `9 + 1` around raw notifier, 1 after append, 1 after get, 5 after count, 9 after selected getter, 3 after setter, 4 after draw, 6 after mouse, and 7 after key.
- Vtables: primary `0x00617fb8`, secondary `0x00618020`, tertiary `0x00618050`; draw cell `0x00617ffc`, mouse `0x00618024`, key `0x00618028`, type `0x00618018`.
- Callback object: 24 bytes, vtable `0x006187e8`, target `0x00498220`, this-adjust zero, object pointer popup `this`.
- MenuPane allocation: `0x10c` bytes; popup allocation: `0x114` bytes.
- Exact resource strings: `POPUPMNU.EPF`, `NPAL8.PAL`.
- Negative raw route facts: no function object, no incoming xref, no accepted pointer route at either raw start.

## Function / Child Inventory

| Exact range | Implemented UID/child role | Reconstructable | Owner/emitter | Applied score |
| --- | --- | --- | --- | --- |
| `0x00498040-0x0049812b` | UID0004IM `PopupMenuControlPaneConstructor` | true | `0000AN` / `0000AN` | `91/92` |
| `0x00498130-0x00498165` | UID0004IN `PopupMenuControlPaneDestructorRaw` | true | `0000AN` / `0000AN` | `89/91` |
| `0x00498170-0x0049817f` | UID0004IO `PopupMenuControlPaneAppendItem` | true | `0000AN` / `0000AN` | `90/92` |
| `0x00498180-0x0049818f` | UID0004IP `PopupMenuControlPaneGetItem` | true | `0000AN` / `0000AN` | `90/93` |
| `0x00498190-0x0049819b` | UID0004IQ `PopupMenuControlPaneGetItemCount` | true | `0000AN` / `0000AN` | `90/93` |
| `0x004981a0-0x004981a7` | UID0004IR `PopupMenuControlPaneGetSelectedIndex` | true | `0000AN` / `0000AN` | `90/94` |
| `0x004981b0-0x0049821f` | UID0004IS `PopupMenuControlPaneSelectItemAndNotifyParentRaw` | true | `0000AN` / `0000AN` | `88/89` |
| `0x00498220-0x0049826d` | UID0004IT `PopupMenuControlPaneSetSelectedIndex` | true | `0000AN` / `0000AN` | `91/92` |
| `0x00498270-0x004984bc` | UID0004IU `PopupMenuControlPaneOnDraw` | true | `0000AN` / `0000AN` | `90/91` |
| `0x004984c0-0x0049851a` | UID0004IV `PopupMenuControlPaneOnMouseEvent` | true | `0000AN` / `0000AN` | `90/92` |
| `0x00498520-0x00498599` | UID0004IW `PopupMenuControlPaneOnKeyDown` | true | `0000AN` / `0000AN` | `90/92` |

Padding remains documented in UID00011F's range map; separate padding pages are unnecessary because the exact children plus parent index classify all interior bytes without overlap ambiguity.

## Direct Xref / Caller Inventory

| Target | Evidence-pass xref result | Meaning |
| --- | --- | --- |
| constructor | 10 code refs | FolderSelect, MusicControl, TerminalSetup, UserInfo dialog construction |
| ordinary raw destructor | 0 | retained source body; scalar wrapper proves ordinary cleanup source |
| AppendItem | 54 code refs | broad public popup API |
| GetItem | 11 code refs | dialog/selection consumers |
| GetItemCount | 12 code refs | setup and selection consumers |
| GetSelectedIndex | 17 code refs | dialog/action consumers |
| raw selection notifier | 0 | retained source method, name/liveness confidence cap |
| SetSelectedIndex | 16 code refs + constructor data ref | public setter and member-function callback target |
| OnDraw | one vtable data ref | primary virtual |
| OnMouseEvent | one vtable data ref | secondary input virtual |
| OnKeyDown | one vtable data ref | secondary input virtual |
| MenuPane::Show | two code refs | only Popup mouse/key paths |
| scalar deleting destructor | two adjustor code refs + primary vtable ref | compiler wrapper |
| GetControlType | one primary-vtable ref | source-authored fixed virtual |

## Documentation Evidence And IDA Status

The callback documents now support the PopupMenuControls source family, shared FunctionObjects callback ownership, MenuPane item ownership, menu item APIs, ControlPane inheritance, EPFTileContext layout, ResourceLayout lookup, GrafPort calls, and Surface callback table. UID00011F's false child-coverage claim, PopupMenuControlPane's withheld declaration/`menuType` signature, UID0003LM's blank C++, and DialogPane's id-lookup wording are preserved only as superseded history.

Generated PopupMenuControls from command `000000008615` contains the pre-existing MenuItem/StringMenuItem/SeparatorMenuItem output, the accepted PopupMenuControlPane class shell, exact UID0004IM-UID0004IW bodies, UID0002YA comment-only support, and UID0003LM. It is verification output rather than binary authority.

## Ranked Ownership Analysis

### 1. PopupMenuControlPane class UID0000AN

- Evidence for: all complete-object vtable stores, direct tail fields, callback target, public callers, draw/input/type slots, ordinary/scalar destructor pair, and class allocation size.
- Evidence against: exact original private method and member spellings are not symbol-proven.
- Decision: direct owner and emitter for all eleven compact source bodies and UID0003LM.

### 2. PopupMenuControls file UID0000MN

- Evidence for: current coherent source family contains PopupMenuControlPane, MenuPane, MenuItem, StringMenuItem, SeparatorMenuItem, and menu resources; class route already surfaces here.
- Evidence against: a later original-source split could have placed PopupMenuControlPane or MenuPane in narrower files.
- Decision: retain as current source root; physical split uncertainty caps file confidence but does not block this target.

### 3. MenuPane UID00007W

- Evidence for: owns callback, item list, show/close/navigation, and receives forwarding calls.
- Evidence against: it does not own popup vtables, popup parent notification, selected field, parent-dialog field, or public popup API call sites.
- Decision: dependency/support only, not owner of popup bodies.

### 4. DialogPane, ControlPane, FunctionObjects, GrafPort/Surface/ImageLib

- Evidence for: provide parent notification, base state, callback template, geometry/draw, and resource APIs.
- Evidence against: each supplies shared infrastructure consumed by PopupMenuControlPane.
- Decision: support owners only; DialogPane receives a narrowly required signature correction.

### 5. No-owner/non-emitting children

- Evidence for: both raw source starts lack direct routes.
- Evidence against: receiver fields, source-shaped ABIs, exact unique bodies, class-local placement, scalar-wrapper parity, and duplicated active setter logic identify their class and source role.
- Decision: reject. No-route is a confidence cap, not a reason to discard source-authored custom game code.

## Source Placement

Implemented placement is `NexusTK/ui/menu/PopupMenuControls.cpp` through class UID0000AN and file UID0000MN. Exact method pages emit through the class. UID00011F is an address/index page and emits nothing. FunctionObjects owns the shared callback template body. DialogPane signature corrections remain in `NexusTK/ui/core/DialogPane.cpp`.

Rejected placements are direct file emission bypassing the class, MenuPane ownership, feature-dialog caller ownership, FunctionObjects ownership of popup methods, ControlPane ownership, a new file created only for raw islands, and a forced physical `PopupMenuControlPane.cpp` split without stronger original-file evidence.

## Range / Split / Padding / Reclassification Analysis

The parent range remains exactly `0x00498040-0x00498599`; it is a useful compact class method-run index. It must not expand into successor `ScrollableControlPane` at `0x004985a0` or non-contiguous destructor/type support. Its source-bearing children are exactly the eleven ranges in the inventory. All omitted subranges are verified `0xcc` alignment. The two raw bodies are child code, not gap annotations.

Parent metadata is `RECONSTRUCTABLE:FALSE` because the parent itself is not a source-level function/declaration. `CANONICAL_OWNER:0000AN` remains valid semantic containment. `EMITTER_UIDS` and formal C++ are blank. `Nested:11` records the exact child count. Exact child pages use `Nested:0`.

Non-contiguous UID00011X/UID0002Y9/UID0002YA/UID0003LM remain cross-referenced support, not nested inside the compact address interval. UID0003LM emits through the class. The other three keep their shared/compiler dispositions.

## Negative Evidence Summary

- Neither raw start is modeled or directly referenced.
- No accepted pointer-table/callback/vtable route targets either raw start.
- The raw code-12 method's exact original name and live invocation path are unavailable.
- Popup draw/input/type methods have no ordinary code callers because they are virtual.
- The IDB has no named PopupMenu/MenuPane struct layout.
- The final ImageLib/ResourceLayout singleton pointer type remains a shared render-layer uncertainty.
- Exact event/member/helper spelling is inferred from accepted project conventions.
- These negatives cap scores below 95. They do not undermine exact range, behavior, class ownership, or first-draft source eligibility.

## IDA Rename / Type / Comment Recommendations

No IDA mutations are requested or permitted. Safe future source-facing labels would be the eleven child names in the inventory, `PopupMenuControlPane::~PopupMenuControlPane` for `0x00498130`, `PopupMenuControlPane::SetSelectedIndex` for `0x00498220`, and `DialogPane::FindControlIndex` for `0x0049dd20`. Preserve the raw-name qualification for `SelectItemAndNotifyParent` until a direct declaration or call route is recovered.

## First-Draft C++ Recommendation

All applied formal changes are preserved below as exact destination-specific managed blocks. Block count: 16 destinations. The parent block is intentionally blank; all source-bearing methods have their own exact child destination. Post-callback comparison confirms every report block is byte-for-byte equal to its destination block after newline normalization.

### Destination 1: UID00011F split/index parent

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: `by-class/PopupMenuControlPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;
struct PaneKeyEvent;
struct RectBounds;
class DialogPane;
class MenuItem;
class MenuPane;

class PopupMenuControlPane : public ControlPane
{
public:
    PopupMenuControlPane(DialogPane *parentDialog, const RectBounds *bounds);
    virtual ~PopupMenuControlPane();

    void AppendItem(MenuItem *item);
    MenuItem *GetItem(int index) const;
    int GetItemCount() const;
    long GetSelectedIndex() const;
    void SetSelectedIndex(long index);

protected:
    virtual void OnDraw();
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual int GetControlType();

private:
    void SelectItemAndNotifyParent(long index);

    MenuPane *m_menuPane;             // +0x108
    long m_selectedIndex;             // +0x10c
    DialogPane *m_parentDialog;       // +0x110
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: new `by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PopupMenuControlPane::PopupMenuControlPane(DialogPane *parentDialog,
                                           const RectBounds *bounds)
    : ControlPane(3, bounds),
      m_menuPane(0),
      m_selectedIndex(-1),
      m_parentDialog(parentDialog)
{
    typedef void (PopupMenuControlPane::*SelectionCallback)(long);

    FunctionObjectT<long> *callback =
        new PlainMemberFunctionObject<SelectionCallback, PopupMenuControlPane, long>(
            &PopupMenuControlPane::SetSelectedIndex, 0, this);

    m_menuPane = new MenuPane(callback);
    m_controlFlags = 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: new `by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PopupMenuControlPane::~PopupMenuControlPane()
{
    delete m_menuPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5: new `by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PopupMenuControlPane::AppendItem(MenuItem *item)
{
    m_menuPane->AppendItem(item);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6: new `by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MenuItem *PopupMenuControlPane::GetItem(int index) const
{
    return m_menuPane->GetItem(index);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7: new `by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int PopupMenuControlPane::GetItemCount() const
{
    return m_menuPane->GetItemCount();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8: new `by-memory/0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
long PopupMenuControlPane::GetSelectedIndex() const
{
    return m_selectedIndex;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9: new `by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PopupMenuControlPane::SelectItemAndNotifyParent(long index)
{
    DialogPane *parentDialog = static_cast<DialogPane *>(GetParent());

    SetSelectedIndex(index);

    const int controlIndex = parentDialog->FindControlIndex(this);
    if (controlIndex != -1)
        parentDialog->OnControlCommand(controlIndex, 12);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10: new `by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PopupMenuControlPane::SetSelectedIndex(long index)
{
    if (index == m_selectedIndex || index == -1)
        return;

    m_selectedIndex = index;
    InvalidateRect(&m_bounds);

    DialogPane *parentDialog = static_cast<DialogPane *>(GetParent());
    if (parentDialog != 0) {
        const int controlIndex = parentDialog->FindControlIndex(this);
        parentDialog->OnControlCommand(controlIndex, 10);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11: new `by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PopupMenuControlPane::OnDraw()
{
    EPFTileContext leftTile;
    EPFTileContext centerTile;
    EPFTileContext rightTile;

    leftTile.Initialize();
    centerTile.Initialize();
    rightTile.Initialize();

    g_pResourceLayoutTable->LookupLayoutEntry(L"POPUPMNU.EPF", 0, &leftTile);
    g_pResourceLayoutTable->LookupLayoutEntry(L"POPUPMNU.EPF", 1, &centerTile);
    g_pResourceLayoutTable->LookupLayoutEntry(L"POPUPMNU.EPF", 2, &rightTile);

    const int leftWidth = leftTile.bounds.right - leftTile.bounds.left;
    const int rightWidth = rightTile.bounds.right - rightTile.bounds.left;

    RectBounds destination = m_bounds;
    destination.right = destination.left + leftWidth;
    m_drawMode = 0;
    RenderTileFrame(&leftTile, &leftTile.bounds, &destination, 0, L"NPAL8.PAL", 0);

    destination = m_bounds;
    destination.left += leftWidth;
    destination.right -= rightWidth;
    DrawTiledBackground(&destination, &centerTile, L"NPAL8.PAL");

    destination = m_bounds;
    destination.left = destination.right - rightWidth;
    RenderTileFrame(&rightTile, &rightTile.bounds, &destination, 0, L"NPAL8.PAL", 0);

    wchar_t selectedText[256];
    selectedText[0] = L'\0';
    if (m_selectedIndex != -1)
        m_menuPane->GetItem(m_selectedIndex)->GetText(selectedText, _countof(selectedText));

    SetTextColor(0x25);
    MoveTo(m_bounds.left + 1, m_bounds.bottom - 2);
    DrawWideText(selectedText, static_cast<int>(wcslen(selectedText)));

    if (!m_controlVisible) {
        m_drawMode = 2;
        SetDrawColor(0x8f);
        g_surfaceRenderCallbacks.fillOrInvalidate(this, &m_bounds);
    }

    if (m_controlVisible && m_controlActive) {
        SetDrawColor(0x80);
        m_drawMode = 0;
        DrawRectFrame(&m_bounds);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12: new `by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PopupMenuControlPane::OnMouseEvent(const PaneMouseEvent *event)
{
    if (event->eventKind == kEventLeftButtonUp &&
        PointInRect(event->y, event->x, &m_bounds)) {
        Point screenOffset;
        GetScreenOffset(&screenOffset);

        m_menuPane->Show(m_parentDialog,
                         screenOffset.x + m_bounds.right - m_bounds.left - 1,
                         screenOffset.y,
                         m_selectedIndex);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 13: new `by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PopupMenuControlPane::OnKeyDown(const PaneKeyEvent *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);

    if (event->eventKind != kEventKeyDown || key != 0x83 || event->keyState != 0)
        return false;

    Point screenOffset;
    GetScreenOffset(&screenOffset);

    m_menuPane->Show(m_parentDialog,
                     screenOffset.x + m_bounds.right - m_bounds.left - 1,
                     screenOffset.y,
                     m_selectedIndex);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 14: UID0003LM `by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int PopupMenuControlPane::GetControlType()
{
    return 12;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 15: `by-class/DialogPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual bool OnInputEvent(InputEvent *event);
    virtual bool OnKeyInput(InputEvent *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    int FindControlIndex(const ControlPane *control) const;

protected:
    void CloseDialog();
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, const wchar_t *paletteName);
    void AddControl(unsigned char category, ControlPane *control);
    void AddControl(ControlPane *control);
    void SelectControlById(int controlId);
    void SwitchControlCategory(int categoryId);
    int GetControlCount() const;
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    void SetHoverControl(int controlId);
    void SetSelectionVisualState(int controlId, unsigned char state);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RedrawSelectedControl();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    DialogControlManager *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginX;
    int m_dragOriginY;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinY;
    int m_dragClampMinX;
    int m_dragClampMaxY;
    int m_dragClampMaxX;
    EPFTileContext m_tileContext;
    DialogBackgroundState m_backgroundState;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 16: UID0003KJ `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int DialogPane::FindControlIndex(const ControlPane *control) const
{
    if (m_controlManager == 0)
        return -1;

    const int controlCount = m_controlManager->GetCount();
    for (int index = 0; index < controlCount; ++index) {
        if (m_controlManager->GetControl(index) == control)
            return index;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The first-draft source preserves original behavior while omitting compiler vptr stores, scalar-delete flags, EH cleanup labels, security-cookie scaffolding, adjustor thunks, and raw IDA names. Exact original private/event/helper spellings remain confidence caps, not blank-C++ blockers.

## Final Recommendation

- Completed UID00011F disposition: target `90/93`, exact children UID0004IM-UID0004IW, and all accepted formal/source-quality detail are present.
- Completed support dispositions: PopupMenuControlPane `90/92`, UID0003LM `90/94`, DialogPane `89/91`, and UID0003KJ `90/92`; all literal destinations match this artifact.
- Accept UID0002YA, MenuPane, UID0001BK, and PopupMenuControls support synchronization at unchanged accepted scores/routes.
- Confirm UID00011X and UID0002Y9 remained unchanged and non-duplicated. Only the parent index and compiler/shared artifacts remain intentionally non-emitting.
- No accepted implementation item remained unapplied at callback completion. B005 did not perform report execution; supervisor-owned review, execution, and archival state are external to and not asserted by this artifact.

## Recommended Target Doc Changes

Implemented target `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`:

- Applied `86/90 -> 90/93`, preserved `CANONICAL_OWNER:0000AN`, changed reconstructable true to false, cleared emitter/formal C++, and changed `Nested:-4 -> 11` only after UID allocation.
- Applied exact child/padding inventory, caller counts, layout, vtables, resources, negative evidence, source route, and non-contiguous support dispositions.
- Preserved historical broad-range, false-coverage, and unresolved-raw-gap claims as superseded context.

## Recommended Support Doc Changes

- `by-class/PopupMenuControlPane.md`: applied `86/88 -> 90/92`, Destination 2, exact field/layout/method map, parent-dialog correction, callback/lifetime, resources, vtables, callers, raw liveness, negatives, and source route.
- Eleven new by-memory pages: registered UID0004IM-UID0004IW with accepted scores/metadata, detailed evidence, and Destinations 3-13.
- UID0003LM: applied `86/90 -> 90/94`, Destination 14, exact bytes/range/vtable/no-callee evidence, and source-facing int return.
- UID0002YA: score/metadata/formal marker unchanged; ordinary-versus-scalar distinction, object size, field name, and lifetime synchronized.
- UID0002Y9 and UID00011X: verified unchanged; existing detail remained sufficient.
- UID0003KJ and `by-class/DialogPane.md`: applied pointer lookup/public access, parent notification declaration, Destinations 15-16, and preserved unrelated class content. Filename remained unchanged because callback did not authorize rename.
- `by-class/MenuPane.md` and UID0001BK: scores/formal blocks unchanged; popup callers, exact tail ownership, count leaf, and four-argument Show support synchronized.
- `by-file/PopupMenuControls.md`: score/path unchanged; complete child route, ownership/lifetime, resources, callers, raw/compiler negatives, and source placement synchronized.

## Score And Metadata Recommendation

- UID00011F: applied `86/90 -> 90/93`, owner `0000AN` preserved, reconstructable false, emitter blank, C++ blank, nested 11.
- PopupMenuControlPane class: applied `86/88 -> 90/92`, owner/emitter and position 21 preserved.
- New children UID0004IM-UID0004IW: applied inventory scores, owner/emitter `0000AN`, reconstructable true, nested 0.
- UID0003LM: applied `86/90 -> 90/94`, owner/emitter preserved.
- UID0003KJ: applied `87/90 -> 90/92`, owner/emitter preserved; source name/signature corrected in place.
- DialogPane class: applied `88/89 -> 89/91`; owner/emitter and unrelated content preserved.
- UID0002Y9, UID0002YA, UID00011X, MenuPane, UID0001BK, and PopupMenuControls file: scores and metadata unchanged as accepted.

Score blockers attempted and resolved:

- Aggregate coverage: resolved by exact split plan and blank parent.
- Raw helper boundaries/liveness: resolved to exact unique source bodies; no-route remains a documented score cap.
- Constructor parameters: resolved by ten caller operand shapes.
- Field layout/lifetime: resolved by constructor, accessors, MenuPane destructor, raw/ scalar destructors, and object size.
- Callback target/type: resolved by typed callback vtable and stores.
- Accessor names/types: resolved by forwarding targets and caller conventions; `long` retained where callback type proves it.
- Draw resources/helpers: resolved by decompile, disassembly, exact strings, EPFTileContext and GrafPort support.
- Mouse/key event shape: resolved by vtables, EventMan, PointInRect, Show helper, and return behavior.
- Dialog lookup: resolved from direct body semantics; stale id name rejected.
- Source placement: current file route retained after rejecting narrower/new/caller/dependency ownership.

Scores stay below 95 because original private method spelling, raw method active route, exact event member names, final ResourceLayout singleton type, and original physical file split are not recoverable from current evidence.

## Open Questions With Attempted Resolution

1. Exact name of raw code-12 method. Checked function model, xrefs, pointer encodings, bytes, sibling setter, parent consumers, and local docs. No declaration or live route exists. `SelectItemAndNotifyParent` is the safest behavior name; score `88/89` reflects the remaining name/liveness uncertainty.
2. Exact meaning of notification code 12. Checked FolderSelect handler, DialogPane class/helper docs, popup body, and caller inventory. Code 10 is directly selection-change; code 12 is a second parent notification but no current consumer proves close/commit/dismiss semantics. Formal source preserves literal 12.
3. Exact event/member names. Checked EventMan producer docs, accepted PaneMouseEvent/PaneKeyEvent precedents, offsets, and handler slots. Descriptive project names are sufficient; exact spelling caps confidence.
4. Exact ResourceLayout singleton pointer type. Checked g_pEPFLib/ResourceLayout docs and current generated conventions. The target's lookup behavior is fixed, while shared render-layer type finalization remains outside this source-family assignment.
5. Original physical file split. Checked PopupMenuControls file, proposed source tree, class grouping, resources, and related reports. No stronger evidence justifies a new file; current route remains.
6. Whether raw methods were retained but optimized out. Zero routes cannot distinguish dead retained source from an externally unmodeled path. Their complete class-local source bodies still require reconstruction documentation; no-route is preserved as the confidence cap.

No open question blocks the split, owner/emitter route, class declaration, or exact first-draft bodies.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Queue/tracker/generated coverage remain validator-owned. Implemented by-* metadata, Item Summaries, exact child UIDs, and `Nested:11` drove validator refresh `000000008615`. No manual coverage, tracker, generated, registry, queue, or supervisor text was edited.

## Lifecycle Boundary

- B005 completed every authorized report and implementation responsibility recorded in C01-C22, the validator results, and the implementation checklist.
- Supervisor-owned review, report execution, move, archive, and post-archive state are external lifecycle facts and are not asserted by this callback artifact.
- A-agent action: none required.
- Optional later research is limited to exact original symbol/header recovery or stronger physical source-file split evidence; neither blocks this implementation or changes its current owner/emitter route.

## Confidence

- Split/container disposition: very high.
- Exact boundaries/padding: very high.
- Class ownership, vtables, fields, callback, and lifetime: very high.
- Method behavior and source bodies: high to very high.
- Raw method liveness and exact name: medium-high.
- Implemented source-file route: high.
- Applied scores/metadata: high.

## Validator Results

All scoped commands ran from `E:\NTK\GhidraBridge\source-3\project-documentation\tools` as `python validator.py --mode file --file "<path>" --apply`. Every command exited `0`; changed/new-file scans that did not print an `ok` row are recorded as `n/a (mutations emitted)`, not inferred as zero.

| Command | Timestamp | File | Exit / ok | Relevant result |
| --- | --- | --- | --- | --- |
| `000000008562` | `2026-07-12T19:25:55-04:00` | UID0004IM constructor | `0` / n/a | allocated UID0004IM; registered `91/92`, owner/emitter 0000AN |
| `000000008563` | `2026-07-12T19:25:57-04:00` | UID0004IN destructor raw | `0` / n/a | allocated UID0004IN; registered `89/91` |
| `000000008564` | `2026-07-12T19:25:59-04:00` | UID0004IO AppendItem | `0` / n/a | allocated UID0004IO; registered `90/92` |
| `000000008565` | `2026-07-12T19:26:02-04:00` | UID0004IP GetItem | `0` / n/a | allocated UID0004IP; registered `90/93` |
| `000000008566` | `2026-07-12T19:26:04-04:00` | UID0004IQ GetItemCount | `0` / n/a | allocated UID0004IQ; registered `90/93` |
| `000000008567` | `2026-07-12T19:26:06-04:00` | UID0004IR GetSelectedIndex | `0` / n/a | allocated UID0004IR; registered `90/94` |
| `000000008568` | `2026-07-12T19:26:08-04:00` | UID0004IS raw notifier | `0` / n/a | allocated UID0004IS; registered `88/89` |
| `000000008569` | `2026-07-12T19:26:10-04:00` | UID0004IT SetSelectedIndex | `0` / n/a | allocated UID0004IT; registered `91/92` |
| `000000008570` | `2026-07-12T19:26:12-04:00` | UID0004IU OnDraw | `0` / n/a | allocated UID0004IU; registered `90/91` |
| `000000008571` | `2026-07-12T19:26:14-04:00` | UID0004IV OnMouseEvent | `0` / n/a | allocated UID0004IV; registered `90/92` |
| `000000008572` | `2026-07-12T19:26:16-04:00` | UID0004IW OnKeyDown | `0` / n/a | allocated UID0004IW; registered `90/92` |
| `000000008575` | `2026-07-12T19:27:24-04:00` | UID00011F parent | `0` / `1` | applied `90/93`, false/blank/`Nested:11`; temporary UID0003LM missing-registry warning |
| `000000008580` | `2026-07-12T19:28:44-04:00` | PopupMenuControlPane class | `0` / `1` | applied `90/92` and Destination 2; temporary UID0003LM missing-registry warnings |
| `000000008581` | `2026-07-12T19:29:23-04:00` | UID0003LM | `0` / `1` | registered existing UID path, applied `90/94`/Destination 14; resolved prior warning |
| `000000008583` | `2026-07-12T19:29:54-04:00` | DialogPane class | `0` / `1` | applied `89/91`/Destination 15; warnings were pre-existing unregistered support UIDs, including UID0003KJ before its scan |
| `000000008586` | `2026-07-12T19:30:35-04:00` | UID0003KJ | `0` / `1` | registered existing UID path, applied `90/92`/Destination 16 |
| `000000008588` | `2026-07-12T19:31:31-04:00` | UID0002YA | `0` / `1` | score/formal unchanged; ordinary-destructor reference/prose synchronized |
| `000000008590` | `2026-07-12T19:32:12-04:00` | MenuPane class | `0` / `1` | score/formal unchanged; warnings only for pre-existing unregistered UID000376-UID000379 refs |
| `000000008592` | `2026-07-12T19:32:44-04:00` | UID0001BK | `0` / `1` | score/formal unchanged; same pre-existing UID000376-UID000379 warnings |
| `000000008596` | `2026-07-12T19:33:37-04:00` | PopupMenuControls file | `0` / `1` | score/path unchanged; same pre-existing UID000376-UID000379 warnings |

Initial waited refresh `000000008600` was superseded by concurrent refresh `000000008604`; the subsequent B005 refresh `000000008607` was likewise superseded by concurrent refresh `000000008608`. B005 therefore ran the waited command again. Final command: `python validator.py --mode autogen --apply --wait-generated`, command `000000008615`, timestamp `2026-07-12T19:41:21-04:00`, exit `0`, generated refresh `completed`. Project-wide informational counts were `autogen_children_fallback_insert:16`, `autogen_children_marker_missing:81`, and `autogen_emitter_has_no_code:220`; none is a target-specific error. The generated file header matched command `000000008615` and its timestamp when B005 performed the immediate post-command verification; later validator-owned refreshes may legitimately advance shared generated metadata without changing this callback's source content.

Generated verification for `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`:

- class declaration count: one;
- UID0004IM-UID0004IW marker count: one each;
- UID0003LM marker/body count: one;
- UID00011F, UID00011X, UID0002Y9 marker count: zero;
- UID0002YA: one marker plus its internal comment reference, one comment-only block, zero executable scalar-wrapper body;
- target/class `[[No Children Attached]]`: zero;
- exact resources `POPUPMNU.EPF`/`NPAL8.PAL`, constructor callback, DialogPane lookup/notification calls, mouse/key Show geometry, and type return are present.

## Changed Files

Created and validator-registered:

- `by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md` [UID0004IM].
- `by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md` [UID0004IN].
- `by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md` [UID0004IO].
- `by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md` [UID0004IP].
- `by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md` [UID0004IQ].
- `by-memory/0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex.md` [UID0004IR].
- `by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md` [UID0004IS].
- `by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md` [UID0004IT].
- `by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md` [UID0004IU].
- `by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md` [UID0004IV].
- `by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md` [UID0004IW].

Modified:

- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md` [UID00011F].
- `by-class/PopupMenuControlPane.md` [UID0000AN].
- `by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md` [UID0003LM].
- `by-class/DialogPane.md` [UID00003T].
- `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md` [UID0003KJ].
- `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md` [UID0002YA].
- `by-class/MenuPane.md` [UID00007W].
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md` [UID0001BK].
- `by-file/PopupMenuControls.md` [UID0000MN].
- `tools/leaser/Agents/Agent-B005/research/00011F-PopupMenuControlPaneCore-source-quality.md` (B005 research and implementation-callback artifact created for UID00011F).

Renamed: none. UID0003KJ's stale filename was preserved because callback scope did not authorize rename; title/signature/body are corrected in place. UID0002Y9 and UID00011X were not edited.

Leases: parent UID00011F was leased while creating/registering the eleven new children and applying the parent split. Each existing by-* page listed above was then leased only for its edit/scoped-validator cycle. Every lease was released immediately; final `current_leases.md` reports no active leases. New children followed the workflow exception and were created/validated while the existing parent lease was held.

Validator-owned side effects included `tools/validator.ini`, projected stats, generated coverage metadata, and generated C++; none was edited manually. During this callback B005 ran no report execution, lifecycle, move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Current target state and generated no-children defect recorded.
- [x] Fresh IDB list and health confirmed for session `bf5519ae`.
- [x] Every modeled and raw in-range body classified.
- [x] Exact boundaries, padding, successor exclusion, vtables, resources, callers/callees, fields, and lifetime recorded.
- [x] Constructor parameter and stale `menuType` interpretation resolved.
- [x] Raw destructor and code-12 method resolved to source-bearing child dispositions.
- [x] Compiler thunk/scalar/shared-callback duplication rejected.
- [x] Claim And Incorporation Ledger contains C01-C22 with destinations.
- [x] Sixteen destination-specific literal managed blocks supplied.
- [x] Score, owner, emitter, reconstructable, split, nesting, and source-route recommendations supplied.
- [x] Positive and negative evidence and rejected alternatives preserved.
- [x] Open questions exhausted or given exact evidence-backed score/C++ impact.
- [x] Manual coverage/tracker change correctly marked not applicable.
- [x] No by-* edit, validator, lease, generated edit, IDA mutation, lifecycle command, execute, move, archive, or subagent occurred.
- [x] Supervisor Gate 1 accepted exact SHA256 `B47E434007CBE8FED37564C24E03715FDF84CA5664D691702504C76B2AB679F0`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] C01-C22 incorporated or explicitly dispositioned at same-or-greater detail.
- [x] UID00011F converted to `90/93` non-emitting split/index with `Nested:11` only after children existed.
- [x] PopupMenuControlPane class raised to `90/92` with Destination 2.
- [x] Eleven exact child pages created as UID0004IM-UID0004IW with accepted scores/metadata, detailed evidence, and Destinations 3-13.
- [x] UID0003LM raised to `90/94` and Destination 14 applied.
- [x] DialogPane/UID0003KJ accepted correction and Destinations 15-16 applied without losing unrelated content.
- [x] UID0002YA ordinary-versus-scalar destructor wording synchronized; UID0002Y9/UID00011X preserved unchanged.
- [x] MenuPane, UID0001BK, and PopupMenuControls support detail synchronized without score/route drift.
- [x] One scoped validator run per changed by-* page under the required lease discipline; command ids/timestamps/results recorded; leases released immediately.
- [x] Final waited generated refresh completed and PopupMenuControls.cpp verified read-only for class shell, eleven children, type id, expected non-emitting parent/shared/compiler items, and no duplicate invoke/adjustor/scalar body.
- [x] Report ledger, checklist, validator results, changed files, and current-state wording updated archive-neutrally.
- [x] Remaining unapplied accepted items: none.
- [x] B005 lifecycle boundary recorded: all callback responsibilities are complete, while supervisor-owned review, execution, move, archive, and post-archive state remain external and are not asserted by this artifact.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000008656","destination_path":"executed-b-agent-research/B005/00011F-PopupMenuControlPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00011F-PopupMenuControlPaneCore-source-quality.md","timestamp":"2026-07-12T19:53:13-04:00","uid":"00011F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

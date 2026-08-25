** TARGET-REPORT-UID:00023U **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00023U ScreenPane Destructor Thunk Island Ownership / Split Research


## Finalized Report / Current Recommendation

- Lifecycle authority: the validator-owned footer is authoritative over report-body snapshots. Command `000000016527` records the historical execution into `executed-b-agent-research/B003/`; later command `000000016537` records de-execution for rework and returned this artifact to `tools/leaser/Agents/Agent-B003/research/`. Immediate predecessor SHA256 `D4CBAC58037A46E8E94B58E4248D838599E4DDC4CAA6511A867EF1BB39BA905B` failed Gate 1 because its current-state and manual-root wording was stale. Earlier preimplementation SHA256 `E0B4475E8D1F8368AE5F3F6A6E687F6A0CAD360E5BB1E38BA57C9C4179404DC8` historically passed Gate 1 only to authorize the completed implementation callback; it does not authorize Gate 2 for this repaired body. C01-C20 and R0-R10 remain implemented and independently read back, UID0004W7 remains registered, all recorded ordinary validators exited `0`, implementation-time final waited command `000000016487` remains complete as historical callback-generation provenance, and the target x86 MSVC layout assertions remain passing. Unrelated foreground commands `000000016565` at `2026-07-22T19:48:00-04:00` and `000000016569` at `2026-07-22T20:20:37-04:00` are retained as historical intermediate generated checkpoints. The current generated-artifact checkpoint is the later repository-wide foreground refresh under command `000000016594` at `2026-07-22T20:38:53-04:00`; it preserves the accepted generated shape exactly. The command-`000000016537` fresh-audit requirement is a historical process checkpoint, not a mutable current-status assertion; current path and lifecycle truth always come from the latest validator-owned footer event.
- Current recommendation: reclassify [UID:00023U] `0x00559b20-0x00559b8b` as a high-confidence, ScreenPane-owned compiler-support island. Set it to `92/94`, retain `CANONICAL_OWNER:0000CB`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, retain blank optional position and `Nested:0`, and leave the managed C++ body empty.
- Final disposition: none of the 107 target bytes is an independently authored NexusTK method. `0x00559b20` is the out-of-line constructor-unwind cleanup for the empty `Singleton<ScreenPane>` base; `0x00559b2b`, `0x00559b36`, and `0x00559b41` are secondary-facet adjustor thunks; `0x00559b50` is the MSVC scalar deleting destructor. Internal and external `0xcc` spans remain non-source alignment.
- Required source action: create one exact source child for the ordinary destructor at `0x00556a60-0x00556cd4`, route it through [UID:0000CB][ScreenPane] and [UID:0000NB][ScreenPane], and express singleton lifetime through `Singleton<ScreenPane>` plus the semantic `g_pScreenPane` definition. Do not hand-author target thunks, flags, vptr writes, base-destructor calls, EH/cookies, RTTI, or vtable arrays.
- Required support action: preserve the root-cluster and ScreenPane family union, correct relative child nesting, make the broad UID0001G5 aggregate, physical singleton slot, and vtable data non-emitting, establish the semantic global as the sole source definition, install the complete compile-visible R3 ScreenPane declaration, normalize three already-accepted method bodies to inherited/source-facing members, and correct the two Surface lookup roots from the stale file-static `-1` model to zero-initialized externally linked definitions required by the destructor's cross-source references.
- Confidence: `94` for the compiler/source split and source ownership; inferred private spellings and the unrecovered semantic types of two proven physical spans cap the class and source child below 95. R3 now preserves both spans with bounded first-draft C++03 storage, so it no longer collapses the object or shifts later members.

## Supporting Research

- Canonical project root: `E:/NTK/GhidraBridge/source-3/project-documentation`.
- Report path at the command-`000000016537` de-execution-for-rework checkpoint: `tools/leaser/Agents/Agent-B003/research/00023U-ScreenPaneDestructorThunkIsland-source-quality.md`; any later validator footer event is authoritative for subsequent path/lifecycle state.
- Historical assignment-time selection authority was `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, line 1823 at that earlier evidence epoch. The final settled tracker checkpoint is command `000000016626`, refreshed `2026-07-22T22:16:12-04:00` from `deferred-generated-refresh`, SHA256 `331381565D56CC8ED83F7FD7234C22A81CF8FF1E8109543A12FA4E5C2A724C23`, 1,634,570 bytes / 6,507 lines; its exact UID00023U row is at line 5426.
- Direct duplicate search terms: `UID00023U`, `0x00559b20`, `ScreenPaneDestructorThunkIsland`, `ScreenPaneDestructor`, and `g_pScreenPane`.
- `executed-b-agent-research/**`: only executed B001 `00023T-FormatWideTextFixedBuffer-source-quality.md` directly matches UID/address/title. It uses UID00023U only as the successor boundary and historically describes `0x00559b20` as a source singleton-clear helper. Its `0x00559b1d-0x00559b20` three-byte predecessor-padding proof remains valid; the source-helper classification is superseded by the fresh constructor-EH evidence in this report.
- `tools/leaser/Agents/Older-Research/**`: zero matches for all five exact terms.
- `tools/leaser/Agents/SpecialReports/**`: zero matches for all five exact terms.
- Active B001-B005 research roots: zero direct UID/address/title/destructor-target matches. Active B001 and B004 reports mention `g_pScreenPane` only as unrelated family support. B004 currently researches UID0002SR MapRefreshDimmer vtable data and does not own this target; any later shared ScreenPane callback must reread/rebase rather than overwrite.
- Relevant executed support leads independently reread or classified: B002/B005 UID00039R (DirectDraw restore), B008 UID00039Q (presentation setup), B007 UID0002VO (browser notification child), B010 UID00039X (cursor loader), B012 UID0003A3 (presentation traversal), and B001 UID0001G6 (mixed presentation index). They support field/source context but are not substitutes for target-specific analysis.
- Initial evidence-time lease ledger had no active leases. Implementation used exactly one ordinary B003 lease at a time, acquired only for each edit/validation and released immediately. Final readback has zero B003 leases.

## Target

- Target UID: `00023U`.
- Target path: `by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md`.
- Exact implemented target SHA256: `F209E8C8B997290031FD9D39D755F9FC4C8DEC67633A1A94A6A09640A2C0AF3F`.
- Exact range: `[0x00559b20,0x00559b8b)`, `0x6b` / 107 bytes.
- Implemented metadata: `92/94`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, blank managed body, `Nested:0`.
- Historical generated symptom: command `000000016371`, refreshed `2026-07-21T21:44:14-04:00`, generated `ScreenPane.cpp` SHA256 `B17182CE11A59C705CC2B637874F0AF4B7F8266317EE5EB2B327ACA79A3833D1`, 11,076 bytes / 336 lines, contained UID00023U as an Empty Emitter Marker. Later read-only external checkpoints `000000016419` and `000000016426` retained the same semantic defects; final repair readback of command `000000016426`, refreshed `2026-07-22T16:16:56-04:00`, is SHA256 `6B5D283C0D550BDA7C8824D2D11965D8657379B006DD0F1C63CFF1E693F2CAC9`, 11,076 bytes / 336 lines, with the same six ScreenPane-family markers and 14 qualified definitions. None of these commands was run by B003 for this report.

## Current Target State

- UID00023U is implemented as the exact `92/94` ScreenPane-owned compiler island with false/non-emitting metadata, blank R0, and all five functions, instruction/block/xref evidence, adjustor constants, vtable references, and padding preserved.
- Exact ordinary destructor UID0004W7 emits R1 through UID0000CB; broad UID0001G5, physical UID0001OX, and vtable UID0003CI are non-emitting evidence pages; semantic UID0000S7 emits the sole global definition.
- Complete R3 is emitted before qualified definitions. The target x86 MSVC verifier required `__declspec(align(4))` on the provisional `0x420` byte member; with that correction, every direct base, Pane facet, bounded storage span, later member, and `sizeof(ScreenPane)==0x5b4` assertion passes.
- Current command-`000000016594` foreground-generated `ScreenPane.cpp` (SHA256 `D99D96E1A714FA4B29115566BD265D9CB88BE566C4D89AD8261DD41914B8FC02`, 17,128 bytes / 543 lines) contains one class declaration, one ordinary destructor, one semantic `g_pScreenPane` definition, R8-R10 once, zero ScreenPane-family Empty Emitter Markers, and no target helper/wrapper, raw vtable/RTTI, explicit base teardown, EH/cookie, target addresses, or stale member spelling. The same checkpoint's `Surface.cpp` (SHA256 `588DCFA2EAD64219E6E5647501908F03D31C5A1F9BF68015252E54CFDD60FEFA`, 24,128 bytes / 681 lines) contains UID00029V once as one external zero-initialized R7 pair and no UID00029V marker or stale static/`-1` roots; exactly 18 unrelated Surface Empty Emitter Markers remain outside this callback.

### Pre-Callback Defects (Historical Gate 1 State)

- The target correctly records five modeled functions, target-internal `0x00559b4c-0x00559b50` padding, predecessor/successor padding, the three adjustor immediates, vtable references, and the deleting-wrapper calls.
- The target incorrectly labels `0x00559b20` as source-authored. Fresh bounded constructor disassembly proves its only xref is the constructor EH funclet at `0x006071df`, which loads the saved ScreenPane object, adds `0xfc`, and tail-jumps to the clear. This is the unwind destructor for the empty `Singleton<ScreenPane>` base.
- The target's `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000CB` state is therefore incoherent with its intentionally blank C++ and produces an avoidable Empty Emitter Marker.
- The ordinary source destructor is currently trapped inside broad [UID:0001G5] with no exact child and no formal body. Its body is complete enough for a source child after removing compiler lowering.
- UID0001G5 is an address aggregate/index, not a source emitter. Leaving it reconstructable with a blank formal creates a second structurally meaningless marker; its exact source children and the class/file routes must emit instead.
- The current [UID:0003CI] vtable page similarly remains reconstructable/empty even though all bytes are regenerated from the class hierarchy and virtual methods.
- Current singleton documentation has two reconstructable blank emitters, [UID:0000S7] and physical [UID:0001OX], rather than one semantic definition and one non-emitting physical evidence page.
- Current [UID:00029V] emits file-static roots initialized to `(unsigned char **)-1`; live bytes are eight zero bytes, the destructor accepts only null/non-null states, and a file-static `Surface.cpp` definition cannot be referenced by a separately generated `ScreenPane.cpp` destructor. The current formal is both value- and linkage-incoherent.
- Current UID0000CB is reconstructable/emitting but blank, while generated qualified ScreenPane methods already require a compile-visible class declaration. The fresh exhaustive class pass resolves every source-observed member and method needed by accepted ScreenPane bodies. Two physical spans remain semantically unidentified, but omitting them would collapse `0x436` bytes and invalidate every later offset; R3 therefore retains them as bounded first-draft C++03 storage after exhausting the semantic routes documented below.
- Historical artifact status before Gate 1 callback: report-only research artifact with no implementation or lifecycle action. This statement is retained as pre-callback history; current implementation state is recorded above and in the terminal ledger/checklist.

## Executive Recommendation

- Treat UID00023U as one compiler-only island with semantic owner ScreenPane; do not split its five compiler functions into source pages.
- Create [UID:0004W7] at `by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md` for the only source-authored destructor body associated with the island.
- Preserve [UID:0001G5] as the broad source cluster/index, make it false/non-emitting with blank R2, and add the exact source child; the first address-sorted child becomes `Nested:+4`, existing later child [UID:0002VO] becomes `Nested:0`, and successor [UID:0001G6] remains `Nested:-4`.
- Preserve `ScreenPane : public Pane, public FrameHandler, public Singleton<ScreenPane>`. RTTI proves Pane at `0`, Pane-owned EventHandler and TimerHandler facets at `+0xa0/+0xa4`, direct FrameHandler at `+0xf8`, and direct empty Singleton at `+0xfc`, overlapping the first ScreenPane member under old-MSVC EBO.
- Install R3 as a complete C++03-era, compile-visible `ScreenPane` declaration. It declares the exact direct bases, every currently emitted or accepted ScreenPane method needed by this source route, every source-observed member/type, and places `[[CHILDREN]]` after the closed class. It physically represents `[+0x130,+0x550)` as target-MSVC `__declspec(align(4)) unsigned char m_presentationStateStorage[0x420]` and `[+0x582,+0x598)` as `unsigned char m_cursorStateStorage[0x16]`. These are bounded, explicitly provisional first-draft members selected only after palette, region/rectangle, cursor-manager, cursor-descriptor/path, hidden-base, and resource-aggregate routes failed. The explicit first-member alignment is verifier-required: without it the byte array begins at `+0x12d`. The accepted form preserves `sizeof(ScreenPane)==0x5b4` and every known later offset without claiming unsupported semantic types.
- Normalize accepted support bodies to the same declaration: UID00039Y calls inherited `TimerHandler::ScheduleTimer`, UID00039Z uses inherited `m_grafPort.m_surface`, UID0003A3 uses `m_renderSurface`, and UID0002VO records adjusted receiver displacement `+0x511` as primary ScreenPane offset `+0x5b1`.
- Use [UID:0000S7] as the sole `ScreenPane *g_pScreenPane = 0;` definition. Make [UID:0001OX] false/non-emitting physical evidence.
- Make [UID:0003CI] false/non-emitting compiler data with a blank managed body.
- Correct [UID:00029V] to externally linked, zero-initialized pointer roots so the exact destructor body can reference them across the current ScreenPane/Surface source split.

## Supervisor Active Recheck

- The supervisor assigned UID00023U as a report-first direct target and explicitly required a live MCP-backed source/compiler, singleton/global, class-layout, source-placement, child/support, C++, and score pass.
- The target required source-cause repair rather than preserving a mixed reconstructable blank island.
- Every source-bearing item directly required to explain the target is closed here: the ordinary destructor has exact implemented child UID0004W7 and complete C++03 body; R3 supplies a complete compile-visible class; the singleton definition has one semantic emitter; the aggregate, target thunks/wrapper/vtable/physical storage have exact no-code dispositions; lookup-root linkage/value contradictions and the four directly contradictory support spellings/offsets have implemented repairs.
- Unrelated ScreenPane behavior is not silently rewritten. Existing methods, ranges, scores, source routes, and behavior remain preserved; only source-facing member access/declaration consistency and the adjusted browser offset are corrected.

## Inference Research Guidance Check

- Binary facts, current documentation, and inference are separated throughout this report.
- IDA facts: exact functions, bytes, sizes, xrefs, vtable pointers, PMDs, object size, field accesses, branch order, calls, and padding.
- Documentation facts: current UIDs, metadata, source routes, accepted field names, generated output, coverage rows, and historical assumptions.
- Inferences: human source names `ScreenPane::~ScreenPane`, `m_rootLayerList`, `m_fadeCompletionCallback`, and Surface lookup-root spellings; each is tied to direct behavior and capped below original-symbol certainty.
- Existing assumptions treated as uncertain: source-authored `0x00559b20`, independently emitted target, `-1` lookup-root initialization, file-static lookup-root linkage, explicit source singleton clear, and raw vtable emission.
- `by-structure.md` relative nesting is applied as an address-sorted delta, not a child count: parent `0`, first child `+4`, later sibling child `0`, successor parent `-4`.
- No active Wave2/Wave3 authority was used. Any such historical labels encountered in old prose were ignored as stale.

## Heuristic / Inference Reanalysis And Validation

### Singleton-clear identity

- Fresh fact: `sub_559B20` is 11 bytes and only writes `g_pScreenPane = 0`.
- Decisive route: its sole xref is `0x006071df`, a tail-jump EH funclet of constructor `0x00556910`; the funclet computes `this + 0xfc` first.
- Best interpretation: generated unwind destruction for the empty `Singleton<ScreenPane>` direct base, not a standalone `ScreenPaneClearSingleton` source helper.
- Rejected: an explicit file-static cleanup function. No ordinary caller, pointer route, callback table, export, or independent source policy exists.

### Ordinary destructor versus deleting wrapper

- `0x00556a60` is the source-authored ordinary destructor. It has one xref, from the scalar wrapper at `0x00559b56`.
- `0x00559b50` returns `this`, accepts the hidden MSVC deleting flag, always invokes the ordinary destructor, conditionally invokes OperatorDeleteWrapper for bit 1 unless bit 4 is set, and takes the size-`0x5b4` guard path for bit 4.
- Best source representation: one virtual `~ScreenPane()` declaration and ordinary body; compiler regenerates the scalar wrapper and three adjustments.
- Rejected: hand-authored flag argument, explicit `operator delete`, size guard, or return-this wrapper.

### Singleton clear in the ordinary destructor

- At `0x00556c16`, the binary clears `g_pScreenPane`, then destroys the `FrameHandler` base at `+0xf8`, then calls the Pane destructor on the complete object.
- Reverse direct-base order proves the clear is the inlined `Singleton<ScreenPane>` base destructor between the destructor body and the later FrameHandler/Pane base destructors.
- Best source representation: no explicit `g_pScreenPane = 0;` in `ScreenPane::~ScreenPane()`; inheritance expresses the cause.
- Rejected: duplicate explicit clear in the human body.

### Resource fields and source names

- `+0x108`: `m_renderSurface`; initialized null, released first, restored and temporarily installed into the inherited GrafPort by existing ScreenPane support. Historical `m_presentationSurface` is superseded for this slot.
- inherited `+0x18`: `m_grafPort.m_surface`; released second through the Pane-owned GrafPort. Fresh destructor, lost-surface, and traversal comparison rejects a duplicate derived `m_grafPortSurface` member.
- `+0x100`: `m_primarySurface`; released third.
- `+0x10c`: `m_rootLayerList`; constructor allocates 20 bytes and initializes a list-like object; destructor uses virtual scalar delete and nulls it.
- `+0x5a8`: `m_fadeCompletionCallback` of best current type `FunctionObject0 *`; queue helpers and the timer callback establish a zero-argument callback payload, while destructor virtual deletion/nulling proves ownership. `LObject *` remains the accepted base-level ABI observation, not the most specific declaration type.
- The field names are inferred but behaviorally constrained. Raw `this[66]`, `this[6]`, `this[64]`, `this[67]`, and `this[362]` are rejected from formal source.

### Exact class layout evidence and source declaration boundary

| Primary offset | Size / type | Best source-facing member or disposition | Exact evidence |
| --- | --- | --- | --- |
| `+0x000..+0x0f7` | inherited `Pane` | direct base | RTTI PMD `0`; Pane-owned EventHandler/TimerHandler facets appear at primary offsets `+0xa0/+0xa4`. |
| `+0x0f8..+0x0fb` | inherited `FrameHandler` | direct base | RTTI PMD `+0xf8`; constructor vptr store; adjustor thunk subtracts `0xf8`. |
| `+0x0fc` | empty `Singleton<ScreenPane>` plus first derived dword | direct EBO base overlapping `LPDIRECTDRAWSURFACE m_primarySurfaceCreateResult` | RTTI PMD `+0xfc`; constructor publication/unwind; old-MSVC EBO; surface initializer writes the overlapping derived slot. |
| `+0x100/+0x104/+0x108` | three surface pointers | `m_primarySurface`, `m_offscreenSurface`, `m_renderSurface` | Constructor clears all; initializer/blit/restore/destructor distinguish display, offscreen, and render roles. |
| `+0x10c` | `List *` | `m_rootLayerList` | Constructor allocates `List(4,4)`; layer helpers/traversal/destructor use it. |
| `+0x110/+0x111` | two `bool` fields | `m_restoreCooperativeLevelPending`, `m_restoreDisplayModePending` | Constructor word clear; setup sets; restore/destructor test and clear independently. |
| `+0x112/+0x114/+0x116` | three signed `short` fields | `m_screenWidth`, `m_screenHeight`, `m_screenBitDepth` | Constructor parameters/stores, signed accessors, SetDisplayMode consumer. |
| `+0x118` | `bool` | `m_hasPendingDirtyRegion` | MarkDirtyRegion sets; traversal consumes/clears. |
| `+0x119..+0x11b` | natural alignment | no source member | Aligns `RectBounds`. |
| `+0x11c..+0x12b` | `RectBounds` | `m_pendingDirtyRegion` | Exact 16-byte RectBounds helpers and traversal use. |
| `+0x12c` | `bool` | `m_presentationModeEnabled` | Setter pair plus startup/teardown consumers. |
| `+0x12d..+0x12f` | natural alignment | no source member | Alignment before the next physical region. |
| `+0x130..+0x54f` | `0x420` semantically unidentified physical span | provisional target-MSVC `__declspec(align(4)) unsigned char m_presentationStateStorage[0x420]` | No read/write/address-take in constructor, destructor, `0x00556910-0x00559a0f` ScreenPane family, or 145 `g_pScreenPane` xref functions; no ctor/dtor/lifetime call or supported project UDT. Exact occupancy and 4-byte start alignment are mandatory because `m_cursorHandles` begins at `+0x550`. |
| `+0x550..+0x57f` | `HCURSOR[12]` | `m_cursorHandles` | Active-cursor helper and resource loader exact table accesses. |
| `+0x580` | signed `short` | `m_activeCursorIndex` | Compare/store in SetActiveCursor; constructor-side default is independent of handle loading. |
| `+0x582..+0x597` | `0x16` semantically unidentified physical span | provisional `unsigned char m_cursorStateStorage[0x16]` | Same bounded negative pass; apparent decompiler offsets in this band resolve to adjusted secondary receivers into known tail fields. Exact occupancy is mandatory because fade state begins at `+0x598`. |
| `+0x598/+0x59a` | two signed `short` fields | `m_fadeCurrentValue`, `m_fadePreviousValue` | Constructor and timer/presentation transition copies. |
| `+0x59c` | `bool` | `m_presentationDirty` | Traversal/render state. |
| `+0x59d` | natural alignment | no source member | Aligns signed-short jitter state. |
| `+0x59e/+0x5a0` | two signed `short` fields | `m_presentationJitterX`, `m_presentationJitterY` | Presentation draw/transition consumers; constructor clears the pair by dword store. |
| `+0x5a2..+0x5a3` | natural alignment | no source member | Aligns dword transition state. |
| `+0x5a4` | `int` | `m_fadeTransitionState` | Callback helpers, timer callback, transition and traversal paths. |
| `+0x5a8` | `FunctionObject0 *` | `m_fadeCompletionCallback` | Queue/timer payload flow and owned virtual delete/null. |
| `+0x5ac` | `int` | `m_fadeStep` | Constructor/timer/presentation countdown state. |
| `+0x5b0/+0x5b1/+0x5b2` | three `bool` fields | `m_forceFullRedraw`, `m_browserNotificationPending`, `m_pointerInputActive` | Presentation path; browser adjusted-receiver writes; constructor and WndProc/browser-default writes. |
| `+0x5b3` | natural tail alignment | no source member | Exact complete size `0x5b4`. |

### Lookup-table roots

- Live bytes at `0x0069b3d8-0x0069b3e0` are `00 00 00 00 00 00 00 00`.
- The destructor tests each root only for null, frees 256 child pointers, then frees the root. No `-1` sentinel handling exists.
- The initializer writes each root later; 12/11 exact xrefs prove shared use.
- Best source initializer: `0`, not `(unsigned char **)-1`.
- Best current linkage: external linkage. The accepted source route emits the definitions in `Surface.cpp` while the destructor emits in `ScreenPane.cpp`; `static` would make the direct destructor references impossible across those translation units.
- Rejected: retaining `-1`, retaining file-static linkage, moving the roots into ScreenPane ownership, or inventing a call to a non-observed cleanup helper.

### DirectDraw restoration

- The ordinary destructor duplicates accepted `ScreenPane::RestoreDirectDrawState` behavior after releasing surfaces.
- Preserve exact branch order: display-mode flag `+0x111` only when `ApplicationActiveGate == 0`, then cooperative-level flag `+0x110` regardless of that gate.
- Preserve `RestoreDisplayMode`, `SetCooperativeLevel(hwnd,DDSCL_NORMAL)`, negative-HRESULT pointer throws, and the unusual temporary DDError formatter side call before the second throw.
- Rejected: factoring a call to `RestoreDirectDrawState()`. The binary contains the body inline in the destructor, and ordinary 2000-era compilation without LTO would not recreate the same direct sequence from an out-of-line call.

### Class hierarchy and complete source declaration

- RTTI/PMDs prove direct source order `Pane`, `FrameHandler`, `Singleton<ScreenPane>` and complete size `0x5b4`.
- Pane supplies EventHandler and TimerHandler facets at `+0xa0/+0xa4`; direct FrameHandler begins `+0xf8`; empty Singleton begins/overlaps `+0xfc`.
- Fresh decompilation of constructor `0x00556910`, timer callback `0x00556d50`, frame callback `0x00557070`, presentation methods, WndProc/browser routes, and all 145 singleton xref functions closes every field and signature used by accepted qualified ScreenPane bodies. The timer callback is source-facing `OnTimer(int,int,int)`, not historical generic `HandleMessage`; the frame callback is `OnFrameUpdate(const FrameUpdateContext *)`, where dispatcher `0x004b6f60` proves the three-field `callbackFrame/currentFrame/dispatching` record.
- The only remaining semantic uncertainty is the identity of the two physical spans in the table. Bounded local-family and singleton-xref searches found no source operation or type/lifetime evidence. Current project UDT inspection has no ScreenPane, Pane, FrameHandler, TimerHandler, CursorManager, Region, or NotificationBlock layout that can account for them. Live constructor `0x00556910` does not initialize either span, and ordinary destruction performs no matching lifetime action.
- Palette hypothesis: `DDPIXELFORMAT` (`0x20`) plus `PALETTEENTRY[256]` (`0x400`) arithmetically totals `0x420`, but no ScreenPane receiver accesses either object, no palette lifetime call exists, and current palette behavior routes through the separate global `PaletteLib`. Exact arithmetic alone is insufficient to assert those types.
- Region/rectangle hypothesis: `0x420` could hold 66 `RectBounds` records or a 64-record array plus metadata, but the one proven dirty rectangle is already at `+0x11c`, Region methods do not receive an address inside the span, and no list/count/iterator consumer exists.
- Cursor/resource hypothesis: an embedded CursorManager, 12 cursor descriptors, resource-path matrix, or presentation resource table is rejected. Current CursorManager documentation is a superseded alias over `g_pScreenPane`; cursor loading uses literal paths and writes the proven `HCURSOR[12]` table at `+0x550`; no separate constructor, destructor, allocation, RTTI, receiver, or address-take reaches either span.
- Small-span hypotheses: `wchar_t[11]`, eleven signed shorts, fade/cursor flags, or a compact resource descriptor all fit `0x16`, but no access establishes element width or role. Apparent `+0x58x` decompiler references normalize from secondary receivers into proven fields at `+0x598` and later.
- Hidden-base and compiler-padding hypotheses are also rejected: RTTI gives the complete direct-base PMDs, constructor vptr/lifetime order has no additional base, and `0x420` cannot be silently discarded as alignment when the deleting wrapper proves complete size `0x5b4`.
- Because every semantic route is exhausted but physical occupancy is certain, the highest-probability safe first draft is named byte storage adjacent to the nearest proven presentation/cursor state. The presentation member carries target-MSVC 4-byte alignment verified by the callback compiler; both arrays remain transparent provisional members, not claims of original names or final types. C++03 `unsigned char` imposes no unobserved construction/destruction behavior while preserving all downstream offsets. Future semantic evidence must replace each member with an equally sized/aligned human type rather than remove it.
- R3 therefore supplies a complete, physically coherent first-draft declaration: it preserves all `0x5b4` bytes, closes the class marker, and maintains every known base/member offset. Semantic identity of the two storage members remains the confidence cap, not an excuse for a byte-collapsing declaration.

### Secondary receiver and support-formal normalization

- Browser handler disassembly writes receiver displacement `+0x511` only after entry through the EventHandler facet at primary `+0xa0`; the primary ScreenPane member is therefore `+0x5b1`. Current `+0x511` class/browser prose is an adjusted-receiver artifact, not a second field.
- UID00039Y currently writes `m_timerHandler.ScheduleTimer`, but RTTI/vptr/caller evidence proves TimerHandler is an inherited Pane facet at `+0xa4`, not an embedded derived member. R8 uses `TimerHandler::ScheduleTimer`.
- UID00039Z currently writes `m_grafPortSurface`; Pane/GrafPort lifecycle and traversal prove the source access is inherited `m_grafPort.m_surface`. R1 and R9 use that spelling.
- UID0003A3 currently writes `m_presentationSurface`; constructor/destructor/restore/initializer evidence standardizes `+0x108` as `m_renderSurface`. R10 applies that one source-name correction without changing traversal behavior.

### Source placement

- Destructor and singleton definition belong to `NexusTK/ui/core/ScreenPane.cpp` under [UID:0000NB].
- Lookup-root definitions remain under `NexusTK/render/Surface.cpp` under [UID:0000OC], with external declarations consumed by ScreenPane.
- Target thunks/vtable/physical storage have semantic ownership but no source emitter.

## Evidence Standards Used

- Mandatory live evidence: MCP `idb_list`, `server_health`, bounded `get_bytes`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, and current IDB-backed pointer/RTTI reads.
- Backing PE identity: SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Target body SHA256: `150A642F2D46EB7C7731976CFD849FDCEF886063844F88EC5255A2CE42E616B8` over exact 107 bytes.
- Ordinary destructor body SHA256: `8A826794A8189177FB52EB2E694E53B569F785671B61F31CBF775DCC6565E1B1` over exact 628 bytes.
- Constructor body SHA256: `F0586B3ED818587CC589F73D24B3205AFEE4F3354571A25648DC36BB2AF058E6` over exact 330 bytes.
- Corroboration: current by-* docs, generated C++, manual coverage, tracker, executed reports, active goals, and lease ledger.
- Confidence remains below original-symbol proof because exact private field spellings and the semantic types of two physical spans are not recovered. The exhaustive negative boundary justifies bounded byte storage as a last-resort first draft; R3 now preserves exact byte occupancy, downstream offsets, and complete size instead of claiming semantic certainty or collapsing the layout.

## Evidence Checked

- Fresh `idb_list` returned active session `9b0396a3`, NexusTK IDB `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`, worker PID 15732, `is_analyzing:false`.
- `server_health(database=9b0396a3)` returned `status:ok`, imagebase `0x400000`, module `NexusTK.exe`, input path `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, and ready auto-analysis, Hex-Rays, and strings cache (2,067 strings).
- Valid bounded `get_bytes` at `0x00559b20` succeeded after schema correction and returned `c7 05 cc a7 67 00 00 00 00 00 c3 81 e9 a0 00 00`.
- Final repair availability recheck rediscovered active database `9b0396a3`, returned `server_health status:ok` with analysis/Hex-Rays/strings ready, and repeated the same bounded 16-byte target read; malformed client requests during schema discovery were not treated as IDB evidence or an MCP outage.
- This Gate 1 layout repair reused live session `9b0396a3`: fresh `analyze_function` and bounded `disasm` for constructor `0x00556910` succeeded and reconfirmed the `0x5b4` allocation/layout route, all known initialization writes, and no initialization of either unidentified span. A later over-broad supplemental displacement query timed out while the MCP listener and IDA worker remained present; it is excluded from evidence and does not replace the already documented bounded negative pass.
- Exact target, constructor, destructor, target-neighbor, vtable, RTTI, lookup-root, timer callback, frame callback, presentation, browser, WndProc, and frame-dispatch byte ranges were read.
- Exact functions at `0x00559b20`, `0x00559b2b`, `0x00559b36`, `0x00559b41`, `0x00559b50`, `0x00556910`, `0x00556a60`, `0x00556d50`, `0x00557070`, `0x00557140`, `0x005583a0`, `0x00558840`, `0x00559410`, `0x005595d0`, and frame dispatcher `0x004b6f60` were bounded/analyzed or decompiled as applicable; non-function boundaries and next start `0x00559b90` were checked.
- Constructor and destructor disassembly included EH funclets and tail cleanup; deleting wrapper and helper disassembly were complete.
- Xrefs were checked for all five target starts, `g_pScreenPane`, the four vtable starts, and both lookup roots. The 145 `g_pScreenPane` xrefs were grouped across 94 functions and checked for primary-object accesses; none accesses `[+0x130,+0x550)` or `[+0x582,+0x598)`.
- Current ordinary docs checked: UID00023U, UID0001G5, UID0002VO, UID0000CB, UID0000NB, UID0000S7, UID0001OX, UID0003CI, UID00029V, UID0000OC, UID00039Y, UID00039Z, UID0003A3, Pane, FrameHandler, TimerHandler, CursorManager, List, RectBounds, Region, Layer, and FunctionObject0 support.
- Gate 1 layout repair also reopened executed B002/B010/B012/B007 cursor/presentation/palette support and archived `unrefined-source-backup/source/ScreenPane.cpp`, `re-agent/reports/code/0x00556910_ScreenPane_ctor_0x556910.cpp`, `re-agent/reports/code/0x00556a60_ScreenPane_dtor_0x556a60.cpp`, and `hooks-generation/cached/search/ScreenPane.txt`. They confirm direct cursor-table ownership, global PaletteLib routing, adjusted-receiver tail offsets, and no recovered semantic declaration for either span.
- Current command-`000000016594` foreground-generated `ScreenPane.cpp` and `Surface.cpp`, final settled tracker target row, current manual coverage roots, completion stats, active goals, executed reports, and current leases were read. The generated headers, exact hashes/sizes/line counts, accepted semantic occurrence counts, zero ScreenPane markers/stale names/target addresses/vtable/RTTI, UID00029V external-zero/no-stale-root state, and exactly 18 unrelated Surface markers outside this callback were independently rechecked during this report-only repair.
- Final settled tracker readback: command `000000016626`, `2026-07-22T22:16:12-04:00`, source `deferred-generated-refresh`, SHA256 `331381565D56CC8ED83F7FD7234C22A81CF8FF1E8109543A12FA4E5C2A724C23`, 1,634,570 bytes / 6,507 lines. Summary is 5,585 tracked, 2,035 covered, 3,550 not covered, 36.4%. UID00023U occurs at line 5426 as `92/94`, combined `93.0`, reconstructable `false`, zero direct coverage, zero additional coverage, zero B-report coverage, and path `by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md`. Earlier tracker line/identity statements are historical.
- Historical pre-final callback readback recorded UID00023U SHA256 `33E4EA2A313651961E270AE61FF39E5C1325D4CE10162704C3FE1165505A8D90`. The current read-only target check for this repair is SHA256 `F209E8C8B997290031FD9D39D755F9FC4C8DEC67633A1A94A6A09640A2C0AF3F`, 12,969 bytes / 131 lines, and supersedes that older target snapshot. The same implementation-time readback confirmed these other intended ordinary destinations and SHA256 values: UID0001G5 `4FF784387C42DE607DD3C5CCB35D0884D5CC5CAC45E52928BE7A01797431FE65`; UID0002VO `FB37AC7F2F4C403A5A907772D63359F7913640ADCD62F853B6DC93119492C87F`; UID0000CB `BE647C6715CE35ED194875339A23B1EAFD08BD2B38C14584AA7F31222DFD660A`; UID0000NB `2617BECA055DE076820627B7F549464E598231AFBE50CCDFC601243C7F12097E`; UID0000S7 `2F47025009498E2BD86A86FCFEABA993B2DF40BC2A491F72F8F70CC9CA8BEA45`; UID0001OX `5685CF406773370E3F6D3FB8DF15232E8DA05B06E06F9FF0825048EA7A18B9CA`; UID0003CI `181492AC135164C2B05BD6A0A8D0ECFD0B7CD9FB5F875AB347A84BE06043F125`; UID00029V `02D7F462A847D3D78FF3B562C35DE55D5781D077785DD2D0FC628D770A01056A`; UID0000OC `DEACFBF623AA152451583F1BB98731C9D834117F7EC4A23544CE676F12713D3B`; UID00039Y `9ED0B446A7C20AC95C61E38D9E747E0A66F785F0BF2890932F93CC4AED941BE8`; UID00039Z `CAA12FEA4ADFC0169332C6A0C1D00D3D05DF92D331D1BB2AADDF9B907748F87B`; UID0003A3 `63E07B802B7FC29671A2D8017DD68C5F9F38854255335029F13C12375CFBD388`.
- Historical searches covered `executed-b-agent-research/**`, `Older-Research/**`, `SpecialReports/**`, and active B001-B005 research roots with all exact terms listed under Supporting Research.
- Negative checks: no ordinary target callers; no independent helper pointer route; no source method inside UID00023U; no second singleton storage; no source need for wrapper flags, vptr stores, RTTI/vtable arrays, explicit bases, EH/cookies, or target padding; no source access/lifetime/type evidence for either unidentified class span; no separate CursorManager object; no support for asserting a palette, region array, cursor descriptor/path matrix, hidden base, or other semantic aggregate. Negative semantic evidence does not permit physical omission, so R3 retains exact bounded storage.
- During the evidence-only Gate 1 layout-repair pass described in this section, B003 performed no IDA mutation, validator, lease, generated refresh, coverage edit, lifecycle command, or report execution. This is an actor/time-scoped statement; validator footer commands `000000016527` and `000000016537` remain the authoritative later lifecycle history.

## Claim And Incorporation Ledger

Target UID is the single normalized primary UID for each claim. A destination may name related support documents without making the row multi-target. Actions and states use only the controlled terminal vocabulary required by the report contract.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | State |
| --- | --- | --- | ---: | --- | --- | --- | --- |
| C01 | `00023U` | Mandatory session `9b0396a3` was healthy; analysis, Hex-Rays, and strings cache were ready; bounded target bytes succeeded. | 99 | `idb_list`, `server_health`, `get_bytes`. | UID00023U MCP evidence; support current-state prose. | incorporate | applied |
| C02 | `00023U` | Exact target range is `0x00559b20-0x00559b8b`, 107 bytes, SHA256 `150A...16B8`, with predecessor `[0x00559b1d,0x00559b20)` and successor `[0x00559b8b,0x00559b90)` padding. | 99 | Function lookups, bytes, B001 predecessor report. | UID00023U range/boundary sections. | incorporate | applied |
| C03 | `00023U` | UID00023U contains five functions and internal `[0x00559b4c,0x00559b50)` padding with exact starts/sizes/instruction/block/xref inventory. | 99 | Analyze/disasm/xrefs/vtable bytes. | UID00023U inventory and Item Summary. | incorporate | applied |
| C04 | `00023U` | `0x00559b20` is constructor-unwind cleanup for `Singleton<ScreenPane>` at `+0xfc`, not a source helper. | 99 | Sole xref `0x006071df`; constructor tail disassembly. | UID00023U, UID0001G5, UID0000CB, UID0000S7/1OX. | historicalize | applied |
| C05 | `00023U` | Three adjustors and `0x00559b50` scalar deleting wrapper are compiler ABI output from virtual destruction and facets. | 99 | Tail-jump bytes, vtable refs, wrapper flags/calls. | UID00023U and UID0003CI. | incorporate | applied |
| C06 | `0000CB` | RTTI proves `ScreenPane : Pane, FrameHandler, Singleton<ScreenPane>`, PMDs `0/+0xf8/+0xfc`, Pane facets `+0xa0/+0xa4`, old-MSVC EBO, size `0x5b4`, and four virtual views; R3 expresses the direct hierarchy. | 98 | RTTI/COL/CHD/base descriptors; constructor stores; wrapper size. | UID0000CB R3, UID0003CI, UID00023U. | incorporate | applied |
| C07 | `0000CB` | Constructor `0x00556910-0x00556a5a` publishes the singleton through the base and initializes exact surfaces/list/flags/dimensions/dirty/fade/pointer-input state; the full field table distinguishes natural alignment from two semantically unidentified but physically mandatory spans. | 98 | 330-byte function, 92 instructions, EH tails, family/xref negative scan. | UID0001G5 index, UID0000CB R3, singleton support. | incorporate | applied |
| C08 | `0004W7` | Ordinary destructor `0x00556a60-0x00556cd4`, 628 bytes, frees both 256-entry lookup families and each root without post-free root clears. | 98 | Complete decompile/disasm and lookup xrefs. | UID0004W7, UID0001G5, UID00029V. | incorporate | applied |
| C09 | `0004W7` | Destructor releases `m_renderSurface`, inherited `m_grafPort.m_surface`, and `m_primarySurface` in that order and nulls each; R1/R9/R10 use one source-facing field vocabulary. | 98 | Destructor instructions and accepted surface/traversal support. | UID0004W7 R1, UID0000CB/0NB, UID00039Z R9, UID0003A3 R10. | incorporate | applied |
| C10 | `0004W7` | Destructor preserves exact two-branch DirectDraw restore behavior and DDError side effects. | 97 | Destructor disasm plus UID00039R accepted evidence. | UID0004W7, UID0001G5, UID0000CB. | incorporate | applied |
| C11 | `0004W7` | Destructor deletes/nulls root layer list `+0x10c` and the `FunctionObject0 *` fade callback `+0x5a8`. | 97 | Virtual-delete sequence; queue/timer payload flow; constructor/callback docs. | UID0004W7, UID0001G5, UID0000CB R3. | incorporate | applied |
| C12 | `0004W7` | Human destructor must omit explicit singleton clear, vptr stores, base calls, wrapper flags, delete wrapper, EH, cookies, and raw addresses. | 99 | Destruction order and compiler ABI evidence. | UID0004W7 formal/prose. | reject-invalid | excluded-with-reason |
| C13 | `00023U` | UID00023U should be `92/94`, owner UID0000CB, false, blank emitter/position/formal, Nested0, no target split. | 98 | C02-C06. | UID00023U metadata and R0. | incorporate | applied |
| C14 | `0004W7` | Create UID0004W7 exact destructor child, `92/94`, owner/emitter UID0000CB, true, blank position, Nested+4, R1. | 96 | C08-C12 and exact source route. | New by-memory page. | incorporate | applied |
| C15 | `0001G5` | Make UID0001G5 a `91/93` false/non-emitting broad index with blank R2, add the exact child; change UID0002VO Nested+4 to 0 and correct adjusted `+0x511` to primary `+0x5b1`; retain parent 0 and UID0001G6 -4. | 98 | Address-sorted delta rules, vtable facet `+0xa0`, handler disassembly, current rows. | UID0001G5, UID0002VO; verify UID0001G6. | incorporate | applied |
| C16 | `0000CB` | Install complete compile-visible R3, raise ScreenPane class to `92/93` and file to `93/94`, preserve exact binary `0x5b4` occupancy with target-MSVC-aligned provisional `0x420` presentation-state and exact `0x16` cursor-state byte members, declare current/accepted methods, normalize UID00039Y/39Z/3A3 with R8-R10, require zero class/aggregate markers, and verify every known base/member offset. | 96 | Constructor/destructor/callback/presentation decompiles, 145-xref negative scan, RTTI, semantic-hypothesis elimination, x86 MSVC class-layout output and compile-time assertions. | UID0000CB R3, UID0000NB, UID00039Y R8, UID00039Z R9, UID0003A3 R10. | incorporate | applied |
| C17 | `0000S7` | UID0000S7 becomes sole `ScreenPane *g_pScreenPane = 0` source definition at 92/94; UID0001OX becomes 92/94 false/non-emitting physical evidence. | 98 | Zero bytes, 145 xrefs, constructor/destructor/unwind cause. | UID0000S7 R4; UID0001OX R5. | incorporate | applied |
| C18 | `0003CI` | UID0003CI becomes `92/94`, owner UID0000CB, false, blank emitter/position/formal, Nested8; no raw vtable/RTTI arrays. | 99 | Exact vtable/RTTI/PMD and vptr-store evidence. | UID0003CI R6. | incorporate | applied |
| C19 | `00029V` | UID00029V becomes `92/94` with zero-initialized externally linked roots; owner/emitter UID0000OC and position10 remain; Surface file records cross-TU use without score change. | 97 | Zero bytes, xrefs, destructor source, current generated split. | UID00029V R7 and UID0000OC. | incorporate | applied |
| C20 | `00023U` | The exact no-loss manual coverage set for the target, new child, non-emitting parent/browser correction, complete class/file route, normalized helper/traversal rows, global/physical/vtable/lookup roots, and Surface source row is already present once in the current supervisor-owned roots. | 99 | Current manual-root readback and hashes. | Supervisor-owned manual roots. | already-present | already-present |

## Positive Evidence Summary

- The only `0x00559b20` xref is a constructor EH tail using `this+0xfc`, exactly the Singleton PMD.
- The three target adjustments match secondary vtable facets at `+0xa0`, `+0xa4`, and `+0xf8`.
- The primary vtable points to `0x00559b50`; the wrapper calls the one ordinary destructor and uses standard deleting flags.
- Constructor and destructor vptr stores match all four table views.
- RTTI names ScreenPane, FrameHandler, and `Singleton<ScreenPane>` and gives exact PMDs.
- The ordinary destructor's resource behavior is fully recoverable and agrees with constructor and accepted ScreenPane field evidence.
- The singleton clear order matches reverse direct-base destruction, proving source cause without an explicit product helper.
- Current zero lookup-root bytes and direct null checks reject the stale `-1` formal.
- The current source split proves the lookup roots cannot remain file-static if the destructor is emitted in ScreenPane.cpp.
- Constructor, callbacks, presentation bodies, and all singleton consumers jointly account for every member named by R3; no accepted qualified definition needs an undeclared class member or method.
- Primary/secondary receiver arithmetic resolves the browser byte to primary `+0x5b1`, TimerHandler access to the inherited `+0xa4` facet, and GrafPort surface access to inherited `m_grafPort.m_surface`.
- The deleting-wrapper `0x5b4` size, direct-base PMDs, cursor table at `+0x550`, fade state at `+0x598`, and all later field accesses jointly require exact occupancy of both unidentified spans. The two bounded byte members satisfy that hard physical constraint without adding construction, destruction, or behavior absent from the binary.

## IDA MCP Facts

- Active evidence session: `9b0396a3`; health `ok`; imagebase `0x400000`; analysis/Hex-Rays/strings ready.
- `0x00559b20-0x00559b2b`: 11 bytes, 2 instructions, 1 block, one xref from `0x006071df`.
- `0x00559b2b-0x00559b36`, `0x00559b36-0x00559b41`, `0x00559b41-0x00559b4c`: 11 bytes each, `sub ecx,0xa0/0xa4/0xf8; jmp 0x00559b50`, one vtable data xref each.
- `0x00559b4c-0x00559b50`: four `0xcc` bytes.
- `0x00559b50-0x00559b8b`: 59 bytes, 25 instructions, 5 blocks, complexity 2, calls ordinary destructor, OperatorDeleteWrapper, and bit-4 size guard.
- Target bytes:
  `c7 05 cc a7 67 00 00 00 00 00 c3 81 e9 a0 00 00 00 e9 1a 00 00 00 81 e9 a4 00 00 00 e9 0f 00 00 00 81 e9 f8 00 00 00 e9 04 00 00 00 cc cc cc cc 55 8b ec 56 8b f1 e8 05 cf ff ff 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 54 af f9 ff 83 c4 04 8b c6 5e 5d c2 04 00 68 b4 05 00 00 56 e8 1f 1b ec ff 83 c4 08 8b c6 5e 5d c2 04 00`.
- External padding: `0x00559b1d-0x00559b20` is three `cc`; `0x00559b8b-0x00559b90` is five `cc`.
- Constructor `0x00556910` size `0x14a`; ordinary destructor `0x00556a60` size `0x274`; wrapper embeds object size `0x5b4`.
- Vtable bases: primary `0x006230ec`, adjusted `0x00623138`, `0x00623168`, `0x00623174`; COL `0x0064ee50`.
- Lookup roots: exact live bytes are eight zeroes; xref totals 12 and 11.
- `g_pScreenPane`: 145 xrefs; lifecycle writes/clears at `0x00556962`, `0x00556969`, `0x00556c16`, and `0x00559b20`.
- Timer callback `0x00556d50` receives the Pane-owned TimerHandler-adjusted view and implements `OnTimer(int,int,int)`; frame callback `0x00557070` receives the direct FrameHandler-adjusted view and consumes the three-field record passed by dispatcher `0x004b6f60`.
- Browser writes at adjusted `+0x511` enter through the EventHandler view at primary `+0xa0`, proving primary ScreenPane member `+0x5b1`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00556910-0x00557132` | UID0001G5 `ScreenPane.md` | Broad source cluster/index. | false, blank R2 | UID0000CB | 91/93 | non-emitting index; exact children/class route emit |
| `0x00556a60-0x00556cd4` | UID0004W7 `ScreenPaneDestructor.md` | Ordinary source destructor. | true, R1 | UID0000CB | 92/94 | registered first; Nested+4 |
| `0x00556f70-0x00557070` | UID0002VO existing browser child | Existing source method. | true, existing formal | UID0000CB | 88/90 | preserve body; Nested 4 -> 0; primary field +0x5b1 |
| `0x00557140-0x00559aef` | UID0001G6 mixed presentation index | Existing non-emitting successor container. | false | mixed | 88/current | verify unchanged; Nested-4 |
| `0x00559b20-0x00559b2b` | UID00023U subrange | Singleton base unwind cleanup. | false | UID0000CB | parent 92/94 | compiler-only |
| `0x00559b2b-0x00559b4c` | UID00023U subranges | Three adjustor thunks. | false | UID0000CB | parent 92/94 | compiler-only |
| `0x00559b4c-0x00559b50` | UID00023U subrange | Internal alignment. | false | parent-only | parent 92/94 | no child |
| `0x00559b50-0x00559b8b` | UID00023U subrange | Scalar deleting destructor. | false | UID0000CB | parent 92/94 | compiler-only |
| `0x006230e8-0x0062317c` | UID0003CI vtable data | COL and four vtable views. | false | UID0000CB | 92/94 | no raw source |
| `0x0067a7cc-0x0067a7d0` | UID0001OX | Physical singleton slot. | false | UID0000S7 | 92/94 | semantic source covers storage |
| semantic global | UID0000S7 `g_pScreenPane.md` | Sole source definition. | true, R4 | UID0000NB | 92/94 | source-bearing |
| `0x0069b3d8-0x0069b3e0` | UID00029V | Two shared lookup roots. | true, R7 | UID0000OC | 92/94 | correct zero/linkage |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006071df -> 0x00559b20` | sole code xref; constructor EH funclet | Destroys Singleton base during constructor unwind. |
| `0x00623138 -> 0x00559b2b` | adjusted vtable entry | EventHandler facet adjustment `-0xa0`. |
| `0x00623168 -> 0x00559b36` | adjusted vtable entry | TimerHandler facet adjustment `-0xa4`. |
| `0x00623174 -> 0x00559b41` | adjusted vtable entry | FrameHandler facet adjustment `-0xf8`. |
| `0x006230ec -> 0x00559b50` | primary vtable entry | Complete-object scalar deleting destructor. |
| `0x00559b31/3c/47 -> 0x00559b50` | thunk tail jumps | Shared wrapper target, not callers in product source. |
| `0x00559b56 -> 0x00556a60` | wrapper call | Sole xref to ordinary destructor. |
| `0x00559b67 -> 0x004f4ac0` | OperatorDeleteWrapper | Hidden deleting flag bit-1 lowering. |
| `0x00559b7c -> 0x0041b6a0` | size guard with `0x5b4` | Hidden bit-4 compiler/runtime path. |
| `0x00556ab6/cf/aec/b05` | lookup-root reads | Destructor loops/free for both roots. |
| `0x00556c16` | global clear before FrameHandler/Pane bases | Inlined Singleton base destructor. |
| `0x00556962/69` | constructor publish/fallback clear | Inlined Singleton base constructor behavior. |

## Documentation Evidence And IDA Status

- Historical pre-callback UID00023U had strong function/byte/vtable evidence but stale source-authored wording and reconstructable/emitting metadata. Current UID00023U is `92/94`, false/non-emitting, owner UID0000CB, blank formal, and retains the exact evidence under the compiler-island disposition.
- Historical pre-callback UID0001G5 contained the exact destructor range and broad resource summary but had no exact destructor child and remained a reconstructable blank aggregate. Current UID0001G5 is `91/93`, false/non-emitting with blank R2, and exact source child UID0004W7 carries the implemented ordinary destructor.
- Historical pre-callback UID0000CB had accepted method/field/hierarchy evidence but a blank emitted class formal. Current UID0000CB is `92/93` with complete physically coherent R3, including both bounded storage spans and verified `sizeof(ScreenPane)==0x5b4`.
- UID0000NB remains the correct ScreenPane source root; current state is `93/94` and owns the complete emitted ScreenPane method/class/global route.
- Historical pre-callback UID0000S7/UID0001OX duplicated blank reconstructable states. Current UID0000S7 is the sole semantic `g_pScreenPane` definition at `92/94`, while current UID0001OX is `92/94`, false/non-emitting physical storage owned by UID0000S7.
- Historical pre-callback UID0003CI had exact table facts but stale reconstructable/emitting metadata. Current UID0003CI is `92/94`, false/non-emitting, owner UID0000CB, with blank formal and `Nested:8`.
- Historical pre-callback UID00029V preserved both `ff` and later zero observations while leaving the disproven `-1`/static formal active. Current UID00029V is `92/94` and emits externally linked, zero-initialized R7 through UID0000OC.
- Generated commands `000000016371`, `000000016419`, and `000000016426` are historical pre-callback checkpoints. Command `000000016426` at `2026-07-22T16:16:56-04:00`, SHA256 `6B5D283C0D550BDA7C8824D2D11965D8657379B006DD0F1C63CFF1E693F2CAC9`, still had the six UID00023U/UID0003CI/UID0000S7/UID0001OX/UID0000CB/UID0001G5 Empty Emitter Markers, 14 qualified ScreenPane definitions, no ordinary destructor definition, and no handwritten raw vtable arrays. The completed callback removed those route-caused markers; implementation-time final waited command `000000016487` produced the corrected historical callback-generation output recorded under Validator Results, and unrelated foreground commands `000000016565` and `000000016569` regenerated the same accepted semantic shape as historical intermediate checkpoints. Later repository-wide foreground command `000000016594` is the current exact generated checkpoint.
- Manual coverage snapshots and exact evidence-time rows are recorded under the dedicated manual section. The B004 root epoch is historical. All 14 C20 rows are already present exactly once at the current root/anchor epoch and still match the report text after later unrelated root drift. Their ledger/checklist state is terminal `already-present`; any future supervisor independent readback/validation or no-loss drift repair is outside B003 work. B003 did not edit any manual coverage file.

## Ranked Ownership Analysis

### 1. ScreenPane / ScreenPane.cpp

- Evidence for: ordinary destructor receiver, ScreenPane vtables and RTTI, Singleton base, exact global, fields, source cluster, and all wrapper/table references.
- Evidence against: none for semantic ownership; target itself is compiler output and therefore should not emit.
- Decision: accepted semantic owner for target/compiler pages and direct owner/emitter for the new ordinary destructor.

### 2. Singleton template support

- Evidence for: `+0xfc` PMD, constructor EH funclet, publication/fallback clear, reverse-order destructor clear.
- Evidence against: no separate by-file source root or independently authored target method; template code is a source cause within ScreenPane's class declaration.
- Decision: accepted source-cause explanation, rejected as a standalone target owner/emitter.

### 3. Surface / Surface.cpp

- Evidence for: owns shared lookup roots and render callback families.
- Evidence against: does not own ScreenPane object lifetime or destructor body.
- Decision: retain only as lookup-root definition owner; use external linkage for ScreenPane consumption.

### 4. CRT/runtime/operator-delete support

- Evidence for: deleting wrapper calls OperatorDeleteWrapper and guard support.
- Evidence against: dependency only; no NexusTK product ownership.
- Decision: compiler/runtime exclusion.

### Proposed new file/grouping, if applicable

- No new by-file root. New exact method page emits through existing `NexusTK/ui/core/ScreenPane.cpp`.
- No target-internal child pages because all target subfunctions share one compiler-only disposition.

## Source Placement

- `ScreenPane::~ScreenPane()` belongs in [UID:0000NB] `NexusTK/ui/core/ScreenPane.cpp` and is declared by [UID:0000CB] in eventual complete class source.
- `g_pScreenPane` semantic definition belongs in the same ScreenPane source root.
- Lookup-root definitions remain in [UID:0000OC] `NexusTK/render/Surface.cpp`; R1 carries the compatible external declarations required by the accepted cross-translation-unit arrangement.
- Raw vtable/RTTI data, adjustor thunks, scalar wrapper, unwind helper, EH/cookies, and alignment have no human source destination.
- Rejected placements: generic DestructorHelpers.cpp, Singleton.cpp, Surface.cpp for the destructor, CursorManager.cpp, Browser.cpp, and raw memory/assembly source.

## Range / Split / Padding / Reclassification Analysis

- Parent source cluster `[0x00556910,0x00557132)` remains exact.
- New child `[0x00556a60,0x00556cd4)` is wholly inside the parent and exactly matches the one ordinary destructor function.
- Parent-internal padding around the child remains parent-only: `[0x00556a5a,0x00556a60)` six `cc`; `[0x00556cd4,0x00556ce0)` twelve `cc`.
- Existing child `[0x00556f70,0x00557070)` remains exact and becomes the second child at the same nesting level.
- Relative deltas: UID0001G5 `0`; UID0004W7 `+4`; UID0002VO `0`; UID0001G6 `-4`. UID00023U is outside UID0001G5 and remains `0`.
- Target external padding remains separate ignored coverage: `[0x00559b1d,0x00559b20)` and `[0x00559b8b,0x00559b90)`.
- Target internal `[0x00559b4c,0x00559b50)` stays documented on the target; no ignored-child row is needed.
- UID00023U changes classification from reconstructable mixed island to false/non-emitting compiler island without changing path/range/title/owner/Nested.
- UID0003CI changes from reconstructable empty emitter to false/non-emitting compiler data without a range/title split.

## Negative Evidence Summary

- No ordinary caller reaches any target entry.
- No function pointer outside the four vtable slots targets the target entries.
- No target body has a product-source signature independent of constructor/destructor lowering.
- No evidence supports an explicit singleton clear in the ordinary destructor body.
- No evidence supports independent global storage for browser/cursor aliases.
- No evidence supports raw vtable/RTTI arrays, hand-coded adjustors, hidden deleting flags, explicit base-destructor calls, or EH/cookie source.
- No evidence supports a `-1` lookup-root initial value in the current PE/IDB; live bytes are zero and destructor semantics lack sentinel handling.
- No legal cross-TU path supports `static` lookup roots in Surface.cpp plus direct ScreenPane.cpp references.
- No evidence supports asserting a semantic palette, region array, cursor manager/descriptor/path matrix, hidden base, or resource aggregate for either unidentified span. That negative result does not permit physical omission: R3 must retain exact bounded byte storage so the cursor table, fade state, callback pointer, tail flags, and complete `0x5b4` size remain correct.
- No evidence supports historical `m_timerHandler`, `m_grafPortSurface`, `m_presentationSurface`, or primary ScreenPane `+0x511` as independent derived members; inherited/member-normalized forms are required.

## IDA Rename / Type / Comment Recommendations

- Do not mutate IDA during this assignment.
- Documentation/source-facing names:
  - `sub_556A60` -> `ScreenPane::~ScreenPane`.
  - `sub_559B20` -> documentation-only `ScreenPaneSingletonConstructorUnwindCleanup`; never emit as a method.
  - `sub_559B50` -> documentation-only `ScreenPaneScalarDeletingDestructor`; never emit as a method.
  - three thunks -> documentation-only EventHandler/TimerHandler/FrameHandler deleting-destructor adjustors.
  - `dword_67A7CC` -> `g_pScreenPane`.
  - `unk_69B3D8/DC` -> `g_surfaceColorLookup5Bit` / `g_surfaceColorLookup6Bit`.
- Types: `ScreenPane *`, `unsigned char **`, `LPDIRECTDRAWSURFACE`, `List *`, `FunctionObject0 *`, `HCURSOR[12]`, signed `short` dimensions/fade/jitter state, `bool` flags, `RectBounds`, C++ virtual destructor/callback declarations, and provisional C++03 `unsigned char[0x420]` / `unsigned char[0x16]` storage for the two physically proven but semantically unidentified spans.
- Keep exact original private spellings explicitly inferred; do not represent addresses or dword-array indexing in formal C++.

## First-Draft C++ Recommendation

- Eligible source destinations: UID0004W7 ordinary destructor, UID0000CB complete class, UID0000S7 semantic global, UID00029V lookup roots, and normalized UID00039Y/UID00039Z/UID0003A3 methods.
- Exact compiler/no-code destinations: UID00023U, false/non-emitting UID0001G5 aggregate, UID0001OX physical slot, and UID0003CI vtable data have blank managed bodies for the specific reasons recorded below.

### R0 - UID00023U target, exact blank compiler block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: all target functions are constructor unwind, adjustor, or deleting-wrapper lowering; source is represented by R1, ScreenPane inheritance, and R4.

### R1 - UID0004W7 ScreenPane ordinary destructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern unsigned char **g_surfaceColorLookup5Bit;
extern unsigned char **g_surfaceColorLookup6Bit;

ScreenPane::~ScreenPane()
{
    if (g_surfaceColorLookup5Bit != 0) {
        for (int index = 0; index < 256; ++index) {
            if (g_surfaceColorLookup5Bit[index] != 0)
                free(g_surfaceColorLookup5Bit[index]);
        }
        free(g_surfaceColorLookup5Bit);
    }

    if (g_surfaceColorLookup6Bit != 0) {
        for (int index = 0; index < 256; ++index) {
            if (g_surfaceColorLookup6Bit[index] != 0)
                free(g_surfaceColorLookup6Bit[index]);
        }
        free(g_surfaceColorLookup6Bit);
    }

    if (g_pDirectX != 0) {
        if (m_renderSurface != 0) {
            m_renderSurface->Release();
            m_renderSurface = 0;
        }

        if (m_grafPort.m_surface != 0) {
            m_grafPort.m_surface->Release();
            m_grafPort.m_surface = 0;
        }

        if (m_primarySurface != 0) {
            m_primarySurface->Release();
            m_primarySurface = 0;
        }
    }

    if (g_pDirectX != 0) {
        LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;

        if (m_restoreDisplayModePending && ApplicationActiveGate == 0) {
            HRESULT result = directDraw->RestoreDisplayMode();
            if (FAILED(result))
                throw new DDError(result);

            m_restoreDisplayModePending = false;
        }

        if (m_restoreCooperativeLevelPending) {
            HRESULT result = directDraw->SetCooperativeLevel(
                g_pApplication->GetMainWindowHandle(),
                DDSCL_NORMAL);

            if (FAILED(result)) {
                wchar_t formattedError[0x50];
                DDError *errorText = new DDError(result);
                errorText->FormatErrorMessage(formattedError, 0x50);
                throw new DDError(result);
            }

            m_restoreCooperativeLevelPending = false;
        }
    }

    delete m_rootLayerList;
    m_rootLayerList = 0;

    delete m_fadeCompletionCallback;
    m_fadeCompletionCallback = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Behavioral rationale: loops are exactly 256 entries; root pointers are not post-free cleared; surface release order and nulling are exact; DirectDraw branches and failure side effects are exact; owned pointers are deleted and nulled. Singleton/base/vptr/EH/deleting-wrapper behavior is deliberately absent.

### R2 - UID0001G5 broad source cluster, exact blank aggregate block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: exact children and the class/file route emit source; this address aggregate spans multiple methods and padding and is explicitly false/non-emitting so it neither duplicates bodies nor creates an inactive-emitter marker.

### R3 - UID0000CB ScreenPane complete compile-visible class declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;
class Layer;
class List;
class LObject;
class NotificationBlock;
class Region;

struct FrameUpdateContext {
    unsigned int callbackFrame;
    unsigned int currentFrame;
    bool dispatching;
};

class ScreenPane : public Pane,
                   public FrameHandler,
                   public Singleton<ScreenPane> {
public:
    ScreenPane(short screenWidth, short screenHeight, short screenBitDepth);
    virtual ~ScreenPane();

    int SetLayerFrame(int slot, Layer *layer);
    int DetachLayerFrame(Layer *layer);

    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual unsigned char HandleBrowserNotification(const NotificationBlock *block);
    virtual bool OnFrameUpdate(const FrameUpdateContext *context);

    void MarkDirtyRegion(const RectBounds *bounds);
    void StartPresentation();
    void SetActiveCursor(signed char cursorIndex, int force);
    void ShowCursor();
    void HideCursor();
    short GetScreenWidth() const;
    short GetScreenHeight() const;
    void PrepareDirectDrawPresentation();
    void RestoreDirectDrawState();
    void EnablePresentationMode();
    void DisablePresentationMode();
    void LoadCursorResources();
    void LoadCursorResourceSlot(unsigned int cursorIndex,
                                const wchar_t *animatedCursorPath,
                                const wchar_t *staticCursorPath);
    int QueueFadeInCallback(LObject *callbackObject);
    int QueueFadeOutCallback(LObject *callbackObject);
    void SetFadeTransitionState(unsigned char state);
    bool IsFadeTransitionActive() const;
    void RestoreLostSurfaces();
    void TraversePresentationList(Region *dirtyRegion);

private:
    void RenderPresentation();

    LPDIRECTDRAWSURFACE m_primarySurfaceCreateResult;
    LPDIRECTDRAWSURFACE m_primarySurface;
    LPDIRECTDRAWSURFACE m_offscreenSurface;
    LPDIRECTDRAWSURFACE m_renderSurface;
    List *m_rootLayerList;
    bool m_restoreCooperativeLevelPending;
    bool m_restoreDisplayModePending;
    short m_screenWidth;
    short m_screenHeight;
    short m_screenBitDepth;
    bool m_hasPendingDirtyRegion;
    RectBounds m_pendingDirtyRegion;
    bool m_presentationModeEnabled;
    __declspec(align(4)) unsigned char m_presentationStateStorage[0x420];
    HCURSOR m_cursorHandles[12];
    short m_activeCursorIndex;
    unsigned char m_cursorStateStorage[0x16];
    short m_fadeCurrentValue;
    short m_fadePreviousValue;
    bool m_presentationDirty;
    short m_presentationJitterX;
    short m_presentationJitterY;
    int m_fadeTransitionState;
    FunctionObject0 *m_fadeCompletionCallback;
    int m_fadeStep;
    bool m_forceFullRedraw;
    bool m_browserNotificationPending;
    bool m_pointerInputActive;
};

extern ScreenPane *g_pScreenPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Source-shape boundary: R3 declares every field and method used by accepted ScreenPane source and closes the class before `[[CHILDREN]]`. It also retains both semantically unidentified spans as bounded first-draft C++03 storage. The `0x420` byte span uses target-MSVC `__declspec(align(4))` so it begins at the proven `+0x130` after the `+0x12c` byte and three bytes of natural aggregate alignment; an unaligned byte array incorrectly begins at `+0x12d` and is rejected by the callback verifier. The names describe only their nearest proven state domains; they do not assert original symbols or final aggregate types. This is the last-resort representation after the semantic routes above failed, and it must be replaced only by equally sized/aligned evidence-backed types.

Mandatory callback layout verification under the target 32-bit MSVC ABI:

| Item | Required offset / size |
| --- | --- |
| `Pane` direct base | `+0x000` |
| Pane-owned `EventHandler` / `TimerHandler` facets | `+0x0a0` / `+0x0a4` |
| `FrameHandler` direct base | `+0x0f8` |
| empty `Singleton<ScreenPane>` direct base / EBO overlap | `+0x0fc` |
| `m_primarySurfaceCreateResult` | `+0x0fc` |
| `m_primarySurface` / `m_offscreenSurface` / `m_renderSurface` | `+0x100` / `+0x104` / `+0x108` |
| `m_rootLayerList` | `+0x10c` |
| restore flags | `+0x110` / `+0x111` |
| width / height / bit depth | `+0x112` / `+0x114` / `+0x116` |
| dirty flag / rectangle / presentation-mode flag | `+0x118` / `+0x11c` / `+0x12c` |
| `m_presentationStateStorage` | `+0x130`, size `0x420` |
| `m_cursorHandles` / `m_activeCursorIndex` | `+0x550` / `+0x580` |
| `m_cursorStateStorage` | `+0x582`, size `0x16` |
| fade current / previous / dirty | `+0x598` / `+0x59a` / `+0x59c` |
| jitter X / Y | `+0x59e` / `+0x5a0` |
| transition / callback / step | `+0x5a4` / `+0x5a8` / `+0x5ac` |
| full-redraw / browser / pointer flags | `+0x5b0` / `+0x5b1` / `+0x5b2` |
| complete `ScreenPane` | `sizeof(ScreenPane)==0x5b4` |

Because `ScreenPane` is a multiple-inheritance, non-standard-layout C++03 class, callback verification should use the target compiler's class-layout output or a temporary build verifier rather than relying on portable `offsetof`. Any mismatch blocks implementation completion and requires type/member correction before validation.

### R4 - UID0000S7 semantic global definition

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScreenPane;
ScreenPane *g_pScreenPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID0001OX physical global slot, exact blank covered-storage block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: R4 is the sole source definition; physical address storage must not emit a duplicate or an inactive comment body.

### R6 - UID0003CI vtable data, exact blank compiler block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: class inheritance and virtual declarations regenerate COL/RTTI/vtables/adjustors. Raw arrays are forbidden.

### R7 - UID00029V lookup-root definitions

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char **g_surfaceColorLookup5Bit = 0;
unsigned char **g_surfaceColorLookup6Bit = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R8 - UID00039Y callback and transition helpers, inherited TimerHandler access

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kScreenPaneFadeInEvent = 0x4664496e;  // FdIn
const int kScreenPaneFadeOutEvent = 0x46644f74; // FdOt
}

int ScreenPane::QueueFadeInCallback(LObject *callbackObject)
{
    m_fadeTransitionState = 0;
    return TimerHandler::ScheduleTimer(kScreenPaneFadeInEvent, 0, callbackObject, 0);
}

int ScreenPane::QueueFadeOutCallback(LObject *callbackObject)
{
    m_fadeTransitionState = 0;
    return TimerHandler::ScheduleTimer(kScreenPaneFadeOutEvent, 0, callbackObject, 0);
}

void ScreenPane::SetFadeTransitionState(unsigned char state)
{
    m_fadeTransitionState = state;
}

bool ScreenPane::IsFadeTransitionActive() const
{
    return m_fadeTransitionState != 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R9 - UID00039Z lost-surface restoration, inherited GrafPort access

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kRestoreLostSurfaceMaxAttempts = 10000;

bool RestoreSurfaceWithRetry(IDirectDrawSurface *surface)
{
    if (surface == 0)
        return true;

    if (surface->IsLost() >= 0)
        return true;

    for (int attempt = 0; attempt < kRestoreLostSurfaceMaxAttempts; ++attempt) {
        if (surface->Restore() >= 0)
            return true;
    }

    return false;
}
}

void ScreenPane::RestoreLostSurfaces()
{
    if (m_grafPort.m_surface != 0 &&
        m_grafPort.m_surface->IsLost() == DDERR_SURFACELOST) {
        m_grafPort.m_surface->Restore();
    }

    if (!RestoreSurfaceWithRetry(m_primarySurface))
        return;

    RestoreSurfaceWithRetry(m_renderSurface);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R10 - UID0003A3 presentation traversal, normalized render-surface member

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::TraversePresentationList(Region *dirtyRegion)
{
    Region layerDirty;
    Region currentMotion;

    GetCurrentMotionRegion(&currentMotion);
    SubtractMotionFromDirtyRegion(&currentMotion);

    const int layerCount = m_rootLayerList->GetCount();
    const int lastLayer = layerCount - 1;

    for (int index = lastLayer; index >= 0; --index) {
        Layer *layer = static_cast<Layer *>(
            m_rootLayerList->GetElementAt(index));
        layer->ClearDirtyRegion();
        layer->CollectDirtyRegion(&layerDirty, &currentMotion);
        dirtyRegion->UnionWith(layerDirty);
    }

    void *savedSurface = m_grafPort.m_surface;
    m_grafPort.m_surface = m_renderSurface;

    Point origin;
    InitPointPair(&origin, 0, 0);

    for (int index = 0; index < layerCount; ++index) {
        Layer *layer = static_cast<Layer *>(
            m_rootLayerList->GetElementAt(index));

        if (index < lastLayer) {
            Layer *nextLayer = static_cast<Layer *>(
                m_rootLayerList->GetElementAt(index + 1));
            layer->CopyDirtyRegion(&layerDirty);
            nextLayer->UnionDirtyRegion(&layerDirty);
        }

        layer->PropagateDirtyRegion();
        if (layer->RenderRecursive(
                &m_grafPort, origin.x, origin.y, &layerDirty, NULL)) {
            m_presentationDirty = true;
        }
        layer->EndRender();
    }

    m_grafPort.m_surface = savedSurface;

    if (m_hasPendingDirtyRegion) {
        m_presentationDirty = true;
        dirtyRegion->UnionWithRect(&m_pendingDirtyRegion);
        m_hasPendingDirtyRegion = false;
        InitRectBounds(&m_pendingDirtyRegion, 0, 0, 0, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- C++03 conventions: integer zero rather than `nullptr`, declarations before use, ordinary `for` loop, Win32/DirectDraw project types, and no C++11 syntax.
- Exact no-code proof applies only to R0/R2/R5/R6; all evidence and rationale remains in prose rather than inactive formal comment text. R3 is the complete class declaration, and R8-R10 preserve existing bodies with only source-shape normalization.

## Final Recommendation

- C01-C20 and R0-R10 are applied after supervisor Gate 1 acceptance; R3 includes the implementation-time alignment correction required by the accepted target-ABI hard gate.
- UID0004W7 was registered before any parent/support validation; all former placeholders now use the validator-issued UID.
- Reclassify UID00023U and UID0003CI as false/non-emitting compiler artifacts with blank formal blocks.
- Add exact ordinary destructor child and complete source body; do not add wrapper/singleton/base/compiler artifacts to it.
- Preserve parent/internal/external padding and correct relative nesting.
- Close `g_pScreenPane` one-definition routing through semantic UID0000S7 and physical non-emitting UID0001OX.
- Correct UID00029V zero initialization and external linkage; preserve Surface ownership and all 12/11 xref families.
- Install complete R3 at UID0000CB, including both bounded storage members, close the class before `[[CHILDREN]]`, and make UID0001G5 false/non-emitting. This removes both structural markers without duplicating source bodies or collapsing the `0x5b4` object.
- Apply R8-R10 and the UID0002VO primary-offset correction so every accepted ScreenPane source body uses the class declaration's inherited/member vocabulary. No class/source blocker is deferred.
- Before accepting callback completion, verify `sizeof(ScreenPane)==0x5b4`, every direct/secondary base offset, and every known member offset in the R3 verification table under the target 32-bit MSVC ABI. A generated file with zero Empty Emitter Markers still fails if any physical offset differs.
- B003's role does not authorize IDA mutation, manual coverage edits, generated edits, or report execution/move/archive lifecycle actions; the validator-owned footer, including commands `000000016527` and `000000016537`, records supervisor/validator lifecycle history independently of B003's actions.

## Recommended Target Doc Changes

- Target: `by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md`.
- Metadata: `86/92 -> 92/94`; retain owner UID0000CB; `TRUE -> FALSE`; clear emitter; retain blank position, blank R0, Nested0, exact range/title.
- Item Summary: exact 107-byte compiler island; constructor-unwind Singleton cleanup; three adjustments; scalar wrapper; internal/external padding; ordinary destructor/source coverage delegated to real UID0004W7.
- Replace stale source-authored helper wording with explicit historical correction.
- Preserve all function starts/sizes, 33 decoded instruction history, block counts, vtable refs, calls, bytes, padding, and rejected handwritten representations.

## Recommended Support Doc Changes

- `by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md` (UID0004W7): create at `92/94`, owner/emitter UID0000CB, true, blank position, Nested+4, exact R1 and full evidence.
- `by-memory/0x00556910-0x00557132.ScreenPane.md` UID0001G5: `88/90 -> 91/93`; retain owner UID0000CB, set false, clear emitter, retain blank position/R2/Nested0; add exact child, full method index, range/hash, resource flow, singleton compiler-source split, padding, history, and exact aggregate no-code cause.
- `by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md` UID0002VO: change Nested4 -> 0, correct adjusted receiver `+0x511` to primary ScreenPane `+0x5b1`, and add address-sorted sibling explanation; preserve 88/90, owner/emitter, formal body/behavior, range, and unrelated content.
- `by-class/ScreenPane.md` UID0000CB: `90/93 -> 92/93`; retain owner/emitter UID0000NB, true, blank position; install complete R3 and add exact hierarchy/RTTI/PMD/EBO/size/layout table, ordinary destructor declaration/behavior, callbacks, target/compiler split, global/lookup support, semantic-hypothesis elimination, provisional `0x420` presentation-state and `0x16` cursor-state storage, exact downstream offsets, and the mandatory callback layout-verification table.
- `by-file/ScreenPane.md` UID0000NB: `90/92 -> 93/94`; preserve path/route and all current methods; add complete class-before-children source route, exact `0x5b4` class occupancy, new destructor child, target/vtable/aggregate/compiler exclusions, semantic global definition, lookup-root extern dependency, normalized support formals, and generated-order/zero-marker plus target-ABI layout expectations.
- `by-global/g_pScreenPane.md` UID0000S7: `86/92 -> 92/94`; retain owner/emitter UID0000NB and true; install R4, sole-definition and Singleton lifecycle evidence.
- `by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md` UID0001OX: `86/92 -> 92/94`; retain owner UID0000S7; set false, clear emitter/position, blank R5, Nested0; preserve exact storage/xrefs/successor/aliases/history.
- `by-memory/0x006230e8-0x0062317c.ScreenPaneVtableData.md` UID0003CI: `87/91 -> 92/94`; owner UID0000CB, false, blank emitter/position/R6, retain Nested8; preserve tables/RTTI/slots/stores/boundaries.
- `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md` UID00029V: `88/91 -> 92/94`; retain owner/emitter UID0000OC, true, position10, Nested0; install R7; preserve 12/11 xrefs, initializer/consumer families, boundaries, historical `ff` observation as superseded.
- `by-file/Surface.md` UID0000OC: score/path unchanged `88/85`; add zero/external linkage, ScreenPane destructor consumer, and reject static/-1 while preserving complete current render union.
- `by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md` UID00039Y: scores/owner/emitter/range/Nested unchanged; install exact R8, replace false embedded `m_timerHandler` with inherited `TimerHandler::ScheduleTimer`, and preserve all four methods, event IDs, padding, callers, raw-helper liveness, and history.
- `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md` UID00039Z: scores/owner/emitter/range/Nested unchanged; install exact R9, replace duplicate derived `m_grafPortSurface` with inherited `m_grafPort.m_surface`, and preserve retry/body/caller/DirectDraw/padding/history detail.
- `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` UID0003A3: scores/owner/emitter/range/Nested unchanged; install exact R10, replace historical `m_presentationSurface` with normalized `m_renderSurface`, and preserve all traversal/order/Layer/padding/caller/history detail.
- Verify-only unless exact callback contradiction: UID0001G6, all existing ScreenPane method children, DirectX/Application/DDError support, Pane/FrameHandler/Singleton templates, OperatorDeleteWrapper, ignored padding, successor ScreenDimmer family, and all unrelated active content.

## Score And Metadata Recommendation

| Destination | Historical / pre-callback baseline | Implemented current-state tuple | Rationale / cap |
| --- | --- | --- | --- |
| UID00023U | 86/92, owner/emitter 0000CB, true, Nested0 | 92/94, owner 0000CB, false, blank emitter/position/formal, Nested0 | Complete compiler/source disposition; no original compiler-source line mapping. |
| UID0004W7 | Absent before callback; no exact destructor child existed. | 92/94, owner/emitter 0000CB, true, blank position, Nested+4 | Exact body and source shape; private names inferred. |
| UID0001G5 | 88/90, owner/emitter 0000CB, true | 91/93, owner 0000CB, false, blank emitter/position/R2, Nested0 | Complete aggregate/index disposition; exact children/class route emit without an aggregate marker. |
| UID0002VO | 88/90, Nested4, adjusted-view `+0x511` not normalized to the primary object. | 88/90 with route/formal unchanged, Nested0; primary byte +0x5b1 | Relative-delta and adjusted-receiver correction only. |
| UID0000CB | 90/93 | 92/93, owner/emitter 0000NB, true, blank position, complete physically coherent R3 | Compile-visible declaration closes all accepted members/methods and preserves exact `0x5b4` occupancy; inferred spellings and unrecovered semantic storage types cap confidence. |
| UID0000NB | 90/92 | 93/94, file route unchanged | Complete class/source/compiler inventory and zero-marker route for this family. |
| UID0000S7 | 86/92 | 92/94, owner/emitter 0000NB, true, R4 | Sole source definition and complete lifecycle. |
| UID0001OX | 86/92 | 92/94, owner 0000S7, false, blank emitter/formal | Complete physical/semantic split. |
| UID0003CI | 87/91 | 92/94, owner 0000CB, false, blank emitter/formal, Nested8 | Exact RTTI/vtables and no-code cause. |
| UID00029V | 88/91 | 92/94, owner/emitter 0000OC, true, position10, R7 | Zero/linkage contradiction resolved; exact names still inferred. |
| UID0000OC | 88/85 with stale lookup-root wording | 88/85, file route unchanged, corrected zero/external-linkage support | Bounded support correction does not settle broader Surface source boundaries. |
| UID00039Y | 88/90 with stale embedded-timer spelling | 88/90, owner/emitter 0000CB, true, R8 | Exact inherited TimerHandler access; behavior unchanged. |
| UID00039Z | 88/91 with stale duplicate-surface spelling | 88/91, owner/emitter 0000CB, true, R9 | Exact inherited GrafPort access; behavior unchanged. |
| UID0003A3 | 90/92 with stale presentation-surface spelling | 90/92, owner/emitter 0000NB, true, R10 | Exact render-surface member normalization; behavior unchanged. |

- Score-improvement work removed every ordinary-document target blocker: helper role, source body, wrapper disposition, hierarchy, exact object occupancy, global one-definition, lookup initializer/linkage, and nesting. All 14 exact C20 manual rows are already present once at the current anchors and match the preserved report text; their B003 checklist state is terminal and no manual application remains pending. Any future supervisor independent readback/validation or no-loss drift repair after later root movement is external lifecycle work, not an unchecked B003 stage.
- Scores remain below 95 where original private names, exact original header placement, or semantic identity of the two bounded storage members is not recoverable. Those caps no longer leave incomplete C++, an active blank emitter, or a layout that shifts later fields.

## Open Questions With Attempted Resolution

- Was `0x00559b20` a source helper? Resolved no: sole constructor EH xref and `+0xfc` receiver prove Singleton unwind lowering.
- Should target emit a destructor wrapper? Resolved no: hidden flags, return-this, adjustment thunks, vtable route, and delete call are canonical compiler ABI lowering.
- Should the ordinary destructor clear `g_pScreenPane` explicitly? Resolved no: clear position proves inlined Singleton base destruction.
- What is the class inheritance? Resolved: `Pane`, `FrameHandler`, `Singleton<ScreenPane>` direct order; Pane owns EventHandler/TimerHandler facets.
- What is exact object size? Resolved `0x5b4` by wrapper bit-4 size path and layout.
- Are lookup roots `-1` sentinels? Resolved no for source initialization: live bytes zero and destructor has no sentinel branch.
- Can lookup roots remain static in Surface.cpp? Resolved no under current source split; direct destructor references require external linkage or an observed helper call, and no helper call exists.
- Can a complete compile-visible ScreenPane class formal be supplied now? Resolved yes: R3 declares every source-observed field/method, retains both unidentified spans as bounded C++03 byte storage, and closes before children. Silent omission is forbidden because it shifts `m_cursorHandles`, all fade/callback/tail state, and contradicts `sizeof(ScreenPane)==0x5b4`.
- Can either storage member receive a stronger semantic type now? Resolved no after bounded palette, region/rectangle, cursor-manager, cursor-descriptor/path, hidden-base, and resource-aggregate checks. Fixed byte storage is accepted only as the behavior-neutral first-draft fallback. Future evidence must refine the type without changing `+0x130/0x420`, `+0x582/0x16`, or any later offset.
- Is the browser byte primary `+0x511`? Resolved no: EventHandler-adjusted receiver `+0xa0` plus displacement `+0x511` proves primary `+0x5b1`.
- Are TimerHandler and GrafPort duplicate derived members? Resolved no: RTTI, adjusted facets, and accepted methods require inherited `TimerHandler::ScheduleTimer` and `m_grafPort.m_surface`.
- Exact private spellings remain inferred. Their roles and types are sufficient for source-ready C++03; this is the stated confidence cap, not an unresolved implementation blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical initial-repair manual snapshots retained only as prior evidence, not as current root state:
  - `by-memory/-coverage-report.md`: SHA256 `94434F13116AE98DAFA5389C85EB21E03217184CB821AE09226129290CBC1AB1`, 1,958,001 bytes / 4,530 lines.
  - `by-class/-coverage-report.md`: SHA256 `2F346B5D08E3D4EFAC3785449B1FF1F0A0DE15123DF2002AA0CDF8E7302D2BE2`, 253,106 bytes / 623 lines.
  - `by-file/-coverage-report.md`: SHA256 `2BF7C218FCF6760E10CC73E9992618491D04A680AF4962E54CFDF33BD2CF85C2`, 150,805 bytes / 317 lines.
  - `by-global/-coverage-report.md`: SHA256 `F79F04B44824C59A4CDC8EEA145C6CDBD2564571754C1FFE61B2471F07E5FEBF`, 97,902 bytes / 217 lines.
- Historical callback-final snapshots, also superseded as current root state, were by-memory `345BD53DE5A40F61B334E48E4A88E413700703F11DDB0180EFFE628DEF3F0396`, by-class `8347783520081E1F9889CEE56AC2E18292F61784E62C8501995090403BFA843D`, by-file `33B6AB28DBA057D8958B1781F205BAC1085C0CCBEE0DFEDC09F0CF2F474B1C2E`, and by-global `F79F04B44824C59A4CDC8EEA145C6CDBD2564571754C1FFE61B2471F07E5FEBF`.
- Historical post-B001 read-only snapshots, superseded as current root state, were by-memory `4A3CC82259A7E7C13695CC23853F82A52491F3DC96D359CE687DDD596D65F02B`, by-class `CEC80113AB7400EEC1CA69F08748D0918FAA394486F1304736D7F51739F51629`, and by-file `2833CB3256DF9AAE0C49397CC096569ECFF91A302B7DCA3579D4BC6EDDE8576A`.
- Historical post-B001/B002/B005 read-only snapshots, superseded as current root state, were by-memory `5DCC8DDA8B60AEBE3A8F665F2A845BC216F5C5FC3983473981E1208957961E69` at 1,968,429 bytes / 4,546 lines, by-class `7B42EED85BE48C2A196E5DD599AD5EE0A5B3C53E5EA9F5A56AACB75B9B33FBFE` at 254,925 bytes / 624 lines, by-file `40713D5C4652FA336A7D243A19CB66FC7A1E9EF0B143D048F7EB99899741C069` at 152,391 bytes / 317 lines, and by-global `F79F04B44824C59A4CDC8EEA145C6CDBD2564571754C1FFE61B2471F07E5FEBF` at 97,902 bytes / 217 lines.
- Historical prior-repair read-only snapshots, superseded by later unrelated root drift, were by-memory `9B6349476C5A16512F7DACA26F84830FD51DF3C36C6BF7F59AA24EBCFCE58E12` at 1,972,129 bytes / 4,550 lines, by-class `CF4D4F7C166A66E300ECABAA8A3F0F8E99F301112A72D372806E90713A8E3A5C` at 255,817 bytes / 624 lines, by-file `21122F425C67038A1006B3F61F55D70658002B0C63CB53B046E4F54E9E4FEFE7` at 153,323 bytes / 317 lines, and by-global `E0D917B49A4FF18AA3B9E83DACFF83DE34C062744B4D5533696D2782D4C6F592` at 97,945 bytes / 217 lines.
- Historical previous exact C20 verification roots, superseded by B004 supervisor coverage work, were by-memory `EEB04A9CEBB5678F4C9AB0039D4CE1E1586C3DCE0F67333A12B14B6AEDE471A7` at 1,973,045 bytes / 4,550 lines, by-class `12FAE415EEF36A9B66BE028C9617D8F997CF08DA46CEB134B0D318B2F3768388` at 256,221 bytes / 624 lines, by-file `CE1C169E10BC184E570C9B5EB37CA43251A50C02BF23818FCA2BE0686A4A8599` at 153,531 bytes / 317 lines, and by-global `E0D917B49A4FF18AA3B9E83DACFF83DE34C062744B4D5533696D2782D4C6F592` at 97,945 bytes / 217 lines.
- Historical B004 supervisor-coverage roots, superseded by the current manual epoch, were by-memory `AACB752C3DB0E27C102E5472533E5589DF3AB17E68173FA179B48AFC030935D1` at 1,974,625 bytes / 4,551 lines, by-class `B87E73A626B3015381C7FF34DF60CDAE4212235785D62BB88A1BC5F0F627DAA6` at 256,443 bytes / 624 lines, by-file `0C080920BF582A99914663321F58DA10828F9C211786A6A2E3043C1F19BE43FE` at 154,349 bytes / 317 lines, and by-global `0A8555A911EDD1424458970C3BD5CB9A0095944C444F05F21AD2FB803809A915` at 98,721 bytes / 217 lines.
- Current read-only manual roots used for this exact 14-row C20 verification, reread from the exact E-drive project immediately before this report repair:
  - `by-memory/-coverage-report.md`: SHA256 `A7D812B60CB35399C541461DC0E214A8380B61D7793E2BB499B9247449A1A70B`, 1,982,596 bytes / 4,564 lines, mtime `2026-07-22T21:57:06.8103048-04:00`.
  - `by-class/-coverage-report.md`: SHA256 `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E`, 257,808 bytes / 624 lines, mtime `2026-07-22T21:57:06.8103048-04:00`.
  - `by-file/-coverage-report.md`: SHA256 `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90`, 154,448 bytes / 317 lines, mtime `2026-07-22T21:57:06.8206790-04:00`.
  - `by-global/-coverage-report.md`: SHA256 `D25BDD5BB2F097258C9B76628317CDC773F8E4F1014B808BAB421E1CC0040226`, 99,098 bytes / 217 lines, mtime `2026-07-22T21:57:06.8206790-04:00`.
- Current row readback confirms that later unrelated coverage additions did not alter any C20 row body. The full C20 rows below remain present exactly once and byte-for-byte equal to the required text: by-memory UID0001G5/UID0004W7/UID0002VO at lines 3049-3051, UID00039Y/UID00039Z/UID0003A3 at lines 3064-3066, UID00023U at line 3072, UID0003CI at line 4159, UID0001OX at line 4351, and UID00029V at line 4451; by-class UID0000CB at line 466; by-file UID0000NB/UID0000OC at lines 237/274; and by-global UID0000S7 at line 139. C20 is terminal `already-present`; no manual claim is blocked and no current application is required.
- Final settled tracker checkpoint is command `000000016626`, refreshed `2026-07-22T22:16:12-04:00`, source `deferred-generated-refresh`, SHA256 `331381565D56CC8ED83F7FD7234C22A81CF8FF1E8109543A12FA4E5C2A724C23`, 1,634,570 bytes / 6,507 lines. Its summary is 5,585 tracked / 2,035 covered / 3,550 not covered / 36.4%; exact UID00023U row line 5426 records `92/94`, combined `93.0`, reconstructable `false`, zero direct/additional/B-report coverage, and path `by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md`. Earlier tracker identities and line anchors are historical.

### by-memory parent/children replacement

Current lines 3049-3051 already equal the required C20 block, between the unchanged UID0000VN padding rows at lines 3048 and 3052. Supervisor action: verify and preserve these three rows; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
    - [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md) 0x00556910-0x00557132 | non-emitting class method index | ScreenPane : not_reconstructable : 91% : very-strong : Root ScreenPane method index preserving exact constructor/destructor/layer-helper/historical HandleMessage and OnFrameTick inventories, their source-facing OnTimer and OnFrameUpdate identities, all internal padding, g_pScreenPane lifecycle refs, ScreenPane vtable refs, browser handler child split, and class/file routing; adds exact ordinary-destructor child UID0004W7 with complete cache/surface/DirectDraw/list/callback cleanup source, correct Singleton compiler-lowering distinction, and address-sorted child nesting. Exact method children and complete ScreenPane class/file routes carry source, so this aggregate is owner UID0000CB, false/non-emitting, blank emitter/formal and creates no duplicate or Empty Emitter Marker.
        - [UID:0004W7][0x00556a60-0x00556cd4.ScreenPaneDestructor](by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md) 0x00556a60-0x00556cd4 | ordinary destructor | ScreenPaneDestructor : reconstructable : 92% : very-strong : Exact 628-byte ScreenPane ordinary destructor with two 256-entry Surface lookup-root cleanup loops, three ordered DirectDraw-surface releases, exact display-mode/cooperative-level restoration and DDError failure side effects, root-layer-list and LObject callback deletion/nulling, implicit Singleton/FrameHandler/Pane teardown, and source-ready C++03 body excluding vptrs, explicit bases, singleton clear, deleting flags, operator delete, EH, and cookies.
        - [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) 0x00556f70-0x00557070 | method | ScreenPaneBrowserNotificationHandler : reconstructable : 88% : very-strong : ScreenPane vtable-referenced Bros/browser notification handler with exact bounds, class parent attachment backed by the ScreenPane source-root chain, payload state handling, adjusted EventHandler-view displacement +0x511 proven as primary ScreenPane bool m_browserNotificationPending at +0x5b1, legacy browser singleton close path, optional alert-pane allocation with payload text/OK/back-pane data, normalized UID links, source-ready HandleBrowserNotification body, preserved high-byte fallback, and address-sorted second-child Nested 0 after UID0004W7.
```

### by-memory normalized ScreenPane support insertion/replacement

Current lines 3064-3066 already equal the required UID00039Y/UID00039Z/UID0003A3 C20 block, after UID0001G9 at line 3063 and before the unchanged padding row at line 3067. Supervisor action: verify and preserve the block; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
        - [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) 0x005590e0-0x0055916b | method cluster | ScreenPaneCallbackAndFlagHelpers : reconstructable : 88% : very-strong : Exact four-method ScreenPane callback/transition cluster preserving FdIn/FdOt event ids, callers, transition state +0x5a4, raw setter/predicate liveness cap, all internal/external padding, class/file route, and exact R8; TimerHandler is the inherited Pane facet at primary +0xa4 and source calls use TimerHandler::ScheduleTimer rather than a false embedded m_timerHandler member.
        - [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) 0x00559170-0x005591fc | method | ScreenPane::RestoreLostSurfaces : reconstructable : 88% : very-strong : Exact WM_SETFOCUS/g_pScreenPane caller route, DDERR_SURFACELOST and IsLost/Restore slots, inherited GrafPort surface plus primary/render retry behavior, early return, 0x005591fc-0x00559200 padding, class/file ownership, and exact R9; inherited m_grafPort.m_surface replaces the superseded duplicate-derived m_grafPortSurface spelling.
        - [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) 0x00559410-0x005595ca | method | ScreenPane::TraversePresentationList : reconstructable : 90% : very-strong : Exact Layer-pointer reverse dirty/forward render traversal with one direct Layer::EndRender call per rendered list entry, inherited GrafPort surface save/restore, normalized m_renderSurface at ScreenPane +0x108, pending dirty-region consumption, all caller/routes/range evidence, and exact R10; stale ScreenLayerEntry/MapPane/m_presentationSurface wording is superseded without changing behavior.
```

### by-memory target replacement

Current UID00023U line 3072 already equals the required C20 row, between unchanged padding rows at lines 3071 and 3073. Supervisor action: verify and preserve it; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
    - [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) 0x00559b20-0x00559b8b | compiler destructor-support island | ScreenPaneDestructorThunkIsland : not_reconstructable : 92% : very-strong : Exact 107-byte ScreenPane compiler island preserving five modeled functions, 33 decoded-instruction history, per-function blocks, constructor-unwind Singleton<ScreenPane> +0xfc clear at 0x00559b20, three +0xa0/+0xa4/+0xf8 adjustor thunks, scalar deleting wrapper calls to ordinary destructor/OperatorDeleteWrapper/size guard, primary and adjusted vtable refs, internal 0x00559b4c-0x00559b50 padding, and both external padding boundaries; semantic owner UID0000CB, false/non-emitting blank formal, with ordinary source destruction covered only by UID0004W7.
```

### by-memory vtable insertion

Current UID0003CI line 4159 already equals the required C20 row, after UID0002OQ at line 4158 under UID00026B at line 4157 and before the next top-level UID00026C row at line 4160. Supervisor action: verify and preserve it; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
        - [UID:0003CI][0x006230e8-0x0062317c.ScreenPaneVtableData](by-memory/0x006230e8-0x0062317c.ScreenPaneVtableData.md) 0x006230e8-0x0062317c | compiler RTTI/vtable data | ScreenPaneVtableData : not_reconstructable : 92% : very-strong : Exact ScreenPane COL and primary/+0xa0/+0xa4/+0xf8 adjusted vtable views, complete ScreenPane/Pane/GrafPort/LObject/EventHandler/TimerHandler/FrameHandler/Singleton RTTI PMDs, constructor/destructor stores, deleting-wrapper targets, browser slot, successor boundary, and class/source cause; semantic owner UID0000CB, false/non-emitting blank formal, no raw arrays or independent source marker.
```

### by-memory physical singleton replacement

Current UID0001OX line 4351 already equals the required C20 row, between UID00028Q at line 4350 and UID00028R at line 4352. Supervisor action: verify and preserve it; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
    - [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) 0x0067a7cc-0x0067a7d0 | global backing storage | g_pScreenPane : not_reconstructable : 92% : very-strong : Exact zero-initialized four-byte ScreenPane singleton slot with 145 xrefs, constructor publication/fallback clear, ordinary-destructor and constructor-unwind Singleton clears, browser-runtime/cursor-manager alias evidence, UI setup/teardown and focus consumers, and separate 0x0067a7d0 successor; semantic definition emits exactly once from UID0000S7, so this physical page is owner UID0000S7, false/non-emitting, blank emitter/formal without duplicate storage.
```

### by-memory lookup-root replacement

Current UID00029V line 4451 already equals the required C20 row, between UID00029U at line 4450 and UID0001PI at line 4452. Supervisor action: verify and preserve it with all current Surface facts; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
    - [UID:00029V][0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers](by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md) 0x0069b3d8-0x0069b3e0 | render lookup-table pointers | SurfaceAlphaLookupTablePointers : reconstructable : 92% : very-strong : Retains Surface ownership, exact two pointer slots, 12/11 xrefs, initializer stores/reuse sites, compatibility/RGB565/helper consumers, and 0x0069b3e0 callback-table boundary; live zero bytes plus ScreenPane destructor null-only cleanup supersede historical ff/-1 initialization, and externally linked zero-initialized definitions replace impossible file-static linkage so ScreenPane.cpp can directly free both 256-entry table families without an invented helper.
```

### by-class replacement

Current UID0000CB line 466 already equals the required C20 row, between UID0000CA at line 465 and UID0000CC at line 467. Supervisor action: verify and preserve every fact in the row; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md) : reconstructable : 92% : very strong : Root Pane/FrameHandler/Singleton<ScreenPane> controller retaining canonical singleton lifecycle, exact cursor table and dimensions, pending dirty-region state, seven source-ready UID0001G7 method children in deterministic order, DirectDraw/presentation/callback/helper inventory, and all existing caller/history evidence; supersedes the formerly blank broad class formal with exact RTTI/PMDs, old-MSVC Singleton EBO at +0xfc, binary size 0x5b4, ordinary destructor child UID0004W7, compiler-only UID00023U/UID0003CI and non-emitting UID0001G5 exclusions, source-facing OnTimer/OnFrameUpdate/HandleBrowserNotification declarations, complete compile-visible R3 closed before children, and exact member table through +0x5b3. Exhaustive constructor/destructor/family/145-xref checks reject unsupported palette, region, cursor-manager/descriptor/path, hidden-base, and resource-aggregate identities for +0x130..+0x54f and +0x582..+0x597; R3 retains those mandatory spans as provisional C++03 `unsigned char[0x420]` presentation-state and `unsigned char[0x16]` cursor-state storage, preserving every later offset and sizeof(ScreenPane)==0x5b4 pending stronger semantic evidence, while handwritten compiler vtable/wrapper output remains excluded.
```

### by-file ScreenPane replacement

Current UID0000NB line 237 already equals the required C20 row, between UID00036Q at line 236 and UID0000NC at line 238. Supervisor action: verify and preserve it; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/core ScreenPane source root retaining canonical singleton, layer/presentation/cursor state, seven exact UID0001G7 methods in positions 110-170, ABI-synchronized callers, all current callback/DirectDraw/lost-surface/traversal/source-boundary history, and no duplicate CursorManager source; adds complete physically coherent ScreenPane R3 before child definitions, sole g_pScreenPane definition, exact ordinary destructor child with lookup/surface/DirectDraw/list/callback cleanup, inherited TimerHandler/GrafPort and normalized render-surface formals R8-R10, primary browser byte +0x5b1, and complete compiler-source split for UID0001G5/UID00023U/UID0003CI/UID0001OX. Generated output must preserve sizeof(ScreenPane)==0x5b4 and every documented base/member offset, contain no ScreenPane-family Empty Emitter Marker, and contain no handwritten vtable/RTTI/adjustor/deleting-wrapper/EH/cookie output.
```

### by-file Surface replacement

Current UID0000OC line 274 already equals the required C20 row, between UID0000OB at line 273 and UID0000OD at line 275. Supervisor action: verify and preserve all facts in the row; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 88% : strong : `NexusTK/render/Surface.cpp` shared surface/render source route retaining typed slot-0 g_pfnDrawPixel storage, source-ready compat/RGB555 and RGB565 pixel callbacks, exact callback initializer selection, current format/lookup globals, existing callback-family implementations, DirectDraw presentation helpers, and broader source-unit boundary caveats; UID00029V now uses externally linked zero-initialized 5-bit/6-bit lookup roots because live bytes and null-only cleanup reject historical -1 and the exact ScreenPane destructor directly frees both 256-entry families across the current ScreenPane/Surface translation-unit split.
```

### by-global replacement

Current UID0000S7 line 139 already equals the required C20 row, between UID0000S5 at line 138 and UID0000S8 at line 140. Supervisor action: verify and preserve it; no current edit is required. Rebase only if a later root advance introduces drift:

```markdown
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) : reconstructable : 92% : very-strong : Sole external `ScreenPane *g_pScreenPane = 0` source definition in ScreenPane.cpp, backed by physical UID0001OX; preserves 145 xrefs, constructor publication/fallback, ordinary and constructor-unwind Singleton lifecycle clears, separate successor boundary, browser/cursor/status-text aliases, startup graph/shutdown layer consumers, and focus restoration; physical storage, UID00023U unwind helper, and UID0003CI vtables are non-emitting compiler/binary evidence with no duplicate definition.
```

- Reason B003 must not edit these rows: every `-coverage-report.md` is manual supervisor-owned state. The current roots already contain the exact C20 text, so B003's manual claim state is terminal `already-present`. Any future supervisor readback/manual-file validation or no-loss drift repair after later root movement is external lifecycle work, not an open report task. Validator-generated output does not authorize B003 manual edits.

## Follow-Up Actions

- Historical process sequence at the command-`000000016537` repair checkpoint required a fresh exact-artifact Gate 1 audit before independent Gate 2 verification against the implemented manifests, validator table, generated-output proof, ABI proof, and checked claim ledger. That sequence is retained as historical process evidence rather than a current pending-status assertion. B003 does not execute or move reports; current lifecycle/path truth always comes from the latest validator-owned footer event.
- UID0004W7 was registered first, every former placeholder was replaced, and each ordinary destination was processed under one lease at a time with immediate release after its scoped validator.
- Historical callback-generation command `000000016487` completed and produced the corrected implementation-time output. Unrelated foreground commands `000000016565` (`2026-07-22T19:48:00-04:00`) and `000000016569` (`2026-07-22T20:20:37-04:00`) are historical intermediate checkpoints that retained the same accepted shape. Current repository-wide foreground command `000000016594`, refreshed `2026-07-22T20:38:53-04:00`, independently retains that shape again: generated `ScreenPane.cpp` has complete R3 before all qualified definitions, one R1 destructor, one R4 definition, R8-R10 exactly once, no stale member spellings or target addresses, and zero Empty Emitter Markers; generated `Surface.cpp` has UID00029V/R7 once with two external zero definitions and no UID00029V marker or stale static/`-1` roots, while exactly 18 unrelated Surface markers remain outside this callback.
- All 14 C20 manual rows are already present exactly once at the current anchors and match the preserved handoff text after later unrelated root drift. B003 reread but did not edit them; their claim/checklist state is terminal `already-present`, while any future validation, drift-only repair, execution, count, path, move, or archive action stays supervisor/validator-owned and outside this report's open work.
- No additional research is required for this target. The only implementation-time defect was the unaligned byte surrogate; target x86 MSVC proof found it and the accepted R3 now uses explicit 4-byte alignment, closing every physical-layout item.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: `93/100`.
- Exact range/function/xref/compiler-source confidence: `99/100`.
- Remaining uncertainty: original private field spellings, exact declaration header for externally linked lookup roots, and semantic identity of the two bounded storage members. R3 preserves their exact physical occupancy without asserting unsupported types; this uncertainty caps source-shape confidence but no longer compromises executable layout, target false/non-emitting status, or R1 behavior.

## Validator Results

- MCP evidence remains session `9b0396a3`; required bounded calls succeeded. The excluded over-broad timeout remains historical and did not represent an outage.
- Historical pre-callback generated checkpoint remains command `000000016426`, `2026-07-22T16:16:56-04:00`, ScreenPane.cpp SHA256 `6B5D283C0D550BDA7C8824D2D11965D8657379B006DD0F1C63CFF1E693F2CAC9`, 11,076 bytes / 336 lines, with six route-caused markers and no ordinary destructor.

- Authoritative invocation provenance was recovered from matched tool-call/tool-output records in `C:\Users\admin\.codex\sessions\2026\07\22\rollout-2026-07-22T16-34-21-019f8b89-572f-7013-a97c-ea4a6c0c21cd.jsonl`. The literal `command` and `workdir` values below are copied from those call records; command-specific `ok` values are copied only from each matching output record. Validator output also reported the canonical mirror root `C:\FastStorage\NTK_Sources\source-3\project-documentation`, but that output-root value does not replace the actual E-drive invocation working directory.

| Command | Timestamp | Scope | Literal exact command line | Invocation working directory | Authoritative rollout call/output records | Exit / command-specific result | Generated state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `000000016465` | `2026-07-22T17:23:44-04:00` | parent-held new-file registration for `ScreenPaneDestructor.md` | `python .\tools\validator.py --mode file --file 'by-memory\0x00556a60-0x00556cd4.ScreenPaneDestructor.md' --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `146983`; output `146984` | `0`; issued UID0004W7; this command's validator output did not emit an `ok` field | deferred |
| `000000016468` | `2026-07-22T17:26:06-04:00` | UID0004W7 exact destructor child | `python .\tools\validator.py --mode file --file 'by-memory\0x00556a60-0x00556cd4.ScreenPaneDestructor.md' --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147015`; output `147016` | `0`; `ok:1` | deferred |
| `000000016470` | `2026-07-22T17:27:49-04:00` | UID00023U target | `python .\tools\validator.py --mode file --file 'by-memory\0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md' --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147046`; output `147047` | `0`; `ok:1` | deferred |
| `000000016471` | `2026-07-22T17:29:30-04:00` | UID0001G5 aggregate | `python .\tools\validator.py --mode file --file 'by-memory\0x00556910-0x00557132.ScreenPane.md' --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147065`; output `147066` | `0`; `ok:1` | deferred |
| `000000016472` | `2026-07-22T17:30:50-04:00` | UID0002VO browser child | `python .\tools\validator.py --mode file --file 'by-memory\0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md' --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147085`; output `147086` | `0`; `ok:1` | deferred |
| `000000016473` | `2026-07-22T17:33:06-04:00` | UID0000CB initial complete R3 | `python .\tools\validator.py --mode file --file 'by-class\ScreenPane.md' --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147125`; output `147126` | `0`; `ok:1` | deferred |
| `000000016475` | `2026-07-22T17:37:14-04:00` | UID0000NB file route | `python .\tools\validator.py --mode file --file .\by-file\ScreenPane.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147200`; output `147201` | `0`; `ok:1` | deferred |
| `000000016476` | `2026-07-22T17:37:52-04:00` | UID0000S7 semantic global | `python .\tools\validator.py --mode file --file .\by-global\g_pScreenPane.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147218`; output `147219` | `0`; `ok:1`; projected stats updated | deferred |
| `000000016477` | `2026-07-22T17:38:37-04:00` | UID0001OX physical slot | `python .\tools\validator.py --mode file --file .\by-memory\0x0067a7cc-0x0067a7d0.g_pScreenPane.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147237`; output `147238` | `0`; `ok:1` | deferred |
| `000000016478` | `2026-07-22T17:39:36-04:00` | UID0003CI vtable data | `python .\tools\validator.py --mode file --file .\by-memory\0x006230e8-0x0062317c.ScreenPaneVtableData.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147260`; output `147261` | `0`; `ok:1` | deferred |
| `000000016479` | `2026-07-22T17:40:38-04:00` | UID00029V lookup roots | `python .\tools\validator.py --mode file --file .\by-memory\0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147286`; output `147287` | `0`; `ok:1` | deferred |
| `000000016480` | `2026-07-22T17:41:49-04:00` | UID0000OC Surface support | `python .\tools\validator.py --mode file --file .\by-file\Surface.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147318`; output `147319` | `0`; `ok:1` | deferred |
| `000000016481` | `2026-07-22T17:42:36-04:00` | UID00039Y R8 | `python .\tools\validator.py --mode file --file .\by-memory\0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147345`; output `147346` | `0`; `ok:1`; metadata/path registered | deferred |
| `000000016482` | `2026-07-22T17:43:37-04:00` | UID00039Z R9 | `python .\tools\validator.py --mode file --file .\by-memory\0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147369`; output `147370` | `0`; `ok:1`; metadata/path registered | deferred |
| `000000016483` | `2026-07-22T17:44:23-04:00` | UID0003A3 R10 | `python .\tools\validator.py --mode file --file .\by-memory\0x00559410-0x005595ca.ScreenPanePresentationTraversal.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147392`; output `147393` | `0`; `ok:1` | deferred |
| `000000016485` | `2026-07-22T17:47:35-04:00` | UID0000CB alignment correction | `python .\tools\validator.py --mode file --file .\by-class\ScreenPane.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147442`; output `147443` | `0`; `ok:1` | deferred |
| `000000016486` | `2026-07-22T17:48:04-04:00` | UID0000NB alignment contract sync | `python .\tools\validator.py --mode file --file .\by-file\ScreenPane.md --apply --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call `147456`; output `147457` | `0`; `ok:1` | deferred |
| `000000016487` | `2026-07-22T17:48:39-04:00` | final waited UID0000NB validation | `python .\tools\validator.py --mode file --file .\by-file\ScreenPane.md --apply --wait-generated --queue-timeout 240` | `E:\NTK\GhidraBridge\source-3\project-documentation` | call/initial output `147480`/`147481`; wait/wait-output `147484`/`147485` | `0`; `ok:1`; 20 seconds | completed |

- Command-specific `ok` provenance: command `000000016465` emitted no `ok` field in its matched output; commands `000000016476`, `000000016481`, and `000000016482` each emitted literal `ok: 1` in their own matched output records; every other command in the 18-row table also emitted literal `ok: 1` in its own matched output record. None of these values is inferred from the aggregate warning summary below.

- Scoped/final warnings were existing or registry-bootstrap `missing_ref_uid` rows for current project entries such as UID00039R/39Y/39Z/3A0/3A2, plus broad generated-tree children-marker/emitter diagnostics unrelated to this exact route. They did not invalidate scoped `ok:1`; commands 16481/16482 registered the previously absent exact UID paths. No validator-state file was manually edited.
- Historical callback-generation checkpoint: final waited command `000000016487` produced `ScreenPane.cpp` SHA256 `8DD6733C149765E4503B995B950F385C262498072B9D37818E72BACD5E3905E1`, 17,128 bytes / 543 lines, and `Surface.cpp` SHA256 `C49E4713474711271339B9DF4FD70DBD3616A9553C6E60E9A915F06F6DD54FF4`, 24,128 bytes / 681 lines. That output first proved the corrected callback-generated route and remains historical implementation provenance rather than the current generated-file identity.
- Historical intermediate foreground checkpoint: unrelated validator command `000000016565`, `2026-07-22T19:48:00-04:00`, refreshed both files with headers `validator-command-id: 000000016565`, `validator-refreshed-at: 2026-07-22T19:48:00-04:00`, and `validator-refresh-source: foreground-generated-refresh`. Its `ScreenPane.cpp` was SHA256 `2EEA98EE582754A1BEBF04EDD723D8F74502D6C9BF33B40A281C5CD88DD4D9D7`, 17,128 bytes / 543 lines; its `Surface.cpp` was SHA256 `D8F2587BA903A4DF2B4503756130BE6926982C0FA80F36E4321597C7A587DAA7`, 24,128 bytes / 681 lines. Both retained the accepted semantic shape described by the current checkpoint below, but these hashes are no longer current artifact identities.
- Historical prior foreground checkpoint: unrelated validator command `000000016569`, `2026-07-22T20:20:37-04:00`, refreshed both files with headers `validator-command-id: 000000016569`, `validator-refreshed-at: 2026-07-22T20:20:37-04:00`, and `validator-refresh-source: foreground-generated-refresh`. Its `ScreenPane.cpp` was SHA256 `9BE5B4FEC38E9777ECD58B6B837AC2C11C817B34EE933DE29C3C61873E7B4B4F`, 17,128 bytes / 543 lines; its `Surface.cpp` was SHA256 `5444F4E45543EC2F93A51397CEA51B2F36AF9E3FB17EE43A4BC0E6CC07BDBF9A`, 24,128 bytes / 681 lines. Both retained the accepted semantic shape, but these hashes are no longer current artifact identities.
- Current exact generated checkpoint: repository-wide validator command `000000016594`, `2026-07-22T20:38:53-04:00`, refreshed both files with headers `validator-command-id: 000000016594`, `validator-refreshed-at: 2026-07-22T20:38:53-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
  - `auto-generated/NexusTK/ui/core/ScreenPane.cpp`: SHA256 `D99D96E1A714FA4B29115566BD265D9CB88BE566C4D89AD8261DD41914B8FC02`, 17,128 bytes / 543 lines. Exact readback finds one `class ScreenPane : public Pane` declaration, one `ScreenPane::~ScreenPane()` definition, one `ScreenPane *g_pScreenPane = 0` semantic-global definition, and one occurrence each of UID00039Y/R8, UID00039Z/R9, and UID0003A3/R10. It contains zero `Empty Emitter Marker`, zero stale `m_timerHandler`/`m_grafPortSurface`/`m_presentationSurface`, zero target addresses `0x00559b20`/`0x00559b8b`, and no handwritten vtable/RTTI output.
  - `auto-generated/NexusTK/render/Surface.cpp`: SHA256 `588DCFA2EAD64219E6E5647501908F03D31C5A1F9BF68015252E54CFDD60FEFA`, 24,128 bytes / 681 lines. UID00029V occurs once and emits exactly one `unsigned char **g_surfaceColorLookup5Bit = 0` plus one `unsigned char **g_surfaceColorLookup6Bit = 0`; neither definition is file-static or initialized to `-1`, and the UID00029V block has no Empty Emitter Marker. Exactly 18 unrelated Surface Empty Emitter Markers remain elsewhere and are outside this callback.
- ABI hard gate: x86 MSVC 14.44.35207 via `vcvars32.bat`, `/d1reportSingleClassLayoutScreenPane`, and compile-time assertions. First compile correctly failed because the unaligned `0x420` byte member started at decimal 301 / `+0x12d`. After `__declspec(align(4))`, compile exited `0`; class-layout output reports size 1460 / `0x5b4`, Pane `0`, EventHandler/TimerHandler facets decimal 160/164 (`+0xa0/+0xa4`), FrameHandler 248 (`+0xf8`), Singleton and first member both 252 (`+0xfc`), storage 304 (`+0x130`) and all later required offsets through byte flags 1456/1457/1458 (`+0x5b0/+0x5b1/+0x5b2`). Every static assertion passed. Temporary source/object were removed.

## Changed Files

- Same report preserved and updated in place; historical preimplementation Gate 1 accepted input SHA256 was `E0B4475E8D1F8368AE5F3F6A6E687F6A0CAD360E5BB1E38BA57C9C4179404DC8`, while immediate predecessor `D4CBAC58037A46E8E94B58E4248D838599E4DDC4CAA6511A867EF1BB39BA905B` failed its fresh Gate 1 current-state audit.
- No file was renamed or deleted. UID0004W7 was created first through the supported registration workflow.

| Ordinary destination | Final SHA256 | Bytes / lines |
| --- | --- | ---: |
| `by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md` | `F9E5DD14E1E1B12A9F795965A9E4DBFCCEF8886D8015C1B5E5AF97C24F056107` | 14,268 / 200 |
| `by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md` | `F209E8C8B997290031FD9D39D755F9FC4C8DEC67633A1A94A6A09640A2C0AF3F` | 12,969 / 131 |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | `8778AFA0CD3BF8F2C5CE80F90D34720C72BDCF568CB58C67DD0D2F4BBFA1581D` | 31,034 / 170 |
| `by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md` | `A65EFF2FDD607E13EFED4EF267C4E37B169D029721724AD6EE43846B07F46F60` | 22,560 / 170 |
| `by-class/ScreenPane.md` | `AFA09AA6A8074734C93AEF6A80E0CE5FED25C9E05A0B36740A26FD199E0623B9` | 55,752 / 363 |
| `by-file/ScreenPane.md` | `16D96EDF9B98BB48D10397DB3F4D590608726703E3132E7764C84D8958AA075B` | 50,967 / 241 |
| `by-global/g_pScreenPane.md` | `D0AB59707FBAC14B5A260D9E403A1BC8FCF1A6DE903CF248D4DF47E195210645` | 14,518 / 115 |
| `by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md` | `3FD3640DF8268EEFD072752DAE837B4E4370FE63D382B59845B5DE8B751CD521` | 10,674 / 96 |
| `by-memory/0x006230e8-0x0062317c.ScreenPaneVtableData.md` | `75255C9B5D143FFC262655A9D0A5CE3B8729C12E21A11297211D31401F49F81E` | 7,507 / 76 |
| `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md` | `0BC1B49DB32C0515DDC48FE02FCA1EEA60A6633ABC810E43BF5463F79B5F3064` | 11,185 / 103 |
| `by-file/Surface.md` | `A45370372C51A9DD118540E94D766F0112B30ED51CD2BBCD34FDA4286B4A5C8A` | 108,467 / 452 |
| `by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md` | `0049F7994BF32D425D9777FC49378948A7E504D2FE44AFA8FFD95A3EE7CE5935` | 24,730 / 306 |
| `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md` | `7881F13FF3F279597C321A2C6F8312090365A5DF5D3911FAC889F04333DEA5F1` | 18,498 / 191 |
| `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | `ECD433555A2C3EA9AF0F86F8B1F78214BBFC98865F4D1C5146AF1DCBE7480C20` | 20,820 / 220 |

- Historical callback validator-owned side effects included `tools/validator.ini`, projected completion stats, generated coverage metadata, and the implementation-time generated C++ refresh under command `000000016487`. Unrelated validator commands `000000016565` and `000000016569` are retained as historical intermediate foreground refreshes. The current generated files were later foreground-refreshed by repository-wide validator command `000000016594` at `2026-07-22T20:38:53-04:00`; their exact current hashes and unchanged accepted semantic shape are recorded under Current Target State and Validator Results. B003 made no manual edits to generated/tracker/validator-state files.
- Manual coverage files were reread for this repair and were not edited. The former post-B001/B002/B005, prior-repair, exact-verification, and B004 epochs are historical: respectively by-memory/by-class/by-file/by-global `5DCC8DDA8B60AEBE3A8F665F2A845BC216F5C5FC3983473981E1208957961E69` / `7B42EED85BE48C2A196E5DD599AD5EE0A5B3C53E5EA9F5A56AACB75B9B33FBFE` / `40713D5C4652FA336A7D243A19CB66FC7A1E9EF0B143D048F7EB99899741C069` / `F79F04B44824C59A4CDC8EEA145C6CDBD2564571754C1FFE61B2471F07E5FEBF`; `9B6349476C5A16512F7DACA26F84830FD51DF3C36C6BF7F59AA24EBCFCE58E12` / `CF4D4F7C166A66E300ECABAA8A3F0F8E99F301112A72D372806E90713A8E3A5C` / `21122F425C67038A1006B3F61F55D70658002B0C63CB53B046E4F54E9E4FEFE7` / `E0D917B49A4FF18AA3B9E83DACFF83DE34C062744B4D5533696D2782D4C6F592`; `EEB04A9CEBB5678F4C9AB0039D4CE1E1586C3DCE0F67333A12B14B6AEDE471A7` / `12FAE415EEF36A9B66BE028C9617D8F997CF08C961CEB134B0D318B2F3768388` / `CE1C169E10BC184E570C9B5EB37CA43251A50C02BF23818FCA2BE0686A4A8599` / `E0D917B49A4FF18AA3B9E83DACFF83DE34C062744B4D5533696D2782D4C6F592`; and `AACB752C3DB0E27C102E5472533E5589DF3AB17E68173FA179B48AFC030935D1` / `B87E73A626B3015381C7FF34DF60CDAE4212235785D62BB88A1BC5F0F627DAA6` / `0C080920BF582A99914663321F58DA10828F9C211786A6A2E3043C1F19BE43FE` / `0A8555A911EDD1424458970C3BD5CB9A0095944C444F05F21AD2FB803809A915`. Current exact roots are by-memory `A7D812B60CB35399C541461DC0E214A8380B61D7793E2BB499B9247449A1A70B` at 1,982,596 bytes / 4,564 lines, by-class `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E` at 257,808 bytes / 624 lines, by-file `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90` at 154,448 bytes / 317 lines, and by-global `D25BDD5BB2F097258C9B76628317CDC773F8E4F1014B808BAB421E1CC0040226` at 99,098 bytes / 217 lines. All 14 C20 row bodies remain exact and occur once: by-memory UID0001G5/0004W7/0002VO at lines 3049/3050/3051, UID00039Y/00039Z/0003A3 at 3064/3065/3066, UID00023U at 3072, UID0003CI at 4159, UID0001OX at 4351, and UID00029V at 4451; by-class UID0000CB at 466; by-file UID0000NB/0000OC at 237/274; and by-global UID0000S7 at 139. C20 is terminal `already-present`; no manual application remains pending, and only independent supervisor readback/validation or no-loss drift repair after an actual later row change is external to B003. The original pre-execution handoff required Gate 1 and Gate 2 before supervisor action; that requirement is a historical checkpoint, while the latest validator path/footer governs lifecycle truth.
- The final settled tracker checkpoint is repository-wide command `000000016626`, refreshed `2026-07-22T22:16:12-04:00` from `deferred-generated-refresh`: SHA256 `331381565D56CC8ED83F7FD7234C22A81CF8FF1E8109543A12FA4E5C2A724C23`, 1,634,570 bytes / 6,507 lines, summary 5,585 tracked / 2,035 covered / 3,550 not covered / 36.4%. UID00023U is exactly line 5426 at 92/94, combined 93.0, reconstructable false, with zero direct/additional/B-report coverage and path `by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md`. Older tracker identities are historical; B003 did not edit the tracker.
- During B003's implementation/report-repair actions, B003 performed no IDA mutation, lifecycle command, `execute_report` probe/run, report move/archive, or audit/supervisor edit. Validator-owned commands `000000016527` and `000000016537` are separate supervisor/validator lifecycle events recorded in the footer. Final B003 lease count is zero.

## Implementation Tracking Checklist

Historical Gate 1 plan preserved as non-actionable prose. These were the pre-callback obligations; their completed state and proof are represented by C01-C20, R0-R10, the validator/generated/ABI sections, and the terminal callback checklist below:

- Historical obligation: supervisor validation was required before implementation.
- Historical obligation: re-read UID00023U immediately before callback and preserve concurrent detail.
- Historical obligation: apply C01-C20 with claim-specific destination proof.
- Historical obligation: set UID00023U to 92/94, owner UID0000CB, false, blank emitter/position/R0, Nested0.
- Historical obligation: preserve exact UID00023U range, 107-byte hash, five-function inventory, 33-instruction history, internal and external padding.
- Historical obligation: historicalize the stale source-authored `0x00559b20` classification.
- Historical obligation: preserve exact adjustor immediates, vtable refs, wrapper flags/calls, object size, and negative evidence.
- Historical obligation: register UID0004W7 through the validator-supported new-file workflow (`000000016465`, `2026-07-22T17:23:44-04:00`, exit 0; the matched output emitted no `ok` field, while successful UID0004W7 insertion confirmed registration).
- Historical obligation: replace every former child placeholder with issued UID0004W7 before validating dependents.
- Historical obligation: create exact `0x00556a60-0x00556cd4.ScreenPaneDestructor.md` at 92/94, owner/emitter UID0000CB, true, blank position, Nested+4.
- Historical obligation: install R1 byte-for-byte and preserve exact resource/branch/delete behavior.
- Historical obligation: keep singleton clear, vptrs, explicit bases, wrapper flags/delete, EH/cookies, and raw addresses out of R1.
- Historical obligation: update UID0001G5 to 91/93, owner UID0000CB, false, blank emitter/position/R2, Nested0, with exact child/inventory/padding/source/compiler detail.
- Historical obligation: change UID0002VO Nested4 to 0 and correct adjusted +0x511 to primary +0x5b1; preserve its scores/formal body/behavior/range/route.
- Historical obligation: verify UID0001G6 remains Nested-4 and unrelated content unchanged.
- Historical obligation: update UID0000CB to 92/93 with exact hierarchy/PMD/EBO/size/layout/destructor/callback/global/compiler evidence and install complete physically coherent R3 before children.
- Historical obligation: install target-MSVC-aligned `m_presentationStateStorage[0x420]` at `+0x130` and `m_cursorStateStorage[0x16]` at `+0x582`; preserve the exhausted semantic alternatives and provisional-status explanation.
- Historical obligation: verify `sizeof(ScreenPane)==0x5b4` and every base/member offset listed under R3 with the target 32-bit MSVC class-layout output or a temporary build verifier; reject zero-marker output if any offset differs.
- Historical obligation: update UID0000NB to 93/94 with complete source/compiler inventory, class-before-children order, and zero-marker generated route.
- Historical obligation: update UID0000S7 to 92/94 and install sole-definition R4.
- Historical obligation: update UID0001OX to 92/94, false, blank emitter/position/R5, owner UID0000S7, Nested0.
- Historical obligation: update UID0003CI to 92/94, false, blank emitter/position/R6, owner UID0000CB, Nested8.
- Historical obligation: update UID00029V to 92/94 and install external zero-initialized R7 while preserving all 12/11 xrefs/history.
- Historical obligation: update UID0000OC wording without changing 88/85 or its current render union.
- Historical obligation: update UID00039Y formal to exact R8 with inherited TimerHandler access and unchanged scores/range/behavior.
- Historical obligation: update UID00039Z formal to exact R9 with inherited GrafPort surface access and unchanged scores/range/behavior.
- Historical obligation: update UID0003A3 formal to exact R10 with normalized m_renderSurface and unchanged scores/range/behavior.
- Historical obligation: preserve verify-only ScreenPane children, DirectX/Application/DDError/Pane/FrameHandler/Singleton/runtime support unless exact contradiction is documented.
- Historical obligation: preserve predecessor/successor/internal padding dispositions exactly.
- Historical obligation: preserve rejected helper, raw wrapper, duplicate global, static/-1, raw vtable, blank-class, silent-omission, palette, region-array, cursor-manager/descriptor/path, hidden-base, and speculative-private-aggregate alternatives.
- Historical obligation: run one scoped validator per changed/new ordinary file after acceptance only.
- Historical obligation: use one ordinary lease at a time and release immediately after its scoped validator.
- Historical obligation: run final waited validation through `by-file/ScreenPane.md`.
- Historical obligation: verify generated ScreenPane.cpp contains complete R3 with both bounded storage members before all qualified definitions, R1 once, R4 once, and R8-R10 exactly once when routed.
- Historical obligation: verify zero UID0000CB/UID0001G5/UID00023U/UID0003CI/UID0000S7/UID0001OX Empty Emitter Markers and zero unresolved accepted-route ScreenPane-family markers.
- Historical obligation: verify no target helper/wrapper definition, wrong-range body, duplicate destructor/global, raw vtable/RTTI, EH/cookie, or explicit base teardown.
- Historical obligation: verify existing ScreenPane methods remain once and preserve current order/content.
- Historical obligation: verify generated Surface.cpp contains R7 once and no stale `static`/`-1` lookup roots.
- Historical obligation: record command IDs, timestamps, exits, ok counts, warnings, side effects, hashes, and generated freshness.
- Historical obligation: re-read all manual rows and rebase exact no-loss text over the then-current external epoch.
- Historical obligation: leave manual coverage application to the supervisor.
- Historical obligation: update ledger actions/states to legal callback-terminal values only after independent readback.
- Historical obligation: update Current Target State, Validator Results, Changed Files, hashes, generated proof, and lifecycle-neutral wording.
- Historical obligation: check every implementation item only after it is independently true.
- Historical obligation: confirm zero provisional tokens and zero B003 leases.

Implementation callback pass:

- [x] Historical preimplementation report SHA256 `E0B4475E8D1F8368AE5F3F6A6E687F6A0CAD360E5BB1E38BA57C9C4179404DC8` accepted by supervisor only to authorize the completed implementation callback. The former `pending fresh Gate 1 review` wording was a pre-execution/repair snapshot; validator commands `000000016527` and later `000000016537` supersede it as lifecycle authority.
- [x] All accepted ordinary destination changes incorporated without detail loss.
- [x] C01-C20 terminalized with exact destination, metadata, validator, generated, and manual-handoff proof.
- [x] R0-R10 parity verified at every formal destination; R3 includes the verifier-required target-MSVC alignment correction.
- [x] Target-ABI verification proves complete size `0x5b4`, direct bases `0/+0xf8/+0xfc`, Pane facets `+0xa0/+0xa4`, both bounded storage ranges, and every known later member offset.
- [x] All metadata, scores, owner/emitter, reconstructable, nesting, and source-route changes independently read back; UID0001G6 remains `Nested:-4`.
- [x] All historical corrections, positive/negative evidence, rejected alternatives, and score caps preserved.
- [x] All 14 C20 manual rows rechecked against current roots by-memory `A7D812B60CB35399C541461DC0E214A8380B61D7793E2BB499B9247449A1A70B`, by-class `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E`, by-file `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90`, and by-global `D25BDD5BB2F097258C9B76628317CDC773F8E4F1014B808BAB421E1CC0040226` as already present exactly once and byte-for-byte equal to the report text. Exact anchors are by-memory 3049/3050/3051, 3064/3065/3066, 3072, 4159, 4351, and 4451; by-class 466; by-file 237/274; and by-global 139. The B004 epoch is historical, and B003 did not edit coverage.
- [x] All scoped validators and historical final waited command `000000016487` recorded; commands `000000016565` and `000000016569` retained as historical intermediate foreground refreshes; current command-`000000016594` foreground-generated ScreenPane/Surface artifacts independently inspected by exact header/hash/size/line and semantic-count readback, with the accepted shape unchanged and exactly 18 unrelated Surface markers bounded outside this callback. Final settled tracker command `000000016626`, `2026-07-22T22:16:12-04:00`, source `deferred-generated-refresh`, SHA256 `331381565D56CC8ED83F7FD7234C22A81CF8FF1E8109543A12FA4E5C2A724C23`, 1,634,570 bytes / 6,507 lines, records 5,585 tracked / 2,035 covered / 3,550 not covered / 36.4%; UID00023U is line 5426 at 92/94, combined 93.0, reconstructable false, zero direct/additional/B-report coverage, and the accepted target path.
- [x] Temporary verifier artifacts removed; no implementation item remains blocked and B003 holds zero leases.
- [x] Lifecycle actor boundary is terminal and archive-stable: B003 performed no IDA mutation, audit/supervisor edit, lifecycle action, report move/archive, or `execute_report` run/probe. The standalone handoff token below is a durable historical token, not a mutable status assertion; current lifecycle/path truth always comes from the latest validator path/footer. The existing validator-owned command `000000016527` execution and later `000000016537` de-execute-for-rework footer events are immutable and balanced, and every future supervisor lifecycle action remains outside B003.

Historical supervisor-stage sequence retained as non-actionable process context; none of these lines is open B003 checklist work or a mutable current-lifecycle assertion:

- Historical supervisor stage: perform a complete exact-artifact Gate 1 audit after any report mutation.
- Historical supervisor stage: independently perform Gate 2 claim-by-claim verification against C01-C20, R0-R10, ordinary destination hashes/content, validator records, generated output, ABI proof, and the completed B003 checklist after Gate 1 passes.
- Historical supervisor stage: independently read back and validate the already-present C20 rows against the then-current by-memory/by-class/by-file/by-global roots, applying only no-loss drift repair if an actual later row change is found.
- Historical supervisor stage: perform any validator lifecycle execution only after exact-artifact Gate 1, independent Gate 2, and manual-row readback/validation; B003 must never run or probe it.
- Historical supervisor stage: after any execution changes the path/footer/hash, perform a complete fresh Gate 1 audit of the exact archived artifact before counting, defending, or treating it as accepted coverage.

Historical pre-execution/repair snapshot only: the earlier Gate 1 review handoff is retained as prose, and its lifecycle meaning is superseded by every later validator footer event.

Archive-stable handoff rule: the standalone token below is a durable historical completion handoff and does not assert pending, active, executed, archived, or moved status. Current lifecycle/path truth always comes from the latest validator path/footer; the existing command `000000016527` / `000000016537` footer chronology is immutable, and any later footer supersedes body-era lifecycle snapshots.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000016527","destination_path":"executed-b-agent-research/B003/00023U-ScreenPaneDestructorThunkIsland-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00023U-ScreenPaneDestructorThunkIsland-source-quality.md","timestamp":"2026-07-22T18:44:03-04:00","uid":"00023U"} -->
<!-- {"agent":"B003","command_id":"000000016537","destination_path":"tools/leaser/Agents/Agent-B003/research/00023U-ScreenPaneDestructorThunkIsland-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B003/00023U-ScreenPaneDestructorThunkIsland-source-quality.md","timestamp":"2026-07-22T19:07:39-04:00","uid":"00023U"} -->
<!-- {"agent":"B003","command_id":"000000016627","destination_path":"executed-b-agent-research/B003/00023U-ScreenPaneDestructorThunkIsland-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00023U-ScreenPaneDestructorThunkIsland-source-quality.md","timestamp":"2026-07-22T22:30:22-04:00","uid":"00023U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

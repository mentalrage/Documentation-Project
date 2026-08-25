*** UID:0000DY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StaffsDialogPane : public DialogPane,
                         public Singleton<StaffsDialogPane>
{
public:
    StaffsDialogPane();

protected:
    virtual void OnControlCommand(int controlId, int notifyCode);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaffsDialogPane

## Status

- Confidence: very strong for direct bases, EBO, size, no-field layout, virtual identity, resource/singleton ownership, vtable support, source/compiler split, and login placement; direct constructor reachability remains only a confidence cap.
- Likely source file: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- Core address range: [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- Support ranges: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md), [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md)
- Source file: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)

## Class Purpose

`StaffsDialogPane` is a pre-login/main-menu credits or staff listing dialog. It directly derives from [UID:00003T][DialogPane](by-class/DialogPane.md) and `Singleton<StaffsDialogPane>`, displays a `STAFF.EPF` background using `NPAL8.PAL`, adds a close button, and embeds a [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) loaded from either `STAFFS` or `STAFFS2`.

The `STAFFS2` variant is selected when the byte returned by `EventMan::GetModifierState(unsigned char *)` has literal bit `0x02` set; otherwise `STAFFS` is used. Current evidence ties the dialog to the pre-login/main-menu route: UID00019Z uses `g_mainUiLayerSlots.overlayPaneLayerContext` for `0x0069b36c` and concrete `g_pMainMenuPane` for `0x0067aba4`. Historical `g_mainUiLayer`, `g_pMainUiGraph`, invented event-enum, and `GetCurrentEventFlags` wording is superseded. IDA MCP reports no direct constructor caller or VA/RVA/rel32 route, so the complete out-of-line body is retained linked source and the absent route caps confidence rather than blocking emission.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x004ffaa0-0x004ffd1d` | Builds the dialog shell, background image, close button, and scrolled staff text; attaches through `g_mainUiLayerSlots.overlayPaneLayerContext`, shows with `g_pMainMenuPane`, and slides open. [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) carries the accepted formal source C++. |
| `OnControlCommand` | `0x004ffd20-0x004ffd3d` | Exact DialogPane virtual `void OnControlCommand(int controlId, int notifyCode)`. It handles only `controlId == 1`, ignores `notifyCode`, slides closed, and closes the dialog. [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) carries the exact formal body. |
| Singleton base destructor | [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md) | Exact `0xb` compiler-generated `Singleton<StaffsDialogPane>` base-destructor instantiation used by constructor EH cleanup. It clears the global because of the direct empty base at `+0x26c`; it is not a handwritten helper or class method. |
| Adjustor thunks | [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md) | Two real `0xb` destructor adjustor thunks; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), both live vtable targets. |
| Scalar deleting destructor | [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md) | Exact compiler scalar deleting wrapper. Singleton clear, `DialogPane::~DialogPane()` at `0x0049d9f0`, vptr/base teardown, delete flags, guard, conditional free, and adjustor routes are compiler/base output. No unique authored destructor statement remains, so the class intentionally omits an explicit destructor. |

## Inheritance And Layout

- Direct bases are `DialogPane` and `Singleton<StaffsDialogPane>`.
- Complete object size is `0x26c`; Singleton PMD `{0x26c,-1,0}` and attributes `0x40` prove a direct nonvirtual empty base at complete-object end.
- StaffsDialogPane adds no authored data members. The vtable views at object offsets `0`, `0xa0`, and `0xa4` come from the inherited DialogPane hierarchy, not derived fields.
- Exact RTTI hierarchy has eight entries: StaffsDialogPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and Singleton.
- The source declaration therefore needs only the two direct bases, constructor, and protected `OnControlCommand` override. It needs no fields and no explicit destructor.

## Vtable And Compiler Support

- [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md) carries the exact physical three-view cluster; [UID:0004VK][StaffsDialogPaneVtables](by-type/by-vtable/StaffsDialogPaneVtables.md) carries the semantic compiler-data inventory.
- Primary `0x0061d934` routes to scalar wrapper `0x00502cc0`; primary `+0x48`, cell `0x0061d97c`, routes to `OnControlCommand` `0x004ffd20`.
- Secondary `0x0061d994` and tertiary `0x0061d9c4` route through the `-0xa0` and `-0xa4` destructor adjustors; `0x0061d9c8 -> 0x00544e90` is inherited/shared.
- Constructor vptr stores, implicit destructor, Singleton publication/clear, EH cleanup, scalar wrapper, adjustors, delete flags, and RTTI/vtable arrays are compiler output caused by this declaration and must not be handwritten.

## Resource Notes

- Background/layout resource: `STAFF.EPF`.
- Palette: `NPAL8.PAL`.
- Text resources: `STAFFS` and `STAFFS2`.
- Close button id: `14`.
- Text rectangle: approximately `(38, 62)-(230, 305)`.
- Dialog offset: based on `STAFF.EPF` dimensions, then offset to around x `630`, y `130` before creating through the main UI layer/context and showing through `g_pMainMenuPane`.

See [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md) for the resource-centered view.

## Evidence Notes

- 2026-06-06 live IDA MCP confirms real functions at `0x004ffaa0`, `0x004ffd20`, `0x00502410`, `0x00502592`, `0x0050259d`, and `0x00502cc0`.
- IDA MCP `callees 0x004ffaa0` includes `DialogPane` construction, `EPFImageControlPane`, `ImageButtonControlPane`, `ScrolledTextControlPane` constructor `0x004ff040`, resource frame lookup `0x004d0530`, and `DialogPane` show/slide helpers.
- IDA MCP `xrefs_to 0x0069b490` shows writes/clears from the constructor, the singleton clear helper, and the scalar deleting destructor.
- IDA MCP `xrefs_to 0x0050259d` shows a vtable data xref at `0x0061d9c4`, proving the second thunk is a live compiler-emitted vtable target.
- IDA MCP `xrefs_to 0x004ffd20` reports the action-handler vtable data ref at `0x0061d97c`, and `xrefs_to 0x00502cc0` reports the primary destructor vtable data ref at `0x0061d934` plus the two thunk code refs.
- 2026-05-26 recheck: `0x00502410` and `0x00502592-0x005025a8` are compiler-generated cleanup/thunk spans, now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- IDA MCP reports no direct callers for the constructor, action handler, or scalar deleting destructor in the current database. Treat this as an open reachability issue rather than proof the dialog is dead.
- 2026-06-16 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed the constructor/action/clear-helper/thunk/destructor function records, the action-handler vtable ref at `0x0061d97c`, the destructor vtable ref at `0x0061d934`, the thunk refs at `0x0061d994` and `0x0061d9c4`, and the four `g_pStaffsDialog` lifecycle xrefs.
- Current constructor decompilation reconfirmed the singleton publication/null-adjustment path, three `StaffsDialogPane` vtable stores, `STAFF.EPF` lookup through `off_66DB44`, `NPAL8.PAL` background setup, close button id `14`, and the event-flag split between `STAFFS2` and `STAFFS`.
- Current method decompilation reconfirmed control id `1` as the only handled path, calling slide-close and dialog-close helpers while ignoring the second parameter. The DialogPane slot contract resolves the source name as `OnControlCommand`, not historical `OnDialogAction`. Scalar-wrapper decompilation reconfirmed implicit Singleton clear, base dialog cleanup, and conditional delete; the inherited `boost::exception` label is type pollution, not ownership evidence.
- A PE-section-mapped scan found zero absolute-VA, RVA, or direct `E8`/`E9` hits to the constructor at `0x004ffaa0`. The same scan found only the expected vtable/thunk evidence for the action handler and destructor. This keeps direct constructor reachability as a real source-placement blocker while strengthening the class ownership evidence.
- 2026-07-03 B014 MCP/local implementation recheck used active session `3a33af0b`, with `server_health` ok and active IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Current `lookup_funcs` reports raw labels (`sub_4FFAA0`, `sub_4FFD20`) rather than older saved source-quality names, but reconfirms sizes `0x27d` and `0x1d`, exact padding, action vtable ref `0x0061d97c`, four `g_pStaffsDialog` refs, resource refs, zero constructor xrefs, and zero constructor VA/RVA/rel32 route hits.
- UID00019Z constructor/method C++ and this complete class declaration are source-ready. Exact RTTI/EBO/layout evidence closes the former class-block caveat; the constructor no-route issue now caps confidence only.

## Source Layout Decision

Place this in `login/StaffsDialogPane.cpp` next to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), and other pre-login support dialogs. It is not an in-game social/staff-management dialog; the resource names and main-menu UI layer/graph show path point to a main-menu credit/staff screen.

Emitter order is external singleton global position 0, file-local resource pointer position 5, this class declaration position 10, and constructor/OnControlCommand definitions position 20.

## Score Rationale

- Completion `92`: complete direct bases, EBO/PMD, object size, no-field layout, virtual identity/signature, implicit destructor, vtable/RTTI/source causes, resource/layer/show behavior, source route, formal declaration, and historical corrections are closed.
- Confidence `94`: RTTI, constructor stores, vtable slots, wrapper/adjustor behavior, resource exclusivity, and base declarations agree. Missing original lexical symbols and direct constructor entry route remain bounded confidence caps.

## Historical And Superseded Assumptions

- Historical class prose and C++ explicitly stored/cleared `g_pStaffsDialog`; direct Singleton base construction/destruction proves those writes are compiler/base lowering.
- Historical `OnDialogAction`, `GetCurrentEventFlags`, invented event constant, `g_mainUiLayer`, and `g_pMainUiGraph` names are superseded by current source contracts.
- Historical explicit `StaffsDialogPane::~StaffsDialogPane()` source is rejected because no authored statement remains after Singleton/DialogPane/compiler teardown is removed.
- Older blank-class-C++ and unresolved-layout conclusions are superseded by the exact direct-base, EBO, no-field, size, and vtable analysis above.

## Cross-References

- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md)
- [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md)
- [UID:0004VK][StaffsDialogPaneVtables](by-type/by-vtable/StaffsDialogPaneVtables.md)

## Changes

- 2026-06-06: Raised confidence to `84` and attached the class to [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md).
  - Reasoning: live IDA MCP confirms the method family, singleton lifetime, action/destructor vtable refs, destructor thunk code refs, and compiler-helper exclusions; no final reconstruction C++ was added because the class is below the 95/95 gate.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: initially set completion to `86`, confidence to `78`; later raised confidence to `84` after the live vtable/thunk/destructor recheck.
- Evidence: the page documents dialog purpose, source placement, constructor/action/destructor/support ranges, resources, singleton state, IDA xrefs, ignored cleanup/thunk spans, and reachability caveat; confidence remains capped because live constructor reachability is still open.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, action handler, singleton-clear helper, destructor thunks, and scalar deleting destructor at `0x004ffaa0`, `0x004ffd20`, `0x00502410`, `0x00502592`, `0x0050259d`, and `0x00502cc0`. The likely parent file meets 80/80, but class confidence is `78`, so the parent UID stays blank.
- 2026-06-16 A001 low-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:87`; owner/emitter remain [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md); final C++ remains blank.
  - Evidence: live IDA reconfirmed function records, vtable refs, singleton lifecycle, constructor resource/control setup, action id `1` close behavior, destructor cleanup, and PE-section-mapped zero constructor pointer/direct-branch hits. The remaining blocker is real: no direct constructor caller or raw pointer/branch evidence currently proves the exact source entry path.
- Historical/superseded 2026-06-19 B005 destructor interpretation: [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md) was modeled as emitting `StaffsDialogPane::~StaffsDialogPane() { g_pStaffsDialog = NULL; }`. The accepted 2026-07-21 direct Singleton-base analysis rejects that authored body while retaining the correct `DialogPane::~DialogPane()` identification and compiler scalar-delete mechanics.
- 2026-07-03 B014 UID00019Z implementation sync: Method Notes now record constructor/action first-draft source C++ as ready/applied through [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md); class declaration caveats and constructor reachability caveat remain. Current MCP session `3a33af0b` reconfirmed raw-label function records, behavior, padding, xrefs, route-negative evidence, and current zero-initialized singleton storage.
- 2026-07-21 B001 UID0001PT accepted callback: raised to `92/94`, inserted the complete direct DialogPane/Singleton declaration at position 10, resolved EBO/no-field/implicit-destructor layout, linked physical/semantic vtable evidence, and historicalized stale authored-lifetime and method/global names.

*** UID:000091 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class NewHistoryDialogPane;
extern NewHistoryDialogPane *g_pNewHistoryDialog;

class NewHistoryDialogPane : public DialogPane,
                             public Singleton<NewHistoryDialogPane>
{
public:
    NewHistoryDialogPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewHistoryDialogPane

## Status

- Confidence: very strong for class behavior, direct bases, layout/EBO, vtables, resources, singleton lifecycle, method contracts, and support ranges; high for retained-source liveness because the historic launcher is absent.
- Likely source file: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- Core address range: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- Support ranges: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md)
- Source module: `NexusTK/login/NewHistoryDialogPane.cpp`

## Class Purpose

`NewHistoryDialogPane` is a fieldless full-screen pre-login history/credits dialog derived directly from [UID:00003T][DialogPane](by-class/DialogPane.md) and `Singleton<NewHistoryDialogPane>`. It displays a `HISTORYN.EPF` background using `HISTORYN.PAL` and embeds [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) over the `MADEBY` text resource. The direct Singleton base, not an authored assignment/destructor, publishes and clears [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md).

The dialog closes on Enter, Escape, Space, or mouse-button release event codes `3` and `6`. The embedded `ScrolledTextControlPaneForMadeBy` timer also closes `g_pNewHistoryDialog` when the credits text reaches the end.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x00500410-0x005005b4` | Builds a full-screen dialog, background image, `MADEBY` scrolled text control, creates it with the `dword_69B36C` main UI layer/context slot, and shows it with `g_pMainMenuPane`; no direct/raw PE constructor pointer is present in the current executable. |
| `HandleKeyOrTextEvent(Event *)` | `0x005005c0-0x00500605` | Closes only for `kEventKeyDown` and translated Enter, Escape, or Space; always returns true. |
| `HandlePointerOrMouseEvent(Event *)` | `0x00500610-0x00500632` | Closes only on `kEventLeftButtonUp` or `kEventRightButtonUp`; always returns true. |
| Singleton base destructor | [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md) | Exact `0xb` direct-Singleton base destructor used only by constructor unwind; compiler-generated and non-emitting. |
| Adjustor thunks | [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md) | Two real destructor adjustor thunks documented in [UID:0000VN][-ignored](by-memory/-ignored.md); both are vtable targets and jump to the scalar deleting destructor. |
| Scalar deleting destructor | [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md) | Compiler wrapper for implicit virtual destruction; direct-Singleton clear, `DialogPane::~DialogPane()` at `0x0049d9f0`, delete flags, guard helper, and adjustor thunks are compiler/base output. No authored destructor statement remains. |

## Resource Notes

- Background/layout resource: `HISTORYN.EPF`.
- Palette: `HISTORYN.PAL`.
- Text resource: `MADEBY`.
- Background/control rectangle: `(0, 0)-(1024, 768)`.
- Scrolled text rectangle: `(614, 156)-(950, 556)`.
- Parent/show operands: distinct `g_mainUiLayerSlots.overlayPaneLayerContext` create context and [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) show parent; the two addresses must not be conflated.

See [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) for the resource-centered view.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms real function starts and sizes for the constructor (`0x00500410`, `0x1a4`), key handler (`0x005005c0`, `0x45`), mouse handler (`0x00500610`, `0x22`), singleton clear helper (`0x005023e0`, `0xb`), two destructor adjustor thunks (`0x005024f8` and `0x00502503`, each `0xb`), and scalar deleting destructor (`0x00502920`, `0x45`).
- Constructor disassembly writes `g_pNewHistoryDialog`, installs primary and two secondary `NewHistoryDialogPane` vtables, allocates the `HISTORYN.EPF` image pane and `MADEBY` scrolled text pane, loads the dialog resource, enables focus mode, creates with the `dword_69B36C` main UI layer/context slot, and shows with [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md).
- String/data checks confirm `HISTORYN.PAL`, `HISTORYN.EPF`, and the UTF-16LE `MADEBY` operand passed through `off_61E504`.
- `xrefs_to 0x0069b49c` shows constructor writes, `ScrolledTextControlPaneForMadeBy::OnTimerEvent` close behavior, singleton clear helper `0x005023e0`, and destructor clear.
- `xrefs_to 0x005024f8` and `xrefs_to 0x00502503` show secondary vtable data refs at `0x0061db54` and `0x0061db84`, proving both destructor thunks are real.
- IDA reports no direct callers for `0x00500410`. Exhaustive VA/RVA/raw-pointer/rel32 scans also find no route; this is a retained-source launcher-history caveat, not proof the class is unused.

Checked again on 2026-06-14 with live IDA MCP session `a001_goal2_class_batch`:

- `lookup_funcs` reconfirmed constructor `0x00500410` size `0x1a4`, key handler `0x005005c0` size `0x45`, mouse handler `0x00500610` size `0x22`, singleton clear helper `0x005023e0` size `0xb`, destructor thunks `0x005024f8`/`0x00502503` size `0xb` each, and scalar deleting destructor `0x00502920` size `0x45`.
- Component analysis keeps the constructor in the main-menu history dialog family: it calls the pane/resource setup helpers at `0x0049dfd0`, `0x0049e190`, `0x005446b0`, `0x0049d8a0`, `0x0049db60`, `0x004991f0`, `0x004b7c50`, `0x0049dc10`, `0x004f4aa0`, and `0x004ff400`; the key and mouse handlers both route accepted input through the same close helper family.
- Decompilation of `0x005005c0` shows the event-type check for `message[4] == 8`, narrows the key value through the CRT locale helper, closes for Enter, Escape, or Space (`13`, `27`, `32`), and returns handled.
- `xrefs_to 0x0069b49c` reconfirmed the singleton is written by the constructor at `0x00500465`/`0x0050046c`, read by the timer close path at `0x004ff6eb`, cleared by helper `0x005023e0`, and cleared again by the destructor at `0x00502926`.
- The current database still reports no direct code xrefs to constructor `0x00500410`, so constructor reachability remains the only material score limiter for the class page.
- B003's 2026-06-17 source-quality reanalysis found no raw PE absolute-VA pointer to constructor start `0x00500410`, while the key handler, mouse handler, and scalar deleting destructor are present as vtable pointers. Direct constructor reachability remains a source-history caveat, but it no longer blocks [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) first-draft C++ because unique resources, singleton lifecycle, vtable stores, destructor support, and the made-by scroller close consumer prove the class.

## Class Layout And Compiler Boundary

- Complete object size is exactly `0x26c`, fully covered by DialogPane. Direct `Singleton<NewHistoryDialogPane>` starts at one-past offset `+0x26c` and is empty-base optimized.
- RTTI PMD `{0x26c,-1,0}` and constructor adjustment independently prove the direct Singleton base. EventHandler `+0xa0` and TimerHandler `+0xa4` remain inherited through DialogPane, not repeated direct bases or authored fields.
- The exact vtable/RTTI backing child is [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md); semantic inventory is [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md).
- Three views contain 23/11/2 slots. Primary wrapper cell is `0x0061daf4`; secondary pointer/key cells are `0x0061db58/0x0061db5c`; secondary/tertiary adjusted-wrapper cells are `0x0061db54/0x0061db84`.
- The class has no authored data member and no explicit destructor declaration/body. Vtables, RTTI, vptr stores, Singleton publication/clear, EH base destructor, adjustors, scalar wrapper, base cleanup, and delete flags are compiler/template output.
- The extern global contract is declared before the complete class; the class closes before `[[CHILDREN]]`, preventing children from being emitted inside an unterminated declaration.

## Source Layout Decision

Place this in `NexusTK/login/NewHistoryDialogPane.cpp` next to [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), and [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md). Keep [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) in the reusable text-control module; this class only composes it for the `HISTORYN`/`MADEBY` screen.

## Score Rationale

The class is `92/94`: direct bases, exact size/EBO, no fields, complete C++03 declaration, mutable Event-pointer virtual contracts, implicit destructor, one extern contract, all three vtable views, complete compiler/source separation, resource ownership, and source route are closed. Confidence remains below perfect because original symbols and a surviving constructor launcher are absent; that bounded caveat does not block source readiness.

## Cross-References

- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md)
- [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented the constructor, event handlers, singleton helpers, destructor family, resources, and source-layout decision.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: IDA-backed function starts, singleton xrefs, vtable thunk notes, resource names, and UI behavior are recorded; confidence remains below strong because direct constructor reachability is still unresolved.
- 2026-06-04: Raised the class page from `78/76` to `82/84`, marked it reconstructable, and attached it to [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md).
  - Before: the page had class behavior and resource notes, but it still had no parent link and lacked the current live vtable/resource/byte-evidence refresh needed for stronger confidence.
  - After: the page records exact live function sizes, singleton and vtable xrefs, resource operands, input-close behavior, support thunk ownership, and the `NexusTK/login/` parent file.
  - Evidence: 2026-06-04 live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, vtable dword reads, string/data checks, and core byte checks recorded here and in [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md).
- 2026-06-14: raised from `82/84` to `85/86` after live IDA MCP session `a001_goal2_class_batch` reconfirmed the full constructor/input/destructor-support function set, singleton xrefs, key-close decompilation, and unchanged no-direct-constructor-xref caveat. Class-level C++ stays blank pending final header/declaration shape; method-body first-draft C++ belongs to [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md).
- Historical 2026-06-17 B003 source-quality support update: correctly separated `dword_69B36C` from the then-current `g_pMainUiGraph` alias, narrowed mouse event codes `3`/`6` to release events, and recorded the raw PE no-pointer result for constructor start `0x00500410`. Current source-facing show parent is `g_pMainMenuPane` at the distinct `0x0067aba4` slot.
- Historical 2026-06-19 B005 support emitted a first-draft ordinary destructor clear. The 2026-07-21 direct-Singleton RTTI/EBO pass supersedes that authored-clear conclusion while preserving the exact wrapper/base evidence.
- 2026-07-21 B004 UID0001PV accepted callback: raised the class to `92/94`, set source position 10, installed the complete fieldless DialogPane/direct-Singleton declaration and extern contract, corrected both Event virtuals, closed the class before `[[CHILDREN]]`, documented exact size/EBO/vtable/RTTI/compiler boundaries and real UIDs 0004VL/0004VM, removed explicit destructor source, and retained the exhaustive constructor-reachability caveat.

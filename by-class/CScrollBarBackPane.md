*** UID:00003D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CScrollBarBackPane : public Pane
{
public:
    CScrollBarBackPane();
    virtual ~CScrollBarBackPane();

    virtual void OnPaint();
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CScrollBarBackPane

## Status

- Confidence: very strong for class behavior, exact source-method split, Pane virtual identity, vtable/subobject ownership, NewOptionPane lifetime, and helper/global contracts; strong for the inferred original OptionPane source placement.
- Source file: [UID:0000M7][OptionPane](by-file/OptionPane.md)
- Main address ranges: `0x0053fea0-0x0053ff8d`, `0x00542680-0x005426d5`, and vtable data `0x00621018-0x006210a0`
- Historical recovered-file lead: `source-3/simroot_v2/class_CScrollBarBackPane.cpp`. The current reconstruction places this local support class in `NexusTK/ui/dialogs/OptionPane.cpp` through [UID:0000M7][OptionPane](by-file/OptionPane.md); the standalone recovered filename is evidence history, not the current source route.

## Class Purpose

`CScrollBarBackPane` is a Pane-derived NewOptionPane volume-slider backplate. Its `OnPaint()` draws a minus sign, three-line groove, and plus sign through inherited `GrafPort::MoveTo` plus runtime `g_pfnDrawLineDelta`. NewOptionPane owns two instances for music and sound volume controls.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md) | `CScrollBarBackPane::CScrollBarBackPane()` | Authored out-of-line constructor with `Pane(true)`; explicit class-view stores are compiler lowering. |
| [UID:0004Y9][0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md) | `CScrollBarBackPane::~CScrollBarBackPane()` | Authored out-of-line empty virtual destructor; view restoration and Pane teardown are compiler lowering. |
| [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md) | `CScrollBarBackPane::OnPaint()` | Pane slot `+0x44`; draws exact minus/groove/plus volume-slider geometry. |
| `0x00542680-0x005426d5` | `ScalarDeletingDestructor` | MSVC-generated deleting-destructor wrapper: resets vtables, calls ordinary `Pane::~Pane()`, optionally routes through `OperatorDeleteWrapper`, and emits only a comment marker rather than handwritten source. |
| [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md) | compiler vtable/RTTI data | Primary, secondary, and tertiary table groups for this class; non-emitting evidence child. |
| [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) | compiler adjustors | EventHandler `this-0xa0` and TimerHandler `this-0xa4` scalar-deleting-destructor entries; no handwritten source. |

## Evidence Notes

- IDA MCP and prior generated metadata identify `0x0054259f` and `0x005425aa` as this-adjustor thunks into the scalar deleting destructor.
- Historical 2026-06-01 label `DrawScrollBarBackPattern` described the fixed coordinates from `0` through `100`. Current evidence resolves the source method as `CScrollBarBackPane::OnPaint()`, drawing the volume-slider minus sign, three-line groove, and plus sign; the old descriptive label is not current source identity.
- Current generated source types destructor support through unrelated classes (`BowGaugeObjectPane` and `TextButtonExControlPane`), which is likely owner-name pollution.
- 2026-06-01 IDA MCP confirms the constructor bytes at `0x0053fea0-0x0053fed2`; IDA does not define a function object there, but the disassembly shows the `Pane`-base constructor call `0x00544460`, writes vtables at `+0x0`, `+0xa0`, and `+0xa4`, returns `this`, and then aligns to the helper at `0x0053fee0`.
- Historical 2026-06-01 raw IDA state labeled `0x0053fee0-0x0053feff` as cleanup helper `sub_53FEE0`; its three view restores and tail jump to ordinary `Pane::~Pane()` at `0x00544580`, together with the separate scalar wrapper and adjustors, now resolve it as the compiler-lowered body of the authored empty `CScrollBarBackPane::~CScrollBarBackPane()` destructor.
- Historical 2026-06-01 raw IDA state labeled `0x0053ff00-0x0053ff8d` as `sub_53FF00` and rendered calls through `0x004b9600` and `dword_69B3E4`. Current source identity is `CScrollBarBackPane::OnPaint()`, using resolved `GrafPort::MoveTo(int,int)` and typed `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta` contracts.
- 2026-06-01 IDA MCP xrefs: draw method referenced from `0x00621060`; scalar deleting destructor referenced from `0x0062101c` and adjustor jumps `0x005425a5`/`0x005425b0`; adjustor thunks referenced from `0x00621068` and `0x00621098`.
- 2026-06-12 IDA MCP recheck splits exact vtable/RTTI child [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md): primary base `0x0062101c`, secondary base `0x00621068`, tertiary base `0x00621098`, successor `NewOptionPane` locator/base at `0x006210a0/0x006210a4`.
- 2026-06-12 IDA MCP recheck confirms the destructor is `0x55` / 85 bytes, the cleanup helper is `0x1f` / 31 bytes, the draw method is `0x8d` / 141 bytes, and the adjustor thunks are `0xb` / 11 bytes each. Values were verified with `tools\int_convert.py`.
- Historical 2026-06-12 ownership gate correctly made this class page the direct parent for [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md), [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md), and [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md), but its then-current [UID:0000NF][ScrollBar](by-file/ScrollBar.md) source-file ancestor is superseded. The current source-file owner is [UID:0000M7][OptionPane](by-file/OptionPane.md) at `93/91`; ScrollBar remains only rejected route history.
- 2026-06-25 B003 IDA MCP session `80de0a67` resolves the stale destructor-support ambiguity: `0x00544580` decompiles as ordinary `Pane::~Pane()` because it restores `Pane` vtables (`0x006219e8`, `0x00621a34`, `0x00621a64`) and performs `Pane` teardown. This is not `TextButtonExControlPane` teardown.
- 2026-06-25 B003 IDA MCP confirms the class deleting wrapper at `0x00542680` writes all three `CScrollBarBackPane` vtables, calls `Pane::~Pane()`, calls `OperatorDeleteWrapper` at `0x004f4ac0` only when `(flags & 1) != 0` and `(flags & 4) == 0`, and takes a compiler/runtime guard path for flag bit `0x4`.
- 2026-06-25 B003 IDA MCP confirms the two class adjustor thunks exactly as `sub ecx, 0A0h; jmp sub_542680` and `sub ecx, 0A4h; jmp sub_542680`; those thunks are ABI glue documented in [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md), not handwritten class methods.
- 2026-07-29 supervisor Gate 2B created exactly one minimal incomplete IDA type `CScrollBarBackPane`, ordinal 942, with no size or members. It also established exact modeled identities and class-pointer prototypes for `CScrollBarBackPane__Constructor`, `CScrollBarBackPane__Destructor`, `CScrollBarBackPane__OnPaint`, and `CScrollBarBackPane__ScalarDeletingDestructor`, plus the one-star EventHandler/TimerHandler adjustors and their accepted function comments. Both stale `Block` address comments are absent; protected GrafPort, predecessor/successor, bytes, ranges, padding, and vtable states remain unchanged.
- The constructor's human initializer remains `Pane(true)` because disassembly has literal `push 1` at `0x0053fea7`. Current Hex-Rays warns `positive sp value has been detected, the output may be wrong!` and renders `Pane__Constructor((Pane *)this, savedregs)` instead of a literal true argument. That bounded analysis artifact is documented rather than allowed to corrupt the source declaration or constructor body.
- Gate 2B saved IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at SHA256 `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`, size `143,189,974` bytes.

## Reconstruction Notes

- Reconstructable is `TRUE` because the complete human class declaration, exact constructor/ordinary-destructor/OnPaint children, vtable writes, destructor/thunk relationship, exact vtable-data child, and current [UID:0000M7][OptionPane](by-file/OptionPane.md) source ownership are backed by IDA and NewOptionPane evidence.
- `0x00544460` and `0x00544580` are now resolved as `Pane::Pane()` and `Pane::~Pane()` dependencies. They should not remain blockers under raw helper names in source-shape discussion.
- The scalar deleting destructor body at `0x00542680` is compiler-generated wrapper glue covered through the class destructor/declaration route. The by-memory destructor page carries a comment-only emitted marker; this class page should not duplicate that wrapper as a handwritten method body.
- Historical 2026-07-01 B007 route-marker state: the class used a comment-only route plus `[[CHILDREN]]`, and its broad declaration was deferred while `0x004b9600`, `dword_69B3E4`, and final layout remained unresolved. The 2026-07-29 closure supersedes that state: the H channel now carries the complete human class declaration, the exact source children emit through OptionPane, and `GrafPort::MoveTo` plus typed `g_pfnDrawLineDelta` are resolved.
- The H block now carries the complete human class declaration. The CPP channel contains only `[[CHILDREN]]`; exact definitions live on UID0004Y8, UID0004Y9, and UID0004YA.
- `GrafPort::MoveTo(int,int)` and typed `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta` are resolved source contracts. No raw helper/global identity remains a declaration blocker.
- Pane owns EventHandler and TimerHandler facets at offsets `+0xa0/+0xa4`; they are not direct bases in the class declaration. Scalar deleting wrapper, adjusted entries, and vtable tables are compiler output and are excluded from handwritten source.

## 2026-07-29 Source-Quality And Ownership Closure

- NewOptionPane contains two `CScrollBarBackPane *` fields at `+0x12cc` and `+0x12d0`, constructs both with `Pane(true)` semantics, gives them paired `120x5` bounds beside music/sound `ScrollVolumePane` controls, and marks them for deletion with those controls.
- Exact OnPaint geometry is minus x `0..4`/y `2`, groove center x `7..94`/y `2`, rails x `8..93`/y `1` and `3`, and plus x `98..102`/y `2` with vertical x `100`/y `0..4`.
- Primary object view is Pane/GrafPort at offset `0`; inherited EventHandler and TimerHandler views are at `+0xa0` and `+0xa4`. Their deleting adjustors subtract those offsets and forward to the scalar wrapper.
- Code/RTTI adjacency plus exclusive NewOptionPane construction/layout/lifetime routes this support class to [UID:0000M7][OptionPane](by-file/OptionPane.md) OptionPane. Generic ScrollPane/ScrollWidget/ScrollablePane code has no construction, storage, layout, deletion, call, or data route to this class.
- Source uses ordinary constructor/destructor/override declarations. It does not reproduce vptr writes, deleting flags, adjusted `this` bodies, static vtable arrays, raw addresses, or decompiler labels.

## Historical Assumptions

- The old [UID:0000NF][ScrollBar](by-file/ScrollBar.md) ScrollBar route was a medium-confidence name-similarity hypothesis. It is retained as rejected history and superseded by exact NewOptionPane ownership and source adjacency.
- `cleanup helper`, `DrawScrollBarBackPattern`, raw `0x004b9600`, `dword_69B3E4`, generic secondary views, and blank-H caution are superseded by the ordinary-destructor family, Pane virtual slot, resolved contracts, inherited facet layout, and complete declaration.
- Earlier generated-source pollution through unrelated class names remains historical lead material only and does not affect the current class/source route.

## Cross-References

- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md) (rejected historical route)
- [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md)
- [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md)
- [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md)
- [UID:0004Y9][0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md)
- [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md)

## Changes

- 2026-07-29 B007 accepted UID0001DV callback:
  - Before: `87/88`, owner/emitter UID0000NF, comment-plus-children CPP, blank H, provisional draw contracts, generic cleanup/draw identities, and current ScrollBar placement.
  - After: `92/94`, owner/emitter UID0000M7, exact class H declaration, `[[CHILDREN]]` CPP, three validator-assigned exact method children, complete minus/groove/plus behavior, inherited Pane facet layout, resolved `MoveTo`/`g_pfnDrawLineDelta` contracts, and compiler scalar/adjustor/vtable exclusions. The old ScrollBar route and generated identities remain only as disproved history.

- 2026-05-28: Changed `DrawScrollBarBackPattern` from `0x0053ff00-0x0053ff8c` to `0x0053ff00-0x0053ff8d`.
  - Before: the method map omitted the function's final `ret` byte.
  - After: the method map matches IDA's full function boundary.
  - Evidence: IDA MCP reports `sub_53FF00` as `0x0053ff00-0x0053ff8d`.
- 2026-05-28: Changed `ScalarDeletingDestructor` from `0x00542680-0x005426d4` to `0x00542680-0x005426d5`.
  - Before: the method map omitted the final byte of the destructor wrapper and left the following bytes as UNKNOWN.
  - After: the method map matches IDA's full function boundary, with following padding and destructor-island rows split separately.
  - Evidence: IDA MCP reports `sub_542680` as `0x00542680-0x005426d5`.
- What existed before: the page had class behavior, method boundaries, and prior range corrections, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor, draw pattern, destructor, and thunk island are documented; final source-file placement and exact class declaration remain incomplete.
- 2026-06-01: Changed completion/confidence from `72/80` to `78/84`, marked reconstructable, and attached parent [UID:0000NF][ScrollBar](by-file/ScrollBar.md).
  - Before: the method map omitted the local cleanup helper and parent autogen metadata was blank.
  - After: current IDA MCP evidence records the constructor bytes, cleanup helper, draw method, destructor xrefs, and vtable refs. C++ remains blank pending final helper/global names.
- 2026-06-12 (A004 Goal 2): Raised completion/confidence from `78/84` to `86/88`.
  - Before: the class was below the strict parent gate, so child pages could only shortcut to the broader [UID:0000NF][ScrollBar](by-file/ScrollBar.md) file parent.
  - After: exact vtable-data child [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md), refreshed constructor/core/destructor evidence, and `tools\int_convert.py` size/offset checks justify the class as the direct parent for the core, destructor, and vtable children. C++ remains blank because helper/global names are still synthetic.
- 2026-06-25 B003 implementation callback: updated destructor-support evidence without changing class score.
  - Before: the class page still described `0x00544460`/`0x00544580` as unresolved helper names and carried generated owner-name pollution from unrelated pane classes.
  - After: B003 report implementation records `0x00544460`/`0x00544580` as `Pane::Pane()`/`Pane::~Pane()` dependencies, classifies the deleting destructor as MSVC-generated wrapper glue covered by a comment-only marker on [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md), and preserves unresolved caution only for the draw helper/global names and final class declaration.
- 2026-07-01 B007 empty-emitter callback: raised completion from `86` to `87` and inserted the formal class-route comment marker with `[[CHILDREN]]`. The class remains reconstructable through [UID:0000NF][ScrollBar](by-file/ScrollBar.md); broad class declaration output remains deferred while exact child pages carry constructor/core/destructor/vtable detail.

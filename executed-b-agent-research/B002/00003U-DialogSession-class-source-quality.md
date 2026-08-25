** TARGET-REPORT-UID:00003U **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report: UID 00003U DialogSession Class Source Quality

Assignment: B002 report-only source-quality reanalysis under the temporary 10-B-agent cap  
Agent: Agent-B002  
Date: 2026-06-19  
Target: [UID:00003U] `by-class/DialogSession.md`  
Required output: `tools/leaser/Agents/Agent-B002/research/00003U-DialogSession-class-source-quality.md`

This was a report-only pass. I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

## Recommendation Summary

Recommended target disposition for a later implementation callback:

- Raise [UID:00003U] `DialogSession` from `85/86` to `90/90`.
- Keep `CANONICAL_OWNER:0000IU`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000IU`.
- Add declaration-level first-draft C++ to the class page, not method-body C++.
- Keep method bodies on exact `by-memory` children or the enclosing [UID:000131] aggregate until exact child splits are accepted.
- Update support docs because the current DialogSession support set omits two source-shaped helpers and misclassifies the tiny `0x004a1380` helper as runtime/library despite broad direct calls.

The best source-facing class shape is:

```cpp
class List;
class DialogInSession;

class DialogSession : public Pane {
public:
    DialogSession();
    virtual ~DialogSession();

    void CloseAllDialogs();
    void PushDialog(DialogInSession *dialog);
    void PopCurrentDialog(bool shouldAnimate);
    DialogInSession *FindPreviousDialog(DialogInSession *dialog);
    DialogInSession *GetDialogAtIndex(int index);

private:
    void ActivateNextDialog(bool shouldAnimate);
    int FindDialogIndex(DialogInSession *dialog);

    List *m_dialogList;                  // +0xf8, elements are DialogInSession*
    unsigned char m_activeDialogIndex;   // +0xfc, 0xff means no active dialog
};

[[CHILDREN]]
```

`ActivateNextDialog` and `FindDialogIndex` are source-shaped helper leaves at `0x004a11e0` and `0x004a13b0` with no direct callers in the current executable. They should be documented because they are real function-shaped code pockets in the class address island, but their declaration should be private/protected until a caller or original-source hint proves a public API.

Do not put `CreateScreenDimmer`, `ReleaseScreenDimmer`, or `IsScreenDimmerActive` inside `DialogSession`. The first is already owned by ScreenDimmer support docs; the latter two are global `g_pScreenDimmer` helpers, not `DialogSession` methods.

## Evidence Checked

Rules and agent state:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md` requirement from the assignment, through the active workspace rules
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `by-structure.md`
- `by-class/-guidance.md`

Target and direct support docs:

- [UID:00003U] `by-class/DialogSession.md`
- [UID:0000IU] `by-file/DialogSession.md`
- [UID:000131] `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md`
- [UID:000132] `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`
- [UID:000134] `by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md`
- [UID:00003S] `by-class/DialogInSession.md`
- [UID:0001U5] `by-type/by-struct/DialogSessionLayouts.md`
- [UID:0001XD] `by-type/by-vtable/DialogSessionVtables.md`
- [UID:0002NB] `by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md`

ScreenDimmer and global support docs:

- [UID:000133] `by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md`
- [UID:0000PJ] `by-global/CreateScreenDimmer_4A12B0.md`
- [UID:0000NA] `by-file/ScreenDimmer.md`
- [UID:0000C8] `by-class/ScreenDimmer.md`
- [UID:0000S5] `by-global/g_pScreenDimmer.md`
- [UID:00029D] `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`
- B002 prior executed report `tools/leaser/Agents/Agent-B002/research/executed/000133-screen-dimmer-factory-source-quality.md`

Caller/source-family support docs:

- [UID:0000ZH] `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`
- [UID:0000HX] `by-file/BulletinSession.md`
- [UID:0000HT] `by-file/BoardDialogs.md`
- `by-project-structure/proposed-source-tree.md` references for the dialog/session source family

Generated/recovered output checked:

- `source-3/simroot_v2/class_DialogSession.cpp`
- `source-3/simroot_v2/class_DialogSession.cpp.disabled`
- `source-3/simroot_v2/class_DialogSession.meta_wave3`
- `source-3/simroot_v2/class_DialogSession.cpp.source_map.json`
- `source-3/simroot_v2/class_DialogInSession.cpp`
- `source-3/simroot_v2/class_DialogInSession.meta_wave3`
- `project-documentation/auto-generated/NexusTK/ui/dialogs/DialogSession.cpp`

Local authoritative binary/listing evidence checked:

- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- `source-3/core/data/readonly/prewave/exported-functions/0x004a11e0.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x004a13b0.json`

Coverage and validator evidence checked:

- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-memory/-coverage-report.md`
- Scoped validator baseline:

_Executable command block removed from the research report; preserved in [00003U-DialogSession-class-source-quality-removed.md](00003U-DialogSession-class-source-quality-removed.md)._

Result: exit code `0`, `ok: 1`. It was a dry run. It scanned the target file, rebuilt the autogen registry, and reported `autogen_cpp_noop 0000IU auto-generated/NexusTK/ui/dialogs/DialogSession.cpp unchanged`. The current generated `DialogSession.cpp` under `project-documentation/auto-generated` still contains only empty emitter markers for `DialogSession`, `DialogInSession`, the aggregate, layouts, vtables, and vtable data.

## Current Target State

[UID:00003U] currently says:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000IU`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000IU`
- final C++ blank

The page correctly identifies `DialogSession` as a full-screen `Pane`-derived session container under [UID:0000IU] `DialogSession.cpp`. It correctly records:

- constructor `0x004a0d80-0x004a0e6e`
- destructor `0x004a0e70-0x004a0f3c`
- close-all `0x004a0f40-0x004a0fbc`
- push `0x004a0fc0-0x004a10d1`
- pop/close-current `0x004a10e0-0x004a11dc`
- previous-dialog lookup `0x004a1250-0x004a12a2`
- ScreenDimmer factory split `0x004a12b0-0x004a1360`
- release helper `0x004a1360-0x004a1371`
- list accessor `0x004a1390-0x004a13a7`
- destructor thunks `0x004a1485`, `0x004a1490`, `0x004a1500`

The page is incomplete or stale in these important ways:

- It does not inventory `0x004a11e0-0x004a124e`, a source-shaped helper that hides the current dialog, increments `m_activeDialogIndex`, and shows the next dialog.
- It does not inventory `0x004a13b0-0x004a13f2`, a source-shaped helper that linearly searches `m_dialogList` and returns an index or `-1`.
- It repeats older generated-output wording that helper bodies were omitted from active generated output. The current `simroot_v2/class_DialogSession.cpp` does include several helper bodies, but the validator-generated `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp` is still empty markers because the docs have blank `RECONSTRUCTION_CPP`.
- It repeats older metadata caveats saying Wave3 reports `vtable_count: 0`; current `class_DialogSession.meta_wave3` and `class_DialogInSession.meta_wave3` both report three vtables.
- It treats `0x004a1380` as a runtime/library predicate in support docs. The byte-level recheck shows it has 24 direct calls and is the paired `g_pScreenDimmer` active predicate used before `0x004a1360`.

## Aggregate Boundary And Child Split Recheck

The aggregate boundary `0x004a0d80-0x004a15f8` remains valid. The first body starts at `0x004a0d80`, the scalar deleting destructor ends at `0x004a15f8`, and the final successor is outside the DialogSession/DialogInSession island.

The internal inventory needs correction:

| Range | Status after this pass | Source-quality role |
| --- | --- | --- |
| `0x004a0d80-0x004a0e6e` | modeled function | `DialogSession::DialogSession()` |
| `0x004a0e70-0x004a0f3c` | modeled function | ordinary `DialogSession::~DialogSession()` cleanup body |
| `0x004a0f40-0x004a0fbc` | modeled function | `DialogSession::CloseAllDialogs()` |
| `0x004a0fc0-0x004a10d1` | modeled function | `DialogSession::PushDialog(DialogInSession *dialog)` |
| `0x004a10e0-0x004a11dc` | modeled function | `DialogSession::PopCurrentDialog(bool shouldAnimate)` |
| `0x004a11e0-0x004a124e` | raw/source-shaped helper, prewave-exported, not in docs | best name `DialogSession::ActivateNextDialog(bool shouldAnimate)`; no direct callers found |
| `0x004a1250-0x004a12a2` | modeled function | `DialogSession::FindPreviousDialog(DialogInSession *dialog)` |
| `0x004a12b0-0x004a1360` | exact child [UID:000133] | `ScreenDimmer *CreateScreenDimmer(void)`, owned by ScreenDimmer, not DialogSession |
| `0x004a1360-0x004a1371` | modeled function | `ReleaseScreenDimmer()` / `DestroyScreenDimmer()` free helper over `g_pScreenDimmer`, not a DialogSession method |
| `0x004a1380-0x004a138b` | collapsed 11-byte function, 24 direct callers | `IsScreenDimmerActive()` / `HasScreenDimmer()` free helper over `g_pScreenDimmer`, not runtime and not DialogSession class |
| `0x004a1390-0x004a13a7` | modeled function | `DialogSession::GetDialogAtIndex(int index)` |
| `0x004a13b0-0x004a13f2` | raw/source-shaped helper, prewave-exported, not in docs | best name `DialogSession::FindDialogIndex(DialogInSession *dialog)`; no direct callers found |
| `0x004a1400-0x004a144e` | modeled function | `DialogInSession::DialogInSession(DialogSession *session, int dialogPaneConfigId, unsigned char dialogType)` |
| `0x004a1450-0x004a146f` | modeled function | ordinary `DialogInSession::~DialogInSession()` cleanup body |
| `0x004a146f-0x004a149b` | exact thunk child [UID:000134] | four compiler-generated destructor adjustor thunks |
| `0x004a14a0-0x004a14f5` | modeled function | `DialogInSession` scalar deleting destructor |
| `0x004a1500-0x004a15f8` | modeled function | `DialogSession` scalar deleting destructor |

The historical [UID:000132] page should therefore no longer say the only source-bearing payload is five helpers. It should say the source-shaped DialogSession payload is seven helpers:

- reached helpers: `0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, `0x004a1250`, `0x004a1390`
- raw/no-direct-call helpers: `0x004a11e0`, `0x004a13b0`

Keep [UID:000132] non-emitting because the historical range still crosses ScreenDimmer helpers, DialogInSession constructor/destructor/scalar destructor bytes, compiler thunks, and the head of the scalar deleting destructor.

## Field, Type, And Layout Recommendations

`DialogSession` layout:

| Offset | Recommended source-facing field | Type recommendation | Evidence |
| --- | --- | --- | --- |
| `+0x00` | primary vptr | compiler-generated vtable pointer | Constructor stores `0x00618d30` at `0x004a0dc1`; destructor paths restore it. |
| `+0x04-+0xf7` | inherited `Pane` state | inherited base object | Constructor calls the `Pane` constructor with mode `4`; later applies full-screen bounds and attaches renderer state. |
| `+0xa0` | secondary/event vptr | compiler-generated vtable pointer | Constructor stores `0x00618d7c`; thunk `0x004a1485` subtracts `0xa0`. |
| `+0xa4` | tertiary/event vptr | compiler-generated vtable pointer | Constructor stores `0x00618dac`; thunk `0x004a1490` subtracts `0xa4`. |
| `+0xf8` | `m_dialogList` | `List *`, element payload is `DialogInSession *` | Constructor allocates 20 bytes, calls list initializer with element size `4` and capacity/block count `16`, stores pointer at `+0xf8`; helper bodies use count at list `+0x0c`, accessor slot `+0x10`, insert slot `+0x18`, erase-range slot `+0x1c`, and deleting slot `+0x00`. |
| `+0xfc` | `m_activeDialogIndex` | `unsigned char` with signed-byte comparisons | Constructor writes `0xff`; helpers use `movsx`, decrement/increment byte, compare against `0xff`, and use signed `jns` behavior. |

Use `List *m_dialogList` in declaration-level C++ rather than a template type. A typed `List<DialogInSession *>` is behaviorally accurate, but the available evidence proves only a custom list object whose element payload is a `DialogInSession *` pointer. The template spelling is not proven.

`DialogInSession` support layout remains:

| Offset | Recommended source-facing field | Type recommendation | Evidence |
| --- | --- | --- | --- |
| `+0x26c` | `m_dialogType` | `unsigned char` | Constructor `0x004a1400` stores `arg_8` here. |
| `+0x270` | `m_session` or `m_sessionData` | `DialogSession *` in source-facing dialog-session contexts; exact original spelling remains inferred | Constructor stores `arg_0` here; board/article/mail constructor sync says callers pass the owning session as this value. |

The constructor role from B014 remains correct: `DialogInSession(DialogSession *session, int dialogPaneConfigId, unsigned char dialogType)`. The common value `2` passed by board/article/mail dialog constructors is the `DialogPane` config/id/style argument forwarded to the base, not the stored dialog type.

## Method Name And Source Shape Recommendations

| Address | Current/generated labels | Recommended source-facing name | Recommendation basis |
| --- | --- | --- | --- |
| `0x004a0d80` | `sub_4A0D80`, `DialogSession::DialogSession` | `DialogSession::DialogSession()` | Base construction, vtable stores, list allocation, active index sentinel, full-screen Pane bounds. |
| `0x004a0e70` | `sub_4A0E70`, destructor | `DialogSession::~DialogSession()` | Restores vtables, releases all dialog entries, frees list, releases dimmer if present, tears down Pane. |
| `0x004a0f40` | `CloseAllDialogs` | `CloseAllDialogs()` | If active index is valid, slide-closes current dialog; closes all tracked dialogs; destroys list; marks pane for deletion. |
| `0x004a0fc0` | `PushDialog` | `PushDialog(DialogInSession *dialog)` | Removes entries above current index, deactivates previous active dialog, inserts new dialog, increments active index, lays out/opens/animates first dialog. Reject generated `RankingDialog *`. |
| `0x004a10e0` | `PopCurrentDialog` | `PopCurrentDialog(bool shouldAnimate)` | Closes active dialog, removes it, decrements active index, reactivates previous dialog or tears down session if empty. Binary uses the low byte of a stack parameter compared to `1`; `bool` is the best source-facing role, `char` remains the ABI observation. |
| `0x004a11e0` | `FUN_004a11e0` | `ActivateNextDialog(bool shouldAnimate)` | Hides/slides current, increments `m_activeDialogIndex`, shows/slides next. No insertion/removal, so `Push`/`Pop` names are wrong. No direct callers found; keep private/protected. |
| `0x004a1250` | `FindPreviousDialog` | `FindPreviousDialog(DialogInSession *dialog)` | Searches list for target and returns previous dialog or null if target is first/missing. |
| `0x004a1360` | `sub_4A1360`, `ReleaseSharedSessionResource` in generated output | `ReleaseScreenDimmer()` or `DestroyScreenDimmer()` free helper | No `this`, reads only `g_pScreenDimmer`, calls scalar deleting destructor with flag `1`. It is a ScreenDimmer/global helper, not a class method. |
| `0x004a1380` | `unknown_libname_11` | `IsScreenDimmerActive()` or `HasScreenDimmer()` free helper | Bytes are `cmp dword ptr [0x0069ae08], 0; setnz al; retn`; 24 direct calls pair it with `ReleaseScreenDimmer`. Treat as source/global helper, not runtime. |
| `0x004a1390` | `GetDialogAtIndex` | `GetDialogAtIndex(int index)` | Calls list accessor at `+0x10` and returns the dereferenced `DialogInSession *`. |
| `0x004a13b0` | `FUN_004a13b0` | `FindDialogIndex(DialogInSession *dialog)` | Searches list and returns matching index or `-1`. No direct callers found; keep private/protected. |
| `0x004a1485`, `0x004a1490` | `virt_meth_*`, adjustor thunks | no source method | `sub ecx, 0xa0/0xa4; jmp 0x004a1500`; compiler-generated. |
| `0x004a1500` | scalar deleting destructor | no handwritten method body in class declaration | Compiler wrapper from virtual destructor declaration; do not emit as ordinary source unless the project has a wrapper policy. |

## Caller And Reachability Evidence

Raw PE `E8 rel32` scan of `.text` in `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found these direct call counts:

| Target | Direct calls | Call sites |
| --- | ---: | --- |
| `0x004a0d80` constructor | 1 | `0x00471186` |
| `0x004a0f40` `CloseAllDialogs` | 5 | `0x00472886`, `0x00473e5a`, `0x004765db`, `0x0047a0b3`, `0x0047c6ee` |
| `0x004a0fc0` `PushDialog` | 15 | `0x00471384`, `0x00471453`, `0x00471613`, `0x00471629`, `0x004716aa`, `0x00471805`, `0x00471934`, `0x004719f6`, `0x00471b89`, `0x00471b9c`, `0x00471d59`, `0x00471d6c`, `0x00471e66`, `0x00471f80`, `0x00471f93` |
| `0x004a10e0` `PopCurrentDialog` | 20 | `0x0047179b`, `0x00471adb`, `0x00471cab`, `0x00471f1a`, `0x00473e7e`, `0x00476466`, `0x00476782`, `0x004771ce`, `0x0047825e`, `0x00479047`, `0x00479107`, `0x0047a134`, `0x0047c556`, `0x0047c666`, `0x0047c8ab`, `0x0047c91c`, `0x0047d83e`, `0x0047e0f7`, `0x0047e490`, `0x0047e820` |
| `0x004a11e0` raw next-dialog helper | 0 | none found |
| `0x004a1250` `FindPreviousDialog` | 10 | `0x004763cc`, `0x00477167`, `0x004781f7`, `0x00478ff6`, `0x004790b6`, `0x0047c4bc`, `0x0047d7d7`, `0x0047e0a6`, `0x0047e43d`, `0x0047e7cd` |
| `0x004a12b0` `CreateScreenDimmer` | 18 direct call instructions | `0x00472985`, `0x00473a81`, `0x00473ba6`, `0x00473cc6`, `0x00473fd0`, `0x004763a6`, `0x00476564`, `0x0047671c`, `0x00477208`, `0x00478298`, `0x00479e09`, `0x00479f26`, `0x0047c496`, `0x0047c654`, `0x0047c87c`, `0x0047d878`, `0x0047e2ce`, `0x0047e67e` |
| `0x004a1360` `ReleaseScreenDimmer` | 24 | `0x0047158a`, `0x0047175b`, `0x00471a9b`, `0x00471c6b`, `0x00471eda`, `0x00474316`, `0x00474387`, `0x00474764`, `0x00474823`, `0x0047692d`, `0x00476a43`, `0x00477261`, `0x0047735d`, `0x004774a3`, `0x004782f1`, `0x004789ad`, `0x00478af3`, `0x0047a425`, `0x0047a7b3`, `0x0047ca5d`, `0x0047cb93`, `0x0047d8d1`, `0x0047da8d`, `0x0047dbc3` |
| `0x004a1380` `IsScreenDimmerActive` | 24 | `0x0047157f`, `0x00471750`, `0x00471a90`, `0x00471c60`, `0x00471ecf`, `0x00474307`, `0x00474378`, `0x00474755`, `0x00474814`, `0x0047691e`, `0x00476a34`, `0x00477252`, `0x0047734e`, `0x00477494`, `0x004782e2`, `0x0047899e`, `0x00478ae4`, `0x0047a416`, `0x0047a7a4`, `0x0047ca4e`, `0x0047cb84`, `0x0047d8c2`, `0x0047da7e`, `0x0047dbb4` |
| `0x004a1390` `GetDialogAtIndex` | 6 | `0x00471788`, `0x00471ac8`, `0x00471af0`, `0x00471c98`, `0x00471cc0`, `0x00471f07` |
| `0x004a13b0` raw index helper | 0 | none found |
| `0x004a1400` `DialogInSession` constructor | 9 | `0x00472012`, `0x004720c8`, `0x00472cf8`, `0x00475445`, `0x00476c51`, `0x004777e9`, `0x00479168`, `0x0047b282`, `0x0047d09c` |
| `0x004a1450` `DialogInSession` destructor | 5 | `0x0047e956`, `0x0047e996`, `0x0047ea16`, `0x0047ebf6`, `0x0047ec36` |
| `0x004a1500` `DialogSession` scalar deleting destructor | 0 ordinary direct calls | vtable/thunk target only |

This supports:

- `DialogSession` source ownership for stack/list helpers because callers are broad board/article/mail/session flows and all the helpers operate on `+0xf8/+0xfc`.
- `BulletinSession` and Board/Mail dialog pages as callers/consumers, not owners of the stack helpers.
- `0x004a11e0` and `0x004a13b0` as real source-shaped dormant/private helpers, not current externally reached APIs.
- `0x004a1360` and `0x004a1380` as paired ScreenDimmer global helpers called by many feature handlers before opening alerts/requests, not class methods.

Example listing context for the predicate/release pair:

```asm
0047157F  call    unknown_libname_11
00471584  test    al, al
00471586  jz      short loc_47158F
00471588  mov     ecx, esi
0047158A  call    sub_4A1360
```

The `ecx` load before `sub_4A1360` is dead for `sub_4A1360` itself; the callee ignores `this` and reads `g_pScreenDimmer` directly. This is further evidence against class-method ownership.

Bytes for `0x004a1380`:

```asm
83 3d 08 ae 69 00 00 0f 95 c0 c3
```

That is `cmp dword ptr [0x0069ae08], 0; setnz al; retn`. It is not a generic CRT runtime helper.

## Generated Output Reanalysis

There are two different generated-output states to keep distinct:

1. `source-3/simroot_v2/class_DialogSession.cpp` is the recovered Wave3 active view. It currently emits constructor/destructor/scalar destructor and several helper bodies:
   - `CloseAllDialogs`
   - `PushDialog`
   - `PopCurrentDialog`
   - `FindPreviousDialog`
   - `GetDialogAtIndex`
2. `project-documentation/auto-generated/NexusTK/ui/dialogs/DialogSession.cpp` is the validator autogen output from by-* docs. It currently emits only empty markers because every attached doc page has blank `RECONSTRUCTION_CPP`.

The target page's older claim that active generated output omitted central helper bodies is now stale for `simroot_v2`, but still effectively true for docs autogen. The wording should be updated to avoid confusing the two.

Current `simroot_v2` pollution to reject:

- `RankingDialog *` in `PushDialog`, `PopCurrentDialog`, `FindPreviousDialog`, and `GetDialogAtIndex` is caller/feature pollution. Shared stack entries should be `DialogInSession *`.
- `ChattingColorPane::CloseDialog` in close/pop paths is helper-name pollution. The real callee is the shared `DialogPane` close/teardown helper at `0x0049dad0`, not chat ownership.
- `m_activeIndex` is shorter generated naming. Use `m_activeDialogIndex` from B001/current layout docs because it describes the `DialogSession` field and avoids collision with unrelated index fields.
- `ReleaseSharedSessionResource` is too vague for `0x004a1360`. The body releases `g_pScreenDimmer`; if a name is needed, use `ReleaseScreenDimmer` or `DestroyScreenDimmer`.
- Modern constructs such as `auto`, `std::uint8_t`, `nullptr`, synthetic layout overlays, `reinterpret_cast`, and direct `operator_delete(this)` artifacts are generated output style problems, not source-quality models for this codebase.
- The active recovered view does not include `0x004a11e0` or `0x004a13b0`, so the current recovered method inventory is incomplete.

Metadata sync:

- Current `class_DialogSession.meta_wave3` reports `vtable_count: 3` and three vtable ranges for `DialogSession`.
- Current `class_DialogInSession.meta_wave3` reports `vtable_count: 3` and three vtable ranges for `DialogInSession`.
- Target/support docs that still say current Wave3 metadata reports `vtable_count: 0` should be updated as stale.

## ScreenDimmer Boundary Decision

Keep these outside `DialogSession` class:

- `0x004a12b0-0x004a1360`: `ScreenDimmer *CreateScreenDimmer(void)`, already [UID:000133], owner [UID:0000NA] `ScreenDimmer`.
- `0x004a1360-0x004a1371`: `ReleaseScreenDimmer()` / `DestroyScreenDimmer()`, a free helper over `g_pScreenDimmer`.
- `0x004a1380-0x004a138b`: `IsScreenDimmerActive()` / `HasScreenDimmer()`, a free predicate helper over `g_pScreenDimmer`.

Recommended source placement:

- Strongest ownership for `CreateScreenDimmer`, `ReleaseScreenDimmer`, and `IsScreenDimmerActive` is the ScreenDimmer/global source family because the functions construct, test, or destroy `g_pScreenDimmer`.
- If the supervisor wants to preserve physical address-island grouping in [UID:000131], the DialogSession aggregate can still list them as physical neighbor/dependency helpers. It should not describe them as `DialogSession` methods.
- Create exact child pages for `0x004a1360` and `0x004a1380` if ScreenDimmer helper emission is desired. Without those pages, update [UID:000131] to say they are ScreenDimmer/global helper dependencies inside the physical island.

Rejected alternatives:

- Reject `DialogSession::ReleaseSharedSessionResource()` as a class method: no `this` state is read.
- Reject `runtime/library predicate` for `0x004a1380`: raw bytes and 24 direct calls prove it is a shared global predicate used by project code.
- Reject `CreateScreenDimmer` ownership under `DialogSession`: no stack/list fields or session class state are used.
- Reject MapPane/ScreenPane ownership for the factory/release/predicate helpers: map/screen panes are parent choices or consumers, not lifecycle owners.

## Heuristic / Inference Reanalysis And Validation

### Compiler/Generated Names

`sub_4A0D80`, `sub_4A0E70`, `sub_4A0F40`, `sub_4A0FC0`, `sub_4A10E0`, `sub_4A1250`, `sub_4A1390`, and `sub_4A1500` are generated binary labels. The best source-facing names are derived from field use, caller behavior, and generated source hints where they agree with the binary:

- `DialogSession::DialogSession`
- `DialogSession::~DialogSession`
- `DialogSession::CloseAllDialogs`
- `DialogSession::PushDialog`
- `DialogSession::PopCurrentDialog`
- `DialogSession::FindPreviousDialog`
- `DialogSession::GetDialogAtIndex`
- scalar deleting destructor as compiler-generated wrapper, not handwritten source

`FUN_004a11e0` and `FUN_004a13b0` are prewave/Ghidra raw function names. They are not padding because both have coherent frame setup, list access, and returns, and prewave exports model exact sizes. The best supported names are:

- `ActivateNextDialog(bool shouldAnimate)` for `0x004a11e0`
- `FindDialogIndex(DialogInSession *dialog)` for `0x004a13b0`

The names remain inferred because no caller or original symbol proves spelling. The evidence supports the roles strongly enough that they should not remain unresolved `FUN_*` in target/support docs.

`unknown_libname_11` at `0x004a1380` is a misleading IDA/library-style label. The raw body and broad direct callers prove a project helper role. Use `IsScreenDimmerActive()` or `HasScreenDimmer()` as source-facing name if promoted.

`RankingDialog *` is rejected for `DialogSession` stack entries. It comes from recovered caller/context pollution. All source-family docs say the shared stack is used by board/article/mail/session dialog subclasses of `DialogInSession`.

`ChattingColorPane::CloseDialog` is rejected for the close helper callee. The call target is shared dialog close/teardown behavior, not chat ownership.

### Field And Type Inferences

`m_dialogList` at `+0xf8` is strong. Constructor writes a newly allocated 20-byte list initialized with `(4, 16)`. Every helper uses it as a list object. The count lives at list `+0x0c`, accessor is vtable slot `+0x10`, insertion is `+0x18`, erase range is `+0x1c`, and deleting destructor is vtable slot `0`.

The element payload type is `DialogInSession *`. Accessor calls return a pointer to a 4-byte slot; helpers dereference `[slot]` to get the dialog pointer. Use `List *` in declaration-level C++ because exact original list class/template spelling is not proven.

`m_activeDialogIndex` at `+0xfc` is strong. Constructor writes `0xff`; helpers compare against `0xff`, sign-extend it for list lookup, decrement/increment the byte, and use signed-byte branching to detect empty/negative states. Source-facing type should be `unsigned char` or `signed char`; choose `unsigned char` with explicit `0xff` sentinel in docs because the stored sentinel is byte-valued and existing docs already use `0xff`.

`DialogInSession +0x26c` and `+0x270` are support fields, not `DialogSession` fields. The best names remain `m_dialogType` and `m_session`/`m_sessionData`. The source-facing constructor role is `DialogInSession(DialogSession *session, int dialogPaneConfigId, unsigned char dialogType)`.

### Ownership And Source Placement

`DialogSession` belongs under [UID:0000IU] `DialogSession.cpp`. The direct evidence is:

- constructor called from `BulletinSession` at `0x00471186`
- stack helpers have broad board/article/mail/session callers
- helpers operate on `DialogSession +0xf8/+0xfc`
- by-file, by-class, layout, vtable, and vtable-data pages all point to `DialogSession.cpp`
- proposed source tree places `DialogSession.cpp` under `NexusTK/ui/dialogs/`

`DialogInSession` remains in the same source file. It shares the physical island, vtable-data cluster, and source-module hypothesis. Splitting it into a separate file is not supported by current evidence.

`BulletinSession`, BoardDialogs, MailDialogs, and alert pages are callers/consumers. They should not own the shared stack helpers even when their call sites dominate the fanout.

`ScreenDimmer` owns the factory and singleton lifecycle helpers. `DialogSession` depends on those helpers but does not own their class declarations or global storage.

### Caller And Reachability

Direct call counts support the split:

- `PushDialog` has 15 direct calls, concentrated in BulletinSession packet/dialog dispatch.
- `PopCurrentDialog` has 20 direct calls across board/article/mail/alert/session handlers.
- `FindPreviousDialog` has 10 direct calls across article/mail/predefined/alert flows.
- `GetDialogAtIndex` has 6 direct calls in BulletinSession core.
- `CloseAllDialogs` has 5 direct calls across board/article/mail/session cleanup paths.
- `0x004a11e0` and `0x004a13b0` have 0 direct `E8` callers, so treat as raw/dormant/private helpers but not as padding.
- `ReleaseScreenDimmer` and `IsScreenDimmerActive` each have 24 direct calls and appear as a pair in feature handlers before alert/request transitions.

### Split And Range Decisions

Keep `0x004a0d80-0x004a15f8` as the physical aggregate. Do not widen or shrink the target class to exclude `DialogInSession` in memory docs; the class page should instead explain that `DialogSession` and `DialogInSession` share the island.

Keep [UID:000132] non-emitting. It is a historical overlapping index and still not a clean source unit.

Create exact children later if method-body emission is desired:

- `0x004a0f40-0x004a0fbc.DialogSessionCloseAllDialogs.md`
- `0x004a0fc0-0x004a10d1.DialogSessionPushDialog.md`
- `0x004a10e0-0x004a11dc.DialogSessionPopCurrentDialog.md`
- `0x004a11e0-0x004a124e.DialogSessionActivateNextDialog.md`
- `0x004a1250-0x004a12a2.DialogSessionFindPreviousDialog.md`
- `0x004a1390-0x004a13a7.DialogSessionGetDialogAtIndex.md`
- `0x004a13b0-0x004a13f2.DialogSessionFindDialogIndex.md`

Create ScreenDimmer helper children later if global helper emission is desired:

- `0x004a1360-0x004a1371.ReleaseScreenDimmer.md`
- `0x004a1380-0x004a138b.IsScreenDimmerActive.md`

### C++ Readiness

`DialogSession` is eligible for declaration-level class C++ after this report is incorporated. It should not emit method bodies from the class page. The class page should emit:

- forward declarations for `List` and `DialogInSession`
- `class DialogSession : public Pane`
- constructor and virtual destructor declarations
- stack helper declarations
- private declarations for no-direct-call helper pockets
- `m_dialogList` and `m_activeDialogIndex`
- `[[CHILDREN]]`

Reasons not to emit method bodies from [UID:00003U]:

- exact helper child pages do not yet exist for the two newly surfaced raw helpers;
- current generated method bodies contain type/name pollution;
- `ReleaseScreenDimmer` and `IsScreenDimmerActive` need ScreenDimmer/global child placement, not class placement;
- scalar deleting destructor and adjustor thunks are compiler-generated products of the class declaration/destructor.

## Rejected Alternatives

- `BulletinSession` owns the stack helpers: rejected. `BulletinSession` calls them, but the helpers operate on `DialogSession +0xf8/+0xfc` and are reached from board/article/mail/alert flows.
- `BoardDialogs` owns the stack helpers: rejected. Board/article dialogs consume the stack; the list/index state is in `DialogSession`.
- `RankingDialog *` is the stack entry type: rejected. It is generated/caller pollution. Use `DialogInSession *`.
- `0x004a11e0` and `0x004a13b0` can be ignored because they have no direct callers: rejected. They are coherent executable helper bodies inside the DialogSession helper cluster; document as dormant/private/no-route source-shaped helpers.
- `0x004a1380` is runtime/library code: rejected by byte scan and 24 direct callers. It is a project helper that tests `g_pScreenDimmer`.
- `ReleaseSharedSessionResource` is a final source name: rejected. The body is specifically `g_pScreenDimmer` deletion. Use `ReleaseScreenDimmer` or `DestroyScreenDimmer` if named.
- `CreateScreenDimmer` should move to DialogSession because of physical address proximity: rejected. The body constructs a `ScreenDimmer` and should remain [UID:0000NA] ScreenDimmer-owned.
- Split `DialogInSession` into a separate source file: rejected. Current file, layout, vtable, vtable-data, and address-island evidence supports one `DialogSession.cpp` source root for both classes.

## Open Question Closure

| Question | Closure |
| --- | --- |
| Should source name be `m_activeIndex` or `m_activeDialogIndex`? | Use `m_activeDialogIndex`. Generated `m_activeIndex` is shorter but less specific; B001/current layout docs and field role support `m_activeDialogIndex`. |
| Is `m_dialogList` a template list? | Do not commit template spelling. Use `List *`; document element payload as `DialogInSession *`. |
| Are `0x004a11e0` and `0x004a13b0` real methods? | Yes as source-shaped helpers; no direct callers found, so keep private/protected and exact-source-name inferred. |
| Is `0x004a1380` runtime/library? | No for source-quality purposes. It is a tiny project helper predicate over `g_pScreenDimmer` with 24 direct calls. |
| Should `0x004a1360` be a DialogSession method? | No. It reads `g_pScreenDimmer`, ignores `this`, and calls the object's deleting destructor. Treat as ScreenDimmer/global helper. |
| Can class C++ be emitted now? | Yes for declaration shell after report incorporation and target score update. No method bodies from the class page. |
| Should [UID:000132] emit C++? | No. It remains a mixed historical split/index. Exact helper leaves can emit if split later. |
| Should scalar deleting destructor and adjustor thunks be in handwritten C++? | No. They are compiler-generated from class declaration/destructor/vtable layout. |
| Does current docs autogen already contain DialogSession C++? | No. Validator autogen output is empty markers only. |
| Does current simroot contain helper code? | Partly yes, but with source-quality pollution and missing `0x004a11e0`/`0x004a13b0`. Treat as lead evidence only. |

## Proposed Score And Metadata

For [UID:00003U] target:

```text
COMPLETION:90
CONFIDENCE:90
CANONICAL_OWNER:0000IU
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IU
```

Rationale:

- Completion reaches `90` after adding the missing helper pockets, updated generated-output state, final field/type recommendations, ScreenDimmer boundary decision, vtable thunk policy, source-placement decision, first-draft class C++ shell, and support sync checklist.
- Confidence reaches `90` because class identity, fields, vtables, constructor/destructor, helper behavior, and caller distribution are strongly corroborated by local listing, raw PE call scan, prewave exports, target/support docs, and validator baseline.
- Do not go above `90` yet. Exact original helper spellings, access specifiers, list class spelling, and the proposed child split pages are still not final-audit complete.

Support recommendations:

- [UID:0000IU] `by-file/DialogSession.md`: keep owner/file route; update stale generated-output and vtable metadata wording; consider `88/90` after sync.
- [UID:000131] `DialogSessionCore`: update inventory for `0x004a11e0`, `0x004a13b0`, and ScreenDimmer predicate/release classification; consider `88/90`.
- [UID:000132] `DialogSessionStackHelperIndex`: keep non-emitting; update "five helpers" to "seven source-shaped helpers"; keep or raise conservatively after exact text update.
- [UID:0001U5] layout: update if class declaration/field names are accepted; no major score change required.
- [UID:0001XD] vtables: already strong; no major change except stale parent/gate notes if encountered.
- [UID:0002NB] vtable-data: update stale assignment-gate paragraph and stale score references; current coverage row still says `84%` while page says `86/90`.
- [UID:0000NA]/[UID:0000S5]/[UID:00029D] ScreenDimmer global support: add `0x004a1360` and `0x004a1380` as release/predicate helper candidates or create exact child pages if supervisor accepts the split.

## Exact Coverage Row Text

Current target row in `by-class/-coverage-report.md`:

```text
- [UID:00003U][DialogSession](by-class/DialogSession.md) : reconstructable : 85% : strong : Assigned to [UID:0000IU][DialogSession](by-file/DialogSession.md) after child 85/86 and direct file parent 86/86 cleared the corrected 85/85 gate; Pane-derived session container with `+0xf8/+0xfc` tracked-list/active-index state, constructor/destructor/stack-helper inventory, exact memory/type/vtable support pages, generated omission caveats, and ScreenDimmer split preserved.
```

Recommended replacement target row:

```text
- [UID:00003U][DialogSession](by-class/DialogSession.md) : reconstructable : 90% : very strong : B002 2026-06-19 source-quality reanalysis resolves the Pane-derived dialog stack owner under [UID:0000IU][DialogSession](by-file/DialogSession.md): declaration-level class C++ with `[[CHILDREN]]` is ready; `m_dialogList` at `+0xf8` is a `List *` whose payload is `DialogInSession *`, `m_activeDialogIndex` at `+0xfc` is a byte/signed-sentinel stack index, reached helpers are `CloseAllDialogs`, `PushDialog`, `PopCurrentDialog`, `FindPreviousDialog`, and `GetDialogAtIndex`, raw no-direct-call helper pockets are `ActivateNextDialog` at `0x004a11e0` and `FindDialogIndex` at `0x004a13b0`, `CreateScreenDimmer`/`ReleaseScreenDimmer`/`IsScreenDimmerActive` are ScreenDimmer/global helpers rather than class methods, adjustor/deleting thunks are compiler-generated, and current generated `RankingDialog*`/`ChattingColorPane` names are rejected as source-quality pollution while docs autogen still emits only empty markers.
```

Optional support row update for `by-file/-coverage-report.md` if the file page is synchronized:

Current file row:

```text
- [UID:0000IU][DialogSession](by-file/DialogSession.md) : reconstructable : 86% : strong : Dialog session infrastructure source root now clears the corrected parent gate for DialogSession/DialogInSession class children; exact support includes DialogSessionCore 86/88, DialogSessionVtableData 86/90, layout/vtable type pages, session/dialog base grouping, stack/list helper inventory, screen-dimmer exclusion, generated-output omissions, and `NexusTK/ui/dialogs/` path evidence.
```

Suggested replacement file row:

```text
- [UID:0000IU][DialogSession](by-file/DialogSession.md) : reconstructable : 88% : strong : Dialog session infrastructure source root for `DialogSession` and `DialogInSession` under `NexusTK/ui/dialogs/`; B002 2026-06-19 reanalysis preserves file ownership while correcting the helper inventory to include raw no-direct-call `0x004a11e0`/`0x004a13b0`, rejects generated `RankingDialog*`/`ChattingColorPane` pollution, updates current vtable metadata caveats, keeps ScreenDimmer factory/release/predicate helpers outside the DialogSession class, and leaves method bodies to exact by-memory children while class pages may emit declaration-level shells with `[[CHILDREN]]`.
```

Do not edit `by-memory/-coverage-report.md` in a class-only callback. If [UID:000131]/[UID:000132] or new exact helper children are edited later, then add separate supervisor-approved by-memory row changes.

## Target Implementation Checklist

For `by-class/DialogSession.md` only, if accepted:

- Update metadata to `COMPLETION:90`, `CONFIDENCE:90`, retaining `CANONICAL_OWNER:0000IU`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IU`.
- Add declaration-level `RECONSTRUCTION_CPP` class shell with `[[CHILDREN]]`.
- Update method table to include `0x004a11e0-0x004a124e` and `0x004a13b0-0x004a13f2`.
- Change `m_activeIndex`/raw `+0xfc` wording to `m_activeDialogIndex`.
- Document `m_dialogList` as `List *` with `DialogInSession *` payload.
- State that `PushDialog`, `PopCurrentDialog`, `FindPreviousDialog`, `GetDialogAtIndex`, `ActivateNextDialog`, and `FindDialogIndex` use `DialogInSession *`, not `RankingDialog *`.
- State that `ReleaseScreenDimmer` and `IsScreenDimmerActive` are not class methods.
- Update generated-output notes to distinguish `simroot_v2` recovered output from validator docs autogen.
- Replace the target coverage row in `by-class/-coverage-report.md` if callback scope allows class coverage edits.
- Run scoped validator for `by-class/DialogSession.md`.

## Support Implementation Checklist

Support sync recommended for a later callback:

- `by-file/DialogSession.md`
  - Add `0x004a11e0` and `0x004a13b0` to proposed contents/evidence.
  - Update stale active-generated-output wording.
  - Update stale `vtable_count: 0` notes to current `vtable_count: 3`.
  - Keep `NexusTK/ui/dialogs/` placement.

- `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md`
  - Add `0x004a11e0-0x004a124e` and `0x004a13b0-0x004a13f2`.
  - Reclassify `0x004a1380` from runtime/library to a `g_pScreenDimmer` predicate helper or state the prior IDA library mark is overridden by raw call evidence.
  - Reword `0x004a1360` as a ScreenDimmer/global release helper, not a `DialogSession` method.
  - Keep aggregate reconstructable and owner [UID:0000IU] unless exact helper children split ownership differently.

- `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`
  - Keep non-emitting.
  - Replace "five source-bearing helpers" with "seven source-shaped helpers", separating reached helpers from no-direct-call helpers.
  - Keep ScreenDimmer and DialogInSession exclusions.

- `by-type/by-struct/DialogSessionLayouts.md`
  - Keep `m_dialogList` and `m_activeDialogIndex`.
  - Optionally mention `0x004a11e0` and `0x004a13b0` as additional field users.

- `by-type/by-vtable/DialogSessionVtables.md`
  - No major behavioral change; ensure current metadata caveats do not claim vtable count is still zero.

- `by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md`
  - Update stale assignment-gate paragraph that still cites old file/class scores.
  - Align coverage row with page score if by-memory coverage edits are in scope.

- ScreenDimmer/global support
  - Add or split exact docs for `0x004a1360-0x004a1371.ReleaseScreenDimmer` and `0x004a1380-0x004a138b.IsScreenDimmerActive`.
  - Update pages that mention `unknown_libname_11` as unresolved when they use this helper.
  - Keep [UID:000133] factory boundary `0x004a12b0-0x004a1360` unchanged.

- Generated reports/autogen
  - After accepted edits, rerun scoped validator on modified docs.
  - Verify `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp` gains only the declaration shell and child markers expected from the class page, not polluted simroot method bodies.

## Validator Baseline Result

Command:

_Executable command block removed from the research report; preserved in [00003U-DialogSession-class-source-quality-removed.md](00003U-DialogSession-class-source-quality-removed.md)._

Result:

- Exit code: `0`
- `ok: 1`
- Dry run only
- Target UID header exists
- Autogen registry rebuilt
- `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp` unchanged
- The generated DialogSession output currently remains empty emitter markers because the target/support pages have blank `RECONSTRUCTION_CPP`

No by-* docs and no coverage reports were edited during this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00003U-DialogSession-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00003U"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00003U-DialogSession-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00003U-DialogSession-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00003U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

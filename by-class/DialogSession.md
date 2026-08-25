*** UID:00003U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class List;
class DialogInSession;

class DialogSession : public Pane
{
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

protected:
    List *m_dialogList;
    unsigned char m_activeDialogIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogSession

## Status

- Confidence: very strong for core behavior, direct file-root ownership, tracked-list/index fields, helper inventory, complete declaration-level class shape, and compiler-vtable route; medium-high for exact original private-helper spellings and the custom list class spelling.
- Likely source file: [UID:0000IU][DialogSession](by-file/DialogSession.md)
- Address range: [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- Current recovered file: `source-3/simroot_v2/class_DialogSession.cpp`; treat it as lead evidence only because it still carries source-quality pollution such as `RankingDialog*` helper types.
- Type docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Vtables: [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), exact data [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)
- Direct autogen parent: [UID:0000IU][DialogSession](by-file/DialogSession.md)
- Source access correction: `m_dialogList` and `m_activeDialogIndex` are protected. Current derived `BulletinSession` source accesses inherited `m_activeDialogIndex`; the historical private placement was source-incompatible without evidence for an unobserved getter/friend route.

## Class Purpose

`DialogSession` is a full-screen `Pane`-derived session container for session-bound dialogs. It owns `m_dialogList` at `+0xf8`, keeps `m_activeDialogIndex` at `+0xfc`, pushes new dialogs onto the stack, closes or removes active dialogs, and releases session renderer state during teardown.

See [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) for the IDA-confirmed `m_dialogList` tracked-list pointer and `m_activeDialogIndex` byte.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `DialogSession` | `0x004a0d80-0x004a0e6e` | Constructs the base `Pane`, creates the tracked dialog list, initializes active index to `0xff`, applies full-screen bounds, and attaches renderer state. |
| `~DialogSession` | `0x004a0e70-0x004a0f3c` | Releases tracked entries/list, shared session resource, pane state, and base object. |
| close all / teardown stack | `0x004a0f40-0x004a0fbc` | Closes active dialog if present, releases all tracked dialogs, frees the list, and invalidates pane/session state. |
| push dialog | `0x004a0fc0-0x004a10d1` | Removes dialogs above the active index, inserts a new dialog, applies bounds/parenting, and shows/activates it. |
| pop/close current dialog | `0x004a10e0-0x004a11dc` | Removes current dialog, optionally restores prior dialog state, and tears down the session when the stack becomes empty. |
| activate next dialog | `0x004a11e0-0x004a124e` | Raw/prewave-exported source-shaped helper best named `ActivateNextDialog(bool shouldAnimate)`: hides or slides the current dialog, increments `m_activeDialogIndex`, and shows or slides the next dialog. No direct callers found, so keep it private/protected and mark the exact spelling inferred. |
| previous dialog lookup | `0x004a1250-0x004a12a2` | Finds a dialog in the tracked list and returns its previous entry when one exists. |
| screen dimmer factory dependency | [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) | Shared `CreateScreenDimmer_4A12B0` helper used by session/dialog callers; source owner is [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md). |
| screen dimmer release helper | `0x004a1360-0x004a1371` | `ReleaseScreenDimmer()` / `DestroyScreenDimmer()` free helper over [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md); it ignores `this` and is not a `DialogSession` method. |
| screen dimmer active predicate | `0x004a1380-0x004a138b` | `IsScreenDimmerActive()` / `HasScreenDimmer()` project helper over `g_pScreenDimmer`; the old `unknown_libname_11` runtime/library label is rejected because raw bytes and 24 direct callers prove a source helper. |
| list entry accessor | `0x004a1390-0x004a13a7` | Returns a tracked dialog list entry by index. |
| find dialog index | `0x004a13b0-0x004a13f2` | Raw/prewave-exported source-shaped helper best named `FindDialogIndex(DialogInSession *dialog)`: searches `m_dialogList` and returns the matching index or `-1`. No direct callers found, so keep it private/protected and mark the exact spelling inferred. |
| destructor thunks | `0x004a1485`, `0x004a1490`, `0x004a1500` | Secondary/tertiary adjustor thunks and scalar deleting destructor. |

## Source Layout

| Offset | Source-facing field | Type direction | Evidence |
| --- | --- | --- | --- |
| `+0x00` | primary vptr | compiler-generated | Constructor stores `0x00618d30`; destructor paths reinstall it. |
| `+0x04-+0xf7` | inherited `Pane` state | `Pane` base | Constructor calls the `Pane` constructor with mode `4`, applies full-screen bounds, and attaches renderer state. |
| `+0xa0` | secondary/event vptr | compiler-generated | Constructor stores `0x00618d7c`; secondary thunk subtracts `0xa0`. |
| `+0xa4` | tertiary/event vptr | compiler-generated | Constructor stores `0x00618dac`; tertiary thunk subtracts `0xa4`. |
| `+0xf8` | `m_dialogList` | `List *`, payload slots hold `DialogInSession *` | Constructor allocates a 20-byte list object as `List(4, 16)` and all stack helpers use list count/accessor/insert/erase/delete slots. |
| `+0xfc` | `m_activeDialogIndex` | `unsigned char` sentinel, `0xff` means no active dialog | Constructor writes `0xff`; helpers sign-extend, increment, decrement, compare against `0xff`, and use signed empty-stack branches. |

- Use `List *m_dialogList` in declaration-level C++ rather than committing a template spelling. A typed `List<DialogInSession *>` is behaviorally correct, but the binary proves a custom 4-byte-payload list, not the original source template spelling.
- Use `DialogInSession *` for stack entries and helper parameters/returns. Generated `RankingDialog *` names are caller/type pollution from feature dialogs and are rejected as source-quality declarations.
- Use `bool shouldAnimate` for the pop/activate helper role. The ABI observes a low byte of a stack parameter compared to `1`; `bool` is the best source-facing role while `char` remains the binary-level caveat.
- Do not place `CreateScreenDimmer`, `ReleaseScreenDimmer`, or `IsScreenDimmerActive` inside the `DialogSession` class. The factory is [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)-owned, and the release/predicate helpers operate only on [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md).

## Vtable Evidence

| View | Vtable | Key slots |
| --- | --- | --- |
| primary | `0x00618d30` | Scalar deleting destructor `0x004a1500` at `+0x00`; pane bounds/interaction slots at `+0x30` and `+0x3c`. |
| secondary | `0x00618d7c` | Adjustor thunk `0x004a1485` at `+0x00`, shared pane/event slots through `+0x28`. |
| tertiary | `0x00618dac` | Adjustor thunk `0x004a1490` at `+0x00`, base event slot `0x00544e90` at `+0x04`. |

The constructor stores these vtables at `0x004a0dc1`, `0x004a0dc7`, and `0x004a0dd1`. The non-deleting destructor and scalar deleting destructor reinstall the same three vtables before cleanup.

The exact compiler-data child begins at the primary COL pointer `0x00618d2c`. Its primary table has 18 slots, its EventHandler facet has 11, and its TimerHandler facet has two. The source class remains directly `Pane`-derived; EventHandler and TimerHandler at `+0xa0/+0xa4` are inherited facets, not additional direct bases.

The scalar deleting destructor and `this-0xa0`/`this-0xa4` adjustor entries are compiler-generated from this class's ordinary virtual destructor and layout. They must not appear as handwritten methods, explicit vptr stores, deletion flags, or adjustor arithmetic.

## Supporting Exact Evidence

- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) records the exact constructor/destructor/stack-helper island, including `+0xf8/+0xfc` list/index state, stack push/pop/close helpers, resource-release helper, runtime-helper caveat, and ScreenDimmer factory ownership split.
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) records `DialogSession` as a `Pane`-derived session container with tracked-list pointer at `+0xf8` and active stack index byte at `+0xfc`.
- [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) records the three `DialogSession` vtable bases, constructor/destructor store xrefs, adjustor thunks, and boundary before `DialogInSession` / `DIBitmap` data.

## Evidence Notes

- IDA MCP confirms all listed function starts.
- Current validator-owned docs autogen emitted only empty markers before this pass because the class page had blank `RECONSTRUCTION_CPP`. The recovered `simroot_v2/class_DialogSession.cpp` does include several helper bodies, but it misses `0x004a11e0`/`0x004a13b0` and carries polluted type/name guesses, so it remains a lead, not final source.
- 2026-06-17 B001 source-quality recheck found that active simroot helper bodies are useful scaffolding but not final source: generated `RankingDialog*` tracked-entry typing is feature/caller pollution, and exact helper leaves should prefer `DialogInSession*` with `m_dialogList`/`m_activeDialogIndex`.
- `xrefs_to 0x004a0d80` shows construction from the bulletin session constructor at `0x00471186`.
- `xrefs_to 0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, and `0x004a1250` shows broad bulletin/session-family callers. `0x004a12b0` also has those callers, but it is a shared [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) factory dependency rather than `DialogSession` implementation.
- Disabled generated output lists `0x004a1485` as missing code, but IDA confirms it is a real `0xb` thunk forwarding to `0x004a1500` with `this - 0xa0`.
- Current `class_DialogSession.meta_wave3` and `class_DialogInSession.meta_wave3` report three vtables; older notes saying `vtable_count: 0` are stale and should not be used to block the vtable/class route.
- B002 2026-06-19 raw PE `E8 rel32` scan found direct caller counts that support ownership and reachability: constructor `1`, `CloseAllDialogs` `5`, `PushDialog` `15`, `PopCurrentDialog` `20`, `ActivateNextDialog` `0`, `FindPreviousDialog` `10`, `CreateScreenDimmer` `18` direct call instructions, `ReleaseScreenDimmer` `24`, `IsScreenDimmerActive` `24`, `GetDialogAtIndex` `6`, `FindDialogIndex` `0`, `DialogInSession` constructor `9`, and `DialogInSession` destructor `5`.

## DeleteReplyAlert Consumer Relationship

[UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) is an exact current consumer of two existing source declarations:

- `FindPreviousDialog(currentDialog)` resolves the [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) immediately preceding the current [UID:00000J][ArticleDialog](by-class/ArticleDialog.md).
- `PopCurrentDialog(false)` removes the current article dialog after the prior list has been reconciled and refreshed.

The pop occurs in the single-reply branch even when `FindArticleById` returns `-1`; it does not occur in multi mode. This call pattern confirms the existing source-facing method names and bool argument without changing DialogSession ownership, formal declaration, helper visibility, or stack-field typing.

## Assignment Gate

This source class is `92/93`, owned and emitted by [UID:0000IU][DialogSession](by-file/DialogSession.md). It is the direct human-source declaration for the Pane-derived session container, while UID000131 is a non-emitting physical index and UID0002NB/UID0001XD are non-emitting compiler-data/type authorities.

## Score Rationale

- Completion is `92` because the page records the complete class declaration, helper union, reached/no-route helper distinction, protected source-compatible state, exact layout, DialogInSession pointer typing, ScreenDimmer exclusions, compiler-vtable route, and no-handwritten-wrapper policy.
- Confidence is `93` because class identity, direct Pane inheritance, fields, vtables, constructors/destructors, helper behavior, callers, and derived access are independently corroborated. The cap preserves uncertainty only in original private-helper and list-class spellings.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `92/93` and the complete class formal; cross-linked exact DeleteReplyAlert use of `FindPreviousDialog(currentDialog)` and `PopCurrentDialog(false)`, including branch and ordering constraints.
- 2026-07-16 B004 UID0002NB accepted implementation callback:
  - Changed `90/90 -> 92/93` while preserving owner/emitter UID0000IU, reconstructable true, blank position, every existing method/helper declaration, and `[[CHILDREN]]`.
  - Applied the accepted complete formal by inserting `protected:` before `m_dialogList` and `m_activeDialogIndex`; no method, field, or unrelated class content was removed.
  - Added the exact 18/11/2 compiler-table route, inherited `+0xa0/+0xa4` facet explanation, renamed UID0002NB support, ordinary-destructor cause, and deleting-wrapper/adjustor no-source proof.
- 2026-06-07 A003 Batch 084 class parent-gate update:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID:0000IU`.
  - Summary/evidence: added supporting exact evidence, assignment gate, and score rationale. Assignment to [UID:0000IU][DialogSession](by-file/DialogSession.md) is justified because the child is `85/86`, the direct file parent is `86/86`, and [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) documents the exact constructor/destructor/stack-helper island with the ScreenDimmer split preserved.
- 2026-06-17 B001 stack-index execution:
  - Score unchanged at `85/86`.
  - Clarified stack field names as `m_dialogList` and `m_activeDialogIndex`, and recorded that [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) is now non-emitting because the historical range is mixed and duplicates [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md).
- 2026-06-20 B002 Rule 26 incorporation:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:90`.
  - Summary/evidence: incorporated B002's class source-quality report, populated declaration-level class C++, added missing raw helper pockets `ActivateNextDialog` (`0x004a11e0-0x004a124e`) and `FindDialogIndex` (`0x004a13b0-0x004a13f2`), corrected `DialogInSession *` stack-entry types, recorded `m_dialogList`/`m_activeDialogIndex` field roles, rejected generated `RankingDialog*` and `ChattingColorPane` pollution, moved `ReleaseScreenDimmer`/`IsScreenDimmerActive` out of the class, and replaced stale generated-output/vtable-count caveats.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/84`.
  - Summary/evidence: session container role, tracked-list layout, constructor/destructor/stack management helpers, vtable stores, screen-dimmer dependency split, caller evidence, and generated omission caveats are documented; remaining uncertainty is final source-folder placement and some helper names.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the session constructor/destructor/helper island and vtable stores as NexusTK-owned dialog infrastructure. Parent/code autogen remains blank because helper names and final source declarations are not fully audited.

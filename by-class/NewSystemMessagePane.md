*** UID:00009C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class NewSystemMessageModifyHeightPane;
class SpelledPane;
class SystemMessagePane;

class NewSystemMessagePane : public PanelPane
{
public:
    NewSystemMessagePane();
    virtual ~NewSystemMessagePane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnActivate(const unsigned char *packet);
    virtual void OnPaint();

    void RefreshSpelledPane();
    void StopSpelledPaneRefresh();

private:
    SpelledPane *m_spelledPane;
    SystemMessagePane *m_systemMessagePane;
    NewSystemMessageModifyHeightPane *m_heightPane;
    wchar_t m_spelledText[256];
};

typedef char NewSystemMessagePaneSizeMustBe0x304[
    sizeof(NewSystemMessagePane) == 0x304 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewSystemMessagePane

## Status

- Confidence: very strong for the complete source declaration, exact `0x304` layout, constructor-owned fields, singleton lifecycle, vtable surface, stop/refresh members, and both false-return EventHandler overrides; final private lexical spellings remain the confidence cap.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewSystemMessagePane.cpp`; constructor currently appears in `class_NewSystemMessageModifyHeightPane.cpp`
- Exact vtable data: [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md)
- Parent range disposition: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is a non-emitting executable split index. This class page, not the broad parent, carries the `NewSystemMessagePane` constructor/destructor/rebuild/paint/source-placement evidence.

## Class Purpose

`NewSystemMessagePane` is the newer system-message panel wrapper. It manages child message panes, rebuilds the scrollable message pane when the available row count changes, refreshes a child world-map pane, and draws an EPF/tile-backed panel background.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00588560-0x00588797` | `NewSystemMessagePane::NewSystemMessagePane()` | Constructs panel wrapper, stores [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md), creates height handle, `SpelledPane`, and child `SystemMessagePane`. At `0x00588720`, it passes the embedded `SpelledPane` at `this+0xf8`, the zeroed 256-wide-character buffer at `this+0x104`, and length zero to [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md). Active generated source emits this in the height-pane file. |
| `0x00588800-0x00588c0c` | `OnActivate(const unsigned char *packetData)`; behavior alias `RebuildMessagePanes` | Primary `+0x48` activation override. The packet argument is unused; the body rebuilds child message panes, clones existing/incoming messages, and scrolls to bottom. `newMessageCount` is rejected because the argument is never read. |
| `0x00588d50-0x00588d6e` | [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md) / `RefreshSpelledPane()` | Exact source wrapper that refreshes the embedded SpelledPane scroll-handler state; one EPF UID0003UN caller. |
| `0x00588d90-0x00588dfb` | `OnPaint()` | Draws the tiled panel background. |
| `0x00588e00-0x00588e15` | Tiny virtual helpers | Two 5-byte helpers listed by Wave3, omitted from current emitted source. |
| `0x0058aab0-0x0058aaba` | singleton clear helper | Clears `g_pNewSystemMessagePane`. Active generated output omits this body. |
| `0x0058ab07-0x0058ab1d` | Adjustor/thunk helpers | Vtable-referenced destructor thunks, omitted from current emitted source. |
| `0x0058ad20-0x0058adab` | `ScalarDeletingDestructor(char flags)` | Destroys child panes, clears `g_pNewSystemMessagePane`, destroys the panel base, and optionally deletes. |

## Evidence Notes

- Wave3 grades the class at effective `97.0`.
- IDA MCP confirms all listed starts as exact functions.
- Older Wave2 notes identify a provisional `RefreshWorldMapPane` method called from the server-entry handler. UID0004R2 supersedes that lexical/receiver interpretation: the wrapper loads `NewSystemMessagePane+0xf8` as SpelledPane and is called by `UserPane::HandleServerEntryPacket`.
- IDA `xrefs_to 0x0069bc10` confirms the singleton writes/clears in constructor, clear helper, and destructor, plus use from [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md).
- 2026-05-25 IDA recheck: the constructor at `0x00588560` is directly called from `GeneralPurposePanel2` construction at `0x004b88ae`; it writes `g_pNewSystemMessagePane`, creates `NewSystemMessageModifyHeightPane`, `SpelledPane`, and child `SystemMessagePane`, and installs `NewSystemMessagePane` vtables.
- Current `simroot_v2/class_NewSystemMessagePane.cpp` still lacks the constructor body, while `class_NewSystemMessageModifyHeightPane.cpp` still emits `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560`; keep this as a generated-file partition issue, not source ownership evidence.
- 2026-06-12 A002 Batch 286 live IDA MCP recheck: [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md) covers only this class, with vtable bases at `0x0062d83c`, `0x0062d88c`, and `0x0062d8bc`; the successor locator at `0x0062d8c4` starts `OldSystemMessagePane`. Store refs land in constructor `0x00588560`, destructor/reset refs at `0x005887a9`/`0x005887af`/`0x005887b9`, and scalar deleting destructor `0x0058ad20`. Disassembly confirms the constructor caller `0x004b88ae`, `g_pNewSystemMessagePane` writes/clears at `0x0069bc10`, nested `NewSystemMessageModifyHeightPane` construction, child pane cleanup, and delete size `0x304` / 772 decimal (Verified with `int_convert.py`).
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync: parent reclassification does not move constructor ownership. `0x00588560` remains `NewSystemMessagePane::NewSystemMessagePane`, directly called from `0x004b88ae`; it publishes `0x0069bc10`, constructs nested `NewSystemMessageModifyHeightPane`, creates `SpelledPane`, constructs child `SystemMessagePane`, and installs this class's vtables. The current generated placement in `class_NewSystemMessageModifyHeightPane.cpp` is still a generated mispartition, not evidence against this class owner.
- 2026-07-13 B004 UID00015Y callback resolves `0x00588800` as the class's primary `+0x48` implementation of the common `OnActivate(const unsigned char *packetData)` contract. The argument is not read, so `newMessageCount` is not a valid parameter meaning. `RebuildMessagePanes` remains a useful behavior alias for the exact body rather than the shared virtual declaration name.
- 2026-07-13 Agent-B001 UID000284 callback resolves the constructor's SpelledPane initialization call. The direct call at `0x00588720` uses the embedded child at `this+0xf8`, the constructor-zeroed 256-wide-character buffer at `this+0x104`, and length `0`. [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) therefore clears the child's entry vector, terminates on empty input without inserting a record, and rebuilds empty display text.
- The constructor call is dependency evidence only. Parser owner/emitter routing remains with [UID:0000DK][SpelledPane](by-class/SpelledPane.md), and [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) remains a function-local parser declaration. It does not become a `NewSystemMessagePane` field or global. This bounded correction does not resolve the class's broader declaration-shell blockers, so score, metadata, and existing formal no-code comment remain unchanged.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md)
- [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md)
- [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md)
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md)

## B011 Declaration-Shell Audit

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` keeps this class source-owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) but resolves the empty emitter with a formal no-code comment. The audit checked constructor `0x00588560-0x00588797`, `RebuildMessagePanes` `0x00588800-0x00588c0c`, the then-provisional refresh wrapper `0x00588d50-0x00588d6e`, `OnPaint` `0x00588d90-0x00588dfb`, tiny virtual helpers `0x00588e00-0x00588e15`, clear helper `0x0058aab0-0x0058aaba`, thunks `0x0058ab07-0x0058ab1d`, scalar deleting destructor `0x0058ad20-0x0058adab`, exact vtable child [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md), global [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md), and direct caller `0x004b88ae`.

The constructor publishes `g_pNewSystemMessagePane`, constructs nested `NewSystemMessageModifyHeightPane` of `0x114` / 276 bytes (Verified with `int_convert.py`), creates `SpelledPane`, constructs child `SystemMessagePane`, and installs three vtable views. The destructor clears the singleton and conditionally deletes storage of `0x304` / 772 bytes (Verified with `int_convert.py`). [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md) proves vtable views at `0x0062d83c`, `0x0062d88c`, and `0x0062d8bc`, with constructor/destructor/scalar-delete refs and successor `OldSystemMessagePane` boundary. A declaration shell would encode member order, child ownership fields, and inherited virtual interface before the new-pane wrapper layout is stable; `[[CHILDREN]]` alone would not import the constructor/body facts.

## UID0004R2 RefreshSpelledPane Source Closure

- [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md) is the exact `void NewSystemMessagePane::RefreshSpelledPane()` child. It is `89/92`, owner UID00009C, emitter UID0000OE, reconstructable true, blank optional position, and `Nested:0`.
- Exact range is 30 bytes and exact SHA256 is `38BE83D274E61C5A74872233AE56A79F2FD40085C3D3BD430602384D735AEEF4`. It loads the embedded SpelledPane at `this+0xf8` and applies the accepted FrameHandler remove-then-schedule operation represented by `m_spelledPane->RefreshScrollState()`.
- Its only direct call is `0x005aace9` in the EPF branch of [UID:0003UN][0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket](by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md), after GeneralPurposePanel2 child index zero is resolved as NewSystemMessagePane. The legacy branch has no NewSystem refresh.
- `RefreshWorldMapPane` is rejected as stale naming: the wrapper has no MapPane field, receiver, global, call, or state effect. SpelledPane and FrameHandler are dependencies, not owners.
- UID0004R2 carries its complete formal method body. This class page deliberately keeps the existing formal no-code shell comment because the broader class declaration/member/vtable shell remains incomplete; adding one exact child does not justify a duplicate class definition or score increase.
- Class score remains `85/86`; all constructor, singleton, vtable, OnActivate, OnPaint, tiny-helper, destructor, partition, and unrelated family evidence remains unchanged.

## Changes

- 2026-07-15 B004 UID0003UN callback: linked real child UID0004R2, replaced only the stale refresh method-map/name/prose, and added exact hash/field/one-caller/FrameHandler/source/negative evidence while preserving `85/86` and the bounded formal no-code shell.

- 2026-07-13 Agent-B001 UID000284 callback support sync:
  - What existed before: constructor evidence stopped at generic SpelledPane creation and did not record the initial parser call.
  - Changed to: documented exact call site `0x00588720`, child offset `this+0xf8`, zeroed 256-wide-character buffer offset `this+0x104`, zero length, empty-input behavior, and non-owning relation to UID0004N5/UID000284. Scores, owner/emitter metadata, and the existing declaration-shell formal comment remain unchanged.
  - Evidence: accepted UID000284 report and live IDA MCP session `supervisor_nexustk_20260713` caller/disassembly/decompilation reads.

- 2026-07-13 B004 UID00015Y accepted callback: scores remain `85/86`; relabeled `0x00588800` as the common pointer-valued `OnActivate` override with an unused packet argument, retained `RebuildMessagePanes` as its behavior alias, explicitly rejected `newMessageCount`, and preserved the existing declaration-shell no-code proof and all unrelated class evidence.
- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for constructor `0x00588560`, caller `0x004b88ae`, nested height pane, `SpelledPane`, child `SystemMessagePane`, [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md), singleton lifecycle, `0x114`/`0x304` sizes, and the rejected layout shell.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync:
  - Reconfirmed constructor ownership for `0x00588560`, direct caller `0x004b88ae`, `g_pNewSystemMessagePane` publication at `0x0069bc10`, nested height-pane construction, `SpelledPane` creation, child `SystemMessagePane` construction, and generated mispartition into `class_NewSystemMessageModifyHeightPane.cpp`.
  - Recorded that [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is now a non-emitting split index, so no aggregate parent C++ should be introduced for this constructor family.
- Before: completion/confidence metadata were `0/0` while the page already documented class role, constructor partition issue, child-pane rebuild behavior, singleton evidence, and destructor support.
- Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
- Evidence: the page contains IDA-backed function starts, constructor caller evidence, singleton xrefs, method roles, and generated-file caveats; remaining gaps are the tiny virtual helper names and final source-file partition correction.
- 2026-06-05: Marked reconstructable and attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) because the class is `82/82` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x00588560`, `0x00588800`, `0x00588d50`, `0x00588d90`, `0x00588e00`, `0x0058aab0`, `0x0058ab07`, and `0x0058ad20`; current `callers` confirms the constructor reference at `0x004b88ae`.
- 2026-06-12 A002 Batch 286 split/parent-gate repair:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: created exact vtable child [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md); live IDA MCP reconfirmed the three class vtable bases, constructor/destructor/scalar-delete refs, `GeneralPurposePanel2` constructor caller, `g_pNewSystemMessagePane` lifecycle, nested child construction, and `OldSystemMessagePane` successor boundary. This clears the direct-parent gate for the exact vtable child while final C++ remains blank.

## B001 UID0003TY Complete Declaration Synchronization - 2026-07-20

- The former comment-only shell is superseded by one complete managed `NewSystemMessagePane : public PanelPane` declaration. Constructor allocation, member initialization, destructor cleanup, vtable bases, and the delete-size operand prove exact `sizeof(NewSystemMessagePane) == 0x304`.
- Exact fields are `SpelledPane *m_spelledPane` at `+0xf8`, `SystemMessagePane *m_systemMessagePane`, `NewSystemMessageModifyHeightPane *m_heightPane`, and `wchar_t m_spelledText[256]`. The constructor and existing parser call jointly prove member order and the 256-wide text capacity; no raw padding or speculative ownership field is introduced.
- [UID:0004TU][0x00588d70-0x00588d81.NewSystemMessagePaneStopSpelledPaneRefresh](by-memory/0x00588d70-0x00588d81.NewSystemMessagePaneStopSpelledPaneRefresh.md) adds `void StopSpelledPaneRefresh()` beside retained [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md). Stop only forwards the child to stop behavior; refresh retains its independent remove-and-schedule policy.
- Secondary EventHandler vtable slots prove [UID:0004TV][0x00588e00-0x00588e05.NewSystemMessagePaneHandleKeyOrTextEvent](by-memory/0x00588e00-0x00588e05.NewSystemMessagePaneHandleKeyOrTextEvent.md) and [UID:0004TW][0x00588e10-0x00588e15.NewSystemMessagePaneHandlePointerOrMouseEvent](by-memory/0x00588e10-0x00588e15.NewSystemMessagePaneHandlePointerOrMouseEvent.md) are source virtual overrides taking `Event *` and returning false. Their direct `xor eax,eax; retn 4` bodies are not adjustors, thunks, or one shared implementation.
- UID0003TY is the sole caller of the stop helper. Its MapPane ownership does not move any NewSystem member or body; SystemMessagePane, SpelledPane, the height pane, and the source file retain their established roles.
- Current score is `92/94`, owner remains UID0000OE, emitter remains UID0000OE, reconstructable remains true, and blank position remains unchanged. Every constructor, OnActivate, OnPaint, destructor, singleton, vtable, parser, and unrelated family fact is preserved.
- Historical claims that the class declaration, member order, tiny virtual names, or source form remained unresolved are superseded. Compiler vptr setup, destructor thunks, scalar-delete flags, and base teardown remain excluded from handwritten class source.

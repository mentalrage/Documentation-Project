*** UID:0000DK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SpelledPane.h"
#include <stddef.h>
#include <wchar.h>
#include "../../localization/LanguageMan.h"

extern bool g_useEpfAssets;
bool IsLegacyAssetMode();

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_PANELS_SPELLEDPANE_H
#define NEXUSTK_UI_PANELS_SPELLEDPANE_H

#include <vector>
#include "../../util/StringBase.h"
#include "../core/FrameMgr.h"
#include "../controls/TextEditPane.h"

class Event;
struct FrameUpdateContext;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > WideString;

struct SpelledPaneEntry
{
    WideString text;
    int value;
    int group;
};

class SpelledPane : public TextEditPane, public FrameHandler
{
public:
    SpelledPane();
    SpelledPane(int viewportWidth,
                int viewportHeight,
                int textAreaWidth,
                int textAreaHeight);
    virtual ~SpelledPane()
    {
    }

    void DeleteLine(short lineIndex);
    void AddOrUpdateEntry(const wchar_t *text, int value, int group);
    void RemoveEntry(const wchar_t *text, int group);
    void ParseAndLoadEntries(const wchar_t *text, int length);

    void RefreshScrollState()
    {
        RemoveFrame();
        ScheduleNextFrame();
    }

protected:
    virtual bool OnMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnFrameUpdate(const FrameUpdateContext *context);

private:
    void RebuildDisplayText();

    std::vector<SpelledPaneEntry> m_entries;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpelledPane

## Status

- Confidence: very strong for class identity, ten-method island, multiple-inheritance layout, 12-byte entry records, caller/vtable routes, and source placement; source-facing lexical names are best-evidence reconstructions where symbols were lost.
- Likely source file: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- Address range: [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- Current recovered file: `source-3/simroot_v2/class_SpelledPane.cpp`
- Rebuild handling: source-authored class declaration and methods, with vtables regenerated from the declaration and the parser's function-local mutable delimiter array emitted only by [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md).
- Autogen parent: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), now `93/93`; this class is `94/94`, so the strict direct-parent gate is satisfied.
- Final C++ behavior/source-shape draft: complete for the ten methods and class layout. Independent compilation remains pending application and validation of the documented TextEditPane/base, StringBase, GrafPort, LanguageMan, IsLegacyAssetMode, and explicit standard-declaration include route; no PCH or umbrella header is assumed.
- C134 compile repair: the guarded class declaration remains complete, but its H channel no longer emits `[[CHILDREN]]`; all ten method bodies are source-channel children and no child contributes a header declaration. This removes command20473's invalid `[[No Children Attached]]` token without moving method bodies into the class header or changing the established CPP attachment order.

## Class Purpose

`SpelledPane` is a shared child text pane used by self-look/status views and at least one system-message pane. It is constructed with a `TextEditPane`-style base, owns a timed/grouped entry list, rebuilds display text, rejects unsupported query paths, and schedules refresh behavior.

## Ownership And Layout Evidence

| Evidence | Meaning |
| --- | --- |
| [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) | Constructor/method aggregate for the class, now documenting boundaries, entry helpers, parser dependencies, vtable/delimiter links, and parent caveats. |
| [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) | Reviewed source-file parent under `NexusTK/ui/panels/`, with generated `SelfSaveOKPane` ownership pollution called out. |
| [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) | Exact RTTI plus four `SpelledPane` vtable views and constructor/destructor-neighborhood store xrefs. |
| [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) | Parser-owned UTF-16 `" \t"` delimiter used only by the serialized-entry parser. |
| [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) | Exact source-emitting parser child. It owns the delimiter declaration, clears and repopulates the entry vector, and preserves the original uninitialized third record scalar. |
| [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md) | Entry-vector insert helper callers at `0x0056bdbc` and `0x0056c26d` tie vector support directly back to SpelledPane entry storage. |
| [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) | Holds the scalar deleting destructor and vector erase/copy helpers in a mixed look/group/spelled support island. |

The class should remain a reusable child-pane class rather than being folded into `SelfSaveOKPane`, `SelfLookPane`, or `SystemMessagePanes`. Those consumers construct or drive it, while the entry list, parser delimiter, vtable views, and vector helper callers identify a distinct `SpelledPane` owner.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0056bb20-0x0056bbdb` | Constructs the child text pane with resolution-dependent layout. |
| `AddOrUpdateEntry` provisional | `0x0056bca0-0x0056be16` | Adds or updates grouped text/value entries and rebuilds display text. Current generated owner is `SelfSaveOKPane`, but caller evidence points here. B006's [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) recheck confirms this is the nonzero value callee reached from `SelfLookPane` via the embedded `SpelledPane` child. |
| `RemoveEntry` provisional | `0x0056be20-0x0056be9f` | Removes a matching grouped entry and rebuilds display text. B006's [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) recheck confirms this is the zero/absent value callee reached from `SelfLookPane` via the embedded `SpelledPane` child. |
| `RebuildDisplayText` provisional | `0x0056bea0-0x0056c0d7` | Formats grouped entries into the embedded text pane, using localized format string id `222` for valued rows. |
| [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) | `0x0056c0e0-0x0056c2db` | Clears the entry vector, reads one line at a time, splits at the last whitespace delimiter, appends a text/value record while intentionally leaving its third scalar uninitialized, and rebuilds display text. |
| [UID:000078][LineIterator](by-class/LineIterator.md) file-private helper | `0x004f3020`, `0x00573240`, `0x00573540`, `0x00624780-0x00624788` | Complete 16-byte stack line reader emitted through this class's source file: inline constructor, explicit inline empty virtual destructor, out-of-line UID000190, live EH-only UID0001HL body, compiler UID0001HO wrapper, and exact RTTI/vtable support. It remains a distinct class owner rather than a SpelledPane member overlay. |
| `IsQuerySupported` | `0x0056c2e0-0x0056c2e5` | Always-false virtual gate. |
| `IsAlternateQuerySupported` | `0x0056c2f0-0x0056c2f5` | Always-false alternate virtual gate. |
| `UpdateEntriesAndScheduleRefresh` | `0x0056c300-0x0056c3f1` | Updates entry text and schedules refresh. |
| entry-vector helpers | [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md), `0x00573880-0x005738fc`, `0x00573900-0x00573962` | Internal vector insert/erase helpers for entry records; not source-facing behavior. The insert helper is split from [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md); copy/erase remain in [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |
| scalar deleting destructor | [UID:00039G][0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor](by-memory/0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor.md) | Exact scalar deleting destructor child assigned here after the Batch 247 parent-gate recheck; the broad mixed island remains only aggregate context. |

## Evidence Notes

- Wave3 reports `SpelledPane` grade `97.5`.
- IDA confirms constructor xrefs from `SelfLookPane`, `SelfLookPane2`, and a system-message/new-system-message constructor.
- IDA caller checks on 2026-05-24 show the entry-list helpers currently emitted under `SelfSaveOKPane` are reached from self-look and system-message SpelledPane paths.
- B006's 2026-06-25 source-quality pass revalidated the `SelfLookPane` consumer route: [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) reads a packet text field and optional value, loads the embedded `SpelledPane` child from `SelfLookPane` offset `this+0xfc`, calls `0x0056be20` on zero/absent value, and calls `0x0056bca0` on nonzero value. The inline event-handler case at `0x00569747-0x005697b2` duplicates the same add/update-or-remove dispatch through the handler's adjusted child pointer. This strengthens the provisional `AddOrUpdateEntry` and `RemoveEntry` roles without finalizing original method spelling or class layout.
- `SpelledPane::UpdateEntriesAndScheduleRefresh` uses a subobject adjustment before calling the same rebuild helper, matching a frame-handler/timer facet inside SpelledPane rather than a separate SelfSave pane.
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) now emits target-specific first-draft `LineIterator::ReadNextLine` C++ through [UID:000078][LineIterator](by-class/LineIterator.md). Treat it as a class-owned helper called only from this local text parser context, not as a transfer of direct ownership to `SpelledPane`.
- [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) confirms four `SpelledPane` vtable views and store xrefs, including the extra callback/facet view.
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) confirms the parser delimiter bytes and four parser-only refs inside `0x0056c0e0-0x0056c2db`.
- [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) resolves the parser body at source quality. [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) passes the TAB-to-LF-normalized copied `wchar_t[256]` member buffer and its measured length, while the `NewSystemMessagePane` constructor passes an empty buffer and zero length. Both are consumers; this class retains parser/delimiter/vector ownership. The method first clears the vector, constructs a `LineIterator`, and processes lines until the current line is empty.
- The parser uses a function-local mutable `static wchar_t delimiters[] = L" \t"`. A line with no delimiter is skipped. Otherwise `FindLastOf` chooses the last delimiter and `FindLastNotOf` trims the text side; `SubstringWide` forms the text and numeric substrings, and `ToLong` supplies the signed value.
- The stack entry has text, value, and a third scalar. The body initializes text and value but performs no write to the third scalar before the vector insertion at `0x0056c26d`; reconstruction must preserve that indeterminate source behavior instead of inventing a default group/category value. Temporary strings and the line iterator are destroyed on normal and EH paths, and the vector helper owns capacity growth and record copying rather than source-authored parser logic.
- Empty input, an empty first line, and the first empty line after valid records terminate parsing before another append. An all-delimiter line reaches the delimiter branch with a zero-length text prefix; it is not evidence for a separate record format. There is no second parser or alternate delimiter owner in the recovered address/caller/data-xref set.
- 2026-06-11 Agent-A001 live IDA MCP recheck reconfirmed the constructor/add/remove/rebuild/parser/gate/refresh function sizes, caller sets from self-look and system-message users, vtable data refs, and the split vector-insert helper [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md) as SpelledPane-only by callers at `0x0056bdbc` and `0x0056c26d`.

## Reconstruction Notes

- Recreate this as a source-level class under the [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) source family unless a future file-split audit proves it was a local class in a larger look/status module.
- Regenerate vtables from the class declaration; do not hand-port [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) bytes.
- Emit the delimiter exactly once as `static wchar_t delimiters[] = L" \t"` inside [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md). UID000284 is the covered data target and must not emit a second global or class-static object.
- Emit the class declaration from this page and compose all source methods through `[[CHILDREN]]`. Exact bodies remain confined to UID0004YO-UID0004YW and parser UID0004N5.
- The final 32-bit layout is `TextEditPane` at `+0x000` through `+0x173`, `FrameHandler` at `+0x174`, and the vector triplet at `+0x178/+0x17c/+0x180`; complete size is `0x184`. Each `SpelledPaneEntry` is `0x0c` bytes (`WideString`, value, group).
- Source-facing helper/member spellings are inferred from stable class context and project conventions; raw `sub_` labels are intentionally excluded from formal source.
- UID000190's first-draft `LineIterator::ReadNextLine` body is now handled on the LineIterator target page. This strengthens the parser dependency documentation but does not finalize the broader `SpelledPane` class body.

## Score Rationale

- Completion is `94` because the class now has an exact ten-method child inventory, complete declaration/formal source, multiple-inheritance/vector layout, caller routes, data ownership, and compiler-artifact dispositions.
- Confidence is `94` because instruction boundaries, base size, four vtable views, field offsets, record width, callers, and source route agree. Lost original lexical spellings prevent a higher claim, but no raw compiler/decompiler name remains in formal source.

## 2026-07-29 B001 UID0001HA Class Completion

- Exact source children are [UID:0004YO][0x0056bb20-0x0056bbdb.SpelledPaneConstructor](by-memory/0x0056bb20-0x0056bbdb.SpelledPaneConstructor.md), [UID:0004YP][0x0056bbe0-0x0056bc6f.SpelledPaneConstructorWithDimensions](by-memory/0x0056bbe0-0x0056bc6f.SpelledPaneConstructorWithDimensions.md), [UID:0004YQ][0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine](by-memory/0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine.md), [UID:0004YR][0x0056bca0-0x0056be17.SpelledPaneAddOrUpdateEntry](by-memory/0x0056bca0-0x0056be17.SpelledPaneAddOrUpdateEntry.md), [UID:0004YS][0x0056be20-0x0056bea0.SpelledPaneRemoveEntry](by-memory/0x0056be20-0x0056bea0.SpelledPaneRemoveEntry.md), [UID:0004YT][0x0056bea0-0x0056c0d8.SpelledPaneRebuildDisplayText](by-memory/0x0056bea0-0x0056c0d8.SpelledPaneRebuildDisplayText.md), parser [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md), [UID:0004YU][0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent](by-memory/0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent.md), [UID:0004YV][0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent](by-memory/0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent.md), and [UID:0004YW][0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate](by-memory/0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate.md).
- The inline virtual destructor is the source construct that regenerates scalar deleting destructor UID00039G. `std::vector<SpelledPaneEntry>` regenerates UID00039O/UID00039I; the inheritance declaration regenerates UID00038O/UID0002UZ. None requires handwritten compiler machinery.
- The historical blank-formal statements above were valid before the UID0001HA split/layout pass and are superseded by the current formal channels; their supporting evidence remains preserved.

## Cross-References

- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md)
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md)
- [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:00039G][0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor](by-memory/0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-14 Agent-B003 UID0003QZ bounded support sync: corrected the parser caller title from historical `SelfLookPane2::OnDraw` to exact `SelfLookPane2::OnActivate` and recorded the fixed-buffer/TAB-to-LF consumer contract. Score, owner/emitter, class body, parser ownership, delimiter disposition, and unrelated evidence remain unchanged.

- 2026-07-15 Agent-B003 UID0001HL bounded helper sync:
  - What existed before: this class correctly identified LineIterator as the parser helper but retained the unresolved declaration/standalone route inherited from UID000190's earlier pass.
  - Changed to: record the complete UID000078 source declaration and SpelledPane file route, exact inline virtual-destructor source cause, EH-only UID0001HL relation, compiler-only UID0001HO relation, exact 16-byte fields, and deterministic helper child order.
  - Preserved: `87/86`, owner/emitter UID0000NZ, blank SpelledPane formal, parser/delimiter/vector ownership, all broader declaration blockers, and every unrelated method/layout/vtable/history fact.

- 2026-07-13 Agent-B001 UID000284 callback support sync:
  - What existed before: the class page listed the parser only as a provisional aggregate method and described delimiter regeneration broadly, without the resolved line parsing, vector insertion, caller, lifetime, or record-initialization behavior.
  - Changed to: linked exact source-emitting parser child UID0004N5, assigned the function-local mutable delimiter declaration to that child, documented both direct call contexts, the clear/read/split/convert/append/rebuild sequence, temporary lifetimes, vector-helper boundary, and the original uninitialized third record scalar. The class score, ownership metadata, and blank formal class C++ remain unchanged because the broader declaration/layout audit is still incomplete.
  - Evidence: accepted UID000284 report C284-001 through C284-046 and live IDA MCP session `supervisor_nexustk_20260713`, including parser disassembly/decompilation, data xrefs, caller reads, and vector insertion call at `0x0056c26d`.

- 2026-07-07 Agent-B011 UID000190 support sync:
  - What existed before: the LineIterator helper row and evidence note still described UID000190 as not emitted as an active `LineIterator` method.
  - Changed to: recorded UID000190's target-specific first-draft `LineIterator::ReadNextLine` C++ and class-owner route, while preserving SpelledPane as the parser-local caller context and keeping this class formal C++ blank.
  - Evidence: accepted B011 UID000190 report and callback, with MCP session `43ccf853` proof for the two parser callers, stack-object setup, inferred LineIterator field names, `InitializeWideFromRange`, and vtable/destructor support.

## 2026-07-15 LineIterator Helper Dependency

- UID000078 is a separate file-private helper class emitted through UID0000NZ before qualified method definitions. It is not folded into the SpelledPane object layout. Historical checkpoint effect: this dependency alone did not change the then-`87/86` score, blank formal C++, or unresolved declaration state; the later UID0001HA split/layout pass independently resolved those class items.
- Parser setup at `0x0056c133-0x0056c146` constructs the exact 16-byte helper: compiler vptr, UTF-16 backing pointer, unsigned length, and zero unsigned offset. UID000190 reads/updates the same fields and has only parser calls at `0x0056c15b` and `0x0056c285`.
- Self-only LineIterator RTTI proves no base class. Its sole vtable slot is compiler scalar-deleting wrapper UID0001HO, so human source must explicitly declare the empty virtual destructor. UID0001HL is the retained complete-object body used only by parser EH cleanup, not another source method.
- Parser FuncInfo state zero invokes thunk `[0x00607b5d,0x00607b65)`, which adjusts ECX to the completed stack helper and jumps to UID0001HL. The normal parser path has no destructor call because the inline empty destructor is optimized away.
- UID0001HO is false/non-emitting compiler support. UID0001UY/UID0001XZ are non-emitting layout/vtable inventories. UID00038W contains the exact complete-object locator plus one slot and emits only a covered marker. Address `0x00624788` starts unrelated `LOOKEXT.EPF` string data.
- Source routing uses UID000078 position 10, UID000190 position 20, UID0001HL position 30, and UID00038W position 40. UID0000KQ is retained as a path/owner `NONE` historical family index.
- Preserve the distinction between dependencies: LineIterator evidence did not by itself justify filling the historical blank SpelledPane formal. Current formal H/layout comes from the later exact constructor/method/vtable/offset pass, not from LineIterator ownership.
- Reject handwritten vptr/scalar-delete/operator-delete/RTTI/vtable/EH/cookie mechanics, raw offsets/addresses, duplicate layout structs, and decompiler labels in generated source.
- 2026-06-12 A004 Batch 247: Score unchanged at `87/86`.
  - What changed: updated the scalar deleting destructor method row and cross-reference to exact child [UID:00039G][0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor](by-memory/0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor.md), which is now assigned here after reaching `87/92`.
  - Evidence: live IDA MCP reconfirmed the destructor wrapper boundary, vtable/thunk refs, entry/state cleanup offsets, and `SpelledPane` cleanup/delete calls.
- 2026-06-25 B006 support sync: refreshed `0x0056bca0` and `0x0056be20` consumer evidence from [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) `SelfLookPaneSpelledTextDispatch` and the inline handler case. At that historical checkpoint, scores/metadata stayed unchanged because the declaration and spellings were still provisional; the 2026-07-29 split/layout callback supersedes only that former blocker state.

- 2026-06-11 Agent-A001 Batch 186 continuation: Raised from `86/80` to `87/86`.
  - Before: the class page had strong identity evidence but stale strict-gate text and still referenced the broad mixed helper island for the insert helper.
  - After: updated the parent gate to [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) `87/85`, linked exact child [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md), refreshed the score rationale, and made the class eligible as direct parent for [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md).
  - Evidence: live IDA MCP `lookup_funcs`, `callers`, `xrefs_to`, and `callees` on 2026-06-11, plus the existing exact vtable/delimiter docs.
- 2026-06-07 - A007 class-parent confidence update:
  - Before: the page was `86/78`, reconstructable but unassigned, with method inventory and generated-owner caveats but no class-level vtable/delimiter dependency table or explicit parent-gate rationale.
  - Changed to: `86/80`, attached to [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), added ownership/layout evidence, reconstruction notes, score rationale, and direct cross-links to the exact vtable and parser delimiter pages.
  - Evidence: UID-linked docs already prove the constructor/method aggregate, four `SpelledPane` vtable views, parser-only delimiter refs, vector-helper callers, mixed destructor island, and reviewed file parent. Final C++ remains blank because field/declaration details are still below the final-code gate.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `78`.
- Evidence: the page documents the shared child-pane role, constructor/method/helper/destructor ranges, generated ownership corrections, caller evidence, line-iterator gap, and helper-island cross-references; confidence remains capped by final file ownership and provisional helper names.
- Before: the entry-vector helpers were listed as `0x00572fd0-0x00573231` and `0x00573900-0x00573961`, without covering the adjacent vector copy/cleanup helper at `0x00573880`.
- Changed to: the helper endpoints now follow IDA function ends, and the related insert/copy/erase helpers are cross-referenced through [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) and [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- Evidence: 2026-05-28 IDA MCP shows `sub_572fd0` ends at `0x00573232`, `sub_573880` is called from that insert helper, and `sub_573900` ends at `0x00573962`.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, entry update/remove/rebuild/parse helpers, query gates, refresh helper, and scalar deleting destructor from `0x0056bb20` through `0x00573820`. The likely parent file meets 80/80, but this class confidence is `78`, so the parent UID stays blank.

## 2026-07-29 Supervisor Gate 2B IDA Reconciliation

- Supervisor Gate 2B applied A01-A06/A08-A10 and protected A07 without mutation. The saved authoritative database is session `1da2b2ae`, SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, 143,190,636 bytes, saved `2026-07-29T13:59:50.138-04:00`. Prestate backup: `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B001-UID0001HA-20260729-135636.i64`; supervisor catalog entry: `0361`.
- Applied class methods and exact regular comments:
  - `[0x0056bb20,0x0056bbdb)` `SpelledPane__Constructor`, `SpelledPane *__thiscall(SpelledPane *this)`: SpelledPane default constructor; selects EPF or legacy text-pane dimensions, initializes TextEditPane and FrameHandler bases, installs four SpelledPane vtable views, and default-constructs the entry vector.
  - `[0x0056bbe0,0x0056bc6f)` `SpelledPane__ConstructorWithDimensions`, `SpelledPane *__thiscall(SpelledPane *this, int viewportWidth, int viewportHeight, int textAreaWidth, int textAreaHeight)`: SpelledPane dimensioned constructor; forwards caller dimensions and fixed text-pane flags, initializes FrameHandler, installs four SpelledPane vtable views, and default-constructs the entry vector.
  - `[0x0056bc70,0x0056bc9d)` `SpelledPane__DeleteLine`, `void __thiscall(SpelledPane *this, short lineIndex)`: Deletes one text line after clamping its signed line index and resolving the line's exact text range through TextEditPane helpers.
  - `[0x0056bca0,0x0056be17)` `SpelledPane__AddOrUpdateEntry`, `void __thiscall(SpelledPane *this, const wchar_t *text, int value, int group)`: Updates an existing SpelledPane entry by text/group or appends a new 12-byte entry, rebuilding text and restoring vertical scroll only after insertion.
  - `[0x0056be20,0x0056bea0)` `SpelledPane__RemoveEntry`, `void __thiscall(SpelledPane *this, const wchar_t *text, int group)`: Removes the matching SpelledPane text/group entry, rebuilds display text, and scrolls the vertical pane to the top.
  - `[0x0056bea0,0x0056c0d8)` `SpelledPane__RebuildDisplayText`, `void __thiscall(SpelledPane *this)`: Rebuilds SpelledPane display text in group order, inserts a separator before group one, omits zero-valued rows, and invalidates the pane.
  - A07 remains `[0x0056c0e0,0x0056c2db)` `SpelledPane_ParseAndLoadEntries`, `void __thiscall(struct SpelledPane *this, const wchar_t *text, int length)`, with its existing parser-local writable space/tab delimiter and intentionally uninitialized third local scalar comment unchanged.
  - `[0x0056c2e0,0x0056c2e5)` `SpelledPane__HandleKeyOrTextEvent`, `bool __thiscall(SpelledPane *this, Event *event)`: SpelledPane EventHandler key/text override; intentionally returns false without consuming the event.
  - `[0x0056c2f0,0x0056c2f5)` `SpelledPane__OnMouseEvent`, `bool __thiscall(SpelledPane *this, Event *event)`: SpelledPane mouse-event override; intentionally returns false without consuming the event.
  - `[0x0056c300,0x0056c3f1)` `SpelledPane__OnFrameUpdate`, `bool __thiscall(SpelledPane *this, const FrameUpdateContext *context)`: SpelledPane FrameHandler callback; decrements positive entry lifetimes, removes expired entries, rebuilds text while restoring scroll, and reschedules after 50 frames.
- Gate 2B declared only an incomplete `FrameUpdateContext` analysis type and modeled the A02/A03 raw bodies. Typed disassembly/analysis now shows their exact arguments, while Hex-Rays still fails at dependency calls `0x0056bc15` and `0x0056bc84`; this bounded lifting failure does not weaken the recovered bodies or class declaration.
- Method sizes, incoming xrefs, bytes, all `0xcc` padding spans, four vtable views, parser bytes, literals, and dependent helper prototypes are unchanged. Agent-B001 made no IDA mutation or save.

## 2026-07-29 Shared IDB Currentness Recheck

- `0E0AF938...AB481` is the historical UID0001HA applied/save checkpoint; `03F102...DBE5DA` and earlier are historical. Current authoritative session `1da2b2ae` is `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`.
- Read-only recheck found no class-family drift across the ten exact names/ranges/prototypes/comments, hashes/xrefs/padding, four vtable views, parser data/literal routes, and protected helpers. A02/A03 retain typed analysis and the same bounded Hex-Rays failures only. Agent-B001 did not mutate/save IDA.
- Currentness supersession: `3C8F3178...5B69` is historical. Current authoritative session `1da2b2ae` is `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`; the full class family again matched.
- Currentness supersession: `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B` and every earlier identity are now dated history. Current authoritative session `1da2b2ae` is saved SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, last write `2026-07-29T14:42:53.5091352-04:00`; bounded read-only target/dependency readback again found zero UID0001HA drift across exact names, ranges, prototypes, four comment channels, body hashes, xref counts, padding, callback slots, literals, helper identities, and relevant type state. A02/A03 retain exact typed analysis with the same bounded Hex-Rays failures at `0x0056bc15` and `0x0056bc84`. Agent-B001 did not mutate or save IDA.

## 2026-08-24 B001 UID0000JM Frame Callback Reconciliation

- Preserved `94/94`, owner/emitter UID0000NZ, the complete `0x184` layout, ten-method child route, all unrelated SpelledPane source, and the existing `FrameMgr.h` include.
- Changed only the formal declaration from historical `bool OnFrameUpdate(...)` to the proven `void OnFrameUpdate(const FrameUpdateContext *context)` FrameHandler override. UID0004YW remains the sole CPP body carrier at position `70`.
- The callback walks 12-byte entries backward, decrements positive lifetimes, erases entries that reach zero, keeps negative entries, rebuilds display text while restoring vertical scroll, and performs a standalone `ScheduleFrameCallback(50);`. Dispatcher callers ignore EAX, so the earlier bool/return-scheduler contract is superseded as source while its dated IDA history remains preserved for supervisor reconciliation.
- This ordinary callback changes no class score, layout, vector/helper ownership, parser behavior, vtable bytes, IDA state, or other method declaration.

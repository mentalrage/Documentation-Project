*** UID:0000NZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SpelledPane

## Status

- Confidence: very strong for the `NexusTK/ui/panels/SpelledPane.cpp` route, exact source contents, class declaration, method ordering, and file-private LineIterator dependency.
- Proposed module: `ui/panels/SpelledPane.cpp`; the accepted class/method/vtable/caller evidence now makes this the resolved reconstruction route.
- Current recovered source: `class_SpelledPane.cpp`
- Main address doc: [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)

## File Role

`SpelledPane` is a reusable child text pane used by self-look/status UI and at least one system-message/new-system-message construction path. It wraps `TextEditPane`-style behavior, owns a timed/grouped entry list, rebuilds display text from that list, rejects unsupported query paths through tiny vtable gates, and schedules refresh callbacks.

IDA confirms four `SpelledPane` vtable views at `0x006242c8`, `0x00624340`, `0x00624370`, and `0x0062437c`. The fourth view matches the extra frame-handler-style callback path around `0x0056c300`; keep it as layout evidence until the final declaration is reconstructed.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SpelledPane` constructor | `0x0056bb20-0x0056bbdb` | Constructs the child text pane with resolution-dependent layout and `TextEditPane` base setup. |
| entry add/update helper | `0x0056bca0-0x0056be16` | Inserts or updates grouped `{text,value,category}` style entries, then rebuilds display text. Current generated owner is polluted as `SelfSaveOKPane`. |
| entry remove helper | `0x0056be20-0x0056be9f` | Removes a matching entry and rebuilds display text. Current generated owner is polluted as `SelfSaveOKPane`. |
| display rebuild helper | `0x0056bea0-0x0056c0d7` | Formats grouped entries, inserts a separator between groups, and writes the text into the embedded text pane. |
| [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) | `0x0056c0e0-0x0056c2db` | Source-emitting `SpelledPane::ParseAndLoadEntries`; clears the entry vector, reads lines, splits each accepted line at its last whitespace delimiter, appends text/value records while preserving the original uninitialized third scalar, and rebuilds display text. |
| [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) | `0x0066fe44-0x0066fe4a` | Covered data target for the parser's sole function-local mutable `static wchar_t delimiters[] = L" \t"`; it does not emit a separate file/global object. |
| [UID:000078][LineIterator](by-class/LineIterator.md) file-private helper | `0x004f3020`, `0x00573240`, `0x00573540`, `0x00624780-0x00624788` | Complete 16-byte stack line reader with inline constructor, explicit inline empty virtual destructor, out-of-line UID000190 method, live EH-only UID0001HL body, compiler-only UID0001HO wrapper, and exact RTTI/vtable support. UID0000KQ remains a non-source historical index. |
| `IsQuerySupported` / `IsAlternateQuerySupported` | `0x0056c2e0`, `0x0056c2f0` | Tiny always-false virtual gates. |
| `UpdateEntriesAndScheduleRefresh` | `0x0056c300-0x0056c3f1` | Updates entry text/state and schedules pane refresh behavior. |
| entry-vector insert/erase helpers | [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md), `0x00573880-0x005738fc`, `0x00573900-0x00573962` | Non-source-facing vector machinery used by the entry add/remove/parse helpers; the insert helper is now split from [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md), while copy/erase remain in [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |
| scalar deleting destructor | `0x00573820-0x00573873` | Destructor body in the mixed self-look destructor/thunk island; covered by [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |

## Resolved Source Order

1. File-private [UID:000078][LineIterator](by-class/LineIterator.md) declaration and its existing qualified children.
2. [UID:0000DK][SpelledPane](by-class/SpelledPane.md) declaration with `TextEditPane` and `FrameHandler` bases and `std::vector<SpelledPaneEntry>` storage.
3. [UID:0004YO][0x0056bb20-0x0056bbdb.SpelledPaneConstructor](by-memory/0x0056bb20-0x0056bbdb.SpelledPaneConstructor.md) and [UID:0004YP][0x0056bbe0-0x0056bc6f.SpelledPaneConstructorWithDimensions](by-memory/0x0056bbe0-0x0056bc6f.SpelledPaneConstructorWithDimensions.md).
4. [UID:0004YQ][0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine](by-memory/0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine.md), [UID:0004YR][0x0056bca0-0x0056be17.SpelledPaneAddOrUpdateEntry](by-memory/0x0056bca0-0x0056be17.SpelledPaneAddOrUpdateEntry.md), [UID:0004YS][0x0056be20-0x0056bea0.SpelledPaneRemoveEntry](by-memory/0x0056be20-0x0056bea0.SpelledPaneRemoveEntry.md), and [UID:0004YT][0x0056bea0-0x0056c0d8.SpelledPaneRebuildDisplayText](by-memory/0x0056bea0-0x0056c0d8.SpelledPaneRebuildDisplayText.md).
5. Existing parser [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md), followed by [UID:0004YU][0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent](by-memory/0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent.md), [UID:0004YV][0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent](by-memory/0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent.md), and [UID:0004YW][0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate](by-memory/0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate.md).

The broad [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md), vtables, RTTI, scalar deleting destructor, and vector growth/erase bodies are non-emitting coverage or compiler artifacts. Source writes the class, ordinary methods, local separator/delimiter literals, and vector operations; the compiler regenerates those binary support forms.

## Evidence Notes

- Wave3 reports `SpelledPane` grade `97.5`.
- IDA confirms constructor xrefs from `SelfLookPane::SelfLookPane` at `0x005656cc`, `SelfLookPane2::SelfLookPane2` at `0x0056ff1e`, and a system-message/new-system-message constructor at `0x005886bd`.
- The extra `0x005886bd` xref means `SpelledPane` is shared UI infrastructure, not exclusively self-look-local.
- IDA caller checks on 2026-05-24 show `0x0056bca0`, `0x0056be20`, and `0x0056c0e0` are called by self-look and system-message paths, while `0x0056c300` adjusts from a frame-handler subobject back to the owner before calling the same display rebuild helper. That supports SpelledPane entry-storage ownership over the current generated `SelfSaveOKPane` label.
- 2026-06-11 Agent-A001 live IDA MCP recheck against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed constructor callers at `0x005656cc`, `0x0056ff1e`, and `0x005886bd`, entry add/remove/parser callers from self-look and system-message paths, SpelledPane vtable data refs at `0x00624328`, `0x00624348`, and `0x00624380`, and the entry-vector insert helper callers only from `0x0056bdbc` and `0x0056c26d`.
- `source-3/simroot_v2/class_SelfSaveOKPane.cpp` currently emits the entry helpers and broad text-edit methods under `SelfSaveOKPane`; treat that as generated-data pollution.
- The same generated file constructs a stack [UID:0000KQ][LineIterator](by-file/LineIterator.md) in `ParseAndLoadEntries`. [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) now has target-specific first-draft `LineIterator::ReadNextLine` C++ and class-owner routing through [UID:000078][LineIterator](by-class/LineIterator.md), but IDA confirms it is called only from this parser in the current database. The 16-byte layout is documented as [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), and the one-slot vtable/string boundary is documented as [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md).
- [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) is the exact source body for the parser inventory row. [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) supplies the TAB-to-LF-normalized copied `wchar_t[256]` member buffer and its measured length; the `NewSystemMessagePane` constructor supplies an empty fixed buffer and zero length. Both are consumers; parser/delimiter/vector ownership stays here.
- The parser clears the vector before constructing `LineIterator`, stops on the first empty line, and skips a nonempty line with no delimiter. For an accepted line, `FindLastOf` chooses the last space/tab, `FindLastNotOf` trims the text prefix, `SubstringWide` creates text/value temporaries, and `ToLong` parses the signed numeric suffix. An all-delimiter line remains in this branch with an empty text prefix.
- The stack record's text and value are assigned before insertion, but its third scalar receives no initialization. The file reconstruction must preserve that indeterminate field rather than adding a zero/default value. Vector allocation/copy and temporary/string destruction remain helper/compiler machinery around this source-authored body.
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) has four references, all from this parser, and no independent owner or inbound data route. Emit `static wchar_t delimiters[] = L" \t"` once inside the parser; do not duplicate it as a file-scope or class-static declaration.

## Cross-References

- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md)
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)

## Changes

- 2026-07-29 Agent-B001 UID0001HA split-first callback:
  - Changed `87/85 -> 93/93` after resolving the exact ten-method inventory, 0x184 class layout, 12-byte entry record, file-private LineIterator route, source order, and compiler-artifact boundaries.
  - Registered and linked method children UID0004YO-UID0004YW while preserving parser UID0004N5 and delimiter UID000284.
  - Historical broad/local-class uncertainty is retained below as provenance; current reconstruction uses `NexusTK/ui/panels/SpelledPane.cpp` because the class, caller, vtable, and shared-consumer evidence converges on this file route.

- 2026-07-14 Agent-B003 UID0003QZ bounded support sync: corrected the parser caller title from historical `SelfLookPane2::OnDraw` to exact `SelfLookPane2::OnActivate` and recorded the fixed-buffer/TAB-to-LF consumer contract. Score, path, source ownership, parser body, delimiter disposition, and unrelated file evidence remain unchanged.

- 2026-07-15 Agent-B003 UID0001HL bounded source-route sync:
  - What existed before: LineIterator remained staged through a standalone by-file reconstruction bucket even though this parser was its only construction/call context and the destructor/class emission policy was unresolved.
  - Changed to: route the complete UID000078 file-private helper through this SpelledPane source root at position 10, followed by UID000190 at 20, UID0001HL covered body at 30, and UID00038W covered data at 40. UID0000KQ is retained as path/owner `NONE` historical inventory.
  - Preserved: `87/85`, `NexusTK/ui/panels/`, FILE ownership, all SpelledPane class/parser/vector/delimiter/vtable/caller/history content, and broader file-vs-local-class caveats.

- 2026-07-13 Agent-B001 UID000284 callback support sync:
  - What existed before: the file inventory treated the parser as an unsplit provisional range and did not specify delimiter ownership, line acceptance, caller shapes, record initialization, or vector/source boundaries.
  - Changed to: linked source-emitting parser child UID0004N5 and covered delimiter target UID000284, documented both direct callers and the complete clear/read/split/convert/append/rebuild behavior, preserved the uninitialized third record scalar, and assigned the mutable delimiter array exactly once to parser-local source. File score, path, and unrelated contents remain unchanged.
  - Evidence: accepted UID000284 report C284-001 through C284-046 and live IDA MCP session `supervisor_nexustk_20260713`, including parser decompilation/disassembly, caller reads, data xrefs, and vector insertion at `0x0056c26d`.

- 2026-07-07 Agent-B011 UID000190 support sync:
  - What existed before: the LineIterator helper row and evidence note still described UID000190 as not emitted as an active `LineIterator` method.
  - Changed to: recorded that UID000190 now has target-specific first-draft `LineIterator::ReadNextLine` C++ through [UID:000078][LineIterator](by-class/LineIterator.md), while preserving SpelledPane as the only observed parser source context and not changing file metadata.
  - Evidence: accepted B011 UID000190 report and callback, with MCP session `43ccf853` proof for the two parser callers, stack-object setup, field offsets, StringBase dependency, and class/vtable support.

## 2026-07-15 LineIterator File-Private Helper Route

- The only observed LineIterator construction is the parser stack setup at `0x0056c133-0x0056c146`; the only UID000190 calls are `0x0056c15b` and `0x0056c285` in the same parser. No heap construction, external caller, registration pointer, or independent static state supports another source module.
- Complete UID000078 source declaration now emits here before qualified children. It provides the exact inline two-argument constructor, explicit inline empty virtual destructor required by root/self-only RTTI, private `m_text`/`m_length`/`m_offset` fields, and out-of-line `ReadNextLine` declaration.
- Exact complete object size is 16 bytes: compiler vptr at `+0x00`, UTF-16 pointer at `+0x04`, unsigned length at `+0x08`, and unsigned offset at `+0x0c`. Parser initialization, UID000190 field accesses, and UID0001HO's allocation-release size all agree.
- UID0001HL `[0x00573240,0x00573247)` is live only through parser EH thunk `[0x00607b5d,0x00607b65)` and is covered by the inline source destructor. Parser FuncInfo state zero points to that cleanup after the stack object is complete; the normal path optimizes the empty destructor call away.
- UID0001HO `[0x00573540,0x00573564)` is the non-emitting MSVC scalar-deleting wrapper. UID0001UY/UID0001XZ are non-emitting layout/vtable support. UID00038W `[0x00624780,0x00624788)` is exact source-declared/generated-binary RTTI plus the one deleting-destructor slot and emits only a covered marker.
- The one vtable slot is UID0001HO; UID000190 is nonvirtual; `0x00624788` begins unrelated UTF-16 `LOOKEXT.EPF`. Self-only RTTI proves no base and therefore requires the explicit virtual destructor in the helper declaration.
- Generated source must close the class before all children, emit the helper before UID000190 and parser definitions, and contain no standalone LineIterator source root, duplicate declaration, handwritten vptr/scalar-delete/RTTI/vtable/EH/cookie machinery, raw addresses, or decompiler labels.
- Exact private-header versus source-local spelling remains inferred. That caveat does not alter this best-evidence source route or any broader SpelledPane score/formal decision.
- 2026-06-11 Agent-A001 Batch 186 continuation: Raised from `86/80` to `87/85`.
  - Before: the file page had the correct panel-folder route but confidence stayed below the strict direct-parent gate because final original source-file ownership was treated as unresolved.
  - After: documented the exact split [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md), refreshed live caller/vtable/vector evidence, and accepted this file as the direct reconstruction parent for routing while preserving the final file-vs-local-class caveat.
  - Evidence: live IDA MCP `lookup_funcs`, `callers`, `xrefs_to`, and `callees` on 2026-06-11, plus existing vtable/delimiter/LineIterator pages.
- 2026-06-05: Assigned projected reconstruction folder.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - After: set the folder to `NexusTK/ui/panels/`.
  - Evidence: live IDA MCP lookup confirms the documented `SpelledPane` constructor anchor at `0x0056bb20`; proposed-source-tree places the reusable child text pane in the self-look/status panel family while preserving the documented final split caveat.
- Before: the entry-vector helper summary omitted the `0x00573880` helper and used older end addresses for the insert/erase helpers.
- Changed to: the helper list now follows the IDA-confirmed ranges and links to the new by-memory pages that split the former unknown coverage gaps.
- Evidence: 2026-05-28 IDA MCP disassembly and xref sweep over `0x005729c3-0x005739a0`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers role, proposed contents, vtable/layout anchor, IDA caller evidence, generated-owner pollution, LineIterator dependency, helper-vector correction, and cross-references; confidence remains capped by final original source-file ownership.

## 2026-07-29 Supervisor Gate 2B IDA Reconciliation

- Supervisor Gate 2B applied and read back the file's complete SpelledPane method family. Authoritative IDB session `1da2b2ae` is saved at SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, 143,190,636 bytes, `2026-07-29T13:59:50.138-04:00`; the byte-identical prestate backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B001-UID0001HA-20260729-135636.i64` and the supervisor record is catalog entry `0361`. Agent-B001 did not mutate or save IDA.
- Exact source-facing identities, prototypes, and regular function comments are:
  - `[0x0056bb20,0x0056bbdb)` `SpelledPane__Constructor`, `SpelledPane *__thiscall(SpelledPane *this)`: SpelledPane default constructor; selects EPF or legacy text-pane dimensions, initializes TextEditPane and FrameHandler bases, installs four SpelledPane vtable views, and default-constructs the entry vector.
  - `[0x0056bbe0,0x0056bc6f)` `SpelledPane__ConstructorWithDimensions`, `SpelledPane *__thiscall(SpelledPane *this, int viewportWidth, int viewportHeight, int textAreaWidth, int textAreaHeight)`: SpelledPane dimensioned constructor; forwards caller dimensions and fixed text-pane flags, initializes FrameHandler, installs four SpelledPane vtable views, and default-constructs the entry vector.
  - `[0x0056bc70,0x0056bc9d)` `SpelledPane__DeleteLine`, `void __thiscall(SpelledPane *this, short lineIndex)`: Deletes one text line after clamping its signed line index and resolving the line's exact text range through TextEditPane helpers.
  - `[0x0056bca0,0x0056be17)` `SpelledPane__AddOrUpdateEntry`, `void __thiscall(SpelledPane *this, const wchar_t *text, int value, int group)`: Updates an existing SpelledPane entry by text/group or appends a new 12-byte entry, rebuilding text and restoring vertical scroll only after insertion.
  - `[0x0056be20,0x0056bea0)` `SpelledPane__RemoveEntry`, `void __thiscall(SpelledPane *this, const wchar_t *text, int group)`: Removes the matching SpelledPane text/group entry, rebuilds display text, and scrolls the vertical pane to the top.
  - `[0x0056bea0,0x0056c0d8)` `SpelledPane__RebuildDisplayText`, `void __thiscall(SpelledPane *this)`: Rebuilds SpelledPane display text in group order, inserts a separator before group one, omits zero-valued rows, and invalidates the pane.
  - A07 remains `[0x0056c0e0,0x0056c2db)` `SpelledPane_ParseAndLoadEntries`, `void __thiscall(struct SpelledPane *this, const wchar_t *text, int length)`; its established parser/loader comment, writable local space/tab delimiter, and intentionally uninitialized third local scalar were protected without change.
  - `[0x0056c2e0,0x0056c2e5)` `SpelledPane__HandleKeyOrTextEvent`, `bool __thiscall(SpelledPane *this, Event *event)`: SpelledPane EventHandler key/text override; intentionally returns false without consuming the event.
  - `[0x0056c2f0,0x0056c2f5)` `SpelledPane__OnMouseEvent`, `bool __thiscall(SpelledPane *this, Event *event)`: SpelledPane mouse-event override; intentionally returns false without consuming the event.
  - `[0x0056c300,0x0056c3f1)` `SpelledPane__OnFrameUpdate`, `bool __thiscall(SpelledPane *this, const FrameUpdateContext *context)`: SpelledPane FrameHandler callback; decrements positive entry lifetimes, removes expired entries, rebuilds text while restoring scroll, and reschedules after 50 frames.
- Gate 2B declared incomplete `FrameUpdateContext` and modeled A02/A03 at their exact retained ranges. Typed analysis and disassembly expose the complete arguments, but Hex-Rays still fails at calls `0x0056bc15` and `0x0056bc84`; this is a bounded tool limitation and not a body, ownership, placement, or source reconstruction blocker.
- All ten body sizes, preserved-byte hashes, incoming xref counts, nine `0xcc` padding spans, vtable cells, dependent helper prototypes, literals, and parser behavior remain byte-for-byte and structurally unchanged.

## 2026-07-29 Shared IDB Currentness Recheck

- `0E0AF938...AB481` is the historical UID0001HA applied/save checkpoint; `03F102...DBE5DA` and earlier are historical. Current authoritative session `1da2b2ae` is `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`.
- Read-only recheck found no file-family drift across all ten method identities, types, comments, body hashes, xrefs, padding, vtable/data routes, literals, or protected dependencies. A02/A03 retain exact typed analysis with unchanged bounded Hex-Rays failures. Agent-B001 did not mutate/save IDA.
- Currentness supersession: `3C8F3178...5B69` is historical. Current authoritative session `1da2b2ae` is `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`; the complete file family again matched.
- Currentness supersession: `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B` and every earlier identity are now dated history. Current authoritative session `1da2b2ae` is saved SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, last write `2026-07-29T14:42:53.5091352-04:00`; bounded read-only target/dependency readback again found zero UID0001HA drift across exact names, ranges, prototypes, four comment channels, body hashes, xref counts, padding, callback slots, literals, helper identities, and relevant type state. A02/A03 retain exact typed analysis with the same bounded Hex-Rays failures at `0x0056bc15` and `0x0056bc84`. Agent-B001 did not mutate or save IDA.

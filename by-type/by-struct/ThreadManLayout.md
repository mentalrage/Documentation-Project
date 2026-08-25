*** UID:0001WA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ThreadMan object layout is emitted by [UID:0000EW][ThreadMan](by-class/ThreadMan.md) ThreadMan class declaration;
// this page supplies offset evidence only and should not emit a duplicate type.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThreadManLayout

## Status

- Kind: class object layout
- Owner class: [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- Likely declaring header: `util/Thread.h`
- Confidence: very strong for the exact `0x14` extent, direct bases, Singleton PMD/EBO, observed field offsets, owner, and current source-facing field names.

## Layout

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `vtable` / `LObject` base head | Constructor calls the common `LObject` constructor and installs `ThreadMan::vftable`; destructor reinstalls the same vtable before teardown. |
| `0x04` | direct empty `Singleton<ThreadMan>` base | RTTI BCD `0x006516a0` has PMD `{mdisp=4,pdisp=-1,vdisp=0}`. The fieldless non-virtual base occupies no distinct byte and overlaps the first derived member through MSVC EBO. |
| `0x04` | `m_isDebuggerPresent` | Constructor clears this byte, optionally calls `IsDebuggerPresent`, and stores the result. Worker loop skips the fatal watchdog pass when this byte is nonzero. |
| `0x08` | `m_workerThreadHandle` | Constructor stores the `CreateThread` handle here; destructor paths call `TerminateThread` and `CloseHandle` on it. |
| `0x0c` | `m_workerThreadId` | Passed as the `CreateThread` thread-id output parameter and used by raw wrappers as the `PostThreadMessageW` destination. |
| `0x10` | `m_watchList` | Constructor allocates `List(20, 16)` and stores the pointer here; worker loop and retained helpers scan/mutate 20-byte watchdog records. |

Observed object size is exactly `0x14` bytes. No field beyond `+0x10` is read or written by the current constructor, worker-loop, or scalar deleting destructor evidence; the scalar wrapper's flag-4 path independently passes size `0x14`.

## Notes

IDA exposes a `ThreadMan` COL at `0x00651650`, CHD at `0x00651664` with attributes `1` and three entries (`ThreadMan`, `LObject`, `Singleton<ThreadMan>`), and the Singleton BCD at `0x006516a0`. The Singleton PMD places the direct base at `+0x04`; because that accepted template is fieldless, EBO overlaps it with `m_isDebuggerPresent` rather than adding storage. The singleton pointer remains separate file-static [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) storage at `0x0069be08`, not a hidden base member.

Source base order is `class ThreadMan : public LObject, public Singleton<ThreadMan>`. Constructor lowering builds `LObject`, forms the `this+4` Singleton subobject and converts it back to the complete object for publication, then enters the derived body. Reverse destruction performs derived cleanup, the Singleton specialization clear, then `LObject` teardown. Consequently the five global writes are lifetime-specialization lowering; they do not enlarge this layout or justify explicit assignments in the derived constructor/destructor.

The field names now match the class-level draft declaration in [UID:0000EW][ThreadMan](by-class/ThreadMan.md). `m_workerThreadId` is intentionally distinct from [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)'s `watchedThreadId`; the former is the manager worker thread id used for `PostThreadMessageW`, while the latter is copied from a watched `Thread` object at `Thread+0x60`.

B008 2026-06-19 destructor reanalysis keeps the `m_` names as current best descriptive source-facing spellings rather than symbol-proven original names. The scalar deleting destructor and raw non-deleting destructor both prove `m_workerThreadHandle` is a Win32 `HANDLE` value at `+0x08` and `m_watchList` is a heap `List *` at `+0x10`; the constructor proves `m_workerThreadId` at `+0x0c` by passing `this+0x0c` to `CreateThread` and the raw wrappers then use that value as the `PostThreadMessageW` destination. The scalar wrapper's flag-4 path pushes object size `0x14`, matching the observed minimum layout size.

B009's Rule 26 recheck independently validates the same destructor-facing layout names and records the inference boundary: `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList` are high-confidence source-facing names selected from constructor/destructor/wrapper context, while exact original spelling and prefix style remain inferred. Reject `std::list`, inline-array, or raw byte-buffer interpretations for `+0x10`; the teardown code reads a heap pointer and deletes it through the first virtual slot with deleting flag `1`.

B012 rechecked the same field/type inferences from constructor, raw ordinary destructor, scalar wrapper, and message-wrapper context. Current best names remain `bool m_isDebuggerPresent`, `HANDLE m_workerThreadHandle`, `DWORD m_workerThreadId`, and `List *m_watchList`; the `m_` prefixes are descriptive/source-facing rather than symbol-proven. The scalar wrapper's flag-4 branch pushes object size `0x14`, matching the observed object extent, and B012 explicitly rejects treating `+0x10` as inline storage, a raw byte buffer, or a standard-library list.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x00596bf0` observed publication to [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md), vtable installation, debugger-byte initialization, `List(20, 16)`, and worker creation. The accepted C305 RTTI/PMD reanalysis supersedes the old assumption that publication was an explicit derived-body statement: the write is lowering of the direct `Singleton<ThreadMan>` base constructor specialization.
- 2026-05-31 IDA MCP decompilation of `0x00596e10` confirms the worker loop reads debugger byte `+0x04` to skip the fatal watchdog scan and iterates the list at `+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x005974f0` confirms the scalar deleting destructor reinstalls `ThreadMan::vftable`, terminates/closes the handle at `+0x08`, releases the list at `+0x10`, clears [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md), and calls the common `LObject` destructor.
- 2026-06-11 Agent-A006 live IDA MCP recheck reconfirmed the function records for the constructor `0x00596bf0-0x00596d13`, worker loop `0x00596e10-0x005970df`, and scalar deleting destructor `0x005974f0-0x0059756e`. The same check still reports raw wrapper starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` as `Not a function`, preserving the raw-wrapper caveat outside this object-layout page.
- 2026-06-11 live decompilation again shows `+0x04` as the debugger-present byte, `+0x08` as the thread handle, `+0x0c` as the `CreateThread` thread-id out slot, and `+0x10` as the `List` pointer used by the worker message cases and watchdog scan. Live xrefs to `0x0069be08` remain limited to constructor writes at `0x00596c33`/`0x00596c3a`, raw wrapper use at `0x00596d5f`, singleton clear at `0x005974e0`, and destructor clear at `0x00597532`.
- 2026-06-20 B003 source-quality review resolved source-facing names for all four fields: the debugger byte stores the result of the dynamic probe and is not a function pointer; the handle/id pair belongs to the manager worker thread; and the list pointer owns `ThreadManWatchRecord` entries.
- 2026-06-19 B008 local PE/Capstone recheck independently matched the constructor/destructor field uses: `+0x08` is terminated/closed/cleared as the worker handle, `+0x0c` is the thread-id out slot and wrapper message destination, `+0x10` is deleted/null through a `List` vtable, and the scalar deleting wrapper's size argument confirms the observed `0x14` byte object size.

## Parent Attachment Decision

Attach this layout to [UID:0000EW][ThreadMan](by-class/ThreadMan.md). The layout is a private class object layout, not a file-level helper struct, and every observed field is read or written by `ThreadMan` constructor, worker, and destructor code. The direct class parent is already `86/85` and attached to [UID:0000OR][Thread](by-file/Thread.md), so this child now clears the strict child/direct-parent `85/85` gate.

Keep the reconstruction C++ block blank for this layout page so it does not duplicate the class declaration emitted by [UID:0000EW][ThreadMan](by-class/ThreadMan.md). This page supplies the offset proof and field-name evidence for that class declaration.

## Cross-References

- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)

## Changes

- 2026-08-01 B007 C305 ordinary callback:
  - Raised `86/90` to `90/94`; added direct bases `LObject` and fieldless `Singleton<ThreadMan>`, exact CHD/BCD addresses and PMD `{4,-1,0}`, EBO overlap with `m_isDebuggerPresent` at `+0x04`, exact `0x14` extent, source base order, and specialization-generated publication/clear. The existing covered-by CPP marker and blank H remain unchanged so [UID:0000EW][ThreadMan](by-class/ThreadMan.md) emits the class only once.
- 2026-06-20 B003 Rule 26 incorporation:
  - Before: `85/88`, field names lacked the `m_` class-member spelling, and the page still treated exact names as a final-source blocker.
  - After: `86/90`, fields are documented as `m_isDebuggerPresent`, `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList`, with explicit distinction between the manager worker id and watched record thread ids. C++ remains blank here because [UID:0000EW][ThreadMan](by-class/ThreadMan.md) emits the class declaration.
- 2026-06-21 B008 scalar-wrapper support sync:
  - Summary/evidence: added the destructor-facing B008 confirmation for `HANDLE m_workerThreadHandle`, `DWORD m_workerThreadId`, `List *m_watchList`, and the `0x14` object-size argument observed in the scalar deleting destructor guard path. Metadata remains unchanged because B003 already resolved the field names and class ownership.
- 2026-06-21 B009 Rule 26 older-report reconciliation:
  - Summary/evidence: added B009's explicit heuristic/inference boundary for field names and rejected alternatives for `+0x10`; metadata remains unchanged because the current layout score already reflects source-facing field-name closure without claiming original symbol spelling.
- 2026-06-22 B012 source-quality implementation:
  - Summary/evidence: added B012's independent constructor/destructor/message-context validation for the four ThreadMan fields, the observed `0x14` object extent, and the explicit rejection of inline/raw/std-list alternatives for `m_watchList`. Metadata remains unchanged.
- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, worker-loop, and destructor field use. The score remains below final-source level because the raw message-wrapper island and exact original type names still need a broader source audit.
- 2026-06-11 Agent-A006 Batch 147 parent-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, and no autogen parent.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000EW`.
  - Summary/evidence: live IDA MCP reconfirmed the constructor, worker loop, destructor, singleton xrefs, and still-raw message-wrapper starts. The page now documents the `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10` fields, minimum `0x14` byte observed layout, direct `ThreadMan` ownership, and the class/file parent chain that satisfies the strict child/direct-parent gate. Final C++ remains blank because exact original member names and raw wrapper source spelling are not final-audit quality.

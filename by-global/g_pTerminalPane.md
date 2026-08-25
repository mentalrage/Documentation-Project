*** UID:0000SF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TerminalPane;

TerminalPane *g_pTerminalPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTerminalPane

## Status

- Confidence: strong for terminal/phone parent singleton role and physical storage slot.
- Address: `0x0069bdf8`
- Symbol kind: global-data pointer
- Likely owner file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Current generated owner evidence: `NexusTK/login/TerminalPane.cpp`, with users in `PhoneBookDialog`, `PhoneEntryDialog`, and `DialDialog`.
- Exact storage evidence: [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) records catalog0376-applied `TerminalPane *g_pTerminalPane` over `0x0069bdf8-0x0069bdfc`, split from the mixed [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md) cluster.
- Source lifetime cause: [UID:0000EG][TerminalPane](by-class/TerminalPane.md) directly inherits `Singleton<TerminalPane>` at EBO displacement `+0x26c`. Base construction publishes this pointer; constructor unwind and destruction clear it unconditionally.
- IDB naming history and current state: 2026-07-04 B005 MCP session `cbc24146` rendered the storage as `unk_69BDF8`/`dword_69BDF8` and could not resolve `g_pTerminalPane`. Supervisor catalog0376 later applied and verified `TerminalPane *g_pTerminalPane`, nine refs, zero bytes, and blank address comments. The raw labels are historical; the accepted source-facing spelling remains inferred rather than PDB-proven.

## Role

`g_pTerminalPane` points to the active pre-login terminal pane. Direct `Singleton<TerminalPane>` base construction publishes the active pane; direct-base unwind/destruction clears it unconditionally. Phone-book entry and dial dialogs use it as their terminal parent but do not own its lifetime.

The global should be source-declared with the terminal pane implementation, while the exact `.data` slot remains documented in the adjacent mixed global cluster. The cluster should not imply a source-level aggregate; it only records physical adjacency between terminal and text-edit globals.

This page is the single source declaration owner for the singleton. The exact by-memory storage page [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) now emits only a covered-by marker so generated source does not duplicate `TerminalPane *g_pTerminalPane = 0;`.

The stores at constructor stage `0x0058afa8/0x0058afaf`, EH helper `0x0058dbe0`, and scalar wrapper `0x0058dc66` are compiler-lowered direct-base lifetime effects. Do not reproduce them as handwritten TerminalPane constructor/destructor assignments, a class-local clear helper, or a guarded `if (g_pTerminalPane == this)` form.

`TerminalSetupPane::OnCommand` also reads this singleton after applying terminal serial settings: command id `1` writes `g_pConfig+0x28de28` / `terminalComPort` and `g_pConfig+0x28de2c` / `terminalBaudRate`, then refreshes the active terminal pane through its virtual slot at `+0x4c` before posting the Socket reset/close command. Phone-book and dial helpers remain consumers of the singleton, not lifetime owners.

## Xref Notes

IDA MCP checked on 2026-05-24:

- `0x0058af50` stores the constructed `TerminalPane` and initializes the terminal singleton lifecycle.
- `0x0058b650`, `0x0058c240`, `0x0058c350`, `0x0058d270`, and `0x0058d750` use the terminal pane as the dialog parent or terminal-family context.
- [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) is a tiny constructor EH/unwind helper that clears `0x0069bdf8`.
- `0x0058dc60` clears the singleton in the `TerminalPane` scalar deleting destructor.
- 2026-05-26 recheck confirms `0x0058dbe0` is reached from the `TerminalPane` constructor unwind metadata path, while `0x0058dc60` is the normal destructor clear path.
- Historical IDA MCP `py_eval` on 2026-05-31 recorded raw IDA name `dword_69BDF8`, initial dword `0xffffffff`, and 9 data xrefs. The raw-name and xref count remain useful as historical lead evidence, but the initial value is superseded by the 2026-07-04 B005 current-session byte/value checks below.
- 2026-07-04 B005 current-session MCP pass used session `cbc24146`: `server_health` was OK with auto-analysis and Hex-Rays ready; `lookup_funcs 0x0069bdf8` reported not-a-function; `get_bytes 0x0069bdf0 size 32` returned all zero bytes; `get_int 0x0069bdf8 u32le` and `get_global_value 0x0069bdf8` returned zero.
- The same B005 pass reconfirmed the nine exact refs and meanings: constructor publish at `0x0058afa8`, constructor adjusted-null/decompiler-artifact fallback clear at `0x0058afaf`, setup/phone/dial consumer reads at `0x0058c15d`, `0x0058c316`, `0x0058c97d`, `0x0058d4ef`, and `0x0058d907`, constructor-unwind clear at `0x0058dbe0`, and destructor clear at `0x0058dc66`.
- B005 neighbor/pointer checks found no extra `F8 BD 69 00` immediate matches beyond those nine refs. Adjacent storage remains separate: `0x0069bdfc` has six TextEdit clipboard-format refs, `0x0069be00` has eight active TextEditPane refs, `0x0069be04` has eight TextEdit mouse-selection scratch refs, `0x0069be06` has zero refs and remains padding, and `0x0069be08` has five ThreadTimer/Timer refs.
- 2026-06-06 documentation refresh links this global to the current [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) range map, including `TerminalPane::TerminalPane`, `TerminalSetupPane` construction/update/command handlers, stream parser and reconnect/leave callback children, terminal vtable data, and the singleton storage cluster.
- 2026-06-21 B006 source-quality sync: [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) recheck confirms constructor writes at `0x0058af50`, scalar deleting destructor clear at `0x0058dc60`, setup command refresh through `g_pTerminalPane` virtual slot `+0x4c`, and phone/dial parent reads as separate consumer evidence.
- Fresh UID000247 RTTI analysis proves `Singleton<TerminalPane>` is a direct nonvirtual base with PMD displacement `+0x26c`. This resolves the source cause for constructor publication, unwind clear, and unconditional destructor clear without adding source assignments to TerminalPane methods.

## Ownership Notes

Keep this global with `login/TerminalPane.cpp`. `PhoneBookDialog.cpp` and `DialDialog` consume the pointer because their dialogs are terminal children, but the singleton lifetime is owned by `TerminalPane`.

This page now emits the source declaration for the singleton while [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) carries exact storage proof. The score remains below final-source levels because exact original declaration spelling/static linkage remains inferred, not because any current IDB raw-name or MCP-timeout blocker remains.

Rejected source forms: duplicate definition on the storage page, class-static rewrite without proof, PhoneBook/Dial ownership, handwritten publish/clear in TerminalPane methods, pointer-comparison guard, or explicit Singleton cleanup helper.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md)
- [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md)
- [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md)
- [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)

## Changes

- 2026-07-30 B010 UID0002AP post-Gate2B reconciliation:
  - Replaced the current raw-name caveat with catalog0376's applied/read-back `TerminalPane *g_pTerminalPane` item, preserving nine refs, zero bytes, blank address comments, exact range, source lifetime cause, and every historical raw alias.
  - Recorded supervisor save SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94`; metadata, formal declaration, ownership, and duplicate-definition policy are unchanged.

- 2026-07-16 B001 accepted UID000247 support synchronization:
  - Preserved `88/91`, owner/emitter UID0000OI, reconstructable true, and the existing formal global definition.
  - Added direct `Singleton<TerminalPane>` EBO/lifetime cause for constructor publication, EH clear, and unconditional destructor clear.
  - Historicalized manual constructor/destructor clear interpretations and rejected guarded/duplicate ownership forms without changing the exact nine-ref evidence.
- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OI` for [UID:0000OI][TerminalPane](by-file/TerminalPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069bdf8` as a 4-byte singleton pointer with 9 data xrefs spanning TerminalPane construction, setup/phone/dial parent usage, constructor-unwind cleanup, and the scalar deleting destructor clear.
- 2026-06-06: Raised `COMPLETION` from `74` to `80` and `CONFIDENCE` from `84` to `86`.
  - Added exact storage-cluster evidence, refreshed current TerminalPane range/child links, and clarified source-declared/generated-binary handling for the physical `.data` slot.
  - Evidence: existing IDA-backed docs tie `dword_69BDF8` to [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md), constructor writes, setup/dialog-parent reads, constructor EH clear, normal scalar deleting destructor clear, terminal vtables, and the [UID:0000OI][TerminalPane](by-file/TerminalPane.md) owner. At that historical point, final C++ was still blank because the exact source declaration spelling was treated as below the then-used 95/95 threshold; the 2026-07-04 B005 callback supersedes that blank-C++ state.
- 2026-06-07 A004 Batch 056 parent-gate refresh:
  - Before: `80/86`, with exact storage still documented only through the mixed terminal/text-edit cluster.
  - Changed to: `86/88`, linking exact child [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md).
  - Summary/evidence: existing IDA-backed constructor, terminal/setup/dialog-parent, EH clear, and destructor-clear evidence is now tied to the exact four-byte storage page. Live MCP refresh timed out during this pass, so no final C++ declaration was emitted.
- 2026-06-21 B006 Rule 26 support sync:
  - Added the setup apply-path use of `g_pTerminalPane` after terminal COM/baud config writes and before Socket reset/close posting.
  - Score unchanged because this reinforces existing singleton ownership rather than changing source placement.
- 2026-07-04 B005 UID000300 implementation callback:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, blank formal C++, historical `0xffffffff` initialization wording, and a stale MCP-timeout blocker from the Batch 056 pass.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:91`, formal source declaration `class TerminalPane;` plus `TerminalPane *g_pTerminalPane = 0;`, and current-session evidence that the exact storage page emits only a covered-by marker.
  - Summary/evidence: MCP session `cbc24146` reported health OK, zero bytes/value at `0x0069bdf8`, nine constructor/read/clear refs, no extra pointer/immediate hits, raw IDB-name caveat (`unk_69BDF8` / `dword_69BDF8`), neighboring-slot separation, and the pre-callback generated empty-marker defect now repaired by the by-global declaration route.

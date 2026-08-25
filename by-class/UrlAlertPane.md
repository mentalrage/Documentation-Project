*** UID:0000FF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UrlAlertPane : public AlertPane
{
public:
    UrlAlertPane(bool exitAfterOpen,
                 Pane *layoutReference,
                 const wchar_t *messageText,
                 const char *urlText,
                 unsigned int urlLength);
    virtual ~UrlAlertPane();

protected:
    virtual void OnPrimaryButton();

private:
    char *m_url;
    bool m_exitAfterOpen;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UrlAlertPane

## Status

- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Address range: [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- Vtables: [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md) at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`.
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md), with `m_url` at `+0x270` and `m_exitAfterOpen` at `+0x274`.
- Generated output target: `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`.
- Reconstruction parent: attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md). The 2026-06-21 B011 source-quality pass resolves the inherited callback source name as `OnPrimaryButton()`, the constructor/destructor/confirm-handler signatures, the `m_url` and `m_exitAfterOpen` roles, and the compiler-glue policy enough for declaration-level C++ and child method emission.
- Confidence: very strong for the class behavior and source route; remaining uncertainty is exact original field/helper spelling and global linkage.

## Class Purpose

`UrlAlertPane` is an `AlertPane` subclass that displays a confirmation prompt for an external URL. It owns an ANSI URL buffer copied from packet data, opens that URL through `ShellExecuteA` when the primary button is pressed, and optionally requests application shutdown afterward.

The source-facing callback name is `OnPrimaryButton()` because [UID:00000B][AlertPane](by-class/AlertPane.md) declares the alert button slots as `OnPrimaryButton` / `OnSecondaryButton`. `OnConfirm` is retained as a behavior alias only.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `UrlAlertPane` | `0x00599a40-0x00599b19` | Source-authored constructor: `UrlAlertPane(bool exitAfterOpen, Pane *layoutReference, const wchar_t *messageText, const char *urlText, unsigned int urlLength)`. It forwards to `AlertPane(messageText, layoutReference, L"OK", NULL)`, publishes [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), allocates/copies/NUL-terminates `m_url`, and records `m_exitAfterOpen`. |
| `~UrlAlertPane` | `0x00599b20-0x00599b92` | Source-authored ordinary destructor: frees `m_url` through the current MemoryMan helper path and clears `g_pUrlAlertPane`. Inherited/base teardown is compiler/base behavior, not a direct source call to write in the derived destructor. |
| `OnPrimaryButton` / confirm handler | `0x00599ba0-0x00599bcf` | Source-authored primary-button override. Calls `ShellExecuteA(NULL, NULL, m_url, NULL, NULL, SW_SHOWNORMAL)` and, if `m_exitAfterOpen` is nonzero, calls [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md). |
| constructor-unwind clear helper | `0x00599bd0-0x00599bda` | Compiler EH cleanup helper that clears [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) if construction fails after singleton publication. No handwritten C++ body. |
| destructor adjustor thunks | `0x00599bdb-0x00599bf1` | Compiler-generated secondary/tertiary vtable thunks into the deleting destructor. No handwritten C++ body. |
| scalar deleting destructor wrapper | `0x00599c00-0x00599cb3` | MSVC deleting-destructor wrapper with optional object-storage delete flags. Generated from `virtual ~UrlAlertPane()`, not handwritten source. |

## Evidence Notes

- IDA decompilation and B011 raw PE/Capstone recheck show the constructor calling `AlertPane::AlertPane` with [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) / `L"OK"` and a null secondary button.
- 2026-05-26 IDA MCP vtable pass confirms `UrlAlertPane` primary/secondary/tertiary vtables at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`, installed by constructor stores at `0x00599aac`, `0x00599ab2`, and `0x00599abc`.
- 2026-05-26 IDA layout pass and B011 reanalysis confirm `+0x270` as `char *m_url`: constructor allocates `urlLength + 1`, copies raw ANSI bytes, writes a terminator, handler passes it to `ShellExecuteA`, and destructor frees it. Wide-string, borrowed-pointer, and `StringBase` interpretations are rejected.
- B011 confirms `+0x274` as `bool m_exitAfterOpen`: constructor stores the first argument byte and the handler tests it before calling `Application::RequestExit`. A URL-length tail or multi-mode enum is unsupported by observed use.
- IDA disassembly of the constructor exception cleanup jumps to `0x00599bd0`; that helper only clears `g_pUrlAlertPane`. The actual destructor adjustor thunks are `0x00599bdb` and `0x00599be6`, and the scalar deleting destructor wrapper is `0x00599c00-0x00599cb3`.
- IDA xrefs to the constructor include calls from `0x00503034` and `0x00513f7e`/`0x0051402f`; `0x00503034` is inside [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md). B003 2026-06-18 confirms the MainMenu opcode `0x66` helper uses the same URL/prompt layout for subtypes `1` and `2`; the differing constructor argument is the `exitAfterOpen` behavior stored at `UrlAlertPane+0x274`, not ownership of the packet helper.
- The two in-game/MapPane constructor callers at `0x00513f7e` and `0x0051402f` are opcode `0x66` analogs. They construct the reusable alert and do not own this class implementation.
- `OnPrimaryButton` directly calls `ShellExecuteA(0, 0, m_url, 0, 0, 1)` and then optionally requests application exit.
- Raw scans found no ordinary direct calls to the ordinary destructor, primary-button handler, adjustor thunks, or scalar deleting destructor except thunk jumps. Virtual/destructor dispatch explains this and does not block source C++.
- Exact vtable-data child [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) records the three vtable views, confirm-handler slot, destructor adjustor thunk slots, and exclusive end before `UserInfoDialogPane`.
- Mixed read-only aggregate [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md) keeps the preceding `UniAPIInit` vtable dword parentless/PlatformApi-owned while assigning only the nested URL-alert vtable data to this class and [UID:0000HE][AlertPanes](by-file/AlertPanes.md).

## Source Ownership And Glue Policy

- Direct executable owner is this class. The broader [UID:0000HE][AlertPanes](by-file/AlertPanes.md) file remains the source root and generated output destination.
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) and the MapPane packet paths are caller/consumer adapters for opcode `0x66`, not class owners.
- `Browser` is rejected as an owner because the alert only launches an external URL through `ShellExecuteA`; it does not contain browser control state.
- `Application` is rejected as an owner because it only supplies the optional `RequestExit` callee.
- The compiler-generated constructor-unwind clear helper, adjustor thunks, scalar deleting destructor wrapper, vtable stores, and base destructor calls must be regenerated from the declaration/destructor, not hand-authored in class source.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md)
- [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)
- [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md)
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)
- [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md)
- [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md)

## Changes

- 2026-06-21 B011 Rule 26 source-quality incorporation:
  - Raised from `88/90` to `89/91` and added first-draft class declaration C++ with constructor, virtual destructor, `OnPrimaryButton`, `m_url`, `m_exitAfterOpen`, and `[[CHILDREN]]`.
  - Replaced stale final-C++ blockers with resolved source decisions: formal callback name follows the base `OnPrimaryButton` slot, `OnConfirm` is prose alias only, `m_url` is owned ANSI storage, `m_exitAfterOpen` controls optional exit, and compiler EH/thunk/deleting-destructor subranges remain no-code glue.
  - Evidence: B011 raw PE/Capstone recheck over [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md), existing vtable/layout/global docs, and packet caller separation.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, destructor, confirm handler, singleton-clear helper, adjustor thunks, and scalar deleting destructor at `0x00599a40`, `0x00599b20`, `0x00599ba0`, `0x00599bd0`, `0x00599bdb`, `0x00599be6`, and `0x00599c00`; at that time likely parent [UID:0000HE][AlertPanes](by-file/AlertPanes.md) was `78/85`, so the parent-side gate did not pass. No C++ was emitted because inherited slot names and final class declaration details still need a class-focused audit.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/destructor/confirm/thunk method map, URL/exit layout offsets, vtable stores, singleton handling, constructor xrefs, and direct `ShellExecuteA` behavior.
- 2026-06-07 parent attachment:
  - Before: `AUTOGEN_PARENT_UID` stayed blank because [UID:0000HE][AlertPanes](by-file/AlertPanes.md) was below the parent-side score gate.
  - Changed to: `AUTOGEN_PARENT_UID:0000HE`, with final C++ still blank.
  - Evidence: `AlertPanes` is now `82/86` with valid `NexusTK/ui/dialogs/` path and records the URL-alert executable, exact vtable-data child, mixed-owner `.rdata` split, and MainMenu packet-adapter separation. This class remains below the final C++ gate because inherited slot naming and source-quality class declaration details still need a final audit.

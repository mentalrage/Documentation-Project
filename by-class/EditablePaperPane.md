*** UID:000048 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "EditablePaperPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "DialogPane.h"

enum PaperOpenMode
{
    kPaperOpenEditable = 0,
    kPaperOpenReadOnly = 1
};

class EditablePaperPane : public DialogPane
{
public:
    EditablePaperPane(const unsigned char *packet, PaperOpenMode mode);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void DrawBackground();
    virtual void DrawBorder();
    virtual void InitializePaperContent(wchar_t *text);

private:
    void ParseEditablePacket(const unsigned char *packet);
    void ParseReadOnlyPacket(const unsigned char *packet);
    void SavePaperContent();

    unsigned char m_paperId;
    unsigned char m_packetStatusByte;
    signed char m_widthTiles;
    signed char m_heightTiles;
    short m_textLength;
    int m_reservedPaperState;
    PaperOpenMode m_paperMode;
    unsigned char m_centerText;
};

typedef char EditablePaperPaneSizeMustBe640[
    sizeof(EditablePaperPane) == 0x280 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EditablePaperPane

## Status

- Confidence: strong for the closed behavior, ABI, complete source route, exact layout, and bounded descriptive name at `+0x274`.
- Likely source: [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- Generated-output note: no Wave2/Wave3 source output is used as authority; ownership rests on by-file/by-memory/IDA evidence.
- Memory: [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- Type docs: [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- Exact vtable data: [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md)

## Responsibility

`EditablePaperPane` is a `DialogPane`-derived paper/document UI. It displays server-sent paper content in either editable or read-only mode, renders a tiled paper frame from `LINE001.EPD`, hosts a text edit control, and sends edited paper content back to the server.

## Layout Evidence

Generated metadata and method bodies support a 640-byte class with a `DialogPane` base and paper-specific fields near the end:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x26c` | `m_paperId` | Parsed from editable packet byte `+1` and written into save packet byte `+1`. |
| `+0x26d` | `m_packetStatusByte` / `m_reservedPacketStatus` | Parsed from both inbound paper packet formats and then cleared before common initialization; best documented as a protocol/reserved status byte. Exact business meaning remains unproven, but this is no longer an unknown behavior blocker. |
| `+0x26e` | `m_widthTiles` | Used to compute `(width + 2) * 16` pixel width. |
| `+0x26f` | `m_heightTiles` | Used to compute `(height + 3) * 16` pixel height. |
| `+0x270` | `m_textLength` | Stores the `MultiByteToWideChar` result length. |
| `+0x272..+0x273` | natural padding | Required to align the four-byte tail state; no source field is emitted. |
| `+0x274` | `m_reservedPaperState` | Descriptive four-byte reserved state; exhaustive class-island access audit found no constructor initialization or class read/write. |
| `+0x278` | `m_paperMode` | Constructor mode; `0` editable, `1` read-only. |
| `+0x27c` | `m_centerText` | Read-only packet flag that centers single-line text. |
| `+0x27d..+0x27f` | natural tail padding | Completes exact class size `0x280`; no reserved byte array is introduced. |

The text editor is owned through the dialog control list rather than a proven tail member. The close/action button is control index `0`, the `TextEditControlPane` is control index `1`, and save reacquires the editor from that control slot. Parser/save text buffers are local stack buffers.

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| `0x00545170-0x00545217` | constructor | Initializes base dialog and dispatches to the mode-specific parser. |
| `0x00545220-0x0054524b` | `OnControlCommand(int,int)` | Ignores the notify argument; editable control index `0` saves, then the dialog closes. |
| `0x00545250-0x0054565b` | `InitializePaperContent` | Builds controls, applies edit/read-only limits, hides editor scrollbars, and opens the pane. |
| `0x00545660-0x00545877` | packet parsing | Reads editable/read-only packet headers, dimensions, centered flag, and text payload. |
| `0x00545880-0x005459a7` | save serialization | Encodes edited text as opcode `0x23`. |
| `0x005459b0-0x00545dc1` | drawing | Draws the `LINE001.EPD` border and background fill. |
| [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md), `0x00545e00-0x00545e3b` | destructor support | Two compiler adjustors and the compiler scalar deleting wrapper; an implicit derived destructor is the sufficient source cause. |

## Vtable Evidence

IDA `list_globals` confirms `EditablePaperPane` vtable bases at `0x00621afc`, `0x00621b60`, and `0x00621b90`. The primary table includes paper-specific slots for `OnControlCommand(int,int)` (`0x00545220`), `DrawBackground` (`0x00545d50`), `DrawBorder` (`0x005459b0`), and `InitializePaperContent` (`0x00545250`).

The tertiary table is short: it owns only the destructor adjustor `0x00545de8` and inherited slot `0x00544e90`. The dword at `0x00621b98` begins adjacent `LINE001.EPD` string/data, which helps explain the stale disabled `0x0045004e` generated row.

## Packet Behavior

- Editable open packets include paper id, parsed-then-cleared reserved/status byte, width tiles, height tiles, 16-bit text length, and multibyte text.
- Read-only open packets omit the paper id, include parsed-then-cleared reserved/status byte, width tiles, height tiles, centered flag, 16-bit text length, and multibyte text.
- Outbound save packets use opcode `0x23`, write paper id at byte `+1`, big-endian text byte count at `+2..+3`, and text bytes at `+4`; the send length is text byte count plus four.
- During display setup, tabs are converted to carriage returns for the text editor.
- During save, carriage returns are converted back to tabs, the text is converted to multibyte, and the client sends opcode `0x23` with paper id plus 16-bit text length.

## Remaining Source-Quality Limits

- The exact business meaning of `+0x26d` remains unproven, but its source role is bounded as a packet status/reserved byte parsed by both inbound formats and cleared before common initialization.
- [UID:000536][0x005128a0-0x005128fd.HandleEditablePaperPacket](by-memory/0x005128a0-0x005128fd.HandleEditablePaperPacket.md) and [UID:000537][0x00512900-0x0051295d.HandleReadOnlyPaperPacket](by-memory/0x00512900-0x0051295d.HandleReadOnlyPaperPacket.md) allocate and construct paper panes but have zero inbound IDA caller/pointer routes. They are exact retained file-static MapPane adapters, not `EditablePaperPane` methods.
- Generated disabled method `0x0045004e` is owner pollution from [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md) and should not be migrated with this class.
- 2026-05-26 IDA recheck confirms `0x00545ddd` and `0x00545de8` forward to `0x00545e00` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

The heading is retained for history. The 2026-08-16 callback closes the source surface: the packet-status byte is semantically bounded, `m_reservedPaperState` is deliberately descriptive rather than invented behavior, and UID000536/UID000537 are retained file-static MapPane children rather than class members.

## 2026-08-16 Source Closure

- The declaration has one direct source base, `DialogPane`. RTTI's EventHandler and TimerHandler facets arrive through Pane; declaring either again would duplicate inheritance.
- The primary `+0x48` override is exactly `void OnControlCommand(int controlIndex, int notifyCode)`. The body ignores `notifyCode`, responds only to index `0`, saves only in editable mode, and then closes.
- `InitializePaperContent(wchar_t *)` is a protected virtual at primary slot `+0x5c`; constructor-dispatched parsers call it virtually after decoding and clearing packet status.
- The complete object size is `0x280`. The typed tail is bytes at `+0x26c..+0x26f`, short at `+0x270`, natural alignment at `+0x272..+0x273`, descriptive four-byte reserved state at `+0x274`, `PaperOpenMode` at `+0x278`, center byte at `+0x27c`, and natural tail padding through `+0x27f`.
- `m_reservedPaperState` is intentionally uninitialized and unreferenced by this class. This negative evidence is preserved; no zeroing or behavioral use is invented.
- The implicit derived destructor is intentional. MSVC generates the primary scalar deleting wrapper and `this-0xa0`/`this-0xa4` adjustors from the class layout; no ordinary destructor declaration or raw ABI body is required.
- Formal CPP owns only the header include and `[[CHILDREN]]`; UID0001EE supplies the definitions. Formal H above is the complete two-mode declaration and the `sizeof == 0x280` compile-time check.

## 2026-06-16 A001 Evidence Refresh

- Live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed modeled function starts and sizes: constructor `0x00545170` size `0xa7`, action `0x00545220` size `0x2b`, setup `0x00545250` size `0x40b`, parsers `0x00545660`/`0x00545770` size `0x107`, save `0x00545880` size `0x127`, border draw `0x005459b0` size `0x396`, background draw `0x00545d50` size `0x71`, adjustors `0x00545ddd`/`0x00545de8` size `0xb`, scalar deleting destructor `0x00545e00` size `0x3b`, and no function at aggregate end `0x00545e3b`.
- `xrefs_to 0x00545170` returns constructor refs at `0x00508338` and `0x0050836b` inside `sub_507C90`, plus wrapper-internal calls from `0x005128e5` and `0x00512945`. `xrefs_to 0x005128a0` and `0x00512900` returns zero refs to the wrapper starts; B003's local PE scan also found no dword or rel32 route, so these stay no-route MapPane-side paper factory wrappers rather than `EditablePaperPane` class methods.
- Vtable xrefs remain exact: constructor stores `0x00621afc`, `0x00621b60`, and `0x00621b90`; the dword/string at `0x00621b98` is `aLine001Epd` and has draw-path data refs, not another `EditablePaperPane` vtable. `0x0045004e` resolves inside `sub_450030` / [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md), with unrelated data refs, so the generated row remains pollution.
- `func_profile` confirms constructor callees include the dialog/base setup plus both parser helpers, `0x00545250` calls UI/control setup helpers, `0x00545880` serializes through packet-buffer/text conversion helpers with opcode constants including `0x23`, and `0x005459b0` has draw-path constants and refs to `aLine001Epd`.
- `search_structs`/`type_query` found no IDA UDT for `EditablePaperPane` or `Paper`; `entity_query names *EditablePaperPane*` only returned decorated vtable/RTTI names, and `entity_query names *LINE001*` returned `aLine001Epd`. This supports the behavior/layout model but does not safely name byte `+0x26d` or settle wrapper file placement.

## Score Rationale

Completion/confidence are `94/94`: the complete declaration, direct-base rule, exact virtual signatures, 0x280 layout, method emitter, file route, compiler-data disposition, and retained MapPane-wrapper boundary are closed. The descriptive `m_reservedPaperState` name and retained zero-xref wrappers keep the score below certainty without blocking source generation.

## Cross-References

- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md)
- [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md)
- [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)

## Changes

- 2026-08-16 B001 implementation callback:
  - Raised `87/88 -> 94/94` and installed the accepted formal CPP preamble/children route plus complete formal H.
  - Corrected stale `OnDialogAction` and direct-handler-base assumptions; added `OnControlCommand(int,int)`, protected virtual `InitializePaperContent`, the exact typed tail/natural padding, descriptive unreferenced `m_reservedPaperState`, and implicit-destructor compiler disposition.
  - Preserved packet, renderer, wrapper, false-slot, and historical evidence while closing the owner/emitter/source route through UID0000IX and UID0001EE.

- 2026-06-18 B003 source-quality execution:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, with `+0x26d` and the wrapper starts still framed as unresolved blockers.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`, with resolved tail-field directions, control-list ownership for the editor, packet layouts, save semantics, and no-route wrapper disposition.
  - Summary/evidence: B003 preserved existing live-IDA-backed evidence and added local PE scan facts: constructor refs, vtable slot refs, `LINE001.EPD` references, no rel32/dword route to `0x005128a0`/`0x00512900`, and wrapper bytes allocating `0x280` then calling the constructor with mode `0` or `1`.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `84/86`.
  - Summary/evidence: paper-dialog responsibility, detailed tail layout, constructor/action/setup/parse/save/draw/destructor families, vtable evidence, packet behavior, and stale generated method pollution are documented; remaining uncertainty is the exact semantic for byte `+0x26d` and wrapper ownership.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IX`.
  - Evidence: live IDA MCP confirms modeled starts at `0x00545170`, `0x00545220`, `0x00545250`, `0x00545660`, `0x00545880`, `0x005459b0`, `0x00545d50`, and `0x00545e00`, with paper-open caller paths into the constructor; this class and the parent file both meet the 80% completion/confidence attachment gate.
- 2026-06-16 A001 source-quality refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: current IDA MCP rechecked function sizes, constructor caller refs, zero-ref wrapper starts, vtable stores, `aLine001Epd` adjacency, the stale LodePNG false anchor, packet/draw profiles, and absence of IDA UDTs for final paper field names. Owner/emitter remains [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md); wrapper/source-field blockers remain documented.

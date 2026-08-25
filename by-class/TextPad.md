*** UID:0000EU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TextPad.h"

#include <wchar.h>
#include <windows.h>

#include "../../app/Application.h"
#include "../../platform/PlatformApi.h"
#include "../../render/Surface.h"
#include "../../util/MemoryMan.h"
#include "../MainUiGraph.h"
#include "../controls/TextEditControlPane.h"
#include "../controls/TextEditPane.h"
#include "../core/Event.h"
#include "../core/ScreenPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/DialogPane.h"

class Event;

class TextPad : public DialogPane
{
public:
    TextPad();
    virtual bool HandleKeyOrTextEvent(Event *event);

protected:
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    void SendText(const wchar_t *commandLine);
    void Open(const wchar_t *path);
    void Save(const wchar_t *path);
    void SetFont(unsigned short fontId);
    void SetColor(unsigned int color);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextPad

## Status

- Confidence: very strong for the complete class declaration, recovered behavior, exact vtable order, command-helper ownership, and file/source separation; the stripped external constructor caller and private spellings remain bounded caps.
- Likely source: [UID:0000OQ][TextPad](by-file/TextPad.md)
- Current recovered source: `source-3/simroot_v2/class_TextPad.cpp`
- Memory: [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- Vtable data: [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md)
- Command strings: [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md)

## Responsibility

`TextPad` is a fieldless full-screen text editing pad built on `DialogPane` and `TextEditControlPane`. It requires no explicit destructor: all observed state belongs to inherited panes/facets, while compiler-emitted deleting wrappers and RTTI/vtables follow from the declaration above. It creates:

- control `0`: main `TextEditControlPane`, screen width by `screen height - 32`, max 2000 lines, max 30000 characters, and Enter-key handling;
- control `1`: bottom single-line input `TextEditControlPane`, height 32 pixels.

When the bottom input receives Enter, `TextPad` reads the input text, passes it to a private command helper, then selects all input text.

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| `0x00595900-0x00595ae2` | `TextPad::TextPad()` | Constructs base `DialogPane`, installs three vtables, builds the main and input text edit controls, and attaches to root/cursor managers. |
| `0x00595af0-0x00595ba9` | `TextPad::HandleKeyOrTextEvent(Event *event)` | Requires translated key `13`, active control `1`, and `kEventKeyDown`; reads command child `1`, sends the command, selects `0..0x7fff`, or falls back to `DialogPane::HandleKeyOrTextEvent`. |
| `0x00595bb0-0x00595bcf` | `TextPad::DrawBackground()` | Sets draw color `0x80`, draw mode `0`, and fills `m_visibleBounds` through `g_pfnFillRect`. |
| `0x00595bd0-0x00595bd1` | `TextPad::DrawBorder()` | Intentionally empty border override. |
| [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) | `TextPad::SendText(const wchar_t *commandLine)` | Private helper for file and formatting commands using [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md). |
| [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) | `TextPad::Open` / `Save` / `SetFont` / `SetColor` | Retained out-of-line member helpers for file commands and direct text-format insertion. |

## Command Helper

IDA disassembly for [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) shows prefix-based command handling:

| Prefix | Behavior |
| --- | --- |
| `Open ` | Opens the named file, reads content, converts it into the main text edit object, and resets selection. |
| `Save ` | Serializes the main text edit content and optional object/style payload, then writes it to the named file. |
| `SetFont ` | Parses a numeric font/style argument and applies edit formatting command `1`. |
| `SetColor ` | Parses a numeric color argument and applies edit formatting command `2`. |

The serialized text-object format used by `Open` and `Save` is now source-placed: TextPad owns the outer local-file command format, while [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md) carries visible UTF-16 text and optional payload and [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) owns the rich editor-state payload stream.

B012's 2026-06-25 implementation sync keeps the class score and split-emission policy unchanged while raising [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) to `90/90`. The accepted child C++ preserves current MCP behavior: no file-handle validity guards, `FILE_FLAG_SEQUENTIAL_SCAN`, MemoryMan allocation/free wrappers, the resolved open payload cursor, duplicated TextEditScrap buffers freed after save, and `SetColor` color stored at offset `+4` in the 12-byte `sub_58FEF0` format payload.

## Vtable And Runtime Evidence

- 2026-06-12 A003 live IDA MCP `entity_query` over [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md) reconfirmed `TextPad` vtable heads at `0x0062e190`, `0x0062e1f0`, and `0x0062e220`, followed by the `Open ` command string at `0x0062e228`.
- `xrefs_to` reports the constructor vptr stores at `0x00595940`, `0x00595946`, and `0x00595950`, and no direct caller for the constructor at `0x00595900`.
- The primary vtable has 23 slots and includes `DrawBackground` at `0x0062e1e0 -> 0x00595bb0` and `DrawBorder` at `0x0062e1e4 -> 0x00595bd0`.
- The secondary/adjusted vtable has 11 slots and includes `HandleKeyOrTextEvent` at `0x0062e1f8 -> 0x00595af0`; the tertiary group has two inherited/compiler slots.
- Constructor disassembly shows two `TextEditControlPane` child allocations. The main editor is configured with `0x7d0` / 2000 lines and `0x7530` / 30000 characters; values verified with `int_convert.py`.
- `HandleKeyOrTextEvent` checks Enter (`13`), inherited active control id `1`, and `kEventKeyDown`, then reads bottom input control id `1` before calling [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md). Raw secondary-view offsets map to inherited primary `DialogPane` state; neither offset is a TextPad-owned field.
- The command helper uses the [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md) successor strings and remains the only direct callee from `TextPad::HandleKeyOrTextEvent`.
- Batch 294 corrected the command-string child to [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md): live IDA shows the four command prefixes are consumed only by the private `TextPad` command helper, and the following `0x0062e268` dword belongs to `Thread` RTTI.
- 2026-06-19 B008 local PE/Capstone recheck finds no direct constructor rel32/data-pointer reference, but resolves the constructor-internal activation route: the constructor attaches/shows through the main UI layer slot and [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) after building a full-screen dialog and its two controls. The unknown remains the allocation/factory entrypoint, not TextPad's source owner or constructor behavior.
- Control ids are now stable for source reconstruction: id `0` is the main editor/display control and id `1` is the bottom command input control. The main editor limit calls set 2000 lines and 30000 characters; byte `TextEditControlPane +0x100` is a TextEditControlPane mode flag, provisionally `m_readOnly` or `m_acceptsInput`, not a TextPad field.

## Historical Superseded Identities And Output

- Earlier pages labeled the three authored overrides `OnKeyInput`, `OnClose`, and `OnEmptyVirtual`. Complete primary/secondary base-slot ordering plus direct bodies prove `HandleKeyOrTextEvent`, `DrawBackground`, and `DrawBorder`; the former labels and close/hide/read-only interpretations are historical only.
- Dated validator commands 26444 and 26459 omitted the complete header and retained stale identities and APIs. They are read-only historical receipts, not current generated authority; every callback must physically reread the current generated `TextPad.cpp` and required `TextPad.h`.

## Residual Caps

- No direct constructor caller is currently visible through IDA xrefs. The external allocation/factory activation path remains open; the constructor's internal attach/show route is no longer open.
- Historical generated output omitted [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) even though the handler calls it. The helper has one direct code caller, `0x00595b64` inside `TextPad::HandleKeyOrTextEvent`, so it remains reconstructable private TextPad code.
- Original exact folder naming is still inferred, but `ui/dialogs/TextPad.cpp` is the current staging path because the class derives from `DialogPane`, owns a local full-screen editor UI, and is explicitly separated from TextDialog, EditablePaperPane, terminal, and chat ownership.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | Complete preamble/header channels now declare the fieldless class and every authored method; the page records exact source order, constructor/handler/draw/command/file/format families, complete 23/11/2 vtable inventory, compiler/data dispositions, current dependencies, and bounded negative evidence. |
| Confidence `93` | Vtable heads/stores, direct body behavior, caller/literal xrefs, inherited receiver offsets, exact executable pages, and rejected neighboring owners converge. No external constructor caller, no inbound retained-helper refs, and stripped private spellings remain score caps rather than unresolved source blockers. |

## Cross-References

- [UID:0000OQ][TextPad](by-file/TextPad.md)
- [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md)
- [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md)
- [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OQ][TextPad](by-file/TextPad.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, key-input handler, close handler, empty virtual, and command helper at `0x00595900`, `0x00595af0`, `0x00595bb0`, `0x00595bd0`, and `0x00595be0`; this page and parent [UID:0000OQ][TextPad](by-file/TextPad.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the documented constructor, key-input flow, private command helper, command-prefix behavior, memory/file cross-references, and explicit unresolved activation/generated-output caveats.
- 2026-06-12 A003 Batch 293:
  - Before: scored `82/80`; the class was attached under the older parent gate but did not clear the strict `85/85` gate needed to route the exact vtable child.
  - After: scored `85/86`, retained parent [UID:0000OQ][TextPad](by-file/TextPad.md), and left final C++ blank.
  - Why: live IDA MCP reconfirmed exact vtable child [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md), constructor vptr stores, `OnClose`/empty/`OnKeyInput` vtable slots, command helper linkage, command-string successor boundary, and text-edit control construction limits. Remaining uncertainty is activation/source-grade naming, not class ownership.
- 2026-06-12 A001 Batch 294:
  - Score unchanged at `85/86`; added the corrected command-string child [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md).
  - Summary/evidence: live IDA traced `Open `/`Save `/`SetFont `/`SetColor ` xrefs to the private `TextPad` command helper and proved the following `0x0062e268` dword belongs to `Thread` RTTI, so the string child routes through the TextPad source file while this class page remains the supporting owner context.
- 2026-06-21 B008 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, with generated helper naming, raw secondary-offset wording, and incomplete child-emission policy.
  - After: `COMPLETION:88`, `CONFIDENCE:89`; owner/emitter remain [UID:0000OQ][TextPad](by-file/TextPad.md), and class-level C++ remains blank to avoid duplicating exact by-memory child bodies.
  - Summary/evidence: B008 recheck resolved source-facing method signatures, corrected adjusted `OnKeyInput` offsets to inherited DialogPane state, stabilized control ids, documented constructor-internal activation, named retained `Open`/`Save`/`SetFont`/`SetColor` helpers, tied file payloads to TextEditScrap/TextEditPane serialization, and rejected generated/free-helper/TextEdit/FileIO/TextDialog/terminal ownership alternatives.
- 2026-06-25 B012 standalone helper implementation sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: accepted [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) updates replace the retained helper formal C++ with current MCP-backed `Open`/`Save`/`SetFont`/`SetColor` bodies and document exact no-xref, file API, payload cursor, TextEditScrap duplicate/free, and `sub_58FEF0` format payload offset behavior. Class ownership and blank class-level C++ are unchanged so child bodies are not duplicated.
- 2026-08-22 B003 UID0000OQ whole-file implementation callback:
  - Before: `88/89`, blank formal preamble/header, and active provisional virtual identities.
  - After: `94/93`, emitter position `10`, exact preamble and complete fieldless/no-explicit-destructor header, corrected overrides, complete vtable/source-order/dependency closure, and historicalized dated output.

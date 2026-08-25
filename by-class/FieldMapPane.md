*** UID:00004U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FieldMapPane.h"

#include "../network/PacketBuffer.h"
#include "../network/Socket.h"
#include "../platform/PlatformApi.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"

#include <string.h>
#include <wchar.h>

static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *destination);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_FIELDMAPPANE_H
#define NEXUSTK_MAP_FIELDMAPPANE_H

#include "../ui/core/Pane.h"

class Event;

struct FieldMapEntry
{
    Point m_displayPosition;
    wchar_t m_label[64];
    unsigned short m_auxiliaryValue;
    unsigned short m_requestFieldId;
    Point m_requestPosition;
};

class FieldMapPane : public Pane
{
public:
    FieldMapPane(
        const wchar_t *sourcePath,
        short entryCount,
        short initialEntryIndex,
        const Point *displayPositions,
        const wchar_t *const *labels,
        const unsigned short *auxiliaryValues,
        const unsigned short *requestFieldIds,
        const Point *requestPositions);

    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    void CalculateFieldItemRect(short entryIndex, RectBounds *outRect);
    void SendFieldMapRequest(short entryIndex);

    wchar_t m_fieldMapEpfPath[128];
    FieldMapEntry m_fieldEntries[256];
    short m_fieldEntryCount;
    short m_selectedEntryIndex;
    short m_cancelEntryIndex;
    bool m_requestInFlight;
};

typedef char FieldMapEntrySizeCheck[sizeof(FieldMapEntry) == 0x94 ? 1 : -1];
typedef char FieldMapPaneSizeCheck[sizeof(FieldMapPane) == 0x9600 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FieldMapPane

## Status

- Confidence: very strong for class behavior, direct inheritance, exact layouts, virtual-facet ownership, helper linkage, complete CPP/H routing, and map source placement. The retained rectangle helper remains unreferenced but is source-ready from its complete bounded body and duplicated class-local formula.
- Likely source file: [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md)
- Address range: [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- Read-only data: [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md)
- Evidence basis: live IDA MCP `py_eval` on 2026-06-04 against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`).

## Class Purpose

`FieldMapPane` renders a selectable field map/list UI. It builds an EPF resource path, copies field metadata into a local entry table, handles mouse/keyboard selection, draws highlighted entries with labels, and sends the selected field-map request packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FieldMapPane` | `0x004b0bb0-0x004b0d2b` | Initializes pane state, stores the three `FieldMapPane` vtables, builds the `.EPF` path, and copies field metadata. |
| `HandleMouseEvent` | `0x004b0d30-0x004b0e50` | Vtable slot `0x0061a418`; hit-tests entries and sends a request for the clicked entry. |
| `HandleKeyEvent` | `0x004b0e50-0x004b0f1b` | Vtable slot `0x0061a41c`; handles navigation, submit, and cancel. |
| `RenderFieldEntries` | `0x004b0fb0-0x004b112a` | Vtable slot `0x0061a40c`; draws entries, selected highlight, and text labels. |
| `CalculateFieldItemRect(short entryIndex, RectBounds *outRect)` | `0x004b1130-0x004b119d` | Private retained helper that computes a hit/render rectangle from `FieldMapEntry::centerY`, `centerX`, measured `label`, `GetTextWidth`, `GetLineHeight`, and `RectBounds`. Formal C++ belongs to UID 000150; no live caller, IDA function object, direct edge, or pointer route is currently proven, and mouse/render duplicate the formula inline. |
| `SendFieldMapRequest` | `0x004b11a0-0x004b1242` | Builds opcode `0x3f` field-map request packet fields `requestFieldId`, `requestX`, and `requestY` from the selected entry, sends seven bytes through `g_packetSender`, and sets the request-in-flight flag. |
| `AdjustorDeletingDestructorA0` | `0x004b1242-0x004b124d` | Secondary vtable slot `0x0061a414`; adjusts by `-0xa0` and jumps to `0x004b1260`. |
| `AdjustorDeletingDestructorA4` | `0x004b124d-0x004b1258` | Tertiary vtable slot `0x0061a444`; adjusts by `-0xa4` and jumps to `0x004b1260`. |
| `ScalarDeletingDestructor` | `0x004b1260-0x004b129b` | Primary vtable slot `0x0061a3c8`; runs destructor/base cleanup and optionally frees storage. |

## Layout Notes

- Exact constructor/consumer evidence places `wchar_t m_fieldMapEpfPath[128]` at `+0x00f8` and `FieldMapEntry m_fieldEntries[256]` at `+0x01f8`.
- The class derives directly only from `Pane`. EventHandler and TimerHandler are inherited `Pane` facets; adjusted handlers subtract the containing-facet offset to recover the complete object. Treating them as additional direct bases would make the exact `0x9600` layout impossible.
- Each `FieldMapEntry` is exactly `0x94` bytes: `Point m_displayPosition` at `+0x00`, `wchar_t m_label[64]` at `+0x08`, `unsigned short m_auxiliaryValue` at `+0x88`, `unsigned short m_requestFieldId` at `+0x8a`, and `Point m_requestPosition` at `+0x8c`. The request helper serializes field ID, `m_requestPosition.x`, then `m_requestPosition.y`.
- The tail is `short m_fieldEntryCount` at `+0x95f8`, `short m_selectedEntryIndex` at `+0x95fa`, `short m_cancelEntryIndex` at `+0x95fc`, `bool m_requestInFlight` at `+0x95fe`, and one implicit tail-padding byte at `+0x95ff`.

## Live IDA Evidence

- 2026-06-04 IDA confirms modeled functions at `0x004b0bb0-0x004b0d2b`, `0x004b0d30-0x004b0e50`, `0x004b0e50-0x004b0f1b`, `0x004b0fb0-0x004b112a`, `0x004b11a0-0x004b1242`, `0x004b1242-0x004b124d`, `0x004b124d-0x004b1258`, `0x004b1260-0x004b129b`, and `0x004b8220-0x004b8284`.
- The constructor stores primary, secondary, and tertiary `FieldMapPane` vtables at `0x0061a3c8`, `0x0061a414`, and `0x0061a444`, then calls `0x004b8220` at `0x004b0c0d` before appending `.EPF` from `0x0061a44c`.
- Vtable data slots bind `RenderFieldEntries` at `0x0061a40c`, `HandleMouseEvent` at `0x0061a418`, `HandleKeyEvent` at `0x0061a41c`, adjustor destructors at `0x0061a414`/`0x0061a444`, and the scalar deleting destructor at `0x0061a3c8`.
- `SendFieldMapRequest` has exactly three code refs from `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`; decompilation confirms opcode `0x3f`, entry values from the `0x94`-byte record, a seven-byte send through `0x00574bb0`, and request-in-flight byte `this+0x95fe`.
- `BuildFieldMapPath` has one code ref from the constructor and decompiles as a wide path-stem copy helper that scans backward for `'.'`, copies the stem with `memmove`, writes a wide NUL, and leaves an incidental zero in `EAX`.
- B002 2026-06-18 [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) reanalysis resolves the constructor path buffer at `+0x0f8` as `wchar_t m_fieldMapEpfPath[0x80]`. The constructor passes this field to the file-local `BuildFieldMapPath` helper, appends pooled use-site `L".EPF"` with `_wcscat_s(...,0x80,...)`, computes the resulting length, and uppercases the completed EPF path through the PlatformApi `CharUpperBuffW` dispatch slot `0x0069be58`. The first entry table remains at `+0x1f8`, confirming the path field occupies exactly `0x100` bytes.
- Raw byte disassembly confirms the rectangle helper shape at `0x004b1130-0x004b119d`, including `index * 0x94`, row base `this+0x1f8`, text helpers `0x004baa70`/`0x004baaa0`, four rectangle writes, and `retn 8`; IDA still reports no function object and no xrefs for `0x004b1130`.
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms modeled starts and sizes: constructor `sub_4B0BB0` size `0x17b`, mouse handler `sub_4B0D30` size `0x120`, key handler `sub_4B0E50` size `0xcb`, render method `sub_4B0FB0` size `0x17a`, request helper `sub_4B11A0` size `0xa2`, scalar destructor `sub_4B1260` size `0x3b`, and path helper `sub_4B8220` size `0x64`; `0x004b1130` still reports `Not a function`.
- Current xrefs reconfirm no refs to `0x004b1130`, request-helper callers `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`, constructor-only path-helper caller `0x004b0c0d`, and vtable-backed render/mouse/key slots at `0x0061a40c`, `0x0061a418`, and `0x0061a41c`.
- `analyze_component` over the modeled class methods reports internal edges `0x004b0bb0 -> 0x004b8220`, `0x004b0d30 -> 0x004b11a0`, and `0x004b0e50 -> 0x004b11a0`, matching the FieldMap-local path and request helpers. `make_signature_for_range(0x004b0bb0,0x004b129b)` returns a unique wildcarded signature for the documented class span.
- 2026-06-17 B003 source-quality recheck resolves the primary aggregate gate at `85/90`: constructor caller remains unresolved after IDA xref, PE-aware rel32, and absolute-pointer checks, but class ownership is still proved by vtable stores and method slots; raw `0x004b1130` remains an exact unreferenced FieldMapPane rectangle-helper child; and request payload names remain structural rather than original-proof.
- 2026-06-27 B006 implementation callback accepts [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md) for first-draft C++. Live IDA MCP session `80de0a67` reconfirmed exactly three FieldMap-only request-helper callers at `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`, unique range signature for `0x004b11a0-0x004b1242`, boundary bytes before the next adjustor thunk, opcode `0x3f`, seven-byte send, request flag `this+0x95fe`, and negative direct pointer-pattern checks for the helper/constructor/raw-rect addresses. Packet helper names are source-quality as `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `Socket::QueueAndSendPacket`, with sender global `g_packetSender`; the stale `FittingRoomDownloadControlPane::SendFieldMapRequest` name is rejected as owner pollution.
- 2026-06-27 B006 source-quality callback accepts [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) for first-draft C++ as `FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)`. Live IDA MCP session `398b87c1` preserves no function object, no incoming xrefs, exact padding/prologue/ret/padding boundaries, a unique concrete range signature, and PE-aware no direct edge/pointer hits. The helper uses the `this+0x1f8` `m_fieldEntries` table, `FieldMapEntry::centerY`, `centerX`, `label`, `GetTextWidth`, `GetLineHeight`, and `RectBounds` `left/top/right/bottom`; mouse/render siblings duplicate the same formula inline and are not documented as callers.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | Exact direct inheritance, `0x94`/`0x9600` layouts, fields, virtuals, helper declarations, complete CPP/H channels, compiler-product causation, and source route are documented. |
| Confidence | 94 | Method/vtable/layout evidence and support pages agree. Exact original lexical spellings and final rebuilt integration remain below final-audit proof. |

## Cross-References

- [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md)
- [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md)
- [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md)
- [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md)
- [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md)
- [UID:0003P8][0x0061a3c4-0x0061a44c.FieldMapPaneVtableData](by-memory/0x0061a3c4-0x0061a44c.FieldMapPaneVtableData.md)

## 2026-08-18 B007 Class And Header Closure

- The formal CPP channel supplies the owning source preamble, all required includes, and the file-local `BuildFieldMapPath` forward declaration before emitted definitions. `EMITTER_POSITION_OPTIONAL:0` makes this the first FieldMapPane CPP fragment.
- The formal H channel is the complete required sibling header. It declares the exact entry and pane layouts, direct `Pane` inheritance, three source-authored virtual declarations, two private helpers, fields, include guard, dependency include/forward declaration, and compile-time `0x94`/`0x9600` size guards.
- `OnPaint` is the primary Pane-facet slot at `0x0061a40c`. `HandlePointerOrMouseEvent` and `HandleKeyOrTextEvent` are EventHandler-facet slots at `0x0061a418` and `0x0061a41c`. The inherited TimerHandler facet contributes compiler vtable/destructor support but no separate authored FieldMapPane method in this range.
- Compiler-emitted COLs, three vtable facets, two this-adjustor destructors, and the scalar deleting destructor are caused by this class declaration and implicit virtual destruction. They remain no-code evidence rather than handwritten source.
- Historical `centerY`, `centerX`, `requestX`, and `requestY` spellings described physical offsets correctly but are superseded as final source shape by `Point m_displayPosition` and `Point m_requestPosition`. Historical evidence remains below; the managed CPP/H channels carry the accepted source-facing declarations.
- The retained raw helper has no direct caller, function object, rel32 edge, or pointer hit. That bounded liveness caveat remains, while the complete source-shaped body and duplicated class-local formula justify retaining the private declaration/body.

## Changes

- 2026-08-18 B007 whole-file implementation callback:
  - Raised `86/89` to `93/94`, set `EMITTER_POSITION_OPTIONAL:0`, populated exact CPP preamble and complete H, resolved direct inheritance and exact layouts, and synchronized virtual/helper declarations with the seven-definition source inventory.
  - Preserved compiler-product and raw-helper caveats while historicalizing superseded scalar-coordinate/request-coordinate source names.

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: class-level purpose, method table, layout notes, and IDA caveats are documented, but full field naming and final C++ reconstruction are not complete. Evidence: documented address cluster `0x004b0bb0-0x004b129b`, helper cross-references, and explicit IDA notes for the unresolved `0x004b1130` helper boundary.
- 2026-06-04: Raised from `72/78` to `82/86`.
  - What existed before: the page had a broad method table and layout notes, but it used stale generated-source evidence wording, mixed last-byte and end-exclusive ranges, and did not tie the class to the current vtable/read-only data scan.
  - Changed to: recorded the current IDA binary identity, exact modeled function endpoints, constructor vtable stores, vtable method slots, request/path helper caller evidence, `.EPF` suffix xref, and raw rectangle-helper disassembly.
  - Reason for score increase: live IDA now strongly proves the class method ownership, vtable layout, field-entry request flow, path helper use, and render/input method endpoints; score remains below final reconstruction because the raw `0x004b1130` helper still has no IDA function object or callers and the broader class declaration/layout is not final-audit complete.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the IDA-backed map pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000JA`; left the C++ block blank because this page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms modeled starts at `0x004b0bb0`, `0x004b0d30`, `0x004b0e50`, `0x004b0fb0`, `0x004b11a0`, `0x004b1260`, and constructor-only path helper `0x004b8220`; `0x004b1130` is still raw code with no IDA function object. The class score `82/86` and parent score `86/84` both meet the 80/80 attachment gate.
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `86/89` with no owner/emitter changes. Live IDA reconfirmed modeled method/helper sizes, vtable-backed render/mouse/key slots, three request-helper callers, constructor-only path-helper caller, raw rectangle-helper no-function/no-ref status, component graph, and unique class-span signature. C++ remains blank because raw-helper reachability and source-quality field/helper names are unresolved.
- 2026-06-17 B003 aggregate gate sync:
  - Summary/evidence: added B003's source-quality recheck for [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md), including constructor no-edge/no-pointer evidence, bounded raw-helper liveness, and structural packet-field naming. Class score unchanged.
- 2026-06-27 B006 implementation callback:
  - Summary/evidence: incorporated accepted [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md) source-quality findings. `SendFieldMapRequest` now has first-draft C++ in its own by-memory page; this class page records packet helpers `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `Socket::QueueAndSendPacket`, sender global `g_packetSender`, and entry fields `requestFieldId`, `requestX`, and `requestY`. The then-current raw `0x004b1130` child blocker is superseded by the rectangle-helper callback below; broader class declaration work still caps this page.
- 2026-06-27 B006 rectangle-helper implementation callback:
  - Summary/evidence: incorporated accepted [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) source-quality findings. Added the private retained helper signature, documented its `centerY`/`centerX`/`label`/text-helper/`RectBounds` role, preserved the no-live-caller caveat, and recorded that mouse/render duplicate the formula inline rather than calling this helper. Class score unchanged because the helper's child page now carries the first-draft C++ while class declaration/layout work remains broader than this callback.
